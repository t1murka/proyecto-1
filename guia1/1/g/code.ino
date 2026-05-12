const int r1 = 13, g1 = 12, b1 = 11;
const int r2 = 10, g2 = 9,  b2 = 8;
const int r3 = 7,  g3 = 6,  b3 = 5;
const int boton = 2;

int ledActual = 0;
int estadoAnterior = HIGH;

void apagar() {
    digitalWrite(r1, LOW); digitalWrite(g1, LOW); digitalWrite(b1, LOW);
    digitalWrite(r2, LOW); digitalWrite(g2, LOW); digitalWrite(b2, LOW);
    digitalWrite(r3, LOW); digitalWrite(g3, LOW); digitalWrite(b3, LOW);
}

void encenderLed(int led) {
    apagar();
  if      (led == 1) { digitalWrite(r1, HIGH); digitalWrite(g1, HIGH); digitalWrite(b1, HIGH); }
  else if (led == 2) { digitalWrite(r2, HIGH); digitalWrite(g2, HIGH); digitalWrite(b2, HIGH); }
  else if (led == 3) { digitalWrite(r3, HIGH); digitalWrite(g3, HIGH); digitalWrite(b3, HIGH); }
}

void setup() {
    pinMode(r1, OUTPUT); pinMode(g1, OUTPUT); pinMode(b1, OUTPUT);
    pinMode(r2, OUTPUT); pinMode(g2, OUTPUT); pinMode(b2, OUTPUT);
    pinMode(r3, OUTPUT); pinMode(g3, OUTPUT); pinMode(b3, OUTPUT);
    pinMode(boton, INPUT_PULLUP);
    apagar();
}

void loop() {
    int estadoActual = digitalRead(boton);

  if (estadoActual == LOW && estadoAnterior == HIGH) {
        ledActual++;
        if (ledActual > 3) ledActual = 1;
        encenderLed(ledActual);
        delay(50);
  }

    estadoAnterior = estadoActual;
}
