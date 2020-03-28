# twoShiftRegs
A example program for using two 74HC595 Shift Registers via bit banging in Arduino. Based on the popular shiftOut function.

Circuit Settings:

74HC595 > Arduino UNO R3
SER     > D4
LATCH   > D3
CLK     > D2

See comments inside program for Additional Information.

Note: This program utilizes "bit banging" on regular GPIO pins rather than the ATMEGA328P hardware SPI.
      Additionally, I chose to use direct port manipulation rather than some of the Arduino primitives for accessing the GPIO pins.
      This method is much faster and drastically decreases the size of the program. Here is a reference document explaining the topic.
      Link: https://www.arduino.cc/en/Reference/PortManipulation
