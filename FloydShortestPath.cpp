#include <iostream>
using namespace std;

void floyd(int num, int w[5][5], int d[5][5], int p[5][5]){
    for(int i=0; i<num; i++)
        for(int j=0; j<num; j++)
            p[i][j]=0;
    d=w;
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++)
            for(int k=0; k<num; k++){
                if(d[j][i]+d[i][k]<d[j][k]){
                    p[j][k]=i+1;
                    d[j][k]=d[j][i]+d[i][k];
                }
            }
    }
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++)
            cout<<d[i][j]<<" ";
        cout<<"\n";
    }
}

void path(int n, int m, int p[5][5]){
    if(p[n][m]!=0){
        //정점 시작이 1이므로 배열 인덱스에 맞게 -1
        path(n, p[n][m]-1, p);
        cout<<"v"<<p[n][m]<<" ";
        path(p[n][m]-1, m, p);
    }
}
void fullpath(int n, int m, int p[5][5]){
    cout<<"v"<<n<<" ";
    path(n-1, m-1, p); //정점 시작이 1이므로 배열 인덱스에 맞게 path 호출
    cout<<"v"<<m<<"\n";
}

int main(){
    int w[5][5]={
        {0, 3, 999, 999, 1},
        {2, 0, 5, 1, 999},
        {999, 999, 0, 1, 999},
        {999, 2, 3, 0, 999},
        {999, 2, 999, 5, 0}
    }, d[5][5], p[5][5];
    //정점 v1, v2, v3, v4, v5
    floyd(5, w, d, p);
    fullpath(3, 1, p);
}