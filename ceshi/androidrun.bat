adb devices

adb shell chmod 777 /data/workspace/vstest


adb shell "cd %1/xmlconfig && mv vrvconfig.xml config.xml"

adb shell "cd %1 && sh ./android.sh"

adb shell "cd %1 && mv test_detail.xml vrv_test_detail.xml"

adb shell "cd %1/xmlconfig && mv config.xml vrvconfig.xml"


adb shell "cd %1/xmlconfig && mv bxyconfig.xml config.xml"

adb shell "cd %1 && sh ./android.sh"

adb shell "cd %1 && mv test_detail.xml bxy_test_detail.xml"

adb shell "cd %1/xmlconfig && mv config.xml bxyconfig.xml"




adb shell "cd %1/xmlconfig && mv imconfig.xml config.xml"

adb shell "cd %1 && sh ./android.sh"

adb shell "cd %1 && mv test_detail.xml im_test_detail.xml"

adb shell "cd %1/xmlconfig && mv config.xml imconfig.xml"



adb pull %1/vrv_test_detail.xml E:/workspace/android-unitest/master/Bin/
adb pull %1/bxy_test_detail.xml E:/workspace/android-unitest/master/Bin/
adb pull %1/im_test_detail.xml E:/workspace/android-unitest/master/Bin/

adb shell "cd %1 && rm bxy_test_detail.xml vrv_test_detail.xml im_test_detail.xml"


