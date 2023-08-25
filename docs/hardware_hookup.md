### Connecting via Qwiic


Connecting to the BNO086 breakout is simple. You will just need a powerful microcontroller to process the data when using the BNO086 and a Qwiic cable. In this case, we used an ESP32 (we specifically tested the Arduino Library with the SparkFun IoT RedBoard - ESP32). Most of the basic examples in the Library will work in this configuration with the I<sup>2</sup>C protocol.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle;"><a href="../assets/img/22857-SEN_SparkFun_VR_IMU_Breakout-BNO086_Qwiic- 05.jpg"><img src="../assets/img/22857-SEN_SparkFun_VR_IMU_Breakout-BNO086_Qwiic- 05.jpg" height="600px" width="600px" alt="Basic Hookup with ESP32, Qwiic cable, and BNO086 Breakout"></a></td>
    </tr>
  </table>
</div>

!!!note
    Unfortunately, users are not able to use an Arduino Uno or RedBoard with an ATmega328P due the demands of the BNO086 IC. We recommend using the ESP32.



### Connecting via Qwiic and the Reset & Interrupt Pins

For the advanced configuration examples (i.e. examples 17 and 18) that requires specific timing, you will need to wire up reset and interrupt pins. This can also be a more reliable connection when using the other examples as well. Just make sure to adjust the code similar to the example 17.

The table and image below shows a connection with IC hooks connected. For a more secure connection, we recommending soldering to the connection. You can choose between a combination of [header pins and jumper wires](https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all), or [stripping wire and soldering the wire](https://learn.sparkfun.com/tutorials/working-with-wire/all) directly to the board.

<div class="grid cards hide col-4" markdown>

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
-   <a href="https://learn.sparkfun.com/tutorials/working-with-wire/all">
      <figure markdown>
        <img src="https://cdn.sparkfun.com/assets/0/5/0/0/f/5138de3cce395fbb1b000002.JPG" style="width:264px; height:148px; object-fit:contain;" alt="Working with Wire">
      </figure>
    </a>

    ---

    <a href="https://learn.sparkfun.com/tutorials/working-with-wire/all">
      <b>Working with Wire</b>
    </a>
<!-- ----------WHITE SPACE BETWEEN GRID CARDS---------- -->
</div>

<div style="text-align: center;">
    <table>
        <tr>
            <th style="text-align: center; border: solid 1px #cccccc;">RedBoard IoT - ESP32
            </th>
            <th style="text-align: center; border: solid 1px #cccccc;">VR IMU Breakout - BNO086
            </th>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#f2dede"><font color="#000000">3.3V (3.3V, Qwiic Port)</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#f2dede"><font color="#000000">3.3V</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#DDDDDD"><font color="#000000">GND (GND, Qwiic Port)</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#DDDDDD"><font color="#000000">GND</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#fff3cd"><font color="#000000">SCL (D22, Qwiic Port)</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#fff3cd"><font color="#000000">SCL</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#cce5ff"><font color="#000000">SDA (D21, Qwiic Port)</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#cce5ff"><font color="#000000">SDA</font>
            </td>
        </tr>    
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#cce5ff"><font color="#000000">D17</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#cce5ff"><font color="#000000">INT</font>
            </td>
        </tr>
        <tr>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#d4edda"><font color="#000000">D16</font>
            </td>
            <td style="text-align: center; border: solid 1px #cccccc;" bgcolor="#d4edda"><font color="#000000">RST</font>
            </td>
        </tr>
    </table>
</div>

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle;"><a href="../assets/img/22857-SEN_SparkFun_VR_IMU_Breakout-BNO086_Qwiic- 06.jpg"><img src="../assets/img/22857-SEN_SparkFun_VR_IMU_Breakout-BNO086_Qwiic- 06.jpg" height="600px" width="600px" alt="Hookup with ESP32, Qwiic cable, IC Hooks, and BNO086 Breakoutfor Advanced Configuration"></a></td>
    </tr>
  </table>
</div>

!!!note
    You will need to be careful when soldering header pins to the board. While you can solder header pins to the edge of the board to mate with a breadboard, you will need to solder header pins facing the other way so that the center pins do not connect to the same rails. Of course, you can cut a [six wire jumper wire cable](https://www.sparkfun.com/products/10371) and wire strip them before connecting to the 1x6 header as well.

!!!note
    For users using a different communication protocol, make sure to adjust the solder joints for PS0 and PS1 before connecting to a UART or SPI port.
