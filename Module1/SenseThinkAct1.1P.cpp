// Simple Sence-Think-Act Board

//Initilising states = 0
int sensorState = 0;
int ledState = 0;

//Pin 2 is set as input and will recieve signal from th Motion Sensor
const int sensorPin = 2;
//Pin 13 is set as the output which is the in-built Led
const int ledPin = 13;
  
void setup()
{
 
  //Setting pins
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  //Begining serial monitor
  Serial.begin(9600);
}

void loop()
{
  //Setting Sensor and LED state
  sensorState = digitalRead(sensorPin);
  ledState = digitalRead(ledPin);
  
  //Printing Sensor State to Serial monitor
  Serial.print("Sensor: ");
  Serial.println(sensorState);
  
  //Set LED to on if Sensor detects movement
  if(sensorState == HIGH){
  	digitalWrite(ledPin, HIGH);
  }
  else {
    //Else set the LED to off
   	digitalWrite(ledPin, LOW); 
  	}
  
  //Printing LED State to Serial monitor
  ledState = digitalRead(ledPin);
  Serial.print("   LED: ");
  Serial.println(ledState);

   delay(100);
}