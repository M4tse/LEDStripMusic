#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266Audio.h>
#include "AudioGenerator.h"
#include "AudioOutput.h";
const char* ssid = "bytewerk";
const char* password = "bluemchenwiese";

const char* radioUrl = "https://www.radio.net/s/jazz24";
AudioFileSourceHTTPStream *file = new AudioFileSourceHTTPStream(radioUrl);
AudioGenerator generator;
// Set up the audio output
AudioOutputI2S audioOutput;
AudioFileSourceICYStream audioStream;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");

    audioOutput.begin();
    
    audioStream.open(radioUrl);
    
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
    if (audioStream.isOpen()) {
        //const uint16_t* waveforms = audioStream.
        //generator.begin(file, );
    }
}