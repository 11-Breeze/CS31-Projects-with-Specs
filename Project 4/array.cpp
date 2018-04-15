#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

//Adds value to the end of each string in the a[] array.

int appendToAll(string a[], int n, string value)
{
	int sizeOfArray = 0;
	if (n < 0) // Is this n < 0 or n <= 0 //How do I write an if stating if the position of an array is past the last element the user is interesed in?
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			a[i] += value;
		}
		return n;
	}
}

//Searches for target within the a[] array.

int lookup(const string a[], int n, string target)
{
	if (n < 0) // Is this n < 0 or n <= 0 //How do I write an if stating if the position of an array is past the last element the user is interesed in?
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if(a[i] == target)
			{
				return i;
			}
		}
		return -1;
	}
}

//Finds the largest string within the a[] array.

int positionOfMax(const string a[], int n)
{
	int greatestStringPosHolder = 0;
	string greatestString = a[0];
	if (n <= 0) // Is this n <= 0 or n < 0
	{
		return -1;
	}
	if (n == 1)
	{
		return greatestStringPosHolder;
	}
	else
	{
		for (int k = 1; k < n; k++)
		{
			/*if (a[k] >= a[k - 1])
				{
					if (a[k] == a[k - 1])
					{
						continue;
					}
					else
					{*/
			if (a[k] >= greatestString)
			{
				if (a[k] == greatestString)
				{
					continue;
				}
				else
				{
					greatestString = a[k];
					greatestStringPosHolder = k;
				}
			}
				else
				{
					continue;
				}
		}
	}
		return greatestStringPosHolder;
}
		/*for (int k = 1; k < n; k++)
		{
			for (int x = 0; x < a[k].size(); x++)
			{
				if (a[k][x] >= a[k - 1][x])
				{
					if (a[k][x] == a[k - 1][x])
					{
						continue;
					}	
					else 
					{
						if (a[k][x] >= greatestString[x])
						{
							if (a[k][x] == greatestString[x])
							{
								continue;
							}
							else
							{
								greatestString = a[k];
								greatestStringPosHolder = k;
								break;
							}
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					break;
				}
			}
		}
		return greatestStringPosHolder;
	}
}*/

//Selects a string within the a[] array and moves every string after the selected string to the left. 
//The selected string goes to the end of the array.

int rotateLeft(string a[], int n, int pos)
{
	string stringHolder;
	if (n <= 0 || pos >= n || pos < 0) //Is this n < 0 or n <= 0
	{
		return -1;
	}
	else
	{
		stringHolder = a[pos];
		for (int i = pos; i < n; i++)
		{
			if (i + 1 < n)
			{
				a[i] = a[i + 1];
			}
		}
		a[n - 1] = stringHolder;
		return pos;
	}
}

//Counts the number of one or more consecutive identical items

int countRuns(const string a[], int n)
{
	int numOfSequences = 0;
	if (n < 0)
	{
		return -1;
	}
	else if (n == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i + 1 < n && a[i + 1] == a[i])
			{
				continue;
			}
			else
			{
				numOfSequences++;
			}
		}
		return numOfSequences;
	}
}

//Reverses the order of the array and the range of the reversal is desginated by n

int flip(string a[], int n)
{
	int x = 1;
	string stringHolder;
	if (n < 0) //I think this is n < 0 becaause an empty string can technically still flip
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < (n/2); i++)
		{
			stringHolder = a[i];
			a[i] = a[n - x];
			a[n - x] = stringHolder;
			x++;
		}
		return n;
	}
}

//Finds the position of the first corresponding elements of a1 and a2 that are not equal

int differ(const string a1[], int n1, const string a2[], int n2)
{
	int posHolder = 0;
	if (n1 < 0 || n2 < 0) //Should this be n1 <= 0 || n2 <= 0?
	{
		return -1;
	}
	else if (n1 == 0 && n2 == 0) //Should this be n1 <= 0 && //ASK IF THIS IS CORRECT
	{
		return 0;
	}
	else //Since both arrays are equal up to the point where either n1 == 0 and runs out or n2 == 0 and runs out, return either n1 or n2
	{
		if (n1 > n2)
		{
			for (int i = 1; i < n2; i++)
			{
				if (a1[i] == a2[i])
				{
					continue;
				}
				else if (a1[i] > a2[i] || a2[i] > a1[i])
				{
					return i;
				}
			}
			return n2;
		}
		if (n2 > n1)
		{
			for (int i = 1; i < n1; i++)
			{
				if (a1[i] == a2[i])
				{
					continue;
				}
				else if (a1[i] > a2[i] || a2[i] > a1[i])
				{
					return i;
				}
			}
			return n1;
		}
		if (n1 == n2)
		{
			for (int i = 1; i < n1; i++)
			{
				if (a1[i] == a2[i])
				{
					continue;
				}
				else if (a1[i] > a2[i] || a2[i] > a1[i])
				{
					return i;
				}
			}
			return n1;
		}
	}
}

//Finds the first position where a consequtive sequence of a2[] begins in a1[] in order 

