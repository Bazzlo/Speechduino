int display_speed = 50;
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

void EightBall()
{
  delay(2000);
  randomSeed(analogRead(A0));
  int randNumber = random(20);
  emicSay(answers[randNumber]);
}

void SammySays()
{
  //Set game
  boolean ss_running = true;
  int numbers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  randomSeed(analogRead(A0));
  for (int i = 0; i < sizeof(numbers); i++)
  {
    int ran = random(1, 5);
    while((numbers[i-1] == ran) && (numbers[i-2] == ran))
    {
      ran = random(1, 5);
    }
    numbers[i] = ran;
  }
  emicSay("Repeat the numbers you see on the screen, each round adds another number to the list");

  //Start game
  for(int w = 0; w < 10; w++)
  {
     for(int i = 0; i < w; i++)
     {
       ss_shownumber(numbers[i]); 
     }
     showSprite(greenLeds, 300);
     boolean wfi = true;
     while (wfi == true)
     {
        //wacht op user input
        for(int i = 0; i < w; i++)
        {
         //check if input is correct 
        }
     }
  }
}

void ss_shownumber(int n)
{
  switch (n)
  {
    case 1:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sone\n");
      while (Serial1.read() != ':')
      {
        showSprite(ss_one, display_speed);
      }

      break;
    case 2:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Stwo\n");
      while (Serial1.read() != ':')
      {
        showSprite(ss_two, display_speed);
      }

      break;
    case 3:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sthree\n");
      while (Serial1.read() != ':')
      {
        showSprite(ss_three, display_speed);
      }
      
      break;
    case 4:
      Serial1.print('\n');
      while (Serial1.read() != ':');
      Serial1.print("Sfour\n");
      while (Serial1.read() != ':')
      {
        showSprite(ss_four, display_speed);
      }
      break;
  }
}
