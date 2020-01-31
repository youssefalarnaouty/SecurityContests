#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){

	int out_size;
	cin >> out_size;

	int rows = out_size / 4;
	int table[64][4] = { 0 };
	int entry;

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < 4; j++)
		{
			cin >> entry;
			table[i][j] = entry;
		}
	}

	int in_size;
	cin >> in_size;

	string hex_input;
	cin >> hex_input;

	int input = stoi(hex_input, 0, 16);
	
	string value;
	string output ="";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 4; j++)
		{
			value = to_string(1 & (input >>(in_size - table[i][j])));
			output += value;
		}
	}
	
	
	int print = stoi(output, 0, 2);
	cout << hex << uppercase << setfill('0') << setw(2) << print;
	
	return 0;
}
