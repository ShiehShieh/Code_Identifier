package com.pubnub.api;

import org.bouncycastle.crypto.DataLengthException;
import org.bouncycastle.crypto.InvalidCipherTextException;
import org.bouncycastle.util.encoders.Hex;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Random;




abstract class PubnubCore {

    private String HOSTNAME = "pubsub";
    private int HOSTNAME_SUFFIX = 1;
    private String DOMAIN = "pubnub.com";
    private String ORIGIN_STR = null;
    protected String PUBLISH_KEY = "";
    protected String SUBSCRIBE_KEY = "";
    protected String SECRET_KEY = "";
    private String CIPHER_KEY = "";
    private String IV = null;
    private volatile String AUTH_STR = null;
    private volatile boolean CACHE_BUSTING = true;
    protected Hashtable params;
    private volatile boolean resumeOnReconnect;

    private boolean SSL = true;
    protected String UUID = null;

    private Subscriptions channelSubscriptions;
    private Subscriptions channelGroupSubscriptions;

    protected SubscribeManager subscribeManager;
    protected NonSubscribeManager nonSubscribeManager;
    protected TimedTaskManager timedTaskManager;
    private volatile String _timetoken = "0";
    private volatile String _saved_timetoken = "0";

    private String PRESENCE_SUFFIX = "-pnpres";
    protected static String VERSION = "";
    private Random generator = new Random();

    private static Logger log = new Logger(PubnubCore.class);

    protected abstract String getUserAgent();

    private int PRESENCE_HEARTBEAT_TASK = 0;
    private int HEARTBEAT = 320;
    private volatile int PRESENCE_HB_INTERVAL = 0;


    public void shutdown() {
        nonSubscribeManager.stop();
        subscribeManager.stop();
        timedTaskManager.stop();
    }

    public boolean isResumeOnReconnect() {
        return resumeOnReconnect;
    }


    public void setRetryInterval(int retryInterval) {
        subscribeManager.setRetryInterval(retryInterval);
    }


    public void setWindowInterval(int windowInterval) {
        subscribeManager.setWindowInterval(windowInterval);
    }


    public int getRetryInterval() {
        return subscribeManager.retryInterval;
    }


    public int getWindowInterval() {
        return subscribeManager.windowInterval;
    }

    String[] getPresenceHeartbeatUrl() {
        String channelString = channelSubscriptions.getItemStringNoPresence();

        if (channelString.length() <= 0) {
            return null;
        }
        return new String[]{ getPubnubUrl(), "v2", "presence", "sub-key",
                this.SUBSCRIBE_KEY, "channel",
                PubnubUtil.urlEncode(channelString), "heartbeat"
        };
    }

    private String getState() {
        return (channelSubscriptions.state.length() > 0) ? channelSubscriptions.state.toString() : null;
    }

    class PresenceHeartbeatTask extends TimedTask {
        private Callback callback;

        PresenceHeartbeatTask(int interval, Callback callback) {
            super(interval);
            this.callback = callback;
        }

        public void run() {

            String[] urlComponents = getPresenceHeartbeatUrl();
            if (urlComponents == null)
                return;

            Hashtable parameters = PubnubUtil.hashtableClone(params);
            if (parameters.get("uuid") == null)
                parameters.put("uuid", UUID);

            String st  = getState();
            if (st != null) parameters.put("state", st);

            if (HEARTBEAT > 0 && HEARTBEAT < 320 ) parameters.put("heartbeat", String.valueOf(HEARTBEAT));

            HttpRequest hreq = new HttpRequest(urlComponents, parameters,
                    new ResponseHandler() {
                        public void handleResponse(HttpRequest hreq, String response) {
                            JSONObject jso;
                            try {
                                jso = new JSONObject(response);
                                response = jso.getString("message");
                            } catch (JSONException e) {
                                handleError(
                                        hreq,
                                        PubnubError.getErrorObject(
                                                PubnubError.PNERROBJ_INVALID_JSON, 1, response
                                        )
                                );
                                return;
                            }
                            callback.successCallback(
                                    channelSubscriptions.getItemStringNoPresence(),
                                    response
                            );
                        }

                        public void handleError(HttpRequest hreq, PubnubError error) {
                            callback.errorCallback(channelSubscriptions.getItemStringNoPresence(), error);
                        }
                    });

            _request(hreq, nonSubscribeManager);

        }

    }


    public void setPnExpires(int pnexpires, Callback callback) {
        setHeartbeat(pnexpires,callback);
    }


    public void setHeartbeat(int heartbeat, Callback callback) {
        Callback cb = getWrappedCallback(callback);

        HEARTBEAT = (heartbeat > 0 && heartbeat < 5)?5:heartbeat;
        if (PRESENCE_HB_INTERVAL == 0) {
            PRESENCE_HB_INTERVAL = (HEARTBEAT - 3 >= 1)?HEARTBEAT - 3:1;
        }
        if (PRESENCE_HEARTBEAT_TASK == 0) {
            PRESENCE_HEARTBEAT_TASK = timedTaskManager.addTask("Presence-Heartbeat",
                    new PresenceHeartbeatTask(PRESENCE_HB_INTERVAL, cb));
        } else if (PRESENCE_HB_INTERVAL == 0 || PRESENCE_HB_INTERVAL > 320) {
            timedTaskManager.removeTask(PRESENCE_HEARTBEAT_TASK);
        } else {
            timedTaskManager.updateTask(PRESENCE_HEARTBEAT_TASK, PRESENCE_HB_INTERVAL);
        }
        disconnectAndResubscribe();
    }

    public void setPnExpires(int pnexpires) {
        setPnExpires(pnexpires, null);
    }

    public void setHeartbeat(int heartbeat) {
        setHeartbeat(heartbeat, null);
    }

    public void setHeartbeatInterval(int heartbeatInterval) {
        setHeartbeatInterval(heartbeatInterval, null);
    }
    public void setHeartbeatInterval(int heartbeatInterval, Callback callback) {

        Callback cb = getWrappedCallback(callback);
        PRESENCE_HB_INTERVAL = heartbeatInterval;
        if (PRESENCE_HEARTBEAT_TASK == 0) {
            PRESENCE_HEARTBEAT_TASK = timedTaskManager.addTask("Presence-Heartbeat",
                    new PresenceHeartbeatTask(PRESENCE_HB_INTERVAL, cb));
        } else if (PRESENCE_HB_INTERVAL == 0 || PRESENCE_HB_INTERVAL > 320) {
            timedTaskManager.removeTask(PRESENCE_HEARTBEAT_TASK);
        } else {
            timedTaskManager.updateTask(PRESENCE_HEARTBEAT_TASK, PRESENCE_HB_INTERVAL);
        }

    }

    public int getHeartbeatInterval() {
        return PRESENCE_HB_INTERVAL;
    }



    public int getPnExpires() {
        return getHeartbeat();
    }


    public int getHeartbeat() {
        return HEARTBEAT;
    }


