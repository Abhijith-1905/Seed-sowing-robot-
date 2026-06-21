#define BLYNK_TEMPLATE_ID "TMPL3jjAc5az5"
#define BLYNK_TEMPLATE_NAME "seed sowing robot"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Motor Pins
#define ENA D5
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D0

// Servo Pin
#define SERVO_PIN D7

// Movement Variables
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;

int Speed = 800;

// Servo Object
Servo seedServo;

// Blynk Credentials
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// WiFi Credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

void setup() {

  Serial.begin(9600);
  Serial.println("Robot Starting...");

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  seedServo.attach(SERVO_PIN);
  seedServo.write(0);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

// Movement Controls
BLYNK_WRITE(V0) {
  forward = param.asInt();
}

BLYNK_WRITE(V1) {
  backward = param.asInt();
}

BLYNK_WRITE(V2) {
  left = param.asInt();
}

BLYNK_WRITE(V3) {
  right = param.asInt();
}

// Speed Control
BLYNK_WRITE(V5) {
  Speed = param.asInt();
}

// Seed Dispensing
BLYNK_WRITE(V6) {

  int value = param.asInt();

  if (value == 1) {

    Serial.println("Seed Dropped");

    seedServo.write(90);
    delay(1000);
    seedServo.write(0);
  }
}

void loop() {

  Blynk.run();
  smartcar();
}

void smartcar() {

  if (forward) {
    carForward();
  }
  else if (backward) {
    carBackward();
  }
  else if (left) {
    carLeft();
  }
  else if (right) {
    carRight();
  }
  else {
    carStop();
  }
}

// Forward
void carForward() {

  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Backward
void carBackward() {

  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Left
void carLeft() {

  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Right
void carRight() {

  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Stop
void carStop() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
