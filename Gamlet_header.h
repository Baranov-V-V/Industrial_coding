#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <io.h>
#include <ctype.h>
#include <sys\stat.h>
#include <assert.h>
#include <stdarg.h>

#define ASSERT_ERROR(x, y, message) if(x == y) {                                                                          \
    fprintf(stderr, "Assert Failed %s : " #x " == " #y " in line %d file %s\n", message, __LINE__, __FILE__);        \
    exit(1);                                                                                                                                                      \
}                                                                                                                                                                       \


struct upd_str {
    char* value;
    size_t length;
};

/*!
�������� ��� ����� old_c � ������ text �� new_c
@param[in] text ������, ��� ����� ���������� ������
@param[in] old_c �����, ������� ���� ��������
@param[in] new_c �����, �� ������� ����� ����������� ������
@return void
*/
void Change_Char(char* text, size_t text_size, char old_c, char new_c);

/*!
������� �� ������� ����������, �� ��� ������ � ����
@param[in] line_pointers ������ ���������� �� ������ ��� ������
@param[in] lines_count ���������� ��������� ��� ������ � ������� ����������,
lines_count ������ ���� �� ������ ���������� ���������� � �������
@param[in] file_name ������ � ��������� ����� ��� ������
@param[in] type ��� ������ � ���� ("a" ��� "w")
@return void
*/
void Write_Sorted_Text(struct upd_str* line_pointers, size_t lines_count, const char* file_name, char* type);

/*!
������� ������ text � ����, ����� �������� �� ����� text_size ��������
@param[in] text ������ ��� ������
@param[in] text_size ���������� �������� ��� ������
@param[in] file_name ������ � ��������� ����� ��� ������
@param[in] type ��� ������ � ���� ("a" ��� "w")
@return void
*/
void Write_Text(char* text, size_t text_size, const char* file_name, char* type);

/*!
���� ���������� ����� � ������� ���� text, ��� ������ ������ �������� �������� '\0'
@param[in] text ����� ��� ������
@param[in] text_size ����� ������, � ������� ����� ������������ �����
@return ���������� ����� � ������ text
*/
size_t Get_Lines_Count(char* text, size_t text_size);

/*!
��������� ��� ���������� �� ����� file_name, �������� ������ ��� �������������� ������ �
���������� ��� ������
@param[in] file_name ��� ����� ��� ����������
@return ��������� �� 1�� ������ ��������� ������
*/
char* Get_Text(const char* file_name, size_t* text_size);

/*!
��������� ������ ������ line_pointers �������� �� ������ text
@param[in] line_pointers ������ �������� upd_str, � ������� ����� ���������� ��������� �� ������ ������� ������ ������
@param[in] text ������ ����, � ������� ����� ����������� ����� �����
@param[in] text_size ����� ������ � ��������
@return void
*/
void Make_Line_pointers(struct upd_str* line_pointers, char* text, size_t text_size);

/*!
������ ��������� i � j ������� �������� upd_str
@param[in] v ������ ����������
@param[in] i ������ ������� ��������
@param[in] j ������ ������ ��������
@return void
!*/
void swap_strings_arr(struct upd_str* arg, int i, int j);

/*!
���������� ������ lhs � rhs, ��������� � upd_str, �����������������, ��������� ������� �� ���������� �������
@param[in] lhs 1�� ������ ��� ���������
@param[in] rhs  2�� ������ ��� ���������
@return 1, ���� lhs ������ rhs, 0 � ��������� ������
*/
int String_comp(struct upd_str* lhs, struct upd_str* rhs);

/*!
�������� ������� ���������� ��� ������� ����������, ��� ������� ����� ������������ ������,
�� ������� ��������� ���������
@param[in] arr ������ ���������� ��� ����������
@param[in] left_pos ������ ���������� �������� ���������� � �������
@param[in] right_pos ������ ��������� �������� ���������� � �������
@param[in] (*comp)(struct upd_str* lhs, struct upd_str* rhs) - ��������� �� �������-����������, ��� ��������� �����,
�������� ��� ����������� � ������� arr
@return void
*/
void Quick_Sort(struct upd_str* arr, int left_pos, int right_pos, int (*comp)(struct upd_str* lhs, struct upd_str* rhs));

/*!
���������� ������ lhs � rhs, ��������� � upd_str, �����������������, ������� � �� �����,
��������� ������� �� ���������� �������
@param[in] lhs 1�� ������ ��� ���������
@param[in] rhs  2�� ������ ��� ���������
@return 1, ���� lhs ������ rhs, 0 � ��������� ������
*/
int Reversed_String_comp(struct upd_str* lhs, struct upd_str* rhs);

/*!
������� ������� ����������� ���������� ������
@param[in] query_count ���������� ���������� �� ������� ������
return void
*/
void FreeALL(int count, ...);

struct upd_str* Get_Prepared_Text(const char* file_in, char* text, size_t text_size, size_t lines_count);
