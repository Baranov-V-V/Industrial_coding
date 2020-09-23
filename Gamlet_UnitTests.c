#pragma once

#include "Gamlet_header.h"
#include "String_sort.c"
#include "Gamlet_Edit.c"
#include "Gamlet_Read&Write.c"

/*!
������� ������ ������ � ���������� ���������� ���������
\param[in] arg ��� ������ ���������, ������� ����� 0 ���� ������� �����������
\param[in] Test_name - �������� �����, ������� ����� ��������� � stderr ��� ������������ �����
\return void
*/
void PrintError(int arg, char* Test_name) {
    if (arg != 0) {
        fprintf(stderr,"%s: Not Passed\n", Test_name);
        exit(1);
    }
    else {
        fprintf(stderr,"%s: Passed\n", Test_name);
    }
}

/*!
���������� ��� ������� ���������� ���������� ����� �� ������������
\param[in] arr1 ������ ������ ��� ���������
\param[in] arr2 ������ ������ ��� ���������
\param[in] arr_size ����� ���� ���� �������� (��� ������ ��������� � arr1 � arr2)
\return 1, ���� ��� �����, 0 � ��������� ������
!*/
int IsEqual(char** arr1, char** arr2, size_t arr_size) {
    int i;
    for(i = 0; i < arr_size; i++) {
        if ( strcmp(arr1[i], arr2[i]) != 0 ) {
            fprintf(stderr, "%s != %s\n", arr1[i], arr2[i]);
            return 0;
        }
    }
    return 1;
}

/*!
��������� ������� swap_strings_arr
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_swap_strings_arr(void) {
    char* test_arr[3] = { "abba", "baab", "abab" };
    swap_strings_arr(test_arr, 0, 1);

    PrintError( strcmp(test_arr[0], "baab") != 0 || strcmp(test_arr[1], "abba") != 0, "Test_swap_strings_arr");
}

/*!
��������� ������� String_comp
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_String_comp(void) {
    char* test_string1 = "ab,/2  b,a  ,k   rwe";
    char* test_string2 = "a,,3  !b  1,b,a,  ,.'a tbrt";

    PrintError( String_comp(test_string1, test_string2) != 1, "Test_String_comp");
}

/*!
��������� ������� Reserved_String_comp
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Reversed_String_comp(void) {
    char* test_string1 = "tre425w a; , 8*9b   b,,5,[a";
    char* test_string2 = "t4349*5a5 a; , 8.,*9b, ?  b,5[a";

    PrintError( Reversed_String_comp(test_string1, test_string2) != 1, "Test_Reversed_String_comp");
}

/*!
��������� ������� Quick_Sort
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Quick_Sort(void) {

    char* s1 = "a,.  ;b.,b  .k";
    char* s2 = ",.   a;;a, a. ,.k";
    char* s3 = " a ,.b ,.b :;a  ;";
    char* test_arr[3] = {s1, s2, s3};
    char* test_arr_correct[3] = {s2, s3, s1};

    Quick_Sort(test_arr, 0, 2, String_comp);

    PrintError(  IsEqual(test_arr, test_arr_correct, 3) != 1, "Test_Quick_Sort");
}

/*!
��������� ������� Change_Char
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Change_Char(void) {
    char test_text[] = "abba";
    char* test_text_correct = "akka";
    Change_Char(test_text, strlen(test_text), 'b', 'k');

    PrintError( strcmp(test_text, test_text_correct) != 0, "Test_Change_Char");
}

/*!
��������� ������� Get_Lines_Count
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Get_Lines_Count(void) {
    char test_text[] = "vbwrv\0ejhuc;we\0wen\0fe,.w\0\0";
    size_t length = 26;      //������ ��������� � ������

    PrintError( Get_Lines_Count(test_text, length) != 5, "Test_Get_Lines_Count");
}

/*!
��������� ������� Make_Line_Pointers
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Make_Line_Pointers(void) {
    char test_text[] = "vbwrv\0ejhuc;we\0wen\0fe,.w\0\0";
    size_t length = 26;      //������ ��������� � ������
    char* test_line_pointers_correct[] = { "vbwrv\0", "ejhuc;we\0", "wen\0", "fe,.w\0", "\0" };

    char** test_line_pointers = (char**) calloc(5, sizeof(char*));
    Make_Line_pointers(test_line_pointers, test_text, length);

    PrintError( IsEqual(test_line_pointers_correct, test_line_pointers, 5) != 1, "Make_Line_pointers");
}

/*!
�������� ��� ����������� �������
!*/
void Test_All(void) {
    Test_swap_strings_arr();
    Test_String_comp();
    Test_Reversed_String_comp();
    Test_Quick_Sort();
    Test_Change_Char();
    Test_Get_Lines_Count();
    Test_Make_Line_Pointers();
}
