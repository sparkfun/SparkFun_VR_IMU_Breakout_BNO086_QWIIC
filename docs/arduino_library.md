
!!! arduino

    ### Arduino IDE

    This example assumes you are using the latest version of the Arduino IDE on your desktop. If this is your first time using Arduino IDE and an library, please review the following tutorials.

    - [Installing the Arduino IDE](https://learn.sparkfun.com/tutorials/installing-arduino-ide)
    - [Installing an Arduino Library](https://learn.sparkfun.com/tutorials/installing-an-arduino-library)

    ### Board Definitions

    For the scope of this tutorial, we will be using the [SparkFun IoT RedBoard - ESP32 Development Board](https://learn.sparkfun.com/tutorials/iot-redboard-esp32-development-board-hookup-guide). If you have not installed a board definition before, please review the following tutorial as well.

    - [Installing Board Definitions in the Arduino IDE](https://learn.sparkfun.com/tutorials/installing-board-definitions-in-the-arduino-ide)

    ### USB-to-Serial Drivers

    If you've never connected an CH340 device to your computer before, you may need to install drivers for the USB-to-serial converter. Check out our section on "[How to Install CH340 Drivers](https://learn.sparkfun.com/tutorials/sparkfun-serial-basic-ch340c-hookup-guide#drivers-if-you-need-them)" for help with the installation.


The SparkFun VR IMU BNO08X Arduino Library provides a quick way to interact with the interfaces on the SparkFun VR IMU Breakout - BNO086 (Qwiic). Install the library through the Arduino Library Manager tool by searching for "**SparkFun BNO08X**". Users who prefer to manually install the library can get it from the [GitHub Repository](https://github.com/sparkfun/SparkFun_BNO08x_Arduino_Library) or download the .ZIP by clicking the button below:

<div style="text-align: center"><a href="https://github.com/sparkfun/SparkFun_BNO08x_Arduino_Library/archive/refs/heads/main.zip" class="md-button">SparkFun VR IMU BNO08X Arduino Library (ZIP)</a></div>

!!!note
    This library is different from the original [BNO080 Arduino Library](https://github.com/sparkfun/SparkFun_BNO080_Arduino_Library). Most of the examples from the old Arduino Library were ported to the BNO08X Arduino Library. We recommend using this library for the BNO08X as it processes the data better.
