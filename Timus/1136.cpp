#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector < int > vi;

class node {
public:
    node *left,*right;
    int val;
    node() {
        val = -1;
        left = NULL;
        right = NULL;
    }
    node(int x) {
        val = x;
        left = right = NULL;
    }
};

int n;
vi v;

void print(node *root) {
    if(root->right != NULL)
        print(root->right);
    if(root->left != NULL)
        print(root->left);
    cout << root->val << endl;
}

void traverse(node *root , int val) {

    if(val < root->val) {
        if(root->left == NULL) {
            node *child = new node(val);
            root->left = child;
        }
        else
            traverse(root->left , val);
    }
    else {
        if(root->right == NULL) {
            node *child = new node(val);
            root->right = child;
        }
        else
            traverse(root->right , val);
    }
}

void dbg(node *root) {
    cout << "node :" << root->val << endl;
    if(root->left != NULL)
        cout << "Left child: " << root->left->val << endl;
    if(root->right != NULL)
        cout << "Right child : " << root->right->val << endl;
    cout << endl;
    if(root->left != NULL)
        dbg(root->left);
    if(root->right != NULL)
        dbg(root->right);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int x;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> x;
        v.pb(x);
    }

    reverse(v.begin() , v.end());

    node *root = new node(v[0]);

    for(int i = 1; i < n; ++i)
        traverse(root , v[i] );
  //  dbg(root);
    print(root);

    return 0;
}
