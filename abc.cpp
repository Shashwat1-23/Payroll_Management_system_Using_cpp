#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<iomanip>
#include<ctype.h>
#define max 50
using namespace std;

int num=0;
void gotoXY(int,int);
void Cdelay(int);   
void border(int, int,int, int);
void borderNoDelay(int, int,int, int);
void loginFrame(int, int, int, int);
void intro();
void login();
void menu();
void insert();
void edit();
void editmenu();
void editnm(int);
void editcde(int);
void editdes(int);
void editexp(int);
void editage(int);
void editsalry(int);
void list();
void deletes();
void search();
void setWindowSize(int,int);
void saverecords();
void getrecords();
bool isFilePresent();
void displayPayslip();


class employee
{
public:
	char nm[20];
	int cde;
	char desig[20];
	int exp;
	int age;
	int salry;
	char Ifloan;
	
	int HRA;
	int PF;
	int tax;
	int FoodAllowance;
	int TravelAllowance;
	int HospitalAllowance;
	int LoanBal;
	int LoanDeb;
	int grosspay;
	int workHours;
	int DA;
	
};
employee emp[max],tempemp[max];


void getrecords()
{
	FILE *fp;
	fp = fopen("Records.txt","r");
	int c=0;
	if(fp!=NULL)
	{
		while(feof(fp)==0)
		{
			fscanf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",&emp[c].nm,&emp[c].cde,&emp[c].desig,&emp[c].exp,&emp[c].age,&emp[c].salry,&emp[c].Ifloan,&emp[c].HRA,&emp[c].PF,&emp[c].tax,&emp[c].FoodAllowance,&emp[c].TravelAllowance,&emp[c].HospitalAllowance,&emp[c].LoanBal,&emp[c].LoanDeb,&emp[c].grosspay,&emp[c].workHours,&emp[c].DA);
			c++;
		}
		num=c;
	}
	fclose(fp);
}

void saverecords()
{
	if(num==0)
	{
		system("del Records.txt");
	}
	else
	{
		FILE *fp;
		fp = fopen("Records.txt","w");
		for(int i=0;i<num;i++)
		{
			fprintf(fp,"%s\t%d\t%s\t%d\t%d\t%d\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",emp[i].nm,emp[i].cde,emp[i].desig,emp[i].exp,emp[i].age,emp[i].salry,emp[i].Ifloan,emp[i].HRA,emp[i].PF,emp[i].tax,emp[i].FoodAllowance,emp[i].TravelAllowance,emp[i].HospitalAllowance,emp[i].LoanBal,emp[i].LoanDeb,emp[i].grosspay,emp[i].workHours,emp[i].DA);
		}
		fclose(fp);
	}
}

void Cdelay(int msec)
{
    long goal = msec + (clock());
    while (goal > (clock()));
}

