#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct data //to held the data of the employee during the running of the program
{
    char name[100];
    char phone[20];
    char e_mail[200];
    char birthdate[20];
    char current_job[200];

};
//**************************************************************************************************************

//Global variables declarations
int i=0; //counter for the employees
int i_counter=0; //counter for the number of employees being held by the structure
struct data employee[100]; //to held the data of several employees
int load_flag=0; //to sign if the data has been loaded before or not
int quit=0;
int i_beg,i_end; //to mark the beginning and the end of i in the load function
//**************************************************************************************************************

//checking for birth date
int check_format=0;
int check_day=0;
int check_month=0;
int check_year=0;
//*******************************************************************************************************************

//Main functions of the program
void ADD ();
void LOAD ();
void DELETE();
void SAVE();
void SEARCH();
void MODIFY();
void QUIT();
void SORT();
//********************************************************************************************************************

//Checking validation functions
int Validate_name();
int Validate_phone();
int Validate_email();
void validate_birthdate();
int validate_job();
//****************************************************************************************************************

//Date entry functions
void name();
void phone();
void e_mail();
void birthdate();
void current_job();
//****************************************************************************************************************

//Auxiliary functions
//void read_jobs();//to print the jobs on the screen
void Menu(); //to open the option to the user
//*****************************************************************************************************************

//Sorting functions
void sort_a2z(); //sort the data alphabetically (from a to z)
void sort_z2a(); //sort the data alphabetically (from a to z)
void sort_y2o(); //sort the data from youngest to oldest according to their birth date
void sort_o2y(); //sort the data from oldest to youngest according to their birth date
//****************************************************************************************************************


int main()
{
    printf("..............<Welcome to Step Up company database>..................");
    Menu();

    return 0;
}
//********************************************************************************************************

void Menu()
{
    int n; //represents the number of the chosen function
    while(1)
    {
        //Reading the choice
        printf("\n\nChoose one of the mentioned options below ");
        printf("\n1-Add\n2-Load\n3-Delete\n4-Save\n5-Search\n6-Modify\n7-Quit\n8-Sort\n");
        printf("write the number of the desired option: ");
        scanf("%d",&n);
        //*********************************************************************************************************

        //Calling the function according to the choice
        if (n==1)
        {
            printf("----------------------------------------------------------------------");
            ADD();
        }
        else if (n==2)
        {
            printf("-------------------------------------------------------------------------");
            LOAD();

        }
        else if (n==3)
        {
            printf("---------------------------------------------------------------------------");
            DELETE();
        }
        else if (n==4)
        {
            printf("----------------------------------------------------------------------------");
            SAVE();
        }
        else if (n==5)
        {
            printf("-----------------------------------------------------------------------------");
            SEARCH();
        }
        else if (n==6)
        {
            printf("------------------------------------------------------------------------------");
            MODIFY();
        }
        else if(n==7)
        {
            printf("-------------------------------------------------------------------------------");
            QUIT();
        }
        else if(n==8)
        {
            printf("-------------------------------------------------------------------------------");
            SORT();
        }
        else
        {
            printf("\nplease enter one of the mentioned choices\n");
            printf("---------------------------------------------------------------------------------");
            Menu();
        }
        //*****************************************************************************************************

        //to quit the program
        if(quit==1)
        {
            break;
        }
        //******************************************************************************************************

    }
}
//**********************************************************************************************************************
void ADD()
{
    printf("\n\nEnter the data of the employee\n");
    name();
    phone();
    e_mail();
    birthdate();
    current_job();
    i++;
    i_counter++;
    printf("********************************************************************************");

}
//********************************************************************************************************

void name()
{
    printf("Name: ");
    scanf("\n");
    scanf("%[^\n]%*c",employee[i].name);
    int v_n = Validate_name();//to check the name is letters only
    if (v_n == 0)
    {
        printf("->please enter letters only\n");
        name();

    }
}
//*********************************************************************************************************

void phone()
{
    printf("Phone number: ");
    scanf("%s",&employee[i].phone);
    int v_p = Validate_phone();//to check the phone is digits only
    if (v_p == 0)
    {
        printf("->please enter digits only\n");
        phone();
    }
}
//*****************************************************************************************************************
void e_mail()
{
    printf("e-mail in the form ""Something@website.com "": ");
    scanf("%s",employee[i].e_mail);
    int v_m = Validate_email();//to check the e-mail is in the right form
    if (v_m == 0)
    {
        printf("->Please enter the right format ""Something@website.com ""\n");
        e_mail();
    }
}
//*****************************************************************************************************************

