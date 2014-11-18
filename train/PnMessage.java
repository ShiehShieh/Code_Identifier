package com.pubnub.api;

import org.json.JSONException;
import org.json.JSONObject;





public class PnMessage extends JSONObject {
    private String channel;
    private Callback callback;
    private Pubnub pubnub;



    public PnMessage(Pubnub pubnub, String channel, Callback callback) {
        super();
        this.channel  = channel;
        this.callback = callback;
        this.pubnub = pubnub;
    }


    public PnMessage() {
        super();
    }


    public PnMessage(PnApnsMessage apnsMsg, PnGcmMessage gcmMsg) {
        super();
        try {
            if (apnsMsg != null) {
                this.put("pn_apns", apnsMsg);
            }
            if (gcmMsg != null) {
                this.put("pn_gcm", gcmMsg);
            }
        } catch (JSONException e) {

        }
    }


    public PnMessage(Pubnub pubnub, String channel, Callback callback, PnApnsMessage apnsMsg, PnGcmMessage gcmMsg) {
        super();
        this.channel = channel;
        this.callback = callback;
        this.pubnub = pubnub;
        try {
            if (apnsMsg != null) {
                this.put("pn_apns", apnsMsg);
            }
            if (gcmMsg != null) {
                this.put("pn_gcm", gcmMsg);
            }
        } catch (JSONException e) {

        }
    }


    public String getChannel() {
        return channel;
    }


    public void setChannel(String channel) {
        this.channel = channel;
    }


    public Callback getCallback() {
        return callback;
    }


    public void setCallback(Callback callback) {
        this.callback = callback;
    }


    public Pubnub getPubnub() {
        return pubnub;
    }


    public void setPubnub(Pubnub pubnub) {
        this.pubnub = pubnub;
    }


    public PnMessage(PnGcmMessage gcmMsg) {
        super();
        try {
            if (gcmMsg != null) {
                this.put("pn_gcm", gcmMsg);
            }
        } catch (JSONException e) {

        }
    }


    public PnMessage(Pubnub pubnub, String channel, Callback callback, PnGcmMessage gcmMsg) {
        super();
        this.channel = channel;
        this.callback = callback;
        this.pubnub = pubnub;
        try {
            if (gcmMsg != null) {
                this.put("pn_gcm", gcmMsg);
            }
        } catch (JSONException e) {

        }
    }


    public PnMessage(PnApnsMessage apnsMsg) {
        super();
        try {
            if (apnsMsg != null) {
                this.put("pn_apns", apnsMsg);
            }
        } catch (JSONException e) {

        }
    }


    public PnMessage(Pubnub pubnub, String channel, Callback callback, PnApnsMessage apnsMsg) {
        super();
        this.channel = channel;
        this.callback = callback;
        this.pubnub = pubnub;
        try {
            if (apnsMsg != null) {
                this.put("pn_apns", apnsMsg);
            }
        } catch (JSONException e) {

        }
    }


    public void publish(Pubnub pubnub, String channel, Callback callback) throws PubnubException  {
        this.channel = channel;
        this.callback = callback;
        this.pubnub = pubnub;
        if (this.channel == null) {
            throw new PubnubException(PubnubError.PNERROBJ_CHANNEL_MISSING);
        }
        if (this.pubnub == null) {
            throw new PubnubException(PubnubError.PNERROBJ_CONNECTION_NOT_SET);
        }
        pubnub.publish(channel, this, callback);
    }


    public void publish() throws PubnubException {
        if (this.channel == null) {
            throw new PubnubException(PubnubError.PNERROBJ_CHANNEL_MISSING);
        }
        if (this.pubnub == null) {
            throw new PubnubException(PubnubError.PNERROBJ_CONNECTION_NOT_SET);
        }
        pubnub.publish(channel, this, callback);
    }

}
