#include<stdio.h>
#include<stdlib.h>
//For exit(0) function is declared in <stdlib.h>  header file.
int menu();
void Delete();
void Bike();
void Car();
void Bus();
void Status();
int no_of_buses=0;
int no_of_bikes=0;
int no_of_cars=0;
int count=0,amount=0;
int main()// when we are returning something then we will place getchar at the end and we dont use void we will use int main.
{
while(1)
{
switch(menu())
{
case 1:
    Bike();
    break;
case 2:
    Car();
    break;
case 3:
    Bus();
    break;
case 4:
    Status();
    break;

case 5:
    printf("Exit all.");
    exit(0);
    break;
case 6:
    Delete();
    break;
default:
    printf("invalid choice\n");
}

getchar();
}
}
int menu()
{
int ch;// void cannot be used for variables there fore here we use int.
printf("\n 1. Enter Bike: \n");
printf("2. Enter Car: \n");
printf("3. Enter Buses:\n");
printf("4. Show Status: \n");
printf("5. exit\n");
printf("6. Delete\n");
printf("\nEnter your choice:\n");
scanf("%d",&ch);
return ch;
}
void Status()
{
printf("No of Cars:%d\n",no_of_cars);
printf("No of Bikes: %d\n",no_of_bikes);
printf("No of Buses:%d\n",no_of_buses);
printf("Total no. of vehicles:%d\n",no_of_buses+no_of_bikes+no_of_cars);
printf("Total amount:%d\n",amount);
}
void Delete()
{
no_of_cars=0;
no_of_bikes=0;
no_of_buses=0;
amount=0;
printf("\nRecords deleted.\n");
}
void Bus()
{
printf ("\nEntry succeed\n");
no_of_buses++;// no of buses increases per entry
amount=amount+100;
count++;
}
void Car()
{
printf ("\nEntry succeed\n");
no_of_cars++;//no of cars increases per entry
amount=amount+80;
count++;
}
void Bike()
{
 printf ("\nEntry succeed\n");
no_of_bikes++;//no of bikes increases per entry
 amount= amount+20;
count++;
}
