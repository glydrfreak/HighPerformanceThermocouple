# HighPerformanceThermocouple
## Preparing the Software
Arduino IDE is an integrated development environment, which compiles and executes written code. All the prewritten code used by the temperature sensor is included in a repository located on github.
1.	Install Arduino IDE from Arduino's website. On Windows, it is preferred to download Arduino with the zip file.  
    - https://www.arduino.cc/en/software
2.	Click <a href="https://github.com/glydrfreak/HighPerformanceThermocouple/archive/main.zip" raw=true>HERE</a> to download and extract the code files in this repository
3.	Open the `thermo_rate.ino` file, which should open with the Arduino IDE
4.	Tools -> Board ->Boards Manager -> Search for: Arduino SAMD Boards -> Install
5.	File -> Preferences -> Next to "Additional Boards Manager URLs", type: `https://adafruit.com/package_adafruit_index.json`
    - (If a URL is already there, separate it with a comma and type the new URL next to it)
6.	Tools -> Board ->Boards Manager -> Search for: Adafruit SAMD Boards -> Install
7.	Tools -> Board -> Select: Adafruit Feather M0
## Preparing the Temperature Sensor
The AD8495 Thermocouple amplifier board (blue PCB) has been modified to measure the temperature range fit for an airbag deployment test. An extremely fine tip, K-type thermocouple is used for deployment tests because of the low thermal mass resulting in extremely fast response. The K-type thin foil thermocouple can be purchased here:  
    - https://shoprdfcorp.com/shop/p/ultra-fast-response-bare-foil-thermocouples-1

A small dot of CA glue or superglue is placed on the welds between the leads and the thin foil tip. This glue joint will prevent the weld from coming apart during deployment. Be careful not to saturate the tip of the thermocouple with glue as this needs to be exposed.
1.	Connect the thermocouple to the amplifier. The thermocouple has a polarity, indicated by red and yellow. Correspondingly, the screw terminal on the amplifier is labeled “red” and “ylw”
2.	Cut off a section of the paper that the thermocouple is shipped with just below the welds on the tip of the thermocouple.
3.	Align the tip of the thermocouple in the hole of the plexiglass and tape the edge of the paper to the plexiglass, leaving the tip of the thermocouple exposed.
## Operating the Temperature Sensor
1.	Connect the microcontroller to your computer with a micro USB cable.
o	Some USB cables are "charge only" cables, which will not work for uploading code, so make sure to use a USB cable that has data wires.
2.	Tools -> Port -> Select the port labeled Adafruit Feather M0. If the port is not labeled, select any port.
3.	Sketch -> Upload
4.	Tools -> Serial Monitor
5.	With the serial monitor open, make sure the baud rate is set to 115200. Two columns of numbers should be rapidly printing to the screen. The first column is a time stamp in microseconds, the second column is the temperature in degrees Celsius.
6.	When the deployment test is complete, uncheck auto scroll in the serial monitor. Select all and copy all the data using CTRL+A and CTRL+C. Paste the data into a spreadsheet or other plotting software for analysis. 
o	There may be a lot of data which may reduce the performance of the spreadsheet or plotting software, especially if the program has been running for more than a couple minutes. If this is a concern, press the tiny reset button on the microcontroller one time, and restart the serial monitor right before the deployment test.

For help solving any issues at all, contact:

Braedin Butler

BraedinButler@gmail.com
