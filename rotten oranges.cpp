#include<bits/stdc++.h>
using namespace std;

class Solution{
	public :
		int OrangeRottening (vector < vector <int > > & grid ){
			int n = grid.size();
			int m = grid[0].size();
			
			queue <pair<pair<int,int>,int>> q;
			int  vis[n][m];
			int cntfrsh = 0 ;
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < m ; j++){
					if(grid[i][j]==2){
						q.push({{i,j},0});
						vis[i][j] = 2;
					}else{
						vis[i][j] = 0;
					}
					if(grid[i][j]==1) cntfrsh++ ;
				}
			}
			
			int tm = 0;
			int drow[] = {-1,0,1,0};
			int dcol[] = {0,1,0,-1};
			int cnt;
			while(!q.empty()){
				int r = q.front().first.first;
				int c = q.front().first.second;
				int t = q.front().second;
				tm = max(tm,t);
				q.pop();
				for(int i = 0 ; i < 4 ; i++){
					nrow = r + drow;
					ncol = c + dcol;
					if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
						q.push({{nrow,ncol}, t + 1});
						vis[nrow][ncol] = 2;
						cnt++;
					}
				}
			}
			if(cnt != cntfrsh) return -1;
			return tm;
		}
};

int main() {

  vector<vector<int>>grid{{0,1,2},{0,1,2},{2,1,1}};
  Solution obj;
  int ans = obj.orangesRotting(grid);
  cout << ans << "\n";

  return 0;
}