#include <Wire.h>

//Jeremy = 11, Wesley = 12, Daniel = 13
#define sAddr 12

int num = 0, renum = 0;

//wd
int relayFan = 4; //active low
int relayFanState = 1;
int relayPowerPin = 2;





void setup() {
  //Serial.begin(9600);
  Wire.begin(sAddr);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode(relayFan, OUTPUT);
  pinMode(relayPowerPin, OUTPUT);
  digitalWrite(relayPowerPin, HIGH);
  digitalWrite(relayFan, relayFanState);
}

void loop() {
  delay(100); 
  //Serial.print("relayFanState: ");
  //Serial.println(relayFanState);
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    num = Wire.read();
    //Serial.print("data received: ");
    //Serial.println(num);
  }
}

void sendData() {

  //Option 1 input low temp
  if (num == 1)
  {
   
  }
  //Option 2 input high temp
  else if (num == 2)
  {
    
  }
  //Option 3 for toggle fan on
  else if (num == 3)
  {
    relayFanState = 0; //active low
    
    digitalWrite(relayFan, relayFanState);
    Wire.write(relayFanState);
  }
  //Option 4 for toggle fan off
  else if (num == 4)
  {
    relayFanState = 1; //active low
    
    digitalWrite(relayFan, relayFanState);
    Wire.write(relayFanState);
  }
  //arduino crashes if you ask it for an option that it doesn't know about
  else
  {
    Wire.write(112); //send a number that is out of the range of what the pi is looking for
  }
}
