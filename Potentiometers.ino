const int Q1 = A0, Q2 = A2, Q3 = A3;
int SensorVal1 = 0, SensorVal2 = 0, SensorVal3 = 0, onDelay = 500;
float q1Level = 0, q2Level = 0, q3Level = 0;

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  Serial.begin(115200);

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
    }
    
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
}

 
void loop() {

  SensorVal1 = analogRead(Q1);
  SensorVal2 = analogRead(Q2);
  SensorVal3 = analogRead(Q3);

// Adjust range as needed according to raw values printed in serial monitor

  q1Level = map(SensorVal1, 0, 800, 1, 3); 
  q2Level = map(SensorVal2, 0, 100, 1, 3);
  q3Level = map(SensorVal3, 0, 850, 1, 3);
 
 
  Serial.print("Value 1 = ");
  Serial.print(SensorVal1);

  Serial.print("\t Q1 = ");
  Serial.print(q1Level);
 
  Serial.print("\t Value 2 = ");
  Serial.print(SensorVal2);

  Serial.print("\t Q2 = ");
  Serial.print(q2Level);
 
  Serial.print("\t Value 3 = ");
  Serial.print(SensorVal3);

  Serial.print("\t Q3 = ");
  Serial.println(q3Level);
 
 // Output #1
    if (q1Level == 1 && q2Level == 1 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/12g"); // Answers #1: (1) :), Answer #2: (1) Subtle; Answer #3: (1) Light
  display.display();
    }
    
 // Output #2
    if (q1Level == 1 && q2Level == 1 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/12g"); // Answers #1: (1) :), Answer #2: (1) Subtle; Answer #3: (2) Medium
  display.display();  
    }

 // Output #3
    if (q1Level == 1 && q2Level == 1 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/12g"); // Answers #1: (1) :), Answer #2: (1) Subtle; Answer #3: (3) Dark
  display.display();   
    }

 // Output #4
    if (q1Level == 1 && q2Level == 2 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/14g"); // Answers #1: (1) :), Answer #2: (2) Balanced; Answer #3: (1) Light
  display.display();   
    }

  // Output #5
    if (q1Level == 1 && q2Level == 2 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/14g"); // Answers #1: (1) :), Answer #2: (2) Balanced; Answer #3: (2) Medium
  display.display();   
    }

  // Output #6
    if (q1Level == 1 && q2Level == 2 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/14g"); // Answers #1: (1) :), Answer #2: (2) Balanced; Answer #3: (3) Dark
  display.display();   
    }

  // Output #7
    if (q1Level == 1 && q2Level == 3 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/15g"); // Answers #1: (1) :), Answer #2: (3) Bold; Answer #3: (1) Light
  display.display();   
    }

// Output #8
    if (q1Level == 1 && q2Level == 3 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/15g"); // Answers #1: (1) :), Answer #2: (3) Bold; Answer #3: (2) Medium
  display.display();   
    }

// Output #9
    if (q1Level == 1 && q2Level == 3 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.setCursor(0, 10);
  display.println("Sumatra/15g"); // Answers #1: (1) :), Answer #2: (3) Bold; Answer #3: (3) Dark
  display.display();
    }

// Output #10
    if (q1Level == 2 && q2Level == 1 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/14g"); // Answers #1: (2) :|, Answer #2: (1) Subtle; Answer #3: (1) Light
  display.display();
    }

// Output #11
    if (q1Level == 2 && q2Level == 1 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/14g"); // Answers #1: (2) :|, Answer #2: (1) Subtle; Answer #3: (2) Medium
  display.display();  
    }

// Output #12
    if (q1Level == 2 && q2Level == 1 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/14g"); // Answers #1: (2) :|, Answer #2: (1) Subtle; Answer #3: (3) Dark
  display.display();  
    }

// Output #13
    if (q1Level == 2 && q2Level == 2 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/15g"); // Answers #1: (2) :|, Answer #2: (2) Balanced; Answer #3: (1) Light
  display.display();  
    }
    
// Output #14
    if (q1Level == 2 && q2Level == 2 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/15g"); // Answers #1: (2) :|, Answer #2: (2) Balanced; Answer #3: (2) Medium
  display.display();
    }

// Output #15
    if (q1Level == 2 && q2Level == 2 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/15g"); // Answers #1: (2) :|, Answer #2: (2) Balanced; Answer #3: (3) Dark
  display.display();
    }

// Output #16
    if (q1Level == 2 && q2Level == 3 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/16g"); // Answers #1: (2) :|, Answer #2: (3) Bold; Answer #3: (1) Light
  display.display();
    }
 
// Output #17
    if (q1Level == 2 && q2Level == 3 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/16g"); // Answers #1: (2) :|, Answer #2: (3) Bold; Answer #3: (2) Medium
  display.display();
    }

// Output #18
    if (q1Level == 2 && q2Level == 3 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/16g"); // Answers #1: (2) :|, Answer #2: (3) Bold; Answer #3: (3) Dark
  display.display();
    }

// Output #19
    if (q1Level == 3 && q2Level == 1 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/15g"); // Answers #1: (3) :(, Answer #2: (1) Subtle; Answer #3: (1) Light
  display.display();
    }

 // Output #20
    if (q1Level == 3 && q2Level == 1 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/15g"); // Answers #1: (3) :(, Answer #2: (1) Subtle; Answer #3: (2) Medium
  display.display();
    }
 
 // Output #21
    if (q1Level == 3 && q2Level == 1 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/15g"); // Answers #1: (3) :(, Answer #2: (1) Subtle; Answer #3: (3) Dark
  display.display();
    }
      
 // Output #22
    if (q1Level == 3 && q2Level == 2 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/16g"); // Answers #1: (3) :(, Answer #2: (2) Balanced; Answer #3: (1) Light
  display.display();
    }

// Output #23
    if (q1Level == 3 && q2Level == 2 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/16g"); // Answers #1: (3) :(, Answer #2: (2) Balanced; Answer #3: (2) Medium
  display.display();
    }

// Output #24
    if (q1Level == 3 && q2Level == 2 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/16g"); // Answers #1: (3) :(, Answer #2: (2) Balanced; Answer #3: (3) Dark
  display.display();
    }

// Output #25  
    if (q1Level == 3 && q2Level == 3 && q3Level == 1) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Rwanda/18g"); // Answers #1: (3) :(, Answer #2: (3) Bold; Answer #3: (1) Light
  display.display();
    }

// Output #26
    if (q1Level == 3 && q2Level == 3 && q3Level == 2) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Gtmala/18g"); // Answers #1: (3) :(, Answer #2: (3) Bold; Answer #3: (2) Medium
  display.display();
    }

// Output #27    
    if (q1Level == 3 && q2Level == 3 && q3Level == 3) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sumatra/18g"); // Answers #1: (3) :(, Answer #2: (3) Bold; Answer #3: (3) Dark
  display.display();
    }

  delay(onDelay);
 
  }
