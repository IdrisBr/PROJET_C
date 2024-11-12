#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "repl.h"

int main() {
    Table* table = create_table();  
    repl();  
    free_table(table);  
    return 0;
}
