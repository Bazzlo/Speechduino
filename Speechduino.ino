/***********DEFINITIONS***********/
#define MIC A7
#define LED 13
#define BAUD 9600
/***********LIBRARIES*************/
#include <fix_fft.h>
#include <BitVoicer11.h>
#include "patterns.h"
/***********CONSTANTS*************/
const int LedRow[] = {36, 34, 32, 30, 47, 49, 51, 53};
const int grn[] =   {31, 33, 35, 37, 39, 41, 43, 45};
const int red[] =   {29, 27, 25, 23, 22, 24, 26, 28};
/***********VARIABLES*************/
byte dataType = 0;
bool sleep = false;
BitVoicerSerial bvSerial = BitVoicerSerial();

enum Mode { WAKE, SLEEP, EX1, EX2, EX3, RED, GREEN, SIMONSAYS, SNAKE, VISUALIZER };
Mode mode;

int receivedNumber;

/***********METHODS***************/
void setup()
{
  /* Pin setup */
  for (int i = 0; i < 8; i++)
  {
    pinMode(red[i], OUTPUT);
    pinMode(grn[i], OUTPUT);
    pinMode(LedRow[i], OUTPUT);
  }
  pinMode(LED, OUTPUT);
  pinMode(MIC, INPUT);

  /* Bitvoicer Setup */
  Serial.begin(BAUD);

  /* Emic2 Setup */
  Serial1.begin(BAUD);
  Serial1.print('\n');
  while (Serial1.read() != ':');
  Serial1.print('V-40\n');
  delay(10);
  Serial1.flush();
  mode = WAKE;
}

void loop()
{
  if (mode == WAKE)
  {
    showSprite(happyFace, 100);
    //SimonSays_Run();
  }
}

void serialEvent()
{
  if (sleep == false)
  {
    dataType = bvSerial.getData();
    if (dataType == BV_STR)
    { 
      String data = bvSerial.strData;
      if (data == "WAKE")
        mode = WAKE;
      if (data == "SLEEP")
        mode = SLEEP;
      if (data == "EXAMPLE1")
        mode = EX1;
      example1();
      mode = WAKE;
      if (data == "EXAMPLE2")
        mode = EX2;
      example2();
      mode = WAKE;
      if (data == "EXAMPLE3")
        mode = EX3;
      example3();
      mode = WAKE;
      if (data == "RED")
        mode = RED;
      showSprite(redLeds, 2000);
      mode = WAKE;
      if (data == "GREEN")
        mode = GREEN;
      showSprite(greenLeds, 2000);
      mode = WAKE;
      if (data == "SIMONSAYS")
        mode = SIMONSAYS;
      SimonSays_Run();
      if (data == "SNAKE")
        mode = SNAKE;
      Snake_Run();
      if (data == "VISUALIZER")
        mode = VISUALIZER;
      if (data == "SNAKE-UP" && mode == SNAKE)
        moveSnake('u');
      if (data == "SNAKE-DOWN" && mode == SNAKE)
        moveSnake('d');
      if (data == "SNAKE-RIGHT" && mode == SNAKE)
        moveSnake('r');
      if (data == "SNAKE-LEFT" && mode == SNAKE)
        moveSnake('l');
      if (data == "ss1" && mode == SIMONSAYS)
        receivedNumber = 1;
      if (data == "ss2" && mode == SIMONSAYS)
        receivedNumber = 2;
      if (data == "ss3" && mode == SIMONSAYS)
        receivedNumber = 3;
      if (data == "ss4" && mode == SIMONSAYS)
        receivedNumber = 4;
      if (data == "ss5" && mode == SIMONSAYS)
        receivedNumber = 5;
      if (data == "ss6" && mode == SIMONSAYS)
        receivedNumber = 6;
      if (data == "ss7" && mode == SIMONSAYS)
        receivedNumber = 7;
      if (data == "ss8" && mode == SIMONSAYS)
        receivedNumber = 8;
      if (data == "ss9" && mode == SIMONSAYS)
        receivedNumber = 9;
    }
  }
}

