#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

int sound = A0;
int led = 13;
int val;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  val = analogRead(A0);  // read the input pin
  //analogWrite(ledPin, val / 4); 
  Serial.print(val*10);
  Serial.print(" ");
  delay(50);
  colorWipe(strip.Color(255, 0, 0), 50); // Red
}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
