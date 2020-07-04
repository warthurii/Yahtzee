//You should be able to read this
#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <Windows.h>
using namespace std;

class Die
{
public:
	int number;
	Die()
	{
		number = rand() % 6 + 1;
	}
};

class Dice
{
public:
	int DieArray[5];
	Dice()
	{
		Die *pDie1 = new Die;
		Die *pDie2 = new Die;
		Die *pDie3 = new Die;
		Die *pDie4 = new Die;
		Die *pDie5 = new Die;
		DieArray[0] = pDie1->number;
		DieArray[1] = pDie2->number;
		DieArray[2] = pDie3->number;
		DieArray[3] = pDie4->number;
		DieArray[4] = pDie5->number;
	}

};

class ScoreCard
{
public:
	string categories[14] = { "Aces","Twos","Threes","Fours","Fives","Sixes","3 of a Kind","4 of a Kind","Full House","Sm Straight","Large Straight","YAHTZEE","Chance","Total" };
	//Bonus and total still need implemented
	int scores[14] = { -1,-1,-1,-1,-1,
					  -1,-1,-1,-1,-1,
					  -1,-1,-1, 0 }; //initialize all scores to zero
	void changeScore(ScoreCard* pScoreCard, int cat, int inputScore)
	{
		pScoreCard->scores[cat] = inputScore;
	}//allows passing of the this object to allow for void return 
	void printCard()
	{
		cout << "Here is your Score Card: " << endl;
		for (int i = 0; i < 14; i++) //iterate through the categories and scores and display to the player. 
		{
			cout << categories[i];
			cout << ": ";
			cout << scores[i];
			cout << endl;
		}
		cout << endl;
	}
	ScoreCard()
	{

	}
};

class Game
{
public:
	ScoreCard myScoreCard;
	Game()
	{

	}//default constructor 

