// Interrupt Sence-Think-Act Board

//Initilising states = 0
volatile int sensorState = 0;
volatile int ledState = 0;

//Pin 2 is set as input and will recieve signal from th Motion Sensor
const int sensorPin = 2;
//Pin 13 is set as the output which is the in-built Led
const int ledPin = 13;

  
void setup()
{
 
  //Setting pins
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  //Attaching Interrupt when INT0 changes (pin 2) 
  attachInterrupt(0, pin_ISR, CHANGE);
  
  //Begining serial monitor
  Serial.begin(9600);
}

void loop()
{

}

//Function that will be called upon interrupt
void pin_ISR(){

  //Setting Sensor and LED state
  sensorState = digitalRead(sensorPin);
  
  //Setting LED
  digitalWrite(ledPin, sensorState);
  
  //Reading From LED
  ledState = digitalRead(ledPin);
  
  //Printing Sensor State to Serial monitor
  Serial.print("Sensor: ");
  Serial.println(sensorState);
  
  //Printing LED State to Serial monitor
  Serial.print("   LED: ");
  Serial.println(ledState);
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~");
  
}