    public void setMaxRetries(int maxRetries) {
        subscribeManager.setMaxRetries(maxRetries);
    }


    public int getMaxRetries() {
        return subscribeManager.maxRetries;
    }

    protected String getPubnubUrl() {

        if (ORIGIN_STR == null) {
            // SSL On?
            if (this.SSL) {
                ORIGIN_STR = "https://";
            } else {
                ORIGIN_STR = "http://";
            }
            ORIGIN_STR  += HOSTNAME;
            ORIGIN_STR  += ((!this.CACHE_BUSTING)?"":"-" + String.valueOf(HOSTNAME_SUFFIX));
            ORIGIN_STR  += "." + DOMAIN;
        }
        return ORIGIN_STR;
    }
    private Callback voidCallback = new Callback()
    {public void successCallback(String channel, Object message) {}};

    protected Callback getWrappedCallback(Callback callback){
        if (callback == null) {
            return voidCallback;
        } else
            return callback;
    }

    private boolean validateInput(String name, Object input, Callback callback) {

        if (input == null) {
            callback.errorCallback("", PubnubError.getErrorObject(
                    PubnubError.PNERROBJ_INVALID_ARGUMENTS, 1, name + " cannot be null"));
            return false;
        }

        if (input instanceof String && ((String)input).length() == 0) {
            callback.errorCallback("", PubnubError.getErrorObject(
                    PubnubError.PNERROBJ_INVALID_ARGUMENTS, 2, name + " cannot be zero length"));
            return false;
        }
        return true;
    }



    public void setCacheBusting(boolean cacheBusting) {
        this.CACHE_BUSTING = cacheBusting;
    }


    public boolean getCacheBusting() {
        return this.CACHE_BUSTING;
    }


    public String getCurrentlySubscribedChannelNames() {
        String currentChannels = channelSubscriptions.getItemString();
        return currentChannels.equals("") ? "no channels." : currentChannels;
    }


    public void setResumeOnReconnect(boolean resumeOnReconnect) {
        this.resumeOnReconnect = resumeOnReconnect;
    }


    public boolean getResumeOnReconnect() {
        return this.resumeOnReconnect;
    }


    abstract String uuid();


    public void setUUID(String uuid) {
        this.UUID = uuid;
    }


    public String getUUID() {
        return this.UUID;
    }



    public PubnubCore(String publish_key, String subscribe_key,
            String secret_key, String cipher_key, boolean ssl_on, String initialization_vector) {
        this.init(publish_key, subscribe_key, secret_key, cipher_key, ssl_on, initialization_vector);
    }



    public PubnubCore(String publish_key, String subscribe_key,
            String secret_key, String cipher_key, boolean ssl_on) {
        this.init(publish_key, subscribe_key, secret_key, cipher_key, ssl_on);
    }



    public PubnubCore(String publish_key, String subscribe_key,
            String secret_key, boolean ssl_on) {
        this.init(publish_key, subscribe_key, secret_key, "", ssl_on);
    }



    public PubnubCore(String publish_key, String subscribe_key) {
        this.init(publish_key, subscribe_key, "", "", false);
    }



    public PubnubCore(String publish_key, String subscribe_key, boolean ssl) {
        this.init(publish_key, subscribe_key, "", "", ssl);
    }


    public PubnubCore(String publish_key, String subscribe_key,
            String secret_key) {
        this.init(publish_key, subscribe_key, secret_key, "", false);
    }


    private void init(String publish_key, String subscribe_key,
            String secret_key, String cipher_key, boolean ssl_on) {
        this.init(publish_key, subscribe_key, secret_key, cipher_key, ssl_on, null);
    }



    private void init(String publish_key, String subscribe_key,
            String secret_key, String cipher_key, boolean ssl_on, String initialization_vector) {
        this.PUBLISH_KEY = publish_key;
        this.SUBSCRIBE_KEY = subscribe_key;
        this.SECRET_KEY = secret_key;
        this.CIPHER_KEY = cipher_key;
        this.SSL = ssl_on;

        if (UUID == null)
            UUID = uuid();

        if (channelSubscriptions == null)
            channelSubscriptions = new Subscriptions();

        if (channelGroupSubscriptions == null)
            channelGroupSubscriptions = new Subscriptions();

        if (subscribeManager == null)
            subscribeManager = new SubscribeManager("Subscribe-Manager-"
                    + System.identityHashCode(this), 10000, 310000);

        if (nonSubscribeManager == null)
            nonSubscribeManager = new NonSubscribeManager(
                    "Non-Subscribe-Manager-" + System.identityHashCode(this),
                    10000, 15000);

        if (timedTaskManager == null)
            timedTaskManager = new TimedTaskManager("TimedTaskManager");

        if (params == null)
            params = new Hashtable();

        params.put("pnsdk", getUserAgent());
        subscribeManager.setHeader("V", VERSION);
        subscribeManager.setHeader("Accept-Encoding", "gzip");
        subscribeManager.setHeader("User-Agent", getUserAgent());

        nonSubscribeManager.setHeader("V", VERSION);
        nonSubscribeManager.setHeader("Accept-Encoding", "gzip");
        nonSubscribeManager.setHeader("User-Agent", getUserAgent());

    }


    protected void setSubscribeTimeout(int timeout) {
        subscribeManager.setRequestTimeout(timeout);
        this.disconnectAndResubscribe();
    }

    protected int getSubscribeTimeout() {
        return subscribeManager.requestTimeout;
    }


    protected void setNonSubscribeTimeout(int timeout) {
        nonSubscribeManager.setRequestTimeout(timeout);
    }

    protected int getNonSubscribeTimeout() {
        return nonSubscribeManager.requestTimeout;
    }


    public void publish(String channel, JSONObject message, boolean storeInHistory, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("storeInHistory", (storeInHistory)?"":"0");
        publish(args);
    }


    public void publish(String channel, JSONArray message, boolean storeInHistory, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        args.put("storeInHistory", (storeInHistory)?"":"0");
        publish(args);
    }


    public void publish(String channel, String message, boolean storeInHistory, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        args.put("storeInHistory", (storeInHistory)?"":"0");
        publish(args);
    }


    public void publish(String channel, Integer message, boolean storeInHistory, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        args.put("storeInHistory", (storeInHistory)?"":"0");
        publish(args);
    }

    public void publish(String channel, Double message, boolean storeInHistory, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        args.put("storeInHistory", (storeInHistory)?"":"0");
        publish(args);
    }



    public void publish(String channel, JSONObject message, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        publish(args);
    }


    public void publish(String channel, JSONArray message, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        publish(args);
    }


    public void publish(String channel, String message, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        publish(args);
    }


    public void publish(String channel, Integer message, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        publish(args);
    }


    public void publish(String channel, Double message, Callback callback) {
        Hashtable args = new Hashtable();
        args.put("channel", channel);
        args.put("message", message);
        args.put("callback", callback);
        publish(args);
    }


    protected void publish(Hashtable args, Callback callback) {
        args.put("callback", callback);
        publish(args);
    }



