
#include "Gamlet_header.h"

void Write_Sorted_Text(struct upd_str* line_pointers, size_t lines_count, const char* file_name, char* type) {
    assert(file_name != NULL);
    assert(type != NULL);

    FILE* fp = fopen(file_name, type);

    ASSERT_ERROR(fp, NULL, "Cannot open file")

    int i = 0;
    for (i; i < lines_count; i++) {
        fputs((line_pointers + i)->value, fp);
        fputc('\n', fp);
    }
    fputs("@--------------------------------------------------------------------------------------------------------@\n",fp);

    fclose(fp);
}

void Write_Text(char* text, size_t text_size, const char* file_name, char* type) {
    assert(file_name != NULL);
    assert(type != NULL);

    FILE* fp = fopen(file_name, type);

    ASSERT_ERROR(fp, NULL, "Cannot open file");

    fwrite(text, text_size, sizeof(char), fp);
    fputs("@--------------------------------------------------------------------------------------------------------@\n",fp);

    fclose(fp);
}

char* Get_Text(const char* file_name, size_t* text_size) {
    assert(file_name != NULL);

    struct stat info;
    stat(file_name, &info);
    size_t file_length = info.st_size;

    FILE* fp = fopen(file_name, "r");
    ASSERT_ERROR(fp, NULL, "Cannot open file");

    char* data = (char*) calloc(file_length, sizeof(char));
    ASSERT_ERROR(data, NULL, "Can not allocate memory!");

    int obj_read = fread(data, sizeof(char), file_length, fp);

    data[obj_read] = '\0';
    *text_size = obj_read;

    return data;
  }

struct upd_str* Get_Prepared_Text(const char* file_in, char* text, size_t text_size, size_t lines_count) {
    assert(file_in != NULL);

    Change_Char(text, text_size, '\n', '\0');
    lines_count = Get_Lines_Count(text, text_size);

    struct upd_str* line_pointers = (struct upd_str*) calloc(lines_count, sizeof(struct upd_str));
    Make_Line_pointers(line_pointers, text, text_size);

    return line_pointers;
};
