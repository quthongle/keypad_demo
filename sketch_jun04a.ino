

#include "Keypad.h"
 

// keypad type definition
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] =
  {{'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}};

byte rowPins[ROWS] = {
    5, 4, 3, 2}; //connect to the row pinouts of the keypad :: pin 5-6-7 on keypad's pin
byte colPins[COLS] = {
    8, 7, 6}; // connect to the column pinouts of the keypad :: pin 4-3-2-1 on keypad's pin

int count=0;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


//---------------------------
void setup()
{
  Serial.begin(9600);
  Serial.println("...testing keypad...");
}

//-----------------------------
void loop()
{
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
        Serial.println(key);
        count++;
        if (count==17)
        {
            Serial.println(key);
            count=0;
        }
    }
}
