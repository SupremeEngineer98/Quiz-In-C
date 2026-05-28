#include <stdio.h>
#include <stdlib.h>
#include "quiz.h"
#include <ctype.h>
//QUIZ GAME

//function prototypes
char main_menu(char menu_choice);

//main 
int main()
{
      
    //declaring variables
    char menu_choice = '\0';
    char questions[10][100];
    char options[10][4][100];
    char correct_answer[10][100];
    char answer_key[10][10];
    int  question_count = 0;
    int  score = 0;
    int questions_number = 0;
    

    //main while loop
    while(menu_choice != 'C')
    {
       //display main menu
       menu_choice = main_menu(menu_choice);
       menu_choice = toupper(menu_choice);//normalize input into a capital letter

       //switch method to display menu choises
       switch(menu_choice)
       {
         case 'A': //create quiz case!
         //call questions number method!
         questions_number = number_of_questions(questions_number);

         //create quiz!
         create_quiz(questions,questions_number);

         //add options 
         add_options(options,questions_number);

         //add correct answer for each option
         add_answer_keys(answer_key,options,questions_number);
         break;

         //display quiz case
         case 'B':

         display_questions(questions,questions_number,options);
         break;
       }
    }

    //goodbye message
    printf("Thanks for using my quiz prototype!");

    return 0;
}

//functions

//main menu!
char main_menu(char menu_choice)
{
    //display options!
    printf("Create Quiz (A)\n");
    printf("Play Quiz (B)\n");
    printf("Exit (C)\n");
    printf("Choose an option (A,B,C):");

    //get user's input
    scanf(" %c", &menu_choice);

    //display an error message while menu_choice is not A B or C
    if(menu_choice != 'A' && menu_choice != 'B' && menu_choice != 'C')
    {
        printf("Please choose between A B or C\n");

        //clean buffer
        clean_buffer();
    }

    return menu_choice;
}

//helper functions

