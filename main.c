#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"book.h"
#include"book.c"
#include"login.h"
#include"login.c"
void adminpart();
void studentpart();
int main()
{
    int who_ch;
    printf("Welcome to your Library Details Management Program\nWho are You ?\nAdmin --> 1\nStudent --> 2\nNew Login --> 3  ");
    scanf("%d",&who_ch);
    printf("\n");
    switch(who_ch) 
    {
        case 1:{
            int i = adminlogin();
            if (i == 1) {
                adminpart();
            }
            else {
                printf("Access Denied");
                getch();
            }
            break;
        }
        case 2:{
            int i = studentlogin();
            if (i==1) {
                studentpart();
            }
            else {
                printf("Access Denied");
                getch();
            }
            break;
        }
        case 3: {
            int ch;
            printf("New login Admin --> 1\nNew Login Student --> 2");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: {
                    newloginadmin();
                    adminpart();
                    break;
                }
                case 2: {
                    newloginstudent();
                    studentpart();
                    break;
                }
            }
        }
    }
    return 0;
}

void adminpart() {
    do {
                    
        int ch_admin;
        printf("\n\nWelcome To Admin Corner :\nAdd New Book in the Database --> 1\nView all Books in the Database --> 2\nSearch a Book by it's ID --> 3\nIssue a Book --> 4\nView Issued Books --> 5\nExit Program --> 6  ");
        scanf("%d",&ch_admin);
        printf("\n");
        switch (ch_admin)
        {
            case 1:{
                addbook();
                getch();
                break;
            }
            case 2:{
               viewbook();
               getch();
               break;
            }
            case 3:{
                searchbook();
                getch();
                break;
            }
            case 4:{
                issuedbookAdmin();
                getch();
                break;
            }
            case 5:{
                
            }
            case 6:{
                exit(0);
            }
        }
        printf("\n\n");
    }while(1);
}

void studentpart() {
    do {

        int ch_student;
        printf("\n\nWelcome to Student Corner :\nView Available Books --> 1\nView my Issued Books --> 2\nExit --> 3  ");
        scanf("%d",&ch_student);
        printf("\n");
        switch(ch_student)
        {
            case 1:{
                viewbookstudent();
                getch();
                break;
            }
            case 2: {
                viewissuebookstudent();
                getch();                
                break;
            }
            case 3: {
                exit(0);
            }
        }

        printf("\n\n");

    }while (1);
}