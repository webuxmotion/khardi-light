#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 4
#define DATA_PIN D3
int buttonPin = D6;
int buzzPin = D8;

int ledState;
int buzzState;

unsigned long previousMillis = 0; 
const long interval = 1000;

unsigned long previousMillis2 = 0; 
const long interval2 = 20;

CRGB leds[NUM_LEDS];

int randd() {
  const int max = 255;
  const int min = 0;

  int range = max - min + 1;
  int num = rand() % range + min;

  return num;
}

void setup()
{
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(buzzPin, OUTPUT);   
}

void loop()
{
  unsigned long currentMillis = millis();
  //int buttonState = digitalRead(buttonPin);

  // leds[0] = CRGB(255, 0, 0);
  // leds[1] = CRGB(255, 0, 0);
  // leds[2] = CRGB(255, 0, 0);
  // leds[3] = CRGB(255, 0, 0);

  // if (buttonState == LOW) {
  //   FastLED.show();
  // } else {
  //   for(int dot = 0; dot < NUM_LEDS; dot++) { 
  //     leds[dot] = CRGB::Black;
  //   }

  //   FastLED.show();
  // }
  
  // digitalWrite(buzzPin, HIGH);
  // digitalWrite(buzzPin, LOW);

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (ledState == 0) {
      ledState = 20;
    } else {
      ledState = 0;
    }

    for(int dot = 0; dot < NUM_LEDS; dot++) { 
      leds[dot] = CRGB(ledState, 0, 0);
    }

    FastLED.show();
  }

  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;

    if (buzzState == LOW) {
      buzzState = HIGH;
    } else {
      buzzState = LOW;
    }

    digitalWrite(buzzPin, HIGH);
  }
}