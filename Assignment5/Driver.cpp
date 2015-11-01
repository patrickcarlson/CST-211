#include <iostream>
#include "CircularQueue.h"
#include "NormalQueue.h"

using namespace std;

void ctorTester();

void enqueueTests();

void frontTest();

void main()
{
	ctorTester();
	enqueueTests();
	frontTest();
}

void ctorTester()
{
	CircularQueue<int> newQueue(10);

	int size = newQueue.size();

	NormalQueue<int> newNormalQueue(5);

}

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

		// Test Underflow
		/*
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

	catch (Exception except)
	{
		cout << except;
	}


}

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

	int* newFront = &newVal;

	newNormal.Front() = *newFront;


}