int ro = 10;
int go = 9;
int bo = 8;
int boton = 2;

int colorActual = 0;
int estadoAnterior = HIGH;

void setColor(int r, int g, int b) {
    digitalWrite(ro, r);
    digitalWrite(go, g);
    digitalWrite(bo, b);
}

void setup() {
    pinMode(ro, OUTPUT);
    pinMode(go, OUTPUT);
    pinMode(bo, OUTPUT);
    pinMode(boton, INPUT_PULLUP);
    setColor(0, 0, 0);
}

void loop() {
    int estadoActual = digitalRead(boton);
  
  if (estadoActual == LOW && estadoAnterior == HIGH) {
        colorActual++;
        if (colorActual > 7) colorActual = 1;
    
        if (colorActual == 1) setColor(1, 0, 0);
        if (colorActual == 2) setColor(0, 1, 1);
        if (colorActual == 3) setColor(0, 1, 0);
        if (colorActual == 4) setColor(1, 0, 1);
        if (colorActual == 5) setColor(0, 0, 1);
        if (colorActual == 6) setColor(1, 1, 1);
        if (colorActual == 7) setColor(1, 1, 0);
    
        delay(50);
  }
  
    estadoAnterior = estadoActual;
}