#pragma once
#ifndef OTABLE_H
#define OTABLE_H
#include "main.h"

void viewTable(List* beg, const int elNumb);
int viewPage(List* point, const int page, const int elNumb);   //Вывод страницы page считая от point c elNumb элементов на странице
void deleteRecord(List*& beg); //Удаление записи по номеру филиала
int SeveInFile(List* beg);
int SeveInBinFile(List* beg);
#endif