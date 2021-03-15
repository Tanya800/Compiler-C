#pragma once
#include<stdio.h>
#include<ctype.h>

#define BSIZE 128 //размер буфера
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257 
#define MOD 258
#define ID 259
#define DONE 260

extern int tokenval;//значение атрибута токета
extern int lineno;

struct entry{ //запись в таблице символов
	char *lexptr;
	int token;
};

extern struct entry symtable[]; //таблица символов