bool isFilePresent()
{
	FILE *fp;
	fp = fopen("Records.txt","r");
	if(fp==NULL)
		return false;
	else
		return true;
}
void loginFrame1(int xLenS = 18, int yLenS = 8, int xAxis = 55, int yAxis = 15)
{
	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);
	
	gotoXY(xLenS,yAxis);printf("%c",200);
	
    for(int i=xLenS+1;i<=xAxis-1;i++)         //Top and Bottom Border line
    {
        //Cdelay(0);
        gotoXY(i,yLenS);
        printf("%c",205);
		//puts(style);
        gotoXY(i,yAxis);
        //puts(style);
        printf("%c",205);

    }
    gotoXY(xAxis,yLenS);printf("%c",187);
    gotoXY(xAxis,yAxis);printf("%c",188);
    for(int i=yLenS+1;i<=yAxis-1;i++)         //Left and Right Border Line
    {
        //Cdelay(20);
        gotoXY(xLenS, i);
        printf("%c",186);
		//puts(style);
        gotoXY(xAxis, i);
        printf("%c",186);
		//puts(style);
    }
    printf("\n\n");
}
void login()
{
	
	char Usernm[30],Password[30],ch;int i=0;
	gotoXY(20,10);
    printf("Enter Usernm : ");
    
    cin>>Usernm;
    gotoXY(20,12);
    cout<<"Enter Password : ";
    while(1)
    {
    	ch = getch();
    	if(ch==13)
    		break;
    	if(ch==32||ch==9)
    		continue;
    	else
    	{
			cout<<"*";
			Password[i]=ch;
			i++;
    	}
	}
	Password[i] = '\0';
    if(strcmp(Usernm,"geu")==0 && strcmp(Password,"geu")==0)
    {
    	system("cls");
    	loginFrame1();
    	gotoXY(27,10);
    	cout<<"Login Success!!!";
    	gotoXY(21,12);
    	cout<<"Will be redirected in 3 Seconds...";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b2";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b1";
    		gotoXY(56,12);
    	Cdelay(1000);
	}
	else
	{
		system("cls");
    	loginFrame1();
    	gotoXY(27,10);
		printf("Access Denied!!!\a");
    	gotoXY(21,12);
    	cout<<"Will be redirected in 3 Seconds...";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b2";
    		gotoXY(56,12);
    	Cdelay(1000);
    	gotoXY(44,12);
    	cout<<"\b \b1";
    		gotoXY(56,12);
    	Cdelay(1000);
    	system("cls");
    	loginFrame1();
    	login();
	}
}
void setWindowSize(int width=670,int height=445)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoXY(int X, int Y)
{
    COORD coordinates;
    coordinates.X = X;
    coordinates.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void borderNoDelay(int xLenS = 2, int yLenS = 2,int xAxis = 76, int yAxis = 24 )
{
	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);
	
	gotoXY(xLenS,yAxis);printf("%c",200);
	
    for(int i=xLenS+1;i<=xAxis-1;i++)         //Top and Bottom Border line
    {
        gotoXY(i,yLenS);
        printf("%c",205);
        gotoXY(i,yAxis);
        printf("%c",205);
    }
    gotoXY(xAxis,yLenS);printf("%c",187);
    gotoXY(xAxis,yAxis);printf("%c",188);
    for(int i=yLenS+1;i<=yAxis-1;i++)         //Left and Right Border Line
    {
        gotoXY(xLenS, i);
        printf("%c",186);
        gotoXY(xAxis, i);
        printf("%c",186);
    }
    printf("\n\n");
}
void border(int xLenS = 2, int yLenS = 2,int xAxis = 76, int yAxis = 22 )
{
	system("cls");
	gotoXY(xLenS,yLenS);printf("%c",201);
	
	gotoXY(xLenS,yAxis);printf("%c",200);
	
    for(int i=xLenS+1;i<=xAxis-1;i++)         //Top and Bottom Border line
    {
        Cdelay(15);
        gotoXY(i,yLenS);
        printf("%c",205);
		//puts(style);
        gotoXY(i,yAxis);
        //puts(style);
        printf("%c",205);

    }
    gotoXY(xAxis,yLenS);printf("%c",187);
    gotoXY(xAxis,yAxis);printf("%c",188);
    for(int i=yLenS+1;i<=yAxis-1;i++)         //Left and Right Border Line
    {
        Cdelay(15);
        gotoXY(xLenS, i);
        printf("%c",186);
		//puts(style);
        gotoXY(xAxis, i);
        printf("%c",186);
		//puts(style);
    }
    printf("\n\n");
}
void loginFrame(int xLenS = 18, int yLenS = 8, int xAxis = 55, int yAxis = 15)
{
    border(xLenS,yLenS,xAxis,yAxis);
}
void insert()
{
	
	borderNoDelay();
	int i=num;
	int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal,LoanDeb,h,DA;
	char loan;
	num+=1; 
	gotoXY(28,4);
	printf("Insert New Record");
	gotoXY(10,6);
	cout<<"nm : ";
	//cin.getline(emp[i].nm,sizeof(emp[i].nm));
	cin>>emp[i].nm;
	gotoXY(10,8);
	cout<<"cde : ";
	cin>>emp[i].cde;
	gotoXY(10,10);
	cout<<"desig : ";
	cin>>emp[i].desig;
	gotoXY(10,12);
	cout<<"Years of Experience : ";
	cin>>emp[i].exp;
	gotoXY(10,14);
	cout<<"Age : ";
	cin>>emp[i].age;
	gotoXY(10,16);
	cout<<"Enter Working Hours : ";	
	cin>>h;
	sal = h*300;
	emp[i].workHours = h;
	do
	{
		gotoXY(10,18);
		cout<<"Any Loan (Y/N) ?: \b \b";
		loan=getche();
		if(loan=='Y'|| loan == 'y' || loan =='n' || loan == 'N')
			break;
	}while(1);
	if(loan=='y'|| loan=='Y')
	{
	gotoXY(10,20);
	cout<<"Enter Loan Balance : ";
	cin>>LoanBal;
	}
	else
	{
		LoanBal=0;
	}
	gotoXY(14,22);
	cout<<"Recorded Succesfully...!!!";
	
	TAX =  0.04 * sal;
	DA = 1.20 * sal;
	PF = 0.12 * sal;
	HRA = sal * 0.27;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[i].salry = sal;
	emp[i].DA = DA;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].FoodAllowance = MealA;
	emp[i].HospitalAllowance = MedicalA;
	emp[i].TravelAllowance = TransportA;
	emp[i].LoanBal = LoanBal-LoanDeb;
	emp[i].Ifloan = loan;
	emp[i].LoanDeb = LoanDeb;
	emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
	getch();
}

