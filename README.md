# twoShiftRegs
An example program for using two 74HC595 Shift Registers to create a binary up counter (0->65535) with 16 LEDS via bit banging in Arduino. Based on the popular shiftOut function.


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
      Also, here is the datasheet for the SNx4HC595 series shift registers by TI. It will help with the rest of the circuit setup.
      http://www.ti.com/lit/ds/symlink/sn74hc595.pdf
