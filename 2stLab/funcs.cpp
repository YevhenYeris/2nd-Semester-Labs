#include <iostream>
#include "funcs.h"

//������� ������� ������� � �����
int myStrlen(const char* str) { 
	int n = 0;
	char tempch = str[0];
	do {
		tempch = str[++n];
	} while (tempch != '\0');
	return n;
}

//�������������
char* myStrcat(char* str1, const char* str2) {
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

//������������� n �������
char* myStrncat(char* str1, const char* str2, int sz) {
	int i = 0;
	bool b = false;
	do {
		if (str1[i] == '\0')
			b = true;
		if (b == true) {
			for (int k = 0; k < sz; ++k) {
				str1[i] = str2[k];
				++i;
			}
			return str1;
		}
		++i;
	} while (1);
	str1[++i] = '\0';
	return str1;
}

//��������������� ������� ��� �����
int myStrcmp(const char* str1, const char* str2) { 
	int i = 0;
	while ((str1[i] != '\0') || (str2[i] != '\0')) {
		if (str1[i] > str2[i])
			return 1;
		else if (str1[i] < str2[i])
			return -1;
		++i;
	}
	return 0; 
}

//��������������� ����� ����� n ������� ���� �����
int myStrncmp(const char* str1, const char* str2, int n) {
	int i = 0;
	while ((str1[i] != '\0') && (i != n - 1)) {
		if ((str1[i] > str2[i]) || (str2[i] == '\0'))
			return 1;
		else if (str1[i] < str2[i])
			return -1;
		++i;
	}
	return 0;
}

//����� ���� ������� ����� � ������
char* myStrcpy(char* str1, const char* str2) {
	int i = 0;
	do {
		str1[i] = str2[i];
		++i;
	} while (str2[i] != '\0');
	str1[i] = '\0';
	return str1;
}

//����� n ������ ������� ������� ����� � ������
char* myStrncpy(char* str1, const char* str2, int sz) {
	int i = 0;
	do {
		str1[i] = str2[i];
		++i;
	} while ((i < sz) && (str2[i] != '\0'));

	return str1;
}

//����� n ������ ������� ������� ����� � ������, ���� ����-������
char* myStrcpy_s(char* str1, char* str2, int sz) {
	int i = 0;
	do {
		str1[i] = str2[i];
		++i;
	} while ((i < sz) && (str2[i] != '\0'));
	str1[sz] = '\0';
	return str1;
}

//����� ������� ��������� ������� � �����
char* myStrchr(char* str, int ch) {
	int i = 0;
	do {
		if (str[i] == char(ch))
			return &str[i];
		++i;
	} while (str[i] != '\0');
	return NULL;
}

//���� ����� ��������� ������� ����� � ������ �����
char* myStrstr(char* str1, char* str2) {
	if (str2[0] == '\0')
		return str1;
	bool flag = false;
	int i = 0, j = 0;
	char* fstp = nullptr;
	do {
		if (str2[j + 1] == '\0')
			return fstp;
		if (str1[i] == str2[j]) {
			if (flag == false)
				fstp = &str1[i];
			flag = true;
			++j;
		}
		else {
			flag = false;
			fstp = nullptr;
			j = 0;
		}
		++i;

	} while (str1[i] != '\0');
	return fstp;
}

/*���� ������ ��������� ����-����� � �������
������� ����� � ������ ����� �� ������� ������*/
	char* myFind_last_of(char* str1, char* str2, int pos) {
		int i = 0;
		char* last = nullptr;
		do {
			int j = 0;
			do {
				if (str1[i] == str2[j])
					last = &str1[i];
				++j;
			} while (str2[j] != '\0');
			++i;
		} while (i <= pos);
		return last;
	}

	/*���� ������ ������ ����� � ������� ������,
�� ����� ������� ������� ������� �����*/
	char* myFind_first_not_of(char* str1, char* str2, int pos) {
		int i = pos;
		do {
			int j = 0;
			do {
				if (str2[j] == '\0')
					return &str1[i];
				++j;
			} while (str2[j] != str1[i]);
			++i;
		} while (str1[i] != '\0');
		return NULL; 
	}

	//������� ������� ������ �����
	char* myPop_back(char* str) {
		int i = -1;
		do {
			++i;
			if (str[i] == '\0') {
				str[i - 1] = '\0';
				return str;
			}
			
		} while (str[i] != '\0');
		return str;
	}

	//����� ������� ��������� ����-����� � ������� ����� � �����
	char* myStrpbrk(char* str1, const char* str2) {
		int i = 0;
		do {
			int j = 0;
			do {
				if (str1[i] == str2[j])
					return &str1[i];
				++j;
			} while (str2[j] != '\0');
			++i;
		} while (str1[i] != '\0');
		return NULL;
	}

	//������� ������� ������� ������� � ������
	int myStrspn(const char* str1, const char* str2) {
		int i = 0, n = 0;
		do {
			int j = 0;
			do {
				if (str1[i] == str2[j])
					++n;
				++j;
			} while (str2[j] != '\0');
			++i;
		} while (str1[i] != '\0');
		return n;
	}

	/*������� ������� ������� ����� �� �������
��������� ����-����� � �������� ������� �����*/
	int myStrcspn(const char* str1, const char* str2) {
		int i = 0;
		do {
			int j = 0;
			do {
				if (str1[i] == str2[j])
					return i;
				++j;
			} while (str2[j] != '\0');
			++i;
		} while (str1[i] != '\0');
		return i;
	}

	/*���� ����� ��������� ����-����� � �������
������� ����� � ������ ���o�, ��������� � ������� ������*/
	char* myFind_first_of(char* str1, char* str2, int pos) {
		int i = pos;
		do {
			int j = 0;
			do {
				if (str1[i] == str2[j])
					return &str1[i];
				++j;
			} while (str2[j] != '\0');
			++i;
		} while (str1[i] != '\0');
		return NULL;
	}

	//������� ����� ��������������� ��� �� �������
	int myCompare(char* str1, char* str2) {
		int i = 0;
		while ((str1[i] != '\0') || (str2[i] != '\0')) {
			if ((str1[i] > str2[i]) || (str2[i] == '\0'))
				return 1;
			else if ((str1[i] < str2[i]) || (str1[i] == '\0'))
				return -1;
			++i;
		}
		return 0;
	}