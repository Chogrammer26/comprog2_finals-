#include <iostream>
#include <conio.h>
#include <windows.h>
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
void login();

int main(){ // main function
	int c;
	logo();
	cout << "				1 - LOG IN\n";
	cout << "				2 - CREATE AN ACCOUNT\n				CHOICE: ";
	cin >> c;
	switch (c){
		case 1:
			login();
			break;
		case 2:
			reg();
			cout << "				Your account has been made!\n";
			system("pause");
			system("cls");
			logo();
			login();
			break;
		default:
			cout << "INVALID CHOICE!";
			break;
	}

	bool loginpwe = checklogin(admin,pass);
	if(loginpwe){
		cout << "\n				WELCOME " << admin << endl;
		system("pause");
		system("cls");
		menu();
	} else {
		cout << "\n				INVALID USER CREDENTIALS";
	}
}


bool checklogin(const string &username, const string &password) {
    std::string fusername, fpassword;
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
			cout << "What is the Flight's City of Origin? : \n";
			cout << "What is the Flight's City of Destination : \n";
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
	cout << "				Create a User Name: ";
	cin >> nUser;
	cout << "				Create a Password: ";
	cin >> nPass;
	outfile << nUser << ";" <<nPass << endl;
	outfile.close();
}

void login() {
	cout << "				LOG IN:\n\n";
	cout << "				User Name: ";
	cin >> admin;
	cout << "				Password: ";
	cin >> pass;
}















