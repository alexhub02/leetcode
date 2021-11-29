#ifndef BREADTH_FIRST_SEARCH_BFS_H
#define BREADTH_FIRST_SEARCH_BFS_H
#include "Tree.h"
// max_island lc_695
class max_island{
public:
    const int dim1[4] = {0,0,1,-1};
    const int dim2[4] = {1,-1,0,0};
    vector<vector<int>> island = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                  {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                  {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                  {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                  {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                  {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                  {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                  {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid);
    void test();
};
#endif //BREADTH_FIRST_SEARCH_BFS_H
