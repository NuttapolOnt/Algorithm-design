#include<iostream>
#include<vector>
#include<algorithm>

void ms(std::vector<int> &v,int left, int right, int &c,int k){
    if(k == 1){
        return;
    }
    else if(left+2 == right){
        std::swap(v[left],v[right-1]);
    }
    else if(left+1 == right){
        return;
    }
    else if(c == k){
        reverse(v.begin()+left,v.begin()+right);
        return;
    }
    else{
        int mid = (left+right)/2;
        c+=1;
        ms(v,left,mid,c,k);
        c+=1;
        ms(v,mid,right,c,k);
    }
    return;
}

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = i+1;
    }
    int c = 1;
    ms(v,0,n,c,k);
    if(c < k){
        std::cout << "-1";
    }
    else{
        for(int i = 0; i < n; i++){
            std::cout << v[i] << " ";
        }
    }
}