#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
void main()
{
	int i=17,j=16,gd=DETECT,gm;
	char key='d';
	clrscr();
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	textcolor(GREEN);
	cprintf("Press P to exit...");
	delay(1500);
	clrscr();
	while(1)
	{
		gotoxy(i,j);
		setfillstyle(SOLID_FILL,8);

/* player*/	pieslice(i,j,20,340,10);

		if(key=='w'&& j>22)
			pieslice(i,j,110,430,10);
		else if(key=='s'&& j<385)
			pieslice(i,j,290,610,10);
		else if(key=='a'&& i>20)
			pieslice(i,j,20,340,10);
		else if(key=='d'&& i<627)
			pieslice(i,j,20,340,10);
		key=getch();
		if(key=='w'&& j>22)
			j=j-5;
		else if(key=='s'&& j<385)
			j=j+5;
		else if(key=='a'&& i>20)
			i=i-5;
		else if(key=='d'&& i<627)
			i=i+5;
		else if(key=='p')
			exit(1);
		clrscr();
	}
}