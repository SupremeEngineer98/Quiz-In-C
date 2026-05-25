#include <stdio.h>
#include <stdlib.h>

//QUIZ GAME

//function prototypes
char main_menu(char menu_choice);
//clean buffer function
void clean_buffer();
void clean_screen();

//main 
int main()
{

    //declaring variables
    char menu_choice = '\0';

    //main while loop
    while(menu_choice != 'C')
    {
       //display main menu
       menu_choice = main_menu(menu_choice);
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