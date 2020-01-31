#include <iostream>
#include <string>

using namespace std;

bool isFound(char matrix[5][5], char x) {
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (matrix[i][j] == x)
				return 1;
		}
	}
	return 0;
}


void findcoordinates(char letter, char matrix[5][5], int* x, int* y) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (matrix[i][j] == letter) {
				*x = j;
				*y = i;
				return;
			}
		}
	}
}


int main(){

	char key_matrix[5][5] = { '\0' };
	string alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
	string mess = "";

	string key_string;
	cin >> key_string;

	string message;
	cin >> message;

	//To replace I -> J in both the message and the key
	for (int i = 0; i < key_string.length(); i++)
	{
		if (key_string[i] == 'J')
			key_string[i] = 'I';
	}
	for (int i = 0; i < message.length(); i++)
	{
		if (message[i] == 'J')
			message[i] = 'I';
	}

	//Checking consecutive letters in message and adding 'X' if needed
	for (int i = 0; i < message.length(); i++){
		if (message[i] == message[i + 1] && message[i] == 'X') {			//If the two consecutive letters are XX
			mess += message[i];
			mess += 'Q';
		}
		else if (message[i] == message[i + 1]) {							//If the 2 letters are the same but not XX
			mess += message[i];
			mess += 'X';
		}
		else if (i + 1 >= message.length()) {
			mess += message[i];
			break;
		}
		else {																//If the 2 letters are not the same
			mess += message[i];
			mess += message[++i];
		}
	}
	if ((mess.size() % 2) != 0) {											//If the last pair has only 1 char, append 'X' 
		if(mess[mess.length()-1] == 'X')
			mess += 'Q';
		else
			mess += 'X';
	}

	
	//forming the key matrix
	int i = 0 ,j = 1, counter_key = 0, counter_alpha = 0;
	key_matrix[0][0] = key_string[counter_key];
	for (counter_key = 1; counter_key < key_string.length();counter_key++) {
		if (!(j < 5)) {
			j = 0;
			i++;
		}
		if (!(i < 5))
			break;
		if (isFound(key_matrix, key_string[counter_key]))
			continue;
		else
			key_matrix[i][j] += key_string[counter_key];
		j++;
	}
	for (counter_alpha = 0; counter_alpha < alpha.length(); counter_alpha++) {
		if (!(j < 5)) {
			j = 0;
			i++;
		}
		if (!(i < 5))
			break;
		if (isFound(key_matrix, alpha[counter_alpha]))
			continue;
		else
			key_matrix[i][j] += alpha[counter_alpha];
		j++;
	}

	
	//find element in the keymatrix and retun the parameters
	int x1, x2, y1, y2;
	string output = "";

	for (int i = 0; i < mess.length(); i++)
	{
		findcoordinates(mess[i], key_matrix, &x1, &y1);
		findcoordinates(mess[++i], key_matrix, &x2, &y2);
		
		//Same row
		if (y1 == y2) {
			x1 = (x1 + 1) % 5;
			x2 = (x2 + 1) % 5;
			output += key_matrix[y1][x1];
			output += key_matrix[y2][x2];
		}

		//Same Coloumn
		else if (x1 == x2) {
			y1 = (y1 + 1) % 5;
			y2 = (y2 + 1) % 5;
			output += key_matrix[y1][x1];
			output += key_matrix[y2][x2];
		}

		else {
			output += key_matrix[y1][x2];
			output += key_matrix[y2][x1];
		}
	}

	cout <<output;

	return 0;
}
