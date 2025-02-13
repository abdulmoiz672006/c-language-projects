#include <stdio.h>
#include <string.h>
// we used string.h because we will use strcspn fuction.
void create_account();
void deposit_money();
void withdraw_money();
void check_balance();
void transfer_money();
const char* ACCOUNT_FILE ="account.dat";
typedef struct
{
  char name[50];
  int acc_no;
  float balance;
}Account;
int main()
{
while(1)
  {
      int choice;
     printf("\n\n***Banking Management System***");
     printf("\n 1.Create Account");
     printf("\n 2.Deposit Money");
     printf("\n 3.Withdraw Money");
     printf("\n 4.Check balance");
     printf("\n 5.Transfer Money");
     printf("\n 6.Exit");
     printf("\n Enter your Choice: ");
     scanf("%d",&choice);

   switch(choice)
   {
case 1:
    create_account();
     break;
    case 2:
    deposit_money ();
     break;
    case 3:
    withdraw_money();
     break;
    case 4:
    check_balance();
     break;
    case 5:
        transfer_money();
        break;
    case 6://exiting program
        printf("\nClosing the Bank,Thanks for your visit.\n\n\n*****************************************************");
        return 0;//return 0 closes the while loop and also the int main.
     break;
    default:
        printf("\nInvalid choice");
     break;
   }
  }
}
void create_account(){
 Account acc;//we make an account object.
 //we use fopen function to open file
 // we use .dat extension when we deal with binary file.
 FILE*file= fopen("account.dat","ab+");
 // in the above ab a:append and b:binary.
 if (file==NULL){
    printf("\nUnable to open file.");
    return ;
 }
 char c;
 do{
    c=getchar();
 }
 while(c!='\n'&&c!=EOF);
 printf("\n Enter your name:");
 fgets(acc.name,sizeof(acc.name),stdin);//we use fgets instead of scanf because we are also saving spaces in the name.
  int ind= strcspn(acc.name,"\n");
 acc.name[ind]='\0';//this function will replace \n into \0 in the name .
 printf("\nEnter your account number:" );
 scanf("%d",&acc.acc_no);
 acc.balance=0;//we have initialized the balance as the account is recently opened.

 fwrite(&acc,sizeof(acc),1,file);// every thing of account will be save in this file.")
fclose(file);//close file.
printf("\n Account created.");
}
void deposit_money(){
FILE *file=fopen(ACCOUNT_FILE,"rb+");// here we have to read and write therefore we use "rb+" to open file file in read and write mode.
if (file == NULL){
    printf("Unable to open account file!!") ;
    return ;
}

int acc_no;
float money;
Account acc_r;
printf("Enter your account number: ");
scanf("%d",&acc_no);
printf("Enter amount to deposit: ");
scanf("%f",&money);
while(fread(&acc_r,sizeof(acc_r),1,file))//acc_r means account to read.
{
  if (acc_r.acc_no ==acc_no){//read account details.
     acc_r.balance+=money;//update balance.
     fseek(file,-sizeof(acc_r),SEEK_CUR);
     //fseek is used to move cursor back to over write the record.
     fwrite(&acc_r,sizeof(acc_r),1,file);//write updated balance to he file.
     fclose(file);
     printf("Successfully deposited rupees:%.2f \n Now current balance is:%.2f",money,acc_r.balance);
     return;
  }
}
fclose(file);
printf("Money could not be deposited as Account number %d i not found in record",acc_no);
}


void withdraw_money(){
FILE *file= fopen(ACCOUNT_FILE,"rb+");//rb:read binary.
 if (file==NULL){
    printf("\n unable to open file!!");
    return;
 }
 int acc_no;
 float money;
 Account acc_r;
 printf("enter your account number: ");
 scanf("%d",&acc_no);
 printf("Enter withdraw amount:");
 scanf("%f",&money);
 while(fread(&acc_r,sizeof(acc_r),1,file)){
    if (acc_r.acc_no==acc_no){
    if(acc_r.balance>=money){
      acc_r.balance-=money;
    fseek(file,-sizeof(acc_r),SEEK_CUR);
    fwrite(&acc_r,sizeof(acc_r),1,file);
    printf("Successfully withdrawn Rs%.2f\nRemaining balance %.2f",money,acc_r.balance);
    }else{
     printf("Insufficient balance.");
    }
    fclose(file);
    return;
        }
    }
 printf("Money could not be withdrawn as Account number %d i not found in record",acc_no);
}
void check_balance(){
 FILE *file= fopen(ACCOUNT_FILE,"rb");//rb:read binary.
 if (file==NULL){
    printf("\n unable to open file!!");
    return;
 }
 int acc_no;
 Account acc_read;
 printf("Enter your account number: ");
 scanf("%d",&acc_no);

 while(fread(&acc_read,sizeof(acc_read),1,file))//we wrote 1 because it reads each file only one time.
 {
  if (acc_read.acc_no==acc_no){
    printf("Your current balance is: Rs.%.2f",acc_read.balance);
    fclose(file);
    return;
  }
 }
 fclose(file);
 printf("\nAccount no: %d was not found.\n",acc_no);
}
void transfer_money(){
FILE *file= fopen(ACCOUNT_FILE,"rb+");//rb:read binary.
 if (file==NULL){
    printf("\n unable to open file!!");
    return;
 }
 int acc_no;
 float money;
 Account acc_r;
 printf("enter your account number: ");
 scanf("%d",&acc_no);
 printf("Enter transferred amount:");
 scanf("%f",&money);
 while(fread(&acc_r,sizeof(acc_r),1,file)){
    if (acc_r.acc_no==acc_no){
    if(acc_r.balance>=money){
      acc_r.balance-=money;
    fseek(file,-sizeof(acc_r),SEEK_CUR);
    fwrite(&acc_r,sizeof(acc_r),1,file);
    printf("Successfully transferred Rs%.2f\nRemaining balance %.2f",money,acc_r.balance);
    }else{
     printf("Insufficient balance.");
    }
    fclose(file);
    return;
        }
    }
 printf("Money could not be transferred as Account number %d i not found in record",acc_no);
}
