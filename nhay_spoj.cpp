#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// for kmp matching simply concatenate pattern#text
// whenever lps is pattern.length(), we are getting a match
// for calculating lps see the preKMP
// void preKMP(string s,int lps[])
// A border of s is a prefix less than s,which is also a suffix of s.
// A border of a border is a border. :- prove this and lps part is done.
// for calculating border for s[0..i+1] if s[0..i] is known
// you either pump the same border as of s[0..i]
// or you look for all borders of the border to be pumped in an ordered fashion.  
int main()
{
	int n;
	string s1;
	while(cin>>n){
		//cout<<"n="<<n<<endl;
		cin>>s1;
		// na#
		s1+='#';
		int id=0;
		int lps[n+1];
		lps[0]=0;
		for(int i=1;i<n+1;){
			//cout<<"i="<<i<<endl;
			if(s1[i]==s1[id]){
				lps[i]=++id;
				i++;
			}
			else{
				if(id>0){
					id=lps[id-1];
				}
				else{
					lps[i]=0;
					i++;
				}
			}
		}
		//cout<<"s1="<<s1<<endl;
		char ch;
		int x=0;
		bool flag=0;
		getchar();
		while(1){
			ch=getchar();
			if(ch=='\n') break;
			while(1) {
				if(ch==s1[id]) {
					id++;
					break;
				}
				else {
					if(id>0) id=lps[id-1];
					else break;
				}
			}
			// cout<<"id="<<id<<"ch="<<ch<<endl;
			if(id==n){cout<<x-n+1<<endl;}
			x++;
		}
		cout<<endl;
	}
}
