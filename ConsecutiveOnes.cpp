#include<iostream>
#include<vector>

void print(std::vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i];
    }
    std::cout << std::endl;
}

void ans(std::vector<int> &v, int pos, int k, int n){
    if(pos == n){
        int count = 0;
        int state = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == 0){
                count = 0;
            }
            else{
                count += 1;
            }
            if(count >= k){
                print(v);
                break;
            }
        }
        return;
    }
    v[pos] = 0; ans(v,pos+1,k,n);
    v[pos] = 1; ans(v,pos+1,k,n);
}

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    ans(v,0,k,n);
    return 0;
}