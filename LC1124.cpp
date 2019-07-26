#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

//add your functions here
int longestWPI(const vector<int>& hours) {
        int n=hours.size();
        //ac(hours)
        vector<int> bin(n+1,0);
        for(int i=1; i<n+1; ++i){
            if(hours[i-1]>8)
                bin[i]=1;
            else
                bin[i]=-1;
        }
        //ac(bin)
        //dsp
        
        for(int i=1; i<n+1; ++i){
            bin[i]+=bin[i-1];
        }
        
        int L=0;
        //ac(L)
        for(int i=0; i<n; ++i){
            for(int j=n; j>=i+L; --j){
                //a(i)
                //a(j)
                //dsp
                if(bin[j]-bin[i]>0){
                    L=j-i;
                    //dsp
                    break;
                }                     
            }
        }
        
        return L;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    //call your function here
    int ret=longestWPI({9,9,6,0,6,6,9});
    return 0;
}            

            
