#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>

#define MAX_DATA 512
#define MAX_BOOKS 50

typedef struct Book {
    int set;
    int id;
    char title[MAX_DATA];
    char author[MAX_DATA];
    int pages;
    int year_published;
} Book;

typedef struct Books {
    FILE *fp;
    Book books[MAX_BOOKS];
} Books;

enum menu_options {READ = 1, ADD, REMOVE, EDIT};

#endif
