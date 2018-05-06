int analogInPin = A1; 
float sensorValue = 0;       
float outputValue = 0;
int bar = 0;

void setup() {
  Serial.begin(9600);
  pinMode(analogInPin, INPUT);
  for (int i=0; i<10; i++){
    pinMode(i+2, OUTPUT);
  }
}

void loop() {
  sensorValue = analogRead(analogInPin);
  for(int i = 0; i < 10; i++){
    digitalWrite(i+2, LOW);
  }
  
  bar = map(sensorValue, 15, 130, 0, 9);
  constrain(bar, 0, 9);
  if(bar<0){
    bar = 0;
  }
  if(bar > 9){
    bar = 9;
  }
 
  Serial.print(sensorValue);
  Serial.print(":");
  Serial.println(bar);
  for (int i=0; i<bar; i++){
    digitalWrite(i+2, HIGH);
  }
  delay(100);  
}
