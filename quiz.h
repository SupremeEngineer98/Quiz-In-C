#ifndef QUIZ_H
#define QUIZ_H

//prototype declarations
void create_quiz(char questions[][100],int questions_number);

int number_of_questions(int questions_number);

void add_options(char options[10][4][100], int questions_number);

void add_answer_keys(char answer_key[10][10],char options[10][4][100], int questions_number);

void display_questions(char questions[][100],int questions_number,char options[10][4][100]);

void clean_buffer();

void clean_screen();
#endif