/*
1 2 
3 6
5 7
4 8
2 1
-1 4
5 8
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
	bool flag;
	int x,y;
	node *left,*right;
	node(int a,int b,bool c)
	{
		x=a;y=b;flag=c;
		left=right=0;
	}
};
node* insert(int x,int y,bool flag,node* root)
{
	if(!root)
	{
		node* t=new node(x,y,flag);
		return t;
	}
	if(root->flag)
	{
		//compare y
		if(y<=root->y)
		{
			root->left=insert(x,y,0,root->left);
		}
		else
		{
			root->right=insert(x,y,0,root->right);
		}
	}
	else
	{
		if(x<=root->x)
		{
			root->left=insert(x,y,1,root->left);
		}
		else
		{
			root->right=insert(x,y,1,root->right);
		}
	}
	return root;
}
void print(node* t)
{
	if(!t)
	{
		cout<<"NULL ";
		return;
	}
	cout<<"("<<t->x<<" "<<t->y;
	if(!t->flag)
	{
		cout<<" x) ";
	}
	else
	cout<<" y) ";
}
void levelOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* t=q.front();q.pop();
		print(t);
		cout<<"left=";
		print(t->left);
		cout<<"right=";
		print(t->right);
		cout<<endl;
		if(t->left)
		{
			q.push(t->left);
		}
		if(t->right)
		{
			q.push(t->right);
		}
	}
}
int main()
{
	cout<<"enter n"<<endl;
	int n;cin>>n;
	cout<<"enter points"<<endl;
	int x[n],y[n];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	node* root=new node(x[0],y[0],0);
	for(int i=1;i<n;i++)
	{
		root=insert(x[i],y[i],0,root);
	}
	cout<<"level Order traversal is:"<<endl;
	levelOrder(root);
}
