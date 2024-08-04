#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "menu.h"

extern const char* mainMenu[] = { "Главное меню:", "1) Создание таблицы.", "2) Просмотр таблицы.", "3) Добавление новой записи в таблицу.", "4) Удаление записи",
	"5) Корректировка записи в таблице", "6) Сортировка таблицы", "7) Поиск записи в таблице", "8) Сохранение таблицы в файле",
	"9) Чтение данных из файла", "10) Обработка таблицы и просмотр результатов обработки", "11) Выход" };
extern const char* fieldMenu[] = { "Выберите поле, по кторому необходимо произвести действие:", "1) Номер завода", "2) Номер филиала",
"3) Фамилия ответственного лица", "4) Суммарная стоимость мат. ценностей на начало периода",
"5) Суммарная стоимость мат. ценностей полученных за период", "6) Суммарная стоимость мат. ценностей выбывших за период", "7) Выход" };
extern const char* sortDirection[] = { "Выберите в каком направлении произвести сортировку:", "1) По возрастанию",
		"2) По убыванию", "3) Назад" };
extern const char* creatingMenu[] = { "Выберите действие:", "1) Создание новой таблицы", "2) Загрузить таблицу из файла", "3) Выход"};
extern const char* choseTypeOfFileMenu[] = { "Выберите, с каким файлом необходимо произвести действие:", "1) Текстовый файл", "2) Типизированный файл", "3) Выход" };

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

