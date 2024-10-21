#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if (right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if (largest!=i){
        std::swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(std::vector<int>& arr){
    if (arr.empty()){
        std::cout<<"Empty!"<<'\n';
        return;
    }
    else{
        int n=arr.size();
        for (int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
        for (int i=n-1;i>=0;i--){
            std::swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
}

int main(){
    std::vector<int> arr{31245,5,234,-6,7,-548,6,-59,34,6432,-5,-4216,2,87,-54238,36435};
    for (int& elem: arr){
        std::cout<<elem<<' ';
    }
    std::cout<<'\n';
    heapsort(arr);
    for (int& elem: arr){
        std::cout<<elem<<' ';
    }
    std::cout<<'\n';
    return 0;
}