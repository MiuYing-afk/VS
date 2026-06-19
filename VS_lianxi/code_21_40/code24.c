#include<stdio.h>
#include<math.h>
void main()
{
    float a,b,c,t1,t2;
    int flag;
    int solvroot(float a,float b,float c,float *r1,float *r2);
    printf("请输入一元二次方程组的参数(a,b,c):");
    scanf("%f,%f,%f",&a,&b,&c);
    flag=solvroot(a,b,c,&t1,&t2);
    if(flag>0)
        { printf("方程的两个实根是:x1=%f,x2=%f\n",t1+t2,t1-t2); }
    else if(flag==0)
        { printf("方程的实根是:x1=x2=%f\n",t1); }
    else
        { printf("方程的两个虚根是:x1=%f+%fi,x2=%f-%fi\n",t1,t2,t1,t2); }
}

int solvroot(float a,float b,float c,float *r1,float *r2)
{
    float delta;
    *r1=-b/(2*a);
    delta=b*b-4*a*c;
    if(delta>=0)
        { *r2=sqrt(delta)/(2*a); }
    else
        { *r2=sqrt(-delta)/(2*a); }
    return (int)delta;
}