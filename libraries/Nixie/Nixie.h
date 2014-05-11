/*
  Nixie.h - Library for controlling the Ogi Lumen nixie tube driver.
  Created by Lionel Haims, July 25, 2008.
  Released into the public domain.
  
  
  Rev 2: July 27, 2008
  
  Rev 3: March 1, 2009: Added include of WProgram.h to fix compile error in arduino IDE 12/13
  Rev 4: February 26, 2013: Updated for IDE 1.0 (changed call from "WProgram.h" to "Arduino.h")
                            Changed "int" to "long" so more that 5 nixie digits can easily be accessed
*/

#ifndef Nixie_h
#define Nixie_h

// Include the standard types 
#include <Arduino.h>
#include <Arduino.h>

// Define the Nixie class
class Nixie
{
  public:
    // Constructor
    // dataPin  -> nixie driver pin 1 (SER)
    // clockPin -> nixie driver pin 3 (SCK)
    // latchPin -> nixie driver pin 4 (RCK)
    Nixie(int dataPin, int clockPin, int latchPin);
    
    // Write a full number, left justified, pushing digits to the right
    //   number = the number to write out
    
    void writeNumLeft(long number);
  
    // Write a full number, right justified, padded with zeros
    
    //   number = the number to write out

    //   digits = the number of digits (nixie tubes) 
    void writeNumZero(long number, int digits);

    // Write a full number, right justified, padded with blanks

    //   number = the number to write out

    //   digits = the number of digits (nixie tubes) 
    void writeNumTrim(long number, int digits);
    
    // Write the digits of an array of specified size
    //   arrayNums = the array of digits

    //   size      = the number to digits
    // note: a digit with a value of 10 will display a blank
    void writeArray(int* arrayNums, int size);

    // Clear the display
    //   digits = the number of digits (nixie tubes)
    void clear(int digits);


  private:
    int _dataPin;
    int _clockPin;
    int _latchPin;
    void _serializeDigit(byte writeDigit);

};

#endif //Nixie_h

