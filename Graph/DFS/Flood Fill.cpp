/*
    Company Tags                     : Amazon, Microsoft, Intuit, Apple
    LeetCode Link                    : https://leetcode.com/problems/flood-fill/description/
*/


/************************************************ C++ ************************************************/

//T.C : O(N * M)
//S.C : O(N × M)
// N = number of rows in the image
// M = number of columns in the image

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>dx={+1,-1,0,0};
    vector<int>dy={0,0,-1,+1};

    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int own_color){

           if(sr>=image.size() || sr<0 || sc>=image[0].size() || sc<0 || image[sr][sc]!=own_color || ans[sr][sc]==color)return ;

           ans[sr][sc]=color;

           for(int i=0;i<4;i++){

                int x=sr+dx[i];
                int y=sc+dy[i];
                
                dfs(image,x,y,color,own_color);
           }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      
      ans=image;
      
      dfs(image,sr,sc,color,image[sr][sc]);

      return ans;
  
    }
};

