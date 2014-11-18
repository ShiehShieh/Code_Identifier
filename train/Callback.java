package com.pubnub.api;


public abstract class Callback {


    public void successCallback(String channel, Object message) {

    }

    public void successCallback(String channel, Object message, String timetoken) {

    }

    void successWrapperCallback(String channel, Object message, String timetoken) {
        successCallback(channel, message);
        successCallback(channel, message, timetoken);
    }


    public void errorCallback(String channel, PubnubError error) {
        errorCallback(channel,error.toString());
    }


    public void errorCallback(String channel, Object message) {

    }

    public void connectCallback(String channel, Object message) {
    }


    public void reconnectCallback(String channel, Object message) {
    }


    public void disconnectCallback(String channel, Object message) {
    }

}