void birthdate()
{
    printf("Birth date in the form ""DD/MM/YYYY"": ");
    scanf("%s",employee[i].birthdate);
    validate_birthdate();
    if (check_format==1)
    {
        printf("\nPlease enter the birth date in the right format ""DD/MM/YYYY""\n");
        birthdate();
    }
    if(check_year==1)
    {
        printf("\nplease the year in the right range(1959-1996)\n");
        birthdate();
    }
    if(check_month==1)
    {
        printf("\nplease the month in the right range(01-12)\n");
        birthdate();
    }
    if(check_day==1)
    {
        printf("\nplease the day in the right range\n");
        birthdate();
    }

}
//******************************************************************************************************************

void current_job()
{
    printf("\nWrite one of the jobs mentioned below");
    printf("\nCEO\nBranch manger\nMarketing director\nMarketeer\nHuman resources director\nHuman resources employee\n");
    printf("Current job: ");
    scanf("\n");
    scanf("%[^\n]%*c",&employee[i].current_job);
    int v_j=validate_job();
    if (v_j == 0)
    {
        printf("\n->please enter the right job");
        current_job();
    }
}
//*****************************************************************************************************************

/*void read_jobs()
{
     //Reading the data from the file
    struct load
    {
        char jobs[100];
    };
    struct load ar_load[20];
    int m =0,m_counter=0;
    FILE* fjob;
    fjob = fopen("CompanyInfo.txt","r+");
    while(!feof(fjob))
    {
        fgets(ar_load[m].jobs,100,fjob);
        m++;
        m_counter++;
    }
    m=1;
    fclose(fjob);
    //**************************************************************************************************************

    //separating the jobs
    int c=0, j=0, k=0;

    struct job
    {
        char load_job[100];
    };

    struct job ar_job [100];

    while(m<(m_counter-1))
    {
        while(ar_load[m].jobs[k]!='\0')
        {

            if (ar_load[m].jobs[k]=='-')
            {
                k++;
                while(ar_load[m].jobs[k]!= '.')
                {
                    ar_job[j].load_job[c]=ar_load[m].jobs[k];
                    k++;
                    c++;

                }
            }
            printf("\n%s", ar_job[j].load_job);
            c=0;
            k=0;
            m++;
            j++;
        }
        k++;
    }
    //*********************************************************************************************************
}
//**********************************************************************************************************************
*/
int Validate_name() //returns zero when the name is not letters only and returns one other wise
{
    int size,j ;
    size =strlen(employee[i].name);
    for(j=0; j<size; j++)
    {
        if((isalpha(employee[i].name[j])==0)&&(employee[i].name[j]!=' '))
        {
            return 0;
        }
    }
    return 1;
}
//********************************************************************************************************************

int Validate_phone() //returns zero when the phone is not digits only and returns one other wise
{
    int size,j ;
    size =strlen(employee[i].phone);
    for(j=0; j<size; j++)
    {
        if((isdigit(employee[i].phone[j])==0))
        {
            return 0;
        }
    }
    return 1;
}
//*******************************************************************************************************************

int Validate_email() //returns zero when the e-mail is not int the right form and returns one other wise
{
    if(!(strchr(employee[i].e_mail,'.') && strchr(employee[i].e_mail,'@') && isalpha(employee[i].e_mail[0]) ))
    {
        return 0;
    }
    return 1;
}
//******************************************************************************************************************

void validate_birthdate()
{
    int day,month,year;

    //Check the format of the date
    if(!(isdigit(employee[i].birthdate[0])&&isdigit(employee[i].birthdate[1])&&(employee[i].birthdate[2]=='/')&&isdigit(employee[i].birthdate[3])&&isdigit(employee[i].birthdate[4])&&(employee[i].birthdate[5]=='/')&&isdigit(employee[i].birthdate[6])&&isdigit(employee[i].birthdate[7])&&isdigit(employee[i].birthdate[8])&&isdigit(employee[i].birthdate[9])))
    {
        check_format = 1;
    }
    else
    {
        check_format=0;
    }
    //****************************************************************************************************************


    if(check_format==0)
    {
        //Check the year range
        sscanf(employee[i].birthdate,"%d/%d/%d",&day,&month,&year);
        if((year<1959) || (year>1996))
        {
            check_year=1;
        }
        else
        {
            check_year=0;
        }
        //**************************************************************************************************

        //check the month range
        if((month<01)||(month>12))
        {
            check_month=1;
        }
        else
        {
            check_month=0;
        }
        //*******************************************************************************************************

        //check leap year
        int leap_year = 0;
        if (((year % 4 == 0) && (year % 100 != 0)) ||(year % 400 == 0))
        {
            leap_year=1;
        }
        else
        {
            leap_year=0;
        }
        //*************************************************************************************************

        //check day per month range
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        {
            if((day<01)||(day>31))
            {
                check_day=1;
            }
            else
            {
                check_day=0;
            }
        }
        else if(month==4||month==6||month==9||month==11)
        {
            if((day<01)||(day>30))
            {
                check_day=1;
            }
            else
            {
                check_day=0;
            }
        }
        else if(month==2)
        {
            if(leap_year==1)
            {
                if((day<01)||(day>29))
                {
                    check_day=1;
                }
                else
                {
                    check_day=0;
                }
            }
            else if(leap_year==0)
            {
                if((day<01)||(day>28))
                {
                    check_day=1;
                }
                else
                {
                    check_day=0;
                }
            }
        }
        //**************************************************************************************************************

    }
}

