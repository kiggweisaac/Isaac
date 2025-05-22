#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book Q;
    FILE *file;

    printf("Enter book title: ");
    fgets(Q.title, sizeof(Q.title), stdin);

    printf("Enter author name: ");
    fgets(Q.author, sizeof(Q.author), stdin);

    printf("Enter price: ");
    scanf("%f", &Q.price);

    file = fopen("book.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "%s%s%.1f\n", Q.title, Q.author, Q.price);
    fclose(file);

    file = fopen("book.txt", "r");
    if (file == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("\nSaved Book Details:\n");

    fgets(Q.title, sizeof(Q.title), file);
    fgets(Q.author, sizeof(Q.author), file);
    fscanf(file, "%f", &Q.price);

    printf("Title: %s", Q.title);
    printf("Author: %s", Q.author);
    printf("Price: %.0f shs\n", Q.price);

    fclose(file);
    return 0;
}
