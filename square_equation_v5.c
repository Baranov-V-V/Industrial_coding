#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_tests.h"

#define INF_INDICATOR -1
#define PRECISION_VALUE 1e-6
#define TRUE_CORRECT_NUMBERS_COUNT 3

/*!
Ищет решения линейного уравнения вида "a*х - b = 0"
\param[in] a коэффицент перед х
\param[in] b свободный член
\param[in] *х1 указатель на переменную, в которую будет положен корень при его наличии
\return количество корней
*/
int Solve_linear(double a, double b, double *x1){
  Test_Correct_Linear(a, b, x1);

  if (a == 0) {
    if (b == 0) {
      return INF_INDICATOR;
    }
    else {
      return 0;
    }
  }
  else {
    *x1 = b / a;
    return 1;
  }
}

/*!
Ищет решения квадратного уравнения вида "a*х^2 + b*х + с = 0"
\param[in] a коэффицент перед х^2
\param[in] b коэффицент перед х
\param[in] с свободный член
\param[in] *х1 указатель на переменную, в которую будет положен один из корене при его наличии
\param[in] *х2 указатель на переменную, в которую будет положен один из корней при его наличии
\return количество корней
*/
int Solve_square(double a, double b, double c, double *x1, double *x2){
  Test_Correct_Square(a, b, c, x1, x2);

  double D = b * b - 4 * a * c;
  if (D >= PRECISION_VALUE) {
    *x1 = (-b - sqrt(D)) / (2 * a);
    *x2 = (-b + sqrt(D)) / (2 * a);
    return 2;
  }
  else if (fabs(D) < PRECISION_VALUE){
    *x1 = -b / (2 * a);
    return 1;
  }
  else {
    return 0;
  }
}

/*!
Ищет корни уравнения уравнения "a*х^2 + b*х + с = 0" с помощью функций Solve_linear и Solve_square
Проверяет корректность входных данных
\param[in] a коэффицент перед х^2
\param[in] b коэффицент перед х
\param[in] с свободный член
\param[in] *х1 указатель на переменную, в которую будет положен один из корене при его наличии
\param[in] *х2 указатель на переменную, в которую будет положен один из корней при его наличии
/return количество корней
*/
int Get_Roots(double a, double b, double c, double *x1, double *x2){
  Test_Correct_Square(a, b, c, x1, x2);

  if (a == 0) {
    return Solve_linear(b, c, x1);
  }
  else {
    return Solve_square(a, b, c, x1, x2);
  }
}

int main(){
  Test_All();

  double a, b, c, x1, x2;
  a = b = c = x1 = x2 = 0;
  int correct_numbers_count = 0;

  printf("Enter parameters:\n");
  do {
    fflush(stdin);
    correct_numbers_count = scanf("%lg %lg %lg", &a, &b, &c);
    if(correct_numbers_count == TRUE_CORRECT_NUMBERS_COUNT) {
      break;
    }
    printf("Error occured, please try again:\n");
  } while(1);


  int number_of_roots = Get_Roots(a, b, c, &x1, &x2);

  switch(number_of_roots){
    case 0: printf("No roots found");
      break;

    case 1: printf("1 root found: %lg", x1);
      break;

    case 2: printf("2 roots found : %lg, %lg", x1, x2);
      break;

    case INF_INDICATOR: printf("Infinite number of roots found");
      break;

    default: printf("Error occured, please check your input parameters");
  }

return 0;
}
