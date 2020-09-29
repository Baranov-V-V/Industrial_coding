
#include "Gamlet_header.h"

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
int IsEqual(struct upd_str* arr1, struct upd_str* arr2, size_t arr_size) {
    int i;
    for(i = 0; i < arr_size; i++) {
        if ( strcmp((arr1 + i)->value, (arr2 + i)->value) != 0 || (arr1 + i)->length != (arr2 + i)->length ) {
            fprintf(stderr, "<%s>, %d != <%s>, %d\n", (arr1 + i)->value, (arr1 + i)->length, (arr2 + i)->value, (arr2 + i)->length);
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
    struct upd_str test_str1;
    struct upd_str test_str2;

    test_str1.value = "abba";
    test_str1.length = 4;
    test_str2.value = "baab";
    test_str2.length = 4;
    struct upd_str test_arr[] = {test_str1, test_str2};
    swap_strings_arr(test_arr, 0, 1);

    PrintError( strcmp(test_arr[0].value, "baab") != 0 || strcmp(test_arr[1].value, "abba") != 0, "Test_swap_strings_arr");
}

/*!
��������� ������� String_comp
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_String_comp(void) {
    struct upd_str test_str1;
    struct upd_str test_str2;

    test_str1.value = "ab,/2  b,a  ,k   rwe";
    test_str1.length = strlen(test_str1.value);
    test_str2.value = "a,,3  !b  1,b,a,  ,.'a tbrt";
    test_str2.length = strlen(test_str2.value);

    PrintError( String_comp(&test_str1, &test_str2) < 0, "Test_String_comp");
}

/*!
��������� ������� Reserved_String_comp
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Reversed_String_comp(void) {

    struct upd_str test_str1;
    struct upd_str test_str2;

    test_str1.value = "Who is't  'that can in''form ;'me'? 95";
    test_str1.length = strlen(test_str1.value);
    test_str2.value = "When he th' ambitious Norway  com'ba  te'd'   .";
    test_str2.length = strlen(test_str2.value);
    PrintError( Reversed_String_comp(&test_str1, &test_str2) < 0, "Test_Reversed_String_comp");
}

/*!
��������� ������� Quick_Sort
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Quick_Sort(void) {

    struct upd_str test_str1;
    struct upd_str test_str2;
    struct upd_str test_str3;

    test_str1.value = "abbauytg\0";
    test_str1.length = 8;
    test_str2.value = "baab\0";
    test_str2.length = 4;
    test_str3.value = "aakkb\0";
    test_str3.length = 5;

    struct upd_str test_arr[] = {test_str2, test_str3, test_str1};
    struct upd_str test_arr_correct[] = {test_str3, test_str1, test_str2};

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
    size_t length = 26;

    PrintError( Get_Lines_Count(test_text, length) != 5, "Test_Get_Lines_Count");
}

/*!
��������� ������� Make_Line_Pointers
��� ��� ��. � ����� Gamlet_header.h
!*/
void Test_Make_Line_Pointers(void) {
    char test_text[] = "vbwrv\0ejhuc;we\0wen\0fe,.w\0\0";
    size_t length = 26;

    struct upd_str test_str1;
    struct upd_str test_str2;
    struct upd_str test_str3;
    struct upd_str test_str4;
    struct upd_str test_str5;

    test_str1.value = "vbwrv\0";
    test_str1.length = strlen(test_str1.value);
    test_str2.value = "ejhuc;we\0";
    test_str2.length = strlen(test_str2.value);
    test_str3.value = "wen\0";
    test_str3.length = strlen(test_str3.value);
    test_str4.value = "fe,.w\0";
    test_str4.length = strlen(test_str4.value);
    test_str5.value = "\0";
    test_str5.length = strlen(test_str5.value);
    struct upd_str test_line_pointers_correct[] = {test_str1, test_str2, test_str3, test_str4, test_str5};

    struct upd_str* test_line_pointers = (struct upd_str*) calloc(5, sizeof(struct upd_str));
    Make_Line_pointers(test_line_pointers, test_text, length);

    PrintError( IsEqual(test_line_pointers, test_line_pointers_correct, 5) != 1, "Make_Line_pointers");
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
