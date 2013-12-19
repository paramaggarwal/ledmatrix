int ver[] = {6, 11, 10, 3, 15, 4, 8, 9};
int hor[] = {2, 7, 17, 5, 13, 16, 12, 14};
int img[8][8];
int pinY = 4;
int pinX = 5;

void Refresh()
{
  for(int i=0; i<8; i++) {  
    for(int j=0;j<8;j++)
      digitalWrite(hor[j], 1);
      
    for(int j=0;j<8;j++) {
      if(j==i)
        digitalWrite(ver[j], HIGH);
      else
        digitalWrite(ver[j], LOW);
    }

    for(int j=0;j<8;j++)
      digitalWrite(hor[j], img[j][i]);
    
    delayMicroseconds(500);
  }
}

void ResetMatrix()
{
  for(int i=0; i<8; i++) {
    for(int j=0;j<8;j++) {
      img[i][j] = 1;
    }
  }
}
void setup()
{
  ResetMatrix();
  for(int i=0; i<18; i++)
    pinMode(i, OUTPUT);
    
    pinMode(18,INPUT);
    pinMode(19,INPUT);

}

void loop()
{
  int oldX,oldY;
  int newX, newY;
  
  newX = (analogRead(pinX) - 200)/40;
  newY = (analogRead(pinY) - 200)/40;
  
  img[newX][newY] = 0;
  
  for(int a=0; a<20; a++)
    Refresh();
  
  oldX = newX;
  oldY = newY;
  
  img[oldX][oldY] = 1;
}
