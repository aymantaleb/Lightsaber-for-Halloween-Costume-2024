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
int ledString1 = 33;
int ledString2 = 32;



//variable inits
bool saberEnable = false;
// bool 

void setup() {
  Serial.begin(9600);
  AudioMemory(8);
  // sgtl5000_1.enable();
  // sgtl5000_1.volume(0.1);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    // stop here, but print a message repetitively
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  pinMode(ledString1, OUTPUT);
  pinMode(ledString2, OUTPUT);
}

void playFile(const char *filename)
{
  Serial.print("Playing file: ");
  Serial.println(filename);

  // Start playing the file.  This sketch continues to
  // run while the file plays.
  playWav1.play(filename);

  // A brief delay for the library read WAV info
  delay(25);

  // Simply wait for the file to finish playing.
  while (playWav1.isPlaying()) {
  
  }
}


void loop() {
  while(!Serial);
  sensorValue = analogRead(hallSensorPin);
  Serial.println(sensorValue);

  delay(1000);
  if(sensorValue <= 10){
    Serial.println("CLOSED");
    saberEnable = false;
  }


  if(sensorValue > 10 && saberEnable == false){
    playFile("IGNITION.WAV");  // filenames are always uppercase 8.3 format
    digitalWrite(ledString1, HIGH);
    digitalWrite(ledString2, HIGH);
    saberEnable = true;
  }
  if(saberEnable == false){
    digitalWrite(ledString1, LOW);
    digitalWrite(ledString2, LOW);
    playFile("IGNITIONREV.WAV");
  }
  
  
}

