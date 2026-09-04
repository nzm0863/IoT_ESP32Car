#include <WiFi.h>
#include "wifi_config.h"
#include <wifi_manager.h>
#include <ota_manager.h>

// 前
const int STBY = 33;
const int PWMA = 25;
const int AIN1 = 26;
const int AIN2 = 27;

const int PWMB = 14;
const int BIN1 = 12;
const int BIN2 = 13;

// 後ろ
const int STBY2 = 23;
const int PWMC = 16;
const int CIN1 = 17;
const int CIN2 = 18;

const int PWMD = 19;
const int DIN1 = 21;
const int DIN2 = 22;

// スイッチ
const int SW = 4;


void setup() {
  Serial.begin(115200);

  wifiConnect(WIFI_SSID, WIFI_PASSWORD);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(PWMC, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);
  pinMode(STBY2, OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);

  pinMode(SW, INPUT_PULLUP);

  // TB6612有効化
  digitalWrite(STBY, HIGH);
  digitalWrite(STBY2, HIGH);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  ArduinoOTA.begin();

  Serial.println("OTA Ready");
}

void motorA(int speed) {
  if (speed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else if (speed < 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    speed = -speed;
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }

  analogWrite(PWMA, speed);
}
void motorB(int speed) {
  if (speed < 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    speed = -speed;
  } else if (speed > 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }

  analogWrite(PWMB, speed);
}
void motorC(int speed) {
  if (speed > 0) {
    digitalWrite(CIN1, HIGH);
    digitalWrite(CIN2, LOW);
  } else if (speed < 0) {
    digitalWrite(CIN1, LOW);
    digitalWrite(CIN2, HIGH);
    speed = -speed;
  } else {
    digitalWrite(CIN1, LOW);
    digitalWrite(CIN2, LOW);
  }

  analogWrite(PWMC, speed);
}
void motorD(int speed) {
  if (speed < 0) {
    digitalWrite(DIN1, HIGH);
    digitalWrite(DIN2, LOW);
    speed = -speed;
  } else if (speed > 0) {
    digitalWrite(DIN1, LOW);
    digitalWrite(DIN2, HIGH);
  } else {
    digitalWrite(DIN1, LOW);
    digitalWrite(DIN2, LOW);
  }

  analogWrite(PWMD, speed);
}

void forward(){
  motorA(200);
  motorB(200);
  motorC(200);
  motorD(200);
}
void back(){
  motorA(-200);
  motorB(-200);
  motorC(-200);
  motorD(-200);
}

void slideR() {
  motorA(200);
  motorB(-200);
  motorC(-200);
  motorD(200);
}
void slideL() {
  motorA(-200);
  motorB(200);
  motorC(200);
  motorD(-200);
}
void slideFR() {
  motorA(200);
  motorB(0);
  motorC(0);
  motorD(200);
}
void slideFL() {
  motorA(0);
  motorB(200);
  motorC(200);
  motorD(0);
}

void stopMoter() {
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  analogWrite(PWMC, 0);
  analogWrite(PWMD, 0);
}


unsigned long lastTime = 0;
bool forwardMode = true;

void loop() {
  ArduinoOTA.handle();

  if (digitalRead(SW) == LOW) {
    forward();
  } else {
    stopMoter();
  }

  // if (millis() - lastTime >= 1000) {
  //   lastTime = millis();
  //   if (forwardMode) {
  //     slideR();
  //   } else {
  //     slideL();
  //   }


  //   forwardMode = !forwardMode;
  // }
}