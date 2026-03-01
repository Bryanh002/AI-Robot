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

  digitalWrite(dirGPIO, HIGH); // Switch to Transmit

  delay(500);


  sms_sts.WritePosEx(1, 2048, 1000, 50);
  delay(5000);
  sms_sts.WritePosEx(1, 0, 2400, 50);
  //int ID = sms_sts.Ping(1);

  Serial1.flush();
  digitalWrite(dirGPIO, LOW); // Switch  Receive mode

  /*
  if(ID != -1 && !sms_sts.getLastError()){
    digitalWrite(LEDpin, HIGH);
    Serial.print("Servo ID:");
    Serial.println(ID, DEC);
    delay(100);
  }else{
    int err = sms_sts.getLastError();
    if(err == 0) {
       Serial.println("TIMEOUT: No servo with ID 1 found. Is it powered?");
    } else {
       Serial.print("COMM ERROR: Data was corrupted. Error code: ");
       Serial.println(err);
    }
    digitalWrite(LEDpin, LOW);
    delay(2000);
  }
  */
  delay(2000);
}