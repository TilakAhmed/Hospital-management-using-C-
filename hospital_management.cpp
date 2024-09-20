#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include <Windows.h>
#include <iomanip>
using namespace std;

void welcomeScreen();
void title();
void loginScreen();
void Add_rec();
void patient_list();
void Search_rec();
void Edit_rec();
void Dlt_rec();
void mainMenu();

class patient
{
public:
	string age, Contact_no, Email, Address, Doctor, Problem, Gender;
	char First_Name[20], Last_Name[20];
	patient()
	{
		cin.ignore();
		cout << "Enter Patient's First Name : ";
		cin >> First_Name;
		cout << "Enter Patient's Last Name : ";
		cin >> Last_Name;
		fflush(stdin);
		cout << "Enter Patient's Gender : ";
		getline(cin, Gender);
		cout << "Enter Patient's Age : ";
		getline(cin, age);
		cout << "Enter Patient's Problem : ";
		getline(cin, Problem);
		cout << "Enter Patient's Address : ";
		getline(cin, Address);
		cout << "Enter Patient's Contact No : ";
		getline(cin, Contact_no);
		cout << "Enter Patient's Email Address : ";
		getline(cin, Email);
		cout << "Prescribed Doctor : ";
		getline(cin, Doctor);
	}
};

int main()
{
	welcomeScreen();
	title();
	loginScreen();
	getch();
}

void welcomeScreen()
{
	cout << "\n\n\n\n\n\n\n\t\t\t\t#########################################";
	cout << "\n\t\t\t\t#\t\t WELCOME TO\t\t#";
	cout << "\n\t\t\t\t#   RAJSHAHI MEDICAL MANAGEMENT SYSTEM  #";
	cout << "\n\t\t\t\t#########################################";
	cout << "\n\n\n\n\n Press any key to continue......\n";
	getch();
	system("cls");
}

void title()
{
	cout << "\n\n\t\t----------------------------------------------------------------------------------";
	cout << "\n\t\t\t\t       		RAJSHAHI MEDICAL         ";
	cout << "\n\t\t----------------------------------------------------------------------------------\n";
}

void loginScreen()
{
    char Username[15];
    char Password[15];
    char original_Username[25] = "tilak";
    char original_Password[15] = "1234";
    int i;
    for (i = 0; i < 5; i++)
    {
        system("cls");
        cout << "\n\n\n\n\t\t\t\tEnter your Username and Password :)";
        cout << "\n\n\n\t\t\t\t\tUSERNAME : ";
        cin >> Username;

        cout << "\n\n\t\t\t\t\tPASSWORD : ";

        // Hide password input by showing '*' for each character
        char ch;
        int index = 0;
        while (true)
        {
            ch = _getch();  // Get a character without displaying it

            if (ch == 13)  // Enter key (ASCII 13)
            {
                Password[index] = '\0';  // Null-terminate the password string
                break;
            }
            else if (ch == 8 && index > 0)  // Handle backspace
            {
                cout << "\b \b";  // Remove the last '*'
                index--;
            }
            else if (ch != 8 && index < 14)  // Normal characters (excluding backspace)
            {
                Password[index] = ch;
                cout << '*';  // Display '*' for each character typed
                index++;
            }
        }

        // Check if the entered username and password match
        if (strcmp(Username, original_Username) == 0 && strcmp(Password, original_Password) == 0)
        {
            cout << "\n\n\n\t\t\t\t\tPassword Matched!!!...\nLogging In";
            for (i = 0; i <= 6; i++)
            {
                Sleep(100);
                cout << ".";
            }
            mainMenu();
            break;
        }
        else
        {
            cout << "\n\t\t\tPassword is incorrect...\nPlease Try Again...";
            getch();
        }

        if (i == 4)
        {
            cout << "\nYou have crossed the limit....\nYour Login is blocked....";
            getch();
            exit(1);
        }
    }
}

void mainMenu()
{
	system("cls");
	int choice;
	title();
	cout << "\n\n\n\n\n\t\t\t\t1. Add Patients Record\n";
	cout << "\n\t\t\t\t2. List Patients Record\n";
	cout << "\n\t\t\t\t3. Search Patients Record\n";
	cout << "\n\t\t\t\t4. Edit Patients Record\n";
	cout << "\n\t\t\t\t5. Delete Patients Record\n";
	cout << "\n\t\t\t\t6. Exit\n";
	cout << "\n\n\n \n\t\t\t\tChoose from 1 to 6:";
	cin >> choice;
	switch (choice)
	{
	case 1:
		Add_rec();
		break;
	case 2:
		patient_list();
		break;
	case 3:
		Search_rec();
		break;
	case 4:
		Edit_rec();
		break;
	case 5:
		Dlt_rec();
		break;
	case 6:
		cout << "\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING..." << endl;
		break;
	default:
		cout << "\n\t\t\tInvalid entry....\nPlease enter right option...";
		getch();
	}
}

