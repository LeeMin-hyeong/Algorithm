#include <iostream>

const int n=6;
struct nodetype{
    int parent;
    int depth;
};
typedef nodetype universe[n];
universe U;

void makeset(int i){
    U[i].parent = i;
    U[i].depth = 0;
}

void merge(int p, int q){
    if(U[p].depth == U[q].depth){
        U[p].depth += 1;
        U[q].parent = p;
    }
    else if(U[p].depth < U[q].depth)
        U[p].parent = q;
    else
        U[q].parent = p;
}

int find(int i){
    int j=i;
    while(U[j].parent != j)
        j=U[j].parent;
    return j;
}

bool equal(int p, int q){
    return p == q;
}

void initial(int n){
    for(int i=1; i <=n-1; i++)
        makeset(i);
}

typedef struct{
    int start;
    int end;
    int weight;
}edge;

int compare(const void *p, const void *q){
    return ((((edge *)p)->weight) > (((edge *)q)->weight)) ? 1 : -1;
}

void kruskal(int n, int m, edge e[], edge f[]){
    int count=0;
    int i;
    int j;
    int p, q;
    edge selectedEdge;
    
    qsort(e, m, sizeof(edge), compare);
    // for(int i=1; i<=m-1; i++)
    //     std::cout<<"(v"<<e[i].start<<", v"<<e[i].end<<") "<<e[i].weight<<"\n";
    // std::cout<<"\n";
    while(count<n-2){
        for(int k=1; k<=m-1; k++){
            if(e[k].weight>0){
                selectedEdge = e[k];
                e[k].weight = 0;
                break;
            }
        }
        i = selectedEdge.start;
        j = selectedEdge.end;
        p = find(i);
        q = find(j);
        if(!equal(p, q)){
            merge(p, q);
            count++;
            f[count]=selectedEdge;
        }
        // for(int k=1; k<=5; k++)
        //     std::cout<<U[k].parent<<" ";
        // std::cout<<"\n";
        // for(int k=1; k<=5; k++)
        //     std::cout<<U[k].depth<<" ";
        // std::cout<<"\n\n";
    }
}

int main(){
    initial(6);
    // edge e[8]={
    //     {0, 0, 0},
    //     {1, 2, 1},
    //     {3, 5, 2},
    //     {1, 3, 3},
    //     {2, 3, 3},
    //     {3, 4, 4},
    //     {4, 5, 5},
    //     {2, 4, 6}
    // };
    edge e[9]={
        {0, 0, 0},
        {1, 2, 4},
        {1, 3, 2},
        {1, 4, 3},
        {2, 3, 3},
        {3, 4, 4},
        {3, 5, 2},
        {4, 5, 1},
        {2, 4, 5}
    };
    edge f[5];
    kruskal(6, 9, e, f);
    for(int i=1; i<=4; i++)
        std::cout<<"(v"<<f[i].start<<", v"<<f[i].end<<") "<<f[i].weight<<"\n";
}
