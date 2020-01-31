#include <iostream>
#include <string>
using namespace std;

int isFoundat(int x,int arr[],int arrlength) {
	for (int i = 0; i < arrlength; i++)
	{
		if (x == arr[i])
			return i + 1;
	}
	return -1;
}

int main() {

	int in_size, out_size;
	cin >> in_size >> out_size;

	int* pbox;
	pbox = new int[out_size];

	for (int i = 0; i < out_size; i++){
		cin >> pbox[i];
	}
	string answer = "";

	int curser = 1;
	int num;
	for (int i = 0; i < in_size; i++)
	{
		num = isFoundat(curser, pbox, out_size);
		if (num == -1) {
			cout << "IMPOSSIBLE";
			return 0;
		}
		else
			answer += to_string(num);
		answer += " ";
		curser++;
	}
	cout << answer.substr(0, answer.length()-1);
	delete[] pbox;
	return 0;
}
