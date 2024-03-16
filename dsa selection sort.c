#include<stdio.h>
#include<stdlib.h>
struct player
{
char name[20];
int age;
int ntests;
double avg;
int runs;
};
void readPlayer(struct player*,int);
void displayPlayer(struct player*,int);
void swap(void*a,void*,int);
void selectionSort(void*,int ,int,int(*cmp)(void*,void*));
int cmpntests(void*,void*);
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    struct player*p;
    p=(struct player*)malloc(sizeof(struct player)*n);
    readPlayer(p,n);
    displayPlayer(p,n);
    selectionSort(p,n,sizeof(struct player),cmpntests);
    printf("The sorted structure is:\n");
    displayPlayer(p,n);
}
void readPlayer(struct player*p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter name:");
        scanf("%s",&p[i].name);
        printf("Enter age:");
        scanf("%d",&p[i].age);
        printf("Enter number of tests:");
        scanf("%d",&p[i].ntests);
        printf("Enter avg:");
        scanf("%lf",&p[i].avg);
        printf("Enter runs:");
        scanf("%d",&p[i].runs);
    }
}
void displayPlayer(struct player*p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nName:%s\n",p[i].name);
        printf("Age:%d\n",p[i].age);
        printf("Number of tests:%d\n",p[i].ntests);
        printf("Average:%lf\n",p[i].avg);
        printf("Runs:%d\n",p[i].runs);
    }
}
void selectionSort(void*a,int n,int datasize,int(*cmp)(void*,void*))
{
    char*x,*y,*z;
    int i,j,max;
    for(i=0;i<n-1;i++)
    {
        max=i;
        x=(char*)(a+i*datasize);
        y=(char*)(a+max*datasize);
        for(j=i+1;j<n;j++)
        {
           z=(char*)(a+j*datasize);
            if((*cmp)(y,z))
            {
                max=j;
                y=(char*)(a+max*datasize);
              }
        }
        swap(x,y,datasize);
    }
}
void swap(void*a,void*b,int s)
{
    char*p=(char*)a;
    char*q=(char*)b;
    char temp;
    int i;
    for(i=0;i<s;i++)
    {
        temp=*p;
        *p=*q;
        *q=temp;
        p++;
        q++;
    }
}
int cmpntests(void*a,void*b)
{
    struct player*p=(struct player*)a;
    struct player*q=(struct player*)b;
    if(p->age<q->age)
        return 1;
    else
        return 0;
}
