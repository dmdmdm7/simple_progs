#include <iostream>
#include <thread>

class Timer{
public:
    Timer(){
        beg=std::chrono::steady_clock::now();
    }
    ~Timer(){
        end=std::chrono::steady_clock::now();
        std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-beg).count()<<'\n';
    }
private:
    std::chrono::steady_clock::time_point beg,end;
};

int main(){
    Timer t;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    return 0;
}