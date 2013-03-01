//new start using new algo to move snake !st March 2013

//19:40 Things done here : Perfect step by step movement of snake.
	 // Also not if snake is moving left, it can't move right and if right i/p is pressed it will continue moving left
	 //same for up and down

#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

#define lmax 10

void assignPosition(int x[],int y[],int length,char ch,int radius)
{	
	/*int xend=x[length-1],yend=y[length-1];
	for(int i=length-1;i>=1;i--)
	{
		x[i]=x[i-1];
		y[i]=y[i-1];
	}
	if(ch=='a')
	{
		x[0]=x[1]-2*radius;
		y[0]=y[1];
	}
	else if(ch=='d')
	{
		//x[0]=x[length-1]+2*radius;
		x[0]=xend;
		y[0]=yend;	
	}
	else if(ch=='w')
	{
		x[0]=x[1]
	}*/
	if(ch=='a')
	{
		/*x[length-1]=x[0]-2*radius;
		y[length-1]=y[0];
		printf("champu");*/
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
		/*x[0]=x[length-1]+2*radius;
		y[0]=y[length-1];*/
		/*for(int i=0;i<=length-2;i++)
		{
			x[i]=x[i+1];
			y[i]=y[i+1];
		}
		x[length-1]=x[length-1]+2*radius;
		y[length-1]=y[length-1];*/
		for(int i=length-1;i>=1;i--)
		{
			x[i]=x[i-1];
			y[i]=y[i-1];
		}
		x[0]=x[0]+2*radius;
	}
	else if(ch=='w')
	{
		/*x[length-1]=x[0];
		y[length-1]=y[0]-2*radius;*/
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
		/*x[length-1]=x[0];
		y[length-1]=y[0]+2*radius;*/
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
		circle(x[i],y[i],radius);
	}
}

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	char ch='a';
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
	while(ch!='p')
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
		cleardevice();
		assignPosition(xPosition,yPosition,length,ch,radius);
		draw(xPosition,yPosition,length,radius);
		/*for(i=0;i<length;i++)
		{
			printf("%d %d for %d \n ",xPosition[i],yPosition[i],i+1);
		}*/
	}
	getch();
	closegraph();
}