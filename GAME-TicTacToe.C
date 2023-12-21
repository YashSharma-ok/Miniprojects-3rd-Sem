			// GAME OF TIC TAC TOE
#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
	int a[9],turn,i,choice,chance=0,p[2],q[2],r[2],s[2],t[2],u[2],v[2],w[2];
	char c[9];
	clrscr();
	// GIVING DISCRIPTION TO PLAYER

	printf("TIC TAC TOE\nPLAYER 1: O\nPLAYER 2: X\n");
	printf("\nPRESS ANY KEY TO PLAY......");
	getch();
	clrscr();
	for(i=0;i<9;i++)
		c[i]=' ';
	while(1)
	{
		//  POINTS SCORE OF PLAYER 1 AND PLAYER 2
		p[0]=0;p[1]=0;
		q[0]=0;q[1]=0;
		r[0]=0;r[1]=0;
		s[0]=0;s[1]=0;
		t[0]=0;t[1]=0;
		u[0]=0;u[1]=0;
		v[0]=0;v[1]=0;
		w[0]=0;w[1]=0;
		chance++;
		//   Checking for MATCH WINNER
		if(chance>4)
			for(i=0;i<chance-1;i++)
			{
				if(i%2==0)
				  {
					if(a[i]==1||a[i]==2||a[i]==3)
					   p[0]++;
					if(a[i]==1||a[i]==4||a[i]==7)
					   q[0]++;
					if(a[i]==1||a[i]==5||a[i]==9)
					   r[0]++;
					if(a[i]==2||a[i]==5||a[i]==8)
					   s[0]++;
					if(a[i]==3||a[i]==6||a[i]==9)
					   t[0]++;
					if(a[i]==3||a[i]==5||a[i]==7)
					   u[0]++;
					if(a[i]==4||a[i]==5||a[i]==6)
					   v[0]++;
					if(a[i]==7||a[i]==8||a[i]==9)
					   w[0]++;
				  }
				else
				  {
					if(a[i]==1||a[i]==2||a[i]==3)
					   p[1]++;
					if(a[i]==1||a[i]==4||a[i]==7)
					   q[1]++;
					if(a[i]==1||a[i]==5||a[i]==9)
					   r[1]++;
					if(a[i]==2||a[i]==5||a[i]==8)
					   s[1]++;
					if(a[i]==3||a[i]==6||a[i]==9)
					   t[1]++;
					if(a[i]==3||a[i]==5||a[i]==7)
					   u[1]++;
					if(a[i]==4||a[i]==5||a[i]==6)
					   v[1]++;
					if(a[i]==7||a[i]==8||a[i]==9)
					   w[1]++;
				  }
			}

		//  DISPLAY THE GAME

		printf("   |   |\n");
		printf(" %c | %c | %c\n",c[0],c[1],c[2]);
		printf("___|___|___\n");
		printf("   |   |\n");
		printf(" %c | %c | %c\n",c[3],c[4],c[5]);
		printf("___|___|___\n");
		printf("   |   |\n");
		printf(" %c | %c | %c\n",c[6],c[7],c[8]);
		printf("   |   |\n");

		// WINNING STATEMENTS
		if(p[0]==3||q[0]==3||r[0]==3||s[0]==3||t[0]==3||u[0]==3||v[0]==3||w[0]==3)
		    {
		       printf("Player 1 Winner\03 \03 \03 \03....\n");
		       break;
		    }
		else if(p[1]==3||q[1]==3||r[1]==3||s[1]==3||t[1]==3||u[1]==3||v[1]==3||w[1]==3)
		    {
		       printf("Player 2 Winner\03 \03 \03 \03....\n");
		       break;
		    }
		if(chance>9)
		    {
			printf("MATCH DRAW.....\n");
			break;
		    }

		//   TAKING A MOVE FOR PLAYER
		turn=(chance%2==0)?2:1;
		printf("Turn: PLAYER %d\nEnter Move:\n1 2 3\n4 5 6\n7 8 9\n",turn);
		while(1)
		   {
			scanf("%d",&choice);

			//   IF MOVE IS VALID, INVALID OR REPEATED
			if( (choice>9) || (choice<1) )
			   {
				printf("Enter valid Move (1-9)...\n");
					continue;
			   }
			for(i=0;i<chance-1;i++)
				if(choice==a[i])
					break;
			if(i==chance-1)
			{

				a[chance-1]=choice;
				break;
			}
			else
				printf("Already entered...try other move..\n");
		   }
		   c[choice-1]=(turn==1)?'O':'X';
		   clrscr();
	}
	// Final results

	printf("\nGAME FINISHED.......");
	getch();
}
