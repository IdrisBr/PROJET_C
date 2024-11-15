// main.c

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "repl.h"

int main() {
    Table* table = create_table();
    if (table == NULL) {
        printf("Erreur lors de la création de la table.\n");
        return 1;
    }
    printf("Table créée avec succès.\n");

    Row row1 = {.id = 0, .username = "user1", .email = "user1@example.com"};
    Row row2 = {.id = 0, .username = "user2", .email = "user2@example.com"};
    Row row3 = {.id = 0, .username = "user3", .email = "user3@example.com"};
    
    insert_row(table, &row1);
    insert_row(table, &row2);
    insert_row(table, &row3);

    printf("Affichage des lignes dans la table avant mise à jour :\n");
    select_rows(table);

    update_row(table, 2, "updated_user2", "updated_user2@example.com");

    printf("Affichage des lignes dans la table après mise à jour :\n");
    select_rows(table);

    free_table(table);
    printf("Table libérée avec succès.\n");

    return 0;
}
