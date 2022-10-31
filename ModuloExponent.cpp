#include<iostream>

int mod(int x,int n,int k){
    if(n == 1){
        return x%k;
    }
    else if(n%2 == 0){
        int tmp = mod(x,n/2,k);
        return (tmp*tmp)%k;
    }
    int tmp1 = mod(x,n/2,k);
    tmp1 = (tmp1*tmp1)%k;
    int tmp2 = x%k;
    return (tmp1*tmp2)%k;
}

int main(){
    int x,n,k;
    std::cin >> x >> n >> k;
    std::cout << mod(x,n,k) << std::endl;
    return 0;
}