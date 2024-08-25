#define TRIGGER_PIN D1  // Pin trigger sensor HC-SR04
#define ECHO_PIN D2     // Pin echo sensor HC-SR04
#define RELAY_PIN D3    // Pin relay
#define MAX_DISTANCE 5  // Jarak maksimum untuk mengaktifkan relay (dalam centimeter)

void setup() {
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Matikan relay pada awalnya
  Serial.begin(115200);
}

void loop() {
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < MAX_DISTANCE) {
    digitalWrite(RELAY_PIN, LOW); // Aktifkan relay
    Serial.println("Relay Aktif");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Matikan relay
    Serial.println("Relay Nonaktif");
  }
  delay(100);  // Hindari pembacaan terlalu cepat
}