#include <MPU6050.h>
#include <I2Cdev.h>
#include <Wire.h>
#include <Servo.h>


MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;


Servo servo1; 
Servo servo2;

int val1;
int val2;
int pval1;
int pval2;


void setup() {
  Wire.begin();
  Serial.begin(115200);
  mpu.initialize();
  servo1.attach(7);
  servo2.attach(8); 
}


void loop() {
  
  
  mpu.getMotion6(&ax,&ay, &az, &gx, &gy, &gz);
  val1= map(ax, -17000, 17000, 0, 179);
  if (val1 != pval1){
  servo1.write(val1);
  pval1= val1;
}
val2= map(ay, -17000, 17000, 0, 179);
if (val2 != pval2){
  servo2.write(val2);
  pval2= val2;
}
delay(5);
}



 