void Add_rec()
{
	system("cls");
	title();
	ofstream out("addRecord.txt", ios::out | ios::app);
	if (!out)
		cout << "Can't open file...." << endl;
	else
	{
		cout << "\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n";
		patient p;
		out << setw(10) << p.First_Name << setw(15) << p.Last_Name << setw(15) << p.age << setw(15) << p.Problem;
		out << setw(15) << p.Address << setw(15) << p.Contact_no << setw(25) << p.Email << setw(20) << p.Doctor << setw(15) << p.Gender << endl;
		cout << "\n\n\t\t\t.... Information Record Successful ...";
		out.close();
	more:
		system("cls");
		printf("\n\n\t\t\tDo you want to add more[Y/N]?? : ");
		char ans;
		cin >> ans;
		if (toupper(ans) == 'Y')
		{
			Add_rec();
		}
		else if (toupper(ans) == 'N')
		{
			printf("\n\t\t Thank you.....");
			system("cls");
			mainMenu();
		}
		else
		{
			printf("\n\t\tInvalid Input\n");
			goto more;
		}
	}
}

void patient_list()
{
	system("cls");
	title();
	ifstream in("addRecord.txt");
	if (!in)
		cout << "Can't open file...." << endl;
	else
	{
		cout << endl
			 << setw(10) << "First Name" << setw(15) << "Last Name" << setw(15) << "Age" << setw(15) << "Problem" << setw(15) << "Address";
		cout << setw(15) << "Contact No" << setw(25) << "Email" << setw(20) << "Prescribe Doctor" << setw(15) << "Gender" << endl;
		string line;
		while (getline(in, line))
		{
			cout << line << endl;
		}
		in.close();
		getch();
		mainMenu();
	}
}

void Search_rec()
{
	char name1[20], name2[20];
	char First_Name[20], Last_Name[20], Gender[10], age[2], Contact_no[20], Email[20], Address[20], Doctor[20], Problem[20];
	system("cls");
	title();
	FILE *ek;
	ek = fopen("addRecord.txt", "r");
	if (ek == NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		mainMenu();
	}
	cout << "\n\n\t\t\t!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!!\n";
	cout << "\n Enter Patient's first Name to be viewed : ";
	cin >> name1;
	cout << "\n Enter Patient's last Name to be viewed : ";
	cin >> name2;
	fflush(stdin);
	while (fscanf(ek, "%s %s %s %s %s %s %s %s %s", First_Name, Last_Name, age, Problem, Address, Contact_no, Email, Doctor, Gender) != EOF)
	{
		if (strcmp(First_Name, name1) == 0 && strcmp(Last_Name, name2) == 0)
		{
			cout << endl << "Name : " << First_Name << " " << Last_Name << endl;
			cout << "Gender : " << Gender << endl;
			cout << "Age : " << age << endl;
			cout << "Problem : " << Problem << endl;
			cout << "Address : " << Address << endl;
			cout << "Contact No : " << Contact_no << endl;
			cout << "Email : " << Email << endl;
			cout << "Doctor : " << Doctor << endl;
			break;
		}
	}
	fclose(ek);
searchMore:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
	char ans;
	scanf("%c", &ans);
	if (toupper(ans) == 'Y')
	{
		Search_rec();
	}
	else if (toupper(ans) == 'N')
	{
		printf("\n\t\t Thank you :) :)");
		getch();
		mainMenu();
	}
	else
	{
		printf("\n\tInvalid Input.\n");
		goto searchMore;
	}
}

