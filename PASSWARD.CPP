#include<stdio.h>
#include<conio.h>
#define ESC 27
		// 27: ASCII value of Esc button
#define BACK 8
		// 8: ASCII value of backspace button
void main()
{
	int i=-1;
	char ch, pass[20];
	clrscr();
	printf("Enter Passward (press ESC to save it) = ");
	while((ch=getch())!=ESC)
	{
		if(ch==BACK)
		  {     i--;
			printf("\b \b");
		  }

		else
		  {
			i++;
			printf("*");
			pass[i]=ch;
		  }
	}
	pass[i+1]='\0';

	printf("\nPassward = [%s]",pass);
	getch();
}