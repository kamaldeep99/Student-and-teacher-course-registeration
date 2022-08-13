// confusion: 1 data type of Course Load for the term
// 3rd point-> prompt for choice in: program? program doesn;t exists in Student struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float sum=0;
char string1[20];
char string2[20];
char ans;
int m=3;
int k=0;
int l=0;
int flag2=0;
int flag3=0;

typedef struct Student {
    char id[25];
    char name[20];
    char Email_id[20];
    char status[14];
    char presence[10];
    int Currentsemester;
    int totalcs;
    struct final_grades_per_course
    {
        char CourseID[20];
        float final_grade; 
    }gradepercourse[30];
    float current_avg;
}Std;

typedef struct teacher {
    char id[20];
    char name[20];
    char mobile[11];
    char status[14];
    float Seniorty;
    int totalts;
    struct Corseload
    {
        char CourseID[20];
    }Corseload[35];
    
}Tea;


typedef struct course {
    char id[20];
    char name[25];
    float hours;
    int semester;
}Cou;

Std Studentarray[250];
Tea teacherarray[25];
Cou  coursearray[35];
int total_course = 0;
struct checkrepeat
    {
        char sid[25] ;
        char tid[25] ;
        char cid[25] ;
        char cname[25];
    }Checkrepeat[250];
Std fillStudentInfo(Cou coursearray[35] ){
    printf("Enter the  information: \n");
    
                
    
    
    Std temoporarystudentarray; 
    if(k==0)
            {
            printf("Student Id : ");
            fflush(stdin); 
            scanf("%s", temoporarystudentarray.id);
            strcpy(Checkrepeat[k].sid,temoporarystudentarray.id);
           
            }
    else
        {   
            
            while(1)
            {       flag2=0;
                    printf("Enter student ID (note that it must be unique from previously entered id value otherwise you have to enter it again) : \n");
                    fflush(stdin);

                    scanf("%s", temoporarystudentarray.id);
                   
                    strcpy(Checkrepeat[k].sid,temoporarystudentarray.id);
                    
                   
                    
                for(int i=0;i<k;i++)
                {    
                    if(strcmp(Checkrepeat[i].sid,temoporarystudentarray.id)==0)
                    {   
                        
                        flag2=1;
                        printf("id already present Enter another id \n");
                        break;

                    }

                }
                if(flag2==0)
                { 
                    break;
                }
            

            }
        }

    
    
    
    printf("\nStudent Name(avoid space between first and latname): ");
    fflush(stdin);    
    
    scanf("%s", temoporarystudentarray.name); 

    
    printf("\nStudent Email: ");
     fflush(stdin);    
    scanf("%s", temoporarystudentarray.Email_id); 
    
    while(1){printf("\nStudent Status (local or international): ");

        fflush(stdin);

    
    scanf("%s", temoporarystudentarray.status);
  
    
    

    
    if (!strcmp(temoporarystudentarray.status,"LOCAL")||!strcmp(temoporarystudentarray.status,"local"))
    {   break;

    }
    else if(!strcmp(temoporarystudentarray.status,"INTENATIONAL")||!strcmp(temoporarystudentarray.status,"international"))
    {break;}
    else{
        printf("\ninvalid input enter again\n ");
    }

    }
    
    while(1){printf("\nPresence (montreal or abroad): "); 
    fflush(stdin);
    scanf("%s", temoporarystudentarray.presence);
   

    
    if (!strcmp(temoporarystudentarray.presence,"MONTREAL")||!strcmp(temoporarystudentarray.presence,"montreal"))
    {   break;

    }
    else if(!strcmp(temoporarystudentarray.presence,"ABROAD")||!strcmp(temoporarystudentarray.presence,"abroad"))
    {break;}
    else{
        printf("\ninvalid input enter again\n ");
    }

    }
    do{printf("\nCurrent Semester (1-4): "); 
    fflush(stdin);
    scanf("%d", &temoporarystudentarray.Currentsemester);
    if(temoporarystudentarray.Currentsemester <1 || temoporarystudentarray.Currentsemester>4)
    {
        printf("\ninvalid input enter again\n ");
    }
    }while(temoporarystudentarray.Currentsemester <1 || temoporarystudentarray.Currentsemester>4);

    do{printf("\nPlease enter Total number of Courses(1-%d): ",m);
    fflush(stdin);
    scanf("%d",&temoporarystudentarray.totalcs);
    if(temoporarystudentarray.totalcs>m)
    {
        printf("\nNote that there are only %d courses in college course inventory so a student can  at max have %d courses .If you want to see the courses which already  college offer then press y or Y if not press n or N \n"
        ,m,m);
        fflush(stdin);
        scanf("%c",&ans);
        if(ans=='y'||ans=='Y')
        {   
            for ( int i=0;i<m;i++)
            {CourseDisplayFunction(coursearray[i]);}


        }




    }
    
    }while(temoporarystudentarray.totalcs>m);



    printf("\nTransscript(Final grades per course)\n");

    for (int i = 0; i < temoporarystudentarray.totalcs; i++){
        flag2=0;
        while(flag2==0)
       {printf("\n%d) Enter Course Id: ",i+1);
        fflush(stdin);
        scanf("%s",temoporarystudentarray.gradepercourse[i].CourseID);
                for(int j=0;j<m;j++)
                {   
                    if(strcmp(temoporarystudentarray.gradepercourse[i].CourseID,coursearray[j].id)==0)
                        {   flag2=1;
                            break;
                        }
                        
                }
                if(flag2==0)
                {
                    printf("\nThe course you entered doesnot exist in course inventory \n");
                    printf("\ndo you want to see which course exist in course inventory if you want press y else type n\n ");
                    fflush(stdin);
                    scanf("%c",&ans);
                    if(ans=='y'||ans=='Y')
                    {
                        for ( int i=0;i<m;i++)
                        {CourseDisplayFunction(coursearray[i]);}
                    }
                    printf("\nIf yourse course id is not in above list and want to assign this course to student you need to add this course to inventory first before assigning it to student or choose a course from above list.\n ");
                    printf("\nTo add new course to the inventory You need to run the programme again and first select course option in data entry option from main menu and after adding it to course inventory then assign it to students who wants this course.\n ");
                    
                }
                
        }
        
        
        
        do{printf("\nFinal Grades for %s .But note that grades can be between 0 to 100: \n", temoporarystudentarray.gradepercourse[i].CourseID);
        fflush(stdin);

        scanf("%f", &temoporarystudentarray.gradepercourse[i].final_grade);}while(temoporarystudentarray.gradepercourse[i].final_grade<0||temoporarystudentarray.gradepercourse[i].final_grade>100);
        sum=sum+temoporarystudentarray.gradepercourse[i].final_grade;
        
    }

        temoporarystudentarray.current_avg=sum/temoporarystudentarray.totalcs;
    
    
    
    return temoporarystudentarray; 
}

