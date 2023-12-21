#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
	int i,min=0,sec=0,msec=0;
	clrscr();
	printf("Enter seconds = ");
	scanf("%d",&sec);
	printf("Enter minutes = ");
	scanf("%d",&min);
	clrscr();
	textcolor(GREEN);
	if(sec<0||min<0)
		cprintf("Enter valid Time!");
	else
	{
	   while(1)
	     {
		 cprintf("%d : %d : %d",min,sec,msec);
		 delay(17);
		 clrscr();
		 if(min==0&&sec==0&&msec==0)
				break;
		 msec--;
		 if(msec<0)
			{
				sec--;
				msec=59;
			}
		 if(sec<0)
			{
				min--;
				sec=59;
			}

		 if(min<0)
				min=0;
	     }
	     printf("Time's UP");
	     sound(600);
	     delay(300);
	     sound(400);
	     delay(300);
	     sound(200);
	     delay(150);
	     sound(400);
	     delay(300);
	     sound(500);
	     delay(300);
	     nosound();
	 }
	 getch();
}






