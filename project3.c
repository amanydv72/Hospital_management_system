#include<stdio.h>
#include<windows.h>//used for gotoxy
#include<conio.h>//use for delay(),getch() etc
#include<ctype.h>//use for toupper(), tolower() etc
#include<string.h>//use for strcmp(), strcpy(), strlen(), etc
#include<stdlib.h>

struct Patient 
{
    int Age;
    char Gender;
    char First_name[20];
    char Last_name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Doctor[20];
    char Problem[30];
}p;

void gotoxy(short x, short y)
{
    COORD pos = {x,y};//sets co-ordinates in(x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
/************************************************ Welcome Screen ***************************************************/
void Welcomescreen(void)
{   
    system("cls");
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t##################################################");
    printf("\n\t\t\t\t\t#\t\t\t        WELCOME TO \t\t\t");
    printf("\n\t\t\t\t\t#\t              XYZ HOSPITAL MANAGMENT SYSTEM");
    printf("\n\t\t\t\t\t\t\t##################################################");
    printf("\n\n    Press any key to continue......\n ");
    getch();
    system("cls");
}
/*********************************************** Title *************************************************************/
void Title(void)
{
    printf("\n\t\t\t\t-------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t          XYZ HOSPITAL        ");
    printf("\n\t\t\t\t-------------------------------------------------------------------------------");
}
/********************************************* Add Record ***********************************************************/
void Add_rec(void)
{   int b,valid=0;
    system("cls");
    Title();
    char ans,ok=0;
    FILE *ek;
    ek=fopen("Record2.dat","a");
    printf("\n\n\n\t\t\t!!!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!!!!!!!!!!!!!!!");
    /************************************** FIRST NAME ******************************************/
    A:
    printf("\n\n\t\t\t First Name: ");
    scanf("%s",p.First_name);
    // p.First_name[0]=toupper(p.First_name[0]);
    if(strlen(p.First_name)>30 || strlen(p.First_name)<2)
    {
        printf("\n\t\t\t Invalid : (\t The max range for first name is 30 and min range is 2");
        goto A;
    }
    else
    {
        for(b=0;b<strlen(p.First_name);b++)
        {
            if(isalpha(p.First_name[b]))
                valid=1;
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t\t Invalid :( First name contain Invalid character : Enter Again) ");
            goto A;
        }
    }
/*************************************** LAST NAME ********************************************/
B:
printf("\n\t\t\t Last Name: ");
scanf("%s",p.Last_name);
// p.Last_name[0]=toupper(p.Last_name[0]);
if(strlen(p.Last_name)>30 || strlen(p.Last_name)<2)
{
    printf("\n\t INvalid :( \t The max range for last name is 30 and min range is 2 :");
    goto B;
}
else
{
    for (b=0;b<strlen(p.Last_name); b++)
    {   
       if(isalpha(p.Last_name[b]))
           valid=1;
       else
       {
           valid=0;
           break;
       }
    }
    if(!valid)
    {
        printf("\n\t\t\t Last name contain Invalid character : ( Enter Again )");
        goto B;
    }
}
/****************************************** Gender *****************************************************************/
do
{
    printf("\n\t\t\t Gender[F/M]: ");
    fflush(stdin);
    scanf("%c",&p.Gender);
    if(toupper(p.Gender)=='M' || toupper(p.Gender)=='F')
        ok=1;
    else
        ok=0;
    if(!ok)
        printf("\n\t\t\t Gender contain Invalid character :( Enter either M or F :");
} while (!ok);
/***************************************** AGE *************************************************************************/
printf("\n\t\t\t Age: ");
scanf("%d",&p.Age);
/********************************************** Address *****************************************************************/
printf("\n\t\t\t Address: ");
fflush(stdin);
gets(p.Address);
/********************************************** Contact no. **************************************************************/
do
{
    D:
    printf("\n\t\t\t Contact no.: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10 || strlen(p.Contact_no)!=10)
    {
        printf("\n\t Invalid Cantact no. must contain 10 digits: ( Enter Again) ");
        goto D;
    }
    else
    {
        for(b=0;b<strlen(p.Contact_no);b++)
        {
            if(!isalpha(p.Contact_no[b]))
                valid=1;
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Contact no, contain Invalid character : ( Enter Again )");
            goto D;
        }
    }
} while (!valid);
/****************************************** Email *************************************/
printf("\n\t\t\t Email: ");
fflush(stdin);
scanf("%s",p.Email);
/********************************************* Problem **********************************/
printf("\n\t\t\t Problem: ");
fflush(stdin);
gets(p.Problem);
/*******************************************  Prescribed Doctor *********************************/
printf("\n\t\t\t Prescribed Doctor: ");
fflush(stdin);
gets(p.Doctor);
/******************************************* FILE HANDLING *****************************************/
fprintf(ek," %s %s %c %d %s %s %s %s %s \n",p.First_name, p.Last_name, p.Gender, p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
printf("\n\t\t\t.... Information Record Successful .....");
fclose(ek);
sd:
getch();
printf("\n\t\t\t Do you want more add[Y/N]: ");
scanf("%c",&ans);
if(toupper(ans)=='y')
    Add_rec();
else if(toupper(ans)=='N')
{
    printf("\n\n\t\t\t Thank You :) :)");
    getch();
    Mainmenu();
}
else
{
    printf("\n\t\t\t Invalid Input\n");
    goto sd;
}
}
/***************************************** Exit screen *********************************************/
void Ex_it(void)
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t THANK YOU FOR VISITING\n");
    getch();
}
/***************************************** Login Screen ******************************************/
void Loginscreen(void)
{
    int e=0;
    char Username[15];
    char Password[15];
    char Original_username[25]="aman";
    char Original_password[25]="7236";
    do
    {
        printf("\n\n\n\n\n\t\t\t\t Enter your usernsme and Password:) ");
        printf("\n\n\n\t\t\t\t\t USERNAME: ");
        scanf("%s",&Username);
        printf("\n\n\n\t\t\t\t\t PASSWORD: ");
        scanf("%s",&Password);
        if(strcmp(Username,Original_username)==0 && strcmp(Password,Original_password)==0)
        {
           printf("\n\n\n\t\t\t\t\t...Login successfull... ");
           getch();
           Mainmenu();
           break;
        }
        else
        {
            printf("\n\n\n\t\t\t\tPassword or Username is incorrect:(Try Again :) ");
            e++;
            getch();
        }
     } while (e<=2);
        if (e>2)
        {
            printf("\n\t\t\t\tYou have cross the limit. You can not login. :(");
            getch();
            Ex_it();
        }
        system("cls");
} 
/************************************ VIEW RECORD ******************************************************/
 void View_list(void)
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\n\n\t\t\t\t\t!!!!!!!!!!!!!!!! View Patients Record !!!!!!!!!!!!!!!!!!!!!!!!\n");
    gotoxy(1,15);
    printf("Full Name");
    gotoxy(20,15);
    printf("Gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(49,15);
    printf("Contact no.");
    gotoxy(64,15);
    printf("Email");
    gotoxy(88,15);
    printf("Problem");
    gotoxy(98,15);
    printf("prescribed Doctor\n");
    printf("====================================================================================================================");
    row=17;
    while (fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.First_name, p.Last_name, &p.Gender, &p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s",p.First_name,p.Last_name);
        gotoxy(20,row);
        printf("%c",p.Gender);
        gotoxy(32,row);
        printf("%d",p.Age);
        gotoxy(37,row);
        printf("%s",p.Address);
        gotoxy(49,row);
        printf("%s",p.Contact_no);
        gotoxy(64,row);
        printf("%s",p.Email);
        gotoxy(88,row);
        printf("%s",p.Problem);
        gotoxy(98,row);
        printf("%s",p.Doctor);
        row++;
    }
    fclose(ek);
    getch();
    Mainmenu();
}
/******************************************** Search Record ************************************************************/
void Search_rec(void)
{
    char ans=0,name[20];
    system("cls");
    // int row=18;
    Title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!!!!!!!!!!!!");
    gotoxy(12,8);
    printf("\n Enter patient First name to viewed: ");
    fflush(stdin);
    gets(name);
    fflush(stdin);
    // name[0]=toupper(name[0]);
    while (fscanf(ek,"%s %s %c %d %s %s %s %s %s\n",p.First_name, p.Last_name, &p.Gender, &p.Age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
    {
        if(strcmp(p.First_name,name)==0)
        {   
            gotoxy(1,15);
            printf("Full Name");
            gotoxy(20,15);
            printf("Gender");
            gotoxy(32,15);
            printf("Age");
            gotoxy(37,15);
            printf("Address");
            gotoxy(49,15);
            printf("Contact no.");
            gotoxy(64,15);
            printf("Email");
            gotoxy(88,15);
            printf("Problem");
            gotoxy(98,15);
            printf("prescribed Doctor\n");
            printf("====================================================================================================================");
            gotoxy(1,18);
            printf("%s %s",p.First_name,p.Last_name);
            gotoxy(20,18);
            printf("%c",p.Gender);
            gotoxy(32,18);
            printf("%d",p.Age);
            gotoxy(37,18);
            printf("%s",p.Address);
            gotoxy(49,18);
            printf("%s",p.Contact_no);
            gotoxy(64,18);
            printf("%s",p.Email);
            gotoxy(88,18);
            printf("%s",p.Problem);
            gotoxy(98,18);
            printf("%s",p.Doctor);
            printf("\n");
            // row++;
            break;
        }
    }
    if(strcmp(p.First_name,name)!=0)
    {
        gotoxy(5,10);
        printf("Record not found");
        getch();
    }
    fclose(ek);
    L:
    getch();
    printf("\n\n\t\t\tDO you want to view more[Y/N]?? ");
    scanf("%c",&ans);
    if(toupper(ans)=='Y')
       Search_rec();
    else if (toupper(ans)=='N')
    {
        printf("\n\t\t Thank You :) :)");
        getch();
        Mainmenu();
    }
    else
    {
        printf("\n\t Invalid Input");
        goto L;
    } 
}

/***************************************** Main Menu **********************************************/
void Mainmenu(void)
{
    system("cls");
    int choose;
    Title();
    printf("\n\n\n\n\t\t\t\t\t\t\t1   Add Patients Record\n");
    printf("\n\t\t\t\t\t\t\t2   View Patients Record\n");
    printf("\n\t\t\t\t\t\t\t3   Search Patients Record\n");
    printf("\n\t\t\t\t\t\t\t4   Edit Patients Record\n");
    printf("\n\t\t\t\t\t\t\t5   Delete Patients Record\n");
    printf("\n\t\t\t\t\t\t\t6   Exit\n");
    printf("\n\n\n\n\n\t\t\t\t\t\t   Choose from 1 to 6:\n");
    fflush(stdin);
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
           Add_rec();
           break;
        case 2:
           View_list();
           break;  
        case 3:
            Search_rec();
            break;    
        case 6:
            Ex_it();
            break;   
        default :
            printf("\t\t invalid entry :)  Please enter right option: ");
            getch();      
    }
} 
  
int main()
{
        Welcomescreen();
        Title();
        Loginscreen();
        // Mainmenu();

    return 0;
}