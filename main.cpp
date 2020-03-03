#include <iostream>
#include <conio.h>
#include <fstream> //for IO of file
using namespace std;
string admin;
string pass;
bool login = false;


void adminLogin();

int main(){ // main function
	
	adminLogin();
	if (login){
		cout << "WELCOME ADMIN " << admin;
	}

}


void adminLogin(){ //admin log-in system
	cout << "User Name: ";
	cin >> admin;
	cout << "Password: ";
	cin >> pass;
	
	string userPass = admin + " " + pass; //this line will be searched
	int offset;
	string line;
	ifstream adminData;
	adminData.open("adminData.txt");
	
	if(adminData.is_open()){
		while (!adminData.eof()){
			getline(adminData,line);
			if ((offset = line.find(pass, 0)) != string::npos) // if log in data is found 
			{
				login = 1;
			}\
			else // if log in data !found 
			{
				cout << "\n INCORRECT ADMIN CREDENTIALS.";
			}
		}
		
		adminData.close();
	}
	else
		cout << "ERROR: Unable to open admin database!. ";
	
	
}


