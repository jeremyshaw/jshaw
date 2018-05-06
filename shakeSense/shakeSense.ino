int digitalInPin = 12; 

float sensorValue = 0;       
float outputValue = 0;

int bar = 0;



void setup() {

  Serial.begin(9600);
  pinMode(digitalInPin, INPUT);
  for (int i=0; i<10; i++){
    pinMode(i+2, OUTPUT);
  }
}

void loop() {

  
  sensorValue = digitalRead(digitalInPin);
  for(int i = 0; i < 10; i++){
    digitalWrite(i+2, LOW);
  }
  if(sensorValue == 1){
    bar += 1;
    if(bar>9){
      bar = 0;
    }
    
  }
  
  Serial.print(sensorValue);
  Serial.print(":");
  Serial.println(bar);
  digitalWrite(bar+2, HIGH);
    
  delay(100);
  
  


  
}
