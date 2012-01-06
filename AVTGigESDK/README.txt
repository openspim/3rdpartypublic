### AVT PvAPI GigE SDK 1.26 for Mac OS X
### README
###
### 09/29/11
###

*************************************************************************
* Notes
*************************************************************************

* Up to and including Mac OS X Snow Leopard, the OS does not support multicasting. 

* The MTU of the GigE adapter MUST be changed to Jumbo frames (9000). See System Preferences -> Network -> Ethernet -> Advanced ->Ethernet -> MTU, or use command line "ifconfig". If a lower MTU is used, camera connection will drop when camera stream or control network traffic floods to NIC.

* A route for 255.255.255.255 may need to be added to point to the adapter on which the camera will be plugged (or to the switch on which the camera will be). This can be done with the following command:

  > sudo route -n add 255.255.255.255 169.254.42.97

where 169.254.42.97 is the IP (self-assigned or assigned by you) of the adapter


*************************************************************************
* Compilation
*************************************************************************

* This distribution support x86,x64 for OS X 10.5 to 10.7. Modify the "ARCH" file located in the Examples directory before building the samples to select the proper architecture: x86 or x64.

* The shared library in ./bin-pc is usable with software compiled with either GCC 4.2

* Static libraries are provides for GCC 4.2, they can be found in ./lib-pc

* Each of the sample code can be build as follow:

  > make sample ; make install

The executables will be copied into the ./bin-pc folder.


*************************************************************************
* SampleViewer Compilation
*************************************************************************

* A compiled version of the SampleViewer is provided for convenience. It is statically linked with wxWidgets (installing/compiling wxMac isn't required) and with PvAPI. 

* SampleViewer requires the wxMAC module >= 2.6, compiled as unicode. Modify the makefile to use the version you have installed on your system.

* Since wxMac is built on top of Carbon, there is NO 64-bit SampleViewer.


*************************************************************************
* Java
*************************************************************************

* The Java folder (in examples) contains a JNI interface to PvAPI and a set of samples. In the bin-pc folder, you will find a build version of the interface (libPvJNI.so). Here's the steps to import the samples in Eclipse:

    1. Start Eclipse & set workspace to "AVT GigE SDK/examples/Java"
    2. In the "Package Explorer", right click then select "Import". From there expand "General" and select "Existing Projects into Workspace"
       then "Next".
    3. In "Select Root directory" browse to "AVT GigE SDK/examples/Java/PvJPI" then click on "Finish". The project will appears in the "Explorer".
    4. Do the same thing for any of sample code you want, e.g. "JListCameras"
    5. Select the "JListCameras" project in the "Explorer", right click and select "Run as" -> "Java Application".
    6. In the "Select Java Application" window, scroll down to "JListCameras - Prosilica" and select it. Press "Ok". The sample code will launch,
       but fail with a java.lang.unsatisfiedLinkError exception. Terminate the app.
    7. In the "Eclipse" menu "Run", select "Run Configuration ...". Select "JListCameras" and click on the "Arguments" tab and add the following
       string to "VM arguments":
       
       -Djava.library.path="/Full/Path/To/AVT GigE SDK/bin-pc/x64"
       
       Replace Full/Path/To by the actual path to the SDK on your system. If you are on a 32bits system, replace x64 by x86.
    8. In the same window, change the "Working Directory" to "Other" and enter the exact same path as above (no need to have it quoted).
    9. Click on "Apply", then "Run".
