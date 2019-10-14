/*
 * Course: CS216
 * Project: Project 1
 * Purpose: Calculates the curved grades for every student by first making an object that holds the
 * 	    original grades entered by the user. Grades have to be in range of [0-100] or the
 * 	    program will kick the input and notify the user that its an invalid input. The user will
 * 	    continue to input grades until they enter 'Q' or 'q' to stop. Once the first Gradebook
 * 	    object is created the program creates a second gradebook object that will then be 
 * 	    a copy of the first gradebook object. The user will then decide what class average they
 * 	    want their grades to be. The program will check to make sure that the user input average
 * 	    is greater than the original average and it does not exeed 100. The program will kick
 * 	    any invalid input from the user and notify them that their input is invalid. Once 
 * 	    a valid input is entered the program will increment every grade in the second gradebook
 * 	    object by the [user input expected average] - [Origninal gradebook average]. Once all 
 * 	    grades are incremented the program displays the Original gradebook along with the 
 * 	    Maximum grade and minimum grade as well as the average of the gradebook. Then the 
 * 	    program outputs the curved gradebook grades along with the curved Max grade, curved 
 * 	    Min grade, new Curved average. The user will continue to input new curved averages until
 * 	    they input a 'Q' or 'q' to quit out of the program.
 * Author: Brandon Bray
 **/

#include <iostream> 	// cout, fixed
#include <iomanip>	// setprecision
#include <cmath>	// abs or absolute value
#include "Gradebook.h"

using namespace std;

void getGrades(Gradebook& grades);
void curveBook(Gradebook& grades);
void printGrades(Gradebook& grades);

int main()
{
	//creates the original gradebook object
	Gradebook grades;

	//calls the getGrades function to get user input grades to input into the grades object
	getGrades(grades);

	//sets and fixes the cout decimal precision for doubles to 2 decimal places or the 
	//hundrets place
	cout << fixed << setprecision(2);

	//checks to see how many grades are in the grades object. If the number of grades is 
	//0 then it notifies the user that the gradebook is empty and exits out of the program
	//else the program calls the curveBook function to create the curved gradebook object
	if (grades.getSize() == 0)
		cout << "The gradebook is Empty!" << endl;
	else
		curveBook(grades);

	//notifies the user they are at the end of the program
	cout << "Thank you for using the Grade Curve Calculator." << endl;

	return 0;
}

/*function that takes in a call by reference Gradebook object and ask the user to input grades 
 * the function verifys the value of grades to be double floating point number and checks the range
 * of the number to ensure it is between [0-100]. If the number passes all the requirements the 
 * function creates a new Finalgrade object and inserts it into the gradebook objec number and 
 * checks the range of the number to ensure it is between [0-100]. If the number passes all the 
 * requirements, the function creates a new Finalgrade object and inserts it into the gradebook 
 * object.
 * */
void getGrades(Gradebook& grades)
{
	double newgrade;
	
	//loop that runs until the user inputs a 'Q' or 'q' 
	while (true)
	{

		//ask the user to input a new score for the gradebook
		cout << "Please enter a score for CS216 (type 'Q' or 'q' to quit):" << endl;
		cin >> newgrade;

		//checks the value of the user input to see if its a double 
		if(cin.fail())
		{

			//clears the input flag
			cin.clear();

			//creates string to hold whatever non double number is inside the cin buffer
			string checkQuit;
			cin >> checkQuit;

			//checks to see if the user input 'Q' or 'q' if they did then the program
			//breaks out of the loop
			if(checkQuit == "Q" || checkQuit == "q")
			{
				break;
			}
			//else the program tells the user their input is invalid and uses continue
			//to restart the loop
			else
			{
				cout << "Invalid input, please try again..." << endl;
				cin.ignore(256, '\n');
				continue;
			}
		}

		//checks to see if newgrade is between 0 and 100 if its not then the program
		//notifys the user their score is not in the correct range
		else if(newgrade < 0 || newgrade > 100)
			cout << "The score is not in the correct range, please try again..." 
				<< endl;

		//if score is in the correct range te function creates a new FinalGrade object
		//and sets the score of the newFg to the newgrade values and inserts newFG
		//into the grades Gradebook object.
		else
			{
				FinalGrade newFg;
				newFg.setScore(newgrade);
				grades.insert(newFg);
			}

	}
}

//Function that takes in gradebook object as a parameter and creates a new gradebook object 
//curvedgrades. Copies original gradebook into curved grades. Ask the user for their expected 
//average score and calculates what the scores in the curved grades should be incremented to
void curveBook(Gradebook& grades)
{
	//new Gradebook object to hold the curved grades
	Gradebook curvedGrades;

	//double value used to test if the current gradebook average = to the new expected average
	double TESTVALUE = 0.01;

	//loop that runs until the user inputs either 'Q' or 'q' to quit
	while (true)
	{

		//variable to hold the user input expected average
		double curvedAverage;

		//variable that holds the curve which is used to increment the curved gradebook
		double curve;

		//copies grades gradebook to the curvedGrades gradebook
		curvedGrades = grades;

		//Displays current gradebook score and ask the user for their expected average score
		cout << endl << endl;
		cout << "The original average score is: " << grades.getAverage() << endl;
		cout << "Please enter your expected average score to curve (type 'Q' or 'q' to quit)" << endl;
		cin >> curvedAverage;

		//checks the user input for valid double variable input
		if (cin.fail())
		{
			//string variable to hold user input if the input failed
			string checkQuit;
			//clears the cin flag
			cin.clear();
			cin >> checkQuit;
			//checks to see if the user input 'Q' or 'q' if they did the program leaves
			//the loop
			if(checkQuit == "Q" || checkQuit == "q")
				break;

			//else informs the user invalid input and restarts the loop
			else
			{
				cout << "Invalid input, please try again..." << endl;
				cin.ignore(256, '\n');
				continue;
			}

		}

		//calculates the curve using the difference between user input and original average
		curve = curvedAverage - grades.getAverage();

		//if the absolute value of curve is less than testvalue then the curved average is 
		//the same as the original average and no increments are needed
		if (abs(curve) < TESTVALUE)
			cout << "The scores are perfect, no need for the grading curve!" << endl;

		//else if the curvedAverage is not between [0-100] then the user input is out of 
		//range
		else if (curvedAverage > 100 || curvedAverage < 0)
		{
			cout << "The expected average is not in the correct range, please try again..." << endl;

		}
		//if curved average is in range and greater than original average then increments 
		//the curvedGrades gradebook by curve and outputs first the original gradebook then
		//the curved gradebook.
		else if (curvedAverage > grades.getAverage())
		{
			curvedGrades.incrementScore(curve);

			cout << "The original gradebook for CS216:" << endl;
			printGrades(grades);
			cout << "The original average score is: " << grades.getAverage() << endl;
			cout << endl << endl;
			cout << "The expected average score is: " << curvedAverage << endl;
			cout << "The curved gradebook for CS216:" << endl;
			printGrades(curvedGrades);
			cout << "The actual average score is:\t" << curvedGrades.getAverage() 
				<< endl;

		}
	}
}

//Function that takes in a Gradebook object as its parameter and prints out all the grades in the 
//gradebook object, maximum grade, minumum grade, and the number of scores inside the gradebook
void printGrades(Gradebook& grades)
{
	FinalGrade max;
	FinalGrade min;
	max = grades.getMax();
	min = grades.getMin();
	grades.print();
	cout << "The number of scores is:\t" << grades.getSize() << endl;
	cout << "The maximum score is:\t";
	max.print();
	cout << "The minimum score is:\t";
	min.print();
}
