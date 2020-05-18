#include <iostream>
#include "funcs.h"

int main() {
	const int length = 100;
	char string1[length];
	char string2[length];
	arrClear(string1);
	arrClear(string2);
	return menuInput(string1, string2);
}

int menuInput(char* str1, char* str2) {
		char option;
		int n = 0;
		char ch;

		std::cout << " \n\n   Enter '1' to call strlen\n   " <<
			"Enter '2' to call strcat\n   " <<
			"Enter '3' to call strncat\n\n   " <<
			"Enter '4' to call strcmp\n   " <<
			"Enter '5' to call strncmp\n   " <<
			"Enter '6' to call strcpy\n\n   " <<
			"Enter '7' to call strncpy\n   " <<
			"Enter '8' to call strcpy_s\n   " <<
			"Enter '9' to call strchr\n\n   " <<
			"Enter 'a' to call strstr\n   " <<
			"Enter 'b' to call strpbrk\n   " <<
			"Enter 'c' to call strspn\n\n   " <<
			"Enter 'd' to call strcspn\n   " <<
			"Enter 'e' to call pop_back\n   " <<
			"Enter 'f' to call find_first_of\n\n   " <<
			"Enter 'g' to call find_first_not_of\n   " <<
			"Enter 'h' to call find_last_of\n   " <<
			"Enter 'i' to call compare\n\n   " <<
			"Enter any other key to quit\n\n" <<
			"\n\n---Your choice: ";

		std::cin >> option;
		system("cls");
		switch (option) {
		case '1': funcIn(str1, str2, 1); std::cout << myStrlen(str1); std::cin.get(); arrClear(str1);  menuInput(str1, str2);
			break;
		case '2': funcIn(str1, str2, 2); std::cout << myStrcat(str1, str2); std::cin.get(); arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case '3':  funcIn(str1, str2, 2); std::cout << "\nn = "; std::cin >> n; std::cout << myStrncat(str1, str2, n); std::cin.ignore(); std::cin.get();
			arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case '4': funcIn(str1, str2, 2); std::cout << myStrcmp(str1, str2); std::cin.get(); arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case '5':  funcIn(str1, str2, 2); std::cout << "\nn = "; std::cin >> n; std::cout << myStrncmp(str1, str2, n); std::cin.ignore(); std::cin.get();
			arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case '6': funcIn(str1, str2, 2); std::cout << myStrcpy(str1, str2); std::cin.get();
			arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case '7': funcIn(str1, str2, 2); std::cout << "\nn = "; std::cin >> n; std::cout << myStrncpy(str1, str2, n); std::cin.ignore(); std::cin.get();
			arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case '8': funcIn(str1, str2, 2); std::cout << "\nn = "; std::cin >> n; std::cout << myStrcpy_s(str1, str2, n); std::cin.ignore(); std::cin.get();
			arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case '9': funcIn(str1, str2, 1); std::cout << "\n Enter a char: "; std::cin >> ch; funcCheck(myStrchr(str1, ch), str1, str2);
			break;
		case 'a': funcIn(str1, str2, 2); funcCheck(myStrstr(str1, str2), str1, str2);
			break;
		case 'b': funcIn(str1, str2, 2); funcCheck(myStrpbrk(str1, str2), str1, str2);
			break;
		case 'c': funcIn(str1, str2, 2); std::cout << myStrspn(str1, str2);	std::cin.get(); arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case 'd': funcIn(str1, str2, 2); std::cout << myStrcspn(str1, str2); std::cin.get(); arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case 'e': funcIn(str1, str2, 1); std::cout << myPop_back(str1); std::cin.get(); arrClear(str1); arrClear(str2); menuInput(str1, str2);
			break;
		case 'f': funcIn(str1, str2, 2); std::cout << "\nn = "; std::cin >> n; funcCheck(myFind_first_of(str1, str2, n), str1, str2);
			break;
		case 'g': funcIn(str1, str2, 2); std::cout << "\nn = "; std::cin >> n; funcCheck(myFind_first_not_of(str1, str2, n), str1, str2);
			break;
		case 'h': funcIn(str1, str2, 2); std::cout << "\nn = "; std::cin >> n; funcCheck(myFind_last_of(str1, str2, n), str1, str2);
			break;
		case 'i': funcIn(str1, str2, 2); std::cout << myCompare(str1, str2); std::cin.get(); arrClear(str1); arrClear(str1); menuInput(str1, str2);
			break;
		default: return 0; break;
		}
		return 0;
	
	
}

void funcCheck(char* str, char* str1, char* str2) {
	if (str != NULL)
		std::cout << str;
	std::cin.ignore();
	std::cin.get();
	system("cls");
	arrClear(str1);
	menuInput(str1, str2);
}

void funcIn(char* str1, char* str2, int p)
{
	char* arr[2] = { str1, str2 };
	std::cin.ignore();
	for (int i = 0; i < p; ++i) {
		std::cout << "\nEnter a string:\n ";
		std::cin.getline(arr[i], 100);
	}
}

void arrClear(char* str) {
	for (int i = 0; i < 100; ++i)
		str[i] = '\0';
}