#include <iostream>
using namespace std;
#include <vector>
#include < unordered_set>
#include <algorithm>
void find(vector<int>& v, int staridex, vector<int>& used, int& sum)
{
	if (staridex != 0)
	{
		sum++;
	}
	if (staridex == v.size())
	{
		return;
	}
	unordered_set<int> s;
	for (int i = staridex; i < v.size(); i++)
	{
		if ((i > 0 && v[i] == v[i - 1] && used[i - 1] == 1) || s.find(v[i]) != s.end())
		{
			continue;
		}
		used[i] = 1;
		find(v, i + 1, used, sum);
		used[i] = 0;
	}

}
int main()
{
	string s;
	cin >> s;
	vector<int> v;
	/*vector<int> path;
	vector<vector<int>> result;*/
	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i] - 'a');
	}
	sort(v.begin(), v.end());
	int staridex = 0;
	vector<int> used(27, 0);
	int sum = 0;
	find(v, staridex, used, sum);
	cout << sum << endl;
	return sum;
}
