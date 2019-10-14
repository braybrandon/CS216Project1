----------------------------------------------------------------------------------------------------
CS216 Project1 Gradebook Curve Calculator
----------------------------------------------------------------------------------------------------

The Gradebook curve calculator uses two seperate classes to create Gradebook objects that will hold
a vector of Finalgrade objects. The program starts and creates an original gradebook object and ask
the user to input different grades from [0-100] and they are stored as a finalgrade object in the 
original gradebook object. The program then gives the user the original gradebook average and ask
the user what expected gradebook average they want. The user inputs the average they want their 
gradebook to be and the program creates a new gradebook object that copies the data from the
original gradebook object. Takes the difference from the expected average and the original gradebook
average and increments the new curve gradebooks grades by that difference. The program then displays
all the grades from the original gradebook along with the minimum and maximum grades as well as the number of grades in the gradebook, and finally the average of the original gradebook. Then the 
program displays the curved gradebooks grades, min grade, max grade, number of scores, and 
final average. Program continues to ask the user for curved average until the user inputs a 'Q' or 
'q' to quit out of the program.

Prerequisites
To compile the program you will need a compiler that is suited for C++11(used linux G++ compiler
when creating this program)
	The files
		-FinalGrade.cpp //FinalGrade class that defines everything needed for the FinalGrade
				  object
		-Gradebook.cpp  //Gradebook class that defines everything needed for the Gradebook
				  object	
		-PA1.cpp        //Main File containing the main function for the Program	
		-FinalGrade.h   //Header file for the FinalGrade class
		-Gradebook.h    //Header file for the Gradebook class

Installation
To install using linux type the fallowing commands
	g++ FinalGrade.cpp PA1.cpp Gradebook.cpp -o CS216PA1
	(this will create an executable file for the linux operational system)

To run the file type the fallowing commands
	./CS216PA1

Author
	Brandon Bray

Version 1.0.0
