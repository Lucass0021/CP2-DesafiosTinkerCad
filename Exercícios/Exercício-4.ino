#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
#define PINO_TENSAO A0

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
}

void loop() {
  int tensao = analogRead(PINO_TENSAO);
  float valorTensao = tensao * (30.0 / 1023.0); 

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tensao: ");
  lcd.print(valorTensao, 1);
  lcd.print(" V");

  lcd.setCursor(0, 1);
  lcd.print("Status: ");

  if (valorTensao < 24) {
    lcd.print("NORMAL");
  } else if (valorTensao < 27) {
    lcd.print("ALERTA");
  } else {
    lcd.print("SOBRECARGA");
  }

  delay(2000);
}

// Link Projeto Tinkercad: https://www.tinkercad.com/things/1VjG3GZ6oed/editel?sharecode=4A7PLvyW82wYUuJ8QUYZbzXtbysa31lY-pM-h5-rXxE
