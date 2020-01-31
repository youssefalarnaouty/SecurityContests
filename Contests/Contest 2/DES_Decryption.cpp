#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

unsigned long long int permutation(int out_size, int table[], int in_size, unsigned long long int input) {
	string value;
	string output1 = "";
	for (int i = 0; i < out_size; i++) {
		value = to_string(1 & (input >> (in_size - table[i])));
		output1 += value;
	}

	unsigned long long int print = stoull(output1, 0, 2);
	return print;
}

void inv_permutation(int out_size, int table[], int output[]) {
	int counter = 1;
	for (int i = 0; i < out_size; i++) {
		output[table[i] - 1] = counter;
		counter++;
	}
	return;
}

string sbox(int s1[4][16], int s2[4][16], int s3[4][16], int s4[4][16], int s5[4][16], int s6[4][16], int s7[4][16], int s8[4][16], unsigned long long keyword) {
	string output = "";
	int row;
	stringstream ss;
	
	//S1
	int now = (keyword >> 48 - 6) & (63);
	int middle = (now >> 1) & 15;
	string temp = "";
	temp += to_string((now & (1 << 5)) >> 5);
	temp += to_string(now & 1);
	row = stoi(temp, 0, 2);
	int hh = (s1[row][middle]);
	ss << hex <<uppercase<< hh; 
	string res(ss.str());

	

	//S2
	now = (keyword >> (48 - (6*2)))& (63);
	middle = (now >> 1) & 15;
	string temp2 = "";
	temp2 += to_string((now & (1 << 5))>>5);
	temp2 += to_string(now & 1);
	row = stoi(temp2, 0, 2);
	hh = (s2[row][middle]);
	ss << hex << uppercase << hh;
	string res2(ss.str());
	
	
	//S3
	
	now = (keyword >> 48 - 6 * 3)& (63);
	middle = (now >> 1) & 15;
	string temp3 = "";
	temp3 += to_string((now & (1 << 5)) >> 5);
	temp3 += to_string(now & 1);
	row = stoi(temp3, 0, 2);
	hh = (s3[row][middle]);
	ss << hex << uppercase << hh;
	string res3(ss.str());

	
	//S4
	now = (keyword >> 48 - 6 * 4)& (63);
	middle = (now >> 1) & 15;
	string temp4 = "";
	temp4 += to_string((now & (1 << 5)) >> 5);
	temp4 += to_string(now & 1);
	row = stoi(temp4, 0, 2);
	hh = (s4[row][middle]);
	ss << hex << uppercase << hh;
	string res4(ss.str());
	
	
	//S5
	now = (keyword >> 48 - 6 * 5)& (63);
	middle = (now >> 1) & 15;
	string temp5 = "";
	temp5 += to_string((now & (1 << 5)) >> 5);
	temp5 += to_string(now & 1);
	row = stoi(temp5, 0, 2);
	hh = (s5[row][middle]);
	ss << hex << uppercase << hh;
	string res5(ss.str());
	
	
	//S6
	now = (keyword >> 48 - 6 * 6)& (63);
	middle = (now >> 1) & 15;
	string temp6 = "";
	temp6 += to_string((now & (1 << 5)) >> 5);
	temp6 += to_string(now & 1);
	row = stoi(temp6, 0, 2);
	hh = (s6[row][middle]);
	ss << hex << uppercase << hh;
	string res6(ss.str());

	
	//S7
	now = (keyword >> 48 - 6 * 7)& (63);
	middle = (now >> 1) & 15;
	string temp7 = "";
	temp7 += to_string((now & (1 << 5)) >> 5);
	temp7 += to_string(now & 1);
	row = stoi(temp7, 0, 2);
	hh = (s7[row][middle]);
	ss << hex << uppercase << hh;
	string res7(ss.str());
	
	
	//S8
	now = (keyword >> 48 - 6 * 8)& (63);
	middle = (now >> 1) & 15;
	string temp8 = "";
	temp8 += to_string((now & (1 << 5)) >> 5);
	temp8 += to_string(now & 1);
	row = stoi(temp8, 0, 2);
	hh = (s8[row][middle]);
	ss << hex << uppercase << hh;
	string res8(ss.str());
	output = res8;
	
	return output;
}

