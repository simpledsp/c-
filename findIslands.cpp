#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

//add your functions here
    void dfs(vector<vector<int>>& M, int rows, int cols, int x, int y, set<pair<int,int>>& visited, vector<pair<int,int>>& move){
        for(auto pair:move){
            int nxtX=pair.first+x;
            int nxtY=pair.second+y;
            if(nxtX>=0 && nxtX<cols && nxtY>=0 && nxtY<rows && M[nxtY][nxtX]==1 && visited.count({nxtX, nxtY})==0){
                visited.insert({nxtX, nxtY});
                //dsp
                dfs(M, rows, cols, nxtX, nxtY, visited, move);
            }
        }
    }
    
    int findIslands(vector<vector<int>>& M) {
        set<pair<int,int>> visited;
        vector<pair<int,int>> move={{-1,0}, {1,0},{0,-1},{0,1}};
        int rows=M.size();
        int cols=M[0].size();
        //a(visited)
        //lk(M, visited)
        int ret=0;
        for(int i=0; i<rows; ++i)
            for(int j=0; j<cols; ++j){
                if(M[i][j]==1 && visited.count({j, i})==0){
                    ++ret;
                    visited.insert({j,i});
                    //dsp
                    dfs(M, rows, cols, j, i, visited, move);
                }
            }
        
        return ret;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    //call your function here
    vector<vector<int>> map={{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    //a(map)
    int ret = findIslands(map);
    //a(ret)
    //dsp
    return 0;
}            
