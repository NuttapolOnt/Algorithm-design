#include<iostream>
#include<vector>

typedef unsigned long long int llint;

llint time_to_q(std::vector<llint> &v,llint time){
    llint q = 0;
    for(auto &x : v){
        q += (time / x);
    }
    return q;
}

llint time(std::vector<llint> &v,llint c,llint left,llint right){
    if(left == right){
        return left;
    }
    llint mid = (left+right)/2;
    if(time_to_q(v,mid) < c){
        return time(v,c,mid+1,right);
    }
    return time(v,c,left,mid);
}

int main(){
    llint n,a;
    std::cin >> n >> a;
    std::vector<llint> v(n);
    int min_time = 201;
    for(int i = 0; i < n; i++){
        llint time;
        std::cin >> time;
        if(time < min_time){
            min_time = time;
        }
        v[i] = time;
    }
    for(int i = 0; i < a; i++){
        llint c;
        std::cin >> c;
        if(c < n){
            std::cout << 0 << "\n";
        }
        else{
            std::cout << time(v,c-n,0,min_time*c) << "\n";
        }
    }
    return 0;
}