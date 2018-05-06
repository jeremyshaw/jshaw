int analogIn = A0;  
int analogOutOne = 9; 
int analogOutTwo = 10;
int analogOutThree = 11;

int sensorValue = 0;        
int outputValue = 0;        
int outputOne = 1;
int outputTwo = 1;
int outputThree = 1;

void setup() {

  Serial.begin(9600);
  digitalWrite(2, HIGH); //power for the sensor, lol
}

void loop() {

  sensorValue = analogRead(analogIn);


  if (sensorValue >= 1 && outputTwo <= 30){
    if (outputOne<250){
      outputOne+=4;
    }    
  }
  else if(sensorValue == 0 && outputTwo < 50){
    if(outputOne>50){
      outputOne-=3;
    }
    else if(outputOne>0){
      outputOne--;
    }
  }
  
  if (sensorValue >= 1 && outputOne >=180 && outputThree <= 30){
    if (outputTwo<250){
      outputTwo+=4;
    }    
  }
  else if(sensorValue == 0 && outputThree < 50){
    if(outputTwo>50){
      outputTwo-=3;
    }
    else if(outputTwo>0){
      outputTwo--;
    }
  }
  
  if (sensorValue >= 1 && outputTwo >=180){
    if (outputThree<250){
      outputThree+=4;
    }    
  }
  else if(sensorValue == 0){
    if(outputThree>50){
      outputThree-=3;
    }
    else if(outputThree>0){
      outputThree--;
    }
  }
  
  analogWrite(analogOutOne, outputOne);
  analogWrite(analogOutTwo, outputTwo);
  analogWrite(analogOutThree, outputThree);
  

  //Serial.print("sensor = ");
  //Serial.println(sensorValue);




  delay(10);
}
