#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
void subjectMenu();
void math();
void chemistry();
void history();
void geography();
void deutsch();
void english();
void test();
void InitGame();
void UpdateGame();
void DrawGame();
void UpdateInput();
void questionn();
extern int questionNum;
extern int asnwerNum;
extern int choosenOne;
extern int choosenTwo;
int login(void);