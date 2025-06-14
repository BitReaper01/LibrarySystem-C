#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "common.h"
#include "book.h"

//defining addbook() function 
void addbook() {

    char price[20];
    Book book;
    printf("Enter Book ID : ");
    while (scanf("%d",&book.ID) != 1)
    {
        printf("\nInvalid Input. Enter book ID again : ");
    }
    getchar();    //it helps to eat the \n left in the buffer after using scanf
    printf("Enter Book Title : ");
    fgets(book.Title,sizeof(book.Title),stdin);
    book.Title[strcspn(book.Title,"\n")] = '\0';
    printf("Enter Book Author : ");
    fgets(book.Author,sizeof(book.Author),stdin);
    book.Author[strcspn(book.Author,"\n")] = '\0'; //it changes the \n in the string to \0 at that index
    printf("Enter Book Price (in INR): ");
    while (1)
    {
        fgets(price,sizeof(price),stdin);
        if (sscanf(price,"%f",&book.Price)!=1)
        printf("Enter Correct Price\n");
        else
        break;
    }
    printf("Enter Quantity of Books : ");
    while (scanf("%d",&book.Quantity) != 1)
    {
        printf("\nInvalid Input. Enter Quantity again : ");
    }
    getchar();

    FILE *fp = fopen("book.bin","ab");
    if (fp == NULL) 
    printf("Book Not Stored");

    fwrite(&book,sizeof(Book),1,fp);
    fclose(fp);

    printf("\n\nBook Stored");

}

//defining viewbook() function
void viewbook() {

    FILE *fp = fopen("book.bin","rb");
    if (fp == NULL)
    {
        printf("No Book Stored");
        exit(0);
    }

    Book book;
    printf("-------------------------Books List-------------------------\n\n");
    while (fread(&book,sizeof(Book),1,fp)==1)
    {
        printf("Book ID = %d | Book Title = %s | Book Author = %s | Book Price = %f INR | Book Quantity = %d\n",book.ID,book.Title,book.Author,book.Price,book.Quantity);
    }
    fclose(fp);
}

//defining searchbook() function
void searchbook() {

    int ID,flag=0;
    Book book;

    printf("Enter Book ID to search : ");
    while (scanf("%d",&ID) != 1)
    {
        printf("\nInvalid Input. Enter book ID again : ");
    }
    getchar();

    FILE *fp = fopen("book.bin","rb");
    while (fread(&book,sizeof(Book),1,fp) == 1)
    {
        if (book.ID == ID)
        {
            printf("Book ID = %d | Book Title = %s | Book Author = %s | Book Price = %f INR | Book Quantity = %d\n",book.ID,book.Title,book.Author,book.Price,book.Quantity);
            flag = 1;
            break;        
        }
    }
    if (flag == 0)
    printf("Book not found");
    
    fclose(fp);

}


//defining issuedbookAdmin() function
void issuedbookAdmin() {

    IssuedBookAdmin details;
    printf("Enter Book ID : ");
    while (scanf("%d",&details.bookID) != 1)
    {
        printf("\nInvalid Input. Enter ID again : ");
    }
    getchar();
    printf("Enter Book Title : ");
    fgets(details.bookTitle,sizeof(details.bookTitle),stdin);
    details.bookTitle[strcspn(details.bookTitle,"\n")] = '\0';
    printf("Enter Book Author : ");
    fgets(details.bookAuthor,sizeof(details.bookAuthor),stdin);
    details.bookAuthor[strcspn(details.bookAuthor,"\n")] = '\0';
    printf("Enter Student ID : ");
    while (scanf("%d",&details.studentID) != 1)
    {
        printf("\nInvalid Input. Enter student ID again : ");
    }
    getchar();
    printf("Enter Student Name : ");
    fgets(details.studentName,sizeof(details.studentName),stdin);
    details.studentName[strcspn(details.studentName,"\n")] = '\0';
    printf("Enter Due Date : ");
    fgets(details.duedate,sizeof(details.duedate),stdin);
    details.duedate[strcspn(details.duedate,"\n")] = '\0';

    FILE *fp = fopen("issue.bin","ab");
    if (fp == NULL)
    {
        printf("Issue File missing");
        exit(0);
    }
    fwrite(&details,sizeof(IssuedBookAdmin),1,fp);
    fclose(fp);

    Book book;
    FILE *f = fopen ("book.bin","r+b"); //the r+b mode can read and write at any location
    if (f == NULL)
    {
        printf("Failed to Issue book ");
        exit(0);
    }
    while (fread(&book,sizeof(Book),1,f)==1)
    {
        if (book.ID == details.bookID)
        {
            if (book.Quantity > 0)
            {
                book.Quantity = book.Quantity - 1;
                printf("Book Issued Successfully");
                break;
            }
            else
            {
                printf("Book out of Stock");
                break;
            }
        }

    }
    fseek(f,-(long)sizeof(Book),SEEK_CUR);
    fwrite(&book,sizeof(Book),1,f);
    fclose(f);
    
}


//defining viewbookstudent() function
void viewbookstudent() {

    FILE *fp = fopen("book.bin","rb");
    Book book;
    if (fp == NULL)
    {
        printf("No books available");
        exit(0);
    }
    while (fread(&book,sizeof(Book),1,fp)==1)
    {
        if (book.Quantity > 0)
        {
            printf("Book ID : %d | Book Title : %s | Book Author : %s | Book Price : %f | Quantity : %d\n",book.ID,book.Title,book.Author,book.Price,book.Quantity);
        }
    }

    fclose(fp);
}

//defining viewissuebookstudent() function 
void viewissuebookstudent() {
    IssuedBookAdmin student;
    printf("Enter your Student ID : ");
    int ID;
    while (scanf("%d",&ID) != 1)
    {
        printf("\nInvalid Input. Enter book ID again : ");
    }
    FILE *fp = fopen("issue.bin","rb"); 
    if (fp == NULL)
    {
        printf("No Books issued");
        exit(0);
    }
    while (fread(&student,sizeof(IssuedBookAdmin),1,fp) == 1)
    {
        if (student.studentID == ID)
        {
            printf("Book ID : %d | Book title : %s | Book Author : %s | Due date : %s\n",student.bookID,student.bookTitle,student.bookAuthor,student.duedate);
            break;
        }
    }

    fclose(fp);
}

//defining viewissuebookadmin() function 
void viewissuebookadmin() {

    IssuedBookAdmin student;
    FILE *fp = fopen("issue.bin","rb");
    if (fp == NULL)
    {
        printf("No books issued yet");
        exit(0);
    }
    while (fread(&student,sizeof(IssuedBookAdmin),1,fp) == 1)
    {
        printf("Book ID : %d | Book title : %s | Book Author : %s | Student ID : %d | Student Name : %s | Due date : %s\n",student.bookID,student.bookTitle,student.bookAuthor,student.studentID,student.studentName,student.duedate);
    }
    fclose(fp);
}   