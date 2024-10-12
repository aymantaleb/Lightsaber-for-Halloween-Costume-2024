/*
  Arduino LSM9DS1 - Simple Accelerometer

  This example reads the acceleration values from the LSM9DS1
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  The circuit:
  - Arduino Nano 33 BLE Sense

  created 10 Jul 2019
  by Riccardo Rizzo

  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>

const int buzzerPin = 21;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");
}

void playTone(int frequency) {
  analogWriteFrequency(buzzerPin, frequency);  // Set the frequency for the buzzer
  analogWrite(buzzerPin, 128);  // Duty cycle at 50% (PWM value is from 0 to 255)
}

void stopTone() {
  analogWrite(buzzerPin, 0);  // Turn off the sound
}

void loop() {
  float x, y, z;
  float a, b, c;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    IMU.readMagneticField(a, b, c);

    
    // delay(200);
    x = abs(x);
    y = abs(y);
    z = abs(z);

    a = abs(a);
    b = abs(b);
    c = abs(c);

    // Serial.print(x);
    // Serial.print('\t');
    // Serial.print(y);
    // Serial.print('\t');
    // Serial.println(z);

    Serial.print(a);
    Serial.print('\t');
    Serial.print(b);
    Serial.print('\t');
    Serial.println(c);

    int freq = map(a * 1000, -4000, 4000, 100, 2000);
    freq = constrain(freq, 100, 2000);  // Constrain frequency to reasonable buzzer range

    playTone(freq);
    delay(100);
    stopTone();
  }
}
