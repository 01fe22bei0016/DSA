#include<stdio.h>
struct point
{
    double x;
    double y;
};
int main()
{
    struct point p1={1.1,2.2};
    struct point p2={8.8,9.9};
    struct point temp;
    temp=p1;
    p1=p2;
    p2=temp;
printf("p1.x=%lf\n",p1.x);
printf("p1.y=%lf\n",p1.y);
printf("p2.x=%lf\n",p2.x);
printf("p2.y=%lf\n",p2.y);
}
