/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/31/2015
* Last Modification Date:	11/1/2015
* Assignment Number:    CST 211 Assignment 5
* Filename:				Driver.cpp
*
* Overview:
*	This is the Driver file to test the custom CircularQueue
*	and NormalQueue classes.
*
* Input:
*
*
* Output:
*	
************************************************************/

#include <iostream>
#include "CircularQueue.h"
#include "NormalQueue.h"

using namespace std;

// Check that constructors are functioning
void ctorTester();

// Test that enqueue and dequeue are functioning
void enqueueTests();

// Test that Front() member function is working.
void frontTest();

void main()
{
	ctorTester();
	enqueueTests();
	frontTest();
}

/**************************************************************
*	  Purpose:  Tests constructors of normalqueue and circularqueue
*				classes
*
*         Entry:	
*
*          Exit:
****************************************************************/
void ctorTester()
{
	CircularQueue<int> newQueue(10);

	int size = newQueue.size();

	NormalQueue<int> newNormalQueue(5);

}

/**************************************************************
*	  Purpose:  Tests enqueue and dequeue functions
*
*         Entry:	
*
*          Exit:
****************************************************************/
void enqueueTests()
{
	try
	{


		CircularQueue<int> newQueue(10);



		newQueue.Enqueue(6);
		newQueue.Enqueue(2);

		/*
		// Test overflow
		newQueue.Enqueue(6);
		newQueue.Enqueue(2);
		newQueue.Enqueue(6);
		newQueue.Enqueue(2);
		newQueue.Enqueue(6);
		newQueue.Enqueue(2);
		newQueue.Enqueue(6);
		newQueue.Enqueue(2);
		newQueue.Enqueue(6);
		*/
		



		int DeqVal;

		DeqVal = newQueue.Dequeue();

		DeqVal = newQueue.Dequeue();
		/*
		//Test Underflow
		DeqVal = newQueue.Dequeue();
		*/

		NormalQueue<int> newNormal(5);
		int enqval1 = 4;
		int enqval2 = 2;
		int enqval3 = 6;
		int enqval4 = 999;

		newNormal.Enqueue(&enqval1);
		newNormal.Enqueue(&enqval2);
		newNormal.Enqueue(&enqval3);
		newNormal.Enqueue(&enqval4);

		newNormal.Dequeue();
		newNormal.Dequeue();


	}

	catch (Exception& except)
	{
		cout << except;
	}


}

/**************************************************************
*	  Purpose:  Tests Front() functions
*
*         Entry:	
*
*          Exit:
****************************************************************/
void frontTest()
{
	CircularQueue<int> newQueue(10);

	newQueue.Enqueue(6);
	newQueue.Enqueue(2);

	int newVal = 10;

	newQueue.Front() = newVal;

	NormalQueue<int> newNormal(5);
	int enqval1 = 4;
	int enqval2 = 2;
	int enqval3 = 6;
	int enqval4 = 999;

	newNormal.Enqueue(&enqval1);
	newNormal.Enqueue(&enqval2);
	newNormal.Enqueue(&enqval3);
	newNormal.Enqueue(&enqval4);

	newNormal.Front() = newVal;


}