#include<iostream>
#include<vector>

void print(std::vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i];
    }
    std::cout << "\n";
}

void ans(std::vector<int> &v, int pos, int k, int size, int count0, int count1){
    if(pos == size){
        print(v);
        return;
    }
    if(count1 < k){
        if(count0 < (size-k)){
            v[pos] = 0; ans(v,pos+1,k,size,count0+1,count1);
            v[pos] = 1; ans(v,pos+1,k,size,count0,count1+1);
        }
        else{
            v[pos] = 1; ans(v,pos+1,k,size,count0,count1+1);
        }
    }
    else{
        v[pos] = 0; ans(v,pos+1,k,size,count0+1,count1);
    }
}

int main(){

    int n,k;
    std::cin >> k >> n;
    std::vector<int> v(n);
    ans(v,0,k,n,0,0);
    return 0;
}