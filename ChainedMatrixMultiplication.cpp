#include <iostream>

int minmult(int n, int d[], int p[][7]){
    int i, j, k, diagonal;
    int m[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(i>=j)
                m[i][j]=0;
            else if(i<j)
                m[i][j]=999999;
        }
    for(diagonal=1; diagonal<=n-2; diagonal++){
        for(i=1; i<=n-diagonal-1; i++){
            j=i+diagonal;
            for(k=i; k<=j-1; k++){
                if(m[i][j]>m[i][k]+m[k+1][j]+(d[i-1]*d[k]*d[j])){
                    m[i][j]=m[i][k]+m[k+1][j]+(d[i-1]*d[k]*d[j]);
                    p[i][j]=k;
                }
            }
        }
    }
    return m[1][n-1];
}
void order(int i, int j, int p[7][7]){
    if(i==j)
        std::cout<<"A"<<i;
    else{
        int k=p[i][j];
        std::cout<<"(";
        order(i, k, p);
        order(k+1, j, p);
        std::cout<<")";
    }
}

int main(){
    int d[7]={6, 3, 4, 5, 2, 4, 8}; //유효 인덱스 1~6
    int p[7][7]={0};
    std::cout<<minmult(7, d, p)<<"\n";
    order(1, 6, p); //A1A2A3A4A5A6 최적곱셈
    return 0;
}