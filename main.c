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

    repl();  

    free_table(table);  
    printf("Table libérée avec succès.\n");

    return 0;
}
