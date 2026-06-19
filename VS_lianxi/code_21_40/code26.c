#include<stdio.h>
#include<math.h>

double integral(double(* func)(double),double a,double b)
{
    return(b-a)*((*func)(a)+(*func)(b))/2;
}
double f1(double x)
{
    return sin(x)*cos(x);
}
double f2(double x)
{
    return x*x/2;
}

void main()
{
    double(*p)(double);
    p=f1;
    printf("%lf\n",integral(p,1,2));
    p=f2;
    printf("%lf\n",integral(p,1,2));
    printf("%lf\n",integral(f2,1,2));
}