int validate_job() //returns zero if the entered job is not in the data list and returns one other wise
{
    //Reading the data from the file
    struct load
    {
        char jobs[100];
    };
    struct load ar_load[20];
    int m =0,m_counter=0;
    FILE* fjob;
    fjob = fopen("CompanyInfo.txt","r+");
    while(!feof(fjob))
    {
        fgets(ar_load[m].jobs,100,fjob);
        m++;
        m_counter++;
    }
    m=0;
    fclose(fjob);
    //**************************************************************************************************************

    //separating the jobs
    int c=0, j=0, k=0;

    struct job
    {
        char load_job[100];
    };

    struct job ar_job [100];

    while(m<(m_counter-1))
    {
        while(ar_load[m].jobs[k]!='\0')
        {

            if (ar_load[m].jobs[k]=='-')
            {
                k++;
                while(ar_load[m].jobs[k]!= '.')
                {
                    ar_job[j].load_job[c]=ar_load[m].jobs[k];
                    k++;
                    c++;

                }
                j++;
                c=0;
            }
            k++;
        }
        k=0;
        m++;
    }
    //*********************************************************************************************************

    //comparing the job entered to the jobs from the file
    for(j=0; j<=(m_counter); j++)
    {
        if(!(strcmp(ar_job[j].load_job,employee[i].current_job)))
        {
            return 1;
        }
        else if(j==(m_counter))
        {
            return 0;
        }
    }
    return 1;
    //*****************************************************************************************************************

}
//****************************************************************************************************************

void LOAD()
{
    if (load_flag==0) //To in indicate that the data has not been loaded before
    {
        i_beg=i;
        //Reading the data from the file
        struct load
        {
            char file[500];
        };
        struct load ar_load[20];
        int m =0,m_counter=0;
        FILE* fpointer;
        fpointer = fopen("CompanyDatabase.txt","r+");
        while(!feof(fpointer))
        {
            fgets(ar_load[m].file,500,fpointer);
            m++;
            m_counter++;
        }
        fclose(fpointer);
        //*********************************************************************************************************

        //Separating each employee in a structure
        int k =0, j=0,c=0;
        m=0;
        int j_counter = 0;

        struct emp
        {
            char load_emp[100];
        };

        struct emp ar_emp [100];

        while(m<(m_counter))
        {
            while(ar_load[m].file[k]!='\0')
            {

                if (ar_load[m].file[k]=='“')
                {
                    k++;
                    while(ar_load[m].file[k]!= '”')
                    {
                        ar_emp[j].load_emp[c]=ar_load[m].file[k];
                        k++;
                        c++;

                    }
                    c=0;
                    j++;
                    j_counter++;
                }
                k++;
            }
            k=0;
            m++;
        }
        //*****************************************************************************************************************

        //Putting the data of the employee in their specified field in the data structure
        j=0;
        c=0;
        k=0;
        int counter =0;//To count and specify the number of fields loaded
        printf("\n\nThe data of the employees: ");
        while(j<j_counter)
        {
            while(ar_emp[j].load_emp[c]!= '\0')
            {
                if(ar_emp[j].load_emp[c]!= ' ')
                {
                    while(counter == 0)
                    {
                        employee[i].name[k]=ar_emp[j].load_emp[c];
                        c++;
                        k++;
                        if(ar_emp[j].load_emp[c] == ',')
                        {
                            counter++;
                            printf("\n\nName: ");
                            printf("%s",employee[i].name);
                            int v_n = Validate_name();
                            if (v_n == 0)
                            {
                                printf("\nThe name should letters only\n");
                                name();

                            }
                            k=0;
                            c++;
                        }
                    }
                }
                if(ar_emp[j].load_emp[c]!= ' ')
                {
                    while (counter == 1)
                    {
                        employee[i].phone[k]=ar_emp[j].load_emp[c];
                        c++;
                        k++;
                        if(ar_emp[j].load_emp[c] == ',')
                        {
                            counter++;
                            printf("\nPhone number: ");
                            printf("%s",employee[i].phone);
                            int v_p = Validate_phone();
                            if (v_p == 0)
                            {
                                printf("\nThe phone number should be digits only\n");
                                phone();
                            }
                            k=0;
                            c++;
                        }
                    }
                }
                if(ar_emp[j].load_emp[c]!= ' ')
                {
                    while (counter == 2)
                    {
                        employee[i].e_mail[k]=ar_emp[j].load_emp[c];
                        c++;
                        k++;
                        if(ar_emp[j].load_emp[c] == ',')
                        {
                            counter++;
                            printf("\ne-mail: ");
                            printf("%s",employee[i].e_mail);
                            int v_m = Validate_email();
                            if (v_m == 0)
                            {
                                printf("\nThe e-mail should be in this format ""Something@website.com ""\n");
                                e_mail();
                            }
                            k=0;
                            c++;
                        }
                    }
                }
                if(ar_emp[j].load_emp[c]!= ' ')
                {
                    while (counter == 3)
                    {
                        employee[i].birthdate[k]=ar_emp[j].load_emp[c];
                        c++;
                        k++;
                        if(ar_emp[j].load_emp[c] == ',')
                        {
                            counter++;
                            printf("\nBirth date: ");
                            printf("%s",employee[i].birthdate);
                            validate_birthdate();
                            if (check_format==1)
                            {
                                printf("\nPlease enter the birth date in the right format ""DD/MM/YYYY""\n");
                                birthdate();
                            }
                            if(check_year==1)
                            {
                                printf("\nplease the year in the right range(1959-1996)\n");
                                birthdate();
                            }
                            if(check_month==1)
                            {
                                printf("\nplease the month in the right range(01-12)\n");
                                birthdate();
                            }
                            if(check_day==1)
                            {
                                printf("\nplease the day in the right range\n");
                                birthdate();
                            }
                            k=0;
                            c++;
                        }
                    }
                }
                if(ar_emp[j].load_emp[c]!= ' ')
                {
                    while (counter == 4)
                    {
                        employee[i].current_job[k]=ar_emp[j].load_emp[c];
                        c++;
                        k++;
                        if(ar_emp[j].load_emp[c] == ',')
                        {
                            counter++;
                            printf("Current job: ");
                            printf("%s",employee[i].current_job);
                            int v_j=validate_job();
                            if (v_j == 0)
                            {
                                printf("\nThe job should be from the list provided\n");
                                current_job();
                            }
                            k=0;
                            c++;
                        }
                    }
                }
                c++;
                if((counter==5))
                {
                    break;
                }



            }
            printf("\n*************************************************************************");
            j++;
            i++;
            i_counter++;
            c=0;
            counter = 0;
        }
        //**********************************************************************************************************************
        i_end = i;
        load_flag=1;
    }
    //********************************************************************************************************

    //if the database has been loaded before it will be only printed
    else if (load_flag==1)
    {
        int n;
        printf("\n\nThe data of the employees: ");
        for(n=i_beg; n<i_end; n++)
        {
            printf("\n\nName: ");
            printf("%s",employee[n].name);
            printf("\nPhone number: ");
            printf("%s",employee[n].phone);
            printf("\ne-mail: ");
            printf("%s",employee[n].e_mail);
            printf("\nBirth date: ");
            printf("%s",employee[n].birthdate);
            printf("\nCurrent job: ");
            printf("%s",employee[n].current_job);
            printf("\n*************************************************************************");

        }
    }
    //************************************************************************************************************************
}
//****************************************************************************************************************

