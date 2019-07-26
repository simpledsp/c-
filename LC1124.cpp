    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        vector<int> bin(n+1,0);
        for(int i=1; i<n+1; ++i){
            if(hours[i-1]>8)
                bin[i]=1;
            else
                bin[i]=-1;
        }
        
        for(int i=1; i<n+1; ++i){
            bin[i]+=bin[i-1];
        }
        
        int L=0;
        for(int i=0; i<n; ++i){
            for(int j=n; j>=i+L; --j){
                if(bin[j]-bin[i]>0){
                    L=j-i;
                    break;
                }                     
            }
        }
        
        return L;
    }
