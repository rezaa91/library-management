#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "file.h"
#include "../main.h"

struct Books *init_file()
{
    struct Books *books = malloc(sizeof(struct Books));

    if (!books) {
        die("Memory error");
    }

    const char *filename = "data/library";

    if ((books->fp = fopen(filename, "r")) == NULL) {
        books->fp = fopen(filename, "w+"); // create file if it does not exist
    }

    books->fp = fopen(filename, "r+");

    if (!books->fp) {
        die("Unable to open file");
    }

    return books;
}

void free_memory(struct Books *books)
{
    if (books) {
        if (books->fp) {
            fclose(books->fp);
        }

        free(books);
    }
}
