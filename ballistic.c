/*
Name: Rayen Ben Ismail
Date: 2/20/2025
Description: This program is a ballistics calculator
file naming: ballistic.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>


const float g = 9.81;

float t = 0;

void repeat(bool *FPvalidity);
int choicemenu(void);

struct params
{
    float angle;
    float velocity_init;
    float drag_coef;
	float cross_sec;
};

int main(void)
{
	printf("\n---This program calculates the ballistic trajectory of a thrown object---\n");
    bool validity = true;

    do
    {

        repeat(&validity);
    } while (validity);
    return 0;
}


int choicemenu(void) // 0 is launch on flat surface, 1 is over angled surface, 2 is against wall, 3 is exit
{
	struct params param;
	int input;

	printf("Please choose a calculation or exit\n");
	printf("Trajectory over a flat surface    [1]\n");
	printf("Trajectory over an angled surface [2]\n");
	printf("trajectory against a wall         [3]\n");
	printf("Exit                              [0]\n\n");

	bool validity1 = true;
	do
	{
		validity1 = true;
		char* buffer;
		buffer = (char*)malloc(100 * sizeof(char));
		fflush(stdin);
		fgets(buffer, 100, stdin);
		for (int i = 0; i < 2 ; i++)
		{
			if (i == 0 && (buffer[i] != '0' && buffer[i] != '1' && buffer[i] != '2' && buffer[i] != '3'))
			{
				validity1=false;

				printf("Please enter a valid input, press any key to continue\n");
				do 
				{
				} while(!kbhit());
				getch();
				
				printf("\x1b[1F"); // goes to start of previous line
				printf("\x1b[2K"); // clears line
				printf("\x1b[1F"); // goes to start of previous line
				printf("\x1b[2K"); // clears line

				break;
			}
			if (i==1)
			{
				if (buffer[i] != '\n')
				{
					validity1 = false;

					printf("Please enter a valid input, press any key to continue\n");
					do 
					{
					} while(!kbhit());
					getch();
					
					printf("\x1b[1F"); // goes to start of previous line
					printf("\x1b[2K"); // clears line
					printf("\x1b[1F"); // goes to start of previous line
					printf("\x1b[2K"); // clears line
					break;
				}
				break;
			}
		}
		input = (int) buffer[0];
		free(buffer);
	} while (validity1 == false);

	switch (input)
	{
		case 0:
			input = 3;
			break;
		case 1:
			input = 0;
			break;
		case 2:
			input = 1;
			break;
		case 3:
			input = 2;
			break;
	}

	return input;
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