void intro()
{
	gotoXY(27,4); printf("PAYROLL MANAGEMENT SYSTEM using C++");
    gotoXY(25,5); for(int i=0;i<29;i++) printf("%c",196);
    gotoXY(20,8); printf("Designed and Programmed by:");
    gotoXY(20,9);for(int i=0;i<29;i++) printf("%c",196);
	gotoXY(20,11); printf("Shashwat Mishra");
	gotoXY(20,15); printf("https://www.linkedin.com/in/shashwat-mishra-2312b5200/");
    gotoXY(24,20);printf("Press Any key to continue...");
    getch();
    
}

void  list()
{
	//system("cls");
	borderNoDelay();
	gotoXY(20,4);
	printf("       ***// List of the Employees //***");
	gotoXY(6,6);
	cout<<"nm\tcde\tdesig\tYears(EXP)\tAge\tsalry "<<endl;
	gotoXY(6,7);
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i=0,j=8;i<=num-1;i++,j++)
	{
		gotoXY(6,j);
		cout<<emp[i].nm;
		gotoXY(19,j);
		cout<<emp[i].cde;
		gotoXY(26,j);
		cout<<emp[i].desig;
		gotoXY(47,j);
		cout<<emp[i].exp;
		gotoXY(58,j);
		cout<<emp[i].age;
		gotoXY(66,j);
		cout<<emp[i].grosspay;
	}
	getch();
}
/*
void loading()
{
	system("cls");
    gotoXY(55,20);
    printf("Loading...");
    gotoXY(50,22);
    for(int i = 0; i<20; i++)
    {
        Cdelay(200);
        printf("%c",254);
    }
}*/
void menu()
{
	//system("cls");
	borderNoDelay();
	//gotoXY(0,0);
	//cout<<"Number of Records Avaliable : "<<num;
	gotoXY(16,4);
	printf("**  Payroll Management System Using C++ ** ");
	gotoXY(12,6);
	cout<<"Press  i ----> Insert New Record.";
	gotoXY(12,8);
	cout<<"Press  e ----> Edit a Record.";
	gotoXY(12,10);
	cout<<"Press  d ----> Delete a Record.";
	gotoXY(12,12);
	cout<<"Press  s ----> Search a Record.";
	gotoXY(12,14);
	cout<<"Press  l ----> List The Employee Table.";
	gotoXY(12,16);
	cout<<"Press  p ----> Print Employee PaySlip.";
	gotoXY(12,18);
	cout<<"Press  q ----> Quit Program.";
	gotoXY(16,22);
	cout<<"Select Your Choice ====> ";
}

