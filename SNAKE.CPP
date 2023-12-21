				//YASH RAJ GAMES
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
void check(int*,int*,int);     // (x), (y), length of snake
int menu();                       //  print menu and return level
int level();
void main()
{
	int key=77,x[100],k,y[30],pre_n=3,post_n=3,food_x=0,food_y=0,level;
	char post,pre='d';
     // MENU choice
	level=menu();
	for(k=0;k<3;k++)
	{
		x[k]=k+2;
		y[k]=2;
	}
	while( (food_x<=1) || (food_y<=1) )
	{
		food_x=rand()%80;
		food_y=rand()%25;
	}                                           //    77 -> RIGHT
	clrscr();
	while(1)
	{
		clrscr();
	//BOUNDRY
		textcolor(WHITE);
		for(k=0;k<=79;k++)
			cprintf("_");
		gotoxy(1,24);
		for(k=0;k<=79;k++)
			cprintf("_");
	//FOOD
		gotoxy(food_x,food_y);
		textcolor(RED);
		cprintf("%c",162);
	//SNAKE printed
		textcolor(YELLOW);
		for(k=0;k<post_n;k++)
		  {
			gotoxy(x[k],y[k]);
			if(k==post_n-1)      // post_n-1  -> HEAD of snake
			{
				textcolor(CYAN);
				cprintf("%c",148);
			}
			else
				cprintf("o",147);
		  }
	//Eated itself or not..
		check(&x[0],&y[0],post_n);
	//SCORE
		gotoxy(35,25);
		textcolor(WHITE);
		cprintf("%c SCORE: %d %c\b",219,(post_n-3)*5,219);
     //LEVEL
		if(level==1)
     /*EASY*/		delay(150);
		else if(level==2)
     /*MEDIUM*/		delay(110);
		else
     /*HARD*/		delay(60);
		if(kbhit())        //TAKING KEYS(ARROW)
		   {
			post=getch();          // post-> next key pressed
			if(post==0)
				post=getch();
			pre=key;               // pre-> last key pressed
			if((post==75&&pre!=77)||(post==80&&pre!=72)||
			    (post==77&&pre!=75)||(post==72&&pre!=80) )
			     {
				key=post;
			     }
		   }
		if(post==13)   // CHECKING IF "ENTER" IS PRESSED
		    {
			gotoxy(34,11);
			textcolor(RED);
			cprintf("GAME PAUSE %c %c\b",219,219);
			textcolor(GREEN);
			if(getch()!=13)
				exit(0);
			post=1;
		    }
	//MOVEMENT OF BODY according to and except HEAD
		if(pre_n==post_n)
			{
				for(k=0;k<post_n-1;k++)
				{
					y[k]=y[k+1];
					x[k]=x[k+1];
				}
			}
	//CHECKING ARROW AND MOVE HEAD ACCORDINGLY
		if(key==72)
		      {

				y[post_n-1]=(y[pre_n-1]>2)?(y[pre_n-1]-1):(24);
				if(post_n!=pre_n)
				{
					x[post_n-1]=x[pre_n-1];
					pre_n=post_n;
				}
		      }
		else if(key==80)
		      {
				y[post_n-1]=(y[pre_n-1]<24)?(y[pre_n-1]+1):(2);
				if(post_n!=pre_n)
				{
					x[post_n-1]=x[pre_n-1];
					pre_n=post_n;
				}
		      }
		else if(key==75)
		      {
				x[post_n-1]=(x[pre_n-1]>2)?(x[pre_n-1]-1):(79);
				if(post_n!=pre_n)
				{
					y[post_n-1]=y[pre_n-1];
					pre_n=post_n;
				}
		      }
		else if(key==77)
		      {
				x[post_n-1]=(x[pre_n-1]<79)?(x[pre_n-1]+1):(2);
				if(post_n!=pre_n)
				{
					y[post_n-1]=y[pre_n-1];
					pre_n=post_n;
				}
		      }
	//Eated food or not
		if( (food_x==x[post_n-1]) && (food_y==y[post_n-1]) )
		  {
			post_n++;
			y[post_n-1]=y[post_n-2];
			x[post_n-1]=x[post_n-2];
			food_x=rand()%80;
			food_y=rand()%25;
			while( (food_x<=1) || (food_y<=1) )
			{
				food_x=rand()%80;
				food_y=rand()%25;
			}
		  }
	}
}
// function for checking Eaten itself or not
void check(int *x, int *y, int n)
{
	int i;
	for(i=0;i<n-3;i++)
	{
	       if( *(x+n-1)== *(x+i) && *(y+n-1)== *(y+i) )
		  {
			gotoxy(35,12);
			textcolor(RED);
			cprintf("GAME_OVER  Score: %d",(n-3)*5);
			gotoxy(39,12);
			getch();
			exit(0);
		  }
	}
}

// menu of game
int menu()
{
	int i,k=1,ch=1,lev=1;
	char m[4][11]={"START GAME","LEVEL","HELP","EXIT"};
	clrscr();
	while(1)
	 {
		delay(100);
		clrscr();
		textcolor(GREEN);
		gotoxy(35,8);
		cprintf("SNAKE GAME");
		textcolor(RED);
		for(i=0;i<4;i++)     //    MENU
		{
		   if(k==i+1)
			textbackground(WHITE);
		   gotoxy(35,10+i);
		   cprintf("%c %s",219,m[i]);
		   textbackground(BLACK);
		   printf("\n");
		   ch=1;
		}
		if(kbhit())                            //  KEYS PRESSED
		{
			ch=getch();
			if(ch==0)
				ch=getch();
		}
		switch (ch)
		{
			case 80:
				if(k!=4)
					k++;
				break;
			case 72:
				if(k!=1)
					k--;
				break;
		}
		if(ch==13)
		{
		       if(k==4)
				exit(0);
		       else if(k==2)
				lev=level();
		       else if(k==3)
		       {
			     clrscr();
			     textcolor(WHITE);
			     cprintf("1. Use Arrow Keys to control Snake");
			     printf("\n");
			     cprintf("2. Eat FRIUT to increase size");
			     printf("\n");
			     cprintf("3. One fruit = 5 points");
			     printf("\n");
			     cprintf("4. Press 'ENTER' to pause game");
			     printf("\nCREATOR: YASH SHARMA...\nHope you will like it");
			     getch();
		       }
		       else if(k==1)
				break;
		}
		gotoxy(35,12);
	 }
	 return lev;
}

int level()
{
	int i,k=1,ch=1;
	char m[3][11]={"EASY","MEDIUM","HARD"};
	clrscr();
	while(1)
	 {
		delay(100);
		clrscr();
		textcolor(RED);
		for(i=0;i<3;i++)     //    MENU
		{
		   if(k==i+1)
			textbackground(WHITE);
		   gotoxy(35,10+i);
		   cprintf("%c %s",219,m[i]);
		   textbackground(BLACK);
		   printf("\n");
		   ch=1;
		}
		if(kbhit())                            //  KEYS PRESSED
		{
			ch=getch();
			if(ch==0)
				ch=getch();
		}
		switch (ch)
		{
			case 80:
				if(k!=3)
					k++;
				break;
			case 72:
				if(k!=1)
					k--;
				break;
		}
		if(ch==13)
			break;
		gotoxy(35,12);
	 }
	 return k;
}