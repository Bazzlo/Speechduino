void example1()
{
  emicSay("Ardueeno executing example a");
  for (int i = 0; i < 7; i++)
  {
    showAnimation();
  }
}

void example2()
{
  emicSay("Arduino Executing example b");
  emicSing();
}

void example3()
{
  emicSay("Arduino executing example c");
  emicIntro();
}

void speechduinoIntro()
{
  emicSay("Hello, and welcome to the presentation of Speechduino");
  delay(100);
  emicSay("I am the Speechduino, I was made by Bas Preest and Lawrence Koohps during their minor");
}

void speechduinoSleep()
{
  emicSay("Your welcome");
  delay(400);
  emicSay("I am going to sleep, goodbye");
  mode = SLEEP;
}
