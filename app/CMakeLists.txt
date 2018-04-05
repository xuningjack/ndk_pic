
cmake_minimum_required(VERSION 3.4.1)

# add_definitions(-std=c++11 -frtti -fexceptions)

add_library( # Sets the name of the library.
             ndk_pic

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/jni/com_example_utils_NativeImageUtils.c )

target_link_libraries( # Specifies the target library.
                       ndk_pic

                       # Links the target library to the log library
                       # included in the NDK.
                       log )
