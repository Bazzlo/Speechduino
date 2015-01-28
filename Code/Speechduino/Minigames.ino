char* answers[20] = {
  "As I see it, yes",
  "It is certain",
  "It is decidedly so",
  "Mostly likely",
  "Outlook good",
  "Signs point to yes",
  "Without a doubt",
  "Yes",
  "Yes - definitely",
  "You may rely on it",
  "Reply hazy, try again",
  "Ask again later",
  "Better not tell you now",
  "Cannot predict now",
  "Concentrate and ask again",
  "Don't count on it",
  "My reply is no",
  "My sources say no",
  "Outlook not so good",
  "Very doubtful"
};

void eightBall()
{
  delay(2000);
  int seed = analogRead(MIC);
  int generatedSeed = random (-seed, seed);
  randomSeed(generatedSeed);
  int randNumber = random(20);
  emicSay(answers[randNumber]);
}

void rollDice()
{
  int seed = analogRead(MIC);
  int generatedSeed = random (-seed, seed);
  randomSeed(generatedSeed);
  int diceNumber = random(1, 7);
  int diceArray[12] = {1, 3, 6, 4, 2, 3, 5, 1, 2, 6, 5, 4};
  emicSay("Rolling");
  for (int i = 0; i < 12; ++i)
  {
    showDice(diceArray[i], 75, false);
  }
  showDice(diceNumber, 3000, true);
}

void showDice(int dice, int time, boolean speak)
{
  switch (dice)
  {
    case 1:
      if (speak){
        emicSay("one");
      }
      showSprite(diceOne, time);
      break;
    case 2:
      if (speak){
        emicSay("two");
      }
      showSprite(diceTwo, time);
      break;
    case 3:
      if (speak){
        emicSay("three");
      }
      showSprite(diceThree, time);
      break;
    case 4:
      if (speak){
        emicSay("four");
      }
      showSprite(diceFour, time);
      break;
    case 5:
      if (speak){
        emicSay("five");
      }
      showSprite(diceFive, time);
      break;
    case 6:
      if (speak){
        emicSay("six");
      }
      showSprite(diceSix, time);
      break;
  }
}

void simonSaysStart()
{
  //Set game
  currentNumber = 0;
  for (int i = 0; i < 8; ++i)
  {
     receivedNumbers[i] = 0; 
  }
  int seed = analogRead(MIC);
  int generatedSeed = random (-seed, seed);
  randomSeed(generatedSeed);
  for (int i = 0; i < 10; ++i)
  {
    numbers[i] = 0;
  }

  //Fill array with random numbers
  for (int i = 0; i < sizeof(numbers); i++)
  {
    int ran = random(1, 10);
    //Prevent repetition of 3
    while ((numbers[i - 1] == ran) && ((numbers[i - 2] == ran) && (numbers[i-3] == ran)))
    {
      ran = random(1, 10);
    }
    numbers[i] = ran;
  }
  emicSay("Repeat the numbers you see on the screen,    eech raawnd adds another number to the list");
  showSprite(happyFace2, 300);
}

void simonSaysRun(int cn)
{
  //Start game
  simonSaysStart();
  for (int i = 0; i <= cn; ++i)
  {
    displayNumber(numbers[i]);
  }
}

void checkReceivedAmount()
{
  int inputNumbers;
  for(int i = 0; i < sizeof(receivedNumbers); ++i)
  {
      if(receivedNumbers[i] != 0)
      {
         inputNumbers++; 
      }
  }
  /*
  if(inputNumbers == )
  {
    
  }
  */
}

void displayNumber(int n)
{
  int ss_display_speed = 35;
  switch (n)
  {
    case 1:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sone\n");
      while (Serial1.read() != ':')
      {
        showSprite(one, ss_display_speed);
      }

      break;
    case 2:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Stwo\n");
      while (Serial1.read() != ':')
      {
        showSprite(two, ss_display_speed);
      }

      break;
    case 3:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sthree\n");
      while (Serial1.read() != ':')
      {
        showSprite(three, ss_display_speed);
      }

      break;
    case 4:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sfour\n");
      while (Serial1.read() != ':')
      {
        showSprite(four, ss_display_speed);
      }
      break;
    case 5:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sfive\n");
      while (Serial1.read() != ':')
      {
        showSprite(five, ss_display_speed);
      }
      break;
    case 6:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Ssix\n");
      while (Serial1.read() != ':')
      {
        showSprite(six, ss_display_speed);
      }
      break;
    case 7:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sseven\n");
      while (Serial1.read() != ':')
      {
        showSprite(seven, ss_display_speed);
      }
      break;
    case 8:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Seight\n");
      while (Serial1.read() != ':')
      {
        showSprite(eight, ss_display_speed);
      }
      break;
    case 9:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Snine\n");
      while (Serial1.read() != ':')
      {
        showSprite(nine, ss_display_speed);
      }
      break;
  }
}

void snakeStart()
{
  //Set empty field
  for (int y = 0; y < 8; ++y)
  {
    for (int x = 0; x < 8; ++x)
    {
      snakefield[y][x] = 0;
    }
  }

  //Starting length of snake
  snakelength = 2;

  //Fill food array
  for (int i = 0; i < 10; ++i)
  {
    foodx[i] = random(1, 9);
    foody[i] = random(1, 9);
  }

  //Set beginning position of snake
  snakey[0] = 4;
  snakey[1] = 5;
  snakex[0], snakex[1] = 4;
}

void snakeRun()
{
  snakeStart();
  boolean playing = true;
  while (playing)
  {
    drawField();
    checkCollision();
  }
}

void snakeEnd()
{

}

void moveSnake(char c)
{
  int newsnakex[12];
  int newsnakey[12];
  for (int i = 0; i < 12; ++i)
  {
    //set new head coordinates
    if (c = 'u') //up
    {
      newsnakey[0] = snakey[0] + 1;
      newsnakex[0] = snakex[0];
    }
    else if (c = 'd') //down
    {
      newsnakey[0] = snakey[0] - 1;
      newsnakex[0] = snakex[0];
    }
    else if (c = 'r') //down
    {
      newsnakey[0] = snakey[0];
      newsnakex[0] = snakex[0] + 1;
    }
    else if (c = 'l') //down
    {
      newsnakey[0] = snakey[0];
      newsnakex[0] = snakex[0] - 1;
    }

    if ((i + 1) < snakelength)
    {
      newsnakex[i] = snakex[i - 1];
      newsnakey[i] = snakey[i - 1];
    }
    else
    {
      newsnakex[i], newsnakey[i] = -1;
    }

    //set new snake coordiantes
    for (int y = 0; y < 8; ++y)
    {
      snakey[y] = newsnakey[y];
    }
    for (int x = 0; x < 8; ++x)
    {
      snakex[x] = newsnakex[x];
    }
  }
}

void checkCollision()
{
  //Snake hits itself?
  for (int i = 1; i < 12; ++i)
  {
    if (snakex[0] == snakex[i] && snakey[0] == snakey[i])
    {
      snakeEnd();
    }
  }

  //Snake out of field?
  if ((snakex[0] > 8 || snakex[0] < 0) || (snakey[0] > 8 || snakey < 0))
  {
    snakeEnd();
  }

  if ((snakex[0] == foodx[10 - (12 - snakelength)]) && (snakey[0] == foody[10 - (12 - snakelength)]))
  {
    snakelength++;
  }
}

void drawField()
{
  snakefield[foody[9 - snakelength]][foodx[9 - snakelength]] = 2;
  showSprite(snakefield, 100);
}
