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

////////////////////////// 测试数据 /////////////////////////////////////
    bookings ={{1,2,10},{2,3,20},{2,5,25}}
    n=5
