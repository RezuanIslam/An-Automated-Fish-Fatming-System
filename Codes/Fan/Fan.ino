int in1 = 8; 
int in2 = 9;
int ConA = 10;// Don't forget this is a PWM DI/DO
int speed1;
void setup() {
Serial.begin(9600);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT); 
pinMode(10, OUTPUT);
}
void TurnMotorA(){ //A function to control the direction and speed
digitalWrite(in1, LOW); //Switch between this HIGH and LOW states to change direction
digitalWrite(in2, HIGH);
speed1 = analogRead(A0);
speed1 = speed1*0.2492668622; //Analog value is read from the potentiometer to calibrate it
analogWrite(ConA,speed1);// To activate the motor
}
void loop() {
int value = analogRead(A0); //declaring and reading value from the pin
value = value*0.2492668622; // doing calibration to change range from 0-1023 to 0-255 the 
//number and is obtained by 255/1023
Serial.println(value);
TurnMotorA(); //one function that keeps looping you can add another one with a different 
//direction or stop
}