void DELETE()
{
    //Loading the database if not previously loaded
    if(load_flag==0)
    {
        LOAD();
    }
    //***********************************************************

    char deleted_emp[100];
    int k,wanted_i,check=0;
    char choice;

    //Specifying the name pf the employee want to be deleted and comparing it to the database
    printf("\n\nEnter the name of the employee you want to delete: ");
    scanf("\n");
    scanf("%[^\n]%*c",deleted_emp);
    for(k=0; k<i_counter; k++)
    {
        if(!strcmp(deleted_emp,employee[k].name))
        {
            wanted_i = k;
            break;
        }
        if(k==(i_counter-1))
        {
            printf("\n->The employee is not in the database\n");
            Menu();
        }
    }
    printf("\nIs this the employee you want to delete: ");
    printf("\nName: %s",employee[wanted_i].name);
    printf("\nPhone number: %s",employee[wanted_i].phone);
    printf("\ne-mail: %s",employee[wanted_i].e_mail);
    printf("\nBirthdate: %s",employee[wanted_i].birthdate);
    printf("\nCurrent job: %s",employee[wanted_i].current_job);
    printf("\n*************************************************************************");
    //******************************************************************************************************

    //Confirming the delete order
    printf("\n->press ""y"" to confirm and ""n"" to get back to the menu: ");
    while (check != 1)
    {

        scanf(" %c",&choice);
        if(choice=='y')
        {
            //Deleting process
            check=1;
            for(i=wanted_i; i<(i_counter); i++)
            {
                strcpy(employee[i].name,employee[(i+1)].name);
                strcpy(employee[i].phone,employee[(i+1)].phone);
                strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                strcpy(employee[i].current_job,employee[(i+1)].current_job);
            }
            i_counter--;
            i--;
            printf("\n------------Done Deleting---------------------");
        }
        else if(choice=='n')
        {
            check=1;
            Menu();
        }
        else
        {
            printf("\nPlease chose ""y"" or ""n ""only: ");
        }
    }
    //***********************************************************************************************************

}
//****************************************************************************************************************************

