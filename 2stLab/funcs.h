#pragma once
#ifndef FUNCS_H
#define FUNCS_H

void arrClear(char*);
void funcCheck(char*, char*, char*);
void funcIn(char*, char*, int);
int menuInput(char*, char*);
int myStrlen(const char*);
char* myStrcat(char*, const char*);
char* myStrncat(char*, const char*, int);
int myStrcmp(const char*, const char*);
int myStrncmp(const char*, const char*, int);
char* myStrcpy(char*, const char*);
char* myStrncpy(char*, const char*, int);
char* myStrcpy_s(char*, char*, int);
char* myStrchr(char*, int);
char* myStrstr(char*, char*);
char* myFind_last_of(char*, char*, int);
char* myFind_first_not_of(char*, char*, int);
char* myPop_back(char*);
char* myStrpbrk(char*, const char*);
int myStrspn(const char*, const char*);
int myStrcspn(const char*, const char*);
char* myFind_first_of(char*, char*, int);
int myCompare(char*, char*);

#endif
