#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF_INDICATOR -1
#define PRECISIONVALUE 1e-6
#define TRUE_CORRECT_NUMBERS_COUNT 3

/*!
Ищет решения линейного уравнения вида "a*х - b = 0"
\param[in] a коэффицент перед х
\param[in] b свободный член
\param[in] *х1 указатель на переменную, в которую будет положен корень при его наличии
\return количество корней
*/
int Solve_linear(double a, double b, double *x1){
  if(a == 0){
    if(b == 0){
      return INF_INDICATOR;
    }
    else{
      return 0;
    }
  }
  else{
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
  double D = b * b - 4 * a * c;
  if(D >= PRECISIONVALUE){
    *x1 = (-b - sqrt(D)) / (2 * a);
    *x2 = (-b + sqrt(D)) / (2 * a);
    return 2;
  }
  else if(D < PRECISIONVALUE && D > -(PRECISIONVALUE)){
    *x1 = -b / (2 * a);
    return 1;
  }
  else{
    return 0;
  }
}

/*!
Ищет корни уравнения уравнения "a*х^2 + b*х + с = 0" с помощью функций Solve_linear и Solve_square
Проверяет корректность входных данных
/params a,b,c коэффиценты уравнения
/params *х1,*х2 указатели на переменные в которые будут положены корни
/return количество корней
*/
int Get_Roots(double a, double b, double c, double *x1, double *x2){
  assert(isfinite(a));
  assert(isfinite(b));
  assert(isfinite(c));

  assert(x1 != x2);
  assert(x1 != NULL);
  assert(x2 != NULL);

  if(a == 0){
    return Solve_linear(b, c, x1);
  }
  else{
     return Solve_square(a, b, c, x1, x2);
  }
}

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

int main(){
  Test_All();

  double a, b, c, x1, x2;
  a = b = c = x1 = x2 = 0;
  int correct_numbers_count = 0;

  printf("Enter parameters:\n");
  correct_numbers_count = scanf("%lg %lg %lg", &a, &b, &c);

  while(correct_numbers_count != TRUE_CORRECT_NUMBERS_COUNT){
    printf("Error occured, please try again:\n");
    fflush(stdin);
    correct_numbers_count = scanf("%lg %lg %lg", &a, &b, &c);
  }


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
