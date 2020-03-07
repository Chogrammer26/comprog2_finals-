#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream> //for IO of file
using namespace std;

// GLOBAL VARIABLES
string admin;
string pass;
int choice;

//FUNCTIONS
void menu();
void PlaceCursor(const int x, const int y); // in case we want to position every text
bool login(const string &username, const string &password);
void logo();

int main(){ // main function
	logo();
	system("pause");
	cout << "User Name: ";
	cin >> admin;
	cout << "Password: ";
	cin >> pass;
	bool loginpwe = login(admin,pass);
	if(loginpwe){
		cout << "WELCOME " << admin << endl;
		system("pause");
		system("cls");
		menu();
	} else {
		cout << "INVALID USER CREDENTIALS";
	}
}


bool login(const string &username, const string &password) {
    ifstream file("adminData.txt");
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















