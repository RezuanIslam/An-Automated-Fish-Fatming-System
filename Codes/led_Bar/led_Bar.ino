#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<LcdBarGraphI2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
LcdBarGraphI2C lbg(&lcd, 16, 0, 1); // Creates an LCD Bargraph object.
const int trigPin = 9;
const int echoPin = 10;
const int motor = 8;
long duration;
int distance;
#define max_distance 30  // Maximum distance we want to ping for (in centimeters).
void setup() 
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen
  //lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor, OUTPUT); // Sets the Motor as an Output
Serial.begin(9600); // Starts the serial communication
}
void loop() 
{
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance= duration*0.034/2;
  // Prints "Distance: " on the first line of the LCD
  lcd.setCursor(0,0);
  lcd.print("Distance: "); 
  lcd.print(distance);
  lcd.print(" cm");
  // Draws bargraph on the second line of the LCD
  lcd.setCursor(0,1);
  lbg.drawValue(distance, max_distance);
  
if(distance < 10){

   digitalWrite(motor, HIGH);

  }else{

     digitalWrite(motor, LOW);

    }


  
  delay(500);
}