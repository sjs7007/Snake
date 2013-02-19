//new start
//best upto now
//add colours to snake
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>


void draw(char c, int x,int y,int r,int length)
{
 for(int i=0;i<length;i++)
 {
  if(c=='a')
  {
   for(int j=0;j<=r;j++)
   {
    circle((x-2*r*i),y,j);
   }
  }
  else if(c=='d')
  {
   for(int j=0;j<=r;j++)
   {
    circle((x+2*r*i),y,j);
   }
  }
  else if(c=='w')
  {
   for(int j=0;j<=r;j++)
   {
    circle(x,(y-2*r*i),j);
   }
  }
  else if(c=='x')
  {
   for(int j=0;j<=r;j++)
   {
    circle(x,(y+2*r*i),j);
   }
  }
 }
}

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"C:\\tc\\bgi");
 char ch='a';
 int length=3;
 int x=100,y=100;
 int xegg,yegg;
 int eggFlag=0; //plot egg whenever flag is 0
 while(ch!='p')
 {
  if(length==10)
  {
   printf("You win!");
   break;
  }
  //don't use clrscr() in graphics mode
  if(kbhit())
  {
   ch=getch();
  // cleardevice();
  }
  for(int i=0;i<10000;i++)
  {
   for(int j=0;j<100;j++)
   {
   }
  }
  cleardevice();
  if(eggFlag==0)
  {
   xegg=rand()%640;
   yegg=rand()%480;
  }
  circle(xegg,yegg,10);
  eggFlag++;
  if(eggFlag==1000)
  {
   eggFlag=0;
  }
  if(xegg==x)
  {
   int flag=0;
   for(int i=yegg;i>=yegg-5;i--)
   {
    if(i==y)
    {
     flag=1;
     break;
    }
   }
   for(i=yegg;i<=yegg+5;i++)
   {
    if(i==y)
    {
     flag=1;
     break;
    }
   }
   if(flag==1)
   {
    length++;
    eggFlag=0;
   }
  }
  else if(yegg==y)
   {
    int flag=0;
    for(int i=xegg;i>=xegg-5;i--)
    {
     if(i==x)
     {
      flag=1;
      break;
     }
    }
    for(i=xegg;i<=xegg+5;i++)
    {
     if(i==x)
     {
      flag=1;
      break;
     }
    }
    if(flag==1)
    {
     length++;
     eggFlag=0;
    }
   } 	
  if(ch=='a')
   {
    x=x-1;
    if(x<0)
    {
     x=639;
    }
    draw(ch,x,y,10,length);
   }
   else if(ch=='d')

   {
    x=x+1;
    if(x>639)
    {
     x=0;
    }
    draw(ch,x,y,10,length);
   }
   else if(ch=='w')
   {
    y=y-1;
    if(y<0)
    {
     y=479;
    }
    draw(ch,x,y,10,length);
   }
   else if(ch=='x')
   {
    y=y+1;
    if(y>479)
    {
     y=0;
    }
    draw(ch,x,y,10,length);
   }
   else if(ch=='p')
   {
    break;
   }
 }
 getch();
 closegraph();
}
