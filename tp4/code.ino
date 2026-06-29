const int tmpPin = A0;
const int luzPin = A3;

const int ledRojo  = 4;
const int ledAzul  = 3;
const int ledVerde = 2;

void setup()
{
  Serial.begin(9600);

  pinMode(tmpPin, INPUT);
  pinMode(luzPin, INPUT);
  
  pinMode(ledRojo , OUTPUT);
  pinMode(ledAzul , OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop()
{
  int valorLuz = analogRead(luzPin);
  int porcentajeLuz = map(valorLuz, 54, 974, 100, 0);
  
  int valorTmp = analogRead(tmpPin);
  float voltaje = valorTmp * 5.0 / 1023.0;
  float temperatura = (voltaje - 0.5) * 100.0;

  Serial.print("El nivel de luz actual es: ");
  Serial.print(porcentajeLuz);
  Serial.println("%");

  Serial.print("La temperatura actual es: ");
  Serial.print(temperatura);
  Serial.print("ºc");
  Serial.print("\n\n");

  if (porcentajeLuz >= 30 && porcentajeLuz <= 70) {
    if (temperatura < 18) {
      ledOff();
      digitalWrite(ledAzul, HIGH);
    } else if (temperatura >= 18 && temperatura <= 90) {
      ledOff();
      digitalWrite(ledVerde, HIGH);
    } else {
      ledOff();
      digitalWrite(ledRojo, HIGH);
    }
  } else {
  	ledOff();
  }
}

void ledOff() {
  digitalWrite(ledRojo , LOW);
  digitalWrite(ledAzul , LOW);
  digitalWrite(ledVerde, LOW);
}