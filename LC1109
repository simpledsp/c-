#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

//add your functions here
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ret(n,0);
        if(bookings.size()==0)
            return ret;
                  
        map<int,int> mp;        
        //amap(mp,int,int)
        for(auto bk:bookings){
            mp[bk[0]]+=bk[2];
            mp[bk[1]+1]-=bk[2];
        }
        
        ret[0]=mp[1];
        for(int i=1; i<n; ++i){
            ret[i]=ret[i-1]+mp[i+1];
        }
        
        //a(ret)
        //dsp
        return ret;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    //call your function here
    vector<vector<int>> bookings ={{1,2,10},{2,3,20},{2,5,25}};
    //a(bookings)
    vector<int> ret = corpFlightBookings(bookings, 5);
    return 0;
}            
