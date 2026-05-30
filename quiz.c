#include <stdio.h>
#include <stdlib.h>
#include "quiz.h"
#include <ctype.h>
#include <string.h>
//QUIZ GAME

//function prototypes
char main_menu(char menu_choice);

//main 
int main()
{
      
    //declaring variables
    char menu_choice = '\0';
    char questions[10][100];
    char options[10][4][100] = {0};
    char correct_answer[10][100];
    char answer_key[10][10];
    char user_answer = '\0'; 
    int  score = 0;
    int min_score = 0;
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
         
         questions_number = number_of_questions(questions_number,&min_score); //call questions number method to add minimum score and quiz's questions number!
         
         //create quiz!
         create_quiz(questions,options,questions_number);        

         //add correct answer for each option
         add_answer_keys(answer_key,options,questions_number);
         break;

         //display quiz case
         case 'B':

         //eliminate score
         score = 0;

              //display an error message if there are no questions added yet
         if(questions_number <= 0)
         {
            printf("There are no questions added yet\n");
            continue;
         }

          display_questions(questions,questions_number,options);//display all the questions
         //for loop to iterate through each question!
         for(int i = 0; i < questions_number; i++)
         {
               

         //get user's answer
         user_answer =  get_user_answer(user_answer,questions_number);

         //validate whether user's answer is correct or not
         if(user_answer == answer_key[i][0])
         {
            printf("\nCorrect\n");

            //increase score
            score++;
            
           
         }
         else
         {
            printf("Incorrect\n");

         }
           

         }
         //display score
         printf("\nYour final score is: %d out of %d questions\n", score, questions_number);

         //return a message to notify user if he won or not

         if(has_user_won(score, min_score))
         {
            printf("Congragulations you won!!!\n");
         }
         else
         {
            printf("You lost\n");
         }
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



