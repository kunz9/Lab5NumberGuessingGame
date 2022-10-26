/*
 Dakota Kunz
 C++
 Lab 5
 Due: October 28th 2022
 Description: Write a number-guessing game in which the computer selects a random 
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At 
the end of each game, users should be told whether they won or lost, and then be asked 
whether they want to play again. When the user quits, the program should output the 
total number of wins and losses. To make the game more interesting, the program 
should vary the wording of the messages that it outputs for winning, for losing, and for 
asking for another game. Create 10 different messages for each of these cases, and use 
random numbers to choose among them. 
*/

#include <iostream>
using namespace std;
//Precondition:Library Iostream
//Postcondition: Outputs the heading of the game
void heading();

//Precondition:Library iostream, needs functions; wrong, correct, and newgame
// needs stored values in tries, num, playagain, wins, and losses
//Postcondition: Out puts entire game, attains stored value for guess
void game(int tries, int num, int guess, int playagain, int wins, int losses);

//Precondition:Library iostream
//Postcondition: outsuts different wrong statments randomly
void wrong();

//Precondition:Library iostream
//Postcondition: outputs different right statements randomly
void correct();

//Precondition:library iostream
//Postcondition: outputs different new game statements, stored value in playagin 
void newgame(int& playagain, int tries);

int main()
{//initalizes most variable 
	int playagain = 0; int y = 0; int x = 0; int tries = 0; int num = 0; int guess = 0; int wins = 0;
		int losses = 0;
	heading();
	game(tries, num, guess,playagain, wins,losses);
	return 0;
}
void heading()
{
	cout << "Welcome to the Random Number Guessing Game! You will have 20 guesses!"<<endl<<endl;
}
void game(int tries, int num, int guess, int playagain, int wins, int losses) 
{
	srand(time(0));
	num = rand() % 100 + 1;
		do
		{
			cout << "Enter a guess between 1 and 100\n";
			cin >> guess; //captues curent guess
			tries++;
			if (guess != num)
				wrong();
			else
				correct();

			if (tries == 20 || guess==num)
			{
				if (tries == 20)
				{
					losses++;//adds losses to end count
					cout << "You Lost\n";
					newgame(playagain, tries);
					if (playagain == 1)
					{
						tries = 0;
						continue;
					}
				}
				if (guess == num)
				{
					wins++;//adds wins to end count
					cout << " You Won!";
					newgame(playagain, tries);
					if (playagain == 1)
					{
						tries = 0;
						continue;
					}
				}
			}
		} while (playagain != 2);
			cout <<" Your Final Score was\n "<<wins<<" win(s)\n "<<losses<<" loss(es). \n";
}
void wrong()
{//statements if you were wrong and will appear after each wrong guess
	int incorrectstatement;
	incorrectstatement= 1 + (rand() % 10);
	switch (incorrectstatement)
	{
	case 1:
		cout << "Wrong";
		break;
	case 2:
		cout << "Incorrect";
		break;
	case 3:
		cout << "Nope";
		break;
	case 4:
		cout << "Try Again";
		break;
	case 5:
		cout << "Loser";
		break;
	case 6: 
		cout << "L + Ratio";
		break;
	case 7:
		cout << "Nahhhhhhh";
		break;
	case 8:
		cout << "Not Correct";
		break;
	case 9:
		cout << ":(";
		break;
	default:
		cout << "Saldy you've been bamboozled";
		break;
	}
	cout << endl<<endl;
}
void correct()
{//statemetns if you were right and will appear after each right guess
	int correctstatement;
	correctstatement = 1 + (rand() % 10);
	switch (correctstatement)
	{
	case 1:
		cout << "Right";
		break;
	case 2:
		cout << "Correct";
		break;
	case 3:
		cout << "Yep";
		break;
	case 4:
		cout << "Yup";
		break;
	case 5:
		cout << "Winner";
		break;
	case 6:
		cout << "W + Ratio";
		break;
	case 7:
		cout << "Yahhhhhhh";
		break;
	case 8:
		cout << "Not Incorrect";
		break;
	case 9:
		cout << ":)";
		break;
	default:
		cout << "Saldy you haven't been bamboozled";
		break;
	}
	cout << endl<<endl;
}
void newgame(int& playagain,int tries)
{//asks to play again using the number 1 if true and any other number will cancel game
	int again;
	again = 1 + (rand() % 10);
	switch (again)
	{
	case 1:
		cout << "If you hated your experience type 2 to leave but if you wanna stay type 1:";
		cin >> playagain;
			break;
	case 2:
		cout << "Why are you playing if you don't want to play again. Type 1:";
		cin >> playagain;
			break;
	case 3:
		cout << "Type 1 if you had fun and want to have more!:";
		cin >> playagain;
			break;
	case 4:
		cout << "Click 2 if you hate this, Click 1 to love this and paly again:";
		cin >> playagain;
			break;
	case 5:
		cout << "If you don't press 1 to play again I'm dissapointed:";
		cin >> playagain;
			break;
	case 6:
		cout << "Screw it type 1 to play again!:";
		cin >> playagain;
			break;
	case 7:
		cout << "Pick 1 and we can roll this thang back:";
		cin >> playagain;
			break;
	case 8:
		cout << "If you type 1 you'll take this ride again, if anything else you'll be done: ";
		cin >> playagain;
			break;
	case 9:
		cout << "1=play again! 2 = Not again!!! :";
		cin >> playagain;
			break;
	default:
		cout << "If you want to play again enter 1 if you want to give up enter 2:";
		cin >> playagain;
			break;
		}
}