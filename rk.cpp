#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define pii pair<int,int>
#define S second
int main()
{
    string t,p;
    cin>>t>>p;
    int n=t.length(),m=p.length();
    int q=11,d=3,pn=0,tn=0,h=1;
    for(int i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }
    for(int i=0;i<m;i++)
    {
        pn=(pn*d+(p[i]-'a'))%q;
        tn=(tn*d+(t[i]-'a'))%q;
    }
    for(int i=0;i<n;i++)
    {
        //cout<<"pn="<<pn<<" tn= "<<tn<<endl;
        if(pn==tn)
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(t[i+j]!=p[j])
                {
                    flag=1;break;
                }
            }
            if(flag==0)
            cout<<"pattern occurs with shift:"<<i<<endl;
        }
        if(i+m<n)
        tn=(tn-(t[i]-'a')*h)*d+(t[i+m]-'a');
        else break;
    }
}