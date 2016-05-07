LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := NativeLibrary
LOCAL_SRC_FILES := NativeLibrary.cpp String_Manipulator.cpp Ident.cpp
LOCAL_LDLIBS    := -llog
include $(BUILD_SHARED_LIBRARY)