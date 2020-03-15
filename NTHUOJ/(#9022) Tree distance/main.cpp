#include<iostream>
#include<vector>

using namespace std;

struct node{
    int val;
    int level;
    node* parent;
};

int FindDis(node* a, node *b)
{
    if(a->val==b->val) return 0;
    if(a->level > b->level) return 1+FindDis(a->parent,b);
    else return 1+FindDis(a,b->parent);
}

int main()
{
    int N, cnt=1;
    while(cin>>N)
    {
        vector<node*> handle;
        handle.push_back(NULL);
        node *root;
        for(int i=1 ; i<=N ; i++)
        {
            node *e = new node();
            e->val = i;
            e->parent = NULL;
            handle.push_back(e);
        }
        for(int i=1 ; i<=N ; i++)
        {
            int par;
            cin >> par;
            if(par==-1) root = handle[i];
            else handle[i]->parent = handle[par];
        }
        for(int i=1 ; i<=N ; i++)
        {
            node *curr = handle[i];
            int level = 0;
            while(curr!=NULL)
            {
                level++;
                curr = curr->parent;
            }
            handle[i]->level = level;
        }
        int n,m;
        cout << "Case " << cnt << ":";
        while(cin>>n>>m)
        {
            if(n==0 && m==0) break;
            cout << " " << FindDis(handle[n],handle[m]);
        }
        cout << endl;
        cnt++;
    }
    return 0;
}