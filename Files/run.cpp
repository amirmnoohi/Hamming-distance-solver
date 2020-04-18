#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
int go_down = 1;
vector<string> allstrings;
vector<int> lower_bnd;
int  L, W, D;
int W_of_string(string x) {
	int temp = 0;
	for (int i = 0; i < x.size(); i++)
		if (x[i] == '1') temp++;
	return temp;
}
string convert_num_to_bin_string(long long x, int length) {
	string temp;
	int alfa = 0;
	for (int i = 0; length;)
	{
		temp.resize(alfa + 1);
		alfa++;
		temp[temp.size() - i - 1] = (x & 1) ? '1' : '0';
		x /= 2;
		length--;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
int diff_hamming(string x, string y) {
	int temp = 0;
	for (int i = 0; i < x.size(); i++)
		if (x[i] != y[i])
			temp++;
	return temp;
}
bool diff_hamming_id(int a, int b) {
	return diff_hamming(allstrings[a], allstrings[b]) >= D ? true : false;
}
int diff(int x, int thresh) {
	int temp = 0;
	for (int i = 0; i < lower_bnd.size(); i++)
	{
		if (!diff_hamming_id(x, lower_bnd[i]))
			temp++;
		if (x == lower_bnd[i])
			return 0;
	}
	return temp <= thresh ? 1 : 0;
}
void output(vector<int> a) {
	FILE * x = fopen("test.mtx", "w");
	fprintf(x, "%%%%MatrixMarket matrix coordinate real symmetric\n");
	vector<pair<int, int>> test;
	for (int i = a.size() - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (diff_hamming_id(a[i], a[j])) {
				test.push_back(make_pair(a[i], a[j]));
			}
		}
	}
	cout << test.size() << endl;
	fprintf(x, "%d %d %d\n", allstrings.size(), allstrings.size(), test.size());
	for (int i = 0; i < test.size(); i++)
	{
		fprintf(x, "%d %d\n", test[i].first + 1, test[i].second + 1);
	}
	cout << "Output Process Done" << endl;
	fclose(x);
}
int index_string(string x) {
	for (int i = 0; i < allstrings.size(); i++)
	{
		if (x == allstrings[i])
			return i;
	}
	return -1;
}
void convert_id_to_file(vector<int> a) {
	FILE * x = fopen("answer.txt", "w");
	for (int i = 0; i < a.size(); i++)
	{
		fprintf(x, "%s \n", allstrings[a[i]].c_str());
	}
	printf("Converted Successfully\n");
	fclose(x);
}
int main()
{
	cin >> L >> W >> D;
	vector<int> all;
	for (int i = (int)pow(2, W) - 1; i < (int)pow(2, L); i++)
	{
		string beta = convert_num_to_bin_string(i, L);
		if (W_of_string(beta) == W) {
			allstrings.push_back(beta);
		}
	}
	for (int i = 0; i < allstrings.size(); i++)
		all.push_back(i);
	cout << "Number of strings SET : " << allstrings.size() << endl;
	output(all);
	char y;
	cout << "is there input.txt?" << endl;
	cin >> y;
	while (1)
	{
		lower_bnd.clear();
		FILE *x = fopen("input.txt", "r");
		int a;
		while (fscanf(x, "%d", &a) != -1) {
			lower_bnd.push_back(a - 1);
		}
		cout << "New Input Size : " << lower_bnd.size() << endl;
		fclose(x);
		vector<int> diff_temp;
		int MAXDIFF;
		cout << "MAXDIFF : ";
		cin >> MAXDIFF;
		for (int i = 0; i < allstrings.size(); i++)
		{
			if (diff(i, MAXDIFF)) {
				diff_temp.push_back(i);
			}
		}
		lower_bnd.insert(lower_bnd.end(), diff_temp.begin(), diff_temp.end());
		sort(lower_bnd.begin(), lower_bnd.end());
		cout << "[+] Number Of New Vertex " << lower_bnd.size() << endl;
		output(lower_bnd);
		char END;
		cout << "END ? ([y],n) ";
		cin >> END;
		if (END == 'y') {
			for (int i = (int)pow(2, W) - 1; i < (int)pow(2, L); i++)
			{
				string beta = convert_num_to_bin_string(i, L);
				if (W_of_string(beta) == W) {
					allstrings.push_back(beta);
				}
			}
			FILE *y = fopen("input.txt", "r");
			int a;
			vector<int> ans;
			while (fscanf(y, "%d", &a) != -1)
				ans.push_back(a - 1);
			fclose(y);
			sort(ans.begin(), ans.end());
			convert_id_to_file(ans);
			/*############################  Check Answers  #####################*/
			FILE * z = fopen("answer.txt", "r");
			char * temp = new char[L];
			string str;
			vector<string> all;
			while (fscanf(z, "%s", temp) != -1)
			{
				str = temp;
				all.push_back(temp);
			}
			fclose(z);
			for (int i = 0; i < all.size() - 1; i++)
			{
				for (int j = i + 1; j < all.size(); j++)
				{
					if (diff_hamming(all[i], all[j]) < D)
					{
						printf("This is not Consistent\n");
						return 0;
					}
				}
			}
			cout << "Answer Passed Tests Successfully\n" << endl;
			return 0;
		}
	}
	return 0;
}


