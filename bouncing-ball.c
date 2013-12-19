int ver[] = {6, 11, 10, 3, 15, 4, 8, 9};
int hor[] = {2, 7, 17, 5, 13, 16, 12, 14};
int img[8][8];
int pinY = 4;
int pinX = 5;

int posX = 10, posY = 0;
int difx = 0, dify = 0;  
  
int startX = analogRead(pinX);
int startY = analogRead(pinY);
  
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
  startX = analogRead(pinX);
  startY = analogRead(pinY);
}

void loop()
{
  posY = posY + dify;
  posX = posX + difx;
  
  if(posX >= 70){
    difx = -difx * 0.9;
    posX = 70;
  }
  if(posX <= 0){
    difx = -difx * 0.9;
    posX = 0;
  }  
  if(posY >= 70){
    dify = -dify * 0.9;
    posY = 70;
  }
  if(posY <= 0){
    dify = -dify * 0.9;
    posY = 0;
  }
  img[posX/10][posY/10] = 0;
  
  for(int a=0; a<10; a++)
    Refresh();
  
  img[posX/10][posY/10] = 1;
  
  dify += (analogRead(pinY)-startY)/20;
  difx += (analogRead(pinX)-startX)/20;
  
}
