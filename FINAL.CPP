#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

#define lmax 8

void assignPosition(int x[],int y[],int length,char ch,int radius)
{	
	if(ch=='a')
	{
		for(int i=length-1;i>=1;i--)
		{
			x[i]=x[i-1];
			y[i]=y[i-1];
		}
		x[0]=x[1]-2*radius;
		y[0]=y[1];
	}
	else if(ch=='d')
	{
		for(int i=length-1;i>=1;i--)
		{
			x[i]=x[i-1];
			y[i]=y[i-1];
		}
		x[0]=x[0]+2*radius;
	}
	else if(ch=='w')
	{
		for(int i=length-1;i>=1;i--)
		{
			x[i]=x[i-1];
			y[i]=y[i-1];
		}
		x[0]=x[1];
		y[0]=y[0]-2*radius;
	}
	else if(ch=='x')
	{
		for(int i=length-1;i>=1;i--)
		{
			x[i]=x[i-1];
			y[i]=y[i-1];
		}
		x[0]=x[1];
		y[0]=y[0]+2*radius;
	}
}

void draw(int x[],int y[],int length,int radius)
{
	for(int i=0;i<length;i++)
	{
		ellipse(x[i],y[i],0,360,radius,radius);
  		setfillstyle(i,rand());
  		fillellipse(x[i],y[i],radius,radius);
	}
}

void egg(int x,int y)
{
	circle(x,y,5);
}

int checkVicinity(int xe, int ye, int xs,int ys,int radius) //return true if near egg
{
	int flag=0;
	if(abs(xe-xs)<=radius && abs(ye-ys)<=radius)
	{
		flag=1;
	}
	return flag;
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	char ch='d';
	int length=5; // Set initial length of snake as 3
	//int lmax=10; //max length
	int radius=10;
	int xPosition[lmax],yPosition[lmax];
	for(int i=0;i<length;i++)
	{
		xPosition[i]=100+i*2*radius;
		yPosition[i]=100;
	}
	draw(xPosition,yPosition,length,radius);
	char temp=ch,temp2;
	int xegg=rand()%640,yegg=rand()%480;
	int eggFlag=0;
	printf("Enter a to move left, d to move right, w to move up, x to move down, p to exit\n");
	printf("If the snake hits the boundary, game will be over else it will continue till snake length raeches 8 \n");
	printf("Mail me at sjs7007@gmail.com if you have any queries\n");
	ch=getch();
	cleardevice();
	while(ch!='p')
	{
		int temp2=checkVicinity(xegg,yegg,xPosition[0],yPosition[0],radius);
		if(temp2==1)
		{
			length=length+1;
			if(ch=='a')
			{
				for(int i=length;i>=1;i--)
				{
					xPosition[i]=xPosition[i-1];
				}
				xPosition[0]=xPosition[1]-2*radius;
				yPosition[0]=yPosition[1];
			}
			else if(ch=='d')
			{
				xPosition[length]=xPosition[length-1]-2*radius;
				yPosition[length]=yPosition[length-1];
			}
		}
		if(length>=lmax)
		{
			printf("You Win!\n");
			break;
		}
		//eggFlag=checkVicinity(xegg,yegg,xPosition[0],yPosition[0],radius);
		eggFlag=temp2;
		if(eggFlag==0)
		{
			egg(xegg,yegg);
		}
		else
		{
			xegg=rand()%640;
			yegg=rand()%480;
		}
		for(int i=0;i<10000;i++) //to slow down
		{ 
			for(int j=0;j<1600;j++)
			{

			}
		}
		if(kbhit())
		{
			temp2=getch();
			if(temp=='a' && temp2=='d')
			{
				ch=temp;
			}
			else if(temp=='d' && temp2=='a')
			{
				ch=temp;
			}
			else if(temp=='w' && temp2=='x')
			{
				ch=temp;
			}
			else if(temp=='x' && temp2=='w')
			{
				ch=temp;
			}
			else
			{
				ch=temp2;
			}
			temp=ch;	
		}
		
		cleardevice();
		assignPosition(xPosition,yPosition,length,ch,radius);
		if(xPosition[0]<0 || xPosition[0]>639 || yPosition[0]<0 || yPosition[0]>479)
		{
			printf("Game Over!\n");
			break;
		}
		draw(xPosition,yPosition,length,radius);
	}
	getch();
	closegraph();
}