void Edit_rec()
{
	int valid = 0;
	char name1[20], name2[20];
	char First_Name[20], Last_Name[20], Gender[10], age[2], Contact_no[20], Email[20], Address[20], Doctor[20], Problem[20];
	system("cls");
	title();
	FILE *ek;
	ek = fopen("addRecord.txt", "r");
	ofstream out("addRecord2.txt", ios::out | ios::app);
	if (ek == NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		mainMenu();
	}
	if (!out)
	{
		printf("\n Can not open file");
		getch();
		mainMenu();
	}
	cout << "\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n";
	cout << "\n Enter the First Name of the Patient : ";
	cin >> name1;
	cout << "\n Enter the Last Name of the Patient : ";
	cin >> name2;
	fflush(stdin);
	while (fscanf(ek, "%s %s %s %s %s %s %s %s %s", First_Name, Last_Name, age, Problem, Address, Contact_no, Email, Doctor, Gender) != EOF)
	{
		if (strcmp(First_Name, name1) == 0 && strcmp(Last_Name, name2) == 0)
		{
			valid = 1;
			cout << "*** Existing Record ***" << endl;
			cout << endl << "1. Name : " << First_Name << " " << Last_Name << endl;
			cout << "2. Gender : " << Gender << endl;
			cout << "3. Age : " << age << endl;
			cout << "4. Problem : " << Problem << endl;
			cout << "5. Address : " << Address << endl;
			cout << "6. Contact No : " << Contact_no << endl;
			cout << "7. Email : " << Email << endl;
			cout << "8. Doctor : " << Doctor << endl;
			int choice;
		editMore:
			cout << "Enter What You Want To Change : ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter The New name : \n";
				cout << "First Name : ";
				cin >> First_Name;
				cout << "Last Name : ";
				cin >> Last_Name;
				break;
			case 2:
				cout << "Enter The New Gender : ";
				cin >> Gender;
				break;
			case 3:
				cout << "Enter The New Age : ";
				cin >> age;
				break;
			case 4:
				cout << "Enter The New Problem : ";
				cin >> Problem;
				break;
			case 5:
				cout << "Enter The New Address : ";
				cin >> Address;
				break;
			case 6:
				cout << "Enetr The New Contact Number : ";
				cin >> Contact_no;
				break;
			case 7:
				cout << "Enter The New Mail Address : ";
				cin >> Email;
				break;
			case 8:
				cout << "Enter The New Appointed Doctor : ";
				cin >> Doctor;
				break;
			default:
				cout << "Invalid Choice....\n";
				break;
			}
			char edit;
			cout << "Wnat To Edit More[Y/N] : ";
			cin >> edit;
			if (edit == 'y' || edit == 'Y')
			{
				goto editMore;
			}
			else
			{
				char ch;
				cout << "\nPress U charecter for the Updating operation : ";
				cin >> ch;
				if (ch == 'u' || ch == 'U')
				{
					out << setw(10) << First_Name << setw(15) << Last_Name << setw(15) << age << setw(15) << Problem;
					out << setw(15) << Address << setw(15) << Contact_no << setw(25) << Email << setw(20) << Doctor << setw(15) << Gender << endl;
					cout << "\n\n\t\t\tPatient record updated successfully...\n";
				}
			}
		}
		else
		{
			out << setw(10) << First_Name << setw(15) << Last_Name << setw(15) << age << setw(15) << Problem;
			out << setw(15) << Address << setw(15) << Contact_no << setw(25) << Email << setw(20) << Doctor << setw(15) << Gender << endl;
		}
	}
	if (valid == 0)
	{
		printf("\n\t\tNO RECORD FOUND...");
	}
	out.close();
	fclose(ek);
	remove("addRecord.txt");
	rename("addRecord2.txt", "addRecord.txt");
	getch();
	mainMenu();
}

void Dlt_rec()
{
	char name1[20], name2[20];
	char First_Name[20], Last_Name[20], Gender[10], age[2], Contact_no[20], Email[20], Address[20], Doctor[20], Problem[20];
    int found=0;
    system("cls");
    title();
    FILE *ek;
	ek = fopen("addRecord.txt", "r");
	ofstream out("addRecord2.txt", ios::out | ios::app);
	if (ek == NULL)
	{
		printf("\n\t Can not open file!! ");
		getch();
		mainMenu();
	}
	if (!out)
	{
		printf("\n Can not open file");
		getch();
	}
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n\n");
    cout << "\n Enter the First Name of the Patient : ";
	cin >> name1;
	cout << "\n Enter the Last Name of the Patient : ";
	cin >> name2;
	fflush(stdin);
    while (fscanf(ek, "%s %s %s %s %s %s %s %s %s", First_Name, Last_Name, age, Problem, Address, Contact_no, Email, Doctor, Gender) != EOF)
    {
        if (strcmp(First_Name, name1) != 0 && strcmp(Last_Name, name2) != 0)
		{
			out << setw(10) << First_Name << setw(15) << Last_Name << setw(15) << age << setw(15) << Problem;
			out << setw(15) << Address << setw(15) << Contact_no << setw(25) << Email << setw(20) << Doctor << setw(15) << Gender << endl;
		}
        else
        {
			cout << endl << "Name : " << First_Name << " " << Last_Name << endl;
			cout << "Gender : " << Gender << endl;
			cout << "Age : " << age << endl;
			cout << "Problem : " << Problem << endl;
			cout << "Address : " << Address << endl;
			cout << "Contact No : " << Contact_no << endl;
			cout << "Email : " << Email << endl;
			cout << "Doctor : " << Doctor << endl;
            found=1;
        }
    }
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        mainMenu();
    }
    else
    {
        out.close();
		fclose(ek);
		remove("addRecord.txt");
		rename("addRecord2.txt", "addRecord.txt");
        printf("\n\n\t\t\t Record deleted successfully :) ");
        getch();
        mainMenu();
    }
}

