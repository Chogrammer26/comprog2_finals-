#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime> // for time function
#include <cstdlib> // for srand
#include <fstream> //for IO of file
using namespace std;

// GLOBAL VARIABLES
string admin;
string pass;
int choice;
ofstream outfile("adminData.txt", std::ios_base::app);
ifstream file("adminData.txt");

//FUNCTIONS
void menu();
void PlaceCursor(const int x, const int y); // in case we want to position every text
bool checklogin(const string &username, const string &password);
void logo();
void reg();
void makeReg();
void pickTime();
void login();
void getRandomCode();

int main(){ // main function
	int c;
	logo();
	cout << "\t\t\t\t1 - LOG IN\n";
	cout << "\t\t\t\t2 - CREATE AN ACCOUNT\n\t\t\t\tCHOICE: ";
	cin >> c;
	switch (c){
		case 1:
			login();
			break;
		case 2:
			reg();
			cout << "\t\t\t\tYOUR ACCOUNT HASE BEEN MADE!!\n";
			cout << "\t\t\t\t" << system("pause");
			system("cls");
			logo();
			login();
			break;
		default:
			cout << "INVALID CHOICE!";
			break;
	}

	bool logincheck = checklogin(admin,pass);
	if(logincheck){
		cout << "\n\t\t\t\tWELCOME " << admin << endl;
		cout << "\t\t\t\t" << system("pause");
		system("cls");
		menu();
	} else {
		cout << "\n\t\t\t\tINVALID USER CREDENTIALS";
	}
}


bool checklogin(const string &username, const string &password) {
    string fusername, fpassword;
    while (file) {
        getline(file, fusername, ';'); 
        getline(file, fpassword); 
 
        if (fusername == username && fpassword == password)
            return true;
    }
    return false;
}

void menu(){
	cout << "1. MAKE RESERVATION\n";
	cout << "2. CANCEL RESERVATION\n";
	cout << "3. SEARCH PASSENGER\n";
	cout << "4. CHANGE RESERVATION\n";
	cout << "5. PRINT RECEIPT\n";
	cout << "QUIT\n";
	cin >> choice;
	switch (choice) {
		case 1:
			break;
	}
	
}



void PlaceCursor(const int x, const int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;
    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
}

void makeReg(){
	int c;
	cout << "SELECT:\n";
	cout << "1 - ROUND TRIP\n";
	cout << "2 - ONE WAY\n";
	switch(c){
		case 1:
			cout << "\t\t\t\tFLYING FROM: ";
			cout << "\t\t\t\tFLYING TO: ";
			cout << "\t\t\t\tDEPARTING ON: ";
			cout << "\t\t\t\tRETURNING ON: ;
			cout << "\t\t\t\tADULT: ;
			cout << "\t\t\t\tCHILD(2-11years): ";
			cout << "\t\t\t\tINFANT(under 2years): ";
			break;
		case 2:
			cout << "\t\t\t\tFLYING FROM: ";
			cout << "\t\t\t\tFLYING TO: ";
			cout << "\t\t\t\tDEPARTING ON: ";
			cout << "\t\t\t\tADULT: ;
			cout << "\t\t\t\tCHILD(2-11years): ";
			cout << "\t\t\t\tINFANT(under 2years): ";
			break;
		default:
			break;
	}
	

}




void logo() {
	cout << "______  ___             ______             ____________                                        \n";
	cout << "___   |/  /___  ___________  /_________    ___    |__(_)_________      _______ _____  _________\n";
	cout << "__  /|_/ /_  / / /_  ___/_  //_/_  ___/    __  /| |_  /__  ___/_ | /| / /  __ `/_  / / /_  ___/\n";
	cout << "_  /  / / / /_/ /_(__  )_  ,<  _(__  )     _  ___ |  / _  /   __ |/ |/ // /_/ /_  /_/ /_(__  )\n";
	cout << "/_/  /_/  \\__,_/ /____/ /_/|_| /____/      /_/  |_/_/  /_/    ____/|__/ \\__,_/ _\\__, / /____/\n";
	cout << "                                                                               /____/        \n";
}

void reg(){
	string nUser;
	string nPass;
	cout << "\t\t\t\tCreate a User Name: ";
	cin >> nUser;
	cout << "\t\t\t\tCreate a Password: ";
	cin >> nPass;
	outfile << nUser << ";" <<nPass << endl;
	outfile.close();
}

void login() {
	cout << "\t\t\t\tLOG IN:\n\n";
	cout << "\t\t\t\tUser Name: ";
	cin >> admin;
	cout << "\t\t\t\tPassword: ";
	cin >> pass;
}

void getRandomCode(){
	int i;
	char cmptchoice[5];
	srand(time(NULL));
    for (i=0; i<5; i++){
		cmptchoice [i] = (90 - (rand() % 26));
    }
    cout << cmptchoice;
}

void pickTime(){
	cout << "\t\t\t\t1 - 7am \n";
	cout << "\t\t\t\t2 - 9am \n";
	cout << "\t\t\t\t3 - 11am \n";
	cout << "\t\t\t\t4 - 2pm \n";
	cout << "\t\t\t\t5 - 5pm \n";
	cout << "\t\t\t\t6 - 8pm \n";
}









