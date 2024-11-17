package pl.janczura;

public class Main {

    public static void main(String[] args) {

        Jni jni = new Jni();

        jni.start();
        jni.print("String without decoration.");
        jni.print(jni.decorate("String with decoration."));

    }
}