int subsequence(const string a1[], int n1, const string a2[], int n2) // YOU DID NOT FINISH THIS YET!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	int position;
	bool a = false;   //use a boolean variable to be able to add extra check conditions
	int beginning;

	for (int i = 0; i < n1; i++) 
	{
		if (a1[i] == a2[0]) //checks if any point in in a1 is the same as the start of a2
		{    
			beginning = i;
			for (int j = 0, position = i; j < n2; j++, position++) //goes through a2 and a1 simultaneously where position stores the location index of a1
			{     
				a = true;
				if (a2[j] != a1[position]) //the moment it is not equal then break
				{     
					a = false;
					break;
				}
			}
			if (a) //if the position is true then return the smallest position of the start of the continuous sequence in a1
			{           
				return beginning;
			}
		}
	}   
	if (n2 == 0)  //if there are no elements then it is still technically a subsequence of any array sequence and 0 will be returned
	{       
		return 0;
	}
	return -1;
}

//Returns the first element within a1[] that appears in a2[]

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	bool a = false;
	int posHolder = 0;
	int posHolder2 = -1;
	if (n1 < 0 || n2 < 0)
	{
		return -1;
	}
	else if (n1 == 0 || n2 == 0) //ASK IF THE 0 ELEMENTS RULE IN THE subsequence() FUNCTION APPLIES TO lookupAny() //ASK IF THIS IS CORRECT!!!!!!!! AN ARRAY WITH NO ELEMENTS SHOULD NOT HAVE AN ELEMENT EQUAL TO ANOTHER ARRAY WITH NO ELEMENTS!!!!!!!
	{
		return -1;
	}
	else
	{
		for (int k = 0; k < n2; k++)
		{
			for (int i = 0; i < n1; i++)
			{
				if (a2[k] == a1[i] && a == false)
				{
					if (i > posHolder)
					{
						posHolder = i;
						a = true;
						break;
					}
					/*else if (a == true)
					{
						if (i < posHolder)
						{
							posHolder = i;
							break;
						}
						else
						{
							continue;
						}
					}*/
					/*else if (a == true && i < posHolder)
					{
						posHolder = i;
						break;
					}
					else if (a == true && i > posHolder)
						break;*/
					else
					{
						break;
					}
				}
				else if (a2[k] == a1[i] && a == true)
				{
					if (i < posHolder)
					{
						posHolder = i;
						break;
					}
					else if (i > posHolder)
						break;
					}
				else
				{
						continue;	
				}
			}
		}
		if (a == true)
		{
			posHolder2 = posHolder;
			return posHolder2;
		}
		else
		{
			return posHolder2;
		}
	}
}

/*int split(string a[], int n, string split)
{
	bool b;
	int holder1 = 0;
	int startFromEnd = 1;
	int startFromBeginning = 0;
	string holder;
	string holder2;
	for (int k = 0; k < n; k++)
	{
		if (a[k] == split)
		{
			b = true;
			holder1 = k;
		}
		else
		{
			b = false;
		}
	}
	if (n < 0)
	{
		return -1;
	}
	else if (n == 0)
	{
		return n;
	}
	else
	{
		if (b = true)
		{
			holder = a[(n / 2)];
			a[(n / 2)] = split;
			a[holder1] = holder;
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] > split)
			{
				holder = a[n - startFromEnd];
				a[n - startFromEnd] = a[i];
				startFromEnd++;
			}
			else if (a[i] < split)
			{
				holder2 = a[n - startFromBeginning];
				a[startFromBeginning] = a[i];
				startFromBeginning++;
			}
			else
			{
				continue;
			}
		}
	//a[n / 2] = split;
	if (b = false)
	{
	for (int k = 0; k < n; k++)
	{
	if (a[k] == split)
	{
	a[y] = a[k];
	}
	}
	}
	for (int j = ((n / 2) + 1); j < n; j++)
	{
	if (a[j] < split)
	{
	a[x] = a[j];
	x++;
	}
	else if (a[j] > split)
	{
	a[y] = a[j];
	y++;
	}
	else
	{
	continue;
	}
	} //NEED A COMMENT MARKER HERE
		if (a[(n / 2)] == split)
		{
			return ((n / 2));
		}
		else
		{
			return n;
		}
	}
}*/

//Rearrange the elements of the array so that all the elements whose value is less than splitter come before all the other elements, and all the elements whose value is > splitter come after all the other elements. 

int split(string a[], int n, string splitter)
{        
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (n>0)
	{
		int counter = -1;
		for (int j = 0; j<n; j++) // counts elements that are less than split
		{
			if (a[j] < splitter)
				counter++;
		}
		for (int k = 0; k<n; k++)
		{

			if (k <= counter && a[k] > splitter) //if current element is less than counter and greater than split, move to right of split
			{
				string temp;
				for (int f = counter; f<n; f++)
				{
					if (a[f] < splitter)
					{
						string temp = a[f];
						a[f] = a[k];
						a[k] = temp;
					}
				}
			}
			if (k > counter && a[k] < splitter) // if current element is greater than counter and less than split move to the left of split
			{
				string temp;
				for (int x = counter; x<n; x++)
				{
					if (a[x] > splitter)
					{
						string temp = a[x];
						a[x] = a[k];
						a[x] = temp;
					}
				}
			}

		}
		return counter + 1; // return one greater than the counter counter
	}
	else
	{
		return -1;
	}
}


