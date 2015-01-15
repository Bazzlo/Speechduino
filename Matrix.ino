void showAnimation()
{
  for (int i = 0; i < 8; i++)
  {
    for (int ii = 0; ii < 8; ii++)
    {
      temp[ii][i] = 1;
      showSprite(temp, 1);
    }
  }
  for (int i = 7; i >= 0; i--)
  {
    for (int ii = 7; ii >= 0; ii--)
    {
      temp[i][ii] = 2;
      showSprite(temp, 1);
    }
  }
  for (int i = 0; i < 8; i++)
  {
    for (int ii = 0; ii < 8; ii++)
    {
      temp[i][ii] = 1;
      showSprite(temp, 1);
    }
  }
  for (int i = 7; i >= 0; i--)
  {
    for (int ii = 7; ii >= 0; ii--)
    {
      temp[ii][i] = 2;
      showSprite(temp, 1);
    }
  }
}

void showSprite(int pattern[8][8], int time)
{
  for (int i = 0; i < time; i++)
  {
    for (int row = 0; row < 8; row++)
    {
      digitalWrite(LedRow[row], LOW);
      for (int column = 0; column < 8; column++)
      {
        switch (pattern[row][column])
        {
          case 0:
            digitalWrite(red[column], LOW);
            digitalWrite(grn[column], LOW);
            break;
          case 1:
            digitalWrite(red[column], HIGH);
            digitalWrite(grn[column], LOW);
            break;
          case 2:
            digitalWrite(red[column], LOW);
            digitalWrite(grn[column], HIGH);
            break;
          case 3:
            digitalWrite(grn[column], HIGH);
            digitalWrite(red[column], HIGH);
            break;
        }
      }
      delay(1);
      digitalWrite(LedRow[row], HIGH);
    }
  }
}