void SAVE()
{

    int k=0;
    FILE* fsave;

    if (load_flag==1)
    {
        sort_a2z();
        fsave=fopen("CompanyDatabase.txt","w");
        printf("\nThe employees to be saved: \n");
        while(k<i_counter)
        {
            printf("\nName: %s",employee[k].name);
            printf("\nPhone number: %s",employee[k].phone);
            printf("\ne-mail: %s",employee[k].e_mail);
            printf("\nBirthdate: %s",employee[k].birthdate);
            printf("\nCurrent job: %s",employee[k].current_job);
            printf("\n**************************************************************");

            fprintf(fsave,"“%s,%s,%s,%s,%s”\n",employee[k].name,employee[k].phone,employee[k].e_mail,employee[k].birthdate,employee[k].current_job);
            k++;
        }
        fclose(fsave);
        printf("\n------------Done saving---------------------");
    }
    else if (load_flag==0)
    {
        LOAD();
        sort_a2z();
        fsave=fopen("CompanyDatabase.txt","w");
        printf("\nThe employees to be saved: \n");
        while(k<i_counter)
        {
            printf("\nName: %s",employee[k].name);
            printf("\nPhone number: %s",employee[k].phone);
            printf("\ne-mail: %s",employee[k].e_mail);
            printf("\nBirthdate: %s",employee[k].birthdate);
            printf("\nCurrent job: %s",employee[k].current_job);
            printf("\n**************************************************************");

            fprintf(fsave,"“%s,%s,%s,%s,%s”\n",employee[k].name,employee[k].phone,employee[k].e_mail,employee[k].birthdate,employee[k].current_job);
            k++;
        }
        fclose(fsave);
        printf("\n------------Done saving---------------------");
    }
}
//****************************************************************************************************************

void SEARCH()
{
    //Loading the database if not previously loaded
    if(load_flag==0)
    {
        LOAD();
    }
    char searched_emp[100];
    int k,wanted_i,check=0;
    //specifying the name of the employee being searched for
    printf("\nEnter the name of the employee you want to search for: ");
    scanf("\n");
    scanf("%[^\n]%*c",searched_emp);
    for(k=0; k<i_counter; k++)
    {
        if(!strcmp(searched_emp,employee[k].name))
        {
            wanted_i = k;
            break;
        }
        if(k==(i_counter-1))
        {
            printf("\nThe employee is not in the database\n");
        }
    }
    //****************************************************************************************

    //Displaying its data on the console
    printf("\nThe employee you are searching for: ");
    printf("\nName: %s",employee[wanted_i].name);
    printf("\nPhone number: %s",employee[wanted_i].phone);
    printf("\ne-mail: %s",employee[wanted_i].e_mail);
    printf("\nBirthdate: %s",employee[wanted_i].birthdate);
    printf("\nCurrent job: %s",employee[wanted_i].current_job);
    printf("\n***********************************************************\n");
    //*********************************************************************************************
}
void MODIFY()
{
    //Loading the database if not previously loaded
    if(load_flag==0)
    {
        LOAD();
    }
    //********************************************************************************************************
    char searched_emp[100];
    int k,wanted_i,check=0,fcheck=0;

    //Specifying the employee the user want to modify and comparing it to the database
    printf("\nEnter the name of the employee you want to modify: ");
    scanf("\n");
    scanf("%[^\n]%*c",searched_emp);
    for(k=0; k<i_counter; k++)
    {
        if(!strcmp(searched_emp,employee[k].name))
        {
            wanted_i = k;
            break;
        }
        if(k==(i_counter-1))
        {
            printf("\nThe employee is not in the database\n");
        }
    }
    printf("The employee you want to modify: ");
    printf("\nName: %s",employee[wanted_i].name);
    printf("\nPhone number: %s",employee[wanted_i].phone);
    printf("\ne-mail: %s",employee[wanted_i].e_mail);
    printf("\nBirthdate: %s",employee[wanted_i].birthdate);
    printf("\nCurrent job: %s",employee[wanted_i].current_job);
    printf("\n*************************************************************************\n");
    //*******************************************************************************************

    //specifying the field the user to modify and modifying
    char targted[100];
    printf("\nwhat do you want to modify 'phone','e_mail','current_job': ");
    while(fcheck==0)
    {
        printf("\nwhat do you want to modify 'phone','e_mail','current_job': ");
        scanf("%s",targted);

        if(!strcmp(targted,"phone"))
        {
            fcheck=1;
            while(check==0)
            {
                printf("Phone number: ");
                scanf("%s",&employee[wanted_i].phone);
                int v_p = Validate_phone();
                if (v_p == 0)
                {
                    printf("please enter digits only\n");
                    check =0;
                }
                else
                {
                    check=1;
                }
            }
        }
        else if(!strcmp(targted,"e_mail"))
        {
            fcheck=1;
            while(check==0)
            {
                printf("e-mail: ");
                scanf("%s",employee[wanted_i].e_mail);
                int v_m = Validate_email();
                if (v_m == 0)
                {
                    printf("Please enter the right format ""Something@website.com ""\n");
                    check=0;
                }
                else
                {
                    check =1;
                }
            }
        }
        else if(!strcmp(targted,"current_job"))
        {
            fcheck=1;
            while(check=0)
            {
                printf("Current job: ");
                scanf("\n");
                scanf("%[^\n]%*c",&employee[wanted_i].current_job);
                int v_j = validate_job();
                if (v_j == 0)
                {
                    printf("please enter the right job\n");
                    check=0;
                }
                else
                {
                    check = 1;
                }
            }
        }
        else
        {
            printf("\nPlease enter one of the mentioned fields: \n");
            fcheck=0;
        }
    }
    //*******************************************************************************************************************
}
//*******************************************************************************************************************

