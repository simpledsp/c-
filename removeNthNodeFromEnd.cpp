#define SIMPLEDSP
#include "simpledsp.h"
//do not use define or include any header file

    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        //ahd(dummy)
        ListNode* pbf=dummy;
        ListNode* pilot=head;
        //a(pbf)
        //a(pilot)
        //lk(dummy, pbf)
        //lk(dummy, pilot)
        while(n-->1){
            //dsp
            pilot=pilot->next;
        }
        while(pilot->next){
            //dsp
            pbf=pbf->next;
            pilot=pilot->next;
        }
        //dsp
        pbf->next=pbf->next->next;
        //dsp
        return dummy->next;
    }

//main function, do not change function name
int main(int argc, char* argv[])
{   
    ListNode* head=intVecToList({1,2,3,4,5,6,7});    
    ListNode* ret = removeNthFromEnd(head, 2);
    
    return 0;
}            
