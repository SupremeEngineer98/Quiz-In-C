#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//file which stores all logic!
int number_of_questions(int questions_number);
void create_quiz(char questions[][100],int questions_number);
void clean_buffer();
void clean_screen();
void add_options(char options[10][4][100], int questions_number);

//create quiz function!
void create_quiz(char questions[][100],int questions_number)
{
    while(1)
    {
        //for loop to iterate and add the questions
    for(int i = 0; i < questions_number; i++)
    {
        //prompt user to enter a question
        printf("\nEnter question  %d:", i+1);
        
        fgets(questions[i], 100, stdin);
        //sanitizing input and removing '\n'
        questions[i][strcspn(questions[i], "\n")] ='\0';
        //return an error message if input is null!
        if(questions[i][0] == '\0')
        {
          printf("\nInvalid input. Please enter a question\n");
          //clean buffer!
        clean_buffer();
          continue;
        }

        
    }
      //break loop
      break;

    }
    

}

//function to get number of questions!
int number_of_questions(int questions_number)
{
    while(1)
    {
        //promt user to enter number of questions
    printf("How many questions do you wish to add?\n");
    printf("Enter number: ");
    
    //validate that user will insert a valid number!
    if(scanf("%d", &questions_number) != 1 || questions_number <= 0)
    {
        //return an error message if input is not a number or number <=0
        printf("Enter a valid positive number\n");

        //clean buffer!
        clean_buffer();
        continue;

    }
    clean_buffer();//clean buffer in order for fgets sanitation to work
        //exit loop
        break;
    }
    
   return questions_number;
}

//add options function 
void add_options(char options[10][4][100], int questions_number)
{
    

            //promt user to enter options!
    printf("\nPlease enter options for quiz questions with the order you entered the questions\n");


    //for loop to iterate through the array!
    for(int i = 0; i< questions_number; i++)
    {
     printf("Option for question %d\n", i+1);
    
    //for loop to enter 4 options for each question
    for(int j = 0; j<4; j++)
    {
    
    printf("\nEnter option %d: ", j + 1);
    //get user's options
    fgets(options[i][j],100, stdin);

    //sanitizing input
    options[i][j][strcspn(options[i][j], "\n")]  ='\0';

    //return an error message if option is null
    if(options[i][j][0] == 0 )
    {
        printf("Invalid input.Please enter a valid option\n");
        
        
        i--;//retry the same question
        //clean buffer!
        clean_buffer();
          continue;
    }
   

    }
    

    }     

}



//helper functions

//clean buffer function
void clean_buffer()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

//clean screan function
void clean_screen()
{
    printf("Press any key to continue..");
    getchar();
    system("cls");
}