void QUIT()
{
    char c;
    printf(" Press:\ns to save\nq to quit without saving\nc to continue\n:");
    scanf(" %c",&c);
    if(c=='s')
    {
        SAVE();
        quit=1;
    }
    else if(c=='q')
    {
        quit=1;
    }
    else if(c=='c')
    {
        Menu();
    }
    else
    {
        printf("\nPlease choose one of the mentioned options: \n");
        QUIT();
    }
}
//*******************************************************************************************************

void SORT()
{
    //Loading the database if not previously loaded
    if(load_flag==0)
    {
        LOAD();
    }
    //***********************************************************

    char s;
    printf("\nChoose the way to sort the data: \n(a) alphabetically from a to z\n(z) alphabetically from z to a\n(y) according to age from youngest to oldest\n(o) according to age from oldest to youngest\n");
    printf("Write the letter of your choice:");
    scanf(" %c",&s);

    if(s=='a')
        sort_a2z();

    else if(s=='z')
        sort_z2a();

    else if(s=='y')
    {
        sort_y2o();
    }


    else if(s=='o')
        sort_o2y();

    else
    {
        printf("->please enter one of the mentioned options");
        SORT();
    }

    int k=0;
    while(k<i_counter)
        {
            printf("\nName: %s",employee[k].name);
            printf("\nPhone number: %s",employee[k].phone);
            printf("\ne-mail: %s",employee[k].e_mail);
            printf("\nBirthdate: %s",employee[k].birthdate);
            printf("\nCurrent job: %s",employee[k].current_job);
            printf("\n**************************************************************");
            k++;
        }

}

void sort_a2z()
{
    struct data temp;
    int j,k=0;

    for(j=0; j<(i_counter-1); j++)
    {
        for(i=0; i<(i_counter-1); i++)
        {
            if(employee[(i+1)].name[k]<employee[i].name[k])
            {
                strcpy(temp.name,employee[i].name);
                strcpy(temp.phone,employee[i].phone);
                strcpy(temp.e_mail,employee[i].e_mail);
                strcpy(temp.birthdate,employee[i].birthdate);
                strcpy(temp.current_job,employee[i].current_job);
                //*********************************************************
                strcpy(employee[i].name,employee[(i+1)].name);
                strcpy(employee[i].phone,employee[(i+1)].phone);
                strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                strcpy(employee[i].current_job,employee[(i+1)].current_job);
                //*************************************************************
                strcpy(employee[(i+1)].name,temp.name);
                strcpy(employee[(i+1)].phone,temp.phone);
                strcpy(employee[(i+1)].e_mail,temp.e_mail);
                strcpy(employee[(i+1)].birthdate,temp.birthdate);
                strcpy(employee[(i+1)].current_job,temp.current_job);
                //*************************************************************
            }
            else if(employee[(i+1)].name[k]==employee[i].name[k])
            {
                k++;
                if(employee[(i+1)].name[k]<employee[i].name[k])
                {
                    strcpy(temp.name,employee[i].name);
                    strcpy(temp.phone,employee[i].phone);
                    strcpy(temp.e_mail,employee[i].e_mail);
                    strcpy(temp.birthdate,employee[i].birthdate);
                    strcpy(temp.current_job,employee[i].current_job);
                    //*********************************************************
                    strcpy(employee[i].name,employee[(i+1)].name);
                    strcpy(employee[i].phone,employee[(i+1)].phone);
                    strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                    strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                    strcpy(employee[i].current_job,employee[(i+1)].current_job);
                    //*************************************************************
                    strcpy(employee[(i+1)].name,temp.name);
                    strcpy(employee[(i+1)].phone,temp.phone);
                    strcpy(employee[(i+1)].e_mail,temp.e_mail);
                    strcpy(employee[(i+1)].birthdate,temp.birthdate);
                    strcpy(employee[(i+1)].current_job,temp.current_job);
                    //*************************************************************
                }
                else if(employee[(i+1)].name[k]==employee[i].name[k])
                {
                    k++;
                    if(employee[(i+1)].name[k]<employee[i].name[k])
                    {
                        strcpy(temp.name,employee[i].name);
                        strcpy(temp.phone,employee[i].phone);
                        strcpy(temp.e_mail,employee[i].e_mail);
                        strcpy(temp.birthdate,employee[i].birthdate);
                        strcpy(temp.current_job,employee[i].current_job);
                        //*********************************************************
                        strcpy(employee[i].name,employee[(i+1)].name);
                        strcpy(employee[i].phone,employee[(i+1)].phone);
                        strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                        strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                        strcpy(employee[i].current_job,employee[(i+1)].current_job);
                        //*************************************************************
                        strcpy(employee[(i+1)].name,temp.name);
                        strcpy(employee[(i+1)].phone,temp.phone);
                        strcpy(employee[(i+1)].e_mail,temp.e_mail);
                        strcpy(employee[(i+1)].birthdate,temp.birthdate);
                        strcpy(employee[(i+1)].current_job,temp.current_job);
                        //*************************************************************
                    }

                }
            }
            k=0;
        }
    }
    i=i_counter;
}
//**************************************************************************************************************************

