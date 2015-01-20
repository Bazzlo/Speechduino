void emicSay(String s)
{
  Serial1.print('\n');
  while (Serial1.read() != ':');
  Serial1.print(s + "\n");
  while (Serial1.read() != ':')
  {
    //showSprite(happyFace2, 10);
  }
}

void emicParser(String s) //0 Dectalk, 1 Epson
{
  Serial1.print("P" + s + "\n");
  while (Serial1.read() != ':');
}

void emicVoice(String s)
{
  Serial1.print("N" + s + "\n");
  while (Serial1.read() != ':');
}

void emicSing()
{
  Serial1.print('\n');
  while (Serial1.read() != ':');
  Serial1.print("D1\n");
  while (Serial1.read() != ':')
  {
    showSprite(musicNote, 10);
  }
}

void emicIntro()
{
  Serial1.print('\n');
  while (Serial1.read() != ':');
  Serial1.print("D0\n");
  while (Serial1.read() != ':')
  {
    showSprite(happyFace2, 10);
  }
}
