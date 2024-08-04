#pragma once
#ifndef IOTABLE_H
#define IOTABLE_H
#include "main.h"
#include "itable.h"
#include "otable.h"

void correctRecord(List*& beg);
void sortTable(List*& beg);
void searchRecords(List*& beg);
void createStatement(List*& beg); //Создать ведомоcть движения материальных ценностей за период

#endif