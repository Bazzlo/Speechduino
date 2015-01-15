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

int temp[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

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

}

void loop()
{
  if (sleep == true)
  {
    return;
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
        sleep = false;
      if (data == "SLEEP")
        sleep = true;
      if (data == "EXAMPLE1")
        example1();
      if (data == "EXAMPLE2")
        example2();
      if (data == "EXAMPLE3")
        example3();
      if (data == "RED")
        showSprite(redLeds, 1000);
      if (data == "GREEN")
        showSprite(greenLeds, 1000);
      if (data == "EIGHTBALL")
        EightBall();
    }
  }
}

