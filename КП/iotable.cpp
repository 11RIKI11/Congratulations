#include "iotable.h"
#include "itable.h"
#include "otable.h"
#include "validation.h"
#include "menu.h"
#include "main.h"
#include <string.h>
#include <stdio.h>

//List* getLastEl(List* beg) {
//	List* temp = beg;
//	for (; temp->right != NULL; temp = temp->right);
//	return temp;
//}
//List* sort(List* top, int start, int end) {
//	if (start > end) return;
//	if (top == NULL) return;
//	List* leftMid = top, *rightMid = top;
//	int mid = start + (end - start) / 2;
//	top->left = sort(top)
//}


int compareElByField(Factory factory1, Factory factory2, int field) {
	switch (field) {
	case 1:
		if (strcmp(factory1.factoryNumb, factory2.factoryNumb) > 0) 
			return 1;
		else if (strcmp(factory1.factoryNumb, factory2.factoryNumb) < 0)
			return -1;
		else 
			return 0;
	case 2:
		if (strcmp(factory1.branchNumb, factory2.branchNumb) > 0)
			return 1;
		else if (strcmp(factory1.branchNumb, factory2.branchNumb) < 0)
			return -1;
		else
			return 0;
	case 3:
		if (strcmp(factory1.respSurname, factory2.respSurname) > 0)
			return 1;
		else if (strcmp(factory1.respSurname, factory2.respSurname) < 0)
			return -1;
		else
			return 0;
	case 4:
		if (factory1.costCountAtBegThePeriod > factory2.costCountAtBegThePeriod)
			return 1;
		else if (factory1.costCountAtBegThePeriod < factory2.costCountAtBegThePeriod)
			return -1;
		else
			return 0;
	case 5:
		if (factory1.receivedCost > factory2.receivedCost)
			return 1;
		else if (factory1.receivedCost < factory2.receivedCost)
			return -1;
		else
			return 0;
	case 6:
		if (factory1.droppedCost > factory2.droppedCost)
			return 1;
		else if (factory1.droppedCost < factory2.droppedCost)
			return -1;
		else
			return 0;
	default:
		printf("Поле не найдено");
		return -2;
	}
}

void sortTableByField(List*& beg, int field, int direction) {
	List* prov = beg;
	for (; prov->right != NULL; prov = prov->right);
	for (; prov != NULL; prov = prov->left) {
		bool resCompare;
		Factory factory = prov->inf;
		for (List* walk = beg; walk != prov; walk = walk->right) {
			if (direction == 1) {
				resCompare = compareElByField(walk->inf, walk->right->inf, field) == 1 ? true : false;
			}
			else {
				resCompare = compareElByField(walk->inf, walk->right->inf, field) == -1 ? true : false;
			}
			if (resCompare) {
				List* temp = walk->left;
				walk->left = walk->right;
				if (temp != NULL && walk->right->right != NULL) {
					walk->left->left = temp;
					temp->right = walk->left;
					walk->right = walk->left->right;
					walk->left->right->left = walk;
					walk->left->right = walk;
				}
				else if (temp == NULL) {
					walk->left->left = temp;
					walk->right = walk->left->right;
					walk->left->right->left = walk;
					walk->left->right = walk;

					beg = walk->left;
				}
				else if (walk->right->right == NULL) {
					walk->left->left = temp;
					temp->right = walk->left;
					walk->left->right = walk;
					walk->right = NULL;
				}
				else {
					walk->left->left = temp;
					walk->left->right = walk;
					walk->right = NULL;
				}
				walk = walk->left;
				if (walk == prov) {
					prov = prov->right;
					break;
				}
				//else if(walk == prov->left);
			}
		}
	}
}

void sortTable(List*& beg) {
	if (beg == NULL || beg->right == NULL && beg->left == NULL) {
		printf("Таблица недостаточно заполнена, либо пуста...");
		return;
	}
	int field, direction;
	while (true) {
		field = printMenu(fieldMenu);
		if (field == 7) return;
		direction = printMenu(sortDirection);
		if (direction == 3) continue;
		break;
	}
	sortTableByField(beg, field, direction);
}

