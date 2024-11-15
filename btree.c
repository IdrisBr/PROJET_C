// btree.c

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

Node* insert_bst(Node* root, Row* row) {
    if (root == NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = *row;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if (row->id < root->data.id) {
        root->left = insert_bst(root->left, row);
    } else {
        root->right = insert_bst(root->right, row);
    }
    return root;
}

void insert_row(Table* table, Row* row) {
    row->id = table->next_id++;
    table->root = insert_bst(table->root, row);
}

void inorder_traversal(Node* node) {
    if (node == NULL) return;
    inorder_traversal(node->left);
    printf("ID: %d, Username: %s, Email: %s\n", node->data.id, node->data.username, node->data.email);
    inorder_traversal(node->right);
}

void select_rows(Table* table) {
    inorder_traversal(table->root);
}

Node* find_node(Node* root, int id) {
    if (root == NULL || root->data.id == id) return root;
    if (id < root->data.id) return find_node(root->left, id);
    return find_node(root->right, id);
}

void update_row(Table* table, int id, const char* new_username, const char* new_email) {
    Node* node = find_node(table->root, id);
    if (node != NULL) {
        strncpy(node->data.username, new_username, sizeof(node->data.username) - 1);
        strncpy(node->data.email, new_email, sizeof(node->data.email) - 1);
        node->data.username[sizeof(node->data.username) - 1] = '\0';
        node->data.email[sizeof(node->data.email) - 1] = '\0';
    }
}
