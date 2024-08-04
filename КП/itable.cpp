#include "itable.h"
#include "validation.h"
#include "menu.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


Factory readData() {
	Factory factory;
	printf("Введите номер завода: \n");
	validateNumb(factory.factoryNumb, sizeof(factory.factoryNumb));
	system("cls");
	printf("Введите номер филиала: \n");
	validateNumb(factory.branchNumb, sizeof(factory.branchNumb));
	system("cls");
	printf("Введите фамилию ответственного за мат. ценности: \n");
	validateFio(factory.respSurname, sizeof(factory.respSurname));
	system("cls");
	printf("Введите стоимость мат. ценностей на начало периода: \n");
	validateDouble(factory.costCountAtBegThePeriod);
	system("cls");
	printf("Введите стоимость полученный мат. ценностей в течении периода: \n");
	validateDouble(factory.receivedCost);
	system("cls");
	printf("Введите стоимость выбывших мат. ценностей в течении периода: \n");
	validateDouble(factory.droppedCost);
	system("cls");
	return factory;
}

void addRecord(List* &beg, Factory data) {
	List* newRecord = (List*)malloc(sizeof(List));
	if (beg == NULL) {
		newRecord->right = NULL;
		newRecord->left = NULL;
		newRecord->inf = data;
		beg = newRecord;
		return;
	}
	List* temp = beg;
	for (; temp->right != NULL; temp = temp->right);
	newRecord->right = NULL;
	newRecord->left = temp;
	newRecord->inf = data;
	temp->right = newRecord;
	return;
}

char* strCopy(char* Dest, const char* Sourse, int n, int k) {
	if (n >= k) {
		return Dest;
	}
	int i;
	int size = sizeof(Dest);
	for (i = 0; i < strlen(Dest) && i < k - n; i++) {
		Dest[i] = Sourse[i + n];
	}
	Dest[i] = '\0';
	return Dest;
}

List* createTable(List* &beg) {
	int activemenu = printMenu(creatingMenu);
	switch (activemenu) {
	case 1:
		while (true) {
			addRecord(beg, readData());
			printf("Добавить ещё элемент (Y - да / N - нет\n");
			if (!askQuestion('Y', 'N')) continue;
			break;
		}
		break;
	case 2:
		//beg = readOutFile(beg);
		break;
	}
	return beg;
}

List* readOutFile(List* beg) {
	char fileName[30];
	printf("Введите имя файла, в котором находится таблица. Имя требуется ввести без расширения\n-->");
	validate(fileName, sizeof(fileName));
	return beg;
}

List* readOutBinFile(List* beg, char* fileName) {
	FILE* file = fopen(fileName, "rb");
	if (file == NULL) {
		printf("Отказано в доступе, файл не найден или не существует");
		return beg;
	}
}

List* readOutTxtFile(List* beg, char* fileName) {
	FILE* file = fopen(fileName, "rt");
	Factory factory;
	if (file == NULL) {
		printf("Отказано в доступе, файл не найден или не существует");
		return beg;
	}
	for (char c = getc(file), count = 0; count != 4; c = getc(file)) {
		if (c == '\n') count++;
		if (c == EOF) {
			printf("Файл недостаточно заполнен\n");
			fclose(file);
			return NULL;
		}
	}

	while (!feof(file)) {
		char row[200], field[30];
		fgets(row, 200, file);

		int i = 4, n = -1, curField = 0;

		int condition = 1;
		if (row[i] == '|') i++;
		for (; strlen(row) && row[i] != '\n'; i++) {
			if (row[i] == ' ') continue;
			if (row[i] != ' ' && row[i] != '|' && n < 0) {
				n = i;
				continue;
			}
			if (row[i] == '|') {
				curField++;
				strCopy(field, row, n, i);
				n = -1;
				switch (curField) {
				case 1:
					if (!checkNumb(field)) {
						condition = 0;
						break;
					}
					strcpy(factory.factoryNumb, field);
					break;
				case 2:
					if (!checkNumb(field)) {
						condition = 0;
						break;
					}
					strcpy(factory.branchNumb, field);
					break;
				case 3:
					if (!checkFio(field)) {
						condition = 0;
						break;
					}
					strcpy(factory.respSurname, field);
					break;
				case 4:
					if (!checkDouble(field)) {
						condition = 0;
						break;
					}
					factory.costCountAtBegThePeriod = atof(field);
					break;
				case 5:
					if (!checkDouble(field)) {
						condition = 0;
						break;
					}
					factory.receivedCost = atof(field);
					break;
				case 6:
					if (!checkDouble(field)) {
						condition = 0;
						break;
					}
					factory.droppedCost = atof(field);
					break;
				}
			}
			if (!condition) {
				curField--;
				break;
			}
		}
		if (curField < 6) {
			continue;
		}
		addRecord(beg, factory);
	}
	printf("Данные из файла '%s' были успешно считыны\n", fileName);
	fclose(file);
	return beg;
}
