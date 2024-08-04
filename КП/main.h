#pragma once
#define _CRT_SECURE_NO_WARNINGS
//#include "itable.h"
//#include "otable.h"
//#include "menu.h"
//#include "validation.h"
//#include "menu.h"
//#ifndef IO_TABLE_H
//#include "iotable.h"
//#endif
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//#include <conio.h>
#include <windows.h>


#define OUTPUT_FORMAT "|%14s|%15s|%21s|%36.2f|%36.2f|%36.2f|"

struct Factory {
	char factoryNumb[9];					// Номер завода
	char branchNumb[9];						// Номер филиала
	char respSurname[21];					// Фамилия ответственного за материальные ценности
	double costCountAtBegThePeriod;		    // Наличие материальных ценностей на начало периода
	double receivedCost;					// Полученно материальных ценностей на сумму
	double droppedCost;						// Выбыло на сумму
};

struct List {
	Factory inf;
	List* left;
	List* right;
};

