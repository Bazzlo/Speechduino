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
int val;
int display_speed = 50;
int diceArray[5][12] = {
  {1, 3, 6, 4, 2, 3, 5, 1, 2, 6, 5, 4},
  {5, 4, 3, 6, 2, 3, 4, 1, 5, 2, 3, 4},
  {2, 3, 1, 4, 5, 3, 4, 2, 3, 1, 4, 5},
  {2, 3, 4, 2, 3, 5, 3, 4, 1, 2, 3, 2},
  {6, 3, 4, 5, 1, 2, 3, 1, 4, 5, 2, 1}
};
byte dataType = 0;
char im[128], data[128], data_avgs[14];
BitVoicerSerial bvSerial = BitVoicerSerial();
enum Mode { WAKE, SLEEP, EX1, EX2, EX3, RED, GREEN, EIGHTBALL, VISUALIZER, VOLUME, DICE };
Mode mode;
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
  speechduinoIntro();
  mode = WAKE;
}

void loop()
{
  if (mode == WAKE)
  {
    showSprite(happyFace, 100);
  }
}

void serialEvent()
{
  dataType = bvSerial.getData();

  if (dataType == BV_STR)
  {
    String data = bvSerial.strData;
    /***********MODES*************/
    if (mode == SLEEP)
    {
      if (data == "WAKE") {
        emicSay("Waking up");
        mode = WAKE;
      }
    }
    else if (mode != SLEEP)
    {
      if (data == "SLEEP") {
        emicSay("Going to sleep-mode");
        mode = SLEEP;
      }
      if (data == "EXAMPLEA") {
        mode = EX1;
        example1();
        mode = WAKE;
      }
      if (data == "EXAMPLEB") {
        mode = EX2;
        example2();
        mode = WAKE;
      }
      if (data == "EXAMPLEC") {
        mode = EX3;
        example3();
        mode = WAKE;
      }
      if (data == "RED") {
        mode = RED;
        showSprite(redLeds, 500);
        mode = WAKE;
      }
      if (data == "GREEN") {
        mode = GREEN;
        showSprite(greenLeds, 500);
        mode = WAKE;
      }
      if (data == "EIGHTBALL") {
        mode = EIGHTBALL;
        eightBall();
      }
      if (data == "VISUALIZER") {
        mode = VISUALIZER;
        displayVisualizer();
      }
      if (data == "VOLUME") {
        mode = VOLUME;
        displayVolume();
      }
      if (data == "DICE") {
        mode = DICE;
        rollDice();
      }
      if (data == "THANKS") {
         speechduinoSleep();
      }
    }
  }
}

