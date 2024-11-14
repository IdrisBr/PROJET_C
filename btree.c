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

Node* insert_bst(Node* node, Row* data) {
    if (node == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = *data;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (data->id < node->data.id) {
        node->left = insert_bst(node->left, data);
    } else {
        node->right = insert_bst(node->right, data);
    }
    return node;
}

void insert_row(Table* table, Row* row) {
    row->id = table->next_id++;
    table->root = insert_bst(table->root, row);
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

void select_rows(Table* table) {  }
void update_row(Table* table, int id, const char* new_username, const char* new_email) {  }
void delete_row(Table* table, int id) {  }
