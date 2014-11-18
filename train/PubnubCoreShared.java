package com.pubnub.api;

import javax.crypto.Mac;
import javax.crypto.spec.SecretKeySpec;
import java.io.UnsupportedEncodingException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Date;
import java.util.Hashtable;
import java.util.UUID;

import static com.pubnub.api.PubnubError.PNERROBJ_SECRET_KEY_MISSING;
import static com.pubnub.api.PubnubError.getErrorObject;



abstract class PubnubCoreShared extends PubnubCore {


    public PubnubCoreShared(String publish_key, String subscribe_key, String secret_key,
                  String cipher_key, boolean ssl_on) {
        super(publish_key, subscribe_key, secret_key, cipher_key, ssl_on);
    }


    public PubnubCoreShared(String publish_key, String subscribe_key, String secret_key,
                  boolean ssl_on) {
        super(publish_key, subscribe_key, secret_key, "", ssl_on);
    }


    public PubnubCoreShared(String publish_key, String subscribe_key) {
        super(publish_key, subscribe_key, "", "", false);
    }


    public PubnubCoreShared(String publish_key, String subscribe_key, boolean ssl) {
        super(publish_key, subscribe_key, "", "", ssl);
    }


    public PubnubCoreShared(String publish_key, String subscribe_key, String secret_key) {
        super(publish_key, subscribe_key, secret_key, "", false);
    }



    public PubnubCoreShared(String publish_key, String subscribe_key,
                  String secret_key, String cipher_key, boolean ssl_on, String initialization_vector) {
        super(publish_key, subscribe_key, secret_key, cipher_key, ssl_on, initialization_vector);
    }


    public void setUUID(UUID uuid) {
        this.UUID = uuid.toString();
    }

    public String uuid() {
        return java.util.UUID.randomUUID().toString();
    }


    public void setSubscribeTimeout(int timeout) {
        super.setSubscribeTimeout(timeout);
    }


    public int getSubscribeTimeout() {
        return super.getSubscribeTimeout();
    }


    public void setNonSubscribeTimeout(int timeout) {
        super.setNonSubscribeTimeout(timeout);
    }

    public int getNonSubscribeTimeout() {
        return super.getNonSubscribeTimeout();
    }

    private String pamSign(String key, String data) throws PubnubException {
        Mac sha256_HMAC;

        try {
            sha256_HMAC = Mac.getInstance("HmacSHA256");
            SecretKeySpec secret_key = new SecretKeySpec(key.getBytes(),
                    "HmacSHA256");
            sha256_HMAC.init(secret_key);
            byte[] hmacData = sha256_HMAC.doFinal(data.getBytes("UTF-8"));
            return new String(Base64Encoder.encode(hmacData)).replace('+', '-')
                   .replace('/', '_');
        } catch (InvalidKeyException e1) {
            throw new PubnubException(getErrorObject(PubnubError.PNERROBJ_ULSSIGN_ERROR, 1, "Invalid Key : " + e1.toString()));
        } catch (NoSuchAlgorithmException e1) {
            throw new PubnubException(getErrorObject(PubnubError.PNERROBJ_ULSSIGN_ERROR, 2, "Invalid Algorithm : " + e1.toString()));
        } catch (IllegalStateException e1) {
            throw new PubnubException(getErrorObject(PubnubError.PNERROBJ_ULSSIGN_ERROR, 3, "Invalid State : " + e1.toString()));
        } catch (UnsupportedEncodingException e1) {
            throw new PubnubException(getErrorObject(PubnubError.PNERROBJ_ULSSIGN_ERROR, 4, "Unsupported encoding : " + e1.toString()));
        }
    }


    public void pamGrant(final String channel, String auth_key, boolean read,
                         boolean write, final Callback callback) {
        pamGrant(channel, auth_key, read, write, -1, callback);
    }


    public void pamGrant(final String channel, boolean read,
                         boolean write, final Callback callback) {
        pamGrant(channel, null, read, write, -1, callback);
    }


    public void pamGrant(final String channel, boolean read,
                         boolean write, int ttl, final Callback callback) {
        pamGrant(channel, null, read, write, ttl, callback);
    }


