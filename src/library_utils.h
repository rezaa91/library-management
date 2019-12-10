#ifndef LIBRARY_UTILS_H_
#define LIBRARY_UTILS_H_

#include <stdio.h>

#include "../main.h"

extern struct Books *books;

void add_book(struct Books *books, char *title, char *author, int pages, int year);
void edit_book(struct Books *books, int id, char *title, char *author, int pages, int year);
void delete_book(struct Books *books, int id);
void read_books(struct Books *books);
void write(struct Books *books);

#endif
