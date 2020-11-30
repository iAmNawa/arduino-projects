#include<Servo.h>

Servo servo1;

void setup() {
  servo1.attach(9); // signal wire
}

void loop() {
  servo1.write(0);
  delay(1000);
  servo1.write(60);
  delay(1000);
}
