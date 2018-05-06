int analogInPin = A1; 
int relayPin = 2;




float sensorValue = 0;       
float outputValue = 0;
int relayToggle = 1;
int relayCounter = 0;
int relayCounterMax = 20;

void setup() {

  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(analogInPin, INPUT);
}

void loop() {

  sensorValue = analogRead(analogInPin);
  outputValue = sensorValue * 0.01624; //at 3.3v on the ZERO, this is the conversion

  
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  
  if(relayCounter == relayCounterMax){
    if(relayToggle == 0){
      relayToggle = 1;
    }
    else if(relayToggle ==1){
      relayToggle = 0;
    }
    digitalWrite(relayPin, relayToggle);
    Serial.println(relayToggle);
    relayCounter = 0;
  }
  else if(relayCounter <relayCounterMax){
    relayCounter++;
  }
  
  


  delay(100);
}
