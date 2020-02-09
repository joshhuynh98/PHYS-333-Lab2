void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //pwm(200,300,10,10);

  //delay(200);

  //pwm(200,298,10,10);
  sawtooth(2000);
  
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

void sawtooth(float period) {
    for (int i=0; i<=1000; i++) {
      pwm(period/1000,i,1,10);
    }
}
