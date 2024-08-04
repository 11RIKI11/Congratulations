#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "menu.h"

extern const char* mainMenu[] = { "������� ����:", "1) �������� �������.", "2) �������� �������.", "3) ���������� ����� ������ � �������.", "4) �������� ������",
	"5) ������������� ������ � �������", "6) ���������� �������", "7) ����� ������ � �������", "8) ���������� ������� � �����",
	"9) ������ ������ �� �����", "10) ��������� ������� � �������� ����������� ���������", "11) �����" };
extern const char* fieldMenu[] = { "�������� ����, �� ������� ���������� ���������� ��������:", "1) ����� ������", "2) ����� �������",
"3) ������� �������������� ����", "4) ��������� ��������� ���. ��������� �� ������ �������",
"5) ��������� ��������� ���. ��������� ���������� �� ������", "6) ��������� ��������� ���. ��������� �������� �� ������", "7) �����" };
extern const char* sortDirection[] = { "�������� � ����� ����������� ���������� ����������:", "1) �� �����������",
		"2) �� ��������", "3) �����" };
extern const char* creatingMenu[] = { "�������� ��������:", "1) �������� ����� �������", "2) ��������� ������� �� �����", "3) �����"};
extern const char* choseTypeOfFileMenu[] = { "��������, � ����� ������ ���������� ���������� ��������:", "1) ��������� ����", "2) �������������� ����", "3) �����" };

int printMenu(const char** menu) {
	int activemenu = 1;
	int menulen = 1;
	for (int i = 1; menu[i] != NULL; i++) {
		if (strchr("0123456789", menu[i][0]) == NULL)
			break;
		menulen++;
	}
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int i = 0; i < menulen; i++) {
		if (i == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("%s\n", menu[i]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			continue;
		}
		printf("%s\n", menu[i]);
	}
	GetAsyncKeyState(VK_RETURN);
	GetAsyncKeyState(VK_UP);
	GetAsyncKeyState(VK_DOWN);
	while (true) {
		_getch();
		if (GetAsyncKeyState(VK_UP)) {
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
			moveStdCursor(0, activemenu);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("%s\n", menu[activemenu]);
			activemenu--;
			if (activemenu == 0) {
				activemenu = menulen - 1;
				moveStdCursor(0, 12);
			}
			moveStdCursor(0, activemenu);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("%s\n", menu[activemenu]);
			Sleep(150);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
			moveStdCursor(0, activemenu);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			printf("%s\n", menu[activemenu]);
			activemenu++;
			if (activemenu == menulen) {
				activemenu = 1;
				moveStdCursor(0, 1);
			}
			moveStdCursor(0, activemenu);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
			printf("%s\n", menu[activemenu]);
			Sleep(150);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		else if (GetAsyncKeyState(VK_RETURN)) {
			keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			return activemenu;
		}
	}
}
void moveStdCursor(int posX, int posY) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = posX;
	cursorPosition.Y = posY;
	SetConsoleCursorPosition(console, cursorPosition);
}

