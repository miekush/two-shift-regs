//two 74HC595 shift registers example using bit banging
//based on the Arduino shiftOut function
//by Mike Kushnerik

//circuit settings:
// SER >> D4
// LATCH >> D3
// CLK >> D2

int num = 0; //input data
 void setup()
 {
   DDRD = B00011100; //set D2,D3,D4 as outputs
   PORTD ^= B00011100; //set D2,D3,D4 to 0
 }
void loop()
{
  PORTD ^= B00001000; //clear latch
  twoByteShiftOut(num); //send two bytes to the registers
  PORTD |= B00001000; //set latch
  num++; //increment input data
  if(num>65535)num=0; //reset input data
  delay(500);
}
void twoByteShiftOut(uint16_t dataInput)
{
  int bitState; //state of current input bit
  PORTD ^= B00010100; //clear ser and clk
  for(int i=16; i>=0; i--) //loop to go through each bit in input message
  {
    PORTD ^= B00000100; //clear clk
    bitState = (dataInput & (1<<i)) >> i; //save state of current input bit to data
    PORTD = (bitState<<4); //write state of current input bit to ser
    PORTD |= B00000100; //set clk
    PORTD ^= B00010000; //clear ser
  }
  //end of message
  PORTD ^= B00000100; //clear clk
}
