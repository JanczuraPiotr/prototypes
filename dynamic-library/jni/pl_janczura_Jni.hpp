#ifndef JNI_PLJANCZURALIBJNI
#define JNI_PLJANCZURALIBJNI

#include <jni.h>

JNIEXPORT void JNICALL Java_pl_janczura_Jni_start(JNIEnv *env, jobject jobject);

JNIEXPORT void JNICALL Java_pl_janczura_Jni_print(JNIEnv *env, jobject jobject, jstring input);

JNIEXPORT jstring JNICALL Java_pl_janczura_Jni_decorate(JNIEnv *env, jobject jobject, jstring input);

#endif
