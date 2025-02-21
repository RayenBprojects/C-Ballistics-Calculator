#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>



const float g = 9.81;


void repeat(bool *FPvalidity);

struct params
{
    float angle;
    float velocity_init;
    float drag_coef;
};

int main()
{
    bool validity = true;

    do
    {
		printf("\nDEBUGDEBUG\n");
        repeat(&validity);
    } while (validity);
    return 0;
}


void repeat(bool *FPvalidity)
{
	
	bool validity = true;
	
	do
	{
		printf("\nRepeat? [y][n]: ");
	
		char buffer[100];
		int bufferlength;
		char input[2];
		fflush(stdin);
		fgets(buffer, 100 , stdin);
		//scanf("%c", &input);
		
		int n = 0;
		for (int i = 0 ; i < 100 ; i++)
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
				bufferlength = i + 1;
				break;
			}
		}
		
		if (bufferlength != 2)// || tolower(buffer[0]) != 'y' || tolower(buffer[0]) != 'n')
		{
			validity = false;
			
			printf("Please enter 'y' to restart or 'n' to terminate, press any key to continue");
			
			do 
			{
			} while(!kbhit());
			getch();
			
			printf("\x1b[2K"); // clears line
			printf("\x1b[1F"); // goes to start of previous line
			printf("\x1b[2K"); // clears line
			printf("\x1b[1F"); // goes to start of previous line
		}
		else if (tolower(buffer[0]) == 'y')
		{
			validity = true;
			*FPvalidity = true;
		}
		else if (tolower(buffer[0]) == 'n')
		{
			validity = true;
			*FPvalidity = false;
		}
		else
		{
			validity = false;
			
			printf("Please enter 'y' to restart or 'n' to terminate, press any key to continue");
			
			do 
			{
			} while(!kbhit());
			getch();
			
			printf("\x1b[2K"); // clears line
			printf("\x1b[1F"); // goes to start of previous line
			printf("\x1b[2K"); // clears line
			printf("\x1b[1F"); // goes to start of previous line
		}
	} while (validity == false);
}