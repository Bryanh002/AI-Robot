#include <SCServo.h>

SMS_STS sms_sts;

int LEDpin = 8;
int dirGPIO = 4;

void setup()
{
  pinMode(LEDpin,OUTPUT);
  pinMode(dirGPIO,OUTPUT);
  digitalWrite(dirGPIO, LOW); // Start in Receive mode
  digitalWrite(LEDpin, HIGH);
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, 11, 12, false);
  sms_sts.pSerial = &Serial1;
  delay(1000);
}


void loop()
{
  int pos = sms_sts.ReadPos(1);
  Serial.println(pos);

  delay(2000);

  sms_sts.WritePosEx(1, 1000, 750, 50); //Write Position 1

  pos = sms_sts.ReadPos(1);
  Serial.println(pos);

  delay(2000);

  sms_sts.WritePosEx(1, 0, 750, 50); //Write Position 2

  delay(2000);


}