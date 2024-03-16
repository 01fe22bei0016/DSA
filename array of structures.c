
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

struct date
{
    int d,m,y;
};
struct student
{
    int rno;
    char name[20];
    char dept[20];
    int nCourse;
    char course[5][20];
    int yoj;
    struct date dob;
};
void readStudentRecord(struct student [],int);
void displayStudentRecord(struct student [],int);
void displayYear(struct student [],int ,int);
void displayRno(struct student [],int,int);
void displayDept(struct student [],int ,char []);
void displayName(struct student [],int ,char []);
void displayDOB(struct student [],int);
void displayCourse(struct student [],int);
void startsWithA(struct student [],int);
void displayPrimeRno(struct student [],int);
int isPrime(int );

int main()
{
    struct student s[450];
    int n;
    printf("Enter n:");
    scanf("%d",&n);

    readStudentRecord(s,n);

    displayStudentRecord(s,n);

    int y;
    printf("\nEnter the year to be found:");
    scanf("%d",&y);
    displayYear(s,n,y);

    int rno;
    printf("\nEnter the rno to be found:");
    scanf("%d",&rno);
    displayRno(s,n,rno);

    char dept[20];
    printf("\nEnter the dept to be found:");
    scanf("%s",&dept);
    displayDept(s,n,dept);

    char name[20];
    printf("\nEnter the name to be searched:");
    scanf("%s",&name);
    displayName(s,n,name);

    printf("Details of all the students born on or after 1st-AUG-2000 are:\n");
    displayDOB(s,n);

    printf("Details of all the students who chose physics are:\n");
    displayCourse(s,n);

    printf("Details of all the students whose name starts with A:\n");
    startsWithA(s,n);

    printf("Details of all the students whose rno is prime:\n");
    displayPrimeRno(s,n);

    return 0;
}
void readStudentRecord(struct student s[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Enter rno:");
        scanf("%d",&s[i].rno);
        printf("Enter name:");
        scanf("%s",&s[i].name);
        printf("Enter the department:");
        scanf("%s",&s[i].dept);
        printf("Enter number of courses:");
        scanf("%d",&s[i].nCourse);
        printf("Enter the courses:\n");
        for(j=0;j<s[i].nCourse;j++)
        {
            scanf("%s",&s[i].course[j]);
        }
        printf("Enter yoj:");
        scanf("%d",&s[i].yoj);
        printf("Enter the DOB in dd-mm-yyyy:");
        scanf("%d%*c",&s[i].dob.d);
        scanf("%d%*c",&s[i].dob.m);
        scanf("%d",&s[i].dob.y);
    }
}
void displayStudentRecord(struct student s[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\nRno:%d\n",s[i].rno);
        printf("Name:%s\n",s[i].name);
        printf("Dept:%s\n",s[i].dept);
        printf("No. of courses:%d\n",s[i].nCourse);
        printf("Courses are:\n");
        for(j=0;j<s[i].nCourse;j++)
        {

            printf("%s\n",s[i].course[j]);
        }
        printf("YOJ:%d\n",s[i].yoj);
        printf("DOB IS:");
        printf("%d-",s[i].dob.d);
        printf("%d-",s[i].dob.m);
        printf("%d\n",s[i].dob.y);
    }
}
void displayYear(struct student s[],int n,int y)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].yoj==y)
            displayStudentRecord((s+i),1);
    }
}
void displayRno(struct student s[],int n,int rno)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].rno==rno)
            displayStudentRecord((s+i),1);
    }
}
void displayDept(struct student s[],int n,char dept[])
{
    int i,c;
    for(i=0;i<n;i++)
    {
        c=strcasecmp(s[i].dept,dept);
        if(c==0)
            displayStudentRecord((s+i),1);
    }
}
void displayName(struct student s[],int n,char name[])
{
    int i,k;
    for(i=0;i<n;i++)
    {
        k=strcasecmp(s[i].name,name);
        if(k==0)
            displayStudentRecord((s+i),1);
    }
}
void displayDOB(struct student s[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(s[i].dob.y>2000)
            displayStudentRecord((s+i),1);
        else if(s[i].dob.y==2000&&s[i].dob.m>=8)
            displayStudentRecord((s+i),1);
    }
}
void displayCourse(struct student s[],int n)
{
    int i,c,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<s[i].nCourse;j++)
        {
            c=strcasecmp(s[i].course[j],"PHYSICS");
            if(c==0)
                displayStudentRecord((s+i),1);
            break;
        }
    }
}
void startsWithA(struct student s[],int n)
{
    int i,c;
    for(i=0;i<n;i++)
    {
        if(s[i].name[0]=='a'||s[i].name[0]=='A')
                displayStudentRecord((s+i),1);
    }
}
void displayPrimeRno(struct student s[],int n)
{
    int i,p;
    for(i=0;i<n;i++)
    {
        p=isPrime(s[i].rno);
            if(p)
                displayStudentRecord((s+i),1);
    }
}
int isPrime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}
