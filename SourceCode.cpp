#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<string.h>
#include<fstream>
#include<windows.h>
using namespace std;
char ans=0;
int ok;
int b, valid=0;
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void Login(void);
void ex_it(void);

class patient
{
	private:
		int age;
	    char Gender;
	    char First_Name[20];
	    char Last_Name[20];
	    char Contact_no[15];
        char Address[30];
	    char Email[30];
	    char Doctor[20];
	    char Problem[20];
	public:
		void MainMenu();
		void Add_rec();
		void func_list();
		void take_data();
		void search();
		void modify();
		void del();

};
void Title(void)//function for title screen
{cout<<"\n\n\t\t==================================================================================";
	cout<<"\n\t\t----------------------------------------------------------------------------------"<<endl;
	cout<<"\n\t\t\t\t       INDGRA GANDHI HOSPITAL         "<<endl;
	cout<<"\n\t\t----------------------------------------------------------------------------------"<<endl;
	cout<<"\t\t==================================================================================";
}
void WelcomeScreen(void) //function for welcome screen
{
    cout<<"\n\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\n\t\t\t\t|\t\t WELCOME TO\t\t   |"<<endl;
	cout<<"\t\t\t\t| INDGRA GANDHI HOSPITAL MANAGEMENT SYSTEM |"<<endl;
	cout<<"\n\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\t\t\t\t--------------------------------------------"<<endl;
	cout<<"\n\n\n\n\n\t\t\t\t\tPress enter to continue......\n";
	getch();//Use to holds screen for some seconds
	system("cls");//Use to clear screen

}
void LoginScreen(void)//function for login screen
{
//list of variables
int e=0	,i;
char Username[15];
char Password[15];
do
{
	cout<<"\n\n\n\n\t\t\t\tEnter your Username and Password :)"<<endl;
	cout<<"\n\n\n\t\t\t\t\tUSERNAME: ";
	cin>>Username;

	cout<<"\n\n\t\t\t\t\tPASSWORD: ";
	cin>>Password;
	for ( i = 0; i <=5; i++) {
            if (Username[i] != Password[i])
                break;

    }
	if(i==6){
        cout<<"\n\n\n\t\t\t\t\t...Login Successfull..."<<endl;
        cout<<"\n\n\n\t\t\t\t\tLoading";
			for(int i=1;i<=6;i++)
			{
				Sleep(500);
				cout<<".";
			}

		//MainMenu();//call MainMenu function
		break;
	}
	else
	{
		printf("\n\t\t\tPassword in incorrect:( Try Again :)");
		e++;
		getch();
	}

}
while(e<=2);
	if(e>2)
	{
	printf("You have cross the limit. You cannot login. :( :(");
	getch();
    ex_it();
	}}
