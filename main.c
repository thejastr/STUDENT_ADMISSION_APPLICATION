#include "student.h"

int main()
{
    int c,continue_choice,n=1;
    Student s[100];
    Program pg;
    char    branch[PROGRAM_NAME_LEN];
    printf("\n-----------------ADMISSION PROCESSS-----------------\n");
    while(n){
    printf("\nTo initialize program seats press 1\n");
    printf("\nTo register student presss 2\n ");
    printf("\nTo allot seats press 3\n");
    printf("\nTo check the number of applications submitted press 4\n");
    printf("\nTo check the number of seats filled press 5\n");
    printf("\nTo assign seats for wait listed students press 6\n");
    printf("\nEnter your choice :");
    scanf("%d",&c);
    switch(c){
        case 1:pg=program_seats(40,40,50);
               break;
        case 2:s[N0_OF_STUDENTS]=add_student();
               N0_OF_STUDENTS=N0_OF_STUDENTS+1;
               break;
        case 3:pg=allot(s,pg);
               break;
        case 4:printf("Total number of applications submitted :%d",N0_OF_STUDENTS);
               break;
        case 5:printf("\nEnter the branch that you want to check the filled seats\n");
               scanf("%s",branch);
               printf("\nThe seats filled is %d\n",filled_seats(pg,branch));
               break;
        case 6:pg=allot_waitlisted(s,pg);
        default:printf("\nInvalid choice\n");


    }
    printf("\nPress 1 to continue :");
    scanf("%d",&continue_choice);
    if(continue_choice==1){
            n=1;
    }
    else{
        n=0;
    }

    }


    return 0;
}
