#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
#include <ctype.h>
#include <sys\stat.h>
#include <assert.h>

#define ASSERT_ERROR(x, y, message) if(x == y) {                                                                          \
    fprintf(stderr, "Assert Failed %s : " #x " == " #y " in line %d\n", message, __LINE__);        \
    exit(1);                                                                                                                                                      \
}                                                                                                                                                                       \


/*!
�������� ��� ����� old_c � ������ text �� new_c
\param[in] text ������, ��� ����� ���������� ������
\param[in] old_c �����, ������� ���� ��������
\param[in] new_c �����, �� ������� ����� ����������� ������
\return void
*/
void Change_Char(char* text, size_t text_size, char old_c, char new_c);

/*!
������� �� ������� ����������, �� ��� ������ � ����
\param[in] line_pointers ������ ���������� �� ������ ��� ������
\param[in] lines_count ���������� ��������� ��� ������ � ������� ����������,
lines_count ������ ���� �� ������ ���������� ���������� � �������
\param[in] file_name ������ � ��������� ����� ��� ������
\param[in] type ��� ������ � ���� ("a" ��� "w")
\return void
*/
void Write_Sorted_Text(char** line_pointers, size_t lines_count, char* file_name, char* type);

/*!
������� ������ text � ����, ����� �������� �� ����� text_size ��������
\param[in] text ������ ��� ������
\param[in] text_size ���������� �������� ��� ������
\param[in] file_name ������ � ��������� ����� ��� ������
\param[in] type ��� ������ � ���� ("a" ��� "w")
\return void
*/
void Write_Text(char* text, size_t text_size, char* file_name, char* type);

/*!
���� ���������� ����� � ������� ���� text, ��� ������ ������ �������� �������� '\0'
\param[in] text ����� ��� ������
\param[in] text_size ����� ������, � ������� ����� ������������ �����
\return ���������� ����� � ������ text
*/
size_t Get_Lines_Count(char* text, size_t text_size);

/*!
��������� ��� ���������� �� ����� file_name, �������� ������ ��� �������������� ������ �
���������� ��� ������
\param[in] file_name ��� ����� ��� ����������
\return ��������� �� 1�� ������ ��������� ������
*/
//int Get_Text(char* file_name, char* data);

/*!
��������� ������ ������ line_pointers �������� �� ������ text
\param[in] line_pointers ������ ����������, � ������� ����� ���������� ��������� �� ������ ������� ������ ������
\param[in] text ������ ����, � ������� ����� ����������� ����� �����
\param[in] text_size ����� ������ � ��������
\return void
*/
void Make_Line_pointers(char** line_pointers, char* text, size_t text_size);

/*!
������ ��������� i � j ������� ���������� v
\param[in] v ������ ����������
\param[in] i ������ ������� ��������
\param[in] j ������ ������ ��������
\return void
*/
void swap_strings_arr(char** v, int i, int j);

/*!
���������� ������ lhs � rhs �����������������, ��������� ������� �� ���������� �������
\param[in] lhs 1�� ������ ��� ���������
\param[in] rhs  2�� ������ ��� ���������
\return 1, ���� lhs ������ rhs, 0 � ��������� ������
*/
int String_comp(char* lhs, char* rhs);

/*!
�������� ������� ���������� ��� ������� ����������, ��� ������� ����� ������������ ������,
�� ������� ��������� ���������
\param[in] arr ������ ���������� ��� ����������
\param[in] left_pos ������ ���������� �������� ���������� � �������
\param[in] right_pos ������ ��������� �������� ���������� � �������
\param[in] (*comp)(char* lhs, char* rhs) - ��������� �� �������-����������, ��� ��������� �����,
�������� ��� ����������� � ������� arr
\return void
*/
void Quick_Sort(char** arr, int left_pos, int right_pos, int (*comp)(char* lhs, char* rhs));

/*!
���������� ������ lhs � rhs �����������������, ������� � �� �����,
��������� ������� �� ���������� �������
\param[in] lhs 1�� ������ ��� ���������
\param[in] rhs  2�� ������ ��� ���������
\return 1, ���� lhs ������ rhs, 0 � ��������� ������
*/
int Reversed_String_comp(char* lhs, char* rhs);

/*!
�������� ������� Quick_Sort � Write_Sorted_Text ��� ���������� ������ ������
\param[in] line_pointers ������ ����������, �� �������� ����� ������� ������
\param[in] lines_count ���������� ����� ��� ������
\param[in] type_sort ��� ����������: "Normal" ��� ������� � "Reserved" ��� ��������
\param[in] file_name ��� ����� ��� ������
\param[in] type_write ��� ������ ("w", "a" � ��)
\return void
*/
void Sort_Write(char** line_pointers, int lines_count, char* type_sort, char* file_name, char* type_write);
