vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> st;
        for(int v:to_delete){
            st.insert(v);
        }
        //ahd(root)
        //a(st)
        vector<TreeNode*> ret;        
        queue<pair<TreeNode*, bool>> qu;
        qu.push({root, true});        
        
        map<TreeNode*, TreeNode*> mp;
        //amap(mp,TreeNode*, TreeNode*)
        //a(qu)
        //ahd(ret)
        mp[root]=NULL;
        
        while(qu.size()>0){
            auto pr=qu.front(); qu.pop();
            //a(pr)
            if(!pr.first)
                continue;
            mp[pr.first->left]=pr.first;
            mp[pr.first->right]=pr.first;
            
            if(st.count(pr.first->val)==0){
                if(pr.second){
                    ret.push_back(pr.first);
                }
                qu.push({pr.first->left, false});
                qu.push({pr.first->right, false});
            }
            else{
                TreeNode* parent =mp[pr.first];
                if(parent){
                if(parent->left==pr.first)
                    parent->left=NULL;
                else
                    parent->right=NULL;
                }
                
                qu.push({pr.first->left, true});
                qu.push({pr.first->right, true});
            }
            //dsp
        }
        
        return ret;
    }

///////////////////////////// 测试数据 /////////////////////////////////////
    TreeNode* root ={1,2,3,4,5,6,7} 
    to_delete = {3,5}