    protected void publish(Hashtable args) {

        final String channel = (String) args.get("channel");
        final Object message = args.get("message");
        final Callback callback = getWrappedCallback((Callback) args.get("callback"));
        String storeInHistory = (String) args.get("storeInHistory");
        String msgStr = message.toString();
        Hashtable parameters = PubnubUtil.hashtableClone(params);

        if (storeInHistory != null && storeInHistory.length() > 0) parameters.put("store", storeInHistory);

        if (this.CIPHER_KEY.length() > 0) {
            PubnubCrypto pc = new PubnubCrypto(this.CIPHER_KEY, this.IV);
            try {
                if (message instanceof String) {
                    msgStr = "\"" + msgStr + "\"";
                }
                msgStr = "\"" + pc.encrypt(msgStr) + "\"";
            } catch (DataLengthException e) {
                callback.errorCallback(channel,
                        PubnubError.getErrorObject(PubnubError.PNERROBJ_ENCRYPTION_ERROR, 1, msgStr));
                return;
            } catch (IllegalStateException e) {
                callback.errorCallback(channel,
                        PubnubError.getErrorObject(PubnubError.PNERROBJ_ENCRYPTION_ERROR, 2, msgStr));
                return;
            } catch (InvalidCipherTextException e) {
                callback.errorCallback(channel,
                        PubnubError.getErrorObject(PubnubError.PNERROBJ_ENCRYPTION_ERROR, 3, msgStr));
                return;
            } catch (Exception e) {
                callback.errorCallback(channel,
                        PubnubError.getErrorObject(PubnubError.PNERROBJ_ENCRYPTION_ERROR, 4, msgStr + " : " + e.toString()));
                return;
            }
        } else {
            if (message instanceof String) {
                msgStr = "\"" + msgStr + "\"";
            }
        }

        String signature = "0";

        if (this.SECRET_KEY.length() > 0) {
            StringBuffer string_to_sign = new StringBuffer();
            string_to_sign.append(this.PUBLISH_KEY).append('/')
            .append(this.SUBSCRIBE_KEY).append('/')
            .append(this.SECRET_KEY).append('/').append(channel)
            .append('/').append(msgStr);

            try {
                signature = new String(Hex.encode(PubnubCrypto
                        .md5(string_to_sign.toString())), "UTF-8");
            } catch (UnsupportedEncodingException e) {

            }
        }
        String[] urlComponents = { getPubnubUrl(), "publish", this.PUBLISH_KEY,
                this.SUBSCRIBE_KEY, PubnubUtil.urlEncode(signature),
                PubnubUtil.urlEncode(channel), "0",
                PubnubUtil.urlEncode(msgStr)
        };

        class PublishResponseHandler extends ResponseHandler {
            public void handleResponse(HttpRequest hreq, String response) {
                JSONArray jsarr;
                try {
                    jsarr = new JSONArray(response);
                } catch (JSONException e) {
                    handleError(hreq,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_INVALID_JSON, 1, response));
                    return;
                }
                callback.successCallback(channel, jsarr);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                callback.errorCallback(channel, error);
                return;
            }
        }
        HttpRequest hreq = new HttpRequest(urlComponents, parameters, new PublishResponseHandler());

