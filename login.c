#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "login.h"

//defining newloginstudent() function
void newloginstudent() {

    Student student;
    printf("Enter your Student ID (It will be your ID to login) : ");
    scanf("%d",&student.ID);
    getchar();
    printf("Enter your Name : ");
    fgets(student.Name,sizeof(student.Name),stdin);
    student.Name[strcspn(student.Name,"\n")] = '\0';
    printf("Enter your Course : ");
    fgets(student.Course,sizeof(student.Course),stdin);
    student.Course[strcspn(student.Course,"\n")] = '\0';
    printf("Enter your Password to login : ");
    fgets(student.Password,sizeof(student.Password),stdin);
    student.Password[strcspn(student.Password,"\n")] = '\0';

    FILE *fp = fopen("student.bin","ab");
    if (fp == NULL)
    {
        printf("\nLogin Credentials not Saved");
    }
    fwrite(&student,sizeof(Student),1,fp);
    printf("Login Credentials Saved");

    fclose(fp);
}


//defining newloginadmin() function
void newloginadmin() {

    Admin admin;
    printf("Enter your Admin ID (It will be your ID to login) : ");
    scanf("%d",&admin.ID);
    getchar();
    printf("Enter your Name : ");
    fgets(admin.Name,sizeof(admin.Name),stdin);
    admin.Name[strcspn(admin.Name,"\n")] = '\0';
    printf("Enter your Password to login : ");
    fgets(admin.Password,sizeof(admin.Password),stdin);
    admin.Password[strcspn(admin.Password,"\n")] = '\0';

    FILE *fp = fopen("admin.bin","ab");
    if (fp == NULL)
    {
        printf("\nLogin Credentials not Saved");
    }
    fwrite(&admin,sizeof(Admin),1,fp);
    printf("Login Credentials Saved");

    fclose(fp);
}

//defining adminlogin() function
int adminlogin() {

    int adminID,i=0;
    char ch = '0';
    char adminPassword[100];
    printf("Enter Admin ID : ");
    while (scanf("%d",&adminID) != 1)
    {
        printf("\nInvalid Input. Enter admin ID again : ");
        while (getchar() != '\n');
    }
    getchar();
    printf("Enter Password : ");
    while(ch!=13) {
        ch =  _getch();
        if (ch==8)
        continue;
        adminPassword[i] = ch;
        i++;
        printf("*");
    }
    adminPassword[i] = '\0';
    Admin admin;
    FILE *fp = fopen("admin.bin","rb");
    if (fp == NULL)
    {                                                         
        printf("No Admin Database found");
        exit(3);
    } 
    while (fread(&admin,sizeof(Admin),1,fp)==1) {
        if (adminID == admin.ID)
        {
            if (strcmp(adminPassword,admin.Password) == 1)
            return 1;
        }
    }
    return 0;
}

//defining studentlogin() function
int studentlogin() {

    int studentID,i=0;
    char ch = '0';
    char studentPassword[100];
    printf("Enter Student ID : ");
    while (scanf("%d",&studentID) != 1)
    {
        printf("\nInvalid Input. Enter student ID again : ");
    }
    getchar();
    printf("Enter Password : ");
    while(ch!=13) {
        ch = _getch();
        if (ch == 8)
        continue;
        studentPassword[i] = ch;
        i++;
        printf("*");
    }
    studentPassword[i] = '\0';
    Student student;
    FILE *fp = fopen("student.bin","rb");
    if (fp == NULL)
    {
        printf("No Student Database found");
        exit(3);
    } 
    while (fread(&student,sizeof(Admin),1,fp)==1) {
        if (studentID == student.ID)
        {
            if (strcmp(studentPassword,student.Password) == 1)
            return 1;
        }
    }
    
    return 0;
}