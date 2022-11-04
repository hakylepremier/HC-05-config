#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10,11); //RX | TX

void setup() {
  pinMode(9, OUTPUT); // this pin will pull the HC-05 pin (key pin or EN) HIGH to switch module to AT mode
  digitalWrite(9, HIGH);

  Serial.begin(9600);
  Serial.println("Enter AT Commands");
  BTSerial .begin(9600); // HC-05 default speed in AT command mode
}

void loop() {
  //The code below allows for commands and messages to be sent from COMPUTER (serial monitor) -> HC-05
  if(Serial.available())            // Keep reading from the Arduino Serial Monitor
    BTSerial.write(Serial.read());  // and send to HC-05

  //The code below allows for commands and messages to be sent from  HC-05 -> COMPUTER (serial monitor)
  if (BTSerial.available())         // Keep reading from the HC-05
    Serial.write(BTSerial.read());  // and send to Arduino Serial Monitor
}

// Usefull commands to know
// AT+NAME => THis displays the name of the bluetooth module
// AT+ADDR => This displays the address of the module (helps to distinguish between different modules with the same name)
// AT+UART => This displays the baud rate of the arduino
// AT+ORGL => This resets everything to factory settings
// AT+NAME=SOMETHING changes the name to SOMETHING so re[place SOMETHING with your desired name.
