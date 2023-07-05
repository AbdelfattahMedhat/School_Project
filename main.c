#include <stdio.h>
#include <stdlib.h>
#include"types & macros.h"
extern FILE*p;
int main()
{
    student_info School[SCHOOL_CAPACITY];
    fopen_s(&p,FILE_NAME,"r");
    fscanf(p,"%d",&School_Index);
    fprintf(p,"\n");
    string_print(file_scan(School));
    Start_Program(School);
    fclose(p);
    fopen_s(&p,FILE_NAME,"w");
    fprintf(p,"%d\n",School_Index);
    if(file_save(School))
    {
        printf("Data Saved Successfully");
    }
    fclose(p);
    return 0;
}
