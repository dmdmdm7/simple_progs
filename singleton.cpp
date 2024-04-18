#include <iostream>

class Singleton{
private:
    inline static Singleton* inst=nullptr;
    Singleton(){};
    ~Singleton(){};
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
public:
    static Singleton* get_inst(int x){
        if (!inst){
            inst=new Singleton;
            inst->x=x;
        }
        return inst;
    }
    void del(){
        if (inst){
            std::cout<<"Delete Singleton\n";
            delete inst;
            inst=nullptr;
        }
        else{
            std::cout<<"No Singleton\n";
        }
    }
    int x;
};

class MSingleton{
private:
    MSingleton(){};
    ~MSingleton(){};
    MSingleton(const MSingleton&) = delete;
    MSingleton& operator = (const MSingleton&) = delete;
public:
    static MSingleton* get_inst(){
        static MSingleton inst;
        return &inst;
    }
};

int main(){
    Singleton* fst=Singleton::get_inst(5);
    Singleton* snd=Singleton::get_inst(10);
    std::cout<<fst->x<<'\n';
    std::cout<<snd->x<<'\n';
    snd->x=3;
    std::cout<<fst->x<<'\n';
    std::cout<<snd->x<<'\n';
    fst->del();
    snd->del();

    MSingleton* fstM=MSingleton::get_inst();
    std::cout<<fstM<<'\n';
    MSingleton* sndM=MSingleton::get_inst();
    std::cout<<sndM<<'\n';
}