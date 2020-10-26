#include <string.h>
#include <jni.h>

//
// Created by dkhai on 26/10/2020.
//

jstring Java_com_dkhai_myapplication_MainActivity_stringFromJNI( JNIEnv* env, jobject thiz )
{
    return (*env)->NewStringUTF(env, "Hello from C");
}