void deletes()
{
	for(int i=0;i<num;i++)
	{
		tempemp[i]=emp[i];
	}
	//system("cls");
	borderNoDelay();
	int cde;
	int check=-1;
	gotoXY(28,4);
	printf("Delete a Record");
	gotoXY(10,6);
	cout<<"Enter the Jobcde To Delete That Record  :";
	cin>>cde;
	int i,j;
	for(i=0;i<=num-1;i++)
	{
	 	if(emp[i].cde==cde)
		{
			check=i;
		}
	}
	if(check!=-1)
	{
		for(i=0,j=0;i<=num-1;i++,j++)
		{
			if(i==check)
			{
				i++;
			}
			emp[j]=tempemp[i];
		}
		num--;
	}
}

void search()
{
	//system("cls");
	borderNoDelay();
	int jobcde;
	bool found = false;
	gotoXY(10,4);
	cout<<"You can Search only through the Jobcde of an Employee";
	gotoXY(10,6);
	cout<<"Enter cde Of the Employee : ";
	cin>>jobcde;
	for(int i=0;i<=num-1;i++)
	{
		if(emp[i].cde==jobcde)
		{
			gotoXY(6,8);
			cout<<"nm\tcde\tdesig\tYears(EXP)\tAge\tsalry "<<endl;
			gotoXY(6,9);
			cout<<"------------------------------------------------------------------"<<endl;
			gotoXY(6,11);
			cout<<emp[i].nm;
			gotoXY(19,11);
			cout<<emp[i].cde;
			gotoXY(26,11);
			cout<<emp[i].desig;
			gotoXY(47,11);
			cout<<emp[i].exp;
			gotoXY(58,11);
			cout<<emp[i].age;
			gotoXY(66,11);
			cout<<emp[i].grosspay;
			found = true;
		}
		//else
		//
	}
	if(!found)
	{
		gotoXY(26,11);
		cout<<"No records Found...!!!\a";
	}
	getch();
}



void editmenu()
{
	//system("cls");
	borderNoDelay();
	gotoXY(28,4);
	printf("Edit An Entry");
	gotoXY(10,6);
	cout<<"What Do You Want To edit";
	gotoXY(12,8);
	cout<<"n ---------> nm ";
	gotoXY(12,9);
	cout<<"c ---------> cde ";
	gotoXY(12,10);
	cout<<"d ---------> desig";
	gotoXY(12,11);
	cout<<"e ---------> Experience ";
	gotoXY(12,12);
	cout<<"a ---------> Age";
	gotoXY(12,13);
	cout<<"s ---------> salry";
	gotoXY(12,14);
	cout<<"q ---------> QUIT";
	gotoXY(10,16);
	cout<<"Enter Choice ---->>>  ";
}

void editnm(int i)
{
	gotoXY(10,18);
	cout<<"Enter New nm----->  ";
	cin>>emp[i].nm;
}

void editcde(int i)
{
	gotoXY(10,18);
	cout<<"Enter New Job cde----->  ";
	cin>>emp[i].cde;
}
void editdes(int i)
{
	gotoXY(10,18);
	cout<<"enter new desig----->  ";
	cin>>emp[i].desig;
}

void editexp(int i)
{
	gotoXY(10,18);
	cout<<"Enter new Years of Experience";
	cin>>emp[i].exp;
}
void editage(int i)
{
	gotoXY(10,18);
	cout<<"Enter new Age ";
	cin>>emp[i].age;
}

void editsalry(int i)
{
	int sal,PF,TAX,HRA,MealA,MedicalA,TransportA,LoanBal=emp[i].LoanBal,LoanDeb,DA;
	char loan;
	gotoXY(10,18);
	cout<<"Enter new salry ";
	cin>>sal;
	DA = 1.20 * sal;	
	TAX =  0.04 * sal;
	PF = 0.12 * sal;
	HRA = 4000;
	MealA = 300;
	MedicalA = 300;
	TransportA = 300;
	LoanDeb = sal * 0.09;
	if(LoanDeb > LoanBal)
	{
		LoanBal = 0;
		LoanDeb = LoanBal;
	}
	emp[i].salry = sal;
	emp[i].tax=TAX;
	emp[i].PF = PF;
	emp[i].HRA = HRA;
	emp[i].FoodAllowance = MealA;
	emp[i].HospitalAllowance = MedicalA;
	emp[i].TravelAllowance = TransportA;
	emp[i].LoanBal = LoanBal;
	emp[i].Ifloan = loan;
	emp[i].LoanDeb = LoanDeb;
	emp[i].grosspay = (sal+MealA+MedicalA+TransportA+HRA+DA)-(PF+TAX+LoanDeb) ;
}

