#pragma once

#include "Gamlet_header.h"

void Change_Char(char* text, size_t text_size, char old_c, char new_c) {
    assert(text);
    assert(text_size >= 0);

    int i = 0;
    for (i; i < text_size; i++) {
        if ( text[i] == old_c ) {
            text[i] = new_c;
        }
    }
}

size_t Get_Lines_Count(char* text, size_t text_size) {
    assert(text != NULL);

    int i = 0;
    size_t lines_count = 0;
    for (i; i < text_size; i++) {
        if (text[i] == '\0') {
            lines_count++;
        }
    }

    return lines_count;
}

void Make_Line_pointers(char** line_pointers, char* text, size_t text_size) {
    assert(line_pointers != NULL);
    assert(text != NULL);

    int i = 0;
    int line_no = 0;
    line_pointers[line_no++] = text;

    for(i; i < text_size - 1; i++) {
        if (text[i] == '\0') {
            line_pointers[line_no] = text + i + 1;
            line_no++;
        }
    }

}

