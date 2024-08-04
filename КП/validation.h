#pragma once
#ifndef VALIDATION_H
#define VALIDATION_H

void validateFio(char* str, int strLen);
void validateDouble(double& number);
void validateInt(int& number);
void validateNumb(char* str, int strLen);
bool askQuestion(char answer1, char answer2);
void validate(char* str, int strLen);
bool checkNumb(char* str);
bool checkDouble(char* str);
bool checkFio(char* str);

#endif