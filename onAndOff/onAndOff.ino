int pwmPin6 = 6;
int pwmPin5 = 5;

void setup() {
  pinMode(pwmPin6, OUTPUT);
  pinMode(pwmPin5, OUTPUT);
}

void loop() {
  analogWrite(pwmPin6, 125);
  analogWrite(pwmPin5, 0);
  delay(1000);
  analogWrite(pwmPin5, 125);
  analogWrite(pwmPin6, 0);
  delay(1000);
}