void ex_it(void)	//function to exit
{
	system("cls");
	Title();// call Title function
	cout<<"\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)"<<endl;
	getch();//holds screen

}
void patient:: MainMenu()//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	cout<<"\n\n\n\n\n\t\t\t\t1. Add Patients Record\n";
	cout<<"\n\t\t\t\t2. List Patients Record\n";
	cout<<"\n\t\t\t\t3. Search Patients Record\n";
	cout<<"\n\t\t\t\t4. Edit Patients Record\n";
	cout<<"\n\t\t\t\t5. Delete Patients Record\n";
	cout<<"\n\t\t\t\t6. Exit\n";
	cout<<"\n\n\n \n\t\t\t\tChoose from 1 to 6:";
	cin>>choose;

	switch(choose)//switch to differeht case
	{

	case 1:
	Add_rec();//Add_rec function is called
    	break;
    case 2:
    	func_list();
    	break;
    case 3:
        search();
        break;
    case 4:
        modify();
        break;
    case 5:
        del();
        break;

	case 6:
		ex_it();//ex_it function is call
    	break;

	default:
		cout<<"\t\t\tInvalid entry. Please enter right option :)";
		getch();//holds screen
	}


}
void patient::take_data(){
    A:
	cout<<"\n\t\t\tFirst Name : ";
	cin>> First_Name;
    First_Name[0]=toupper(First_Name[0]);
	if(strlen(First_Name)>20||strlen(First_Name)<2)
	{
		cout<<"\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)";
		goto A;
	}
	else
	{
		for (b=0;b<strlen(First_Name);b++)
		{
			if (isalpha(First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			cout<<"\n\t\t First name contain Invalid character :(  Enter again :)";
			goto A;
		}
	}

	/* ********************************************** Last name ************************************************ */
	B:
	cout<<"\n\t\t\tLast Name: ";
	cin>>Last_Name;
    Last_Name[0]=toupper(Last_Name[0]);
    if(strlen(Last_Name)>20||strlen(Last_Name)<2)
	{
		cout<<"\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)";
		goto B;
	}
	else
	{
		for (b=0;b<strlen(Last_Name);b++)
		{
			if (isalpha(Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			cout<<"\n\t\t Last name contain Invalid character :(  Enter again :)";
			goto B;
		}
	}
//*********************************************(gender)*************************************************************
do
	{
	    cout<<"\n\t\t\tGender[F/M]: ";
		cin>>Gender;
		if(toupper(Gender)=='M'|| toupper(Gender)=='F')
		{
			ok =1;
		}
		else
		{
		ok =0;
		}
        if(!ok)
	    {
	    	cout<<"\n\t\t Gender contain Invalid character :(  Enter either F or M :)";
    	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */
   cout<<"\n\t\t\tAge:";
    cin>>age;
/* **************************************** Address ******************************************************************* */

    C:
     cout<<"\n\t\t\tAddress: ";
    cin>>Address;
    Address[0]=toupper(Address[0]);
    if(strlen(Address)>20||strlen(Address)<4)
	{
		cout<<"\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)";
		goto C;
	}


/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    cout<<"\n\t\t\tContact no: ";
    cin>>Contact_no;
    if(strlen(Contact_no)>10||strlen(Contact_no)!=10)
	{
		cout<<"\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)";
		goto D;
	}
	else
	{
		for (b=0;b<strlen(Contact_no);b++)
		{
			if (!isalpha(Contact_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			cout<<"\n\t\t Contact no. contain Invalid character :(  Enter again :)";
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    cout<<"\n\t\t\tEmail: ";
    cin>>Email;
    if (strlen(Email)>30||strlen(Email)<8)
    {
      cout<<"\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)";
	}
}while(strlen(Email)>30||strlen(Email)<8);
/* ********************************************************* Problem *********************************************** */
    E:
    cout<<"\n\t\t\tProblem: ";
    cin>>Problem;
    Problem[0]=toupper(Problem[0]);
    if(strlen(Problem)>15||strlen(Problem)<3)
	{
		cout<<"\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)";
		goto E;
	}
	else
	{
		for (b=0;b<strlen(Problem);b++)
		{
			if (isalpha(Problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
		cout<<"\n\t\t Problem contain Invalid character :(  Enter again :)";
			goto E;
		}
	}
/* ********************************************** Prescribed Doctor **************************************** */
	F:
    cout<<"\n\t\t\tPrescribed Doctor:";
    cin>>Doctor;
    Doctor[0]=toupper(Doctor[0]);
    if(strlen(Doctor)>30||strlen(Doctor)<3)
	{
		cout<<"\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)";
		goto F;
	}
	else
	{
		for (b=0;b<strlen(Doctor);b++)
		{
			if (isalpha(Doctor[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			cout<<"\n\t\t Doctor name contain Invalid character :(  Enter again :)";
			goto F;
		}
	}


    }
void patient::Add_rec()
	{
		system("cls");
		 Title();
		int found=0;
		fstream file;
		cout<<"\n\n\t\t\t.................. Add Patients Record.........................\n";

        take_data();
        file.open("patient.txt",ios::out|ios::app);


   // cout<<First_Name<<" "<<Last_Name<<" "<<Gender<<" "<<age<<" "<<Address<<" "<<Contact_no<<" "<<Email<<" "<<Problem<<" "<<Doctor<<"\n";
    file<<" "<<First_Name<<" "<<Last_Name<<" "<<Gender<<" "<<age<<" "<<Address<<" "<<Contact_no<<" "<<Email<<" "<<Problem<<" "<<Doctor<<"\n";
    file.close();
    cout<<"\n\n\t\t\t.... Information Record Successful ...";
    sd:
    getch();
    cout<<"\n\n\t\t\tDo you want to add more[Y/N]?? ";
    cin>>ans;
    if (toupper(ans)=='Y')
	{
    	Add_rec();
	}
    else if(toupper(ans)=='N')
	{
		cout<<"\n\t\t Thank you :) :)";
    	getch();
    	MainMenu();
	}
    else
    {
        cout<<"\n\t\tInvalid Input\n";
        goto sd;
    }
}
void patient:: func_list()
{

	system("cls");
	Title();

		fstream file;
		cout<<"\n\n\t\t\t\tDisplay Record";
		file.open("patient.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			MainMenu();
		}
		file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
		while(!file.eof())
		{

			cout<<"\n\n\t\t Name : "<<First_Name<<" "<<Last_Name;
			cout<<"\n\t\t gender : "<<Gender;
			cout<<"\n\t\t Age : "<<age;
			cout<<"\n\t\t Address : "<<Address;
			cout<<"\n\t\t Contact_no : "<<Contact_no;
			cout<<"\n\t\t Email : "<<Email;
			cout<<"\n\t\t Problem : "<<Problem;
			cout<<"\n\t\tDoctor : "<<Doctor;
			file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
			cout<<"\n\t\t***************************************************"<<endl;


		}
		file.close();


		getch();
		MainMenu();
}
void patient::search()
	{
		system("cls");
		fstream file;
        char firstname[20];

		int found=0;
		cout<<"\n\n\t\t\t\tSearch Record";
		file.open("patient.txt",ios::in);
		if(!file)
		{
			cout<<"\n\n File Openning Error...";
			getch();
			MainMenu();
		}
		cout<<"\n\n Patient name For Search : ";
		cin>>firstname;
		firstname[0]=toupper(firstname[0]);
		file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
		while(!file.eof())
		{
			if(strcmp(First_Name, firstname)==0)
			{
			system("cls");
			Title();
			cout<<"\n\n\t\t\t\tSearch Record";
			cout<<"\n\nFirst name: "<<First_Name;
			cout<<"\n\nlast Name : "<<Last_Name;
			cout<<"\n\n gender : "<<Gender;
			cout<<"\n\n Age : "<<age;
			cout<<"\n\n Address : "<<Address;
			cout<<"\n\n Contact_no : "<<Contact_no;
			cout<<"\n\n Email : "<<Email;
			cout<<"\n\n Problem : "<<Problem;
			cout<<"\n\n Doctor : "<<Doctor;
			found++;
			}
			file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
		}
		if(strcmp(First_Name,firstname)!=0)
	   {

		printf("Record not found!");
		getch();
	   }
	    file.close();
    L:
	getch();
	cout<<"\n\n\t\t\tDo you want to view more[Y/N]??";
    cin>>ans;
    if (toupper(ans)=='Y')
    {
        search();
    }
	else if(toupper(ans)=='N')
	{
		cout<<"\n\t\t Thank you :) :)";
    	getch();
		MainMenu();
    }
	else
    {
    	cout<<"\n\tInvalid Input.\n";
    	goto L;
    }

	}

	//***********************************edit*********************************************************
	void patient::modify()
	{
		system("cls");
		int sall,found=0;
		char name[20];

		fstream file,file2;
		cout<<"\n\n\t\t\t\tModify Record";
		file.open("patient.txt",ios::in);

		if(!file )
		{
			cout<<"\n\n File Openning Error...";
			getch();
			MainMenu();
		}
		cout<<"\n\n Patient name For Modify : ";
		cin>>name;
		name[0]=toupper(name[0]);
		file2.open("patient1.txt",ios::app|ios::out);
		file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
		while(!file.eof())
		{
			if(strcmp(First_Name,name)==0)
			{
				system("cls");
				Title();
				cout<<"\n\n\t\t\t\tModify Record";
				take_data();

				file2<<" "<<First_Name<<" "<<Last_Name<<" "<<Gender<<" "<<age<<" "<<Address<<" "<<Contact_no<<" "<<Email<<" "<<Problem<<" "<<Doctor<<"\n";;
				found++;
			}
			else
			{
				file2<<" "<<First_Name<<" "<<Last_Name<<" "<<Gender<<" "<<age<<" "<<Address<<" "<<Contact_no<<" "<<Email<<" "<<Problem<<" "<<Doctor<<"\n";
			}
			file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
		}
		if(found == 0)
		cout<<"\n\n Patient Can't Found...";
		else
		cout<<"\n\n\t\t\t Record Modify Successfully...";
		file.close();
		file2.close();
		remove("patient.txt");
		rename("patient1.txt","patient.txt");
		getch();
		MainMenu();

	}

/* ************************************************* Delete record ********************************************* */
void patient::del()
	{
		system("cls");
		Title();
		int found=0;
		char name[20];
		fstream file,file2;
		cout<<"\n\n\t\t\t\tDelete Record";
		file.open("patient.txt",ios::in);

		if(!file )
		{
			cout<<"\n\n File Openning Error...";
			getch();
			MainMenu();
		}
		cout<<"\n\n Patient name For Delete : ";
		cin>>name;
		name[0]=toupper(name[0]);
		file2.open("patient1.txt",ios::app|ios::out);
		file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
		while(!file.eof())
		{
			if(strcmp(name,First_Name)==0)
			{
				cout<<"\n\n Record Deleted Successfully...";
				found++;
			}
			else
			{
				file2<<" "<<First_Name<<" "<<Last_Name<<" "<<Gender<<" "<<age<<" "<<Address<<" "<<Contact_no<<" "<<Email<<" "<<Problem<<" "<<Doctor<<"\n";;

			}
			file>>First_Name>>Last_Name>>Gender>>age>>Address>>Contact_no>>Email>>Problem>>Doctor;
		}
		if(found == 0)
		cout<<"\n\n Patient Can't Found...";
		else
		cout<<"\n\n\t\t\t Record Modify Successfully...";
		file.close();
		file2.close();
		remove("patient.txt");
		rename("patient1.txt","patient.txt");
	}
main()
{
	patient e;
	WelcomeScreen();//Use to call WelcomeScreen function
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function
    e.MainMenu();

}
