//UNIVERSITY STUDENT DETAILS MAINTENANCE
/*PROGRAM ON SPARSE MATRIX IMPLEMENTATION USING LINKED LIST -A UNIVERSITY CONTAINS 500 STUDENTS AND THERE ARE 40 COURSES. EACH STUDENT CAN REGISTER FOR MAX. 10 COURSES(MIN. 0). IT IS REQUIRED TO STORE THE REGISTRATION DETAILS AND ALSO GENERATE THE REPORT BASED ON COURSE WISE REGISTRATION AND STUDENT WISE REGISTRATION.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[20];
    char usn[20];
    int regno;
    int courseno;
    char coursename[20];
    struct node *rlink;
    struct node *dlink;
};
typedef struct node *NODE;
int SN,CN;
NODE getnode(char sname[20], char susn[20],int cn, int rn, char cname[20])
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->regno=rn;
    temp->courseno=cn;
    strcpy(temp->coursename,cname);
    strcpy(temp->usn,susn);
    strcpy(temp->name,sname);
    temp->rlink=NULL;
    temp->dlink=NULL;
    return temp;
}
NODE insertright(NODE head,char name[20],char usn[20],int cn, int rn, char cname[20])
{
    NODE temp=getnode(name,usn,cn,rn,cname);
    NODE cur=head;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        cur->rlink=temp;
        return head;
    }
}
NODE insertdown(NODE head,char name[20],char usn[20],int cn, int rn, char cname[20])
{
    NODE temp=getnode(name,usn,cn,rn,cname);
    NODE cur=head;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else
    {
        while(cur->dlink!=NULL)
        {
            cur=cur->dlink;
        }
        cur->dlink=temp;
        return head;
    }
}
NODE createstudent(NODE head)
{
    int i,j,N;
    char name[20],usn[20],cn[20];
    for(i=1;i<=SN;i++)
    {
        printf("Enter the Name of Student-%d:\n",i);
        scanf("%s",name);
        printf("Enter the USN of Student-%d:\n",i);
        scanf("%s",usn);
        printf("Enter the number of Courses of Student-%d:\n",i);
        scanf("%d",&N);
        head = insertdown(head,name,usn,N,i,"\0");
    }
    return head;
}
NODE createcourse(NODE head)
{
    int i;
    char cn[20];
    printf("Enter the Course Name : ");
    for(i=1;i<=CN;i++)
    {
        scanf("%s",cn);
        head = insertright(head,"\0","\0",0,0,cn);
    }
    return head;
}
NODE matrix(NODE head)
{
    char cn[20];  int cono=1;
    NODE ccur = head->rlink; NODE dp=head->rlink;
    NODE scur = head->dlink;
    while(scur!=NULL)
    {
        ccur = head->rlink;
        printf(“Courses available are:\n”);
        while(dp!=NULL)
        {
           printf(“%d: %s\n”,cono,dp->coursename);
           dp=dp->rlink;
           cono++;
        }
         printf(“!!Enter course name according to the order shown!!\n”);
        printf("Enter the Courses of Student-%d:\n",scur->regno);
        for(int i=1;i<=scur->courseno;i++)
        {
            scanf("%s",cn);
            while(ccur!=NULL)
            {
                if(strcmp(ccur->coursename,cn)==0)
                {
                    ccur = insertdown(ccur,scur->name,scur->usn,scur->courseno,scur->regno,cn);
                    scur = insertright(scur,scur->name,scur->usn,scur->courseno,scur->regno,cn);
                    break;
                }
                ccur=ccur->rlink;
            }
        }
        scur=scur->dlink;
    }
    return head;
}
void studentdisplay(NODE head)
{
    NODE cur = head->dlink;
    NODE scur;
    while(cur!=NULL)
    {
        printf("Student-%d\n",cur->regno);
        printf("Name : %s || USN : %s\nCOURSES : ",cur->name,cur->usn);
        scur=cur->rlink;
        while(scur!=NULL)
        {
            printf("%s ",scur->coursename);
            scur=scur->rlink;
        }
        printf("\n");
        cur=cur->dlink;
    }
}
void coursedisplay(NODE head)
{
    NODE cur = head->rlink;
    NODE ccur;
    while(cur!=NULL)
    {
        printf("Students of %s :\n",cur->coursename);
        ccur=cur->dlink;
        while(ccur!=NULL)
        {
             printf("Name : %s || USN : %s\n",ccur->name,ccur->usn);
            ccur=ccur->dlink;
        }
        printf("\n");
        cur=cur->rlink;
    }
}
void main()
{
    int choice;
    printf("Enter the Number of Students : ");
    scanf("%d",&SN);
    printf("Enter the number of Courses : ");
    scanf("%d",&CN);
    NODE head=getnode("\0","\0",0,0,"\0");
    head->rlink=createcourse(head->rlink);
    for(;;)
    {
        printf("Menu:\n1.Enter Details\n2.Student-Wise Details\n3.Course-Wise Details\n4.Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the Details of %d Students\n",SN);
                     head->dlink=createstudent(head->dlink);
                     head = matrix(head);
                     break;
            case 2 : studentdisplay(head);
                     break;
            case 3 : coursedisplay(head);
                     break;
            case 4 : printf("!! THANK YOU !!\n");
                     exit(1);
            default : printf("Invalid Choice\n");
        }
    }
}


