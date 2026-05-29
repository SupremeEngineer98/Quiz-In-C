#ifndef QUIZ_H
#define QUIZ_H

//prototype declarations
void create_quiz(char questions[][100],int questions_number);

int number_of_questions(int questions_number, int min_score);

void add_options(char options[10][4][100], int questions_number);

void add_answer_keys(char answer_key[10][10],char options[10][4][100], int questions_number);

void display_questions(char questions[][100],int questions_number,char options[10][4][100]);

char get_user_answer(char user_answer,int questions_number);
bool has_user_won(int score, int min_score);

void clean_buffer();

void clean_screen();
#endif