Tea fillTeacherInfo(){
    Tea temoporaryteacherarray;
    printf("\nEnter the  information: \n");
     
    
    

    if(l==0)
            {
            printf("\nTeacherId: "); 
            scanf("%s", temoporaryteacherarray.id);
            strcpy(Checkrepeat[l].tid,temoporaryteacherarray.id);
            
            }
    else
        {   
            
            while(1)
            {       flag2=0;
                    printf("\nEnter Teacher ID (note that it must be unique from previously entered id value otherwise you have to enter it again) : \n");
                    fflush(stdin);

                    scanf("%s", temoporaryteacherarray.id);
                   
                    strcpy(Checkrepeat[l].tid,temoporaryteacherarray.id);
                    
                   
                    
                for(int i=0;i<l;i++)
                {    
                    if(strcmp(Checkrepeat[i].tid,temoporaryteacherarray.id)==0)
                    {   
                        
                        flag2=1;
                        printf("\nid already present Enter another id \n");
                        break;

                    }

                }
                if(flag2==0)
                { 
                    break;
                }
            

            }
        }

    
    
    printf("\nName (avoid space between first and lastname): ");
    fflush(stdin);    
    scanf("%s", temoporaryteacherarray.mobile); 

    

    
    
    printf("\nMobile: ");
    fflush(stdin);
    scanf("%s", temoporaryteacherarray.mobile); 
    while(1) {
    printf("\nStatus (permanent, parttimer): ");
    scanf("%s", temoporaryteacherarray.status);
    
    if (!strcmp(temoporaryteacherarray.status,"PERMANENT")||!strcmp(temoporaryteacherarray.status,"permanent"))
    {   break;

    }
    else if(!strcmp(temoporaryteacherarray.status,"PARTTIMER")||!strcmp(temoporaryteacherarray.status,"parttimer"))
    {break;}
    else{
        printf("\ninvalid input enter again\n ");
    }

    }

    do{
        printf("\nSeniority(note that seniority value lies between 0.00 to 20.0): ");
        fflush(stdin);
        scanf("%f", &temoporaryteacherarray.Seniorty);
        if((temoporaryteacherarray.Seniorty<0||temoporaryteacherarray.Seniorty>20))
        {
            printf("\ninvalid input enter again\n ");
        }
    }while(temoporaryteacherarray.Seniorty<0||temoporaryteacherarray.Seniorty>20);


    do{printf("\nPlease enter Total number of Courses(1-%d) : ",m);
    fflush(stdin);
    scanf("%d",&temoporaryteacherarray.totalts);
    if(temoporaryteacherarray.totalts>m)
    {
        printf("\nNote that there are only %d courses in college course inventory so a teacher can teach at max have %d courses .If you want to see the courses which already  college offer then press y or Y else type n\n"
        ,m,m);
        fflush(stdin);
        scanf("%c",&ans);
        if(ans=='y'||ans=='Y')
        {   
            for ( int i=0;i<m;i++)
            {CourseDisplayFunction(coursearray[i]);}


        }



    }
    
    }while(temoporaryteacherarray.totalts>m);

     printf("\nPlease enter the Course Id\n");

    for (int i = 0; i < temoporaryteacherarray.totalts; i++)
    {
        flag2=0;
        while(flag2==0)
       {printf("\n%d) Enter Course Id: ",i+1);
        fflush(stdin);
        scanf("%s",temoporaryteacherarray.Corseload[i].CourseID);
                for(int j=0;j<m;j++)
                {   
                    if(strcmp(temoporaryteacherarray.Corseload[i].CourseID,coursearray[j].id)==0)
                        {   flag2=1;
                            break;
                        }
                        
                }
                if(flag2==0)
                {
                    printf("The course you entered doesnot exist in course inventory \n");
                    printf("\ndo you want to see which course exist in course inventory if you want press y else type n\n ");
                    fflush(stdin);
                    scanf("%c",&ans);
                    if(ans=='y'||ans=='Y')
                    {
                        for ( int i=0;i<m;i++)
                        {CourseDisplayFunction(coursearray[i]);}
                    }
                    printf("\nIf yourse course id is not in above list and want to assign this course to this teacher you need to add this course to inventory first before assigning it to teacher or choose a course from above list.\n ");
                     printf("\nTo add new course to the inventory You need to run the programme again and first select course option in data entry option from main menu and after adding it to course inventory then assign it to teacher who wants this course.\n ");

                    
                    
                }
                
        }
    }

    

   

    
    return temoporaryteacherarray;  
}

