#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repl.h"
#include "btree.h"

InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}

void read_input(InputBuffer* input_buffer) {  }


void repl() {
    InputBuffer* input_buffer = new_input_buffer();
    printf("REPL démarré (fonctionnalité en développement).\n");


    free(input_buffer->buffer);
    free(input_buffer);
}