void sort_z2a()
{
    struct data temp;
    int j,k=0;

    for(j=0; j<(i_counter-1); j++)
    {
        for(i=0; i<(i_counter-1); i++)
        {
            if(employee[(i+1)].name[k]>employee[i].name[k])
            {
                strcpy(temp.name,employee[i].name);
                strcpy(temp.phone,employee[i].phone);
                strcpy(temp.e_mail,employee[i].e_mail);
                strcpy(temp.birthdate,employee[i].birthdate);
                strcpy(temp.current_job,employee[i].current_job);
                //*********************************************************
                strcpy(employee[i].name,employee[(i+1)].name);
                strcpy(employee[i].phone,employee[(i+1)].phone);
                strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                strcpy(employee[i].current_job,employee[(i+1)].current_job);
                //*************************************************************
                strcpy(employee[(i+1)].name,temp.name);
                strcpy(employee[(i+1)].phone,temp.phone);
                strcpy(employee[(i+1)].e_mail,temp.e_mail);
                strcpy(employee[(i+1)].birthdate,temp.birthdate);
                strcpy(employee[(i+1)].current_job,temp.current_job);
                //*************************************************************
            }
            else if(employee[(i+1)].name[k]==employee[i].name[k])
            {
                k++;
                if(employee[(i+1)].name[k]>employee[i].name[k])
                {
                    strcpy(temp.name,employee[i].name);
                    strcpy(temp.phone,employee[i].phone);
                    strcpy(temp.e_mail,employee[i].e_mail);
                    strcpy(temp.birthdate,employee[i].birthdate);
                    strcpy(temp.current_job,employee[i].current_job);
                    //*********************************************************
                    strcpy(employee[i].name,employee[(i+1)].name);
                    strcpy(employee[i].phone,employee[(i+1)].phone);
                    strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                    strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                    strcpy(employee[i].current_job,employee[(i+1)].current_job);
                    //*************************************************************
                    strcpy(employee[(i+1)].name,temp.name);
                    strcpy(employee[(i+1)].phone,temp.phone);
                    strcpy(employee[(i+1)].e_mail,temp.e_mail);
                    strcpy(employee[(i+1)].birthdate,temp.birthdate);
                    strcpy(employee[(i+1)].current_job,temp.current_job);
                    //*************************************************************
                }
                else if(employee[(i+1)].name[k]==employee[i].name[k])
                {
                    k++;
                    if(employee[(i+1)].name[k]>employee[i].name[k])
                    {
                        strcpy(temp.name,employee[i].name);
                        strcpy(temp.phone,employee[i].phone);
                        strcpy(temp.e_mail,employee[i].e_mail);
                        strcpy(temp.birthdate,employee[i].birthdate);
                        strcpy(temp.current_job,employee[i].current_job);
                        //*********************************************************
                        strcpy(employee[i].name,employee[(i+1)].name);
                        strcpy(employee[i].phone,employee[(i+1)].phone);
                        strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                        strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                        strcpy(employee[i].current_job,employee[(i+1)].current_job);
                        //*************************************************************
                        strcpy(employee[(i+1)].name,temp.name);
                        strcpy(employee[(i+1)].phone,temp.phone);
                        strcpy(employee[(i+1)].e_mail,temp.e_mail);
                        strcpy(employee[(i+1)].birthdate,temp.birthdate);
                        strcpy(employee[(i+1)].current_job,temp.current_job);
                        //*************************************************************
                    }

                }
            }
            k=0;
        }
    }
    i=i_counter;
}
 //***********************************************************************************************************************

 void sort_y2o()
 {
    struct data temp;
    int j,k=8;

    for(j=0; j<(i_counter-1); j++)
    {
        for(i=0; i<(i_counter-1); i++)
        {
            if(employee[(i+1)].birthdate[k]>employee[i].birthdate[k])
            {
                strcpy(temp.name,employee[i].name);
                strcpy(temp.phone,employee[i].phone);
                strcpy(temp.e_mail,employee[i].e_mail);
                strcpy(temp.birthdate,employee[i].birthdate);
                strcpy(temp.current_job,employee[i].current_job);
                //*********************************************************
                strcpy(employee[i].name,employee[(i+1)].name);
                strcpy(employee[i].phone,employee[(i+1)].phone);
                strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                strcpy(employee[i].current_job,employee[(i+1)].current_job);
                //*************************************************************
                strcpy(employee[(i+1)].name,temp.name);
                strcpy(employee[(i+1)].phone,temp.phone);
                strcpy(employee[(i+1)].e_mail,temp.e_mail);
                strcpy(employee[(i+1)].birthdate,temp.birthdate);
                strcpy(employee[(i+1)].current_job,temp.current_job);
                //*************************************************************
            }
            else if(employee[(i+1)].name[k]==employee[i].name[k])
            {
                k++;
                if(employee[(i+1)].name[k]>employee[i].name[k])
                {
                    strcpy(temp.name,employee[i].name);
                    strcpy(temp.phone,employee[i].phone);
                    strcpy(temp.e_mail,employee[i].e_mail);
                    strcpy(temp.birthdate,employee[i].birthdate);
                    strcpy(temp.current_job,employee[i].current_job);
                    //*********************************************************
                    strcpy(employee[i].name,employee[(i+1)].name);
                    strcpy(employee[i].phone,employee[(i+1)].phone);
                    strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                    strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                    strcpy(employee[i].current_job,employee[(i+1)].current_job);
                    //*************************************************************
                    strcpy(employee[(i+1)].name,temp.name);
                    strcpy(employee[(i+1)].phone,temp.phone);
                    strcpy(employee[(i+1)].e_mail,temp.e_mail);
                    strcpy(employee[(i+1)].birthdate,temp.birthdate);
                    strcpy(employee[(i+1)].current_job,temp.current_job);
                    //*************************************************************
                }

            }
            k=8;
        }
    }
    i=i_counter;
 }
 //*****************************************************************************************************************

 void sort_o2y()
 {
    struct data temp;
    int j,k=8;

    for(j=0; j<(i_counter-1); j++)
    {
        for(i=0; i<(i_counter-1); i++)
        {
            if(employee[(i+1)].birthdate[k]<employee[i].birthdate[k])
            {
                strcpy(temp.name,employee[i].name);
                strcpy(temp.phone,employee[i].phone);
                strcpy(temp.e_mail,employee[i].e_mail);
                strcpy(temp.birthdate,employee[i].birthdate);
                strcpy(temp.current_job,employee[i].current_job);
                //*********************************************************
                strcpy(employee[i].name,employee[(i+1)].name);
                strcpy(employee[i].phone,employee[(i+1)].phone);
                strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                strcpy(employee[i].current_job,employee[(i+1)].current_job);
                //*************************************************************
                strcpy(employee[(i+1)].name,temp.name);
                strcpy(employee[(i+1)].phone,temp.phone);
                strcpy(employee[(i+1)].e_mail,temp.e_mail);
                strcpy(employee[(i+1)].birthdate,temp.birthdate);
                strcpy(employee[(i+1)].current_job,temp.current_job);
                //*************************************************************
            }
            else if(employee[(i+1)].name[k]==employee[i].name[k])
            {
                k++;
                if(employee[(i+1)].name[k]<employee[i].name[k])
                {
                    strcpy(temp.name,employee[i].name);
                    strcpy(temp.phone,employee[i].phone);
                    strcpy(temp.e_mail,employee[i].e_mail);
                    strcpy(temp.birthdate,employee[i].birthdate);
                    strcpy(temp.current_job,employee[i].current_job);
                    //*********************************************************
                    strcpy(employee[i].name,employee[(i+1)].name);
                    strcpy(employee[i].phone,employee[(i+1)].phone);
                    strcpy(employee[i].e_mail,employee[(i+1)].e_mail);
                    strcpy(employee[i].birthdate,employee[(i+1)].birthdate);
                    strcpy(employee[i].current_job,employee[(i+1)].current_job);
                    //*************************************************************
                    strcpy(employee[(i+1)].name,temp.name);
                    strcpy(employee[(i+1)].phone,temp.phone);
                    strcpy(employee[(i+1)].e_mail,temp.e_mail);
                    strcpy(employee[(i+1)].birthdate,temp.birthdate);
                    strcpy(employee[(i+1)].current_job,temp.current_job);
                    //*************************************************************
                }

            }
            k=8;
        }
    }
    i=i_counter;
 }
 //*****************************************************************************************************************
