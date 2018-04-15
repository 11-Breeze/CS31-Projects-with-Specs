#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Listing the integers that will be used in the program
	int ageOfRider;
	int numOfZoneBoundsCrossed; // Make sure to clarify with someone whether or not an unsigned int is always positive. // Can I use unsigned int?
	double initialFarePrice;
	double perZoneBoundCost;
	double finalFarePrice; //When I set finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZonesBoundsCrossed); the following errors occurred: error C4700: uninitialized local variable 'numOfZoneBoundsCrossed' used, uninitialized local variable 'perZoneBoundCost' used, uninitialized local variable 'initialFarePrice' used
	string student;
	string destination;

	//Test to see if an invalid input was inputted into the program
	cout << "Age of rider: ";
	cin >> ageOfRider;
	cin.ignore(10000, '\n');

	cout << "Student? (y/n): ";
	getline(cin, student); // Do not forget to make the input only equal to y or n.

	cout << "Destination: ";
	getline(cin, destination);

	cout << "Number of zone boundaries crossed: ";
	cin >> numOfZoneBoundsCrossed;
	
	/* Rounds the numbers inputted with at least one digit to the left of the decimal point and
	exactly two digits to the right of theh decimal point */

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Three hyphens required for the output of the program
	cout << "---" << endl;
	
	// Tests for invalid inputs inputted into the program by the user
	if (ageOfRider < 0)
	{
		cout << "The age must not be negative" << endl;
	}

	if (ageOfRider >= 0)
	{
		if (student != "y" && student != "n")
		{
			cout << "You must enter y or n" << endl;
		}
	}

	if (ageOfRider >= 0)
	{
		if (student == "y" || student == "n")
		{
			if (destination == "")
			{
				cout << "You must enter a destination" << endl;
			}
		}
	}

	if (ageOfRider >= 0)
	{
		if (student == "y" || student == "n")
		{
			if (destination != "")
			{
				if (numOfZoneBoundsCrossed < 0)
				{
					cout << "The number of zone boundaries crossed must not be negative" << endl;
				}
			}
		}
	}
	
	/* Tests which fare applies to the user depending on the criteria for each fare and the user's
	inputs */
	if (ageOfRider >= 0 && (student == "y" || student == "n") && destination != "" && numOfZoneBoundsCrossed >= 0) //Although project 2's specs did not specifically state that the age of the rider can be zero, I did not include it in my program because it does not make logical sense
	{
		if (ageOfRider < 18 && numOfZoneBoundsCrossed <= 1)
		{
			initialFarePrice = 0.65;
			perZoneBoundCost = 0.0;
			finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZoneBoundsCrossed);
			cout << "The fare to " << destination << " is $" << finalFarePrice << endl;
		}
		else if (student == "y" && ageOfRider >= 18 && numOfZoneBoundsCrossed <= 1)
		{
			if (ageOfRider >= 65 && numOfZoneBoundsCrossed == 0)
			{
				initialFarePrice = 0.45;
				perZoneBoundCost = 0.0;
				finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZoneBoundsCrossed);
				cout << "The fare to " << destination << " is $" << finalFarePrice << endl;
			}
			else
			{
				initialFarePrice = 0.65;
				perZoneBoundCost = 0.0;
				finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZoneBoundsCrossed);
				cout << "The fare to " << destination << " is $" << finalFarePrice << endl;
			}
		}
		else if (student == "n" && ageOfRider >= 65 && numOfZoneBoundsCrossed > 0)
		{
			initialFarePrice = 0.55;
			perZoneBoundCost = 0.25;
			finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZoneBoundsCrossed);
			cout << "The fare to " << destination << " is $" << finalFarePrice << endl;
		}
		else if (student == "n" && ageOfRider >= 65 && numOfZoneBoundsCrossed == 0)
		{
			initialFarePrice = 0.45;
			perZoneBoundCost = 0.0;
			finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZoneBoundsCrossed);
			cout << "The fare to " << destination << " is $" << finalFarePrice << endl;
		}
		else if (student == "y" && ageOfRider >= 65 && numOfZoneBoundsCrossed > 1)
		{
			initialFarePrice = 0.55;
			perZoneBoundCost = 0.25;
			finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZoneBoundsCrossed);
			cout << "The fare to " << destination << " is $" << finalFarePrice << endl;
		}
		else
		{
			initialFarePrice = 1.35;
			perZoneBoundCost = 0.55;
			finalFarePrice = initialFarePrice + (perZoneBoundCost * numOfZoneBoundsCrossed);
			cout << "The fare to " << destination << " is $" << finalFarePrice << endl;
		}
    }
}