#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class Compare 
{
    public:
        bool operator() (Node *a, Node *b)
        {
            return a -> data > b -> data;
        }
};


void preorder(Node* root, vector<string> &ans, string curr)
{
    if(root == nullptr) return;
    if(root -> left == nullptr && root -> right == nullptr)
    {
        ans.push_back(curr);
        return;
    }

    preorder(root->left, ans, curr + '0');
    preorder(root->right, ans, curr + '1');
    
}

vector<string> huffman(vector<char> ch, vector<int> freq)
{
    int n = ch.size();
    priority_queue <Node *, vector<Node*>, Compare> pq;
    for(int i = 0; i < n; i++)
    {
        Node *tmp = new Node(freq[i]);
        pq.push(tmp);
    }

    while(pq.size() > 1)
    {
        Node *l = pq.top();
        pq.pop();

        Node *r = pq.top();
        pq.pop();

        Node * newNode = new Node (l -> data + r -> data);
        newNode -> left = l;
        newNode -> right = r;

        pq.push(newNode);
    }

    Node * root = pq.top();
    vector<string> ans;
    preorder(root, ans, "");
    return ans;
}


int main()
{
    int n;
    cout<<"Enter the number of characters: ";
    cin>>n;

    vector<char> ch(n);
    cout<<"Enter the characters: ";
    for(int i = 0; i < n; i++)
    {
        cin>>ch[i];
    }

    cout<<"Enter the frequencies of the repective characters: ";
    vector<int> freq(n);
    for(int i = 0; i < n; i++)
    {
        cin>>freq[i];
    }

    vector<string> ans = huffman(ch, freq);

    for(int i = 0; i < n; i++)
    {
        cout<<ch[i]<<" "<<ans[i]<<endl;
    }

    return 0;
}
