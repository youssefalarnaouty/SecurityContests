#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main(){

	string key_string;
	cin >> key_string;

	string message;
	cin >> message;

	int index = 0;
	char temp;
	string vigenere = "";
	string vernam = "";
	bool onepad = 1;

	while (key_string.length() != message.length()){
		onepad = 0;
		key_string += key_string[index];
		index++;
		if (index > key_string.length())
			index = 0;
	}

	for (int i = 0; i < message.length(); i++){
		temp= (message[i] - 65 + key_string[i] - 65)%26;
		vigenere += temp + 65 ;
	}
	
	

	cout <<"Vigenere: " << vigenere << endl;
	cout << "Vernam: ";
	int tempp;
	for (int i = 0; i < message.length(); i++) {
		tempp = (message[i]) ^ (key_string[i]);
		cout << hex << uppercase<< setfill('0') << setw(2) << tempp;
	}
	cout << endl;
	cout <<"One-Time Pad: ";
	if (onepad)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
