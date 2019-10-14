 /* 
 * File:   Gradebook.cpp
 * Course: CS216
 * Project: Lab 5 (as second part of Project 1)
 * Purpose: provide the implementation of the member functions of Gradebook class
 *
 * Author: Brandon Bray
 *
 */
#include <iostream>
#include "Gradebook.h"

// default constructor
Gradebook::Gradebook()
{
}

// return the size of the current vector: scores, 
// which represents current gradebook
int Gradebook::getSize() const
{
	return scores.size();
}
    
// insert a FinalGrade object, newFG, 
// into the end of the current gradebook
void Gradebook::insert(FinalGrade newFG)
{
	scores.push_back(newFG);
}

// return a FinalGrade object, 
// which holds the maximum score in the current gradebook
FinalGrade Gradebook::getMax() const
{
	int max = 0;
	for (int i = 1; i < getSize(); i++)
		if (scores[max].getScore() < scores[i].getScore())
			max = i;
	return scores[max];
}

// return a FinalGrade object,
// which holds the minimum score in the current gradebook
FinalGrade Gradebook::getMin() const
{
	int min = 0;
	for (int i = 1; i < getSize(); i++)
		if (scores[min].getScore() > scores[i].getScore())
			min = i;
	return scores[min];
}
    
// return the average score among all scores in the current gradebook
double Gradebook::getAverage() const
{
	double average = 0;
	int i = 0;
	while (i < getSize())
	{
		average = average + scores[i].getScore();
		i++;
	}
	return average / i;
}

// For each FinalGrade object in the current gradebook, 
// its score will be increased by the given value 
// If the score reaches MAX_SCORE, it does not go beyond
void Gradebook::incrementScore(double value)
{
	double newScore;
	for (int i = 0; i < getSize(); i++)
	{
		newScore = scores[i].getScore() + value;
		if (newScore > 100.0)
			newScore = 100.0;

		scores[i].setScore(newScore);
	}
}
    
// print the FinalGrade objects in the current gradebook
void Gradebook::print() const
{
	for (int i =0; i < getSize(); i++)
		scores[i].print();
}

