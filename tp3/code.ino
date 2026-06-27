#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int temperaturaPin = A0;
const int luzPin = A3;
const int pirPin = 7;

const int trigPin = 5;
const int echoPin = 6;

const int buzzerPin = 12;

const int rojoPin = 9;
const int azulPin = 10;
const int verdePin = 11;

void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(rojoPin, OUTPUT);
  pinMode(verdePin, OUTPUT);
  pinMode(azulPin, OUTPUT);

  digitalWrite(trigPin, LOW);

  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);

  lcd.setCursor(0, 0);
  lcd.print("Sistema museo");

  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");

  delay(1500);
  lcd.clear();
}

void loop() {
  int valorTemperatura = analogRead(temperaturaPin);

  float voltaje =
    valorTemperatura * 5.0 / 1023.0;

  float temperatura =
    (voltaje - 0.5) * 100.0;

  int valorLuz = analogRead(luzPin);

  int porcentajeLuz =
    map(valorLuz, 0, 1023, 0, 100);

  porcentajeLuz =
    constrain(porcentajeLuz, 0, 100);

  bool noche = porcentajeLuz < 20;

  int movimiento = digitalRead(pirPin);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duracion =
    pulseIn(echoPin, HIGH, 30000);

  float distancia;

  if (duracion == 0) {
    distancia = -1;
  } else {
    distancia =
      duracion * 0.0343 / 2.0;
  }

  lcd.setCursor(0, 0);
  lcd.print("                ");

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.print("C");

  lcd.print(" L:");
  lcd.print(porcentajeLuz);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("                ");

  lcd.setCursor(0, 1);
  lcd.print("D:");

  if (distancia == -1) {
    lcd.print("---");
  } else {
    lcd.print((int)distancia);
  }

  lcd.print("cm M:");

  if (movimiento == HIGH) {
    lcd.print("SI");
  } else {
    lcd.print("NO");
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.print(" C");

  Serial.print(" | Luz: ");
  Serial.print(porcentajeLuz);
  Serial.print("%");

  Serial.print(" | Movimiento: ");

  if (movimiento == HIGH) {
    Serial.print("SI");
  } else {
    Serial.print("NO");
  }

  Serial.print(" | Distancia: ");

  if (distancia == -1) {
    Serial.print("SIN RESPUESTA");
  } else {
    Serial.print(distancia, 1);
    Serial.print(" cm");
  }

  Serial.print(" | Momento: ");

  if (noche == true) {
    Serial.print("NOCHE");
  } else {
    Serial.print("DIA");
  }

  analogWrite(rojoPin, 0);
  analogWrite(verdePin, 0);
  analogWrite(azulPin, 0);

  noTone(buzzerPin);

  if (
    noche == true &&
    (
      movimiento == HIGH ||
      temperatura > 39
    )
  ) {
    analogWrite(rojoPin, 255);
    analogWrite(verdePin, 0);
    analogWrite(azulPin, 0);

    tone(buzzerPin, 1600);
    delay(200);

    tone(buzzerPin, 900);
    delay(200);

    noTone(buzzerPin);

    Serial.println(
      " | Estado: ALARMA NOCTURNA"
    );
  }

  else if (
    noche == false &&
    distancia > 0 &&
    distancia < 100
  ) {
    analogWrite(rojoPin, 255);
    analogWrite(verdePin, 0);
    analogWrite(azulPin, 0);

    tone(buzzerPin, 1500, 100);
    delay(150);

    tone(buzzerPin, 1500, 100);
    delay(150);

    tone(buzzerPin, 1500, 100);
    delay(150);

    Serial.println(
      " | Estado: DISTANCIA MENOR A 1 METRO"
    );
  }

  else if (temperatura > 39) {
    analogWrite(rojoPin, 255);
    analogWrite(verdePin, 0);
    analogWrite(azulPin, 0);

    tone(buzzerPin, 1200, 200);

    Serial.println(
      " | Estado: TEMPERATURA ALTA"
    );
  }

  else if (movimiento == HIGH) {
    analogWrite(rojoPin, 255);
    analogWrite(verdePin, 255);
    analogWrite(azulPin, 0);

    tone(buzzerPin, 900, 150);

    Serial.println(
      " | Estado: MOVIMIENTO DETECTADO"
    );
  }

  else {
    analogWrite(rojoPin, 0);
    analogWrite(verdePin, 0);
    analogWrite(azulPin, 0);

    noTone(buzzerPin);

    if (noche == true) {
      Serial.println(
        " | Estado: VIGILANCIA NOCTURNA"
      );
    } else {
      Serial.println(
        " | Estado: NORMAL"
      );
    }
  }

  delay(500);
}