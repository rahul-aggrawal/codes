#include<bits/stdc++.h>
using namespace std;
struct process
{
	int id;
	int at;
	int bt;	
	int ct;
	int tat;
	int queue;
};
bool comp(process a,process b)
{
	if(a.at==b.at)
		return a.id<b.id;
	return a.at<b.at;
}
int main()
{
	int i,n,id,at,bt,tq,t;
	cin>>n;
	process a[n];
	for(i=0;i<n;i++)
	{
		cin>>id>>at>>bt;
		a[i].id=id;
		a[i].at=at;
		a[i].bt=bt;
	}
	cin>>tq;
	bt=0;
	queue<process> q1;
	sort(a,a+n,comp);
	q1.push(a[0]);
	t=a[0].at;
	i=1;
	while(1)
	{
		process z;
		if(q1.empty())
		{
			break;
		}
		else if(!q1.empty())
		{
			bool f=0;
			z=q1.front();
			q1.pop();
			if(t<z.at)
			t=z.at;
			if(z.bt <=tq)
			{
				t=t+z.bt;
				bt+=(t-z.at);
				cout<<"Completed "<<z.id<<" at "<<t<<" queue1"<<endl;
			}
			else
			{
				z.bt = z.bt-tq;	
				t=t+tq;
				f=1;
			}
			while(i<n && t>=a[i].at)
			{
				q1.push(a[i++]);
			}
			if(f)
			{
				q1.push(z);
			}
		}
	}
cout<<"Average turn around time = "<<(1.0*bt)/n<<endl;
}
