#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

    vector<int> twoSum(vector<int>& nums, int target){
        map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); ++i){
            mp[nums[i]].push_back(i);            
        }
        //acmap(mp,int, vector<int>) 
        //ac(nums)
        for(int i=0; i<nums.size(); ++i){
            //a(i)
            //dsp
            int tmp=target-nums[i];
            if(mp.find(tmp)!=mp.end()){
                auto vec=mp[tmp];
                for(int j:vec){
                    if(j!=i){
                        return {i, j};
                    }
                }
            }
        }        
        return {};
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    vector<int> nums = {1,2,3,4,5,6};
    int target=10;
    vector<int> ret = twoSum(nums, target);
    //a(ret)
    //dsp
    
    return 0;
}            
