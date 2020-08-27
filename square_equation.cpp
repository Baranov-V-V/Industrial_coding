#include <stdio.h>
#include <math.h>
#include <cassert>

const int INF_INDICATOR = -1;

int Get_Roots(double a, double b, double c, double *x1, double *x2){
  assert(std::isfinite(a));
  assert(std::isfinite(b));
  assert(std::isfinite(c));

  assert(x1 != x2);
  assert(x1 != NULL);
  assert(x2 != NULL);

  if(a == 0){  //linear equation
    if(b == 0){
      if(c == 0){
        return INF_INDICATOR;
      }
      else{
        return 0;
      }
    }
    else{ // b != 0
      *x1 = c / b;
      return 1;
    }
  }
  else{  // square equation
    double D = b * b - 4 * a * c;
    if(D > 0){
      *x1 = (-b - sqrt(D)) / (2 * a);
      *x2 = (-b + sqrt(D)) / (2 * a);
      return 2;
    }
    else if(D == 0){
      *x1 = -b / (2 * a);
      return 1;
    }
    else{
      return 0;
    }
  }
}

int main(){
  double a, b, c, x1, x2;

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
