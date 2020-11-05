#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "appconst.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


//-----------------------------------------------------------------------------------------------
static int N0_OF_STUDENTS=0;
//-----------------------------------------------------------------------------------------------
//Structure for storing Student Details
struct _student_{
	char    name[STUDENT_NAME_LEN];
	int32_t regnumber;
	char    program[PROGRAM_NAME_LEN];
	char    email[EMAIL_LEN];
	int32_t MET_rank;
	float   UG_grade;
	char    addmission_status[ADMISSSION_STATUS_LEN];
};
typedef struct _student_ Student;
//------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------
//Structure for storing the details regarding the program
struct _program_  {
	int8_t big_data_seats;
	int8_t machine_learning_seats;
	int8_t emnedded_systems_seats;

	int8_t filled_bda_seats;
	int8_t filled_ml_seats;
	int8_t filled_es_seats;
};
typedef struct _program_ Program;
//-----------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------
//Declaration of funton used in the application
Program	program_seats(int8_t bda, int8_t ml, int8_t es);
Student add_student();
Student student_new(char name[], char prg[], char email[],int32_t MET_rank,float UG_grade);
Program allot(Student *s,Program pg);
int32_t test_admission_ststus(Student s1);
int option(Student *s,Program *pg,char next_option[]);
Program allot_waitlisted(Student *s,Program pg);
int8_t  filled_seats(Program pg, char branch[]);
//--------------------------------------------------------------------------------------------------

#endif