Cou fillCourseInfo(){
    
    Cou temporarycoursearray; 
    printf("\nEnter the  information: \n");
    
    
                 
                    
               
            
    



    if(m==3)
            {       while(1)
                        {
                        printf("\nCourse Id (note that it must be different from courses already in inventry otherwise it will ask course id again to avoid  repeated course id in inventory): \n");
                        fflush(stdin); 
                        scanf("%s", temporarycoursearray.id);
                        strcpy(Checkrepeat[0].sid,temporarycoursearray.id);
                        if(strcmp(Checkrepeat[0].sid,"786")==0||strcmp(Checkrepeat[0].sid,"678")==0||strcmp(Checkrepeat[0].sid,"111")==0)
                            {
                                printf("\nrepeated id\n");
                            }
                        else{
                           

                            break;
                            }
                        }
           
            }
    else
        {   
            
            while(1)

            {      
                flag2=0;
                    printf("\nCourse Id (note that it must be different from courses already in inventry otherwise it will ask course id again to avoid  repeated course id in inventory) : \n");
                    fflush(stdin);

                    scanf("%s", temporarycoursearray.id);
                   
                    strcpy(Checkrepeat[m-3].sid,temporarycoursearray.id);
                    
                   
                    
                for(int i=0;i<(m-3);i++)
                {    
                    if(strcmp(Checkrepeat[i].sid,temporarycoursearray.id)==0||strcmp("786",temporarycoursearray.id)==0||strcmp(temporarycoursearray.id,"678")==0||strcmp(temporarycoursearray.id,"111")==0)
                    {   
                        
                        flag2=1;
                        printf("\nid already present Enter another id \n");
                        break;

                    }

                }
                if(flag2==0)
                { 
                    break;
                }
            

            }
        }

    
                   
                   
    
    
     
    

    if(m==3)
            {       while(1)
                        {
                        printf("\nCourse name (note that it must be different from courses already in inventry otherwise it will ask course id again to avoid  repeated course name in inventory): \n");
                        printf("\nIt is advised to enter all of it in smaller case\n");
                        fflush(stdin); 
                        scanf("%s", temporarycoursearray.name);
                        strcpy(Checkrepeat[0].cname,temporarycoursearray.name);
                        if(strcmp(Checkrepeat[0].cname,"algo")==0||strcmp(Checkrepeat[0].cname,"sql")==0||strcmp(Checkrepeat[0].cname,"computer architecture")==0)
                            {
                                printf("\nrepeated name no two course can have repeated name\n");
                            }
                        else{
                           

                            break;
                            }
                        }
           
            }
    else
        {   
            
            while(1)

            {     printf("%d",m); 
                flag2=0;
                    printf("\nCourse Id (note that it must be different from courses already in inventry otherwise it will ask course id again to avoid  repeated course id in inventory) : \n");
                    printf("\nIt is advised to enter all of it in smaller case\n");
                    fflush(stdin);

                    scanf("%s",temporarycoursearray.name);
                   
                    strcpy(Checkrepeat[m-3].cname,temporarycoursearray.name);
                    
                   
                    
                for(int i=0;i<(m-3);i++)
                {    
                    if(strcmp(Checkrepeat[i].cname,temporarycoursearray.name)==0||strcmp("algo",temporarycoursearray.name)==0||strcmp(temporarycoursearray.name,"sql")==0||strcmp(temporarycoursearray.name,"computer architecture")==0)
                    {   
                        
                        flag2=1;
                        printf("\nname already present Enter another name \n");
                        break;

                    }

                }
                if(flag2==0)
                { 
                    break;
                }
            

            }
        }



                   
                    


    
    printf("\nHours: ");
    fflush(stdin);
    scanf("%f", &temporarycoursearray.hours); 
    



    do{printf("\n Semester (1-4): "); 
    fflush(stdin);
    scanf("%d", &temporarycoursearray.semester);
    if(temporarycoursearray.semester <1 || temporarycoursearray.semester>4)
    {
        printf("\ninvalid input enter again\n ");
    }
    }while(temporarycoursearray.semester <1 || temporarycoursearray.semester>4);

    
    return temporarycoursearray;  
}
int selectcategory(){
    int category;
    printf("\t1) Student\n");
            printf("\t2) Teacher\n");
            printf("\t3) Course\n");

            printf("Choose Category for data entry(1-3): \n");
            fflush(stdin);
            scanf("%d", &category);
            return category;

}

