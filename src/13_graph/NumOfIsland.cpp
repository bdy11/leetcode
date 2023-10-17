/*
200. 岛屿数量
中等
2.3K
相关企业
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

 

示例 1：

输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：

输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
*/

/*
solution:
使用深度搜索或者广度搜索
1. 定义dfs - function
 4个输入分别是:
 grid 为输入的岛屿对应的graph
 二维矩阵visited用来标记，哪些格子已经访问过
 x,y表示当前处理的格子的对应坐标
 x控制行坐标
 y控制列坐标

dfs function的作用是，如果当前格子时陆地，那么将当前格子相邻的陆地，以及相邻陆地相邻的陆地...标记为访问过。
dfs检查当前格子的周围四个方向的相邻格子， 是否越界，是否访问过，以及是否是陆地，
如果是陆地，继续dfs，并且将当前岛屿标记为访问过

主函数里，用m, n表示graph的行数，列数
然后创建一个m行 n列的二维矩阵，存储bool值，用来记录格子是否被访问过。
再使用二重循环遍历每一个格子时，使用index i 遍历每一行，使用j遍历每一列
如果遍历时发现一个格子是陆地，陆地计数器加1，然后调用dfs function，将相邻陆地全部标记为访问过。

下一次发现一个格子是陆地且未访问过时，我们可以确定，这次发现了另外一片陆地，陆地计数器加一，
并且用dfs function标记所有相邻陆地为访问过。

*/
#include <vector>
using namespace std;
class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        for(int i = 0; i < 4; i++){
            int nextx = x + dx[i];
            int nexty = y + dy[i];
            if(nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;
            if(!visited[nextx][nexty] && grid[nextx][nexty] == '1'){
                visited[nextx][nexty] = true; 
                dfs(grid, visited, nextx, nexty);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int result = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    result++;
                    visited[i][j] = true;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return result;
    }
};