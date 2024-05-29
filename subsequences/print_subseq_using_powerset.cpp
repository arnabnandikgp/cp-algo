#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
vector<string> AllPossibleStrings(string s) //function to find all the subsequences of string s.
{
    int n = s.length();
    vector<string> ans;
    for(int i=0;i<(1<<s.length());i++)
    {   string sub ="";
        for(int j=0;j<s.length();j++)
        {
            if(i&(1<<j))
            {
                sub +=s[j];
            }
        }
        if(sub.length()>0) ans.push_back(sub);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{


	string s="abc";
	vector<string>ans = AllPossibleStrings(s);
	//printint all the subsequence.
	cout<<"All possible subsequences are "<<endl;
	for (auto it : ans) {
		cout << it << " ";
	}

}