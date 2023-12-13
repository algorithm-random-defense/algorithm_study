#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> ret;
	for (int i = 0; i < n; i++)
	{
		string input, ext;
		size_t sep;
		cin >> input;
		sep = input.find('.');
		ext = input.substr(sep + 1, input.size());
		ret[ext] += 1;
	}
	for (auto const &pair : ret)
		cout << pair.first << " " << pair.second << endl;
}
