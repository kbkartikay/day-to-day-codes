#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> mtr;
vector<int>p;
void dfs(int curr_node,int curr_id=-1)
{
	if(mtr[curr_node].size()==1) p[curr_id]=1;
	for(auto[next_node,next_id] : mtr[curr_node])
	{
		if(next_id==curr_id) continue;
		dfs(next_node,next_id);
		if(curr_id!=-1) p[curr_id]+=p[next_id]; 
	} 
}


int main()

{
	int n;
	cin>>n;
	vector<vector<pair<int,int>>> mtr(n-1);
	vector<int>p(n-1);
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		mtr[x].push_back({y,i});
		mtr[y].push_back({x,i});
	}
	for(auto x : p)
		cout<<x<<" ";
	cout<<endl;

}

