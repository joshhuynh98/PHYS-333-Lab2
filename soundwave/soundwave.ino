void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int period = 2000;
  int f = 1;
  
  unsigned long t = millis() % period;
  float power = 500 * (sin(6.28*f*t) +1);

  pwm(period/1000,power,1,10);
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
