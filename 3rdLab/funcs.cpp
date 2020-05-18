#include "funcs.h"

//Фуекція очищення масиву
void arrClear(char* arr, int N) {
	for (int i = 0; i < N; ++i) {
		arr[i] = '\0';
	}
}

//Функція пошуку найбільшого слова в реченні
void lenCheck(char* sent, int len, char* maxw)
{
	char word[600] = {};
	arrClear(word, len);

	int maxl = 0;
	int j = 0;

	for (int i = 0; i < len; ++i) {
		if ((sent[i] != ' ') && (sent[i] != '.')) {
			word[j] = sent[i];

			++j;
		}
		else
		{
			j = 0;
			if (sent[i - 1] != ' ') {

				if (myStrlen(word) >= maxl) {
					maxl = myStrlen(word);
					myStrcpy(maxw, word);

					arrClear(word, len);
				}
			}
		}
	}
}

//Функція, що зчитування інформації з файлу й утворення кінцевого результату
void fileRead(int N) {
	char point[3] = ". ";
	char a = ' ';
	int sentlen = 0, sentstart = 0;

	char* new_file = new char[N];
	arrClear(new_file, N);

	std::ifstream fli; fli.open(/*INPUT FILE PATH*/"text.txt");

	if (fli.is_open()) {
		char* file_content = new char[10 * N];
		arrClear(file_content, 10 * N);
		int i = 0;

		while (!fli.eof()) {
			fli.get(a);
			file_content[i] = a;
			++sentlen;

			if (a == '.') {
				char* maxw = new char[600];
				arrClear(maxw, 600);

				lenCheck(&file_content[sentstart], sentlen, maxw);
				myStrcat(maxw, point);
				myStrcat(new_file, maxw);

				sentstart = i + 1;
				sentlen = 0;
				delete[] maxw;
			}
			++i;
		}
		fli.close();
		int leb = myStrlen(new_file);
		if (myStrlen(new_file) <= 1) {
			pointPut(file_content);
			myStrcat(new_file, file_content);
		}

		delete[] file_content;
	}
	std::cout << "\n\nRESULT:\n" << new_file << "\n\n";

	std::ofstream flo; flo.open(/*OUTPUT FILE PATH*/"res.txt");
	if (flo.is_open()) {
		flo << new_file;
		flo.close();
	}
	delete[] new_file;
}

//Функція додавання точки через кожні 6 слів
void pointPut(char* text)
{
	int len = myStrlen(text);
	int wordcount = 0;
	bool flag = false;
	for (int i = 0; i < len; ++i) {
		if ((text[i] == ' ') && (flag == true))
			++wordcount;
		if (text[i] != ' ')
			flag = true;
		if (wordcount == 6) {
			text[i] = '.';
			wordcount = 0;
		}
	}
}

char* myStrcat(char* str1, char* str2) {
	int i = 0, j = 0;
	bool b = false;
	do {
		if (str1[i] == '\0')
			b = true;
		if (b == true) {
			str1[i] = str2[j];
			++j;
		}
		++i;
	} while (str2[j] != '\0');
	str1[i] = '\0';
	return str1;
}

int myStrlen(const char* str) {
	int n = 0;
	char tempch = str[0];
	do {
		tempch = str[++n];
	} while (tempch != '\0');
	return n;
}

char* myStrcpy(char* str1, char* str2) {
	int i = 0;
	do {
		str1[i] = str2[i];
		++i;
	} while (str2[i] != '\0');
	str1[i] = '\0';
	return str1;
}