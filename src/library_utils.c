#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "library_utils.h"
#include "../main.h"

extern int ID;

void add_book(struct Books *books, char *title, char *author, int pages, int year)
{
    books->books[ID].set = 1;
    books->books[ID].id = ID;
    strcpy(books->books[ID].title, title);
    strcpy(books->books[ID].author, author);
    books->books[ID].pages = pages;
    books->books[ID].year_published = year;

    printf("\nBook successfully added!\n\n\n");

    ID++;
}

void read_books(struct Books *books)
{
    fread(&books->books, (sizeof(struct Book) * MAX_BOOKS), 1, books->fp);

    int i;
    printf("\n\nID\t\tTITLE\t\tAUTHOR\t\tPAGES\t\tYEAR_PUBLISHED\n");

    for (i = 0; i < MAX_BOOKS; i++) {
        if (books->books[i].set == 1) {
            fprintf(stdout, "%d.\t\t%s\t\t%s\t\t%d\t\t%d\n",
                books->books[i].id,
                books->books[i].title,
                books->books[i].author,
                books->books[i].pages,
                books->books[i].year_published
            );
        }
    }

    printf("\n\n");
}

void delete_book(struct Books *books, int id)
{
    if (books->books[id].set != 0) {
        books->books[id].set = 0;
    }

    printf("\nBook successfully deleted!\n\n\n");
}

void edit_book(struct Books *books, int id, char *title, char *author, int pages, int year)
{
    if (books->books[id].set != 1) {
        printf("Unable to find book");

        return;
    }

    strcpy(books->books[id].title, title);
    strcpy(books->books[id].author, author);
    books->books[id].pages = pages;
    books->books[id].year_published = year;

    printf("\n%s has been editted\n\n\n", books->books[id].title);
}

void write(struct Books *books)
{
    rewind(books->fp);
    int rc = fwrite(&books->books, (sizeof(struct Book) * MAX_BOOKS), 1, books->fp);

    if (!rc) {
        die("Unable to write to file");
    }
}
