void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(1, HIGH);
  digitalWrite(7, HIGH);
  delay(10000);
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  delay(2000);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  delay(10000);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
}