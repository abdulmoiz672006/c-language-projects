#include<stdio.h>
#include<stdlib.h>
float Intermediate_percentage,merit_cs=91.5,merit_se=90.8,merit_it=87.0,merit_ds=90.9;
float age,entrytest_marks;
void Eligible_to_apply();
void Merit_list();
int menu();
void Your_Eligibility();
int main(){
printf("============= Welcome to XYZ University Admission Portal ============\n");
printf("Enter your intermediate percentage: \n");
scanf("%f",&Intermediate_percentage);
printf("Enter your Entry test marks out of 100 marks is: \n");
scanf("%f",&entrytest_marks);
printf("Enter your age: \n");
scanf("%f",&age);
while(1){
switch (menu()){
case 1:
    Eligible_to_apply();
    break;
case 2:
    Merit_list();
    break;
case 3:
    Your_Eligibility();
    break;
case 4:
    printf("You are exiting the program.");
    exit(0);
    break;
default:
    printf("Invalid choice!!\n");
}
}
return 0;
}
int menu(){
int ch;
printf("\n************************************\n1. Eligibility to apply is: \n");
printf    ("2. Merit of different fields is: \n");
printf    ("3. Your Eligibility is: \n");
printf    ("4. Exit the program: \n");
printf    ("   Enter your choice: \n");
scanf     ("%d",&ch);
return ch;
}
void Eligible_to_apply()
{
    if(Intermediate_percentage>=60|| age>=18){
        printf("\nYou are eligible to apply.\n");
    }else{
        printf("\nYou are not eligible to apply.\n");
    }

}
void Merit_list()
{
  printf("\nClosing merit of Computer Science is: %f\n",merit_cs);
  printf("Closing merit of Software Engineering is: %f\n",merit_se);
  printf("Closing merit of Data Science is: %f\n",merit_ds);
  printf("Closing merit of Information and Technology is: %f\n",merit_it);
}
void Your_Eligibility()
{
 float agregate =(0.5*Intermediate_percentage)+(0.5*entrytest_marks);
 printf("\nYour agregate is: %f",agregate);
  if(agregate>=91.5){
    printf("You're eligible for getting admission in BS'CS,BS'DS,BS'IT,BS'SE.\n");
  }else if(agregate<91.5&&agregate>=90.9) {
    printf("You're eligible for getting admission in BS'DS,BS'IT,BS'SE.\n");
  }else if(agregate<90.9&&agregate>=90.8){
    printf("You're eligible for getting admission in BS'SE,BS'IT.\n");
  }else if(agregate<90.8&&agregate>=87.0){
    printf("You're only eligible for getting admission in BS'IT.\n");
  }else{
  printf("You're not eligible for getting admission in any of Computer'degree.\n ");
         }
}