unsigned long long int key_generated(int PC1[], int PC2[], int Rotations[], unsigned long long int key, unsigned long long int keys[16]) {
	unsigned long long int key56 = permutation(56, PC1, 64, key);

	unsigned long long int key28_1, key28_2;

	key28_1 = ((key56 >> 28) & 0xFFFFFFF);
	key28_2 = (key56 & 0xFFFFFFF);

	unsigned long long int key56_2;
	unsigned long long int key48;

	for (int i = 0; i < 16; i++)
	{
		key28_1 = ((key28_1 << Rotations[i]) | (key28_1 >> 28 - Rotations[i])) & 0xFFFFFFF;
		key28_2 = ((key28_2 << Rotations[i]) | (key28_2 >> 28 - Rotations[i])) & 0xFFFFFFF;

		key56_2 = ((key28_1 << 28) | key28_2);
		key48 = permutation(48, PC2, 56, key56_2);
		keys[i] = key48;
	}
	return key48;
}

int main() {

	int IP[] = {58,50,42,34,26,18,10,2,60,52,44,
		36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7 };
	int Inv[] = { 40,8,48,16,56,24,
		64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };


	int s1[4][16] = { {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},

				{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},

				{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},

				{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13} };
	int s2[4][16] = { {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 },

				{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},

				{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},

				{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9} };
	int s3[4][16] = { {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8} ,

				{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},

				{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},

				{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12} };
	int s4[4][16] = { {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 },

				{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },

				{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 },

				{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 }};
	int s5[4][16] = { {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 },

				{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },

				{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 },

				{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 }};
	int s6[4][16] = { {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11} ,

				{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},

				{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},

				{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13} };
	int s7[4][16] = { {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1} ,

				{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
													 
				{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
													 
				{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12} };
	int s8[4][16] = { {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7} ,

{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},

{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},

{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11} };

	int eptable[] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17
		,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
	int sptable[] = { 16,7,20,21,29,12,28,17,1,15,23,26,5,18
		,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};

	int PC1[] = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43,
		35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
	int	PC2[] = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19,
		12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

	int Rotations[] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

	unsigned long long int keys[16];

	string key64;
	cin >> key64;
	istringstream converter2{ key64 };
	unsigned long long int givenkey = 0;
	converter2 >> hex >> givenkey;

	string in;
	cin >> in;
	istringstream converter{ in }; 
	unsigned long long int input = 0;
	converter >> hex >> input;
	
	int rounds;
	cin >> rounds;
	
	unsigned long long int key = key_generated(PC1, PC2, Rotations, givenkey, keys);

	unsigned long long int p1 = permutation(64, IP, 64, input);
	unsigned long long int pt32_L, pt32_R;
	unsigned long long int out1;
	unsigned long long int out2;
	unsigned long long int out3 = 0;
	unsigned long long int last;
	unsigned long long int temp;
	unsigned long long int last2;
	
	while (rounds > 0) {
		pt32_L = ((p1 >> 32) & 0xFFFFFFFF);
		pt32_R = (p1 & 0xFFFFFFFF);

		for (int j = 15; j >= 0; j--) {
			out1 = permutation(48, eptable, 32, pt32_R);
			out2 = out1 ^ keys[j];
			string out3s = sbox(s1, s2, s3, s4, s5, s6, s7, s8, out2);
			istringstream converter3{ out3s };
			converter3 >> hex >> out3;
			last = permutation(32, sptable, 32, out3);
			temp = pt32_R;
			pt32_R = last ^ pt32_L;
			pt32_L = temp;
		}

		swap(pt32_L, pt32_R);
		p1 = ((pt32_L << 32) | pt32_R);
		
		
		rounds--;
	}
	last2 = permutation(64, Inv, 64, p1);
	cout << hex << uppercase << setfill('0') << setw(16) << last2;

	return 0;
}
