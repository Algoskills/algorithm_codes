#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long int i=a;i<n;i++)
#define per(i,a,n) for (long int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<long int> vi;
typedef long long int lli;
const lli mod=1000000007;
lli powmod(lli a,lli b) {lli res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
lli gcd(lli a,lli b) { return b?gcd(b,a%b):a;}

struct node
{
    lli data;
    node *left;
    node *right;
};
node *createNode(lli val)
{
    node *newNode=new node;
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void BST(node *&head,lli val)
{
    node *temp=createNode(val);
    node *curr=head;
    node *parent=NULL;
    while(curr!=NULL)
    {
        parent=curr;
        if(val<=curr->data)
            curr=curr->left;
        else
            curr=curr->right;
    }
    if(val<=parent->data)
        parent->left=temp;
    else
        parent->right=temp;
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    lli n;
    cin>>n;
    node *head;
    rep(i,0,n)
    {
        lli val;
        cin>>val;
        if(i==0)
            head=createNode(val);
        else
            BST(head,val);
    }
    cout<<"inorder"<<endl;
    inorder(head);
    cout<<"preorder"<<endl;
    preorder(head);
    cout<<"postorder"<<endl;
    postorder(head);

}



