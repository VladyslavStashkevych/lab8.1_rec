// lab8.1_rec.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 8.1
// Опрацювання багатовимірних масивів ітераційними та рекурсивними способами
// Варіант 19

// abccabbcanbmcnacnb

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Check(char* str, const char* strC, int counter, bool& b,  int i, int j);
char* Change(char* str, char* tmp, char* t, int k, int* indexArr, size_t len, size_t i);
int Count(char* str, const char* strC, int* indexArr, int counter, int k, bool b, int i);

int main() {
	char str[101];
	int  count = 0;
	int* arr = new int[34];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	count = Count(str, "abc", arr, count, 0, false, 0);
	cout << "String contained " << count << " groups of 'a', 'b', 'c'" << endl;

	char* tmp = new char[strlen(str) * 2 / 3 + 1];
	char* dest = new char[101];
	char* t = tmp;
	tmp[0] = '\0';
	size_t len = strlen(str);

	cout << "Modified string (param) : " << str << endl;
	dest = Change(str, tmp, t, 0, arr, len, 0);
	cout << "Modified string (result): " << dest << endl;

	return 0;
}

int Check(char* str, const char* strC, int counter, bool &b, int i, int j) {
	if (j > 2)
		return counter;
	if (str[i] == strC[j]) {
		b = true;
		counter++;
	}
	return Check(str, strC, counter, b,  i, j + 1);
}

int Count(char* str, const char* strC, int* indexArr, int counter, int k, bool b, int i) {
	if (strlen(str) < 3)
		return 0;
	if (str[i] == 0)
		return counter / 3;

	counter = Check(str, strC, counter, b, i, 0);
	if (counter != 0) {
		if (!b) {
			counter -= counter % 3;
		}
		else if (counter % 3 == 0) {
			indexArr[k] = i - 2;
			k++;
		}
	}

	return Count(str, strC, indexArr, counter, k, false, i + 1);

	
}

char* Change(char* str, char* tmp, char* t, int k, int* indexArr, size_t len, size_t i) {
	if (len < 3)
		return str;
	if (i < len && str[i] != 0) {
		if (i == indexArr[k]) {
			strcat(t, "**");
			t += 2;
			i += 2;
			k++;
		}
		else {
			*t++ = str[i];
			*t = '\0';
		}
		return Change(str, tmp, t, k, indexArr, len, i + 1);
	}
	else {
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		strcpy(str, tmp);
		return tmp;
	}
}