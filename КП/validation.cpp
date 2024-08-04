#include "validation.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void validateFio(char* str, int strLen) {
	char c;
	for (int i = 0; i < strLen; i++) {
		c = _getch();
		if (c == '\n' || c == '\r') {
			str[i] = '\0';
			break;
		}
		else if (c == 8) {
			if (i == 0) {
				--i;
				continue;
			}

			i--;
			str[i] = '\0';
			i--;
		}
		else if (i == strLen - 1) {
			i -= 1;
			continue;
		}
		else {
			if (strchr("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", c) != NULL 
				&& strchr("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", str[0]) != NULL || i == 0) {
				str[i] = c;
				str[i + 1] = '\0';
			}
			else if (strchr("éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ", c) != NULL 
				&& strchr("éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ", str[0]) != NULL || i == 0) {
				str[i] = c;
				str[i + 1] = '\0';
			}
			else {
				i--;
				str[i + 1] = '\0';
			}
		}

		printf("\r");
		for (int j = 0; j < strLen; ++j)
			printf("%c", ' ');
		printf("\r%s", str);
		fflush(stdin);
	}
}


void validateDouble(double& number) {
	int N = 10;
	char* str = new char[N];
	char c;
	bool point = false;
	for (int i = 0; i < N; i++) {
		c = _getch();
		if (c == '\n' || c == '\r') {

			str[i] = '\0';
			break;
		}
		else if (c == 8) {
			if (i == 0) {
				--i;
				continue;
			}
			--i;
			if (str[i] == '.') {
				point = false;
			}
			str[i] = '\0';
			--i;
		}
		else if (i == N - 1) {
			i -= 1;
			continue;
		}
		else {
			if ((c == '.' && !point) || strchr("1234567890", c) != NULL) {
				if (c == '.') {
					point = true;
				}
				str[i] = c;
				str[i + 1] = '\0';
			}
			else {
				i--;
				str[i + 1] = '\0';
			}
		}

		printf("\r");
		for (int j = 0; j < N; ++j)
			printf("%c", ' ');
		printf("\r%s", str);
		fflush(stdin);
	}
	number = atof(str);
	printf("\n");
	delete[] str;
}

void validateNumb(char* str, int strLen) {
	char c;
	for (int i = 0; i < strLen; i++) {
		c = _getch();
		if (c == '\n' || c == '\r') {
			if (i != strLen - 1) {
				--i;
				continue;
			}

			str[i] = '\0';
			break;
		}
		else if (c == 8) {
			if (i == 0) {
				--i;
				continue;
			}

			--i;
			str[i] = '\0';
			--i;
		}
		else if (i == strLen - 1) {
			i -= 1;
			continue;
		}
		else {
			if (strchr("0123456789", c) != NULL) {
				str[i] = c;
				str[i + 1] = '\0';
			}
			else {
				i--;
				str[i + 1] = '\0';
			}
		}

		printf("\r");
		for (int j = 0; j < strLen; ++j)
			printf("%c", ' ');
		printf("\r%s", str);
		fflush(stdin);
	}
}

void validateInt(int& number) {
	int N = 10;
	char* str = new char[N];
	char c;
	for (int i = 0; i < N; i++) {

		c = _getch();
		if (c == '\n' || c == '\r') {

			str[i] = '\0';
			break;
		}
		else if (c == 8) {
			if (i == 0) {
				--i;
				continue;
			}

			--i;
			str[i] = '\0';
			--i;
		}
		else if (i == N - 1) {
			i -= 1;
			continue;
		}
		else {
			if (strchr("1234567890", c) != NULL) {
				str[i] = c;
				str[i + 1] = '\0';
			}
			else {
				i--;
				str[i + 1] = '\0';
			}
		}

		printf("\r");
		for (int j = 0; j < N; ++j)
			printf("%c", ' ');
		printf("\r%s", str);
		fflush(stdin);
	}
	number = atoi(str);
	printf("\n");
	delete[] str;
}

bool askQuestion(char answer1, char answer2) {
	char c;
	do {
		c = _getch();
		if (c == answer1) {
			return true;
		}
		else if (c == answer2) {
			return false;
		}
	} while (true);
}

void validate(char* str, int strLen) {
	char c;
	for (int i = 0; i < strLen; i++) {

		c = _getch();
		if (c == '\n' || c == '\r') {
			str[i] = '\0';
			break;
		}
		else if (c == 8) {
			if (i == 0) {
				--i;
				continue;
			}

			i--;
			str[i] = '\0';
			i--;
		}
		else if (i == strLen - 1) {
			i -= 1;
			continue;
		}
		else {
			if (strchr("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMéöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ01234567890_", c) != NULL) {
				str[i] = c;
				str[i + 1] = '\0';
			}
			else {
				i--;
			}
		}

		printf("\r");
		for (int j = 0; j < strLen; ++j)
			printf("%c", ' ');
		printf("\r%s", str);
		fflush(stdin);
	}
}

bool checkNumb(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (strchr("0123456789", str[i]) == NULL) {
			return false;
		}
	}
	return true;
}

bool checkDouble(char* str) {
	bool point = false;
	for (int i = 0; i < strlen(str); i++) {
		if (strchr("0123456789.", str[i]) == NULL) {
			return false;
		}
		if ((str[i] == '.' && !point)) {
			point = true;
		}
		else if ((str[i] == '.' && point)) {
			return false;
		}
	}
	return true;
}

bool checkFio(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		if (strchr("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMéöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ", str[i]) == NULL) {
			return false;
		}
		if (strchr("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", str[i]) != NULL
			&& strchr("qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM", str[0]) == NULL) {
			return false;
		}
		else if (strchr("éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ", str[i]) != NULL
			&& strchr("éöóêåíãøùçõúôûâàïðîëäæýÿ÷ñìèòüáþÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜÁÞ", str[0]) == NULL ) {
			return false;
		}
	}
	return true;
}