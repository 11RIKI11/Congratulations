#pragma once
#ifndef OTABLE_H
#define OTABLE_H
#include "main.h"

void viewTable(List* beg, const int elNumb);
int viewPage(List* point, const int page, const int elNumb);   //����� �������� page ������ �� point c elNumb ��������� �� ��������
void deleteRecord(List*& beg); //�������� ������ �� ������ �������
int SeveInFile(List* beg);
int SeveInBinFile(List* beg);
#endif