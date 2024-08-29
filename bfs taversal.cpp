#include<iostream>
using namespace std;

//tc = o(n) + o(2E)
class SolutionBFS{
	public:
		vector<int> bfsOfGraph(int v , vector<int>adj[]){
			int vis[v] = {0};
			vis[0] = 1;
			queue<int> q;
			q.push(0);
			vector<int> bfs;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				
				for(auto it : adj[node]){
					if(!vis[it]){
						vis[it] = 1;
						q.push(it);
					}
				}
			}
			return bfs;
		}
};


//tc = o(n) + o(2E)
class SolutionDFS{
	private :
		void DFS(int node , vector<int> adj[] , int vis[] , vector<int> &ls){
			vis[node] = 1 ;
			ls.push_back(node)
			for(auto it : adj[node]){
				if(!vis[node]){
					dfs(node,adj,vis,ls);
				}
			}
		}
	public:
		vector<int> bfsOfGraph(int v , vector<int>adj[]){
			int vis[v]= {0};
			int start = 0;
			vector<int> ls;
			dfs(start,adj,vis,ls);
			return ls;
		}
};