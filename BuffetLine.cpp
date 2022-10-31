#include<iostream>
#include<vector>

int buffet(std::vector<int> &v, int left, int right, int min, int m, int ref){
    if(left == right){
        return left;
    }
    else{
        int mid = (left + right)/2;
        int val = v[mid] - v[ref-1] - ((mid - ref + 1)*m);
        if(val < min){
            return buffet(v,mid+1,right,min,m,ref);
        }
        else{
            return buffet(v,left,mid,min,m,ref);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,k,m;
    std::cin >> n >> k >> m;
    std::vector<int> v(n+1);
    v[0] = 0;
    for(int i = 1; i <= n; i++){
        int a;
        std::cin >> a;
        v[i] = v[i-1] + a;
    }
    for(int i = 0; i < k; i++){
        int start, min;
        std::cin >> start >> min;
        std::cout << buffet(v,start,n,min,m,start) << "\n";
    }
}