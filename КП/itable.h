#pragma once
#ifndef ITABLE_H
#define ITABLE_H
#include "main.h"
#include <stdio.h>

List* createTable(List* beg); // �������� ������� �� �����
void addRecord(List* &beg, Factory data);   // ���������� ����� ������ � �������
List* readOutFile(List* beg, FILE* file);
List* readOutTxtFile(List* beg, char* fileName);// ������ ������ �� �����;
Factory readData();			  // ������ ������

#endif