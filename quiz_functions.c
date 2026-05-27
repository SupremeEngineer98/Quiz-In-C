#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//file which stores all logic!

//function prototypes
int number_of_questions(int questions_number);

void create_quiz(char questions[][100],int questions_number);

void clean_buffer();

void clean_screen();

void add_options(char options[10][4][100], int questions_number);

void add_answer_keys(char answer_key[10][10],char options[10][4][100], int questions_number);

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
    printf("\nHow many questions do you wish to add?\n");
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

//method to add the answer keys
void add_answer_keys(char answer_key[10][10],char options[10][4][100], int questions_number)
{
    //prompt user to enter A,B,C,D to choose the correct answer
    printf("Add A,B,C,D for each question to determine the correct answers\n");

    while(1)
    {
         //add a correct option for each answer
    for(int i=0; i < questions_number; i++)
    {
        printf("Correct answer key for question %d:", i +1);
        fgets(answer_key[i], 10, stdin);
        //sanitize input from '\n'
        answer_key[i][strcspn(answer_key[i], "\n")] = '\0';
        
        if(answer_key[i] == 0)
        {
            //return an error message if answer is null
        printf("Please enter a valid answer key (A,B,C,D)\n");

        //clean buffer
        clean_buffer();
        //return to the beginning
        continue;

        }
    
           ///return an error message if answer_key is not a letter between A-D
            if (strcmp(answer_key[i], "A") != 0 &&
            strcmp(answer_key[i], "B") != 0 &&
            strcmp(answer_key[i], "C") != 0 &&
            strcmp(answer_key[i], "D") != 0)
            {
                printf("Invalid input. Please add A,B,C or D\n");
                //clean buffer
                   clean_buffer();
              //return to the beginning
              continue;
            }

        
          //normalize input
            answer_key[i][0] = toupper(answer_key[i][0]);
        
    }
     break;

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