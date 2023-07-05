#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"types & macros.h"
int School_Index=0;
FILE *p=NULL;
const char Subject_names [Subject_NUM][10] =
{
    "Math",
    "science",
    "arabic",
    "history",
    "English"
};
void string_scan(char*str,int maxsize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    while (str[i]!='\n' && i<maxsize-1)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i] = 0;
}
void string_print(char * str)
{
    int i;
    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}
int string_compare(char*str1,char *str2)
{
    int i;
    for(i=0; str1[i]&&str2[i]; i++)
    {
        if(str1[i]==str2[i])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    if(str1[i]||str2[i])
    {
        return 0;
    }
    return 1;
}
void add_student(student_info* student)
{

    printf("Enter student name:");
    string_scan((student+School_Index)->S_Name,20);
    printf("Enter student age:");
    scanf("%d",&(student+School_Index)->S_Age);
    printf("Enter student address:");
    string_scan((student+School_Index)->Address,20);
    printf("Enter student phone number:");
    string_scan((student+School_Index)->phone_number,11);
    (student+School_Index)->S_ID = School_Index+1;
    (student+School_Index)->grade='n';
    School_Index++;
}
char grade_calcultor(int grade)
{
    if(grade>=85)
    {
        return 'A';
    }
    else if(grade<85 && grade>=75)
    {
        return 'B';
    }
    else if(grade<75 && grade>=65)
    {
        return 'C';
    }
    else if(grade<65 && grade>=50)
    {
        return 'E';
    }
    else
    {
        return 'F';
    }
}
void print_subject(S_Subjects* subjects)
{
   for(int i =0; i<Subject_NUM; i++)
   {
        printf("%s, %d\n", Subject_names[i], subjects->Subjects[i]);
   }
}
/*void print_subject(S_Subjects* subjects)
{
    printf("math       science     Arabic      history\n");
    printf("%2d/%2d     %2d/%2d      %2d/%2d       %2d/%2d  \n",\
           subjects->Math,MAX,subjects->science,MAX,\
           subjects->arabic,MAX,subjects->history,MAX);

}*/
void print_student(student_info* student,int s_num )
{
    printf("===============================\n");
    string_print((student+s_num)->S_Name);
    printf("%d\n",(student+s_num)->S_ID);
    printf("%d\n",(student+s_num)->S_Age);
    string_print((student+s_num)->Address);
    string_print((student+s_num)->phone_number);
    print_subject(&(student+s_num)->subjects);
    printf("%c\n",(student+s_num)->grade);
    printf("===============================\n");
}
int search_student(student_info student[],char* name)
{
    int i;
    for(i=0; i<School_Index; i++)
    {
        if(string_compare(name,student[i].S_Name))
        {
            return i;
        }
    }
    return -1;
}
void Edit_student(student_info*student,int i)
{
    string_print((student+i)->S_Name);
    printf("Editing...\n");
    printf("Enter student age:");
    scanf("%d",&(student+i)->S_Age);
    printf("Enter student address:");
    string_scan((student+i)->Address,20);
    printf("Enter student phone number:");
    string_scan((student+i)->phone_number,11);
    printf("Done.\n");
}
void file_print(student_info*school)
{

    fprintf(p,"%s,\n",school->S_Name);
    fprintf(p,"%d\n",school->S_Age);
    fprintf(p,"%s\n",school->Address);
    fprintf(p,"%s\n",school->phone_number);
    fprintf(p,"%d\n",school->S_ID);
    fprintf(p,"%c\n",school->grade);
    for(int i =0; i<Subject_NUM; i++)
   {
        fprintf(p,"%d  ",school->subjects.Subjects[i]);
   }
    /*fprintf(p,"%d  ",school->subjects.arabic);
    fprintf(p,"%d  ",school->subjects.Math);
    fprintf(p,"%d  ",school->subjects.history);
    fprintf(p,"%d  \n",school->subjects.science);*/
}
char* file_scan(student_info*school)
{
    int i;
    for(i=0; i<School_Index; i++)
    {
        fscanf(p,"%[^,]",(school+i)->S_Name);
        fprintf(p,"\n");
        fscanf(p,"%d\n",&(school+i)->S_Age);
        fscanf(p,"%[^\n]",(school+i)->Address);
        fscanf(p,"%s\n",(school+i)->phone_number);
        fscanf(p,"%d\n",&(school+i)->S_ID);
        fscanf(p,"%c",&(school+i)->grade);
        for(int i =0; i<Subject_NUM; i++)
   {
        fscanf(p,"%d  ",&(school+i)->subjects.Subjects[i]);
   }
        /*
        fscanf(p,"%d  ",&(school+i)->subjects.arabic);
        fscanf(p,"%d  ",&(school+i)->subjects.Math);
        fscanf(p,"%d  ",&(school+i)->subjects.history);
        fscanf(p,"%d  ",&(school+i)->subjects.science);
        */
    }
    printf("students=%d\n",School_Index);
    return "data base loaded";
}
int file_save(student_info*school)
{
    for(int i=0; i<School_Index; i++)
    {
        file_print(school+i);
    }
    printf("\n====Done====\n");
    return 1;
}
void Edit_student_subject(S_Subjects* subject,student_info*student)
{
    /*printf("math degree:");
    scanf("%d",&subject->Math);
    printf("science degree:");
    scanf("%d",&subject->science);
    printf("arabic degree:");
    scanf("%d",&subject->arabic);
    printf("history degree:");
    scanf("%d",&subject->history);*/
    int res = 0, i;
    for(i =0; i<Subject_NUM; i++)
   {
       printf("%s\n", Subject_names[i]);
       scanf("%d", &subject->Subjects[i]);
        res += subject->Subjects[i];
   }
    res /= (Subject_NUM);
    student->grade=grade_calcultor(res);
}
void Delete_student(student_info* student,int student_num)
{
    char c;
    printf("Are you sure you want to delete:");
    print_student(student,student_num);
    printf("if Yes press y if No press any key\n\n");
    scanf("%c",&c);
    if(c=='y' || c=='Y')
    {
        for(int i=student_num; i<School_Index; i++)
        {
            student[i]=student[i+1];
            student[i].S_ID=i+1;
        }
        School_Index--;
    }
}
void process_maker(student_info*school,int x)
{
    char name[20];
    switch(x)
    {
    case 1://add new student.
        add_student(school);
        break;
    case 2://edit student information by name.
        printf("Enter name of student:");
        string_scan(name,20);
        x=search_student(school,name);
        if(x==-1)
        {
            printf("student not found");
        }
        else
        {
            Edit_student(school,x);
        }
        print_student(school,search_student(school,name));
        break;
    case 3://print student information by name.
        printf("Enter name of student:");
        string_scan(name,20);
        x=search_student(school,name);
        if(x==-1)
        {
            printf("student not found");
        }
        else
        {
            print_student(school,x);
        }
        break;
    case 4://delete student from data base by name.
        printf("Enter name of student:");
        string_scan(name,20);
        x=search_student(school,name);
        if(x==-1)
        {
            printf("student not found");
        }
        else
        {
            Delete_student(school,x);
        }
        break;
    case 5://print student information by name.
        for(int i=0; i<School_Index; i++)
        {
            print_student(school,i);
        };
        break;
    case 6://call student by name.
        printf("Enter name of student:");
        string_scan(name,20);
        x=search_student(school,name);
        if(x==-1)
        {
            printf("student not found");
        }
        else
        {
        printf("calling ");
        string_print((school+x)->phone_number);
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<4; j++)
            {
                Sleep(1000);
                printf(".");
            }
            printf("\r");
            for(int j=0; j<4; j++)
            {

                printf(" ");
            }
            printf("\r");
        }
        printf("NO Answer!");
        }

        break;
    case 7://edit student subjects by name.
        printf("Enter name of student:");
        string_scan(name,20);
        x=search_student(school,name);
        if(x==-1)
        {
            printf("student not found");
        }
        else
        {
        string_print((school+x)->S_Name);
        Edit_student_subject((&(school+x)->subjects),(school+x));
        }
        break;
    case 0://save data in external file and exit by if condition at start_progam fun.
        printf("Thanks.");
        break;
    }
}
void Start_Program (student_info*school)
{
    int x;
    while(1)
    {
        printf("\n=======================================\n");
        printf("1-Add student\n2-Edit student info\n3-Print student\n4-Delete student\
               \n5-print school\n6-call student\n7-Edit student subject\
               \n0-Exit&Save\nNumber of students in school=%d\n\n",School_Index);
        printf("======================================\n");
        scanf("%d",&x);
        process_maker(school,x);
        if(x==0)
        {
            break;
        }
        printf("\n==================================\n");
    }

}