void Studentdisplayfunction(Std temoporarystudentarray){
    

    fflush(stdin);
    printf("Id: %s\n",temoporarystudentarray.id);
    printf("Name: %s\n",temoporarystudentarray.name);
    printf("Email: %s\n",temoporarystudentarray.Email_id);
    printf("Status: %s\n",temoporarystudentarray.status);
    printf("Presence: %s\n",temoporarystudentarray.presence);
    printf("Current Semester: %d\n",temoporarystudentarray.Currentsemester);
    printf("Transscript(Final grades per course)\n");

    for (int i = 0; i < temoporarystudentarray.totalcs  ;i++){
        printf("\nFinal Grade for Course Id %s: %f\n",temoporarystudentarray.gradepercourse[i].CourseID,temoporarystudentarray.gradepercourse[i].final_grade);


    }

    
    printf("Current Average: %f\n",temoporarystudentarray.current_avg);

}

void Teacherdisplayfunction( Tea temoporaryteacherarray){
    printf("\n");
    fflush(stdin);
    printf("Id: %s\n",temoporaryteacherarray.id);
    printf("Name: %s\n",temoporaryteacherarray.name);
    printf("Mobile: %s\n",temoporaryteacherarray.mobile);
    printf("Status: %s\n",temoporaryteacherarray.status);
    printf("Seniority: %f\n",temoporaryteacherarray.Seniorty);
           ;

    for (int i = 0; i < temoporaryteacherarray.totalts; i++){
        printf("Course load (for the term): %s\n",temoporaryteacherarray.Corseload[i].CourseID);

    }
    

}
void CourseDisplayFunction(Cou temporarycoursearray){
    printf("\n");
    fflush(stdin);
    printf("Course Id: %s\n",temporarycoursearray.id);
    printf("Course Name: %s\n",temporarycoursearray.name);
    printf("Hours: %f\n",temporarycoursearray.hours);
    printf("Semester: %d\n",temporarycoursearray.semester);
}


int category;
char id[20];


