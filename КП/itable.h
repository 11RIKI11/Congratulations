#pragma once
#ifndef ITABLE_H
#define ITABLE_H
#include "main.h"
#include <stdio.h>

List* createTable(List* beg); // Создание таблицы из файла
void addRecord(List* &beg, Factory data);   // Добавление новой записи в таблицу
List* readOutFile(List* beg, FILE* file);
List* readOutTxtFile(List* beg, char* fileName);// Чтение данных из файла;
Factory readData();			  // Чтение данных

#endif