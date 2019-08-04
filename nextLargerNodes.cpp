#define SIMPLEDSP
#include "cheader.h"
//do not use define or include any header file

    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> stk;
        vector<int> ret;
        ListNode* p=head;
        //ahd(head)
        //a(p)
        //lk(head,p)
        //a(stk)
        //a(ret)
        int i=0;
        while(p){
            ret.push_back(0);   
            //dsp
            while(stk.size()>0){                
                auto pr=stk.top();
                if(pr.second<p->val){
                    ret[pr.first]=p->val;
                    stk.pop();
                }
                else
                    break;
            }        
            //dsp
            stk.push({i, p->val});
            ++i;
            p=p->next;
        }
        
        return ret;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{
    ListNode* head=intVecToList({2,1,5});
    vector<int> ret=nextLargerNodes(head);
    
    return 0;
}            
