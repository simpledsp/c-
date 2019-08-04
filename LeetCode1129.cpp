#define SIMPLEDSP
#include "cheader.h"
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<set<pair<int,string>>> g(n, set<pair<int,string>>());
        for(auto v:red_edges){
            g[v[0]].insert({v[1], "red"});
        }
        for(auto v:blue_edges){
            g[v[0]].insert({v[1], "blue"});
        }
        //a(g)
        vector<int> ret(n, -1);
        ret[0]=0;
        
        set<pair<int,string>> visit;
        visit.insert({0, "na"});
        queue<pair<int,string>> que; 
        que.push({0,"na"});
        //a(que)
        int len=0;
        //a(len)
        //a(ret)
        while (!que.empty()) 
        {
            ++len;
            int k=que.size();
            while(k-->0)
            {
                auto cur = que.front(); que.pop();
                //a(cur)
                //dsp
                for (auto pr : g[cur.first]) {
                    if(cur.second==pr.second){
                        continue;
                    }

                    if(visit.count(pr)!=0)
                        continue;

                    visit.insert(pr);
                    que.push(pr);
                    if(ret[pr.first]==-1){
                        ret[pr.first]=len;
                    }
                    //dsp
                }
            }
        }
        
        return ret;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    //call your function here
    int n=5;
    vector<vector<int>> red={{2,2},{0,1},{0,3},{0,0},{0,4},{2,1},{2,0},{1,4},{3,4}};
    vector<vector<int>> blue={{1,3},{0,0},{0,3},{4,2},{1,0}};
    auto ret = shortestAlternatingPaths(n, red, blue);
    
    return 0;
}            

            
