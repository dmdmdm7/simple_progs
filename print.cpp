#include <iostream>
#include <vector>

void printI(int summa, std::vector<int>& arr){
    if (!summa){
        for (int i=0;i<arr.size();i++){
            std::cout<<arr[i]<<'\t';
        }
        std::cout<<'\n';
        return;
    }
    for (int i=1;i<=summa;i++){
        if (arr.empty() || arr.back()<=i){
            arr.push_back(i);
            printI(summa-i,arr);
            arr.pop_back();
        }
    }
}

void print(int summa){
    std::vector<int> arr;
    printI(summa,arr);
}

int main(){
    print(5);
    return 0;
}