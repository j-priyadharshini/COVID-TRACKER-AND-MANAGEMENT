//COVID-19 MANAGEMENT
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

void edit();
void nearby();
void search();
void read_data();
void view();
void testing_center();
void self_asses();
void end();
void login();
void g_check();
void c_menu();
void analysis();
void g_menu();
void system_switcher();
void open_screen();

char ans=0;
int ok,valid=0;

struct patient
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20];
	char Contact_no[15];
	struct address
	{
	    char Address[50];
	    int pincode;
	}ad;
}p,temp_c;

void gotoxy(short x,short y)
{
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void edit()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n\n\n");
    char f_name[20],l_name[20];
	int found=0;
    FILE *ek, *ft,*analyze,*temp;
    int dead,cured,aff;
	ft=fopen("temp_file2.dat","w+");
	ek=fopen("Record2.dat","r");
	printf("\n Enter name to delete");
	printf("\nFirst name:");
	scanf("%s",f_name);
	f_name[0]=toupper(f_name[0]);
	printf("\nLast name:");
	scanf("%s",l_name);
	l_name[0]=toupper(l_name[0]);
	while(fscanf(ek,"%s %s %c %s %i %s %i\n", p.First_Name, p.Last_Name,&p.Gender, p.Contact_no,
				 &p.age, p.ad.Address,&p.ad.pincode)!=EOF)
    {
        if (strcmp(p.First_Name,f_name)!=0 || strcmp(p.Last_Name,l_name)!=0)
        {
                fprintf(ft,"%s %s %c %s %i %s %i\n", p.First_Name, p.Last_Name,p.Gender, p.Contact_no,
				 p.age, p.ad.Address,p.ad.pincode);
        }
        else
        {
            found=1;
        }
    }
    if(found==0)
    {
        printf("Record not found\n");
        getch();
        g_menu();
    }
    else
    {
        int flag;
        printf("Press-\n0 if the person is dead.\n1 if the person is cured.\n");
        scanf("%d",&flag);
        analyze=fopen("cases.dat","r");
        temp=fopen("temp_file.dat","w+");
        fscanf(analyze,"%d %d %d",&cured,&aff,&dead);
	if(flag)
    {
        cured++;
    }
    else{
        dead++;
    }aff--;
    fprintf(temp,"%d %d %d",cured,aff,dead);
    fclose(temp);
    fclose(analyze);
    remove("cases.dat");
    rename("temp_file.dat","cases.dat");

    fclose(ek);
    fclose(ft);
    remove("Record2.dat");
    rename("temp_file2.dat","Record2.dat");
    printf("Record removed ");
    getch();
    g_menu();
    }

}

void nearby()
{
    system("cls");
        printf("\n\t\t\t\t\t\t\t  COVID-19\n");
        printf("\t\t\t\t\t\t  ************************\n\n");
        int row=0,n;
        FILE *ek;
	    ek=fopen("Record2.dat","r");
        printf("No. of Covid patients in your area\n");
        printf("********************************\n");
        printf("Enter your area pincode\n");
        scanf("%i",&n);
        while(fscanf(ek,"%s %s %c %s %i %s %i\n", p.First_Name, p.Last_Name,&p.Gender, p.Contact_no,
				 &p.age, p.ad.Address,&p.ad.pincode)!=EOF)
        {
            if(p.ad.pincode==n)
            {
                row++;
            }
        }
        printf("\nNumber of people affected nearby your area: %i",row);
        fclose(ek);
        getch();
        c_menu();
}

void search()
{
        system("cls");
        printf("\n\t\t\t\t\t\t\t  COVID-19\n");
        printf("\t\t\t\t\t\t  ************************\n\n");
        int row,n;
        FILE *ek;
	    ek=fopen("Record2.dat","r");
        printf("Covid patients list in that area\n");
        printf("********************************\n");
        printf("Enter the area pincode\n");
        scanf("%i",&n);
		gotoxy(1,8);
		printf("Full Name");
		gotoxy(20,8);
		printf("Gender");
		gotoxy(32,8);
		printf("Contact No.");
		gotoxy(49,8);
		printf("Age");
		gotoxy(55,8);
		printf("Address");
		gotoxy(94,8);
		printf("Pincode");
		gotoxy(101,8);
		row=10;
		while(fscanf(ek,"%s %s %c %s %i %s %i\n", p.First_Name, p.Last_Name,&p.Gender, p.Contact_no,
				 &p.age, p.ad.Address,&p.ad.pincode)!=EOF)
        {
            if(p.ad.pincode==n)
            {
            gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(32,row);
			printf("%s",p.Contact_no);
			gotoxy(49,row);
			printf("%i",p.age);
			gotoxy(55,row);
			printf("%s",p.ad.Address);
			gotoxy(94,row);
			printf("%i",p.ad.pincode);
			gotoxy(49,row);
			row++;
            }
        }
        fclose(ek);
        getch();
        g_menu();
}