void edit()
{
	//system("cls");
	borderNoDelay();
	int jobcde;
	gotoXY(28,4);
	printf("Edit a Record");
	int i;
	char Choice;
	gotoXY(10,6);
	cout<<"Enter the jobcde To Edit : ";
	cin>>jobcde;
	editmenu();
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].cde==jobcde)
		{
			while((Choice=cin.get())!='q')
			{
				switch(Choice)
				{
					case 'n':
						editnm(i);
						break;
					case 'c':
						editcde(i);
						break;
					case 'd':
						editdes(i);
						break;
					case 'e':
						editexp(i);
						break;
					case 'a':
						editage(i);
						break;
					case 's':
						editsalry(i);
						break;
				}
   				editmenu();
			}
		}
	}
}


void displayPayslip()
{
	system("cls");
	borderNoDelay();
	gotoXY(10,4);
	int cde,i;
	cout<<"Enter Employee Job cde :";
	cin>>cde;
	for(i=0;i<=num-1;i++)
	{
		if(emp[i].cde==cde)
		{
			gotoXY(12,6);
			cout<<"nm : "<<emp[i].nm;
			gotoXY(45,6);
			cout<<"Working Hours : "<<emp[i].workHours<<" Hrs";
			gotoXY(6,8);
			cout<<"Earnings :-";
			gotoXY(8,10);
			cout<<"Basic Pay : "<<emp[i].salry<<endl;
			gotoXY(8,12);
			cout<<"HRA(27% of Basic): "<<emp[i].HRA<<endl;
			gotoXY(8,14);
			cout<<"DA (120% of Basic):"<<emp[i].DA;
			gotoXY(8,16);
			cout<<"Meal Allowance : "<<emp[i].FoodAllowance<<endl;
			gotoXY(8,18);
			cout<<"Medical Alowance : "<<emp[i].HospitalAllowance<<endl;
			gotoXY(8,20);
			cout<<"Transport Allowance : "<<emp[i].TravelAllowance<<endl;
			gotoXY(40,8);
			cout<<"Deductions :- "<<endl<<endl;
			gotoXY(42,10);
			cout<<"PF : "<<emp[i].PF<<endl;
			gotoXY(42,12);
			cout<<"Tax : "<<emp[i].tax<<endl;
			gotoXY(42,14);
			int l = emp[i].Ifloan;
			char l2 = toupper(l);
			cout<<"Loan Status : "<<l2<<endl;
			gotoXY(42,16);
			cout<<"Loan Debit This Month : "<<emp[i].LoanDeb<<endl;
			gotoXY(42,18);
			cout<<"Loan Balance : "<<emp[i].LoanBal<<endl;
			gotoXY(32,22);
			cout<<"Total Gross Pay : "<<emp[i].grosspay;
		}
	}
	getch();
}





int main()
{
	setWindowSize();	
	border();
	intro();
	//loading();    
	loginFrame();
    login();
    menu();
    getrecords();
    char Choice;
    if(emp[0].cde==0 && isFilePresent())
    	num--;
	while(1)
	{
		Choice=getch();
		switch(Choice)
		{
			case 'l':
				list();
				break;
			case 'i':
				insert();
				break;
			case 'd':
				deletes();
				break;
			case 'e':
				edit();
				break;
			case 's':
				search();
				break;
			case 'p':
				displayPayslip();
				break;
			case 'q':
				saverecords();
				exit(0);
		}
		menu();
	}
	
	
	return 0;
}