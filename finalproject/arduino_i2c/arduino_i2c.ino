#include <Wire.h>

//Jeremy = 11, Wesley = 12, Daniel = 13
#define sAddr 11

int num = 0, renum = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  Wire.begin(sAddr);

  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  Serial.println("Start");
}

void loop() {
  delay(100);
}

void receiveData(int byteCount){
  while(Wire.available()){
    num = Wire.read();
    Serial.print("data received: ");
    Serial.println(num);
  }
}

void sendData(){
  
  //Option 1 for information
  if(num == 1)
  {
    renum = num + 1;  //just to verify that the information is legit
    Wire.write(renum);
  }
  //Option 2 for information
  else if(num == 2)
  {
    renum = num + 10;  //just to verify that the information is legit
    Wire.write(renum);
  }
  //Option 3 for information
  else if(num == 3)
  {
    renum = num + 50;  //just to verify that the information is legit
    Wire.write(renum);
  }
  //Option 4 for information
  else if(num == 4)
  {
    renum = num + 50;  //just to verify that the information is legit
    Wire.write(renum);
  }
  //arduino crashes if you ask it for an option that it doesn't know about
  else
  {
    Wire.write(111); //send a number that is out of the range of what the pi is looking for
  }
}
