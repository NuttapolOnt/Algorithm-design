#include<iostream>

typedef unsigned long long int llint;

int m = 100000007;

int mod(int a, int b){
    return ((a%m)+(b%m))%m;
}

int main(){
    llint n;
    std::cin >> n;
    int s0 = 1;
    int s1 = 0;
    int s2 = 0;
    std::cout << n <<"\n";
    for(llint i = 1; i <= n; i++){
        int tmp1 = s1;
        s1 = (s0+s1) %m;
        s0 = (s2+s0)%m;
        s2 = tmp1;
        // int tmp0 = s0;
        // int tmp1 = s1;
        // int tmp2 = s2;
        // s0 = mod(tmp0,tmp2);
        // s1 = mod(tmp0 , tmp1);
        // s2 = tmp1%m;
    }
    std::cout << (s0+s1+s2)%m;
}