    public void pamGrant(final String channel, String auth_key, boolean read,
                         boolean write, int ttl, Callback callback) {
        final Callback cb = getWrappedCallback(callback);
        Hashtable parameters = PubnubUtil.hashtableClone(params);

        String r = (read) ? "1" : "0";
        String w = (write) ? "1" : "0";

        String signature = "0";

        int timestamp = (int) ((new Date().getTime()) / 1000);

        if (this.SECRET_KEY.length() == 0) {
            callback.errorCallback(channel,
                                   getErrorObject(PNERROBJ_SECRET_KEY_MISSING, 1));
            return;
        }

        String sign_input = this.SUBSCRIBE_KEY + "\n" + this.PUBLISH_KEY + "\n" + "grant" + "\n" ;

        if (auth_key != null && auth_key.length() > 0)
            sign_input += "auth=" + auth_key + "&"  ;

        sign_input += "channel=" + PubnubUtil.urlEncode(channel) + "&" + "pnsdk=" + PubnubUtil.urlEncode(getUserAgent()) + "&" + "r=" + r + "&" + "timestamp=" + timestamp
                            + ((ttl >= -1)?"&" + "ttl=" + ttl:"")
                            + "&" + "w=" + w;


        try {
            signature = pamSign(this.SECRET_KEY, sign_input);
        } catch (PubnubException e1) {
            callback.errorCallback(channel,
                                   e1.getPubnubError());
            return;
        }


        parameters.put("w", w);
        parameters.put("timestamp", String.valueOf(timestamp));
        parameters.put("signature", signature);
        parameters.put("r", r);
        parameters.put("channel", channel);

        if (auth_key != null && auth_key.length() > 0 ) parameters.put("auth", auth_key);
        if (ttl >= -1) parameters.put("ttl", String.valueOf(ttl));

        String[] urlComponents = { getPubnubUrl(), "v1", "auth", "grant", "sub-key",
                                   this.SUBSCRIBE_KEY
                                 };

        HttpRequest hreq = new HttpRequest(urlComponents, parameters,
        new ResponseHandler() {
            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback(channel, response, "payload", cb, 4);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(channel, error);
                return;
            }
        });

