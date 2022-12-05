#include <iostream>
class Knapsack{
    private:
    int N; //input size
    int W; //max weight
    int maxprofit;
    int numbest;
    int *p;
    int *w;
    int *bestset;
    int *include;
    public:
    Knapsack(int N, int W, int *p, int *w){
        this->N = N;
        this->W = W;
        this->p = p;
        this->w = w;
        this->maxprofit = 0;
        this->bestset = new int[N+1];
        this->include = new int[N+1];
    }
    bool promising(int i, int profit, int weight){
        int j, k;
        int totweight;
        float bound;
        if(weight >= W){
            return false;
        }
        else{
            j = i + 1;
            bound = (float)profit;
            totweight = weight;
            while((j <= N) && (totweight+w[j] <= W)){
                totweight = totweight + w[j];
                bound = bound + p[j];
                j++;
            }
            k=j;
            if(k <= N){
                std::cout<<bound<<"+"<<"("<<W<<"-"<<totweight<<")*"<<p[k]<<"/"<<w[k]<<"="<<bound+(W-totweight)*(float)p[k]/w[k]<<"\n";
                bound = bound+(W-totweight)*(float)p[k]/w[k];

            }
            std::cout<<"bound : "<<bound<<"\n";
            return bound > maxprofit;
        }
    }
    void knapsack(int i, int profit, int weight){
        std::cout<<"knapsack("<<i<<", "<<profit<<", "<<weight<<")\n";
        if((weight <= W) && (profit > maxprofit)){
            maxprofit = profit;
            std::cout<<"maxprofit "<<maxprofit<<"\n";
            numbest = i;
            for(int i=1; i<=N; i++)
                bestset[i]=include[i];
        }
        bool a=promising(i, profit, weight);
        std::cout<<(a?"true":"false")<<"\n\n";
        if(a){
            include[i+1] = 1; //포함
            knapsack(i+1, profit+p[i+1], weight+w[i+1]);
            include[i+1] = 2; //포함하지 않음
            knapsack(i+1, profit, weight);
        }
    }
    void showBestset(){
        for(int i=1; i<=N; i++)
            std::cout<<bestset[i]<<" ";
        std::cout<<"\n";
    }
};

int main(){
    //교재 데이터
    // int p[5]={0, 40, 30, 50, 10};
    // int w[5]={0, 2, 5, 10, 5};
    // Knapsack k = Knapsack(4, 16, p, w);
    //자작 데이터
    int p[5]={0, 50, 60, 75, 90};
    int w[5]={0, 5, 10, 5, 9};
    Knapsack k = Knapsack(4, 20, p, w);
    k.knapsack(0, 0, 0);
    k.showBestset();
}