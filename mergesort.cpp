#include <iostream>
#include <vector>

void mergesortImpl(std::vector<int>& arr, std::vector<int>& buffer, int left, int right){
    if (left<right){
        int m=(left+right)/2;
        mergesortImpl(arr,buffer,left,m);
        mergesortImpl(arr,buffer,m+1,right);
        int k=left;
        for (int i=left, j=m+1;i<=m || j<=right;){
            if (j>right || i<=m && arr[i]<arr[j]){
                buffer[k]=arr[i];
                i++;
            }
            else{
                buffer[k]=arr[j];
                j++;
            }
            k++;
        }
        for (int i=left;i<=right;i++){
            arr[i]=buffer[i];
        }
    }
}

void mergesort(std::vector<int>& arr){
    if (arr.empty()){
        std::cout<<"Empty!"<<'\n';
        return;
    }
    else{
        std::vector<int> buffer(arr.size());
        mergesortImpl(arr,buffer,0,arr.size()-1);
    }
}

int main(){
    std::vector<int> arr{31245,5,234,-6,7,-548,6,-59,34,6432,-5,-4216,2,87,-54238,36435};
    for (int& elem: arr){
        std::cout<<elem<<' ';
    }
    std::cout<<'\n';
    mergesort(arr);
    for (int& elem: arr){
        std::cout<<elem<<' ';
    }
    std::cout<<'\n';
    return 0;
}