        _request(hreq, nonSubscribeManager);
    }


    public void presence(String channel, Callback callback)
            throws PubnubException {
        Hashtable args = new Hashtable(2);

        args.put("channels", new String[] {channel + PRESENCE_SUFFIX});
        args.put("callback", callback);

        subscribe(args);
    }


    public void whereNow(final String uuid, Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        String[] urlargs = { getPubnubUrl(), "v2", "presence", "sub_key",
                this.SUBSCRIBE_KEY, "uuid", PubnubUtil.urlEncode(uuid)
        };

        HttpRequest hreq = new HttpRequest(urlargs, params,
                new ResponseHandler() {
            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback("", response, "payload", cb, 4);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback("", error);
                return;
            }
        });

        _request(hreq, nonSubscribeManager);
    }

    public void whereNow(Callback callback) {
        whereNow(this.UUID, callback);
    }

    public void setState(String channel, String uuid, JSONObject state, Callback callback) {
        _setState(channelSubscriptions, PubnubUtil.urlEncode(channel), null, uuid, state, callback);
    }

    public void channelGroupSetState(String group, String uuid, JSONObject state, Callback callback) {
        _setState(channelSubscriptions, ".", group, uuid, state, callback);
    }

    protected void _setState(Subscriptions sub, String channel, String group, String uuid, JSONObject state, Callback callback) {
        SubscriptionItem item = sub.getItem(channel);
        final Callback cb = getWrappedCallback(callback);
        Hashtable parameters = PubnubUtil.hashtableClone(params);

        String[] urlArgs = { getPubnubUrl(), "v2", "presence", "sub-key",
                this.SUBSCRIBE_KEY, "channel", channel, "uuid", PubnubUtil.urlEncode(uuid),
                "data"
        };

        if (state != null) parameters.put("state", state.toString());
        if (group != null) parameters.put("channel-group", group);

        if (item != null) {
            try {
                sub.state.put(channel, state);
            } catch (JSONException e) {

            }
        }

        HttpRequest hreq = new HttpRequest(urlArgs, parameters,
                new ResponseHandler() {
            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback("", response, "payload", cb, 2 );
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback("", error);
            }
        });

        _request(hreq, nonSubscribeManager);
    }

    public void getState(String channel, String uuid, Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        Hashtable parameters = PubnubUtil.hashtableClone(params);

        String[] urlArgs = { getPubnubUrl(), "v2", "presence", "sub-key",
                this.SUBSCRIBE_KEY, "channel", PubnubUtil.urlEncode(channel),
                "uuid", PubnubUtil.urlEncode(uuid)
        };

        HttpRequest hreq = new HttpRequest(urlArgs, parameters,
                new ResponseHandler() {
                    public void handleResponse(HttpRequest hreq, String response) {
                        invokeCallback("", response, "payload", cb, 1 );
                    }

                    public void handleError(HttpRequest hreq, PubnubError error) {
                        cb.errorCallback("", error);
                    }
                });

        _request(hreq, nonSubscribeManager);
    }

    protected void invokeCallback(String channel, String response, String key,
            Callback callback, int extendedErrorCode) {
        invokeCallback(channel, response, key, callback, extendedErrorCode, false);
    }

    protected void invokeCallback(String channel, String response, String key,
            Callback callback, int extendedErrorCode, boolean key_strict) {
        JSONObject responseJso = null;
        try {
            responseJso = new JSONObject(response);
        } catch (JSONException e) {
            callback.errorCallback(channel,
                    PubnubError.getErrorObject(PubnubError.PNERROBJ_JSON_ERROR, extendedErrorCode, response));
            return;
        }

        JSONObject payloadJso = null;

        if (key != null && key.length() > 0) {
            try {
                payloadJso = (JSONObject) responseJso.get(key);
            } catch (JSONException e) {
                if (!key_strict) {
                    callback.successCallback(channel, responseJso);
                } else {
                    callback.errorCallback(channel,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_JSON_ERROR, extendedErrorCode, response));
                }
                return;

            }
            callback.successCallback(channel, payloadJso);
            return;
        }
    }

    protected void invokeJSONStringCallback(String response, String key, Callback callback) {
        String responseJSON;

        try {
            responseJSON = (new JSONObject(response)).getString(key);
            callback.successCallback(null, responseJSON);
        } catch (JSONException e) {
            callback.errorCallback(
                    null,
                    PubnubError.getErrorObject(PubnubError.PNERROBJ_JSON_ERROR, 0, response)
            );
        }
    }


    public void channelGroupListNamespaces(Callback callback) {
        final Callback cb = getWrappedCallback(callback);

        String[] url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "namespace"};

        Hashtable parameters = PubnubUtil.hashtableClone(params);

        HttpRequest hreq = new HttpRequest(url, parameters, new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback("", response, "payload", cb, 0);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(null, error);
            }
        });

        _request(hreq, nonSubscribeManager);
    }


    public void channelGroupRemoveNamespace(String namespace, Callback callback) {
        final Callback cb = getWrappedCallback(callback);

        String[] url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                this.SUBSCRIBE_KEY, "namespace", namespace, "remove"};

        Hashtable parameters = PubnubUtil.hashtableClone(params);

        HttpRequest hreq = new HttpRequest(url, parameters, new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {
                invokeJSONStringCallback(response, "message", cb);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(null, error);
            }
        });

        _request(hreq, nonSubscribeManager);
    }


    public void channelGroupListGroups(Callback callback) {
        channelGroupListGroups(null, callback);
    }


    public void channelGroupListGroups(String namespace, Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        String[] url;

        if (namespace != null) {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "namespace", namespace, "channel-group"};
        } else {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "channel-group"};
        }

        Hashtable parameters = PubnubUtil.hashtableClone(params);

        HttpRequest hreq = new HttpRequest(url, parameters, new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback("", response, "payload", cb, 0);
             }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(null, error);
            }
        });

        _request(hreq, nonSubscribeManager);
    }


    public void channelGroupListChannels(String group, Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        ChannelGroup channelGroup;
        String[] url;

        try {
            channelGroup =  new ChannelGroup(group);
        } catch (PubnubException e) {
            cb.errorCallback(null, PubnubError.PNERROBJ_CHANNEL_GROUP_PARSING_ERROR);
            return;
        }

        if (channelGroup.namespace != null) {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "namespace", channelGroup.namespace, "channel-group", channelGroup.group};
        } else {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "channel-group", channelGroup.group};
        }

        Hashtable parameters = PubnubUtil.hashtableClone(params);

        HttpRequest hreq = new HttpRequest(url, parameters, new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback("", response, "payload", cb, 0);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(null, error);
            }
        });

        _request(hreq, nonSubscribeManager);
    }

    public void channelGroupAddChannel(String group, String channel, Callback callback) {
        channelGroupUpdate("add", group, new String[]{channel}, callback);
    }

    public void channelGroupAddChannel(String group, String[] channels, Callback callback) {
        channelGroupUpdate("add", group, channels, callback);
    }

    public void channelGroupRemoveChannel(String group, String channel, Callback callback) {
        channelGroupUpdate("remove", group, new String[]{channel}, callback);
    }

    public void channelGroupRemoveChannel(String group, String[] channels, Callback callback) {
        channelGroupUpdate("remove", group, channels, callback);
    }

    private void channelGroupUpdate(String action, String group, String[] channels, final Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        ChannelGroup channelGroup;
        String[] url;

        try {
            channelGroup =  new ChannelGroup(group);
        } catch (PubnubException e) {
            cb.errorCallback(null, PubnubError.PNERROBJ_CHANNEL_GROUP_PARSING_ERROR);
            return;
        }

        if (channelGroup.namespace != null) {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "namespace", channelGroup.namespace, "channel-group", channelGroup.group};
        } else {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "channel-group", channelGroup.group};
        }

        Hashtable parameters = PubnubUtil.hashtableClone(params);

        if (channels.length > 0) {
            parameters.put(action, PubnubUtil.joinString(channels, ","));
        }

        HttpRequest hreq = new HttpRequest(url, parameters, new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {
                invokeJSONStringCallback(response, "message", cb);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(null, error);
            }

        });

        _request(hreq, nonSubscribeManager);
    }

    public void channelGroupRemoveGroup(String group, Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        ChannelGroup channelGroup;
        String[] url;

        try {
            channelGroup =  new ChannelGroup(group);
        } catch (PubnubException e) {
            cb.errorCallback(null, PubnubError.PNERROBJ_CHANNEL_GROUP_PARSING_ERROR);
            return;
        }

        if (channelGroup.namespace != null) {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "namespace",
                    channelGroup.namespace, "channel-group", channelGroup.group, "remove"};
        } else {
            url = new String[]{getPubnubUrl(), "v1", "channel-registration", "sub-key",
                    this.SUBSCRIBE_KEY, "channel-group", channelGroup.group, "remove"};
        }

        Hashtable parameters = PubnubUtil.hashtableClone(params);

        HttpRequest hreq = new HttpRequest(url, parameters, new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {
                invokeJSONStringCallback(response, "message", cb);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(null, error);
            }

        });

        _request(hreq, nonSubscribeManager);
    }


    public void hereNow(final String channel, Callback callback) {
        hereNow(new String[]{channel}, null, false, true, callback);
    }

    public void hereNow(boolean state, boolean uuids, Callback callback) {
        hereNow(null, null, state, uuids, callback);
    }

    public void hereNow(final String channel, boolean state, boolean uuids, Callback callback) {
        hereNow(new String[]{channel}, null, state, uuids, callback);
    }

    public void channelGroupHereNow(String group, Callback callback) {
        channelGroupHereNow(group, false, true, callback);
    }

    public void channelGroupHereNow(String group, boolean state, boolean uuids, Callback callback) {
        channelGroupHereNow(new String[]{group}, state, uuids, callback);
    }

    public void channelGroupHereNow(String[] groups, boolean state, boolean uuids, Callback callback) {
        hereNow(null, groups, state, uuids, callback);
    }


    public void hereNow(String[] channels, String[] channelGroups, boolean state,
                        boolean uuids, Callback callback) {

        final Callback cb = getWrappedCallback(callback);
        Hashtable parameters = PubnubUtil.hashtableClone(params);
        ArrayList urlArgs = new ArrayList();

        urlArgs.add(getPubnubUrl());
        urlArgs.add("v2");
        urlArgs.add("presence");
        urlArgs.add("sub_key");
        urlArgs.add(this.SUBSCRIBE_KEY);

        if (channels != null || channelGroups != null) {
            String channelsString = PubnubUtil.joinString(channels, ",");
            if ("".equals(channelsString)) {
                channelsString = ",";
            } else {
                channelsString = PubnubUtil.urlEncode(channelsString);
            }

            urlArgs.add("channel");
            urlArgs.add(channelsString);
        }

        if (state) parameters.put("state", "1");
        if (!uuids) parameters.put("disable_uuids", "1");
        if (channelGroups != null && channelGroups.length > 0) {
            parameters.put("channel-group", PubnubUtil.joinString(channelGroups, ","));
        }

        String[] path = (String[]) urlArgs.toArray(new String[urlArgs.size()]);

        HttpRequest hreq = new HttpRequest(path, parameters,
                new ResponseHandler() {
                    public void handleResponse(HttpRequest hreq, String response) {
                        invokeCallback(null, response, "payload", cb, 1);
                    }

                    public void handleError(HttpRequest hreq, PubnubError error) {
                        cb.errorCallback(null, error);
                    }
                });

        _request(hreq, nonSubscribeManager);
    }


   public void history(final String channel, long start, long end,
           int count, boolean reverse, Callback callback) {
       history(channel, start, end, count, reverse, false, callback);
   }




    public void history(final String channel, long start, long end,
            int count, boolean reverse, boolean includeTimetoken, Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        Hashtable parameters = PubnubUtil.hashtableClone(params);
        if (count == -1)
            count = 100;

        parameters.put("count", String.valueOf(count));
        parameters.put("reverse", String.valueOf(reverse));
        parameters.put("include_token", String.valueOf(includeTimetoken));

        if (start != -1)
            parameters.put("start", Long.toString(start).toLowerCase());

        if (end != -1)
            parameters.put("end", Long.toString(end).toLowerCase());

        String[] urlargs = { getPubnubUrl(), "v2", "history", "sub-key",
                this.SUBSCRIBE_KEY, "channel", PubnubUtil.urlEncode(channel)
        };

        class HistoryResponseHandler extends ResponseHandler {

            public void handleResponse(HttpRequest hreq, String response) {
                JSONArray respArr;
                try {
                    respArr = new JSONArray(response);
                    decryptJSONArray((JSONArray) respArr.get(0));
                    cb.successCallback(channel, respArr);
                } catch (JSONException e) {
                    cb.errorCallback(channel,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_JSON_ERROR, 3));
                } catch (DataLengthException e) {
                    cb.errorCallback(channel,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_DECRYPTION_ERROR, 6, response));
                } catch (IllegalStateException e) {
                    cb.errorCallback(channel,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_DECRYPTION_ERROR, 7, response));
                } catch (InvalidCipherTextException e) {
                    cb.errorCallback(channel,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_DECRYPTION_ERROR, 8, response));
                } catch (IOException e) {
                    cb.errorCallback(channel,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_DECRYPTION_ERROR, 9, response));
                } catch (Exception e) {
                    cb.errorCallback(channel,
                            PubnubError.getErrorObject(PubnubError.PNERROBJ_DECRYPTION_ERROR, 10, response + " : " + e.toString()));
                }

            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(channel, error);
                return;
            }
        }

        HttpRequest hreq = new HttpRequest(urlargs, parameters, new HistoryResponseHandler());
        _request(hreq, nonSubscribeManager);
    }


    public void history(String channel, long start, long end,
            boolean reverse, Callback callback) {
        history(channel, start, end, -1, reverse, callback);
    }


    public void history(String channel, int count, Callback callback) {
        history(channel, -1, -1, count, false, callback);
    }


   public void history(String channel, boolean includeTimetoken, int count, Callback callback) {
       history(channel, -1, -1, count, false, includeTimetoken, callback);
   }



    public void history(String channel, long start, boolean reverse,
            Callback callback) {
        history(channel, start, -1, -1, reverse, callback);
    }


    public void history(String channel, long start, long end,
            Callback callback) {
        history(channel, start, end, -1, false, callback);
    }


    public void history(String channel, long start, long end, int count,
            Callback callback) {
        history(channel, start, end, count, false, callback);
    }


    public void history(String channel, long start, int count,
            boolean reverse, Callback callback) {
        history(channel, start, -1, count, reverse, callback);
    }


    public void history(String channel, long start, int count,
            Callback callback) {
        history(channel, start, -1, count, false, callback);
    }


    public void history(String channel, int count, boolean reverse,
            Callback callback) {
        history(channel, -1, -1, count, reverse, callback);
    }


    public void history(String channel, boolean reverse,
            Callback callback) {
        history(channel, -1, -1, -1, reverse, callback);
    }


    public void time(Callback callback) {
        final Callback cb = getWrappedCallback(callback);

        String[] url = { getPubnubUrl(), "time", "0" };
        HttpRequest hreq = new HttpRequest(url, params, new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {
                cb.successCallback(null, response);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(null, error);
            }

        });

        _request(hreq, nonSubscribeManager);
    }

    private void keepOnlyPluralSubscriptionItems(Hashtable args) {
        String _channel = (String) args.get("channel");
        String _group = (String) args.get("group");

        if (_channel != null && !(_channel.equals(""))) {
            args.put("channels", new String[]{_channel});
            args.remove("channel");
        }

        if (_group != null && !(_group.equals(""))) {
            args.put("groups", new String[]{_group});
            args.remove("group");
        }
    }

    private boolean inputsValid(Hashtable args) throws PubnubException {
        boolean channelsOk;
        boolean groupsOk;

        if (!(args.get("callback") instanceof Callback) || args.get("callback") == null) {
            throw new PubnubException("Invalid Callback");
        }

        String[] _channels = (String[]) args.get("channels");
        String[] _groups = (String[]) args.get("groups");

        channelsOk = (_channels != null && _channels.length > 0);
        groupsOk = (_groups != null && _groups.length > 0);

        if (!channelsOk && !groupsOk) {
            throw new PubnubException("Channel or Channel Group Missing");
        }

        return true;
    }

    private void leave(final String channel) {
        _leave(PubnubUtil.urlEncode(channel), new Hashtable());
    }

    private void channelGroupLeave(String group) {
        Hashtable params = new Hashtable();
        params.put("channel-group", group);

        _leave(",", params);
    }

    private void _leave(String channel, Hashtable params) {
        String[] urlArgs = {getPubnubUrl(), "v2/presence/sub_key",
                this.SUBSCRIBE_KEY, "channel", channel, "leave"
        };

        params.put("uuid", UUID);

        HttpRequest hreq = new HttpRequest(urlArgs, params,
                new ResponseHandler() {
                    public void handleResponse(HttpRequest hreq, String response) {
                    }

                    public void handleError(HttpRequest hreq, PubnubError error) {
                    }
                });

        _request(hreq, nonSubscribeManager);
    }


    public void unsubscribe(String[] channels) {
        for (int i = 0; i < channels.length; i++) {
            String channel = channels[i];
            channelSubscriptions.removeItem(channel);
            channelSubscriptions.state.remove(channel);
            leave(channel);
        }

        resubscribe();
    }


    public void unsubscribe(String channel) {
        unsubscribe(new String[]{channel});
    }


    protected void unsubscribe(Hashtable args) {
        String[] channelList = (String[]) args.get("channels");
        if (channelList == null) {
            channelList = new String[]{(String) args.get("channel")};
        }

        unsubscribe(channelList);
    }


    public void channelGroupUnsubscribe(String group) {
        channelGroupUnsubscribe(new String[]{group});
    }


    public void channelGroupUnsubscribe(String[] groups) {
        for (int i = 0; i < groups.length; i++) {
            String group = groups[i];
            channelGroupSubscriptions.removeItem(group);
            channelGroupLeave(group);
        }

        resubscribe();
    }

    public void unsubscribePresence(String channel) {
        unsubscribe(new String[]{channel + PRESENCE_SUFFIX});
    }


    public void unsubscribeAll() {
        String[] channels = channelSubscriptions.getItemNames();
        String[] groups = channelGroupSubscriptions.getItemNames();

        for (int i = 0; i < channels.length; i++) {
            String channel = channels[i];
            channelSubscriptions.removeItem(channel);
            leave(channel);
        }

        for (int i = 0; i < groups.length; i++) {
            String group = groups[i];
            channelGroupSubscriptions.removeItem(group);
            channelGroupLeave(group);
        }

        disconnectAndResubscribe();
    }


    public void unsubscribeAllChannels() {
        String[] channels = channelSubscriptions.getItemNames();

        for (int i = 0; i < channels.length; i++) {
            String channel = channels[i];
            channelSubscriptions.removeItem(channel);
            leave(channel);
        }

        disconnectAndResubscribe();
    }


    public void channelGroupUnsubscribeAllGroups() {
        String[] groups = channelGroupSubscriptions.getItemNames();

        for (int i = 0; i < groups.length; i++) {
            String group = groups[i];
            channelGroupSubscriptions.removeItem(group);
            channelGroupLeave(group);
        }

        disconnectAndResubscribe();
    }


    protected void subscribe(Hashtable args, Callback callback)
            throws PubnubException {
        args.put("callback", callback);

        subscribe(args);
    }


    protected void subscribe(Hashtable args) throws PubnubException {

        keepOnlyPluralSubscriptionItems(args);

        if (!inputsValid(args)) {
            return;
        }

        _subscribe(args);
    }


    public void subscribe(String[] channels, Callback callback)
            throws PubnubException {
        subscribe(channels, callback, "0");
    }


    public void subscribe(String[] channels, Callback callback, String timetoken)
            throws PubnubException {

        Hashtable args = new Hashtable();

        args.put("channels", channels);
        args.put("callback", callback);
        args.put("timetoken", timetoken);

        subscribe(args);
    }


    public void subscribe(String[] channels, Callback callback, long timetoken)
            throws PubnubException {
        subscribe(channels, callback, String.valueOf(timetoken));
    }


    public void subscribe(String channel, Callback callback)
            throws PubnubException {
        subscribe(channel, callback, "0");
    }


    public void subscribe(String channel, Callback callback, String timetoken)
            throws PubnubException {
        subscribe(new String[]{channel}, callback, timetoken);
    }


    public void subscribe(String channel, Callback callback, long timetoken)
            throws PubnubException {
        subscribe(channel, callback, String.valueOf(timetoken));
    }


    public void subscribe(String channel, String group, Callback callback)
            throws PubnubException {
        subscribe(channel, group, callback, "0");
    }


    public void subscribe(String channel, String group, Callback callback, long timetoken)
            throws PubnubException {
        subscribe(channel, group, callback, String.valueOf(timetoken));
    }


    public void subscribe(String channel, String group, Callback callback, String timetoken)
            throws PubnubException {
        subscribe(new String[]{channel}, new String[]{group}, callback, timetoken);
    }


    public void subscribe(String[] channels, String group, Callback callback)
            throws PubnubException {
        subscribe(channels, group, callback, "0");
    }


    public void subscribe(String[] channels, String group, Callback callback, long timetoken)
            throws PubnubException {
        subscribe(channels, group, callback, String.valueOf(timetoken));
    }


    public void subscribe(String[] channels, String group, Callback callback, String timetoken)
            throws PubnubException {
        subscribe(channels, new String[]{group}, callback, timetoken);
    }


    public void subscribe(String channel, String[] groups, Callback callback)
            throws PubnubException {
        subscribe(channel, groups, callback, "0");
    }


    public void subscribe(String channel, String[] groups, Callback callback, long timetoken)
            throws PubnubException {
        subscribe(channel, groups, callback, String.valueOf(timetoken));
    }


    public void subscribe(String channel, String[] groups, Callback callback, String timetoken)
            throws PubnubException {
        subscribe(new String[]{channel}, groups, callback, timetoken);
    }


    public void subscribe(String[] channels, String[] groups, Callback callback)
            throws PubnubException {
        subscribe(channels, groups, callback, "0");
    }


    public void subscribe(String[] channels, String[] groups, Callback callback, long timetoken)
            throws PubnubException {
        subscribe(channels, groups, callback, String.valueOf(timetoken));
    }


    public void subscribe(String[] channels, String[] groups, Callback callback, String timetoken)
            throws PubnubException {
        Hashtable args = new Hashtable();

        args.put("channels", channels);
        args.put("groups", groups);
        args.put("callback", callback);
        args.put("timetoken", timetoken);

        subscribe(args);
    }


    public void channelGroupSubscribe(String group, Callback callback)
            throws PubnubException {
        channelGroupSubscribe(group, callback, "0");
    }

    public void channelGroupSubscribe(String[] groups, Callback callback)
            throws PubnubException {
        channelGroupSubscribe(groups, callback, "0");
    }


    public void channelGroupSubscribe(String group, Callback callback, long timetoken)
            throws PubnubException {
        channelGroupSubscribe(group, callback, String.valueOf(timetoken));
    }


    public void channelGroupSubscribe(String group, Callback callback, String timetoken)
            throws PubnubException {
        channelGroupSubscribe(new String[]{group}, callback, timetoken);
    }


    public void channelGroupSubscribe(String[] groups, Callback callback, long timetoken)
            throws PubnubException {
        channelGroupSubscribe(groups, callback, String.valueOf(timetoken));
    }


    public void channelGroupSubscribe(String[] groups, Callback callback, String timetoken)
            throws PubnubException {

        Hashtable args = new Hashtable();

        args.put("groups", groups);
        args.put("callback", callback);
        args.put("timetoken", timetoken);

        subscribe(args);
    }

    private void callErrorCallbacks(String[] channelList, PubnubError error) {
        for (int i = 0; i < channelList.length; i++) {
            String channel = channelList[i];
            Callback cb = channelSubscriptions.getItem(channel).callback;
            cb.errorCallback(channel, error);
        }
    }

    private void decryptJSONArray(JSONArray messages) throws JSONException, DataLengthException, IllegalStateException, InvalidCipherTextException, IOException {

        if (CIPHER_KEY.length() > 0) {
            for (int i = 0; i < messages.length(); i++) {
                PubnubCrypto pc = new PubnubCrypto(CIPHER_KEY, IV);

                String message;
                message = pc.decrypt(messages.get(i).toString());
                messages.put(i, PubnubUtil.stringToJSON(message));
            }
        }
    }


    private void _subscribe(Hashtable args) {

        String[] channelList = (String[]) args.get("channels");
        String[] groupList = (String[]) args.get("groups");

        if (channelList == null) {
            channelList = new String[0];
        }

        if (groupList == null) {
            groupList = new String[0];
        }

        Callback callback = (Callback) args.get("callback");
        String timetoken = (String) args.get("timetoken");

        if (!_timetoken.equals("0"))
            _saved_timetoken = _timetoken;
        _timetoken = (timetoken == null) ? "0" : timetoken;



        for (int i = 0; i < channelList.length; i++) {
            String channel = channelList[i];
            SubscriptionItem channelObj = (SubscriptionItem) channelSubscriptions.getItem(channel);

            if (channelObj == null) {
                SubscriptionItem ch = new SubscriptionItem(channel, callback);

                channelSubscriptions.addItem(ch);
            }
        }

        for (int i = 0; i < groupList.length; i++) {
            String group = groupList[i];
            SubscriptionItem channelGroupObj = (SubscriptionItem) channelGroupSubscriptions.getItem(group);

            if (channelGroupObj == null) {
                SubscriptionItem chg = new SubscriptionItem(group, callback);

                channelGroupSubscriptions.addItem(chg);
            }
        }

        _subscribe_base(true);
    }

    private void _subscribe_base(boolean fresh) {
        _subscribe_base(fresh, false, null);
    }
    private void _subscribe_base(boolean fresh, boolean dar) {
        _subscribe_base(fresh, dar, null);
    }

    private void _subscribe_base(Worker worker) {
        _subscribe_base(false, false, worker);
    }

    private void _subscribe_base(boolean fresh, Worker worker) {
        _subscribe_base(fresh, false, worker);
    }

    private boolean isWorkerDead(HttpRequest hreq) {
        return (hreq == null || hreq.getWorker() == null)?false:hreq.getWorker()._die;
    }
    private void _subscribe_base(boolean fresh, boolean dar, Worker worker) {
        String channelString = channelSubscriptions.getItemString();
        String groupString = channelGroupSubscriptions.getItemString();
        String[] channelsArray = channelSubscriptions.getItemNames();
        String[] groupsArray = channelGroupSubscriptions.getItemNames();

        if (channelsArray.length <= 0) {
            subscribeManager.resetHttpManager();
            return;
		}
        if (channelString == null) {
            callErrorCallbacks(channelsArray,
                    PubnubError.PNERROBJ_PARSING_ERROR);
            return;
        }

        if (channelString.equals("")) {
            channelString = ",";
        } else {
            channelString = PubnubUtil.urlEncode(channelString);
        }

        String[] urlComponents = { getPubnubUrl(), "subscribe",
                PubnubCore.this.SUBSCRIBE_KEY,
                channelString, "0", _timetoken
        };

        Hashtable params = PubnubUtil.hashtableClone(this.params);
        params.put("uuid", UUID);

        if (groupsArray.length > 0) {
            params.put("channel-group", groupString);
        }

        String st  = getState();
        if (st != null) params.put("state", st);

        if (HEARTBEAT > 5 && HEARTBEAT < 320) params.put("heartbeat", String.valueOf(HEARTBEAT));
        log.verbose("Subscribing with timetoken : " + _timetoken);

        HttpRequest hreq = new HttpRequest(urlComponents, params,
                new ResponseHandler() {

            public void handleResponse(HttpRequest hreq, String response) {



                JSONArray jsa;
                try {
                    jsa = new JSONArray(response);

                    _timetoken = (!_saved_timetoken.equals("0") && isResumeOnReconnect()) ? _saved_timetoken
                            : jsa.get(1).toString();
                    log.verbose("Resume On Reconnect is "
                            + isResumeOnReconnect());
                    log.verbose("Saved Timetoken : " + _saved_timetoken);
                    log.verbose("In Response Timetoken : "
                            + jsa.get(1).toString());
                    log.verbose("Timetoken value set to " + _timetoken);
                    _saved_timetoken = "0";
                    log.verbose("Saved Timetoken reset to 0");

                    if (!hreq.isDar()) {
                        channelSubscriptions.invokeConnectCallbackOnItems(_timetoken);
                        channelGroupSubscriptions.invokeConnectCallbackOnItems(_timetoken);
                    } else {
                        channelSubscriptions.invokeReconnectCallbackOnItems(_timetoken);
                        channelGroupSubscriptions.invokeReconnectCallbackOnItems(_timetoken);
                    }

                    JSONArray messages = new JSONArray(jsa.get(0).toString());

                    if (jsa.length() == 4) {
                        String[] _groups = PubnubUtil.splitString(jsa.getString(2), ",");
                        String[] _channels = PubnubUtil.splitString(jsa.getString(3), ",");

                        for (int i = 0; i < _channels.length; i++) {
                            String _groupName = _groups[i];
                            String _channelName = _channels[i];
                            Object message = messages.get(i);

                            SubscriptionItem _group = channelGroupSubscriptions.getItem(_groups[i]);
                            SubscriptionItem _channel = channelSubscriptions.getItem(_groups[i]);

                            if (_groupName.equals(_channelName)
                                && _channel != null
                                && !isWorkerDead(hreq)
                            ) {
                                invokeSubscribeCallback(_channelName, _channel.callback,
                                        message, hreq);
                            } else if (!_groupName.equals(_channelName)
                                    && _group != null
                                    && !isWorkerDead(hreq)
                            ) {
                                invokeSubscribeCallback(_channelName, _group.callback,
                                        message, hreq);
                            }
                        }
                    } else if(jsa.length() == 3) {


                        String[] _channels = PubnubUtil.splitString(jsa.getString(2), ",");

                        for (int i = 0; i < _channels.length; i++) {
                            SubscriptionItem _channel = channelSubscriptions.getItem(_channels[i]);
                            Object message = messages.get(i);

                            if (_channel != null) {
                                invokeSubscribeCallback(_channel.name, _channel.callback,
                                        message, hreq);
                            }
                        }
                    } else if(jsa.length() < 3) {

                        SubscriptionItem _channel = channelSubscriptions.getFirstItem();

                        if (_channel != null) {
                            for (int i = 0; i < messages.length(); i++) {
                                Object message = messages.get(i);
                                invokeSubscribeCallback(_channel.name, _channel.callback,
                                        message, hreq);
                            }
                        }

                    }
                    if (hreq.isSubzero()) {
                        log.verbose("Response of subscribe 0 request. Need to do dAr process again");
                        _subscribe_base(false, hreq.isDar(), hreq.getWorker());
                    } else
                        _subscribe_base(false);
                } catch (JSONException e) {
                    if (hreq.isSubzero()) {
                        log.verbose("Response of subscribe 0 request. Need to do dAr process again");
                        _subscribe_base(false, hreq.isDar(), hreq.getWorker());
                    } else
                        _subscribe_base(false, hreq.getWorker());
                }

            }

            public void handleBackFromDar(HttpRequest hreq) {
                _subscribe_base(false, hreq.getWorker());
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                disconnectAndResubscribe(error);
            }

            public void handleTimeout(HttpRequest hreq) {
                log.verbose("Timeout Occurred, Calling disconnect callbacks on the channels");
                String timeoutTimetoken = (isResumeOnReconnect()) ? (_timetoken
                        .equals("0")) ? _saved_timetoken : _timetoken
                                : "0";
                log.verbose("Timeout Timetoken : " + timeoutTimetoken);
                channelSubscriptions.invokeDisconnectCallbackOnItems(timeoutTimetoken);
                channelGroupSubscriptions.invokeDisconnectCallbackOnItems(timeoutTimetoken);
                channelSubscriptions.invokeErrorCallbackOnItems(
                        PubnubError.getErrorObject(PubnubError.PNERROBJ_TIMEOUT, 1)
                );
                channelGroupSubscriptions.invokeErrorCallbackOnItems(
                        PubnubError.getErrorObject(PubnubError.PNERROBJ_TIMEOUT, 1)
                );
            }

            public String getTimetoken() {
                return _timetoken;
            }
        });
        if (_timetoken.equals("0")) {
            hreq.setSubzero(true);
            log.verbose("This is a subscribe 0 request");
        }
        hreq.setDar(dar);
        if ( worker != null && worker instanceof Worker )
            hreq.setWorker(worker);
        _request(hreq, subscribeManager, fresh);
    }

    private void invokeSubscribeCallback(String channel, Callback callback, Object message,
                                         HttpRequest hreq) throws JSONException {
        if (CIPHER_KEY.length() > 0
                && !channel
                .endsWith(PRESENCE_SUFFIX)) {
            PubnubCrypto pc = new PubnubCrypto(
                    CIPHER_KEY, IV);
            try {
                message = pc.decrypt(message.toString());
                if (!isWorkerDead(hreq)) callback
                        .successCallback(
                                channel,
                                PubnubUtil.parseJSON(PubnubUtil.stringToJSON(message.toString())));
            } catch (DataLengthException e) {
                if (!isWorkerDead(hreq)) callback
                        .errorCallback(
                                channel,
                                PubnubError.getErrorObject(
                                        PubnubError.PNERROBJ_DECRYPTION_ERROR, 11,
                                        message.toString()));
            } catch (IllegalStateException e) {
                if (!isWorkerDead(hreq)) callback
                        .errorCallback(
                                channel,
                                PubnubError.getErrorObject(
                                        PubnubError.PNERROBJ_DECRYPTION_ERROR, 12,
                                        message.toString()));
            } catch (InvalidCipherTextException e) {
                if (!isWorkerDead(hreq)) callback
                        .errorCallback(
                                channel,
                                PubnubError.getErrorObject(
                                        PubnubError.PNERROBJ_DECRYPTION_ERROR, 13,
                                        message.toString()));
            } catch (IOException e) {
                if (!isWorkerDead(hreq)) callback
                        .errorCallback(
                                channel,
                                PubnubError.getErrorObject(
                                        PubnubError.PNERROBJ_DECRYPTION_ERROR, 14,
                                        message.toString()));
            } catch (Exception e) {
                if (!isWorkerDead(hreq)) callback
                        .errorCallback(
                                channel,
                                PubnubError.getErrorObject(
                                        PubnubError.PNERROBJ_DECRYPTION_ERROR, 15,
                                        message.toString() + " : " + e.toString()));
            }
        } else {
            if (!isWorkerDead(hreq)) callback.successCallback(
                    channel,
                    PubnubUtil.parseJSON(message));
        }
    }


    private void _request(final HttpRequest hreq, RequestManager connManager,
            boolean abortExisting) {
        if (abortExisting) {
            connManager.resetHttpManager();
        }
        connManager.queue(hreq);
    }


    protected void _request(final HttpRequest hreq,
            RequestManager simpleConnManager) {
        _request(hreq, simpleConnManager, false);
    }

    private int getRandom() {
        return Math.abs(this.generator.nextInt());
    }

    private void changeOrigin() {
        this.ORIGIN_STR = null;
        this.HOSTNAME_SUFFIX = getRandom();
    }

    private void resubscribe() {
        changeOrigin();
        if (!_timetoken.equals("0"))
            _saved_timetoken = _timetoken;
        _timetoken = "0";
        log.verbose("Before Resubscribe Timetoken : " + _timetoken);
        log.verbose("Before Resubscribe Saved Timetoken : " + _saved_timetoken);
        _subscribe_base(true, true);
    }

    private void resubscribe(String timetoken) {
        changeOrigin();
        if (!timetoken.equals("0"))
            _saved_timetoken = timetoken;
        _timetoken = "0";
        log.verbose("Before Resubscribe Timetoken : " + _timetoken);
        log.verbose("Before Resubscribe Saved Timetoken : " + _saved_timetoken);
        _subscribe_base(true, true);
    }


    public void disconnectAndResubscribeWithTimetoken(String timetoken) {
        disconnectAndResubscribeWithTimetoken(timetoken,
                PubnubError.PNERROBJ_DISCONN_AND_RESUB);
    }

    public void disconnectAndResubscribeWithTimetoken(String timetoken,
            PubnubError error) {
        log.verbose("Received disconnectAndResubscribeWithTimetoken");
        channelSubscriptions.invokeErrorCallbackOnItems(error);
        channelGroupSubscriptions.invokeErrorCallbackOnItems(error);
        resubscribe(timetoken);
    }


    public void disconnectAndResubscribe() {
        disconnectAndResubscribe(PubnubError.PNERROBJ_DISCONNECT);
    }


    public void disconnectAndResubscribe(PubnubError error) {
        log.verbose("Received disconnectAndResubscribe");
        channelSubscriptions.invokeErrorCallbackOnItems(error);
        channelGroupSubscriptions.invokeErrorCallbackOnItems(error);
        resubscribe();
    }


    public String[] getSubscribedChannelsArray() {
        return channelSubscriptions.getItemNames();
    }


    public void setOrigin(String origin) {
        this.HOSTNAME = origin;
    }


    public String getOrigin() {
        return this.HOSTNAME;
    }


    public void setDomain(String domain) {
        this.DOMAIN = domain;
    }

    public String getDomain() {
        return this.DOMAIN;
    }


    public String getAuthKey() {
        return this.AUTH_STR;
    }


    public void setAuthKey(String authKey) {

        this.AUTH_STR = authKey;
        if (authKey == null || authKey.length() == 0) {
            params.remove("auth");
        } else {
            params.put("auth", this.AUTH_STR);
        }
        resubscribe();
    }


    public void unsetAuthKey() {
        this.AUTH_STR = null;
        params.remove("auth");
        resubscribe();
    }

}
