/************************************************************************
`* This program gives the user a choice to enter student names and grades
`* and allows them to be displayed
************************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


int main()
{
	vector<string> stuVector; // Vector of strings to hold student names
	vector<int> gradesVector; // Vector of int to hold grades
	
	string name; // Holds student names
	double grade; // Holds student grade
	int numStudents; // Holds number of students
	int count = 0, // Counter variable
		index = 1, // Tracks which student user is entering for
		choice = 0; // Holds user choice from menu
	
	// Prompt user for selection from menu
	cout << "1 - Enter Student Names and Grades" << endl;
	cout << "2 - Display Student Names and Grades" << endl;
	cout << "3 - Quit" << endl;
	cout << "Please make a selection from the menu: ";
	cin >> choice; // Get user choice
	
		// While loop input validation to ensure input is an integer between 1 and 3
		while( cin.fail() || ((choice < 1 ) && (choice > 3)) )
		{	
			// Clear input stream
			cin.clear();
			cin.ignore(100, '\n');
			// Prompt user for correct integer range
			cout << "Please enter a number greater than 0: ";
			cin >> choice; // Get user input
		}
	
	cout << endl; // Blank line
	
	// Begin do while loop
	do
	{
		if( choice == 1 )
		{
			// Prompt user for number of students to input
			cout << "How many students with grades will you be entering? ";
			cin >> numStudents; // Get user input
			
				// While loop input validation to ensure input is an integer greater than 0
				while( cin.fail() || (numStudents <= 0) )
				{
					// Clear input stream
					cin.clear();
					cin.ignore(100, '\n');
					// Prompt user for correct input
					cout << "Please enter a number greater than 0: ";
					cin >> numStudents; // Get user input
				}
			
			// While loop for continuous input
			while( count != numStudents )
			{	
				// Prompt for user name at index
				cout << "Please enter the name for student " << index << ": ";
				// Ignore last input
				cin.ignore();
				// Get user input
				getline(cin, name);
				// Assign input name to stuVector
				stuVector.push_back(name);
				// Prompt user for grade input for stuVector at count
				cout << "Please enter a grade between 0 and 120 (maximum of 20 bonus points) for "
					 << stuVector[count] << ": ";
				// Get user input for grade
				cin >> grade;
					// While loop input validation to ensure input is an integer greater than 0 and less than 120
					while( cin.fail() || (grade < 0) || (grade > 120) )
					{
						// Clear buffer
						cin.clear();
						cin.ignore(100, '\n');
						// Prompt user for correct input
						cout << "Please enter a grade between 0 and 120 (maximum of 20 bonus points): ";
						cin >> grade; // Get user input
					}
				
				// Assign grade to gradesVector
				gradesVector.push_back(grade);
				count++; // Increment counter
				index++; // Increment index
			}
		}
		
		// Displays stuVector and gradesVector if they hold data
		if( (choice == 2) && (stuVector.size() != 0) && (gradesVector.size() != 0) )
		{
			cout << setw(10) << "Student" << setw(10) << "|" << setw (10)<< " Grade" << endl;
			
			for( unsigned int i = 0; i < stuVector.size(); i++ )
			{
				cout << right << setw(10) << stuVector[i] << right << setw(23) << gradesVector[i] << endl;
			}
		}
		
		// Display message that vectors are empty if they hold no data
		if( (stuVector.size() == 0) && (gradesVector.size() == 0) )
			cout << "The grade book is empty. Please rerun program to enter grades." << endl;
			
		cout << endl; // Blank line	
		
		// Display menu options to allow user to continue or quit
		cout << "1 - Enter Student Names and Grades" << endl;
		cout << "2 - Display Student Names and Grades" << endl;
		cout << "3 - Quit" << endl;
		cout << "Please make a selection from the menu: ";
		cin >> choice; // Get user input
	
			// While loop input validation to ensure input is an integer between 1 and 3
			while( cin.fail() || ((choice < 1 ) && (choice > 3)) )
			{
				// Clear buffer / input stream
				cin.clear();
				cin.ignore(100, '\n');
				// Prompt user for correct input
				cout << "Please enter a number greater than 0: ";
				cin >> choice; // Get user input
			}
		
		cout << endl; // Blank line
		
		}while( choice != 3 ); // End do while loop
	
	return 0;
}