        _request(hreq, nonSubscribeManager);

    }

    public void pamGrantChannelGroup(final String group, boolean read,
                                     boolean management, Callback callback) {
        pamGrantChannelGroup(group, read, management, -1, callback);
    }

    public void pamGrantChannelGroup(final String group, boolean read,
                                     boolean management, int ttl, Callback callback) {
        pamGrantChannelGroup(group, null, read, management, ttl, callback);
    }

    public void pamGrantChannelGroup(final String group, String auth_key, boolean read,
                                     boolean management, Callback callback) {
        pamGrantChannelGroup(group, auth_key, read, management, -1, callback);
    }

    public void pamGrantChannelGroup(final String group, String auth_key, boolean read, boolean management, int ttl,
                                               Callback callback) {
        String signature;
        final Callback cb = getWrappedCallback(callback);
        Hashtable parameters = PubnubUtil.hashtableClone(params);

        String r = (read) ? "1" : "0";
        String m = (management) ? "1" : "0";

        int timestamp = (int) ((new Date().getTime()) / 1000);

        if (this.SECRET_KEY.length() == 0) {
            callback.errorCallback(group, getErrorObject(PNERROBJ_SECRET_KEY_MISSING, 1));
            return;
        }

        String sign_input = this.SUBSCRIBE_KEY + "\n" + this.PUBLISH_KEY + "\n" + "grant" + "\n";

        if (auth_key != null && auth_key.length() > 0)
            sign_input += "auth=" + auth_key + "&"  ;

        sign_input += "channel-group=" + PubnubUtil.urlEncode(group) + "&"
                + "m=" + m + "&"
                + "pnsdk=" + PubnubUtil.urlEncode(getUserAgent()) + "&"
                + "r=" + r + "&"
                + "timestamp=" + timestamp
                + ((ttl >= -1)?"&" + "ttl=" + ttl:"");

        try {
            signature = pamSign(this.SECRET_KEY, sign_input);
        } catch (PubnubException e1) {
            callback.errorCallback(group, e1.getPubnubError());
            return;
        }

        parameters.put("timestamp", String.valueOf(timestamp));
        parameters.put("signature", signature);
        parameters.put("r", r);
        parameters.put("m", m);
        parameters.put("channel-group", group);

        if (ttl >= -1) parameters.put("ttl", String.valueOf(ttl));
        if (auth_key != null && auth_key.length() > 0 ) parameters.put("auth", auth_key);

        String[] urlComponents = { getPubnubUrl(), "v1", "auth", "grant", "sub-key",
                this.SUBSCRIBE_KEY
        };

        HttpRequest hreq = new HttpRequest(urlComponents, parameters,
                new ResponseHandler() {
                    public void handleResponse(HttpRequest hreq, String response) {
                        invokeCallback(group, response, "payload", cb, 4);
                    }

                    public void handleError(HttpRequest hreq, PubnubError error) {
                        cb.errorCallback(group, error);
                    }
                });

        _request(hreq, nonSubscribeManager);
    }


    public void pamAudit(Callback callback) {

        final Callback cb = getWrappedCallback(callback);

        Hashtable parameters = PubnubUtil.hashtableClone(params);
        parameters.remove("auth");

        String signature = "0";

        int timestamp = (int) ((new Date().getTime()) / 1000);

        if (this.SECRET_KEY.length() == 0) {
            callback.errorCallback("",
                                   getErrorObject(PNERROBJ_SECRET_KEY_MISSING, 2));
            return;
        }

        String sign_input = this.SUBSCRIBE_KEY + "\n" + this.PUBLISH_KEY + "\n"
                            + "audit" + "\n" + "pnsdk=" + PubnubUtil.urlEncode(getUserAgent()) + "&"
                            + "timestamp=" + timestamp;


        try {
            signature = pamSign(this.SECRET_KEY, sign_input);
        } catch (PubnubException e1) {
            callback.errorCallback("",
                                   e1.getPubnubError());
            return;
        }

        parameters.put("timestamp", String.valueOf(timestamp));
        parameters.put("signature", signature);

        String[] urlComponents = { getPubnubUrl(), "v1", "auth", "audit", "sub-key",
                                   this.SUBSCRIBE_KEY
                                 };

        HttpRequest hreq = new HttpRequest(urlComponents, parameters,
        new ResponseHandler() {
            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback("", response, "payload", cb, 5 );
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback("", error);
                return;
            }
        });

        _request(hreq, nonSubscribeManager);

    }


    public void pamAudit(final String channel,
                         Callback callback) {

        final Callback cb = getWrappedCallback(callback);

        Hashtable parameters = PubnubUtil.hashtableClone(params);
        parameters.remove("auth");

        String signature = "0";

        int timestamp = (int) ((new Date().getTime()) / 1000);

        if (this.SECRET_KEY.length() == 0) {
            callback.errorCallback(channel,
                                   getErrorObject(PNERROBJ_SECRET_KEY_MISSING , 3));
            return;
        }

        String sign_input = this.SUBSCRIBE_KEY + "\n" + this.PUBLISH_KEY + "\n"
                            + "audit" + "\n" + "channel="
                            + PubnubUtil.urlEncode(channel) + "&" + "pnsdk=" + PubnubUtil.urlEncode(getUserAgent()) + "&" + "timestamp=" + timestamp;

        try {
            signature = pamSign(this.SECRET_KEY, sign_input);
        } catch (PubnubException e1) {
            callback.errorCallback(channel,
                                   e1.getPubnubError());
            return;
        }

        parameters.put("timestamp", String.valueOf(timestamp));
        parameters.put("signature", signature);
        parameters.put("channel", channel);

        String[] urlComponents = { getPubnubUrl(), "v1", "auth", "audit", "sub-key",
                                   this.SUBSCRIBE_KEY
                                 };

        HttpRequest hreq = new HttpRequest(urlComponents, parameters,
        new ResponseHandler() {
            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback(channel, response, "payload", cb, 6);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(channel, error);
                return;
            }
        });

        _request(hreq, nonSubscribeManager);

    }


    public void pamAudit(final String channel, String auth_key,
                         Callback callback) {

        final Callback cb = getWrappedCallback(callback);
        Hashtable parameters = PubnubUtil.hashtableClone(params);

        String signature = "0";

        int timestamp = (int) ((new Date().getTime()) / 1000);

        if (this.SECRET_KEY.length() == 0) {
            callback.errorCallback(channel,
                                   getErrorObject(PNERROBJ_SECRET_KEY_MISSING, 4));
            return;
        }

        String sign_input = this.SUBSCRIBE_KEY + "\n" + this.PUBLISH_KEY + "\n"
                            + "audit" + "\n" + "auth=" + PubnubUtil.urlEncode(auth_key) + "&" + "channel="
                            + PubnubUtil.urlEncode(channel) + "&" + "pnsdk=" + PubnubUtil.urlEncode(getUserAgent()) + "&" + "timestamp=" + timestamp;


        try {
            signature = pamSign(this.SECRET_KEY, sign_input);
        } catch (PubnubException e1) {
            callback.errorCallback(channel,
                                   e1.getPubnubError());
            return;
        }

        parameters.put("timestamp", String.valueOf(timestamp));
        parameters.put("signature", signature);
        parameters.put("channel", channel);
        parameters.put("auth", auth_key);

        String[] urlComponents = { getPubnubUrl(), "v1", "auth", "audit", "sub-key",
                                   this.SUBSCRIBE_KEY
                                 };

        HttpRequest hreq = new HttpRequest(urlComponents, parameters,
        new ResponseHandler() {
            public void handleResponse(HttpRequest hreq, String response) {
                invokeCallback(channel, response, "payload", cb, 2);
            }

            public void handleError(HttpRequest hreq, PubnubError error) {
                cb.errorCallback(channel, error);
                return;
            }
        });

        _request(hreq, nonSubscribeManager);

    }

    public void pamAuditChannelGroup(final String group, Callback callback) {
        pamAuditChannelGroup(group, null, callback);
    }

    public void pamAuditChannelGroup(final String group, String auth_key, Callback callback) {
        String signature;
        final Callback cb = getWrappedCallback(callback);

        Hashtable parameters = PubnubUtil.hashtableClone(params);
        parameters.remove("auth");

        int timestamp = (int) ((new Date().getTime()) / 1000);

        if (this.SECRET_KEY.length() == 0) {
            callback.errorCallback(group, getErrorObject(PNERROBJ_SECRET_KEY_MISSING, 3));
            return;
        }

        String sign_input = this.SUBSCRIBE_KEY + "\n" + this.PUBLISH_KEY + "\n" + "audit" + "\n";

        if (auth_key != null && auth_key.length() > 0)
            sign_input += "auth=" + auth_key + "&"  ;

        sign_input += "channel-group=" + PubnubUtil.urlEncode(group) + "&"
                + "pnsdk=" + PubnubUtil.urlEncode(getUserAgent()) + "&"
                + "timestamp=" + timestamp;

        try {
            signature = pamSign(this.SECRET_KEY, sign_input);
        } catch (PubnubException e1) {
            callback.errorCallback(group, e1.getPubnubError());
            return;
        }

        parameters.put("timestamp", String.valueOf(timestamp));
        parameters.put("signature", signature);
        parameters.put("channel-group", group);

        if (auth_key != null && auth_key.length() > 0 ) parameters.put("auth", auth_key);

        String[] urlComponents = {getPubnubUrl(), "v1", "auth", "audit", "sub-key",
                this.SUBSCRIBE_KEY
        };

        HttpRequest hreq = new HttpRequest(urlComponents, parameters,
                new ResponseHandler() {
                    public void handleResponse(HttpRequest hreq, String response) {
                        invokeCallback(group, response, "payload", cb, 6);
                    }

                    public void handleError(HttpRequest hreq, PubnubError error) {
                        cb.errorCallback(group, error);
                    }
                });

        _request(hreq, nonSubscribeManager);
    }


    public void pamRevoke(String channel, String auth_key, Callback callback) {
        pamGrant(channel, auth_key, false, false, callback);
    }


    public void pamRevoke(String channel, Callback callback) {
        pamGrant(channel, null, false, false, callback);
    }

    public void pamRevokeChannelGroup(String group, Callback callback) {
        pamRevokeChannelGroup(group, null, callback);
    }

    public void pamRevokeChannelGroup(String group, String auth_key, Callback callback) {
        pamGrantChannelGroup(group, auth_key, false, false, -1, callback);
    }
}
