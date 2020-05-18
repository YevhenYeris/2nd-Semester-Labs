#include <iostream>
#include "funcs.h"
#include "ctime"
#include "stdlib.h"

void ArrayInput(int* arr, int& n) {
	std::cout << "\n\n---Enter an array of integers:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << "---array[" << i << "] = ";
		std::cin >> arr[i];
	}
	system("cls");
	ArrayOutput(arr, n);
}

void ArrayRand(int* arr, int n) {
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 100;
	system("cls");
	ArrayOutput(arr, n);
}

void ArrayIns(int*& arr, int& n, int val) {
	int ind = MinSearch(arr, n, 0);
	++n;
	int* new_arr = new int[n];
	int j = 0;
	for (int i = 0; i < n; ++i) {
		if (i == ind + 1) {
			new_arr[i] = val;
		}
		else {
			new_arr[i] = arr[j];
			++j;
		}
	}
	delete[] arr;
	arr = new_arr;
	system("cls");
	Message(n);
	ArrayOutput(arr, n);
}

void ArraySort(int*& arr, int n) {
	for (int i = 0; i < n; ++i) {
		int ind = MinSearch(arr, n, i);
		swap(arr[ind], arr[i]);
	}
	system("cls");
	ArrayOutput(arr, n);
}

int MinSearch(int* arr, int n, int low) {
	int min = arr[low], index = 0;
	for (int i = low; i < n; ++i) {
		if (arr[i] <= min) {
			min = arr[i];
			index = i;
		}
	}
	return index;
}

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void ChangeN(int*& arr, int& n) {
	std::cout << "---N = ";
	std::cin >> n;
	if (n <= 0)
		ChangeN(arr, n);
	delete[] arr;
	arr = new int[n];
	system("cls");
	Message(n);
}

void ArrayOutput(int* arr, int n) {
	std::cout << "\n\n   Actual array:\n    ";
	for (int i = 0; i < n; ++i) {
		if (i % 5 == 0)
			std::cout << "\n   ";
		std::cout << arr[i] << " ";
	}

}