#include<bits/stdc++.h>
using namespace std;
struct process
{
	int id;
	int at;
	int bt;
	int ct;
	int tat;
	int qn;
};

bool comp(process a,process b)
{
	if(a.at==b.at)
		return a.id<b.id;
	return a.at<b.at;
}
int main()
{
	int i,n,id,at,bt,t;
	cin>>n;
	process a[n];
	for(i=0;i<n;i++)
	{
		cin>>id>>at>>bt;
		a[i].id=id;
		a[i].at=at;
		a[i].bt=bt;
	}
	sort(a,a+n,comp);
	t=a[0].at;
	for(i=0;i<n;i++)
	{
		if(t<a[i].at)
		{
			t=a[i].at;
		}
		a[i].ct=t+a[i].bt;
		t=a[i].ct;
		a[i].tat=a[i].ct-a[i].at;
	}
	t=0;
	for(int i=0;i<n;i++)
	{
		t=t+a[i].tat;
	}
	cout<<"Average turn around time="<<(1.0*t)/n<<endl;
}
