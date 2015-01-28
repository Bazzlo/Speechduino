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
