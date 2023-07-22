# gesturecar
The gesture control car, powered by Arduino and a gyro sensor, offers an engaging experience, allowing users to control the car's movements through hand gestures. The Arduino processes data from the gyro sensor, interpreting tilt angles to determine the desired direction. By cleverly mapping gestures to motor commands, the car moves forward, backward, turns left, or right. Your programming skills played a vital role in implementing the gesture recognition algorithm. This innovative project showcases your technical aptitude and creativity, offering exciting possibilities for human-computer interaction and inspiring others in the maker community. The gesture control car exemplifies the fusion of electronics and robotics, opening doors to future technological advancements.



Creating a Bluetooth gesture-controlled car using Arduino is an exciting project that combines robotics, electronics, and wireless communication. Here are step-by-step instructions to guide you through the process:

**Materials Required:**
1. Arduino board (e.g., Arduino Uno or Arduino Nano)
2. Motor driver module (e.g., L298N or L293D)
3. Two DC motors with wheels + 2 free wheel
4. Bluetooth module (HC-05 )
5. Chassis or frame to build the car
6. Power supply (e.g., battery pack or power bank)
7. Jumper wires and breadboard (optional) for connections

**Connection Instructions
(GESTURE SENSOR)**

Connect MPU6050 to Arduino:

VCC to 5V on Arduino
GND to GND on Arduino
SDA to A4 (SDA) on Arduino
SCL to A5 (SCL) on Arduino
Connect HC-05/HC-06 to Arduino:

VCC to 5V on Arduino
GND to GND on Arduino
TXD to RX (pin 11) on Arduino
RXD to TX (pin 10) on Arduino
Connect Motors to Arduino:

Connect the left motor to two digital pins on the Arduino (e.g., pins 5 and 6).
Connect the right motor to two digital pins on the Arduino (e.g., pins 9 and 10).
Connect Power Supply:

Connect the positive terminal of the power supply to the VCC on the Arduino board.
Connect the negative terminal of the power supply to the GND on the Arduino board.
Connect the VCC of the MPU6050 and HC-05/HC-06 modules to the 5V on the Arduino board.
Connect the GND of the MPU6050 and HC-05/HC-06 modules to the GND on the Arduino board.


