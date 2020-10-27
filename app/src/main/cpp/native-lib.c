#include <jni.h>
#include <string.h>
#include <android/log.h>
#define LOG_TAG "log_dkhai"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)


jstring Java_com_dkhai_myapplication_MainActivity_add(JNIEnv* env, jobject thiz , jint x, jint y)
{
    LOGI("JNI_log : x = %d , y = %d" , x , y);
    return x + y;
}

// Chuyển kiểu jstring trong java thành chuỗi char trong ngôn ngữ c
char* Jstring2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "utf-8");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",
                                        "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid,
                                                           strencode);
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char*) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);
    return rtn;
}



jstring Java_com_dkhai_myapplication_MainActivity_sayHelloInc(JNIEnv *env, jobject obj, jstring str)
{
    char *p = (char*)Jstring2CStr(env, str);
    // In du lieu java
    LOGI("Java JNI string parameter is : %s", p);

    char *append = "append";
    //strcat(dest, source)
    return (*env)->NewStringUTF(env, strcat(p, append));
}

jintArray Java_com_dkhai_myapplication_MainActivity_intMethod(JNIEnv *env, jobject obj, jintArray arr)
{
    int len = (*env)->GetArrayLength(env, arr);

    LOGI("the length of array is %d", len);

    if(len == 0)
        return arr;

    jint* p = (*env)->GetIntArrayElements(env, arr, 0);

    int i = 0;
    for(; i < len; i ++)
    {
        LOGI("arr[%d] = %d", i, *(p + i));
    }

    return arr;

}