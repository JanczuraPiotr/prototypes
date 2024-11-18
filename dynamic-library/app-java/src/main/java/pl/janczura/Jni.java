package pl.janczura;

public class Jni {
    static {
        System.loadLibrary("jni");
    }

    public Jni() {

    }

    public native void start();

    public native void print(String text);

    public native String decorate(String text);
}
