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
    assert(text_size >= 0);

    int i = 0;
    size_t lines_count = 0;
    for (i; i < text_size; i++) {
        if (text[i] == '\0') {
            lines_count++;
        }
    }

    return lines_count;
}

void Make_Line_pointers(struct upd_str* line_pointers, char* text, size_t text_size) {
    assert(line_pointers != NULL);
    assert(text != NULL);

    int line_no = 0;
    int str_len = 0;
    line_pointers->value = text;

    int i = 0;
    for(i; i < text_size - 1; i++) {
        str_len++;
        if (text[i] == '\0') {
            line_pointers[line_no].length = str_len - 1;
            str_len = 0;
            line_no++;
            line_pointers[line_no].value = text + i + 1;
        }

    }

}

void Free_All(int count, ...) {

    va_list ap;
    va_start(ap, count);

    int i = 0;
    for(i; i < count ; ++i) {
        void* tmp = va_arg(ap, void*);
        free(tmp);
    }

    va_end(ap);
}


