#include <iostream>
#include "funcs.h"

int main() {
	aboutA();
	int N = 12;
	int* array = new int[N];
	Message(N);
	MenuInput(array, N);
	delete[] array;
	return 0;
}

void MenuInput(int*& arr, int& n) {
	char option;
	std::cout << "\n   N = " << n << " \n\n   Enter '1' to fill from keyboard\n   " <<
		"Enter '2' to fill with pseudorandom numbers\n   " <<
		"Enter '3' to change N\n\n   " <<
		"Enter any other key to quit\n\n" <<
		"---Your choice: ";

	std::cin >> option;
	switch (option) {
	case '1':	ArrayInput(arr, n);	MenuAct(arr, n);
		break;
	case '2': ArrayRand(arr, n); MenuAct(arr, n);
		break;
	case '3': ChangeN(arr, n);	MenuInput(arr, n);
		break;
	}
	system("cls");
}

void MenuAct(int*& arr, int& n) {
	char option;
	int val;
	std::cout << "\n\n   Enter '1' to insert a value\n   " <<
		"Enter '2' to sort the array\n   " <<
		"Enter 'q' to quit\n   " <<
		"Enter 'r' to return to 1st Menu\n\n" <<
		"---Your choice: ";

	std::cin >> option;
	switch (option) {
	case '1': std::cout << "\n---Enter an integer: "; std::cin >> val; ArrayIns(arr, n, val); MenuAct(arr, n); break;
	case '2': ArraySort(arr, n); MenuAct(arr, n); break;
	case 'q': system("cls"); break;
	case 'r': system("cls"); MenuInput(arr, n); break;
	default: system("cls"); MenuAct(arr, n); break;
	}
	system("cls");
}

void Message(int n) {
	std::cout << "\n   MEMORY ALLOC: " << n << "   " << n * 4;
}

void aboutA() {
	setlocale(LC_ALL, "Ukrainian");
	std::cout << "\n\n   Єрiс Євген\n   " <<
		"Група К-15\n\n   " <<
		"Завдання:\n   " <<
		"8. Вставити елемeнт пiсля останнього елеманта з мiнiмальним значенням\n   " <<
		"SelectionSort\n\n";
}