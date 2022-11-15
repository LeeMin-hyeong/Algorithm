#include <iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
};

float sum(int start, int end, float p[]){
    float sum=0;
    for(int i=start; i<=end; i++)
        sum+=p[i];
    return sum;
}

void optsearchtree(int n, float p[], float *minavg, int r[][5]){
    int i, j, k, diagonal;
    float a[n+1][n];

    for(i=1; i<=n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                a[i][j]=p[i];
                r[i][j]=i;
            }
            else{
                a[i][j]=0;
                r[i][j]=0;
            }
        }
    }

    for(diagonal=1; diagonal<=n-2; diagonal++){
        for(i=1; i<=n-diagonal-1; i++){
            j=i+diagonal;
            float min=99;
            for(k=i; k<=j; k++){
                if(min>a[i][k-1]+a[k+1][j]){
                    min=a[i][k-1]+a[k+1][j];
                    r[i][j]=k;
                }
            }
            a[i][j]=min+sum(i, j, p);
        }
        *minavg=a[1][n-1];
    }

    for(i=1; i<=n; i++){
        for(int j=0; j<n; j++){
            printf("%7f ", a[i][j]);
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(i=1; i<=n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", r[i][j]);
        }
        cout<<"\n";
    }
    cout<<"\n";
}

struct Node *tree(int i, int j, int r[][5]){
    int k;
    struct Node *p;
    k=r[i][j];
    if(k==0)
        return NULL;
    else{
        p=new Node;
        p->key=k;
        p->left=tree(i, k-1, r);
        p->right=tree(k+1, j, r);
    }
    return p;
}

//Pre order
void print_tree(struct Node *root){
    cout<<root->key<<" ";
    if(root->left!=NULL)
        print_tree(root->left);
    if(root->right!=NULL)
        print_tree(root->right);
}

int main(){
    float p[5]={0, 3.0/8, 3.0/8, 1.0/8, 1.0/8};
    int r[6][5];
    float *minavg;
    optsearchtree(5, p, minavg, r);
    print_tree(tree(1, 4, r));
}