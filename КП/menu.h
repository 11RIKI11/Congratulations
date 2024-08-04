#pragma once
#ifndef MENU_H
#define MENU_H

extern const char* mainMenu[];
extern const char* fieldMenu[];
extern const char* sortDirection[];
extern const char* creatingMenu[];
extern const char* choseTypeOfFileMenu[];

int printMenu(const char** menu);
void moveStdCursor(int X, int Y);

#endif
