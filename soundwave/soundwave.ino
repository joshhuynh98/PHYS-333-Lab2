void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // 2s
  //soundwave(2000);

  // 4s
  soundwave(4000);
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

void soundwave(float T) {
  // w = 2pi/T
  // T this case is the pediod (horizontal length) of the sin wave
  // period: starts at 2.5V, go up to 5V, down to 0V, ends at 2.5V
  float dur = (T/1000)/2;
  
  for (int i=500; i<=1000; i++) {
    pwm(dur,i,1,10);
  }
  for (int i=1000; i>=500; i--) {
    pwm(dur,i,1,10);
  }
  for (int i=500; i>0; i--) {
    pwm(dur,i,1,10);
  }
  for (int i=0; i<=500; i++) {
    pwm(dur,i,1,10);
  }
}