void analysis()
{
    system("cls");
    int cured,aff,dead;
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n");
    FILE *analyze;
    analyze=fopen("cases.dat","r");
    fscanf(analyze,"%d %d %d",&cured,&aff,&dead);
    printf("Number of people cured: %d\nNumber of people affected: %d\nNumber of people dead: %d\n",cured,aff,dead);
    fclose(analyze);
    getch();
}
void read_data()
{
    system("cls");int flag=0;
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n");
    printf("Enter the details\n");
    printf("*****************\n");
    FILE *ek,*analyze,*temp;
    int dead,cured,aff;
    analyze=fopen("cases.dat","r");
    temp=fopen("temp_file.dat","w+");
    fscanf(analyze,"%d %d %d",&cured,&aff,&dead);
    aff++;
    fprintf(temp,"%d %d %d",cured,aff,dead);
    fclose(temp);
    fclose(analyze);
    remove("cases.dat");
    rename("temp_file.dat","cases.dat");
    ek=fopen("Record2.dat","a");
    do{
    printf("First Name:\n");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\nInvalid\nThe max range for first name is 20 and min range is 2\n");
		flag=1;
		//end();
	}
	else
        flag=0;
	}while(flag);
	do{
	printf("Last Name:\n");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\nInvalid\nThe max range for last name is 20 and min range is 2\n");
		flag=1;
		//end();
	}
	else
        flag=0;
	}while(flag);
	do
	{
	    printf("\nGender[F/M]:\n");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok =1;
		}
		else
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\nGender contain Invalid character\nEnter either F or M\n");
    	}
	 }	while(!ok);
	 do{
     printf("\nContact no:\n");
     scanf("%s",p.Contact_no);
     if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
	 {
	  	 printf("Invalid\nContact no. must contain 10 numbers.\nEnter again\n");
		 flag=1;
		 //end();
	 }
	 else
        flag=0;}while(flag);
    printf("\nAge:");
    scanf(" %i",&p.age);
    do{
    printf("\nAddress (without space):\n");
    scanf("%s",p.ad.Address);
    p.ad.Address[0]=toupper(p.ad.Address[0]);
    if(strlen(p.ad.Address)>40||strlen(p.ad.Address)<4)
	{
		printf("\nInvalid\nThe max range for address is 40 and min range is 4\n");
		flag=1;
		//end();
	}else
	flag=0;
    }while(flag);
    printf("\nPincode(without space):\n");
    scanf(" %i",&p.ad.pincode);
    fprintf(ek,"\n%s %s %c %s %i %s %i\n", p.First_Name, p.Last_Name,p.Gender, p.Contact_no,
				 p.age, p.ad.Address,p.ad.pincode);
    printf("\n\nInformation Recorded...\n");
    fclose(ek);
}


void view()
{
        system("cls");
        printf("\n\t\t\t\t\t\t\t  COVID-19\n");
        printf("\t\t\t\t\t\t  ************************\n\n");
        int row;
        FILE *ek;
	    ek=fopen("Record2.dat","r");
        printf("Covid patients list\n");
        printf("*******************\n");
		gotoxy(3,7);
		printf("Full Name");
		gotoxy(20,7);
		printf("Gender");
		gotoxy(32,7);
		printf("Contact No.");
		gotoxy(49,7);
		printf("Age");
		gotoxy(55,7);
		printf("Address");
		gotoxy(94,7);
		printf("Pincode");
		gotoxy(101,7);
		row=9;
		while(fscanf(ek,"%s %s %c %s %i %s %i\n", p.First_Name, p.Last_Name,&p.Gender, p.Contact_no,
				 &p.age, p.ad.Address,&p.ad.pincode)!=EOF)
        {
            gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(32,row);
			printf("%s",p.Contact_no);
			gotoxy(49,row);
			printf("%i",p.age);
			gotoxy(55,row);
			printf("%s",p.ad.Address);
			gotoxy(94,row);
			printf("%i",p.ad.pincode);
			gotoxy(49,row);
			row++;
        }
        fclose(ek);
        getch();
        g_menu();
}

