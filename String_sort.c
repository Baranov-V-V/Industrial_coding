#include "Gamlet_header.h"

int String_comp(struct upd_str* lhs, struct upd_str* rhs) {
    assert(lhs != NULL);
    assert(rhs != NULL);

    int lhs_pos = 0;
    int rhs_pos = 0;

    while (lhs_pos != lhs->length && rhs_pos != rhs->length) {
        if ( !isalpha( (lhs->value)[lhs_pos] ) ) {
            lhs_pos++;
            continue;
        }
        if ( !isalpha( (rhs->value)[rhs_pos] ) ) {
            rhs_pos++;
            continue;
        }

        if( tolower( (lhs->value)[lhs_pos] ) != tolower( (rhs->value)[rhs_pos] ) ) {
            return tolower( (lhs->value)[lhs_pos] ) - tolower( (rhs->value)[rhs_pos] );
        }
        rhs_pos++;
        lhs_pos++;
    }

    return 0;
}

int Reversed_String_comp(struct upd_str* lhs, struct upd_str* rhs) {
    assert(lhs != NULL);
    assert(rhs != NULL);

    int lhs_pos = lhs->length;
    int rhs_pos = rhs->length;

    while (lhs_pos >= 0 && rhs_pos >= 0) {
        if ( !isalpha( (lhs->value)[lhs_pos] ) ) {
            lhs_pos--;
            continue;
        }
        if ( !isalpha( (rhs->value)[rhs_pos] ) ) {
            rhs_pos--;
            continue;
        }

        if( tolower( (lhs->value)[lhs_pos] ) != tolower( (rhs->value)[rhs_pos] ) ) {
            return tolower( (lhs->value)[lhs_pos] ) - tolower( (rhs->value)[rhs_pos] );
        }
        rhs_pos--;
        lhs_pos--;
    }

    return 0;
}

void Quick_Sort(struct upd_str* arr, int left_pos, int right_pos, int (*comp)(struct upd_str* lhs, struct upd_str* rhs)) {
    int last = 0;
    int i = 0;

    if (left_pos  >= right_pos) {
        return;
    }

    if (right_pos - left_pos == 1 && ( (*comp)(arr + left_pos, arr + right_pos) < 0 )) {
        swap_strings_arr(arr, left_pos, right_pos);
    }
    swap_strings_arr(arr, left_pos, (left_pos + right_pos) / 2);
    last = left_pos;

    for (i = left_pos + 1; i <= right_pos; i++) {
        if ( (*comp)(arr + i, arr + left_pos) < 0 ) {
            swap_strings_arr(arr, ++last, i);
        }
    }

    swap_strings_arr(arr, left_pos, last);

    Quick_Sort(arr, left_pos, last - 1, comp);
    Quick_Sort(arr, last + 1, right_pos, comp);
}

void swap_strings_arr(struct upd_str* arr, int i, int j) {
    assert(i >= 0);
    assert(j >= 0);

    struct upd_str tmp;

    tmp.length = (arr + i)->length;
    tmp.value = (arr + i)-> value;
    (arr + i)->length = (arr + j)->length;
    (arr + i)->value = (arr + j)-> value;
    (arr + j)->length = tmp.length;
    (arr + j)->value = tmp.value;
}
