#include "BFS.h"

int max_island::maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    int height = grid.size();
    int width = grid[0].size();
    for(int i = 0;i<height;i++){
        for(int j =0;j<width;j++){
            if(grid[i][j]==1){
                int local = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                grid[i][j] = -1;
                while(!q.empty()){
                    int now_x = q.front().first;
                    int now_y = q.front().second;
                    q.pop();
                    for(int k = 0;k<4;k++){
                        if(now_x+dim1[k]>=0&&now_x+dim1[k]<height&&now_y+dim2[k]>=0
                           &&now_y+dim2[k]<width&&grid[now_x+dim1[k]][now_y+dim2[k]]==1){
                            q.push({now_x+dim1[k],now_y+dim2[k]});
                            grid[now_x+dim1[k]][now_y+dim2[k]] = -1;
                            local++;
                        }
                    }
                }
                ans = max(ans,local);
            }
        }
    }
    return ans;
}

void max_island::test(){
    auto ans = maxAreaOfIsland(island);
    cout<<ans<<endl;
}
