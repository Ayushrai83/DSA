class Solution {
private:
    void dfs(vector<vector<int>>& image ,int row ,int col,vector<vector<int>>& ans,  int color,int delRow[] , int delCol[], int iniColor){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0 ; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == iniColor && 
            ans[nrow][ncol]){
                dfs(image , nrow , ncol , ans   , color , delRow ,delCol , iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1 , 0 ,1, 0};
        int delCol[] = {0,1,0,-1};
        dfs(image, sr , sc , ans  ,color,delRow,delCol, iniColor);
        return ans;
    }
};