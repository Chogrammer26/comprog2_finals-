#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime> // for time function
#include <cstdlib> // for srand
#include <fstream> //for IO of file
using namespace std;

// GLOBAL VARIABLES
string admin;
string pass;
int choice;
int c;
int numPassenger;

ofstream outfile("adminData.txt", std::ios_base::app);
ifstream file("adminData.txt");

class Data{
	public:
	string flyF;
	string flyT,depOn,retOn;
	string depTime,retTime;
	int adult,child,infant;
};


//FUNCTIONS
void outReceipt();
void menu();
void PlaceCursor(const int x, const int y); // in case we want to position every text
bool checklogin(const string &username, const string &password);
void logo();
void reg();
void makeReg();
string pickDate();
string pickTime();
void login();
string getRandomCode();


int main(){ // main function
	int c;
	logo();
	cout << "\t\t\t\t1 - LOG IN\n";
	cout << "\t\t\t\t2 - CREATE AN ACCOUNT\n\t\t\t\t>: ";
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
		cout << "\n\t\t\t\tWELCOME BACK " << admin << endl;
		cout << "\t\t\t\t." << system("pause");
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
	logo();
	cout << "\t\t\t\t1 - MAKE RESERVATION\n";
	cout << "\t\t\t\t2 - CANCEL RESERVATION\n";
	cout << "\t\t\t\t3 - SEARCH PASSENGER\n";
	cout << "\t\t\t\t4 - CHANGE RESERVATION\n";
	cout << "\t\t\t\t5 - PRINT RECEIPT\n";
	cout << "\t\t\t\t6 - QUIT\n\t\t\t\t>: ";
	cin >> choice;
	system ("cls");
	switch (choice) {
		case 1:
			makeReg();
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
	Data info;
void makeReg(){
	logo();
	cout << "\t\t\t\tSELECT:\n";
	cout << "\t\t\t\t1 - ROUND TRIP\n";
	cout << "\t\t\t\t2 - ONE WAY\n\t\t\t\t>: ";
	cin >> c;
	system ("cls");
	switch(c){
		case 1:
			logo();
			cout << "\t\t\t\tFLYING FROM: ";
			cin >> info.flyF;
			cout << "\t\t\t\tFLYING TO: ";
			cin >> info.flyT;
			system("cls");	
			logo();
			cout << "\n\t\t\t\tDEPARTING ON: ";
			info.depOn = pickDate();
			info.depTime = pickTime();
			system("cls");
			logo();
			cout << "\n\t\t\t\tRETURNING ON: ";
			info.retOn = pickDate();
			info.retTime = pickTime();
			system("cls");
			logo();
			cout << "\n\t\t\t\tPASENGERS: \n";
			cout << "\t\t\t\tADULT: ";
			cin >> info.adult;
			cout << "\t\t\t\tCHILD(2-11years): ";
			cin >> info.child;
			cout << "\t\t\t\tINFANT(under 2years): ";
			cin >> info.infant;
			numPassenger = info.child + info.adult + info.infant;
			outReceipt();
			break;
		case 2:
			logo();
			cout << "\t\t\t\tFLYING FROM: ";
			cin >> info.flyF;
			cout << "\t\t\t\tFLYING TO: ";
			cin >> info.flyT;
			system("cls");	
			logo();
			cout << "\n\t\t\t\tDEPARTING ON: ";
			pickDate();
			pickTime();
			system("cls");
			logo();
			cout << "\n\t\t\t\tPASENGERS: \n";
			cout << "\t\t\t\tADULT: ";
			cin >> info.adult;
			cout << "\t\t\t\tCHILD(2-11years): ";
			cin >> info.child;
			cout << "\t\t\t\tINFANT(under 2years): ";
			cin >> info.infant;
			numPassenger = info.child + info.adult + info.infant;
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
	cout << "\n\t\t\t\tLOG IN:\n\n";
	cout << "\t\t\t\tUser Name: ";
	cin >> admin;
	cout << "\t\t\t\tPassword: ";
	cin >> pass;
}

string getRandomCode(){
	string s;
	int i;
	char cmptchoice[5];
	srand(time(NULL));
    for (i=0; i<5; i++){
		cmptchoice [i] = (90 - (rand() % 26));
    }
    s = cmptchoice;
    return s;
}

string pickTime(){
	int a;
	cout << "\n\t\t\t\tPICK TIME: ";
	cout << "\n\n\t\t\t\t1 - 7am \n";
	cout << "\t\t\t\t2 - 9am \n";
	cout << "\t\t\t\t3 - 11am \n";
	cout << "\t\t\t\t4 - 2pm \n";
	cout << "\t\t\t\t5 - 5pm \n";
	cout << "\t\t\t\t6 - 8pm \n";
	cout << "\t\t\t\t>: ";
	cin >> a;
	switch(a){
		case 1:
			return "7am";
			break;
		case 2:
			return "9am";
			break;
		case 3:
			return "11am";
			break;
		case 4:
			return "2pm";
			break;
		case 5:
			return "5pm";
			break;
		case 6:
			return "8am";
			break;
		default:
			cout << "\t\t\t\tINVALID CHOICE!";
			break;
	}
}

string pickDate(){
	string a;
	cout << "\n\n\t\t\t\tPlease type the date on mm/dd/yyyy format: \n";
	cout << "\n\t\t\t\t>: ";
	cin >> a;
	return a;
}

void outReceipt(){
	ofstream outFile("flightUserData.txt", std::ios_base::app);
	ifstream file("flightUserData.txt", std::ios_base::app);
	outFile << "FLIGHT CODE: " << getRandomCode() << endl;
	outFile << "NAME: " << admin << endl;
	outFile << "FLYING FROM: " << info.flyF << "AIRPORT" << endl;
	outFile << "FLYING TO: " << info.flyT << "AIRPORT"  << endl;
	outFile << "DEPARTING ON: " << info.depOn << endl;
	outFile << "DEPARTING TIME: " << info.depTime << endl;
	if (c == 1){
		outFile << "RETURNING ON: " <<  info.retOn << endl;
		outFile << "RETURNING TIME: "<< info.retTime << endl;
		
	}
	outFile << "NUMBER OF ADULTS: " << info.adult << endl;
	outFile << "NUMBER OF CHILD(s): " << info.child << endl;
	outFile << "NUMBER OF INFANT(s): " << info.infant << endl;
	outFile << "NUMBER OF PASSENGER(s): " << numPassenger << endl;
	outFile.close();
}