int main()
{
	string h[7] = { "selina", "reed", "diana", "tony", "", "logan", "peter" };
	assert(lookup(h, 7, "logan") == 5);
	assert(lookup(h, 7, "diana") == 2);
	assert(lookup(h, 2, "diana") == -1);
	assert(positionOfMax(h, 7) == 3);

	string g[4] = { "selina", "reed", "peter", "sue" };
	assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "selina?" && g[3] == "sue?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "peter?" && g[3] == "reed?");

	string e[4] = { "diana", "tony", "", "logan" };
	assert(subsequence(h, 7, e, 4) == 2);

	string d[5] = { "reed", "reed", "reed", "tony", "tony" };
	assert(countRuns(d, 5) == 2);

	string f[3] = { "peter", "diana", "steve" };
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "steve" && f[2] == "peter");

	assert(split(h, 7, "peter") == 3);

	cout << "All tests succeeded" << endl;
}

//int main()
//{
	//TEST FOR positionOfMax()!!!
	
	/*string hero[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
	int j = positionOfMax(hero, 6);   // returns 3, since  tony  is latest
									  // in alphabetic order*/
	
	/*string hero[6] = { "clark", "abby", "clark", "davidg", "clark" , "davidgejjjjj"};
	/*string k;
	getline(cin, k);
	int j = positionOfMax(hero, 6);*/

	//TEST FOR rotateLeft()!!!
	
	
	/*string super[5] = { "logan", "clark", "peter", "sue", "reed" };
	int j = rotateLeft(super, 5, 0);  // returns 1
									  // super now contains:  "logan", "peter", "sue", "reed", "clark"
	cout << j << endl;
	cout << super[0] << endl;
	cout << super[1] << endl;
	cout << super[2] << endl;
	cout << super[3] << endl;
	cout << super[4] << endl;*/

	//TEST FOR countRuns()!!!
	
	/*string d[9] = {
		"tony", "bruce", "steve", "steve", "diana", "diana", "diana", "steve", "steve"
	};
	int p = countRuns(d, 9);  //  returns 5
							  //  The five sequences of consecutive identical items are
							  //    "tony"
							  //    "bruce"
							  //    "steve", "steve"
							  //    "diana", "diana", "diana"
							  //    "steve", "steve"
	cout << p << endl;*/
	
	//TEST FOR flip()!!!

	/*(string folks[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
	int q = flip(folks, 1);  // returns 4
							 // folks now contains:  "tony"  ""  "steve"  "bruce"  "sue"  "clark"
	cout << q << endl;
	cout << folks[0] << endl;
	cout << folks[1] << endl;
	cout << folks[2] << endl;
	cout << folks[3] << endl;
	cout << folks[4] << endl;
	cout << folks[5] << endl;*/
	
	//TEST FOR differ()!!!

	/*string folks[6] = { "bruce", "steve", "", "tony", "sue", "clark" };
	string group[6] = { "bruce", "steve", "clark", "", "tony" };
	string folks[6] = { "bruce", "bruce", "bruce", "bruce", "bruce", "bruce" };
	string group[5] = { "bruce", "bruce", "bruce", "bruce", "bruce" };
	int r = differ(folks, 4, group, 5);  //  returns 2
	int s = differ(folks, 0, group, 0);  //  returns 1 // ASK IF THIS SHOULD RETURN 0!!!
	cout << s << endl;*/

	//TEST FOR subsequence() //I DID NOT FINISH THIS YET!!!!!!!!!!!!!!!!!!!!!!!
	
	/*string names[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
	string names1[10] = { "reed", "sue", "selina" };
	int t = subsequence(names, 6, names1, 3);  // returns 1
	string names2[10] = { "logan", "selina" };
	int u = subsequence(names, 5, names2, 2);  // returns -1
	cout << t << endl;*/

	//TEST FOR lookupAny()

	/*string names[10] = { "logan", "reed", "sue", "selina", "bruce", "peter" };
	string set1[10] = { "clark", "bruce", "selina", "reed" };
	int v = lookupAny(names, 6, set1, 4);  // returns 1 (a1 has "reed" there)
	string set2[10] = { "tony", "diana" };
	int w = lookupAny(names, 6, set2, 2);  // returns -1 (a1 has none)
	cout << v << endl;*/

	//TEST FOR split()

	
	/*string hero[6] = { "clark", "peter", "reed", "tony", "diana", "bruce" };
	int x = split(hero, 6, "logan");  //  returns 3
	string hero2[4] = { "reed", "sue", "peter", "steve" };
	int y = split(hero2, 4, "steve");  //  returns 2
	cout << y;
	cout << hero2[0] << endl;
	cout << hero2[1] << endl;
	cout << hero2[2] << endl;
	cout << hero2[3] << endl;
}
*/
