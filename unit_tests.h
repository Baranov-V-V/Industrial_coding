#pragma once

#include <assert.h>
#include <stdio.h>

#define INF_INDICATOR -1

int Get_Roots(double, double, double, double*, double*);
int Solve_square(double, double, double, double*, double*);
int Solve_linear(double, double, double*);

///Вызывает все тесты для функции поиска корней уравнения
void Test__Get_Roots(void){

  double x1 = 0;
  double x2 = 0;

  assert( Get_Roots(1, -10, 1, &x1, &x2) == 2 );
  assert( Get_Roots(0, -10, 1, &x1, &x2) == 1 );

  fprintf(stderr, "Test Get_Roots OK\n");
}
///Вызывает все тесты для функции решения линейного уравнения
void Test__Solve_linear(void){
  double x = 0;
  int root_number;

  assert( Solve_linear(0, 0, &x) == INF_INDICATOR );
  assert( Solve_linear(0, 1, &x) == 0 );
  assert( Solve_linear(0, -1, &x) == 0 );
  {
  root_number = Solve_linear(2, 6, &x);
  assert(root_number == 1 && x == 3);
  }
  {
  root_number = Solve_linear(-2, 6, &x);
  assert(root_number == 1 && x == -3);
  }
  {
  root_number = Solve_linear(-2, -6, &x);
  assert(root_number == 1 && x == 3);
  }

  fprintf(stderr, "Test Solve_linear OK\n");
}

///Вызывает все тесты для функции решения квадратного уравнения
void Test__Solve_square(void){
  double x1 = 0;
  double x2 = 0;
  int root_number;
  /// test general
  {
  root_number = Solve_square(1, -7, 12, &x1, &x2);
  assert(root_number == 2 && (x1 * x2 == 12) && (x1 + x2) == 7);
  }
  {
  root_number = Solve_square(1, -4, 4, &x1, &x2);
  assert(root_number == 1 && (x1 == 2));
  }

  /// test b = 0
  assert( Solve_square(1, 0, 4, &x1, &x2) == 0 );
  assert( Solve_square(1, 0, -4, &x1, &x2) == 2 );

  /// test c = 0
  assert( Solve_square(1, 1, 0, &x1, &x2) == 2 );
  assert( Solve_square(1, 0, 0, &x1, &x2) == 1 );

  fprintf(stderr, "Test Solve_square Ok\n");
}

///Вызывает все тестирующие функции
void Test_All(void){
  Test__Get_Roots();
  Test__Solve_linear();
  Test__Solve_square();
}
