//Created by Ayman Taleb 10/1/2024


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

//I2S audio inits
AudioPlaySdWav           playWav1;
AudioOutputI2S           audioOutput;
AudioConnection          patchCord1(playWav1, 0, audioOutput, 0);
AudioConnection          patchCord2(playWav1, 1, audioOutput, 1);
AudioControlSGTL5000     sgtl5000_1;

// SD Card init
#define SDCARD_CS_PIN    BUILTIN_SDCARD
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13  

//hall sensor init
int hallSensorPin = A0;
int sensorValue = 0;

const byte ledString2 = 32;



//variable inits
bool saberEnable = false;


void setup() {
  Serial.begin(9600);
  AudioMemory(8);
  // sgtl5000_1.enable();
  // sgtl5000_1.volume(0.05);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  
  pinMode(ledString2, OUTPUT);
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

 
  playWav1.play(filename);

 
  delay(25);

 
  while (playWav1.isPlaying()) {
  
  }
}


void loop() {
  // while(!Serial);
  sensorValue = analogRead(hallSensorPin);
  Serial.println(sensorValue);

  delay(200);
  if(sensorValue <= 1){
    Serial.println("CLOSED");
     if (saberEnable) {
      // Only turn off if it was previously enabled
    
      digitalWrite(ledString2, LOW);
      playFile("IGNITIONREV.WAV");
      saberEnable = false; // Disable saber
    }
  } else {
    if (!saberEnable) {
      // Only play the sound and turn on LEDs if saber was previously disabled
      digitalWrite(ledString2, HIGH);
      playFile("IGNITION.WAV");  // Play sound when the saber is activated
      saberEnable = true; // Enable saber
    }
  }

}

