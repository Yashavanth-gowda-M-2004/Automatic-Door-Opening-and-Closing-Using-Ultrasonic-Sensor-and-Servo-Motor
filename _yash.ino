#include <Servo.h>
#define TRIG 4
#define ECHO 6
#define SERVO 2
Servo door;

void setup()
{
  door.attach(SERVO);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}
void loop()
{
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(2);
  digitalWrite(TRIG,LOW);
  long Time=pulseIn(ECHO,HIGH);
  int distance=Time*0.036/2;
  if(distance<20)
  {
    door.write(90);

  }
  else
   {
    door.write(0);

  }
  delay(200);
}