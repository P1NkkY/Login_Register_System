#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;

	cout << "Enter your username: ";
	cin >> username;
	cout << "Enter your password: ";
	cin >> password;

	ifstream read("D:\\C++_projects\\Login_Register_System\\data\\" + username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password)
		return true;
	else 
		return false;
}

int main()
{
	int choice;

	cout << "1: Register\n2: Login\n Your choise: ";
	cin >> choice;

	if (choice == 1) {
		string username, password;

		cout << "select a username: ";
		cin >> username;
		cout << "select a password: ";
		cin >> password;

		ofstream file;
		file.open("D:\\C++_projects\\Login_Register_System\\data\\" + username + ".txt");
		file << username << endl << password;
		file.close();

		main();
	}
	else if (choice == 2) {
		bool status = IsLoggedIn();

		if (!status) {
			cout << "False login!" << endl;
			system("PAUSE");
			return 0;
		}
		else {
			cout << "Succesfully logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
}
