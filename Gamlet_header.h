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
Заменяет все буквы old_c в строке text на new_c
\param[in] text строка, где нужно произвести замену
\param[in] old_c буква, которую надо заменить
\param[in] new_c буква, на которую будет произведена замена
\return void
*/
void Change_Char(char* text, size_t text_size, char old_c, char new_c);

/*!
Выводит из массива указателей, на эти строки в файл
\param[in] line_pointers массив указателей на строки для вывода
\param[in] lines_count количество элементов для вывода в массиве указателей,
lines_count должно быть не больше количества элеменотов в массиве
\param[in] file_name строка с названием файла для вывода
\param[in] type тип записи в файл ("a" или "w")
\return void
*/
void Write_Sorted_Text(char** line_pointers, size_t lines_count, char* file_name, char* type);

/*!
Выводит строку text в файл, будет выведено не более text_size символов
\param[in] text строка для вывода
\param[in] text_size количество символов для вывода
\param[in] file_name строка с названием файла для вывода
\param[in] type тип записи в файл ("a" или "w")
\return void
*/
void Write_Text(char* text, size_t text_size, char* file_name, char* type);

/*!
Ищет количество строк в массиве букв text, где каждая строка отделена символом '\0'
\param[in] text текст для поиска
\param[in] text_size длина текста, в котором будет производится поиск
\return количество строк в тексте text
*/
size_t Get_Lines_Count(char* text, size_t text_size);

/*!
Считывает все содержимое из файла file_name, выделяет память под образовавшуюся строку и
возвращает это строку
\param[in] file_name имя файла для считывания
\return указатель на 1ый символ считанной строки
*/
//int Get_Text(char* file_name, char* data);

/*!
Заполняет пустой массив line_pointers строками из текста text
\param[in] line_pointers массив указателей, в который будут помещаться указатели на первые символы каждой строки
\param[in] text массив букв, в котором будет происходить поиск строк
\param[in] text_size длина текста в символах
\return void
*/
void Make_Line_pointers(char** line_pointers, char* text, size_t text_size);

/*!
Меняет указатели i и j массиве указателей v
\param[in] v массив указателей
\param[in] i индекс первого элемента
\param[in] j индекс втрого элеметна
\return void
*/
void swap_strings_arr(char** v, int i, int j);

/*!
Сравнивает строки lhs и rhs лексикографически, пропуская символы не являющиеся буквами
\param[in] lhs 1ая строка для сравнения
\param[in] rhs  2ая строка для сравнения
\return 1, если lhs больще rhs, 0 в противном случае
*/
int String_comp(char* lhs, char* rhs);

/*!
Алгоритм быстрой сортировки для массива указателей, при котором будут сравниваться строки,
на которые указывают указатели
\param[in] arr массив указателей для сортировки
\param[in] left_pos индекс начального элемента сортировки в массиве
\param[in] right_pos индекс конечного элемента сортировки в массиве
\param[in] (*comp)(char* lhs, char* rhs) - указатель на функцию-компаратор, для сравнения строк,
лежащими под указателями в массиве arr
\return void
*/
void Quick_Sort(char** arr, int left_pos, int right_pos, int (*comp)(char* lhs, char* rhs));

/*!
Сравнивает строки lhs и rhs лексикографически, начиная с их конца,
пропуская символы не являющиеся буквами
\param[in] lhs 1ая строка для сравнения
\param[in] rhs  2ая строка для сравнения
\return 1, если lhs больще rhs, 0 в противном случае
*/
int Reversed_String_comp(char* lhs, char* rhs);

/*!
Вызывает функции Quick_Sort и Write_Sorted_Text для сортировки вывода текста
\param[in] line_pointers массив указателей, из которого будут печатся строки
\param[in] lines_count количество строк для вывода
\param[in] type_sort тип сортировки: "Normal" для обычной и "Reserved" для обратной
\param[in] file_name имя файла для вывода
\param[in] type_write тип вывода ("w", "a" и тд)
\return void
*/
void Sort_Write(char** line_pointers, int lines_count, char* type_sort, char* file_name, char* type_write);
