#ifndef INIT_FILE_H_
#define INIT_FILE_H_

#include <stdio.h>

#include "../main.h"

struct Books *init_file(void);
void free_memory(struct Books *books);

#endif
