//binary search 알고리즘
//정렬은 구현하지 않았음
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int find);

int main(){
    int arr[10]={32, 124, 123, 56, 234, 19023, 54, 0, 2, 89};
    sort(arr, arr+10);
    std::cout<<binarySearch(arr, 10, 89)<<"\n";
}

int binarySearch(int arr[], int n, int find){
    int high=n-1, low=0, mid;
    while(high>=low){
        mid=(high+low)/2;
        if(arr[mid]==find)
            return mid;
        else if(arr[mid]<find)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
