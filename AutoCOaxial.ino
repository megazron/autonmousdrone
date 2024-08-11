#include <Servo.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include <Wire.h>

Servo ESCA;     // create servo object to control the ESC
Servo ESCB;   // value from the analog pin

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
  // Attach the ESC on pin 9
  Wire.begin();
  ESCA.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
  ESCB.attach(10,1000,2000);
   mpu.initialize();
  servo1.attach(7);
  servo2.attach(8);  
}

void loop() {
   // scale it to use it with the servo library (value between 0 and 180)
  ESCA.write(1600);
  ESCB.write(1600);    // Send the signal to the ESC
  delay(4000);

 ESCA.write(1600);
 ESCB.write(1600);    // Send the signal to the ESC
  delay(4000);

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