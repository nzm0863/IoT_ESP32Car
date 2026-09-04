#pragma once

#include <Bluepad32.h>

extern ControllerPtr myControllers[BP32_MAX_GAMEPADS];

// 初期化・更新
void controlBegin();
void controlUpdate();

// 接続状態
bool isControllerConnected();

// スティック
int leftStickX();
int leftStickY();
int rightStickX();
int rightStickY();

// トリガー
int brake();
int throttle();

// ボタン
bool buttonA();
bool buttonB();
bool buttonX();
bool buttonY();
bool buttonL1();
bool buttonR1();
bool buttonL2();
bool buttonR2();

// 十字キー
uint8_t dpad();