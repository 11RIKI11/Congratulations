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
	char factoryNumb[9];					// ����� ������
	char branchNumb[9];						// ����� �������
	char respSurname[21];					// ������� �������������� �� ������������ ��������
	double costCountAtBegThePeriod;		    // ������� ������������ ��������� �� ������ �������
	double receivedCost;					// ��������� ������������ ��������� �� �����
	double droppedCost;						// ������ �� �����
};

struct List {
	Factory inf;
	List* left;
	List* right;
};