	void play()
	{
		int total = 0;
		int choice, num = 0, num2 = 0, count = 0, count2 = 0;
		cout << "***Welcome to Yahtzee!***" << endl;
		cout << "*********Rules***********" << endl;
		cout << "1. You get 13 rolls, one for each category" << endl;
		cout << "2. After each roll you will see your score card" << endl;
		cout << "3. DO NOT select a category more than once" << endl;
		cout << "4. Unused categories will show a score of negative 1" << endl;
		cout << "5. HAVE FUN!!!" << endl;

		int counter = 0;
		do
		{
			Dice myRoll; //a new set of 5 dice
			cout << "Press the enter key to roll!" << endl;
			if (counter > 0)
				cin.get();
			cin.get();
			cout << "Yay! You rolled the following:" << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << myRoll.DieArray[i];
			}
			cout << endl;
			cout << endl;
			cout << "Please Select a scoring category" << endl;

			cout << "1 - Aces" << endl;
			cout << "2 - Twos" << endl;
			cout << "3 - Threes" << endl;
			cout << "4 - Fours" << endl;
			cout << "5 - Fives" << endl;
			cout << "6 - Sixes" << endl;
			cout << "7 - Three of a Kind" << endl;
			cout << "8 - Four of a Kind" << endl;
			cout << "9 - Full House" << endl;
			cout << "10 - Small Straight" << endl;
			cout << "11 - Large Straight" << endl;
			cout << "12 - YAHTZEE" << endl;
			cout << "13 - Chance" << endl;


			cin >> choice;

			switch (choice)
			{
			case 1:
				// "Aces" Category
			{
				int temp1 = 0;
				for (int j = 0; j < 5; j++)
				{
					if (myRoll.DieArray[j] == 1)
						temp1++;
				}
				myScoreCard.changeScore(&myScoreCard, 0, temp1);
				total += temp1;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 2:
				// "Twos" Category
			{
				int temp2 = 0;
				for (int j = 0; j < 5; j++)
				{
					if (myRoll.DieArray[j] == 2)
						temp2 += myRoll.DieArray[j];
				}
				myScoreCard.changeScore(&myScoreCard, 1, temp2);
				total += temp2;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 3:
				// "Threes" Category
			{
				int temp3 = 0;
				for (int j = 0; j < 5; j++)
				{
					if (myRoll.DieArray[j] == 3)
						temp3 += myRoll.DieArray[j];
				}
				myScoreCard.changeScore(&myScoreCard, 2, temp3);
				total += temp3;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 4:
				// "Fours" Category
			{
				int temp4 = 0;
				for (int j = 0; j < 5; j++)
				{
					if (myRoll.DieArray[j] == 4)
						temp4 += myRoll.DieArray[j];
				}
				myScoreCard.changeScore(&myScoreCard, 3, temp4);
				total += temp4;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 5:
				// "Fives" Category
			{
				int temp5 = 0;
				for (int j = 0; j < 5; j++)
				{
					if (myRoll.DieArray[j] == 5)
						temp5 += myRoll.DieArray[j];
				}
				myScoreCard.changeScore(&myScoreCard, 4, temp5);
				total += temp5;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 6:
			{
				// "Sixes" Category
				int temp6 = 0;
				for (int j = 0; j < 5; j++)
				{
					if (myRoll.DieArray[j] == 6)
						temp6 += myRoll.DieArray[j];
				}
				myScoreCard.changeScore(&myScoreCard, 5, temp6);
				total += temp6;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			
			case 7:
			{
				// "Three of a Kind" Category
				int temp8;
				cout << "What number do you have three of?" << endl;
				cin >> num;

				count = 0;

				for (int i = 0; i < 5; i++)
				{
					if (myRoll.DieArray[i] == num)
						count++;
				}

				if (count >= 3)
					temp8 = myRoll.DieArray[0] + myRoll.DieArray[1] + myRoll.DieArray[2] + myRoll.DieArray[3] + myRoll.DieArray[4];
				else
					temp8 = 0;
				myScoreCard.changeScore(&myScoreCard, 6, temp8);
				total += temp8;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 8:
			{
				// "Four of a Kind" Category
				int temp9 = 0;
				cout << "What number do you have four of?" << endl;
				cin >> num;

				count = 0;

				for (int i = 0; i < 5; i++)
				{
					if (myRoll.DieArray[i] == num)
						count++;
				}

				if (count >= 4)
					temp9 = myRoll.DieArray[0] + myRoll.DieArray[1] + myRoll.DieArray[2] + myRoll.DieArray[3] + myRoll.DieArray[4];
				else
					temp9 = 0;
				myScoreCard.changeScore(&myScoreCard, 7, temp9);
				total += temp9;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 9:
				// "Full House" Category
			{
				int num1;
				int num2;
				int temp10;
				int count = 0;
				int count2 = 0;
				cout << "What number do you have 2 of?" << endl;
				cin >> num1;
				cout << "What number do you have 3 of" << endl;
				cin >> num2;

				for (int i = 0; i < 5; i++)
				{
					if (myRoll.DieArray[i] == num1)
						count++;
					else if (myRoll.DieArray[i] == num2)
						count2++;
				}

				if (count == 2 && count2 == 3)
					temp10 = 25;
				else
					temp10 = 0;

				myScoreCard.changeScore(&myScoreCard, 8, temp10);
				total += temp10;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 10:
				// "Small Straight" Category
			{
				bool smallSt = false;
				for (int i = 0; i < 5; i++)
				{
					if (myRoll.DieArray[i] == 1)
						for (int i = 0; i < 5; i++)
							if (myRoll.DieArray[i] == 2)
								for (int i = 0; i < 5; i++)
									if (myRoll.DieArray[i] == 3)
										for (int i = 0; i < 5; i++)
											if (myRoll.DieArray[i] == 4)
												smallSt = true;
											else if (myRoll.DieArray[i] == 2)
												for (int i = 0; i < 5; i++)
													if (myRoll.DieArray[i] == 3)
														for (int i = 0; i < 5; i++)
															if (myRoll.DieArray[i] == 4)
																for (int i = 0; i < 5; i++)
																	if (myRoll.DieArray[i] == 5)
																		smallSt = true;
				}
				int score = 0;
				if (smallSt == true)
					score = 30;
				myScoreCard.changeScore(&myScoreCard, 9, score);
				total += score;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 11:
			{
				// Large Straight 
				bool largeSt = false;
				for (int i = 0; i < 5; i++)
				{
					if (myRoll.DieArray[i] == 1)
						for (int i = 0; i < 5; i++)
							if (myRoll.DieArray[i] == 2)
								for (int i = 0; i < 5; i++)
									if (myRoll.DieArray[i] == 3)
										for (int i = 0; i < 5; i++)
											if (myRoll.DieArray[i] == 4)
												for (int i = 0; i < 5; i++)
													if (myRoll.DieArray[i] == 5)
														largeSt = true;

				}
				int score = 0;
				if (largeSt == true)
					score = 40;
				myScoreCard.changeScore(&myScoreCard, 10, score);
				total += score;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 12:
			{
				// "YAHTZEE" Category
				int Y = myRoll.DieArray[0];
				int score = 0;
				if (myRoll.DieArray[1] == Y && myRoll.DieArray[2] == Y && myRoll.DieArray[3] == Y && myRoll.DieArray[4] == Y)
					score = 50;
				myScoreCard.changeScore(&myScoreCard, 11, score);
				total += score;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
			}
			break;
			case 13:
				// "Chance" Category
				int temp14 = myRoll.DieArray[0] + myRoll.DieArray[1] + myRoll.DieArray[2] + myRoll.DieArray[3] + myRoll.DieArray[4];
				myScoreCard.changeScore(&myScoreCard, 12, temp14);
				total += temp14;
				myScoreCard.changeScore(&myScoreCard, 13, total);
				myScoreCard.printCard();
				break;
			}
			counter++;
		} while (counter < 13);

		cout << "Thanks for playing" << endl;
		cout << "Your final score was: ";
		cout << myScoreCard.scores[13] << endl;
		cout << "See you next time!" << endl;
	}

};

int main()
{
	srand(time(NULL));

	Game myGame;

	myGame.play();

	return 0;
}