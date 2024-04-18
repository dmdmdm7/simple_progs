#include <iostream>

std::string multiply(std::string num1, std::string num2){
    std::string sum(num1.size()+num2.size(),'0');
    for (int i=num1.size()-1;i>=0;i--){
        int carry=0;
        for (int j=num2.size()-1;j>=0;j--){
            int temp=(sum[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry;
            sum[i+j+1]=temp%10+'0';
            carry=temp/10;
        }
        sum[i]+=carry;
    }
    size_t pos=sum.find_first_not_of("0");
    if (pos!=std::string::npos){
        return sum.substr(pos);
    }
    return "0";
}

int main(){
    std::cout<<multiply("123","456")<<'\n';
    return 0;
}