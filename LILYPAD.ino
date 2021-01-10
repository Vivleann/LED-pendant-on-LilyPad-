#define num 9
int mass[num * 2] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3};
int delay_time = 160;
int delay_circle = 80;

void setup()
{
  for (int i = 0; i < num * 2; i++)
  {
    pinMode(mass[i], OUTPUT);
    if (i % 2 == 0)
      digitalWrite(mass[i], 0);
  }
  randomSeed(analogRead(0));
}

void loop()
{
  up();
  circle();
  middle();
  star();
  middle();
  uncircle();
  down();
}

void up()
{
  for (int j = 2; j < num; j += 2)
  {
    for (int i = 1; i < num * 2; i += j)
    {
      digitalWrite(mass[i], 1);
      delay(delay_time);
    }
    zero();

    for (int i = 1; i < num * 2; i += j)
    {
      digitalWrite(mass[i], 1);
    }
    delay(delay_time);
    zero();
  }
}

void down()
{
  for (int j = num - 1; j >= 2; j -= 2)
  {
    for (int i = num * 2 - 1; i >= 1; i -= j)
    {
      digitalWrite(mass[i], 1);
      delay(delay_time);
    }
    zero();

    for (int i = num * 2 - 1; i >= 1; i -= j)
    {
      digitalWrite(mass[i], 1);
    }
    delay(delay_time);
    zero();
  }
}

void all()
{
  for (int i = 1; i < num * 2; i += 2)
  {
    digitalWrite(mass[i], 1);
  }
  delay(delay_time);
}

void zero()
{
  for (int i = 1; i < num * 2; i += 2)
  {
    digitalWrite(mass[i], 0);
  }
  delay(delay_time);
}

void circle()
{
  for (int j = 1; j < num * 2; j += 2)
  {
    for (int i = j; i < num * 2; i += 2)
    {
      digitalWrite(mass[i], 1);
      delay(delay_circle);
    }

    for (int i = 1; i < j; i += 2)
    {
      digitalWrite(mass[i], 1);
      delay(delay_circle);
    }

    for (int i = j; i < num * 2; i += 2)
    {
      digitalWrite(mass[i], 0);
      delay(delay_circle);
    }

    for (int i = 1; i < j; i += 2)
    {
      digitalWrite(mass[i], 0);
      delay(delay_circle);
    }
  }
}

void uncircle()
{
  for (int j = num * 2 - 1; j >= 1; j -= 2)
  {
    for (int i = j; i >= 1; i -= 2)
    {
      digitalWrite(mass[i], 1);
      delay(delay_circle);
    }

    for (int i = num * 2 - 1; i > j; i -= 2)
    {
      digitalWrite(mass[i], 1);
      delay(delay_circle);
    }

    for (int i = j; i >= 1; i -= 2)
    {
      digitalWrite(mass[i], 0);
      delay(delay_circle);
    }

    for (int i = num * 2 - 1; i > j; i -= 2)
    {
      digitalWrite(mass[i], 0);
      delay(delay_circle);
    }
  }
}

void middle()
{
  for (int j = 1; j < 4; j++)
  {
    for (int i = 1; i < num * 2; i += 4)
    {
      digitalWrite(mass[i], 1);
    }
    delay(delay_time);
    zero();

    for (int i = 3; i < num * 2; i += 4)
    {
      digitalWrite(mass[i], 1);
    }
    delay(delay_time);
    zero();
  }
}

void star()
{
  for (int i = 1; i < num * num; i++)
  {
    int number = random(num * 2);
    if (number % 2 == 0)
      number++;

    digitalWrite(mass[number], 1);
    delay(delay_circle);
    digitalWrite(mass[number], 0);
  }
}
