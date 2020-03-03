#include <iostream>
#include <conio.h>
#include <fstream> //for IO of file
using namespace std;
string admin;
string pass;


bool login(const string &username, const string &password);

int main(){ // main function
	
	cout << "User Name: ";
	cin >> admin;
	cout << "Password: ";
	cin >> pass;
	bool loginpwe = login(admin,pass);
	if(loginpwe){
		cout << "WELCOME " << admin;
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


