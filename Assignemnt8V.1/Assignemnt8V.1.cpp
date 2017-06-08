// Assignemnt8V.1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <sstream>
#include <iostream>


using namespace std;
const int MAX = 10;
struct student_t
{
	int kNum;
	string name;
} student [MAX];


void MergeSort(student_t values[], int first, int last);

void Merge(student_t values[], int leftFirst, int leftLast, int rightFirst, int rightLast);



int main()
{
	string mystr;
	int n;

	for (n = 0; n<MAX; n++)
	{
		cout << "Enter student name: ";
		cin >> student[n].name;
		cout << "Enter k-number: ";
		cin >> student[n].kNum;
		cout << endl;
		
	}

	cout << "\nBefore sort:\n";
	for (int i = 0; i < MAX; ++i)
	{
		cout << "Name: " << student[i].name << endl;
		cout << "Marks: " << student[i].kNum << endl;
	}
	MergeSort(student, 0, MAX-1);
	cout << "\nAfter sort:\n";
	for (int i = 0; i < MAX; ++i)
	{
		cout << "Name: " << student[i].name << endl;
		cout << "Marks: " << student[i].kNum << endl;
	}
	cout << "\n";
    return 0;
}

void Merge(student_t values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
	student_t tempArray[MAX];
	int index = leftFirst;
	int saveFirst = leftFirst;
	while ((leftFirst <= leftLast) &&
		(rightFirst <= rightLast))
	{
		if (values[leftFirst].kNum > values[rightFirst].kNum)
		{
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else
		{
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}
	while (leftFirst <= leftLast)
	{
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast)
	{
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}
	for (index = saveFirst; index <= rightLast; index++)
		values[index] = tempArray[index];
}

void MergeSort(student_t values[], int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}