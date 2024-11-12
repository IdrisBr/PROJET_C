#ifndef BTREE_H
#define BTREE_H

typedef struct {
    int id;
    char username[32];
    char email[32];
} Row;

typedef struct Node {
    Row data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
    int next_id;  
} Table;


Table* create_table();
void free_table(Table* table);
void insert_row(Table* table, Row* row);
void select_rows(Table* table);
void update_row(Table* table, int id, const char* new_username, const char* new_email);
void delete_row(Table* table, int id);

#endif
