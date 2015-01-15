bool visualize = false;
int val = 0;

char im[128], data[128];
char data_avgs[14];

void Visualize()
{
  int i = 0;
  while (i < 128)
  {
    val = analogRead(MIC);
    if (val < 693 && val > 311)
    {
      if (i > 0)
      {
        i--;
      }
    }
    else
    {
      data[i] = val / 8;
      im[i] = 0;
      i++;
    }
  }
  fix_fft(data, im, 7, 0);
  for (int i = 0; i < 64; i++)
  {
    data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
  }
  for (int i = 0; i < 14; i++)
  {
    data_avgs[i] = data[i * 4] + data[i * 4 + 1] + data[i * 4 + 2] + data[i * 4 + 3];
    data_avgs[i] = map(data_avgs[i], 0, 30, 0, 9);
  }
  for (int x = 0; x < 8; x++)
  {
    for (int y = 0; y < 8; y++)
    {
      if (y > data[8 - x])
      {
        temp[x][y] = 2;
      }
      else
      {
        temp[x][y] = 0;
      }
    }
  }
  showSprite(temp, 8);
}

void Volume()
{
  int VU = (analogRead(MIC));
  if (VU > 455 && VU < 555)
  {
    showVolume(2);
  }
  else if (VU > 378 && VU < 624)
  {
    showVolume(3);
  }
  else if (VU > 311 && VU < 693)
  {
    showVolume(4);
  }
  else if (VU > 244 && VU < 762)
  {
    showVolume(5);
  }
  else if (VU > 177 && VU < 831)
  {
    showVolume(6);
  }
  else if (VU < 177 || VU > 831)
  {
    showVolume(7);
  }
  delay(1);
}

void showVolume(int volume)
{
  for (int i = 0; i < 8; i++)
  {
    temp[0][i] = 0;
  }
  for (int i = 0; i < volume; i++)
  {
    temp[0][i] = 2;
    if (volume >= 7)
    {
      temp[0][i] = 1;
    }
  }
  showSprite(temp, 5);
}
