
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

Table* create_table() {
    Table* table = (Table*)malloc(sizeof(Table));
    if (table == NULL) {
        return NULL;
    }
    table->root = NULL;
    table->next_id = 1;  
    return table;
}

void free_tree(Node* node) {
    if (node == NULL) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void free_table(Table* table) {
    if (table == NULL) return;
    free_tree(table->root);
    free(table);
}

void insert_row(Table* table, Row* row) {  }
void select_rows(Table* table) {  }
void update_row(Table* table, int id, const char* new_username, const char* new_email) {  }
void delete_row(Table* table, int id) {  }
