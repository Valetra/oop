#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> string;
	string.push_back("Lorum");
	string.push_back("ipmsum");
	string.push_back("avec");

	string.at(0).clear();

	for (size_t i = 0; i < string.size(); ++i)
	{
		for (size_t j = 0; j < string.at(i).size(); ++j)
		{
			cout << string.at(i).at(j);
		}
		cout << "\n";
	}
	return 0;
}