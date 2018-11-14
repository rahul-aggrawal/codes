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
	while(1)
	{
		int k=-1;
		for(i=0;i<n;i++)
		{
			if(a[i].bt!=0&&a[i].at<=t)
			{
				if(k==-1||a[i].bt<a[k].bt)
				{
					k=i;
				}
			}
		}
		if(k==-1)
		{
			break;
		}
		a[k].bt--;
		t++;
		if(a[k].bt==0)
		{
			a[k].ct=t;
			a[k].tat=a[k].ct-a[k].at;
		}
	}
	t=0;
	for(int i=0;i<n;i++)
	{
		t=t+a[i].tat;
	}
	cout<<"Average turn around time="<<(1.0*t)/n<<endl;
}
