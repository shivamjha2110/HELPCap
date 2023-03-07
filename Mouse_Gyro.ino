#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>


MPU6050 mpu;
int16_t ax, ay, az, gx, gy, gz;
double vx, vy;
int Click=0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();
  while(!mpu.testConnection());

  pinMode(12,OUTPUT);  //Making A GND pin on D12
  digitalWrite(12,LOW);

  attachInterrupt(digitalPinToInterrupt(2), LeftClickDetected, RISING);
  attachInterrupt(digitalPinToInterrupt(3), RightClickDetected, RISING);
}

void loop() 
{  
  double timer=millis();

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);


  Serial.print(gz+10);		//Calibrate the constant as per your sensor
  Serial.print("\t");
  Serial.print(gy-210);		//Calibrate the constant as per your sensor
  Serial.print("\t");
  Serial.println(Click);
 
  Click=0;

  while((millis()-timer)<50);
}

void LeftClickDetected()
{
  Click=1;
}
void RightClickDetected()
{
  Click=2;
}
