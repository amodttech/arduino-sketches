const int light = 2;
const int envelope = A0;

void setup() {
  Serial.begin(9600);
  pinMode(envelope, INPUT);
  pinMode(light, OUTPUT);
}

void loop() {
  int audioOut = analogRead(envelope);
  Serial.println(audioOut);
  delay(100);
}