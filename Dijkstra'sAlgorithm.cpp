#include <iostream>
#define INF 999
#define INPUTSIZE 5

typedef struct{
    int start;
    int end;
}edge;

void dijkstra(int n, int w[][INPUTSIZE+1], edge f[]){
    int i, vnear;
    int touch[n], length[n];
    for(i=2; i<=n-1; i++){
        touch[i]=1;
        length[i]=w[1][i];
    }
    for(int j=0; j<n-2; j++){
        int min=INF;
        for(i=2; i<=n-1; i++){
            if(length[i]>=0 && length[i]<=min){
                min=length[i];
                vnear=i;
            }
        }
        f[j].start=touch[vnear];
        f[j].end=vnear;
        for(i=2; i<=n-1; i++){
            if(length[vnear]+w[vnear][i]<length[i]){
                length[i]=length[vnear]+w[vnear][i];
                touch[i]=vnear;
            }
        }
        length[vnear]=-1;
    }
}

int main(){
    //교재 데이터
    // int w[INPUTSIZE+1][INPUTSIZE+1]={
    //     0,   0,   0,   0,   0,   0,
    //     0,   0,   7,   4,   6,   1,
    //     0, INF,   0, INF, INF, INF,
    //     0, INF,   2,   0,   5, INF,
    //     0, INF,   3, INF,   0, INF,
    //     0, INF, INF, INF,   1,   0 
    // };
    //자작 데이터
    int w[INPUTSIZE+1][INPUTSIZE+1]={
        0,   0,   0,   0,   0,   0,
        0,   0,   3,   6,   5,  10,
        0, INF,   0,   2,   1, INF,
        0, INF, INF,   0, INF,   3,
        0, INF, INF, INF,   0,   4,
        0, INF, INF, INF, INF,   0 
    };
    edge f[INPUTSIZE-1];
    dijkstra(INPUTSIZE+1, w, f);
    for(int i=0; i<INPUTSIZE-1; i++)
        std::cout<<f[i].start<<"->"<<f[i].end<<"\n";
}