#ifndef COMMON_H

#define COMMON_H

//book structure defined
typedef struct 
{
    int ID;
    char Title[100];
    char Author[100];
    float Price ;
    int Quantity;
}Book;

//student structure defined
typedef struct {
    int ID;
    char Name[50];
    char Course[50];
    char Password[100];
}Student;

//admin structure defined
typedef struct {
    int ID;
    char Name[50];
    char Password[100];
}Admin;

//issued books structure defined
typedef struct {
    int bookID;
    char bookTitle[100];
    char bookAuthor[100];
    int studentID;
    char studentName[100];
    char duedate[30];
}IssuedBookAdmin;

#endif