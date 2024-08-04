#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include "main.h"
#include "menu.h"
#include "iotable.h"
#include "validation.h"

/*
1) Начальное создание таблицы.При необходимости создания новой таблицы исходные данные считываются из текстового файла.Имя файла должен задавать пользователь.
2) Просмотр таблицы.При этом необходимо предусмотреть возможность+
скроллинга.+
3) Добавление новой записи в таблицу. +
4) Удаление записи.Удаляемый элемент выбирается по одному из полей +
таблицы(ключевому).Ключевое поле выбирает студент. +
5) Корректировка записи в таблице.Корректируемую запись выбирают по
одному из полей таблицы(ключевому).
6) Сортировка таблицы.Сортировка производится по одному из полей таблицы(ключевому).Метод сортировки выбирает студент.
7) Поиск записи в таблице(по не ключевому полю).
8) Сохранение таблицы в файле.Имя файла должен вводить пользователь.
Сохранять таблицу следует в текстовый файл и в типизированный.
9) Чтение данных из файла.Имя файла должен вводить пользователь.При
чтении данных необходимо создавать новый список.
10)Обработка таблицы и просмотр результатов обработки.Результат
обработки необходимо вывести на экран и в текстовый файл.Имя файла вводит
пользователь.
11) Выход ― завершение работы программы
*/

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int activemenu;
	List* table = NULL;
	char a[] = "tutu.txt";
	table = readOutTxtFile(table, a);

	char fileName[30];
	FILE* file;
	while (true) {
		moveStdCursor(0, 0);
		activemenu = printMenu(mainMenu);
		switch (activemenu) {
		case 1:
			//system("cls");
			//createTable(table);
			system("pause");
			break;
		case 2:
			viewTable(table, 10); //+
			system("pause");
			break;
		case 3:
			system("cls");
			addRecord(table, readData()); //+
			system("pause");
			break;
		case 4:
			system("cls");
			//deleteRecord(table); //+
			system("pause");
			break;
		case 5:
			system("cls");
			printf("Корректировка таблицы");
			system("pause");
			break;
		case 6:
			system("cls");
			sortTable(table);
			system("pause");
			break;
		case 7:
			system("cls");
			printf("Поиск записи в таблице");
			system("pause");
			break;
		case 8:
			system("cls");
			SeveInFile(table);
			SeveInBinFile(table);
			system("pause");
			break;
		case 9:
			system("cls");
			//table = readOutFile(table, file);
			system("pause");
			break;
		case 10:
			system("cls");
			printf("Обрабока таблицы");
			system("pause");
			break;
		case 11:
			system("cls");
			printf("Выход...");
			return 0;
		}
		fflush(stdin);
	}
}

//int Menu() {
//	system("cls");
//	int activemenu = 0;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//	printf("Меню:\n");
//	while (true) {
//		system("cls");
//		for (int i = 0; i < menulen; i++) {
//			if (i == activemenu) {
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//				printf("%s\n", menu[i]);
//			}
//			else {
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//				printf("%s\n", menu[i]);
//			}
//			//printf("%s%s", menu[i], i == activemenu ? "<-" : " ");
//		}
//		while (true) {
//			if (GetAsyncKeyState(VK_UP)) {
//				Sleep(150);
//				activemenu--;
//				if (activemenu == -1) {
//					activemenu = menulen - 1;
//				}
//				break;
//			}
//			else if (GetAsyncKeyState(VK_DOWN)) {
//				Sleep(150);
//				activemenu++;
//				if (activemenu == menulen) {
//					activemenu = 0;
//				}
//				break;
//			}
//			else if (GetAsyncKeyState(VK_RETURN)) {
//				Sleep(150);
//				return activemenu;
//			}
//		}
//	}
//}
//
//
