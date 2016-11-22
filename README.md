# micLatencyTest
Simple latency testing solution using a microphone.

- Build on Arduino SDK
- Calculates the latency from when play is hit and when music starts playing from the device
- Right now, only works with Spotify on windows.
- Works with SpotifyArduinoCOM https://github.com/yangantang/SpotifyArduinoCOM

----------------
WHA LATENCY TEST (by Yang An Tang)
----------------
https://github.com/yangantang/SpotifyArduinoCOM
https://github.com/yangantang/micLatencyTest

---------------------
CONTENTS OF THIS FILE
---------------------
 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Troubleshooting
------------
INTRODUCTION
------------
This test is to reduce the presence of human error when carrying out Whole Home Audio(WHA)
latency testing. The whole project was based off an electret microphone that is attached
to an Arduino Uno development board. There are 2 components to this test, firstly is the 
Arduino board and then there is the Spotify to Arduino COM VB .net application. The Spotify
to VB .net application is the main communication between the computer and board. The on board
Arduino clock is used to determine the latency by calculating from when Spotify starts playing
till when the microphone picks up the music.

This test application only works with Windows PC.
------------
REQUIREMENTS
------------
- Spotify (Windows version - https://www.spotify.com/us/download/windows/)
- ArduinoCOM (Visual Basic .NET application)
- Arduino UNO board with electret microphone extension
- Arduino driver

- Microsoft Visual Studios (Optional)
- Arduino IDE (Optional)
------------
INSTALLATION
------------
1) Make sure all the necessary applications have been downloaded, extracted and installed.
   The ArduinoCOM application can be found in */WHA_test/ArduinoCOM/bin/Release/ArduinoCOM.exe
2) Connect the Arduino board to an electret microphone. (If you are using any off the shelf
   microhpones, the connections should be really simple ie. VCC, GND, and OUT)
3) Then using a USB connection, plug the board into your computer and make sure that it is
   visible and the right COM ports are opened by your computer. 
4) You can use either the Arduino IDE or ArduinoCOM application to check whether COM ports 
   are open.(https://www.arduino.cc/en/Guide/Environment#toc12)
-------------
CONFIGURATION
-------------
1) In the Arduino COM application, choose the right COM port (usually only 1 port should be visible)
   then click on connect.
2) (Make sure Spotify is open at this point) Following the instructions in the console box, 
   type either 1 or 2 then hit send. (the physical enter key does not work, you have to manually
   click on send)
3) Spotify should start playing and when the microphone detects music, the latency value (ms)
   should appear in the console box.
4) All data are logged in a CSV file which should be located on your Desktop with the name
   latencyData.csv.

** I have prepared a list of songs that I use because not all songs start off loud. Songs beginning
   softly will not trigger the timer accurately. The list can be found in song_names.txt.
---------------
TROUBLESHOOTING
---------------
- If the Arduino COM application cannot detect the serial port, try unplugging and plugging in again.
  Make sure that your USB port is also a serial port and provides sufficient power for the board.
- The first time launching the Arduino COM application and connecting to the serial port will spit
  out a random value and mess up the whole buffer string. Relaunch the app and everything should
  work normally. (If someone knows how to fix this, that would be great! :) )
- Always make sure the Spotify window is on top of all others in order for the application to fully
  control Spotify.
- The microphone threshold is static which means only sounds of a certain volume will trigger it.
  So if for some reason the Arduino COM application does not display latency values, try 
  increasing the volume in Spotify or on the test device manually.  
