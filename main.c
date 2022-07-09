#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <ctype.h>

int Game() //Where the game is stored 
{
    double diff = 0.0;
    time_t start;
    time_t stop;
    char buff[128];
    int bombtimer = 60;
   //I wanted to add different modules about different topics but I would have to make a different questions array and that's an entire issue.
   char questions[][100] = {"1. What year did the C language debut?: ",
                            "2. Who is credited with creating C?:",
                            "3. What is the predecessor of C?: "
                            "4. What operations system was coded in C?:"};
                            
   char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                          "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carmack", "D. Doc Brown",
                          "A. Objective C", "B. B", "C. C++", "D. C#"
                          "A. Windows 7","B. MacOS","C. MS-DOS", "D. GM-NAA"};
                          
   char answers[] = {'B', 'A', 'B','A'};
   int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);

   char guess;
   int score = 0; //Sets score to 0 so doesn't change to 16212003 

   printf("QUIZ GAME\n");    
   time(&start);
   for(int i = 0; i < numberOfQuestions; i++)
   {
      printf("*********************\n");
      printf("%s\n", questions[i]);
      printf("*********************\n");
     

      for(int j = (i * 4); j < (i * 4) + 4; j++)
      {
         printf("%s\n", options[j]);
      }

      printf("guess: ");
      scanf(" %c", &guess); //Takes answer from user
      scanf("%c"); //clear \n from input buffer

      guess = toupper(guess); //Turns lower case answers to uppercase

      if(guess == answers[i])
      {
         printf("CORRECT!\n");
         score++;
      }
      else
      {
         printf("WRONG!\n");
      }
   }
   time(&stop); //Stops timer
   diff = difftime(stop, start); //Gets time
  
   
   if( diff > bombtimer ) {
      //If you get over the time limit then its GAME OVER
      printf("You took too long and the bombs went off!\nYou overestimated your time by %g seconds.\nGAME OVER", diff);
   }
   else {
     printf("/*/*/*/*/*/*/*/*/*/*/*\n");
     printf("FINAL SCORE: %d/%d\n", score, numberOfQuestions);
     printf("TIME REMAINING: %g seconds\n", bombtimer-diff);
     printf("/*/*/*/*/*/*/*/*/*/*/*\n");
   }
     
 
   return 0;
}


int main() {
  Game(); // call the function
  return 0;
}
