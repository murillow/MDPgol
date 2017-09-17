#include <bits/stdc++.h>

using namespace std;

#define MAX_STATES 21
#define MAX_CHARSET 15

int sigma[MAX_STATES][MAX_CHARSET];

inline int charToCol(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
		return 0;
	} else if (c >= 48 && c <= 57) {
		return 1;
	} else if (c >= 40 && c <= 47) {
		return c - 38;
	} else if (c >= 60 && c <= 62) {
		return c - 50;
	} else if (c == 59) {
		return 13;
	} else {
		return 14;
	}
}

int main() {
	char c = '/';
	cout << charToCol(c) << endl;
	return 0;
}