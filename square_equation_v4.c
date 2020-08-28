#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF_INDICATOR -1
#define PRECISIONVALUE 1e-6

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

int main(){
  double a, b, c, x1, x2;
  a = b = c = x1 = x2 = 0;

  printf("Enter parameters:\n");
  printf("a = ");
  scanf("%lg", &a);
  printf("b = ");
  scanf("%lg", &b);
  printf("c = ");
  scanf("%lg", &c);

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
