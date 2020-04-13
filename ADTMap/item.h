#pragma once

typedef struct item {
	int code;
	char description[51];
	double price;
} Item;

Item itemCreate(int code, char *description, double price);
void itemPrint(Item *ptItem);
