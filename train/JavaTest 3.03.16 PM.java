
//package com.xie510894496.gmail;

import java.util.*;
import java.lang.reflect.*;

interface Ainterface{
    int output();
    String toString();
}

class Imple implements Ainterface{
    public int output(){return 5;}
    public String toString(){
        Integer i = new Integer(this.output());
        return i.toString();
    }
}

class WaterSource{
    private String s;
    WaterSource(){
        System.out.println("WaterSource()");
        s = "Constructed";
    }
    public String toString(){return s;}
}

class TestForInnerClass extends WaterSource implements Ainterface {
    public static Imple innertest(){
        return new Imple(){
            public String toString(){
                System.out.println("innertest\n");
                return " ";
            }
        };
    }
    public int output(){return 5;}
    public String toString(){return " ";}
}

class Nothing{
    public void donothing(){}
    public String toString(){
        return "Nothing.";
    }
}

class Gp<T>{
    Class<T> cl;
    public Gp(Class<T> cl){
        this.cl = cl;
        System.out.println(cl.getSimpleName());
        Method[] methods = cl.getMethods();
        for (Method method : methods) {
            System.out.println(method);
        }
    }
    public String toString(){
        return cl.getSimpleName();
    }
}

class JavaTest{
    private String value1, value2, value3, value4 ;
    private WaterSource source = new WaterSource();
    private int i;
    private float f;
    public String toString(){
        return "value1 = " + value1 + " "
        + "value2 = " + value2 + " " + "value3 = "
        + value3 + " " + "value4 = " + value4 + "\n"
        + "i = " + i + " " + "f = " + f + " " + "source = "
        + source;
    }
    public static void main(String[] args) {
        Imple imple = new Imple();
        JavaTest javatest = new JavaTest();
        System.out.println(javatest);
        System.out.println(imple);
        imple = TestForInnerClass.innertest();
        System.out.println(imple);
        Gp<Nothing> gs = new Gp<Nothing>(Nothing.class);
        System.out.println(gs);
    }
}
