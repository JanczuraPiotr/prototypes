#include "jni.h"
#include "pl_janczura_Jni.hpp"
#include "lib.h"

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT void JNICALL Java_pl_janczura_Jni_start (JNIEnv *env, jobject jobject)
{
    std::ignore = env;
    std::ignore = jobject;

    start();
}

JNIEXPORT void JNICALL Java_pl_janczura_Jni_print (JNIEnv *env, jobject jobject,
                                                   jstring input)
{
    std::ignore = jobject;
    const char* chars = env->GetStringUTFChars(input, nullptr);

    if (chars != nullptr) {
        print(chars);
        env->ReleaseStringUTFChars(input, chars);
    } else {
        print("");
    }
}

JNIEXPORT jstring JNICALL Java_pl_janczura_Jni_decorate (JNIEnv *env, jobject jobject,
                                                         jstring input)
{
    std::ignore = jobject;
    const char* chars = env->GetStringUTFChars(input, nullptr);
    std::string ret;
    if (chars != nullptr) {
        ret = decorate(chars);
        env->ReleaseStringUTFChars(input, chars);
    } else {
        ret = decorate("");
    }

    return env->NewStringUTF(ret.c_str());
}

#ifdef __cplusplus
}
#endif
