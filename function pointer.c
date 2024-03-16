#include<stdio.h>
double add(double a,double b)
{
    return a+b;
}
double mul(double a,double b)
{
    return a*b;
}
double sub(double a,double b)
{
    return a-b;
}
double div(double a,double b)
{
    return a/b;
}
int main()
{
    double (*p[])(double,double)={add,sub,mul,div};
    double a,b,c;
    int ch;
    printf("enter a and b:");
    scanf("%lf%lf",&a,&b);
    printf("enter choice:");
    scanf("%d",&ch);
    c=(*p[ch-1])(a,b);
    printf("%lf\n", c);
}
