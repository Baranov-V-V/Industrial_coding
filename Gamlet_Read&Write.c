#pragma once

#include "Gamlet_header.h"

void Write_Sorted_Text(char** line_pointers, size_t lines_count, char* file_name, char* type) {
    assert(file_name != NULL);
    assert(type != NULL);

    FILE* fp = fopen(file_name, type);

    ASSERT_ERROR(fp, NULL, "Cannot open file")

    int i = 0;
    for (i; i < lines_count; i++) {
        fputs(line_pointers[i], fp);
        fputc('\n', fp);
    }

    fclose(fp);
}

void Write_Text(char* text, size_t text_size, char* file_name, char* type) {
    assert(file_name != NULL);
    assert(type != NULL);

    FILE* fp = fopen(file_name, type);

    ASSERT_ERROR(fp, NULL, "Cannot open file");

    fwrite(text, text_size, sizeof(char), fp);

    fclose(fp);
}

char* Get_Text(char* file_name, char* data, int* text_size) {
    assert(file_name != NULL);

    struct stat info;
    stat(file_name, &info);
    size_t file_length = info.st_size;

    FILE* fp = fopen(file_name, "r");

    ASSERT_ERROR(fp, NULL, "Cannot open file");

    data = (char*) calloc(file_length + 1, sizeof(char));

    ASSERT_ERROR(data, NULL, "Can not allocate memory!");

    int obj_read = fread(data, sizeof(char), file_length + 1, fp);
    //fprintf(stderr, "done1\n");
    data[obj_read - 1] = '\0';
    *text_size = obj_read;
    //fprintf(stderr, "done2\n");
    //printf("%s", data);

    return data;
  }

void Sort_Write(char** line_pointers, int lines_count, char* type_sort, char* file_name, char* type_write) {
    if ( type_sort == "Normal") {
        Quick_Sort(line_pointers, 0, lines_count - 1,  String_comp);
        Write_Sorted_Text(line_pointers, lines_count, file_name, type_write);
    }
    else if ( type_sort == "Reserved" ) {
        Quick_Sort(line_pointers, 0, lines_count - 1, Reversed_String_comp);
        Write_Sorted_Text(line_pointers, lines_count, file_name, type_write);
    }
    else {
        fprintf(stderr, "Can't detect type of sort\n");
        exit(1);
    }
}
