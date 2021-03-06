#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#define S0 3
#define S1 4
#define S2 5
#define S3 6
#define sensorOut 7
//Servo topServo;
//Servo bottomServo;
int frequency = 0;
int color=0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  //topServo.attach(7);
  //bottomServo.attach(8);
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("Arduino");
  lcd.setCursor(1, 1);
  lcd.print("Color Detection");
  Serial.begin(9600);
}
void loop() {
  //topServo.write(115);
  delay(500);

  for(int i = 115; i > 65; i--) {
    //topServo.write(i);
    delay(2);
  }
  delay(500);

  color = readColor();
  delay(10);
  switch (color) {
    case 1:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Color : ");
    lcd.setCursor(0, 1);
    lcd.print("Red");
    Serial.println(" - (Red Color)");
    //bottomServo.write(50);
    break;
    case 2:
    //bottomServo.write(75);
    break;
    case 3:
    //bottomServo.write(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Color : ");
    lcd.setCursor(0, 1);
    lcd.print("Green");
    Serial.println(" - (Green Color)");
    break;
    case 4:
    //bottomServo.write(125);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Color : ");
    lcd.setCursor(0, 1);
    lcd.print("Yellow");
    Serial.println(" - (Yellow Color)");
    break;
    case 5:
    //bottomServo.write(150);
    break;
    case 6:
    //bottomServo.write(175);
    break;

    case 0:
    break;
  }
  delay(300);

  for(int i = 65; i > 29; i--) {
    //topServo.write(i);
    delay(2);
  }
  delay(200);

  for(int i = 29; i < 115; i++) {
    //topServo.write(i);
    delay(2);
  }
  color=0;
}
// Custom Function - readColor()
int readColor() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(50);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(50);
  if(G - B >= 10 && G - B <= 25 && G - ( 2 * R ) >= 8 ){
    color = 1; // Red
  }
  if(G<55 & G>43 & B<47 &B>35){
    color = 2; // Orange
  }
  if(R<160 & G<150 & G>37){
    color = 3; // Green
  }
  if(R<1){
    color = 4; // Yellow
  }
  if(R<56 & R>46 & G<65 & G>55){
    color = 5; // Brown
  }
  if (G<58 & G>45 & B<40 &B>26){
    color = 6; // Blue
  }
  return color;
}