void testing_center()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n");
    FILE *fptr;
    char  c;
    fptr = fopen("list.dat", "r");
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }

    fclose(fptr);
    getch();
    c_menu();
}

void self_asses()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n");
    printf("Self assessment\n\n");
    printf("***************\n");
    int n=0,i;
    printf("If YES press \" 1 \"\nIf NO press \" 0 \"\n");
    printf("\nDo you have cough?  ");
    scanf("%i",&i);
    if(i==1){n++;}
    printf("\nDo you have fever?  ");
    scanf("%i",&i);
    if(i==1){n++;}
    printf("\nDo you have breathing issue?  ");
    scanf("%i",&i);
    if(i==1){n++;}
    printf("\nDo you have diabetes or hypertension or lung diseases or heart diseases?  ");
    scanf("%i",&i);
    if(i==1){n++;}
    printf("\nDid you travel abroad?  ");
    scanf("%i",&i);
    if(i==1){n++;}
    printf("\nDid you meet anyone with covid patient?  ");
    scanf("%i",&i);
    if(i==1){n=n+5;}
    if(n>4)
    {
        printf("\n\nYou have chances of Covid-19\nThe officials will contact you");
        getch();
        read_data();
        getch();
        c_menu();
    }
    else
    {
        printf("\n...You are safe...");
        getch();
        c_menu();
    }
}
void end()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n\n");
    printf("\n\n\t\t\t\t\t\t\tTHANK YOU");
    getch();
}

void g_menu()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n\n\n");
    printf("\nPress the number corresponding to your choice_\n\n1.View the record of all covid patients.\n2.Patients list in an area\n3.Update the list if the person is safe or dead \n4.Add affected person details\n5.Analysis record\n6.Exit\n");
    int n;
    scanf("%i",&n);
    if (n==1)
    {
        view();
    }
    else if (n==2)
    {
        search();
    }
    else if (n==3)
    {
        edit();
    }
        else if (n==4)
    {
        read_data();
        getch();
        g_menu();
    }
    else if (n==5)
    {
        analysis();
        g_menu();
    }
    else if (n==6)
    {
        end();
    }
    else
    {
        system_switcher();
    }
    getch();
}

void login()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n\n");
    int e=0	;
    char Username[15];
    char Password[15];
    char original_Username[25]="GOVERNMENT";
    char original_Password[15]="COVID-19";

    do
    {
        printf("\nEnter your Username and Password");
        printf("\nUSERNAME:");
        scanf("%s",Username);
        printf("\nPASSWORD:");
        scanf("%s",Password);
        if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
        {
            printf("\nLogin Successfull...\npress any key to continue");
            getch();
            g_menu();
            break;
        }
        else
        {
            printf("\nPassword in incorrect,Try Again ");
            e++;
            getch();
        }
    }while(e<=2);
    if(e>2)
    {
    printf("\nYou have crossed the limit. You cannot login");
    getch();
    end();
    }
}

void g_check()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n");
    login();
}

void c_menu()
{
    system("cls");int cured,dead,aff;
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n");
    printf("\nPress the number corresponding to your choice_\n\n1.Self assessment\n2.Number of affected people nearby\n3.Testing centers list\n4.Analysis record\n5.Exit\n");
    int n;
    scanf("%i",&n);
    if (n==1)
    {
        self_asses();
    }
    else if (n==2)
    {
        nearby();
    }
    else if (n==3)
    {
        testing_center();
    }
    else if (n==4)
    {
       analysis();
        c_menu();
    }
     else if (n==5)
    {
        end();
    }
    else
    {
        system_switcher();
    }
    getch();
}

void system_switcher()
{
    system("cls");
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n");
    int n;
    printf("\nPress the number corresponding to your choice_\n\n1.Government officials\n2.Citizens\n");
    scanf("%i",&n);
    if(n==1)
    {
        g_check();
    }
    else if(n==2)
    {
        c_menu();
    }
    else
    {
        system_switcher();
    }
    getch();
}

void open_screen()
{
    printf("\n\t\t\t\t\t\t\t  COVID-19\n");
    printf("\t\t\t\t\t\t  ************************\n\n\n");
    printf("\t\t\t\t\t    ALL INDIA CORONA MONITORING SYSTEM\n\n\n");
    printf("\t\t\t\t\t\t  ************************\n\n\n");
    printf("Press any key to continue...");
    getch();
    system("cls");
}

int main()
{
    open_screen();
    system_switcher();
    return 0;
}