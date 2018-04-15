#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//My Constant Global Variables
const char noBeats = ' ';
const char beatEnding = '/';

//Test to see if song's syntax is valid.
bool hasCorrectSyntax(string song)
{
	
	if (song.empty())
	{
		return true;
	}
	if (song[song.size() - 1] != beatEnding)
	{
		return false;
	}
	for (int k = 0; k < (song.size()); k++)
	{
		if (song[k] == beatEnding) {
			continue;
		}
		if (!(song[k] >= 'A' && song[k] <= 'G')) {
			return false;
		}
		
		if(song[k + 1] == '#' || song[k+1] == 'b')
		{
			k++;
			if (song[k + 1] >= '0' && song[k + 1] <= '9')
			{
				k++;
			}
		}
		else if (song[k + 1] >= '0' && song[k + 1] <= '9')
		{
			k++;
		}
		
	}
	return true;
}

// Given an octave number, a note letter, and an accidental sign, return
// the character that the indicated note is encoded as if it is playable.
// Return a space character if it is not playable.
//
// First parameter:   the octave number (the integer 4 is the number of the
//                    octave that starts with middle C, for example).
// Second parameter:  an upper case note letter, 'A' through 'G'
// Third parameter:   '#', 'b', or ' ' (meaning no accidental sign)
//
// Examples:  encodeNote(4, 'A', ' ') returns 'Q'
//            encodeNote(4, 'A', '#') returns '%'
//            encodeNote(4, 'H', ' ') returns ' '

//Encoding each character in the song string
char encodeNote(int octave, char noteLetter, char accidentalSign)
{
	// This check is here solely to report a common CS 31 student error.
	if (octave > 9)
	{
		cerr << "********** encodeNote was called with first argument = "
			<< octave << endl;
	}

	// Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
	//      to -1, 0,   1,   2,   3, ...,  11, 12

	int note;
	switch (noteLetter)
	{
	case 'C':  note = 0; break;
	case 'D':  note = 2; break;
	case 'E':  note = 4; break;
	case 'F':  note = 5; break;
	case 'G':  note = 7; break;
	case 'A':  note = 9; break;
	case 'B':  note = 11; break;
	default:   return ' ';
	}
	switch (accidentalSign)
	{
	case '#':  note++; break;
	case 'b':  note--; break;
	case ' ':  break;
	default:   return ' ';
	}

	// Convert ..., A#1, B1, C2, C#2, D2, ... to
	//         ..., -2,  -1, 0,   1,  2, ...

	int sequenceNumber = 12 * (octave - 2) + note;

	string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
	if (sequenceNumber < 0 || sequenceNumber >= keymap.size())
		return ' ';
	return keymap[sequenceNumber];
}

//Encoding the original song string.
int encodeSong(string song, string& instructions, int& badBeat)
{
	string myInstructions;
	bool playableNote;
	int octave = 4;
	char noteLetter;
	char accidentalSign = ' ';
	if (hasCorrectSyntax(song) == true)
	{
		for (int i = 0; i < song.size(); i++)
		{

			/*if (song[i] == 'C' && song[i + 1] == 'b' && song[i + 2] == '2') //Ask if this is ok
			{
				playableNote = false;
				return 8;
				break;

			}*/

			if ((song[i] == 'B' && song[i + 1] == '#' && song[i + 2] == '1')) //Ask if this is ok
			{
				playableNote = true;
				//return 7; // GET RID OF THE RETURN STATEMENTS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			}
			if ((song[i] == 'C' && song[i + 1] == 'b' && song[i + 2] == '6'))
			{
				playableNote = true;
				//return 4;
			}
			if ((song[i] == 'C' && song[i + 1] == '6'))
			{
				playableNote = true;
				//return 15;
			}
			if (isdigit(song[i]))
			{
				if ((song[i] == '2' || song[i] == '3' || song[i] == '4' || song[i] == '5'))
				{
					if ((song[i + 1] >= 'A' && song[i + 1] <= 'G') || (song[i + 1] == '/'))
					{
						playableNote = true;
						//return 2;
					}
				}
				else
				{
					playableNote = false;
					//return 3;
				}
			}
			else //This means if it does not have a digit
			{
				playableNote = true;
				//return 11;
			}
		}
		if (song == "")
		{
			playableNote = true;
		}



		if (playableNote == true)
		{
			for (int x = 0; x < song.size(); x++)
			{
				if (song[x] >= 'A' && song[x] <= 'G')
				{
					if (song[x + 1] >= 'A' && song[x + 1] <= 'G')
					{
						myInstructions += '[';
					}
					if (song[x + 1] == '#' || song[x + 1] == 'b')
					{
						accidentalSign = song[x + 1];
						if (song[x + 2] == '/' && song[x + 3] == '/')
						{
							myInstructions += encodeNote(octave, song[x], accidentalSign);
							myInstructions += ' ';
							myInstructions += ' ';


						}
						else if (song[x + 2] >= '0' && song[x + 2] <= '9')
						{
							octave = (song[x + 2] - '0');
							if (song[x + 3] == '/' && song[x + 4] == '/')
							{
								myInstructions += encodeNote(octave, song[x], accidentalSign);
								myInstructions += ' ';
								myInstructions += ' ';
								x+=3;
							}
							else
							{
								myInstructions += encodeNote(octave, song[x], accidentalSign);
							}
						}
						else
						{
							myInstructions += encodeNote(octave, song[x], accidentalSign);
						}
					}
					else if (song[x + 1] >= '0' && song[x + 1] <= '9')
					{
						octave = (song[x + 1] - '0');
						if (song[x + 2] == '/' && song[x + 3] == '/')
						{
							myInstructions += encodeNote(octave, song[x], accidentalSign);
							myInstructions += ' ';
							myInstructions += ' ';
							x += 3;
							
						}
						else
						{
							myInstructions += encodeNote(octave, song[x], accidentalSign);
						}
					}
					else if (song[x + 1] == '/' && song[x + 2] == '/')
					{
						myInstructions += encodeNote(octave, song[x], accidentalSign);
						myInstructions += ' ';
						myInstructions += ' ';
						
					}
					else
					{
						myInstructions += encodeNote(octave, song[x], accidentalSign);
					}

				}
				if (song[x] == '/' && song[x + 1] == '/')
				{
					myInstructions += ' ';
					myInstructions += ' ';
					
				}
			}
		}
		instructions = myInstructions;
		return 0;
	}
		if (playableNote = false) //song is a song string but is not playable
		{
			return 2;
		}
	else //if song is not a song string
	{
		return 1;
	}
}

//The main function used to test my functions
int main()
{
	string song;
	string instructions;
	int badBeat;
	int octave;
	char noteLetter;
	char accidentalSign;

	getline(cin, song);
	if (hasCorrectSyntax(song) == true)
	{
		
			encodeSong(song, instructions, badBeat);
			cerr << instructions;
	}
}
