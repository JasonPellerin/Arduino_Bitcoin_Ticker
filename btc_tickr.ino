// btc_tickr.ino
#include <LiquidCrystal.h>

// Initialize lcd display
LiquidCrystal lcd(8, 6, 5, 4, 3, 2);

// Initialize RGB backlight
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
#define COMMON_ANODE

void setup() {
 // Initiaize output pins for RGB backlight
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
// Initialize LCD  
  lcd.begin(20, 4);
 // Set backlight color to Blue  
  setColor(0, 0, 255);  // blue
 // Print message to LCD before receiving serial data  
  lcd.print(" Hack The Planet!!! ");
 // Open serial port
  Serial.begin(9600);
}

void loop() {
  // Check for serial data input
  if (Serial.available()) {
    // Set serial data to vars
    float price = Serial.parseFloat();
    char end = Serial.read();
   // If BTC price is beow 300 turn Red light on  
    if  (price < 300.00) {
      setColor(255, 0, 0);  // Red
    }
   // Else if the BTC price is above 300, turn Green light on  
      else  {
      setColor(0, 255, 0);  // Red
    }
    
    // Display data to lcd
    lcd.clear();
    lcd.print(" CURRENT BTC PRICE  ");
    lcd.setCursor(6,2);
    lcd.print("$");
    lcd.setCursor(7,2);
    lcd.print(price);
  }
}

void setColor(int red, int green, int blue)
{
#ifdef COMMON_ANODE
red = 255 - red;
green = 255 - green;
blue = 255 - blue;
#endif
analogWrite(redPin, red);
analogWrite(greenPin, green);
analogWrite(bluePin, blue);
}
