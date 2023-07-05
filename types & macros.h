#ifndef TYPES_MACROS_H_INCLUDED
#define TYPES_MACROS_H_INCLUDED
#define MAX 100
#define FILE_NAME "school_dat.txt"
#define SCHOOL_CAPACITY 1000
extern int School_Index;
extern FILE*pt;
typedef enum
{
    Math,
    science,
    arabic,
    history,
    English,
    Subject_NUM
}Subjects_t;



typedef struct
{
    int Subjects[Subject_NUM];
}S_Subjects;
/*typedef enum
{
     math,
     arabic,
     history,
     science,
     total_subject
}subject_n;
typedef struct
{
    int Math,science,arabic,history;
}S_Subjects;*/
typedef struct
{
    int S_ID;
    char S_Name[20];
    int S_Age;
    char phone_number[11];
    char Address [20];
    S_Subjects subjects;
    char grade;
}student_info;
void Start_Program (student_info*school);
void add_student(student_info* Student);
void print_subject(S_Subjects* subjects);
void print_student(student_info* student,int s_num );
int search_student(student_info student[],char* name);
void Delete_student(student_info* student,int student_num);
void process_maker(student_info*school,int x);
void Edit_student(student_info*student,int i);
void Edit_student_subject(S_Subjects* subject,student_info*student);
void file_print(student_info*school);
char* file_scan(student_info*school);
#endif // TYPES_&_MACROS_H_INCLUDED
