#define CREDENTIAL_LENGTH 30//Maximum length of user name or password is 30.
#include<stdio.h>
#include<string.h>
#define MAX_USERS 10 //Maximum users are 10.
typedef struct{
char username[CREDENTIAL_LENGTH];
char password[CREDENTIAL_LENGTH];
}user; //User is alternative name of structure.
user users[MAX_USERS];
int user_count=0;
int user_index;
void Register();
int login_user();//results user index
void fix_fgets_input(char*);// this is done to fix /n problem.
void input_password(char*);
int main(){
int option;//integer declared for selecting option in menu.
while(1)// creating infinite loop so that menu will be appeared after every process until we did not select exit option.
{
printf("\n Welcome to user management system.");
printf("\n 1.Register");
printf("\n 2.Login");
printf("\n 3.Exit");
printf("\n Select an option");
scanf("%d",&option);
getchar();//consume extra enter.
switch (option){
case 1://Register.
Register();
    break;
case 2://Login.
     user_index=login_user();
    if(user_index>=0){
     printf("login successful! Welcome,%s!\n\n",users[user_index].username);// we take user name from user index array in users.
    }else{
    printf("\nLogin failed!\tIncorrect user name or password");
           }
    break;
case 3://Exit.
    printf("\nExiting Program.\n");
    return 0;
    break;
default:
    printf("\nInvalid Option!\nPlease try again.\n");
    break;
}
}
return 0;
}
void Register()
{
if(user_count==MAX_USERS){
    printf("\Maximum %d users are supported! No more users are allowed!!!!\n",MAX_USERS);
    return;//this is done to show response if maximum users are entered.
}
int new_index=user_count;
printf("\nRegister a new User");
printf("\nEnter User Name:");
fgets(users[new_index].username,CREDENTIAL_LENGTH,stdin);
fix_fgets_input(users[new_index].username);
input_password(users[new_index].password);
user_count++;
printf("\nRegistration Successful.");
}
int login_user(){
char username[CREDENTIAL_LENGTH];
char password[CREDENTIAL_LENGTH];
printf("\nEnter User Name:");
fgets(username,CREDENTIAL_LENGTH,stdin);
fix_fgets_input(username);
input_password(password);
 for (int i=0;i<user_count;i++){
    if(strcmp(username,users[i].username)==0&&
       strcmp(password,users[i].password)==0)// "strcmp"  is used to compare user name and password.
       {
        return i;
    }
 }
    return -1;
}
void  input_password(char*password)
{
printf("Enter Password:");

fgets(password,CREDENTIAL_LENGTH,stdin);
fix_fgets_input(password);
}
void fix_fgets_input(char*string)
{
int index=strcspn(string,"\n");
string[index]='\0';//this converts /n to /0.
}
