#ifndef REPL_H
#define REPL_H

#include <stdio.h>
#include "btree.h"

typedef struct {
    char* buffer;
    int buffer_length;
    int input_length;
} InputBuffer;

InputBuffer* new_input_buffer();
void read_input(InputBuffer* input_buffer);
void repl();

#endif
