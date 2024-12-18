#include "jni.h"
#include <string>
#include "pl_janczura_Jni.hpp"
#include "lib.h"

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT void JNICALL Java_pl_janczura_Jni_start (JNIEnv *env, jobject jobject)
{
    (void)env;
    (void)jobject;

    start();
}

JNIEXPORT void JNICALL Java_pl_janczura_Jni_print (JNIEnv *env, jobject jobject,
                                                   jstring input)
{
    std::ignore = jobject;

    if (input == nullptr) {
        print("");
        return;
    }

    const char* chars = env->GetStringUTFChars(input, nullptr);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        print("");
        return;
    }

    if (chars != nullptr) {
        print(chars);
        env->ReleaseStringUTFChars(input, chars);

        if (env->ExceptionCheck()) {
            env->ExceptionDescribe();
            env->ExceptionClear();
            print("");
        }
    } else {
        print("");
    }
}

JNIEXPORT jstring JNICALL Java_pl_janczura_Jni_decorate (JNIEnv *env, jobject jobject,
                                                         jstring input)
{
    std::ignore = jobject;

    if (input == nullptr) {
        const std::string ret = decorate("");
        return env->NewStringUTF(ret.c_str());
    }

    const char *chars = env->GetStringUTFChars(input, JNI_FALSE);

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        std::string ret = decorate("");
        return env->NewStringUTF(ret.c_str());
    }

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
