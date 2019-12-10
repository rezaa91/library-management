#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int ID;

#include "main.h"
#include "src/debug.h"
#include "src/main_menu.h"
#include "src/file.h"
#include "src/library_utils.h"

int main()
{
    Books *books = init_file();

    read_books(books);
    printf("Set ID:");
    scanf("%d", &ID);
    getchar();

    while(true) {
        display_main_menu();
        char selectedOption = getchar();

        int id, pages, year;
        char title[MAX_DATA], author[MAX_DATA];

        switch ((int) selectedOption - '0') {
            case READ:
                read_books(books);
                selectedOption = getchar();
                break;


            case ADD:
                printf("title: ");
                scanf("%s", title);
                printf("author: ");
                scanf("%s", author);
                printf("pages: ");
                scanf("%d", &pages);
                printf("year published: ");
                scanf("%d", &year);

                add_book(books, title, author, pages, year);
                write(books);
                selectedOption = getchar();
                break;


            case REMOVE:
                printf("Which book would you like to delete (id): ");
                scanf("%d", &id);

                delete_book(books, id);
                write(books);
                selectedOption = getchar();
                break;


            case EDIT:
                printf("Which book would you like to edit (id): ");
                scanf("%d", &id);
                printf("title: ");
                scanf("%s", title);
                printf("author: ");
                scanf("%s", author);
                printf("pages: ");
                scanf("%d", &pages);
                printf("year published: ");
                scanf("%d", &year);

                edit_book(books, id, title, author, pages, year);
                write(books);
                selectedOption = getchar();
                break;


            default:
                fprintf(stderr, "\n\n***************INVALID OPTION****************\n\n\n");
        }
    }

    free_memory(books);

    return 0;
}
