LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := gmock
LOCAL_SRC_FILES := $(LOCAL_PATH)/../gmock/lib/android/$(TARGET_ARCH_ABI)/libgmock.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := gtest
LOCAL_SRC_FILES := $(LOCAL_PATH)/../gtest/lib/android/$(TARGET_ARCH_ABI)/libgtest.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := vstest
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../gmock/include \
$(LOCAL_PATH)/../gtest/include \
$(LOCAL_PATH)/../../SDK/include \
$(LOCAL_PATH)/../../SDK/include/service

LOCAL_SRC_FILES := ../allTests.cpp \
  ../LogError.cpp \
  ../main.cpp \
  ../TestConfig.cpp \
  ../tinyxml2.cpp \
  ../tools.cpp \
  ../unitest_auth.cpp \
  ../unitest_chat.cpp \
  ../unitest_cloud.cpp \
  ../unitest_config.cpp \
  ../unitest_contact.cpp \
  ../unitest_ext.cpp \
  ../unitest_file.cpp \
  ../unitest_gainter.cpp \
  ../unitest_group.cpp \
  ../unitest_rtc.cpp \
  ../unitest_search.cpp \
  ../unitest_sysmsg.cpp \
  ../unitest_user.cpp \
  
LOCAL_CPPFLAGS := -ffunction-sections -fdata-sections -fvisibility=default
LOCAL_CFLAGS := -ffunction-sections -fdata-sections -fvisibility=default -DSDK_FOR_ANDROID -pie -fPIE
LOCAL_STATIC_LIBRARIES := gmock gtest
LOCAL_LDFLAGS := -pie -fPIE
LOCAL_LDLIBS := -ldl
LOCAL_CFLAGS += -g -o0
LOCAL_CPPFLAGS += -g -o0

LOCAL_ARM_MODE := arm
include $(BUILD_EXECUTABLE)
