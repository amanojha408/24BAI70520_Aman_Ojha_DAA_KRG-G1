
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        
        Node * left;
        Node * right;
        int val;
        
        Node(int x)
        {
            val = x;
            left = NULL;
            right = NULL;
        }
        
};

class Compare
{
    bool op(Node * a, Node * b) 
    {
        return a -> val > b -> val;
    }
};


void preorder(Node* root, vector<string> &ans, string s)
{
    if(root == nullptr) return;
    if(root -> left == nullptr && root -> right == nullptr) {
        ans.push_back(s);
        return;
    }
    preorder(root->left, ans, s + '0');
    preorder(root ->right, ans, s + '1');
}

vector<string> huffman(vector<char> ch, vector<int> freq)
{
    Node* l, *r;
    
    priority_queue <Node *, Compare> pq;
    for(int i = 0; i < ch.size(); i++)
    {
        Node *tmp = new Node(freq[i]);
        pq.push(tmp);
    }
    
    
    while(pq.size() > 1)
    {
        l -> val = pq.top();
        pq.pop();
        
        r -> val = pq.top();
        pq.pop();
        
        Node* newNode = new Node(l -> val + r -> val);
        
        newNode -> left = l;
        newNode -> right = r;
        
        pq.push(newNode); 
        
    }
    
    vector<string> ans;
    preorder(root, ans, "");
    return ans;
}


int main()
{
    string s;
    cin>>s;
    
    unordered_map<char, int> mp;
    
    for(char c : s)
    {
        mp[c]++;
    }
    
    vector<char> ch; 
    vector<int> freq;
    
    for(auto [x, y] : mp)
    {
        ch.push_back(x);
        freq.push_back(y);
    }
    
    vector<string> ans = huffman(ch, freq);
    for(int i = 0; i < ch.size(); i++)
    {
        cout<<ch[i]<<" "<<ans[i]<<endl;
    }
    
    return 0;
}
