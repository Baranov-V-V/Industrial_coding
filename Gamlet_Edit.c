
#include "Gamlet_header.h"

void Change_Char(char* text, size_t text_size, char old_c, char new_c) {
    assert(text != NULL);
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
    assert(text_size > 0);

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
    assert(text_size >= 0);
    
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

void Free_All(int query_count, ...) {

    va_list ap;
    va_start(ap, query_count);

    int i = 0;
    for (i; i < query_count; i++) {
        void* tmp = va_arg(ap, void*);
        free(tmp);
    }

    va_end(ap);

}
