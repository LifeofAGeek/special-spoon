void dfs(Tree* root, Tree*& first, Tree*& second, Tree*& prev) {
    if (!root) return;

    dfs(root->left,first,second,prev);

    if(prev and prev->val>=root->val){
        if(!first) first=prev;
        second=root;
    }
    prev=root;

    dfs(root->right,first,second,prev);
}

Tree* solve(Tree* root) {
    Tree *first=NULL, *second=NULL, *prev=NULL;
    dfs(root,first,second,prev);
    swap(first->val,second->val);
    return root;
}
