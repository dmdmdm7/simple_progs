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

int kth(std::vector<int> arr, int k){
    int left=0, right=arr.size()-1;
    while (1){
        int m=Partition(arr,left,right);
        if (m==k){
            return arr[k];
        }
        else if (m>k){
            right=m-1;
        }
        else{
            left=m+1;
        }
    }
}

int main(){
    std::vector<int> arr{4,5,8,2};
    std::cout<<kth(arr,2)<<'\n';
    return 0;
}