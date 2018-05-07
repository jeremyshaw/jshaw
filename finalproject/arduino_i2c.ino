#include <Wire.h>

//Jeremy = 11, Wesley = 12, Daniel = 13
#define sAddr 11


int num = 0, renum = 0;
int state = 0;


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
  if(num == 1)
  {
    renum = num + 1;
    Wire.write(renum);
  }
  else if(num == 2)
  {
    renum = num + 10;
    Wire.write(renum);
  }
  else if(num == 3)
  {
    renum = num + 50;
    Wire.write(renum);
  }
}
