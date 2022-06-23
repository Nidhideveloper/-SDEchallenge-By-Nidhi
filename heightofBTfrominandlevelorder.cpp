#include<bits/stdc++.h>
typedef struct Node{
    int height;
    int left;
    int right;
}
Node;
int heightOfTheTree(vector<int>& inorder, vector<int>& level, int N){
	// Write your code here.
    queue<Node> q;
    Node node;
    node.height=0;
    node.left=0;
    node.right=N-1;
    q.push(node);
    int pos[N+1];
    for(int i=0;i<N;i++)
    {
        pos[inorder[i]]=i;
    }
    int mx=0;
    for(int i=0; i<N; i++){
        int curr=level[i];
        
        Node cur=q.front();
        q.pop();
        
        int currPos=pos[curr];
        
        //left child Present
        if(currPos>cur.left)
        {
            Node newNode;
            
            newNode.height=cur.height+1;
            mx=max(mx,newNode.height);
            newNode.left=cur.left;
            newNode.right=currPos-1;
            
            q.push(newNode);
        }
        if(currPos<cur.right){
            Node newnode;
            newnode.height=cur.height+1;
            mx=max(mx, newnode.height);
            newnode.left=currPos+1;
            newnode.right=cur.right;
            q.push(newnode);
        }
    }
    return mx;
        
}