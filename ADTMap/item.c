#include "item.h"
#include <stdio.h>
#include <string.h>

Item itemCreate(int code, char *description, double price) {
	Item it;

	it.code = code;
	strcpy(it.description, description);
	it.price = price;

	return it;
}

void itemPrint(Item *_this) {
	printf("Item {code: %d, description: %s, price: %.2f} \n", _this->code, _this->description, _this->price);
}