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
	bt=0;
	queue<process> q1;
	queue<process> q2;
	queue<process> q3;
	sort(a,a+n,comp);
	q1.push(a[0]);
	t=a[0].at;
	i=1;
	while(1)
	{
		process z;
		if(q1.empty()&&q2.empty()&&q3.empty())
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
			if(z.bt <=4)
			{
				t=t+z.bt;
				bt+=(t-z.at);
				cout<<"Completed "<<z.id<<" at "<<t<<" queue1"<<endl;
			}
			else
			{
				z.bt = z.bt-4;	
				t=t+4;
				f=1;
			}
			while(i<n && t>=a[i].at)
			{
				q1.push(a[i++]);
			}
			if(f)
			{
				q2.push(z);
			}
		}
		else if(!q2.empty())
		{
			bool l=0;
			z=q2.front();	
			q2.pop();
			if(z.bt<=8)
			{
				t=t+z.bt;
				bt+=(t-z.at);
				cout<<"Completed "<<z.id<<" at "<<t<<" queue2"<<endl;
			}
			else
			{
				z.bt = z.bt-8;
				t=t+8;
				l=1;
			}
			if(l)
				q3.push(z);
		}
		else if(!q3.empty())
		{
			bool a=0;
			z=q3.front();
			q3.pop();
			if(z.bt<=12)
			{
				t=t+z.bt;
				bt+=(t-z.at);
				cout<<"Completed "<<z.id<<" at "<<t<<" queue3"<<endl;
			}
			else
			{
				z.bt = z.bt-12;
				t=t+12;
				a=1;
			}
			if(a)
				q3.push(z);
		}
	}
cout<<"Average turn around time = "<<(1.0*bt)/n<<endl;
}
