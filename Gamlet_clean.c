#include "Gamlet_header.h"

int main(int argc,char* argv[]) {

    //---------------------------------------------------------------
    //     ������������ ��������� ��������� ������
    //---------------------------------------------------------------
    if (argc > 1) {

        for (int i = 0; i < argc; i++) {
            if ( strcmp(argv[i], "--test") == 0) {
                Test_All();
            }
            else {
                fprintf(stderr,"Unknown command : %s", argv[i]);
            }
        }
    }

    const char* file_in = "Gamlet_part.txt";
    const char* file_out = "Gamlet_test_for_part.txt";

    size_t text_size = 0;
    size_t lines_count = 0;

    //-------------------------------------
    //    ��������� ����� �� �����
    //-------------------------------------
    char* text = Get_Text(file_in, &text_size);
    struct upd_str* line_pointers = Get_Prepared_Text(file_in, text, text_size, lines_count);

    //---------------------------------------------------------------------
    //   ���������, ��������� � ������, � ������� � ����
    //---------------------------------------------------------------------
    Quick_Sort(line_pointers, 0, lines_count - 1,  String_comp);
    Write_Sorted_Text(line_pointers, lines_count, file_out, "w");

    //---------------------------------------------------------------------
    //     ���������, ��������� � �����, � ������� � ����
    //---------------------------------------------------------------------
    qsort(line_pointers, lines_count, sizeof(struct upd_str),  Reversed_String_comp);
    Write_Sorted_Text(line_pointers, lines_count, file_out, "a");

    //----------------------------------------------------------------------------
    //      ����������� �����, � ������� �������� ����� � ����
    //----------------------------------------------------------------------------
    Change_Char(text, text_size, '\0', '\n');
    Write_Text(text, text_size, file_out, "a");

    //------------------------------
    //  ����������� ������
    //------------------------------
    Free_All(2, text, line_pointers);

    return 0;
}
