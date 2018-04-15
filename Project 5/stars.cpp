#define _CRT_SECURE_NO_DEPRECATE

#include "utilities.h"
#include <iostream>
#include <cstring>

using namespace std;

const char WORDFILENAME[] = "C:/Users/fax21/Desktop/CS 31/Projects/Project 5/smallwords.txt";
const int MAXWORDS = 10000;
//const int MAXWORDLEN = 6;

int main()
{
	bool a = false;
	int numOfCharsInWord = 0;
	int numOfRounds = 0;
	int numOfRoundsPlaceHold = 1;
	int nWords = 0;
	int stars = 0;
	int planets = 0;
	int i;
	int n;
	char wordList[MAXWORDS][MAXWORDLEN + 1];
	char probeWord[MAXWORDS];

	cout << "How many rounds do you want to play? ";
	cin >> numOfRounds;
	cin.ignore(10000, '\n');

	if (numOfRounds <= 0)
	{
		cout << "The number of rounds must be positive."; // Ask if I did the precede by an empty line part correctly?
	}
	else
	{
		nWords = getWords(wordList, 10000, WORDFILENAME);
		if (nWords < 1) //DOES THE GETWORDS FUNCTION AUTOMATICALLY MAKES SURE THE GETWORDS FUNCTION's RETURN VALUE IS NOT GREATER THAN maxWords???
		{
			cout << "No words were loaded, so I can't play the game."; //Why does this print out text when maxWords is 0???
		}
		else
		{
			n = randInt(0, 1);
			cout << "Round " << numOfRoundsPlaceHold << endl;
			numOfCharsInWord = strlen(wordList[n]);
			cout << "The secret word is " << numOfCharsInWord << " letters long." << endl;
			cout << wordList[n] << endl;
			while (numOfRoundsPlaceHold <= numOfRounds)
			{
				cout << "Probe word: ";
				cin >> probeWord;
				/*for (int k = 0; k < strlen(probeWord); k++)
				{
					if (wordList[n][k] == probeWord[k])
					{
						stars++;
					}
					else
					{
						continue;
					}
				}*/
				for (int j = 0; j < strlen(probeWord); j++)
				{
					for (int k = 0; k < strlen(wordList[n]); k++)
					{
						if (wordList[n][k] == probeWord[j])
						{
							if (wordList[n][j] == probeWord[j])
							{
								stars++;
							}
							else
							{
								planets++;
							}
						}
						else
						{
							continue;
						}
					}
				}
				numOfRoundsPlaceHold++;
				if (stars == strlen(wordList[n]))
				{
					a = true;
					break;
				}
				cout << "Stars: " << stars << " Planets: " << planets << endl;
				
				if (a == true) //ADD THE AVERAGE, MINIMUM, AND MAXIMUM!!! //FIX THE OUTPUT SO THAT THE OUTPUT DOES NOT STOP AT numOfRoundsPlaceHold
				{
					if (numOfRoundsPlaceHold == 1)
					{
						cout << "You got it in " << numOfRoundsPlaceHold << " try.";
					}
					else
					{
						cout << "You got it in " << numOfRoundsPlaceHold << " tries.";
					}
				}
			}
		}
	}
} 





