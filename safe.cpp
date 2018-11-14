#include<bits/stdc++.h>
using namespace std;
int q=0;
void seq(vector<vector<int> > need, vector<int> avail, vector<bool> f,vector<vector<int> > all , vector<int> ans)
{

        int i,j,p;
        bool g=1;
        for(i=0;i<f.size();i++)
              g=g&f[i];
        if(g)
	{
                for(i=0;i<ans.size();i++)
                        cout<<ans[i]<<" ";
                cout<<endl;
                q++;
                return;
        }
        p=-1;
        for(i=0;i<need.size();i++)
	{
                if(!f[i])
		{
                        bool r=1;
                        for(j=0;j<need[0].size();j++)
                                r=r && (need[i][j] <= avail[j]);
                        if(r)
			{
                                ans.push_back(i);
                                int x;
                                for(x=0;x<need[0].size();x++)
                                        avail[x]+=all[i][x];
                                f[i]=1;
                                
                                seq(need,avail,f,all,ans);                                  
                                
                                ans.pop_back();
                                f[i]=0;
                                for(x=0;x<need[0].size();x++)
                                        avail[x]-=all[i][x];
                                
                        }                       
                } 
        } 

}

int main()
{
        vector<vector<int> > all={{4,2,6,5},{3,1,0,1},{4,2,5,0},{1,0,0,2}};
        vector<vector<int> > max={{7,6,7,7},{6,5,3,4},{7,6,6,2},{9,2,3,2}};
//        vector<int> avail={15,9,12,10};
          vector<int> avail={3,4,1,2};
        
        int i,j,n=all.size(),m=all[0].size();
        vector<vector<int> > need(n,vector<int> (m));
        
        for(i=0;i<n;i++)
                for(j=0;j<m;j++)
                        need[i][j]=max[i][j]-all[i][j];
        
        vector<bool> f(n,0);
        vector<int> ans;
        seq(need,avail,f,all,ans);       
        cout<<q<<endl;
}
