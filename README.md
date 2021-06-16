# uFR Java Get PAN example

EMV_GetPan() Java example with the implementation of JNI and uFCoder API. Suggested IDE: Eclipse. Tested with JavaSE-15
#### Getting Started
Consult documentation for API reference on function calls.
Use the following commands to generate the 'uFCoder_JNI.dll' which is mandatory for running this example.
* javac com/dlogic/uFCoder.java
* javah com.dlogic.uFCoder
* g++ -I"%JAVA_HOME%\include" -I"%JAVA_HOME%\include\win32" -Iinclude -shared -Llib -luFCoder-x86_64 -o uFCoder_JNI.dll uFCoder.cpp

After the creation of 'uFCoder_JNI.dll' file, edit line 7 in 'jni_example.java' file to match the path where 'uFCoder_JNI.dll' is located. 
Since 'uFCoder.cpp' contains most of the function calls in our API. Simply edit 'uFCoder.java' to expose API function to this project. Make sure that function import contains proper variable types (e.g 'uint8_t' in C/C++ is 'byte' in Java)

# Run the example
Navigate to 'dist' folder and simply run the software with:
* java -jar ufr-get_pan_java_jni_example.jar