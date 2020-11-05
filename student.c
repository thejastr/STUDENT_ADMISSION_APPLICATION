#include "student.h"

//------------------------------------------------------------------------------------------
//Declaring global variables
int REG_BDA_SAMPLE=201046001;
int REG_ML_SAMPLE=201047001;
int REG_ES_SAMPLE=201048001;
//-------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------
//Initializing the seats
Program  program_seats(int8_t bda, int8_t ml, int8_t es){
    Program prog = {bda, ml, es, 0, 0, 0};
    return prog;
}
//-------------------------------------------------------------------------------------------
//Assigning values of a student
Student student_new(char name[],char prg[],char email[],int32_t MET_rank,float UG_grade){
    Student s;
    strcpy(s.name,name);
    strcpy(s.program,prg);
    strcpy(s.email,email);
    s.MET_rank=MET_rank;
    s.UG_grade=UG_grade;
    return s;

}
//------------------------------------------------------------------------------------------
//Taking the values od student from user
Student add_student(){
    char    name[STUDENT_NAME_LEN];
	char    program[PROGRAM_NAME_LEN];
	char    email[EMAIL_LEN];
	int32_t MET_rank;
	float   UG_grade;
    Student s;
    printf("\n Enter the Student name \n");
    scanf("%s",name);
    printf("\n Enter the program\n");
    scanf("%s",program);
    printf("\nEnter the email address\n");
    scanf("%s",email);
    printf("\nEnter the MET rank\n");
    scanf("%d",&MET_rank);
    printf("\nEnter UG grade\n");
    scanf("%f",&UG_grade);
    s=student_new(name,program,email,MET_rank,UG_grade);
    N0_OF_STUDENTS=N0_OF_STUDENTS+1;
    return s;


}
//-------------------------------------------------------------------------------------------

//Sorting the students according to rank and allotting seats and providing register numbers
Program allot(Student *s,Program pg){
            int i,j;
            Student temp;
            for (i = 1; i < N0_OF_STUDENTS; i++){                            //Sorting the Students
               for (j = 0; j < N0_OF_STUDENTS - i; j++) {
                 if (s[j].MET_rank>s[j+1].MET_rank) {
                    temp =s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                  }
                }
            }

            for (i=0;i<N0_OF_STUDENTS;i++){
                if (s[i].UG_grade>5.0){
                    if(strcmp(s[i].program,"BDA")==0){
                        if(pg.filled_bda_seats<pg.big_data_seats){
                            pg.filled_bda_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_BDA_SAMPLE++;

                        }
                        else{
                           strcpy(s[i].addmission_status,"waiting");
                        }
                    }
                    if(strcmp(s[i].program,"ML")==0){
                        if(pg.filled_ml_seats<pg.machine_learning_seats){
                            pg.filled_ml_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ML_SAMPLE++;

                        }
                        else{
                           strcpy(s[i].addmission_status,"waiting");
                        }
                    }
                    if(strcmp(s[i].program,"ES")==0){
                        if(pg.filled_es_seats<pg.emnedded_systems_seats){
                            pg.filled_es_seats++;
                            strcpy(s[i].addmission_status,"alotted");
                            s[i].regnumber=REG_ES_SAMPLE++;

                        }
                        else{
                           strcpy(s[i].addmission_status,"waiting");
                        }
                    }
                }
                else{
                    strcpy(s[i].addmission_status,"rejected");
                }
            }
            return pg;
}
//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------
//Alloting seats according to the preference given
int option(Student *s,Program *pg,char next_option[]){
    if (!strcmp(next_option,"ML")&&pg->filled_ml_seats<pg->machine_learning_seats){
                            pg->filled_ml_seats++;
                            strcpy(s->addmission_status,"alotted");
                            s->regnumber=REG_ML_SAMPLE++;
                            return 1;
            }
            else if (!strcmp(next_option,"BDA")&&pg->filled_bda_seats<pg->big_data_seats){
                            pg->filled_bda_seats++;
                            strcpy(s->addmission_status,"alotted");
                            s->regnumber=REG_BDA_SAMPLE++;
                            return 1;
            }
            else if (!strcmp(next_option,"BDA")&&pg->filled_es_seats<pg->emnedded_systems_seats){
                            pg->filled_es_seats++;
                            strcpy(s->addmission_status,"alotted");
                            s->regnumber=REG_ES_SAMPLE++;
                            return 1;
            }

return 0;

}
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Allotting seats for wait listed students
Program allot_waitlisted(Student *s,Program pg){
    int i,r;
    char   next_option1[PROGRAM_NAME_LEN],next_option2[PROGRAM_NAME_LEN];
    for(i=0;i<N0_OF_STUDENTS;i++){
        if(!strcmp(s[i].addmission_status,"waiting")){
            scanf("\nEnter the next 1st preference : %s",next_option1);
            scanf("\nEnter the next 2nd preference : %s",next_option2);
            r=option(&s[i],&pg,next_option1);
            if(r==0){
              option(&s[i],&pg,next_option2);
            }


        }
    }
    return pg;
}
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//Display the filled seats
int8_t      filled_seats(Program pg, char branch[]){
    if(!strcmp(branch,"BDA")){
        return pg.filled_bda_seats;
    }
    else if(!strcmp(branch,"ML")){
        return pg.filled_ml_seats;
    }
    else if(!strcmp(branch,"ES")){
        return pg.filled_es_seats;
    }
    else{
        return 0;
    }
}

//-----------------------------------------------------------------------------------------------------
