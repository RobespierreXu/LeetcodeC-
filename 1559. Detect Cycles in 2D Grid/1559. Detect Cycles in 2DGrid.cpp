using namespace std;

#include <vector>
#include <list>
#include <stack>

#include <iostream>

/* 
https://leetcode.com/problems/detect-cycles-in-2d-grid/
Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.

A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cycle of the same value exists in grid, otherwise, return false.

 

Example 1:



Input: grid = [['a','a','a','a'],['a','b','b','a'],['a','b','b','a'],['a','a','a','a']]
Output: true
Explanation: There are two valid cycles shown in different colors in the image below:

Example 2:



Input: grid = [['c','c','c','a'],['c','d','c','c'],['c','c','e','c'],['f','c','c','c']]
Output: true
Explanation: There is only one valid cycle highlighted in the image below:

Example 3:



Input: grid = [['a','b','b'],['b','z','b'],['b','b','a']]
Output: false


Input:
[['c','a','d'],['a','a','a'],['a','a','d'],['a','c','d'],['a','b','c']]
Expected:
true

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 500
1 <= n <= 500
grid consists only of lowercase English letters.
*/


class Solution {
private:
    bool dfs(vector<vector<int>> &link_tab, int &start_node){
        bool has_cycle = false;
        reached[start_node] = 1;
        cout << "node" << start_node << "--";
        for (auto child : link_tab[start_node]) {
            if (reached[child] == 1 && child != parent_node[start_node]) {
                cout << "node" << child << "end cycle" << endl;
                has_cycle = true;
                break;
            }
            else if (reached[child] == 0) {
                parent_node[child] = start_node;
                has_cycle = dfs(link_tab, child);
                if (has_cycle == true)
                {
                    break;
                }
            }
        }
        cout << "cycle " << has_cycle << " end " << start_node <<" node" << endl;
        reached[start_node] = 2;
        return has_cycle;
    }

    vector<int> reached;
    vector<int> parent_node;

public:
    bool containsCycle(vector<vector<char>>& grid) {

        // represent the all the nodes can be reached to this node
        vector<vector<int>> link_tab;

        link_tab.resize(grid.size()*grid[0].size());
        reached.resize(grid.size()*grid[0].size());
        parent_node.resize(grid.size()*grid[0].size());
        for(auto var : parent_node)
        {
            var = grid.size()*grid[0].size();
        }

        int i = 0; 
        int j = 0;

        for(i=0; i<grid.size(); i++)
        {
            for(j=0; j<grid[0].size(); j++)
            {
                // calculator how many ways each block
                // and reachable table
                if(i>0)
                {
                    if(grid[i][j] == grid[i-1][j])
                    {
                        //ways[i*grid[0].size()+j]++;
                        link_tab[i*grid[0].size()+j].push_back((i-1)*grid[0].size()+j);
                    }
                }
                if(j>0)
                {
                    if(grid[i][j] == grid[i][j-1])
                    {
                        //ways[i*grid[0].size()+j]++;
                        link_tab[i*grid[0].size()+j].push_back(i*grid[0].size()+j-1);
                    }
                }
                if(i<grid.size()-1)
                {
                    if(grid[i][j] == grid[i+1][j])
                    {
                        //ways[i*grid[0].size()+j]++;
                        link_tab[i*grid[0].size()+j].push_back((i+1)*grid[0].size()+j);
                    }
                }
                if(j<grid[0].size()-1)
                {
                    if(grid[i][j] == grid[i][j+1])
                    {
                        //ways[i*grid[0].size()+j]++;
                        link_tab[i*grid[0].size()+j].push_back(i*grid[0].size()+j+1);
                    }
                }
            }
        }

        bool has_cycle = false;

        for (int k = 0; k < reached.size(); k++)
        {
            /* code */
            if(reached[k] == 0)
            {
                // bfs search from node-k
                has_cycle = dfs(link_tab, k);
            }
            else
            {
                continue;
            }

            if(has_cycle == true){
                return true;
            }
        }

        return has_cycle;        
    }
};


int main()
{
    vector<vector<char>> grid2 = 
    {
   
        {'c','c','c','a'},
        {'c','d','c','c'},
        {'c','c','e','c'},
        {'f','c','c','c'}
    };
    vector<vector<char>> grid1 = 
    {
        
        {'a','a','a','a'},
        {'a','b','b','a'},
        {'a','b','b','a'},
        {'a','a','a','a'}
        
    };
    vector<vector<char>> grid3 = 
    {    
        {'a','b','b'},
        {'b','z','b'},
        {'b','b','a'}
    };
    vector<vector<char>> grid4 = 
    {    
        {'d','b','b'},
        {'c','a','a'},
        {'b','a','c'},
        {'c','c','c'},
        {'d','d','a'}
    };
    vector<vector<char>> grid5 = 
    {    
        {'c','a','d'},
        {'a','a','a'},
        {'a','a','d'},
        {'a','c','d'},
        {'a','b','c'}
    };


    Solution m_solution;
    bool result;

    //result = m_solution.containsCycle(grid1);
    //cout << endl << 'has_cycle' << result << endl;
    result = m_solution.containsCycle(grid5);
    cout << endl << "has_cycle" << result << endl;
    //result = m_solution.containsCycle(grid3);
    //cout << endl << 'has_cycle' << result << endl;    
    return 0;
}
