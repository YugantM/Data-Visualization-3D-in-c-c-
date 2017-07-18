#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>

void main()
{
clrscr();
float angle[100][3];
int i,j,data[100][3],temp;

for(i=0;i<100;i++)
{
	for(j=0;j<3;j++)
	{
		label:
		temp=rand()%100;
		if(temp!=0)
		{
			data[i][j]=temp;
			printf("%d ",data[i][j]);
		}
		if(temp==0)
		goto label;
	}
	printf("\n");
}

getch();
int gd=0,gm,x,y,N=100,zoom;
zoom=1;
float t,b;
char ch;
initgraph(&gd,&gm,"");
x=getmaxx();
y=getmaxy();


	for(i=0;i<N;i++)
	{
		for(j=0;j<2;j++)
		{
			//t=asin((data[i][1]/sqrt((data[i][0])*sqrt(data[i][0])+sqrt(data[i][1])*sqrt(data[i][01])))*180/3.14);
			t=data[i][1]/data[i][0];
			b=data[i][2]/data[i][0];
			angle[i][0]=atan(t);
			angle[i][1]=atan(b);
			angle[i][2]=sqrt(data[i][0]*data[i][0]+data[i][1]*data[i][1]);
			//printf("%f %f %f\n",angle[i][0],angle[i][1],angle[i][2]);
		}
	}

int flag=1;
while(1>0)
{

	if(flag==1)
	{
		line(0,y/2,x,y/2);
		line(x/2,0,x/2,y);

	for(j=0;j<N;j++)
	{
	putpixel(x/2+zoom*angle[j][2]*cos(angle[j][0]*3.14/180),y/2-zoom*angle[j][2]*sin(angle[j][0]*3.14/180),3);
	}
		delay(100);
		cleardevice();

	}

	if(flag==0)
	{
		line(0,y/2,x,y/2);
		line(x/2,0,x/2,y);

	for(j=0;j<N;j++)
	{
	putpixel(x/2+zoom*angle[j][2]*cos(angle[j][0]*3.14/180)*cos(angle[j][1]*3.14/180),y/2-zoom*angle[j][2]*sin(angle[j][0]*3.14/180),3);
	}
		delay(100);
		cleardevice();

	}


	if(kbhit())   //checkif a key is pressed
	{
	     ch=getch();

	     if(ch==72)                           //move upward
		{
				for(i=0;i<N;i++)
				angle[i][1]+=5;
				flag=0;
		}
	     if(ch==75)                           //move left
		{
				for(i=0;i<N;i++)
				angle[i][0]-=5;
				flag=1;
		}

	     if(ch==77)                           //move right
		{
				for(i=0;i<N;i++)
				angle[i][0]+=5;
				flag=1;
		}

	     if(ch==80)                           //move downward
		{
				for(i=0;i<N;i++)
				angle[i][1]-=5;
				flag=0;
		}
	     if(ch==97)
		zoom++;
	     if(ch==115)
		zoom--;

		if(ch==27)                           //exit when esc pressed
		 exit(0);
	}
}
}