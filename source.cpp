#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
/**************************************************************
*
*
* Name: _____Yanan Liu_________________________________________
* Assignment3 : Print a report for Kingston Bird Watchers Society
*               to show bird sightings in the area.
*
*
***************************************************************/

int main()
{
	//housekeeping
	const int SIZE = 20;
	int noSightings[SIZE], length, totalSightings = 0, index = 0, maxSighting = 0;
	double aveSighting = 0;
	string type[SIZE];
	ofstream fout("birds.dat");
	fout << fixed << setprecision(0);

	if (!fout.is_open())
	{
		cout << "error opening birds.dat";
		cout << "program will terminate ";
		system("pause");
		exit(666);
	}

	fout << "writing to a file" << endl;
	fout << setw(50) << "Kingston Bird Watchers Society" << endl
		<< left << setw(40) << "Type of Bird"
		<< right << setw(5) << "# of sightings" << endl;

	//Input
	for (length = 0; length < SIZE; length++)
	{
		cout << "Please input the bird type here, or ^Z to end " << endl;
		getline(cin, type[length]);

		if (cin.eof())
			break;

		cout << "Please enter the number of sightings you have, or ^Z to end " << endl;
		cin >> noSightings[length];

		if (cin.eof())
			break;


		while (noSightings[length] < 0 || noSightings[length] > 100 || cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "You have input an invalid number, please re-enter a number between 0 and 100 here, or ^Z to end  " << endl;
			cin >> noSightings[length];

			if (cin.eof())
				break;
		}

		if (cin.eof())
			break;

		totalSightings += noSightings[length];

		cin.ignore(80, '\n');
	}

	if (length > 0)
	{
		aveSighting = totalSightings / length;
	}

	for (index = 0; index < length; index++)
	{
		if (noSightings[index] > noSightings[maxSighting])
		{
			maxSighting = index;
		}


		if (noSightings[index] < aveSighting)
		{
			fout << left << setw(40) << type[index]
				<< right << setw(5) << noSightings[index] << "   *** below average ***" << endl;

		}

		else
		{
			fout << left << setw(40) << type[index]
				<< right << setw(5) << noSightings[index] << endl;
		}
	}
	// output

	fout << endl << left << setw(40) << "Total number of sightings "
		<< right << setw(5) << totalSightings << endl;
	fout << left << setw(40) << "The average number of sightings/bird is "
		<< right << setw(5) << aveSighting << endl;
	fout << "The " << type[maxSighting] << " was seen the most." << endl << endl;

	system("type birds.dat");
	system("pause");


}
/*
Please input the bird type here, or ^Z to end
Blue Heron
Please enter the number of sightings you have, or ^Z to end
1000
You have input an invalid number, please re-enter a number between 0 and 100 here, or ^Z to end
75
Please input the bird type here, or ^Z to end
Cardinal
Please enter the number of sightings you have, or ^Z to end
25
Please input the bird type here, or ^Z to end
King Fisher
Please enter the number of sightings you have, or ^Z to end
45
Please input the bird type here, or ^Z to end
^Z
writing to a file
					Kingston Bird Watchers Society
Type of Bird                            # of sightings
Blue Heron                                 75
Cardinal                                   25   *** below average ***
King Fisher                                45   *** below average ***

Total number of sightings                 145
The average number of sightings/bird is    48
The Blue Heron was seen the most.

Press any key to continue . . .

F:\Yanan\SLC\Semester1\COMP1100 c++\test\Debug\test.exe (process 33448) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .



*/