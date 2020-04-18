#include<iostream>
#include<string>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int L, W, D;
int W_of_string(string x) {
	int temp = 0;
	for (int i = 0; i < x.size(); i++)
		if (x[i] == '1') temp++;
	return temp;
}
int diff_hamming(string x, string y) {
	int temp = 0;
	for (int i = 0; i < x.size(); i++)
		if (x[i] != y[i])
			temp++;
	return temp;
}
int main()
{
	cin >> L >> W >> D;
	FILE * x = fopen("answer.txt", "r");
	char * temp = new char[L];
	string str;
	vector<string> all;
	while (fscanf(x, "%s", temp) != -1)
	{
		str = temp;
		all.push_back(temp);
	}
	/*####################   CHECK L    ######################*/
	for (int i = 0; i < all.size(); i++)
	{
		if (all[i].size() != L) {
			cout << "Wrong L : " << i << endl;
			cin >> W;
			return 0;
		}
	}
	/*####################   CHECK W    ######################*/
	for (int i = 0; i < all.size(); i++)
	{
		if (W_of_string(all[i]) != W) {
			cout << "Wrong W : " << i << endl;
			cin >> W;
			return 0;
		}
	}
	/*####################   REPEAT   ######################*/
	for (int i = 0; i < all.size() - 1; i++)
	{
		for (int j = i + 1; j < all.size(); j++)
		{
			if (all[i] == all[j])
			{
				printf("Repeat String Found : %d %d", i, j);
				cin >> W;
				return 0;
			}
		}
	}
	/*####################   CHECK W   ######################*/
	for (int i = 0; i < all.size() - 1; i++)
	{
		for (int j = i + 1; j < all.size(); j++)
		{
			if (diff_hamming(all[i], all[j]) < D)
			{
				printf("This is not Consistent\n");
				cout << i << " " << j << endl;
				cin >> W;
				return 0;
			}
		}
	}
	cout << "Answer Passed Tests Successfully\n" << endl;
	cin >> W;
	return 0;
}
