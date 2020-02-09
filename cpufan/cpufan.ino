void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // 40%
  //pwm(200,400,10,13);
  
  // 60%
  //pwm(200,600,10,13);

  // 100%
  //pwm(200,1000,10,13);

  pwm(200,150,10,13);
}

void pwm(float duration, float power, float period, int pin) {
  /*
  duration (ms)
  power (out of 1000)
  period (microseconds)
  output pin
  */
  unsigned long time_0 = millis();

  while ((millis()-time_0) < duration) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(power*period);
    digitalWrite(pin, LOW);
    delayMicroseconds((1000-power)*period);
  }
  return;
}
