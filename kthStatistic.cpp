#include <iostream>
#include <vector>

int Partition(std::vector<int>& arr, int left, int right){
    if (left!=right){
        std::swap(arr[left+rand()%(right-left+1)],arr[right]);
    }
    int x=arr[right];
    int j=left-1;
    for (int i=left;i<=right;i++){
        if (arr[i]<=x){
            std::swap(arr[++j],arr[i]);
        }
    }
    return j;
}

void kth(std::vector<int> arr, int k){
    int n = arr.size(), left = 0, right = n-1, t = n-k;
    if (k <= 0 || k > n) return;
    while (1){
        int m=Partition(arr,left,right);
        if (m == t){
            for (int i=t; i<n; i++){
                std::cout<<arr[i]<<' ';
            }
            std::cout<<'\n';
            return;
        }
        else if (m>t){
            right=m-1;
        }
        else{
            left=m+1;
        }
    }
}

int main(){
    std::vector<int> arr{1,6,9,3,2,5,4,8,7};
    for (int i=1; i<=arr.size(); i++){
        std::cout<<"\""<<i<<"\" наибольших элементов массива:\n";
        kth(arr,i);
    }
    return 0;
}