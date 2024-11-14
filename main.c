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

    Row row1 = {.username = "alice", .email = "alice@example.com"};
    Row row2 = {.username = "bob", .email = "bob@example.com"};
    Row row3 = {.username = "charlie", .email = "charlie@example.com"};

    insert_row(table, &row1);
    insert_row(table, &row2);
    insert_row(table, &row3);

    printf("Lignes insérées avec succès.\n");

    repl();

    free_table(table);
    printf("Table libérée avec succès.\n");

    return 0;
}
