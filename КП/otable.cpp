#include "otable.h"
#include "validation.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

void deleteRecordByField(List*& beg) {
	if (beg == NULL) {
		printf("Таблица пуста\n");
		return;
	}
	List* temp = beg;
	printf("Введите номер удаляемой записи:\n");
	int N;
	validateInt(N);
	while (N) {
		temp = beg;
		if (temp->right == NULL && temp->left == NULL && N == 1) {
			printf("Запись удалена\n");
			free(temp);
			return;
		}
		for (int i = 2; temp->right != NULL; temp = temp->right, i++) {
			if (i == N) {
				if (temp->left == NULL && temp->right == NULL) {
					free(temp);
					printf("Запись удалена\n");
					break;
				}
				else if (temp->right == NULL) {
					temp->left->right = temp->right;
					free(temp);
					printf("Запись удалена\n");
					break;
				}
				else {
					temp->left->right = temp->right;
					temp->right->left = temp->left;
					free(temp);
					printf("Запись удалена\n");
				}
			}
		}
		printf("Записи с заданным номером не найдено");
	}
}
//	return;
//}

void viewTable(List* beg, const int elNumb) {
	if (beg == NULL) {
		printf("Таблица пуста");
		return;
	}
	int currentPage = 1;
	List* temp = beg;
	int res;
	while (true) {
		res = viewPage(temp, currentPage, elNumb);
		switch (res) {
		case 0:
			printf("Клавиша ESC - Выход\n");
			while (true) {
				_getch();
				if (GetAsyncKeyState(VK_ESCAPE)) {
					keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
					system("cls");
					return;
				}
			}
			system("cls");
			return;
		case 1:
			printf("Клавиша ВЛЕВО - Перелестнуть назад\n Клавиша ВПРАВО - Перелестнуть вперёд\n Клавиша ESC - Выход\n");
			while (true) {
				_getch();
				if (GetAsyncKeyState(VK_LEFT)) {
					keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
					Sleep(150);
					system("cls");
					currentPage--;
					break;
				}
				else if (GetAsyncKeyState(VK_RIGHT)) {
					keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
					Sleep(150);
					system("cls");
					currentPage++;
					break;
				}
				else if (GetAsyncKeyState(VK_ESCAPE)) {
					keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
					system("cls");
					return;
				}
			}
			break;
		case 2:
			printf("Клавиша ВЛЕВО - Перелестнуть назад\n Клавиша ESC - Выход\n");
			while (true) {
				_getch();
				if (GetAsyncKeyState(VK_LEFT)) {
					keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
					Sleep(150);
					system("cls");
					currentPage--;
					break;
				}
				else if (GetAsyncKeyState(VK_ESCAPE)) {
					keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
					system("cls");
					return;
				}
			}
			break;
		case 3:
			printf("Клавиша ВПРАВО - Перелестнуть вперёд\n Клавиша ESC - Выход\n");
			while (true) {
				_getch();
				if (GetAsyncKeyState(VK_RIGHT)) {
					keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
					Sleep(150);
					system("cls");
					currentPage++;

					break;
				}
				else if (GetAsyncKeyState(VK_ESCAPE)) {
					keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
					system("cls");
					return;
				}
			}
			break;
		}
	}
}

int viewPage(List* point, const int page, const int elNumb) {
	if (page <= 0) {
		printf("Неверно задан номер страницы");
		return -1;
	}
	if (point == NULL) {
		printf("Позиция пуста");
		return -1;
	}
	int fl = 0,  i = 1;
	printf("_________________________________________________________________________________________________________________________________________________________________________\n");
	printf("| N | Номер завода | Номер филиала | Фамилия             | Суммарная стоимость мат. ценностей | Суммарная стоимость мат. ценностей | Суммарная стоимость мат. ценностей |\n");
	printf("|   |              |               | ответственного лица | на начало периода                  | полученных за период               | выбывших за период                 |\n");
	printf("_________________________________________________________________________________________________________________________________________________________________________\n");
	do {
		if (i > (page-1) * elNumb && i <= elNumb * page) {
			printf("|%3d|%14s|%15s|%21s|%36.2f|%36.2f|%36.2f|\n", i, point->inf.factoryNumb, point->inf.branchNumb, point->inf.respSurname,
				point->inf.costCountAtBegThePeriod, point->inf.receivedCost, point->inf.droppedCost);
			fl = 1;
		}
		else if (i > elNumb * page) {
			break;
		}
		if (point->right == NULL) {
			break;
		}
		i++;
		point = point->right;
	} while (true);
	printf("_________________________________________________________________________________________________________________________________________________________________________\n");
	if (point->right == NULL || point == NULL) {
		if (page == 1) {
			return 0;
		}
		return 2;
	}
	else if ((i-1)%elNumb == 0 && page > 1) {
		return 1;
	}
	else if ((i-1)%elNumb == 0 && page == 1) {
		return 3;
	}
}


int SeveInFile(List* beg) {
	printf("Seve in txt file");
	return 1;
}
int SeveInBinFile(List* beg) {
	printf("Save in bin file");
	return 1;
}