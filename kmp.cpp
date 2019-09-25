#include<bits/stdc++.h>
using namespace std;
// for kmp matching simply concatenate pattern#text
// whenever lps is pattern.length(), we are getting a match
// for calculating lps see the preKMP
void preKMP(string s,int lps[])
{
	// A border of s is a prefix less than s,which is also a suffix of s.
	// A border of a border is a border. :- prove this and lps part is done.
	// for calculating border for s[0..i+1] if s[0..i] is known
	// you either pump the same border as of s[0..i]
	// or you look for all borders of the border to be pumped in an ordered fashion.  
	int n=s.length(),index=0,i=1;
	lps[0]=0;
	while(i<n)
	{
		if(s[i]==s[index])
		{
			lps[i]=index+1;
			index++;
			i++;
		}
		else
		{
			if(index>0)
			{
				index=lps[index-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}
vector<int> KmpOccurences(string text,string pattern,int lps[])
{

	int i=0,j=0,n=text.length(),m=pattern.length();
	vector<int> ans;
	while(i<n)
	{
		if(text[i]==pattern[j])
		{
			i++;j++;
			if(j==m)
			{
				ans.push_back(i-m+1);
				j=lps[j-1];
			}
		}
		else
		{
			if(j!=0)
			j=lps[j-1];
			else
			i++;
		}
	}
	return ans;
}
int main()
{
	string text,pattern;
	cin>>text>>pattern;
	int lps[pattern.length()];
	preKMP(pattern,lps);
	vector<int> res=KmpOccurences(text,pattern,lps);
	for(int i=0;i<res.size();i++)
	{
		cout<<"at shift="<<res[i]-1<<endl;;
	}
	if(res.size()==0)
	cout<<"not found"<<endl;
	cout<<endl;
}
