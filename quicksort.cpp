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

void quicksortImpl(std::vector<int>& arr, int left, int right){
    if (left<right){
        int m=Partition(arr,left,right);
        quicksortImpl(arr,left,m-1);
        quicksortImpl(arr,m+1,right);
    }
}

void quicksort(std::vector<int>& arr){
    if (arr.empty()){
        std::cout<<"Empty!"<<'\n';
        return;
    }
    else{
        quicksortImpl(arr,0,arr.size()-1);
    }
}

int main(){
    std::vector<int> arr{31245,5,234,-6,7,-548,6,-59,34,6432,-5,-4216,2,87,-54238,36435};
    for (int& elem: arr){
        std::cout<<elem<<' ';
    }
    std::cout<<'\n';
    quicksort(arr);
    for (int& elem: arr){
        std::cout<<elem<<' ';
    }
    std::cout<<'\n';
    return 0;
}