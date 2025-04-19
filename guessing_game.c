#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
int random,guess;
int no_of_guess=0;
srand(time(NULL));//this is used for current time function as the random value changes with current time
printf("Welcome to the game of Guessing Numbers\n");
random=rand()%10+1;//by this compiler assumes a random value
do{
printf("\nPlease enter your guess number between 1 and 10\n");
scanf("%d",&guess);
no_of_guess++;
if (guess<random){
    printf("Hint: Guess larger number\n");
}else if(guess>random) {
printf("Hint: Guess a smaller number\n");
}else
{
  printf("You have successfully guessed the number in %d attemps\n",no_of_guess);
}
}while(guess!=random);
printf("Thanks for playing\n");
printf("Developed by Rana Abdul Moiz\n\n\n\n");
printf("*************************************");
}












