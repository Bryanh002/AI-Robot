#include <SCServo.h>

SMS_STS sms_sts;


int dirGPIO = 4;

void setup()
{
  pinMode(dirGPIO,OUTPUT);
  digitalWrite(dirGPIO, LOW); // Start in Receive mode
  Serial.begin(115200);
  Serial1.begin(1000000, SERIAL_8N1, 11, 12);
  delay(1000);
}

void loop()
{
  digitalWrite(dirGPIO, HIGH); // Switch to Transmit
  Serial.println("Transmitting Mode Activated");
  delay(5000);
  digitalWrite(dirGPIO, LOW); // Switch  Receive mode
  Serial.println("Receiving Mode Activated");
  delay(5000);
}