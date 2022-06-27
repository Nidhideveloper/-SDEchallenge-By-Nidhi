void dfs(graphNode* node, graphNode* cp, vector<graphNode*> &vis){
    vis[cp->data]=cp;
    for(auto it:node->neighbours){
        if(vis[it->data]==NULL){
            graphNode *newnode = new graphNode(it->data);
            (cp->neighbours).push_back(newnode);
            dfs(it, newnode, vis);
        }
        else{
            (cp->neighbours).push_back(vis[it->data]);
        }
    }
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    vector<graphNode*> vis(100001, NULL);
    if(node==NULL) return node;
    graphNode* cp=new graphNode(node->data);
    dfs(node, cp, vis);
    return cp;
}