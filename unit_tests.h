#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INF_INDICATOR -1

int Get_Roots(double, double, double, double*, double*);
int Solve_square(double, double, double, double*, double*);
int Solve_linear(double, double, double*);

#define ASSERT_EQUAL(x, y, f) if(x != y){                                                                                                       \
    fprintf(stderr, "Assert Failed: in file %s in line %d, %d != %d \n", __FILE__, __LINE__, x, y);        \
    f++;                                                                                                                                                                        \
}                                                                                                                                                                                  \

///Вызывает все тесты для функции поиска корней уравнения
void Test__Get_Roots(void) {
    int error_count = 0;

    double x1 = 0;
    double x2 = 0;

    ASSERT_EQUAL( Get_Roots(1, -10, 1, &x1, &x2), 2, error_count );
    ASSERT_EQUAL( Get_Roots(1, -10, 1, &x1, &x2), 2, error_count );
    ASSERT_EQUAL( Get_Roots(0, -10, 1, &x1, &x2), 1, error_count );

    if(error_count == 0) {
        fprintf(stderr, "Test Get_Roots OK\n");
    }
    else {
        fprintf(stderr, "Test Get_Roots FAILED\n");
        exit(1);
    }
}

///Вызывает все тесты для функции решения линейного уравнения
void Test__Solve_linear(void) {
    double x = 0;
    int root_number = 0;
    int error_count = 0;

    ASSERT_EQUAL( Solve_linear(0, 0, &x), INF_INDICATOR, error_count );
    ASSERT_EQUAL( Solve_linear(0, 1, &x), 0, error_count );
    ASSERT_EQUAL( Solve_linear(0, -1, &x), 0, error_count );
    {
    root_number = Solve_linear(2, 6, &x);
    ASSERT_EQUAL( root_number, 1, error_count );
    ASSERT_EQUAL( x, 3, error_count )
    }
    {
    root_number = Solve_linear(-2, 6, &x);
    ASSERT_EQUAL( root_number, 1, error_count );
    ASSERT_EQUAL( x, -3, error_count )
    }
    {
    root_number = Solve_linear(-2, -6, &x);
    ASSERT_EQUAL( root_number, 1, error_count );
    ASSERT_EQUAL( x, 3, error_count );
    }

    if(error_count == 0) {
        fprintf(stderr, "Test Solve_linear OK\n");
    }
    else {
        fprintf(stderr, "Test Solve_linear FAILED\n");
        exit(1);
    }
}

///Вызывает все тесты для функции решения квадратного уравнения
void Test__Solve_square(void) {
    double x1 = 0;
    double x2 = 0;
    int root_number;
    int error_count = 0;

    /// test general
    {
    root_number = Solve_square(1, -7, 12, &x1, &x2);
    ASSERT_EQUAL( root_number, 2, error_count )
    ASSERT_EQUAL( (x1 * x2 == 12) && (x1 + x2) == 7, 1, error_count );
    }
    {
    root_number = Solve_square(1, -4, 4, &x1, &x2);
    ASSERT_EQUAL( root_number, 1, error_count );
    ASSERT_EQUAL( x1, 2, error_count );
    }

    /// test b = 0
    ASSERT_EQUAL( Solve_square(1, 0, 4, &x1, &x2), 0, error_count );
    ASSERT_EQUAL( Solve_square(1, 0, -4, &x1, &x2), 2, error_count );

    /// test c = 0
    ASSERT_EQUAL( Solve_square(1, 1, 0, &x1, &x2), 2, error_count );
    ASSERT_EQUAL( Solve_square(1, 0, 0, &x1, &x2), 1, error_count );

    if(error_count == 0) {
        fprintf(stderr, "Test Solve_square OK\n");
    }
    else {
        fprintf(stderr, "Test Solve_square FAILED\n");
        exit(1);
    }
}

///Вызывает все тестирующие функции
void Test_All(void) {
    Test__Get_Roots();
    Test__Solve_linear();
    Test__Solve_square();
}
