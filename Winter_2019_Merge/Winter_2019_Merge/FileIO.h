#pragma once

#include <stdio.h>
#include "Node.h"

FILE *fp;

node* readFile(void);
int writeFile(node* outputData);