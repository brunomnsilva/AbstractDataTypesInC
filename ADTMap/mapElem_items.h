#pragma once

#include "item.h"
#include <stdbool.h>

typedef int MapKey;
typedef Item MapValue;

void mapKeyPrint(MapKey key);
void mapValuePrint(MapValue value);

bool mapKeyEquals(MapKey key1, MapKey key2);
