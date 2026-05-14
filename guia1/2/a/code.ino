const int LED = 3;

void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    analogWrite(LED, 50);
    delay(1000);

    analogWrite(LED, 100);
    delay(1000);

    analogWrite(LED, 150);
    delay(1000);

    analogWrite(LED, 200);
    delay(1000);

    analogWrite(LED, 250);
    delay(1000);
}