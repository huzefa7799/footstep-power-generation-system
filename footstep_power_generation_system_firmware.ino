#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Use 0x3F if 0x27 doesn't work

const int voltagePin = A0;      // Piezo output connected to A0
const int ledControlPin = 7;    // Pin connected to base of BC547 via 10k resistor
const int threshold = 10;       // Trigger voltage set to 10 mV

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Generated Volts.:-");

  pinMode(ledControlPin, OUTPUT);  // Set pin 7 as output for LED control
  digitalWrite(ledControlPin, LOW); // Ensure LED is off initially
}

void loop() {
  int analogVal = analogRead(voltagePin);
  int millivolts = analogVal * 4.88;

  lcd.setCursor(0, 1);
  lcd.print(millivolts);
  lcd.print(" mV   ");  // Spaces to clear old values

  // Control LED through BC547 if voltage crosses threshold
  if (millivolts > threshold) {
    digitalWrite(ledControlPin, HIGH);  // Turn on LED
    delay(1000);                         // Keep it on briefly
    digitalWrite(ledControlPin, LOW);   // Turn off LED
  }

  delay(100);
}
