<!--
    TODO
    _?_ Table of characteristics or bullet points?!?
    ____ Hardware Overview
        ___ check SPI speed...
        ___ Arduino Examples
            ___ SPI?
            ___ Serial?!? information about the different UARTs types
    ____ Add note linking both BNO080 to BNO086 tutorials together from old tutorial
    ____ Adjust align="center"

-->

!!!info
    This tutorial is an update to the BNO080. If you are looking for the original tutorial for the BNO080, make sure to head to the [Qwiic VR IMU (BNO080) Hookup Guide](https://learn.sparkfun.com/tutorials/qwiic-vr-imu-bno080-hookup-guide). Note that the BNO080 is EOL. Additionally, this tutorial uses a different Arduino Library.

CEVA's [BNO086](https://www.sparkfun.com/products/22857), a combination triple-axis accelerometer/gyro/magnetometer System in Package (SiP), packaged with a 32-bit ARM&copy; Cortex&trade; M0+. The BNO086 Inertial Measurement Unit (IMU) produces accurate rotation vector headings, excellently suited for VR and other heading applications, with a static rotation error of two degrees or less. The VR IMU is exactly what we’ve been waiting for: all the sensor data is combined and drift-corrected into meaningful, accurate IMU information. It’s perfect for any project that needs to sense orientation or motion. We've taken this IMU and stuck it on a Qwiic enabled breakout board, in order to make interfacing with the tiny, QFN package a bit easier to connect.

<center>
<div class="grid cards" style="width:500px;" markdown>

-   <a href="https://www.sparkfun.com/products/22857">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/parts/2/3/0/2/7/22857-SEN_SparkFun_VR_IMU_Breakout-BNO086_Qwiic-_01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun VR IMU Breakout - BNO086 (Qwiic)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/22857">
      <b>SparkFun VR IMU Breakout - BNO086 (Qwiic)</b>
      <br />
      SEN-22857
      <br />
      <center>[Purchase from SparkFun :fontawesome-solid-cart-plus:](https://www.sparkfun.com/products/22857){ .md-button .md-button--primary }</center>
    </a>

</div>
</center>

<div style="text-align: center;">
  <iframe width="560" height="315" src="https://www.youtube.com/embed/30WDbm8smP8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
</div>

In this hookup guide, we'll connect our sensor up to our microcontroller of choice and separately read the rotation vectors (which is what we will mainly want), acceleration vectors, gyro values, and magnetometer vectors. We'll check out how to implement the step counter on the BNO086 in order to use it as a pedometer. We'll also read Q values from the sensor. Knowing what activity you're performing is important so we'll learn how to classify what activity the IMU is performing (i.e. Sitting still, moving, biking, walking, running, etc...) and how confident the IMU is that each activity is being performed. Printing out raw packets will also be examined for debugging purposes. Finally, we'll examine how to configure the sensor on different I<sup>2</sup>C ports and addresses. A bonus example is provided in Processing to show us how to use quaternion data to orient a cube.



### Required Materials

To follow along with this tutorial, you will need the following materials. You may not need everything though depending on what you have. Add it to your cart, read through the guide, and adjust the cart as necessary.

* 1x [SparkFun IoT RedBoard - ESP32 Development Board [WRL-19177]](https://www.sparkfun.com/products/19177)
* 1x USB-C cable
    * Our [USB 2.0 A to C Cable [CAB-15092]](https://www.sparkfun.com/products/15092) will do nicely
    * Our [USB 3.1 A to C Cable [CAB-14743]](https://www.sparkfun.com/products/14743) is a good choice too
* 1x [SparkFun VR IMU Breakout - BNO086 (Qwiic) [SEN-22857]](https://www.sparkfun.com/products/22857)
* 1x Qwiic Cable
    * [Flexible Qwiic Cable - 100mm [PRT-17259]](https://www.sparkfun.com/products/17259)
    * [Flexible Qwiic Cable - 500mm [PRT-17257]](https://www.sparkfun.com/products/17257)
* 2x IC Hooks (_optional for advanced configuration_)
    * The pack of 5x [IC Hook with Pigtail [CAB-09741]](https://www.sparkfun.com/products/9741) for a temporary connection

<div class="grid cards hide col-4" markdown>

-   <a href="https://www.sparkfun.com/products/19177">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/8/8/0/0/ESP32_03.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun IoT RedBoard - ESP32 Development Board">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/19177">
      <b>SparkFun IoT RedBoard - ESP32 Development Board</b>
      <br />
      WRL-19177
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/15092">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/3/9/8/4/15425-Reversible_USB_A_to_C_Cable_-_0.8m-02.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Reversible USB A to C Cable - 0.8m">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/15092">
      <b>Reversible USB A to C Cable - 0.8m</b>
      <br />
      CAB-15092
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/22857">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/parts/2/3/0/2/7/22857-SEN_SparkFun_VR_IMU_Breakout-BNO086_Qwiic-_01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="SparkFun VR IMU Breakout - BNO086 (Qwiic)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/22857">
      <b>SparkFun VR IMU Breakout - BNO086 (Qwiic)</b>
      <br />
      SEN-22857
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/17259">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/6/2/4/6/17259-Flexible_Qwiic_Cable_-_100mm-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Flexible Qwiic Cable - 100mm">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/17259">
      <b>Flexible Qwiic Cable - 100mm</b>
      <br>
      PRT-17259
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9741">
      <figure markdown>
       <img src="https://cdn.sparkfun.com//assets/parts/3/6/9/6/09741-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="IC Hook with Pigtail">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9741">
      <b>IC Hook with Pigtail</b>
      <br>
      CAB-09741
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->

</div>



### Tools

For a secure connection when using the advanced configuration, you will need to solder two wires between your microcontroller and the breakout board. This requires some assembly and soldering. You may already have a few of these items but if not, the tools and hardware below help with that assembly.

* [Hook-Up Wire - Assortment (Stranded, 22 AWG) [PRT-11375]](https://www.sparkfun.com/products/11375)
* [Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded) [TOL-22263]](https://www.sparkfun.com/products/22263)
* [Soldering Iron [TOL-14456]](https://www.sparkfun.com/products/14456)
* [Solder Lead Free - 15-gram Tube [TOL-9163]](https://www.sparkfun.com/products/9163)

<div class="grid cards hide col-4" markdown>

-   <a href="https://www.sparkfun.com/products/11375">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/7/1/2/0/11375-Hook-Up_Wire_-_Assortment__Solid_Core__22_AWG_-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Hook-Up Wire - Assortment (Stranded, 22 AWG)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/11375">
      <b>Hook-Up Wire - Assortment (Stranded, 22 AWG)</b>
      <br />
      PRT-11375
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/22263">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/2/2/0/1/22263-_TOL_Wire_Stripper-_01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/22263">
      <b>Wire Stripper - 20-30 AWG Solid (22-32 AWG Stranded)</b>
      <br />
      TOL-22263
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/14456">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/1/2/4/9/0/14456-01.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Soldering Iron - 60W (Adjustable Temperature)">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/14456">
      <b>Soldering Iron - 60W (Adjustable Temperature)</b>
      <br />
      TOL-14456
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
-   <a href="https://www.sparkfun.com/products/9163">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/parts/2/5/8/7/09162-02-L.jpg" style="width:140px; height:140px; object-fit:contain;" alt="Solder Lead Free - 15-gram Tube">
      </figure>
    </a>

    ---

    <a href="https://www.sparkfun.com/products/9163">
      <b>Solder Lead Free - 15-gram Tube</b>
      <br>
      TOL-09163
    </a>
<!-- ----------WHITE SPACE BETWEEN PRODUCTS---------- -->
</div>



### Suggested Reading

If you aren't familiar with the Qwiic Connection System, we recommend reading [here for an overview](https://www.sparkfun.com/qwiic).

<div style="text-align: center">
  <table style="border-style:none">
    <tr>
     <td>
     <div style="text-align: center"><a href="https://www.sparkfun.com/qwiic"><img src="../assets/Qwiic-registered-updated.png" alt="Qwiic Connection System" title="Click to learn more about the Qwiic Connection System!"></a>
     </div>
    </td>
    </tr>
    <tr>
      <td><div style="text-align: center"><i><a href="https://www.sparkfun.com/qwiic">Qwiic Connection System</a></i></div></td>
    </tr>
  </table>
</div>

If you aren’t familiar with the following concepts, we also recommend checking out a few of these tutorials before continuing.

<div class="grid cards hide col-4" markdown>

-   <a href="https://learn.sparkfun.com/tutorials/gyroscope">
      <figure markdown>
        <img src="https://cdn.sparkfun.com//assets/d/6/5/6/a/5112ed4ece395f2f2a000003.gif" style="width:264px; height:148px; object-fit:contain;" alt="Gyroscope">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/gyroscope">
      <b>Gyroscope</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/accelerometer-basics">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/r/600-600/assets/6/7/e/5/a/516c6b6ece395f0f49000000.jpeg" style="width:264px; height:148px; object-fit:contain;" alt="Accelerometer Basics">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/accelerometer-basics">
      <b>Accelerometer Basics</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/serial-communication">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/c/264-148/assets/7/d/f/9/9/50d24be7ce395f1f6c000000.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Serial Communication">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/serial-communication">
      <b>Serial Communication</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/i2c">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/8/2/I2C-Block-Diagram.jpg" style="width:264px; height:148px; object-fit:contain;" alt="I2C">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/i2c">
      <b>I2C</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/terminal-basics">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/1/1/2/terminalThumb.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Serial Terminal Basics">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/terminal-basics">
      <b>Serial Terminal Basics</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/installing-an-arduino-library">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/b/e/4/b/2/50f04b99ce395fd95e000001.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Installing an Arduino Library">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/installing-an-arduino-library">
      <b>Installing an Arduino Library</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/c/264-148/assets/learn_tutorials/6/9/ArdPro.jpg" style="width:264px; height:148px; object-fit:contain;" alt="Connecting Arduino to Processing">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing">
      <b>Connecting Arduino to Processing</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
-   <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/learn_tutorials/5/Soldering_Action-01.jpg"style="width:264px; height:148px; object-fit:contain;" alt="How to Solder: Through Hole Soldering">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all">
      <b>How to Solder: Through Hole Soldering</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>
