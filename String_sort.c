#pragma once

#include "Gamlet_header.h"

void swap_strings_arr(char** v, int i, int j) {
    assert(i >= 0);
    assert(j >= 0);

    char* tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int String_comp(char* lhs, char* rhs) {
    assert(lhs != NULL);
    assert(rhs != NULL);

    int lhs_pos = 0;
    int rhs_pos = 0;

    while (lhs[lhs_pos] !='\0' && rhs[rhs_pos] != '\0') {
        if ( !isalpha(lhs[lhs_pos]) ) {
            lhs_pos++;
            continue;
        }
        if ( !isalpha(rhs[rhs_pos]) ) {
            rhs_pos++;
            continue;
        }

        if( tolower(lhs[lhs_pos]) > tolower(rhs[rhs_pos]) ) {
            return 1;
        }
        else if ( tolower(lhs[lhs_pos]) < tolower(rhs[rhs_pos]) ) {
            return 0;
        }
        rhs_pos++;
        lhs_pos++;
    }
    if (lhs[lhs_pos] == '\0') {
        return 0;
    }
    else {
        return 1;
    }
}

int Reversed_String_comp(char* lhs, char* rhs) {
    assert(lhs != NULL);
    assert(rhs != NULL);

    int lhs_pos = strlen(lhs) - 1;
    int rhs_pos = strlen(rhs) - 1;

    while (lhs_pos >= 0 && rhs_pos >= 0) {
        if ( !isalpha(lhs[lhs_pos]) ) {
            lhs_pos--;
            continue;
        }
        if ( !isalpha(rhs[rhs_pos]) ) {
            rhs_pos--;
            continue;
        }

        if( tolower(lhs[lhs_pos]) > tolower(rhs[rhs_pos]) ) {
            return 1;
        }
        else if( tolower(lhs[lhs_pos]) < tolower(rhs[rhs_pos]) ) {
            return 0;
        }
        rhs_pos--;
        lhs_pos--;
    }
    if (lhs_pos == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

void Quick_Sort(char** arr, int left_pos, int right_pos, int (*comp)(char* lhs, char* rhs)) {
    int last = 0;
    int i = 0;

    if (left_pos  >= right_pos) {
        return;
    }

    if ( right_pos - left_pos == 1) {
        if ( (*comp)(arr[left_pos], arr[right_pos]) == 0 ) {
            swap_strings_arr(arr, left_pos, right_pos);
        }
    }
    swap_strings_arr(arr, left_pos, (left_pos + right_pos) / 2);
    last = left_pos;

    for (i = left_pos + 1; i <= right_pos; i++) {
        if ( (*comp)(arr[i], arr[left_pos]) == 0 ) {
            swap_strings_arr(arr, ++last, i);
        }
    }

    swap_strings_arr(arr, left_pos, last);

    Quick_Sort(arr, left_pos, last - 1, comp);
    Quick_Sort(arr, last + 1, right_pos, comp);
}
