int ver[] = {10, 14, 15, 7, 17, 8, 12, 13};
int hor[] = {6, 11, 19, 9, 3, 18, 2, 16};

int img[8][8] = 
{
  {1,1,1,1,1,0,0,1},
  {1,1,1,1,0,1,1,0},
  {0,1,1,0,1,1,1,1},
  {1,0,0,1,1,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,0,1,1,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0}
};

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
      digitalWrite(hor[j], img[i][j]);
    
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
  //ResetMatrix();
  for(int i=0; i<20; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
   for(int a=0; a<8; a++) {
       for(int b=0; b<8; b++) {
         if(b!=7) {
           img[a][b] = img[a][b+1];
         }else{
           img[a][b] = img[a][0];
         }
       }
   }
   
   for(int c=0; c<25; c++)
         Refresh();
}
