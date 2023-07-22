#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(11, 10); // RX, TX

#include <Wire.h> // I2C communication library

const int MPU = 0x68; // I2C address of the MPU6050 accelerometer
int16_t AcX, AcY, AcZ;

int flag = 0;

void setup() {
  Serial.begin(9600); // start serial communication at 9600bps
  BT_Serial.begin(9600);

  // Initialize interface to the MPU6050
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  delay(500);
  Serial.println("Setup completed");
}

void loop() {
  Read_accelerometer(); // Read MPU6050 accelerometer

  if (AcX < 60 && flag == 0) {
    flag = 1;
    BT_Serial.write('f');
    Serial.println("Moving forward");
  }
  if (AcX > 130 && flag == 0) {
    flag = 1;
    BT_Serial.write('b');
    Serial.println("Moving backward");
  }

  if (AcY < 60 && flag == 0) {
    flag = 1;
    BT_Serial.write('l');
    Serial.println("Moving left");
  }
  if (AcY > 130 && flag == 0) {
    flag = 1;
    BT_Serial.write('r');
    Serial.println("Moving right");
  }

  if ((AcX > 70) && (AcX < 120) && (AcY > 70) && (AcY < 120) && (flag == 1)) {
    flag = 0;
    BT_Serial.write('s');
    Serial.println("Stopped");
  }

  delay(100);
}

void Read_accelerometer() {
  // Read the accelerometer data
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); // Start with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // Read 6 registers total, each axis value is stored in 2 registers

  AcX = Wire.read() << 8 | Wire.read(); // X-axis value
  AcY = Wire.read() << 8 | Wire.read(); // Y-axis value
  AcZ = Wire.read() << 8 | Wire.read(); // Z-axis value

  AcX = map(AcX, -17000, 17000, 0, 180);
  AcY = map(AcY, -17000, 17000, 0, 180);
  AcZ = map(AcZ, -17000, 17000, 0, 180);

  Serial.print("X: ");
  Serial.print(AcX);
  Serial.print("\tY: ");
  Serial.print(AcY);
  Serial.print("\tZ: ");
  Serial.println(AcZ);
}
