int ver[] = {6, 11, 10, 3, 15, 4, 8, 9};
int hor[] = {2, 7, 17, 5, 13, 16, 12, 14};
long start, end;

int img[8][8] =
{
  {0,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,0,0,1,0,0},
  {0,1,0,0,0,0,1,0}
};

int pinY = 4;
int pinX = 5;

int posX = 10, posY = 0;
int difx = 0, dify = 0;  
  
int startX = analogRead(pinX);
int startY = analogRead(pinY);
  
void Refresh()
{
  for(int k=1; k<=5; k++) {
    for(int i=0; i<8; i++) {  
      for(int j=0;j<8;j++)
        digitalWrite(hor[j], HIGH);
      
      for(int j=0;j<8;j++) {
        if(j==i)
          digitalWrite(ver[j], HIGH);
        else
          digitalWrite(ver[j], LOW);
      }
       
      for(int j=0;j<8;j++){
        if(img[j][i] >= k) {
          digitalWrite(hor[j], LOW);
        } else {
          digitalWrite(hor[j], HIGH);
        }
      }
       
      delayMicroseconds(100);
    }
  }
}

void ResetMatrix()
{
  for(int i=0; i<8; i++) {
    for(int j=0;j<8;j++) {
      img[i][j] = 0;
    }
  }
}
void setup()
{
 // ResetMatrix();
  for(int i=0; i<18; i++)
    pinMode(i, OUTPUT);
    
  pinMode(18,INPUT);
  pinMode(19,INPUT);
  startX = analogRead(pinX);
  startY = analogRead(pinY);
  start = millis();
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
  if(img[posX/10][posY/10] == 1){
     dify = -dify;
     difx = -difx;
  }
  
  img[posX/10][posY/10] = 4;
  
  for(int a=0; a<10; a++)
    Refresh();
  
  bool clear = true;
  for(int d=0; d<8; d++) {
     for(int e=0; e<8; e++) {
       if(img[d][e] == 1)
           clear = false;
     }
  }
  
  if(clear) {
    end = millis();
    delay(500);
    ResetMatrix();
      for(int g=0; g<64-(((int)end-start)/1000); g++) {
          img[g/8][g%8] = 4;
      }
      while(1)
        Refresh();        
  }
  
  img[posX/10][posY/10] = 0;
  
  dify += (analogRead(pinY)-startY)/20;
  difx += (analogRead(pinX)-startX)/20;
 
}
