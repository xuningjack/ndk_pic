LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := ndk_pic
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_SRC_FILES := \
	/Users/xuning/Desktop/+完美世界/+Android JNI NDK初级(Jack 2016.10.14)/Android_ndk_pic1/app/src/main/jni/Android.mk \
	/Users/xuning/Desktop/+完美世界/+Android JNI NDK初级(Jack 2016.10.14)/Android_ndk_pic1/app/src/main/jni/Application.mk \
	/Users/xuning/Desktop/+完美世界/+Android JNI NDK初级(Jack 2016.10.14)/Android_ndk_pic1/app/src/main/jni/com_example_utils_NativeImageUtils.c \

LOCAL_C_INCLUDES += /Users/xuning/Desktop/+完美世界/+Android JNI NDK初级(Jack 2016.10.14)/Android_ndk_pic1/app/src/main/jni
LOCAL_C_INCLUDES += /Users/xuning/Desktop/+完美世界/+Android JNI NDK初级(Jack 2016.10.14)/Android_ndk_pic1/app/src/debug/jni

include $(BUILD_SHARED_LIBRARY)
