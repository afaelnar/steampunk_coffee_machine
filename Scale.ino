// Load Cell part
#include "HX711.h"

#define calibration_factor 867 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2
const int buttonPin = 8;
int buttonState = 0;
HX711 scale;

// Adafruit Display Part
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  // Scale part
  //
  //
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0

  //OLED part
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }

}

void loop() {
  //button to ZERO it out
  if(digitalRead(buttonPin)){
    scale.tare();
    delay(1000);
  }
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(buttonPin));
  Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1); //scale.get_units() returns a float
  Serial.print(" grams"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
  // the oled part

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(14,12);

  float currentWeight = scale.get_units();
  if (currentWeight < 0.0 && currentWeight > -1.0)
    currentWeight = 0; 
    
  display.print(currentWeight, 0);
  display.print(" grams");
  display.display();
  
}
