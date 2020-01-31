#include <iostream>
#include <string>

using namespace std;

int main(){
	long long key;
	string input;

	cin >> key;
	cin >> input;
	
	if(key > 26)
		key =key % 26;

	for (int i = 0; i < input.length(); i++) {
		input[i] = ((input[i] + key - 65)) % 26 + 65;
	}

	cout << input;

	return 0;
}
