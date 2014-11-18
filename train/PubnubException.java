package com.pubnub.api;


public class PubnubException extends Exception {
    private String errormsg = "";
    private PubnubError pubnubError = PubnubError.PNERROBJ_PUBNUB_ERROR;



    public PubnubException(String s) {
        this.errormsg = s;
    }


    public PubnubException(PubnubError pubnubError) {
        this.pubnubError = pubnubError;
    }


    public PubnubException(PubnubError pubnubError, String s) {
        this.errormsg = s;
        this.pubnubError = pubnubError;
    }



    public String toString() {
        String msg = pubnubError.toString();
        if (errormsg.length() > 0 )
            msg = msg + " . " + errormsg;
        return msg;
    }

    public PubnubError getPubnubError() {
        return pubnubError;
    }

}