int isFound( char id[20], int category,  int x, int y, int z){
    int i;
    int flag=0;
    int sc;
    if (category==1)
    {
        for (i = 0; i < x ; i++)
        {    sc=strcmp(id,Studentarray[i].id);
            if (sc==0)
            {
                
                flag=1;
                return i;
                
                 
            }
        }
             if (flag == 0)
            {
                   
                 return -1;
                 
             }
            
        
        
        
    }
    else if (category==2)
    {
        for (i = 0; i < y; i++)
        {sc=strcmp(id,teacherarray[i].id);
            if (sc==0)
            
            {
                
                flag=1;
                return i;
                
                break;
            }            
        }
        if (flag == 0)
        {    
            return -1;
        }
    }

    else if (category==3)
    {
        for (i = 0; i < z ; i++)
        {
            sc=strcmp(id,teacherarray[i].id);
            if (sc==0)
            {
                
                flag=1;
                return i;
                
                break;
            }            
        }
        if (flag == 0)
        {
            return -1;
        }
    }

    
    
    
}


int main(){

    int option_number;
    
   
    int index;
    int choice;
    
    char update_string[12];
    int update_int;
    float update_float=0;
    int category;
    int cm;
    int entrycount1=0;
    int entrycount2=0;
    int entrycount3=0;
    int countintl1=0;
    int countintl2=0;
    float stats[250];
    
    
    strcpy(coursearray[0].id,"786");
    coursearray[0].hours=45;
    strcpy(coursearray[0].name,"algo");
    coursearray[0].semester=1;
    strcpy(coursearray[1].id,"678");
    coursearray[1].hours=45;
    strcpy(coursearray[1].name,"sql");
    coursearray[1].semester=1;
    strcpy(coursearray[2].id,"111");
    coursearray[2].hours=45;
    strcpy(coursearray[2].name,"computer architecture");
    coursearray[2].semester=1;
    

    

     
    int totalcourseStudents[250];
     
    int  totalcourseteachers[50];
    

    
    printf("Hey welcome to lassale database please note that there are some  courses  already present in college inventory .These course are\n  ");
    for ( int i=0;i<m;i++)
            {CourseDisplayFunction(coursearray[i]);}
    printf("\nIt is preferred to add courses first in course inventory database \n");
    printf("if you want some new courses as you will only able to access courses which are available in inventory only therefore create inventory first. \n  ");
    printf("\nTo do that first you need to press 1 and select option 3 in data entry menu.Add student and Teacher data afterwards \n  ");


 

    do
    {

    printf("\n--------------------Select any Option from Option menu means type from keyboard anything between 1-7-----------------------\n");
    printf("---------------------------------- 1)Data Entry-----------------------------------------------------\n");
    printf("---------------------------------- 2) Display Record-----------------------------------------------------\n");
    printf("---------------------------------- 3) Update Record-----------------------------------------------------\n");
    printf("---------------------------------- 4) List Current Classes-----------------------------------------------------\n");
    printf("---------------------------------- 5) Run Stats-----------------------------------------------------\n");
    printf("---------------------------------- 6) Display All Records-----------------------------------------------------\n");
    printf("---------------------------------- 7) Exit-----------------------------------------------------\n");

 

    printf("Please choose one option from above menu (1-7): ");
    scanf("%d", &option_number);

    switch (option_number)
    {
    case 1:
            category= selectcategory();
              if (category==1)
                {          
                    do{
                                
                                Studentarray[k] = fillStudentInfo( coursearray);
                                totalcourseStudents[k]=Studentarray[k].totalcs;
                                
                                k++;
                                
                                 printf("do you want to enter other student data if if youwant then type y in keyboard else type n  \n");
                                 fflush(stdin);
                                 scanf("%c",&ans);
                                 
                                


                            }while(ans=='y'||ans=='Y');
                    
                        
                }
                else if   (category==2)
                {           

                         do{
                                
                                teacherarray[l] = fillTeacherInfo();
                                totalcourseteachers[l]=teacherarray[l].totalts;
                               
                                l++;
                                
                                 printf("do you want to enter other teacher data if if you  want then type y in keyboard else type n \n ");
                                  fflush(stdin);
                                 scanf("%c",&ans);
                                
                                 
                                


                            }while(ans=='y'||ans=='Y');
                        
                }
                else if   (category==3)
                {       
                     do{
                                
                                coursearray[m] = fillCourseInfo();
                                entrycount3++;
                               
                                m++;
                                
                                 printf("do you want to enter other course data if if you  want then type y in keyboard else type n  \n");
                                 fflush(stdin);
                                 scanf("%c",&ans);
                                 
                                 
                                


                            } while(ans=='y'||ans=='Y');
                        
                }
                    
                else
                        printf("Invalid Category as you only need to choose between 1 and 3 \n");
                        
                
                    break;
    case 2:
       category= selectcategory();
       if(category==1)
        {
        
            
                printf("Please Enter the Student Id: \n");
                fflush(stdin);
                scanf("%s", id);
                index = isFound(id,category,k,l,m);
                if (index<0)
                {
                    printf("Student with id : %s is not found hence index returned is %d \n",id,index);
                }
                else
                {   printf("Student iswith id : %s is found in class and index at which it is present is %d.Its details are as follows:\n",id,index);
                    Studentdisplayfunction(Studentarray[index]);
                }
                
            
            
        }
        else if(category==2)
        {
        
            printf("Please Enter the Teacher Id: \n");
            fflush(stdin);
            scanf("%s", id);
            index = isFound(id,category,k,l,m);
            if (index<0)
            {
                printf("Teacher with id : %s is not found and index reurned is %d \n",id,index);
            }
            else
            {   printf("Teacher with id : %s is present is found and index at which it is persent is %d.Its details are as follows:\n",id,index);
                Teacherdisplayfunction(teacherarray[index]);
            }
        }
        else if(category==3)
        {
            printf("Please Enter the Course Id: \n");
            fflush(stdin);
            scanf("%s", id);
            index = isFound(id,category,k,l,m);
            if (index<0)
            {
                printf("Record not found with Course ID: %s so index returned%d\n",id,index);
            }
            else
            {   printf("Record not found with Course ID: %s is found at index %d.Its details are as follows: \n",id,index);
                CourseDisplayFunction(coursearray[index]);
            }
            
        }
        
        else{
            printf("wrong Category only choose in 1 and 3  \n");
            
        }
        break;
    case 3:
        category= selectcategory();
        if (category==1)
        {
        
            printf("Please Enter the Student Id: \n");
            fflush(stdin);
            scanf("%s", id);
            index = isFound(id,category,k,l,m);
            if (index<0)
            {
                printf("Record not found with Student ID: %s\n",id);
            }
            else
            {
                do
                {
                    
                    
                    printf("-----------------------------------------1) Status----------------------------------------------------------------\n");
                    printf("-----------------------------------------2) Presence--------------------------------------------------------------\n");
                    printf("-----------------------------------------3) Current Semester---------------------------------------------------\n");
                    printf("-----------------------------------------4) Transcript or GPA per course----------------------------------\n");
                    printf("-----------------------------------------5) Current Average-----------------------------------------------\n");
                    printf("Please type the serial number(1-5) you want to choose but note that average cannot be manually edited  : \n");
                    scanf("%d",&choice);
                    
    

    
    
    
    

    
    

    


                    if (choice==1)
                    {
                            while(1)
                            {
                            
                                printf("Please update Student Status (local or international): ");
                                fflush(stdin);
                                scanf("%s", update_string);
                                
                                if (!strcmp(update_string,"LOCAL")||!strcmp(update_string,"local"))
                                    {   break;

                                    }
                                    if(!strcmp(update_string,"INTENATIONAL")||!strcmp(update_string,"international"))
                                    {break;}

            
                            }
                        strcpy(Studentarray[index].status, update_string);
                    }
                    else if (choice==2)
                    {

                        while(1){
                                printf("Please update Presence (montreal or abroad): "); 
                                fflush(stdin);
                                scanf("%s", update_string);
                                if (!strcmp(update_string,"MONTREAL")||!strcmp(update_string,"montreal"))
                                    {   break;

                                    }
                                    if(!strcmp(update_string,"ABROAD")||!strcmp(update_string,"abroad"))
                                    {break;}
                                }
                        strcpy(Studentarray[index].presence, update_string);
                    }
                    else if (choice==3)
                    {
                            do{   printf("Please update Current Semester (1-4): "); 
                                        fflush(stdin);
                                        scanf("%d", &update_int);
                                        Studentarray[index].Currentsemester = update_int;
                            }while(update_int <1 || update_int>4);
                    } 
                    else if (choice==4)
                    {
                    
                            for (int i = 0; i < Studentarray[index].totalcs ;i++)
                                {
                                    printf("%d) Final Grade for Course Id %s: %f\n",i+1,Studentarray[index].gradepercourse[i].CourseID,Studentarray[index].gradepercourse[i].final_grade);
                                }
                            printf("what is serial number of the course whose marks are u going to update .For example serial number of course %s is 1.Look at the above list for serial number  ",Studentarray[index].gradepercourse[0].CourseID);
                            fflush(stdin);
                            scanf("%d", &update_int);
                            do{printf("Enter updated marks for this course not that marks can be between 0 to 100 : ");
                            fflush(stdin);
                            scanf("%d", &cm);}while(cm<0||cm>100);
                                Studentarray[index].gradepercourse[update_int-1].final_grade =cm ;
                            
                            for (int i = 0; i < Studentarray[index].totalcs ;i++)
                                {
                                    update_float=update_float+Studentarray[index].gradepercourse[i].final_grade;
                                }
                            Studentarray[index].current_avg=update_float/Studentarray[index].totalcs;
                    }
                    else if(choice==5)
                    {
                        printf("Sorry access denied average cannot be modified manually.No cheating\n");
                    }

                    else
                    {    printf("wrong input only choose between 1 to 5\n");
                    }
                    fflush(stdin);
                    printf("Do you want to update other values for same student .If u want to continue updation of some other values for same student press y and if u dont want press n \n");
                    scanf("%c",&ans);
                } while (ans == 'y');           
            }

        }
        else if(category==2)
         {   
            printf("Please Enter the Teacher Id: \n");
            fflush(stdin);
            scanf("%s", id);
            index = isFound(id,category,k,l,m);
            if (index<0)
            {
                printf("Record not found with teacher ID: %s\n",id);
            }
            else
            {
                do
                {
                    
                    printf("----------------------------------------1)Status----------------------------------------\n");
                    printf("----------------------------------------2)Seniority----------------------------------------\n");
                    printf("----------------------------------------3)add course----------------------------------------\n");
                    printf("Please type the serial number you want to update between 1 and 3 : ");
                    fflush(stdin);
                    scanf("%d",&choice);

                    if(choice==1)
                    {
                    
                        printf("Please update Teacher Status (permanent or parttimer): ");
                        fflush(stdin);
                        scanf("%s", update_string);
                        while(1) 
                        {
                       
                
                        
                        if (!strcmp(update_string,"PERMANENT")||!strcmp(update_string,"permanent"))
                        {   break;

                        }
                        if(!strcmp(update_string,"PARTTIMER")||!strcmp(update_string,"parttimer"))
                        {break;}

                        }
                        strcpy(teacherarray[index].status, update_string);
                    }

                        
                        
                    
                    else if(choice==2)
                    {
                        
                        
                        do{
                            printf("Seniority(note that seniority value lies between 0.00 to 20.0): ");
                            scanf("%f", &update_float);
                            
                        }while(update_float<0||update_float>20);

                        teacherarray[index].Seniorty = update_float;
                    }
                    else if(choice==3)
                    {
                        for (int i = 0; i <teacherarray[index].totalts ; i++)
                          
                            {printf("%d) CourseId: %s  (note that here %d is serial number of course %s)\n",i+1,teacherarray[index].Corseload[i].CourseID,i+1,teacherarray[index].Corseload[i].CourseID);}

    
                        do {printf("How many course you want to add for this particular teacher(note that a teacher can at max have %d distinct courses )  : ",m);
                        fflush(stdin);
                        scanf("%d", &update_int);}while(update_int>m);
                        int u=teacherarray[index].totalts-1;
                        teacherarray[index].totalts=teacherarray[index].totalts+update_int;
                        

                        for (int i = 1; i<=update_int ; i++)
                            {
                            flag2=0;
                                        while(flag2==0)
                                    {
                                        printf("%d)Enter Id of number %d added course :  ",i,i);
                                        fflush(stdin);
                                        scanf("%s", teacherarray[index].Corseload[u+i].CourseID);
                                                for(int j=0;j<m;j++)
                                                {   
                                                    if(strcmp( teacherarray[index].Corseload[u+i].CourseID,coursearray[j].id)==0)
                                                        {   flag2=1;
                                                            break;
                                                        }
                                                        
                                                }
                                                if(flag2==0)
                                                {
                                                    printf("The course you entered doesnot exist in course inventory \n");
                                                    printf("do you want to see which course exist in course inventory if you want press y else type n\n ");
                                                    fflush(stdin);
                                                    scanf("%c",&ans);
                                                    if(ans=='y'||ans=='Y')
                                                    {
                                                        for ( int i=0;i<m;i++)
                                                        {CourseDisplayFunction(coursearray[i]);}
                                                    }
                                                    printf("If yourse course id is not in above list and want to assign this course to this teacher you need to add this course to inventory first before assigning it to teacher or choose a course from above list.\n ");
                                                    printf("\nTo add new course to the inventory You need to run the programme again and first select course option in data entry option from main menu and after adding it to course inventory then assign it to teacher who wants this course.\n ");
                                                    
                                                }
                                                
                                        }
                             }
                       }

                        
                        
                      
                    else
                    {
                            printf("Invalid Choice\n");
                        
                    }
                    fflush(stdin);
                    printf("Do you want to update other values for this teacher category.Type  y to update again and anything else to exit from updation : ");
                    scanf("%c",&ans);
                } while (ans == 'y');                
            }
                
        
        }
        else if (category==3){
            printf("Courses can ony be updated in data entry section not in this section.For updation of courses go to main menu and select data entry option");
            }
        else{
            printf("invalid input going to main menu");
        }
        break;

        
    case 4:
    
        printf("Please enter Student Id: ");
        fflush(stdin);
        scanf("%s", id);
        category=1;
        index = isFound(id,category,k,l,m);
        
        
        update_int=  Studentarray[index].Currentsemester;
        printf("current semester of Student is %d ",Studentarray[index].Currentsemester);
            for (int i=0;i<m;i++)
                {
                    if(coursearray[i].semester==update_int)
                    {  
                            for (int j = 0; j < l; j++)
                        {
                            for(int k=0;k<teacherarray[j].totalts;k++ )
    
                                {
                                    int stringcompare=strcmp (coursearray[i].id,teacherarray[j].Corseload[k].CourseID  );
                                    if(stringcompare==0)
                                            printf("Name: %s    course  id   %s ",teacherarray[j].name,teacherarray[j].Corseload[k].CourseID);
        
                                }
                                    printf("\n"); 
                        }   


                    }
                    
                }

        
        
        break;
    case 5:
    countintl1=0;
    countintl2=0;
    for (int i = 0; i < k; i++)
    {
        printf("%s",Studentarray[i].status);
        if(strcmp("INTERNATIONAL",Studentarray[i].status)==0||strcmp("international",Studentarray[i].status)==0)
        {
            countintl1++;
            
                if(strcmp("ABROAD",Studentarray[i].presence)==0||strcmp("abroad",Studentarray[i].presence)==0)
                {
                    countintl2++;
                }     

            
        }
        
         

    }
    printf("\nnumber of international student are %d and percentage of international student are %f percent\n",countintl1,
    (float)(((float)countintl1*100)/(float)k) );
     
    printf("number of international student who  are studying abroad are %d and percentage of international student who are abroad studying is %f percent",countintl2, (float)(((float)countintl1*100)/(float)k)  );

    
   
    float min,max;
    int failcount=0;

    for (int i = 0; i < m; i++)
        {   update_int=0;
            update_float=0;
                    for (int j = 0; j < k; j++)
                        {   
                            for(int k=0;k<Studentarray[j].totalcs;k++ )
    
                                {
                                    int stringcompare=strcmp ( coursearray[i].id,Studentarray[j].gradepercourse[k].CourseID  );
                                    if(stringcompare==0)
                                            {
                                            stats[update_int]=Studentarray[j].gradepercourse[k].final_grade;
                                            update_float=stats[update_int]+ update_float;
                                            if(stats[update_int]<60)
                                                {
                                                    failcount++;
                                                }
                                            update_int++;
                                            
                                            }
                                           
                                            
        
                                }
                                    printf("\n"); 
                        }           printf("number of students studying for course id %s is %d\n",coursearray[i].id,update_int);
                                if(update_int!=0)
                                            {printf("number of students failing   for course id %s is %d out of total %d studentwho have taken this course\n",coursearray[i].id,failcount,update_int);
                                            printf("average for course id %s is %f\n",coursearray[i].id,(update_float/update_int));
                                            max= stats[0];
                                            min= stats[0];
                                            for(int i=1; i<update_int; i++)
                                            {
                                            
                                                        if(stats[i] > max)
                                                        {
                                                            max = stats[i];
                                                        }

                                                        
                                                        if(stats[i] < min)
                                                        {
                                                            min = stats[i];
                                                        }
                                            }

            
                                        printf("Maximum marks for course id %s = %f\n",coursearray[i].id,max);
                                        printf("Minimum marks for course id %s= %f\n",coursearray[i].id, min);
                                            }
                       


        
        
                }


    
     




     







    
        
        break;
    case 6:
        printf("\nStudent details are as follows:\n");
        
        for ( int i=0;i<k;i++)
            
            {Studentdisplayfunction(Studentarray[i]);}
        
        printf("\n\n\n\n\nTeacher details are as follows:\n");
             for ( int i=0;i<l;i++)
           { Teacherdisplayfunction(teacherarray[i]);}
        
        printf("\n\n\n\n\nCourse detalis are as follows:\n");
        
           for ( int i=0;i<m;i++)
            {CourseDisplayFunction(coursearray[i]);}
                
        break;
    case 7:
        printf("Exit\n");
        break;
    
    default:
        printf("wrong input you can only choose between 1 to 7 \n");
        break;
    



    }
    } while (option_number !=7);
    
    return 0;
}

