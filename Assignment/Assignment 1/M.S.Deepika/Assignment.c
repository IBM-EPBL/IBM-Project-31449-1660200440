
#include <Servo.h>

Int output1Value = 0;
Int sen1Value = 0;
Int sen2Value = 0;
Int const gas_sensor = A1;
Int const LDR = A0;
Int limit = 400;

Long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  Return pulseIn(echoPin, HIGH);
}

Servo servo_7;

Void setup()
{
   Serial.begin(9600);	
  pinMode(A0, INPUT);		
  pinMode(A1,INPUT);      	 
  pinMode(13, OUTPUT);		
  servo_7.attach(7, 500, 2500); 

  pinMode(8,OUTPUT);     
  pinMode(9, INPUT);		
  pinMode(10, OUTPUT);
  pinMode(4, OUTPUT);		
  pinMode(3, OUTPUT);		
 }
Void loop()
    Int val1 = analogRead(LDR);
  If (val1 > 500) 
  	{
    	digitalWrite(13, LOW);
    Serial.print(“Bulb ON = “);
    Serial.print(val1);
  	} 
  Else 
  	{
    	digitalWrite(13, HIGH);
     Serial.print(“Bulb OFF = “);
    Serial.print(val1);
  	}
  Sen2Value = digitalRead(9);
  If (sen2Value == 0) 
  	{
    	digitalWrite(10, LOW); 
    	digitalWrite(4, HIGH); 
    	digitalWrite(3, LOW); 
    Serial.print(“     || NO Motion Detected    “ );
  	}
 
  If (sen2Value == 1) 
  	{
    	digitalWrite(10, HIGH);
    delay(3000);
    	digitalWrite(4, LOW)
