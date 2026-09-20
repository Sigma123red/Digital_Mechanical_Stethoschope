#include <LiquidCrystal.h>

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int piezoPin = A0;
const int potPin = A1;
const int buzzerPin = 8;
const int ledPin = 9;

int baseline = 0;

unsigned long lastDisplay = 0;
const unsigned long displayInterval = 250;

void setup() {
  Serial.begin(9600);

  pinMode(piezoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.clear();

  // Measure the resting piezo value
  long total = 0;

  for (int i = 0; i < 50; i++) {
    total += analogRead(piezoPin);
    delay(10);
  }

  baseline = total / 50;

  lcd.setCursor(0, 0);
  lcd.print("V: 0");

  lcd.setCursor(0, 1);
  lcd.print("Ready");
}

void loop() {

  // Find the biggest vibration during a short sampling window
  int peakDeviation = 0;

  unsigned long startTime = millis();

  while (millis() - startTime < 50) {

    int piezoValue = analogRead(piezoPin);

    int deviation = abs(piezoValue - baseline);

    if (deviation > peakDeviation) {
      peakDeviation = deviation;
    }
  }

  // Convert vibration to 0-100
  int vibrationLevel = map(peakDeviation, 0, 1000, 0, 100);
  vibrationLevel = constrain(vibrationLevel, 0, 100);

  // Potentiometer controls threshold
  int potValue = analogRead(potPin);

  int thresholdLevel = map(potValue, 0, 1023, 0, 100);
  thresholdLevel = constrain(thresholdLevel, 0, 100);

  // Alarm
  if (vibrationLevel >= thresholdLevel && vibrationLevel > 5) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 4000);
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

  // Update LCD only every 250 ms
  if (millis() - lastDisplay >= displayInterval) {

    lcd.setCursor(0, 0);
    lcd.print("V: ");
    lcd.print(vibrationLevel);
    lcd.print("          ");

    lcd.setCursor(0, 1);
    lcd.print("Thresh: ");
    lcd.print(thresholdLevel);
    lcd.print("       ");

    lastDisplay = millis();
  }

  // Serial
  Serial.print("Peak: ");
  Serial.print(peakDeviation);
  Serial.print(" | V: ");
  Serial.print(vibrationLevel);
  Serial.print(" | Threshold: ");
  Serial.println(thresholdLevel);
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
