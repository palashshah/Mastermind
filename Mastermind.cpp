#include <iostream.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
#include <dos.h>

int randnum();
void display(int number[]);
int check_number(int number[], int guess_number[]);
int check_position(int number[], int guess_number[]);


int randnum()
{
    int num, d[1000], i=0, count1;

    for(; ;)
    {
		num = (rand() % 6) + 1;
		if(d[num]!=5)
		{
		    d[num]=5;
		    return num;
		}
    }
}

void display(int number[])
{
    for(int i=0 ; i<4 ; i++)
		cout<< number[i];
}

int check_number(int number[], int guess_number[])		//Check no. of correct numbers
{
    int count1=0;
    for(int i=0 ; i<4 ; i++)
    {
		for(int j=0 ; j<4; j++)
		{
		    if(guess_number[j]==number[j])		//Ignore numbers with correct positions
			continue;

		    if(guess_number[i]==number[j])
			count1++;
		}
    }
    return count1;
}

int check_position(int number[], int guess_number[])		//Check no. of correct positions
{
    int count2=0;
    for(int i=0 ; i<4 ; i++)
    {
		if(number[i]==guess_number[i])
		    count2++;
    }
    return count2;
}
int main()
{  // textbackground(WHITE);
   // textcolor(RED);
    int number[4], guess_number[4], i, j, rem, guess, correct_position,life=10;
    char choice1, choice2,x,z;
    do
    {
		unsigned int seedval;
		time_t t;
		seedval= (unsigned) time (&t);	//time(&t) will initialise time variable 't' with system time
		srand(seedval);		//seed the random no. generator

	    {b:	clrscr();
			cout<<"\n\t\t\t******************************"<<"\n\t\t\t******************************";
			cout<<"\n\t\t\t**                          **"<<"\n\t\t\t**   WELCOME TO MASTERMIND  **"<<"\n\t\t\t**                          **"<<"\n\t\t\t******************************";
			cout<<"\n\t\t\t******************************";
			cout<<"\n\n\nGAME MENU: ";
			cout<<"\n\n\n1.NEW GAME";
			cout<<"\n\n2.RULES";
			cout<<"\n\n3.CREDITS";
			cout<<"\n\n4.EXIT";
			cout<<"\n\n\nEnter your choice: ";
			cin >> choice1;
		}
		if(choice1=='1')		//Start the Game
		{
			clrscr();
			goto a;
		}
		if(choice1=='2')		//Rules and then start the Game
		{
			clrscr();
			cout<<"============================RULES================================";
			cout<<"\n\n==>Computer Will Generate A 4 Digit Number (Without Repetition)." ;
			cout<<"\n==>You Will Get 10 Chances To Guess That Number. ";
			cout<<"\n==>After Every Guess Computer Will Inform You About Your Progress.\n\n";
			cout<<"\n\n==>Press * to Play : ";
			cin>>x;
			if(x=='*')
			{
				clrscr();
				goto a;
			}
		}
		else if(choice1=='3')		//Credits
		{
			clrscr();
			cout<<"==============================CREDITS=====================================";
			cout<<"\n\n==>Developed by PALASH AND DHRUV";
			cout<<"\n\n==>Game made in Turbo C++";
			cout<<"\n\n==>Comments From Users Will Be Highly Appreciated.";
			cout<<"\n\n\nPress a to continue : ";
			cin>>z;
			if(z=='a')
				goto b;
		}
		else if(choice1=='4')		//Exit
			exit (0);

		switch(choice1)
		{
			a:	case '1':		//Main Start of Game
			
			for(int l=0;l<=100;l+=20)
			{
				cout<<"Generating......."<<l<<"%\r";		//\r is Carriage Return to move the cursor to begining of the line
				sleep(1);
			}
		    for(i=0 ; i<4 ; i++)		//Generate random 4-digit number
				number[i] = randnum();

		    while(correct_position!=4 && life>0)
		    {
				cout<<"\n\n----------------------------------------------------------";
				cout<<"\nNumber of guess left: " << life;
				cout<<"\nEnter your guess: ";
				cin>>guess;

				j=3;
				while(guess)
				{
				    rem = guess % 10;
				    guess_number[j] = rem;
				    guess = guess / 10;
				    j--;
				}

				cout<<"\n";
				cout<<check_number(number, guess_number) <<" number correct, ";
				cout<<"   " << check_position(number, guess_number) <<" position correct. ";
				correct_position = check_position(number, guess_number);
				life--;
		    }


		    if(correct_position==4)
				cout<<"\n\nYou are a mastermind! YOU WIN!";

		    else
		    {
				cout<<"\n\nYOU LOSE. Better luck next time";
				cout<<"\nThe correct number is: ";
				display(number);
		    }

		    correct_position = 0;
		    life = 10;
		    cout<<"\n\n\n\n\t\t\t    @@@@@@@@ THANK YOU @@@@@@@@   \n\n";
			cout<<"================================================================================";

			// cout<<"\a\a\n\n\t\t\t\t Special Thanks To PALASH AND DHRUV ";
		    cout<<"\n\nBack to Main Menu? (Y/N)";
		    cin>>choice2;
		}

    }while(choice2=='y' || choice2=='Y');

    getch();
    return 0;
}