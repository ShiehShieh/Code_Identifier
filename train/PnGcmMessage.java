package com.pubnub.api;

import org.json.JSONException;
import org.json.JSONObject;


public class PnGcmMessage extends JSONObject {


    public PnGcmMessage() {
        super();
    }


    public PnGcmMessage(JSONObject json) {
        super();
        setData(json);
    }

    public void setData(JSONObject json) {
        try {
            this.put("data", json);
        } catch (JSONException e) {

        }
    }
}
