#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
int dir(pii p1,pii p2,pii p3)
{
	int x1=p1.F-p3.F;
	int y1=p1.S-p3.S;
	int x2=p2.F-p3.F;
	int y2=p2.S-p3.S;
	return x1*y2-x2*y1;
}
bool onseg(pii p1,pii p2,pii p3)
{
	if(p3.F>=min(p1.F,p2.F)&&p3.F<=max(p1.F,p2.F)&&p3.S>=min(p1.S,p2.S)&&p3.S<=max(p1.S,p2.S))
	return true;
	return false;
}
bool intersect(pii p1,pii p2,pii p3,pii p4)
{
	int d1=dir(p3,p4,p1);
	int d2=dir(p3,p4,p2);
	int d3=dir(p1,p2,p3);
	int d4=dir(p1,p2,p4);
	if(d1*d2<0&&d3*d4<0)
	{
		return true;
	}
	if(!d1&&onseg(p3,p4,p1))
	return true;
	if(!d2&&onseg(p3,p4,p2))
	return true;
	if(!d3&&onseg(p1,p2,p3))
	return true;
	if(!d4&&onseg(p1,p2,p4))
	return true;
	return false;
}
int main()
{
	pii p1,p2,p3,p4;
	cout<<"enter x and y coordintes of the points"<<endl;
	cin>>p1.F>>p1.S>>p2.F>>p2.S;
	cin>>p3.F>>p3.S>>p4.F>>p4.S;
	if(intersect(p1,p2,p3,p4))
	{
		cout<<"segments intersect"<<endl;
	}
	else
	{
		cout<<"segments do not intersect"<<endl;
	}
}
