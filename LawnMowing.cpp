#include<iostream>
#include<vector>

typedef long long llint;

llint ans(std::vector<llint> &v, llint left,llint right, llint k, llint budget, llint start){
    if(left == right){
        llint price = (v[left]-v[start-1]) + ((left - start+1)*k);
        if(left == start){
            if(price > budget){
                return 0;
            }
            else{
                return (v[left] - v[start-1]);
            }
        }
        return (v[left] - v[start-1]);
    }
    llint mid = (right + left)/2;
    llint price = (v[mid+1]-v[start-1]) + ((mid+1- start+1)*k);
    //std::cout << mid+1  << " " << price << "\n";
    if(price > budget){
        return ans(v,left,mid,k,budget,start);
    }
    return ans(v,mid+1,right,k,budget,start);
}

int main(){
    std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    llint n,m,k;
    std::cin >> n >> m >> k;
    std::vector<llint> v(n+1);
    v[0] = 0;
    for(int i = 1; i < n+1; i++){
        llint c;
        std::cin >> c;
        v[i] = c+v[i-1];
    }
    for(int i = 0; i < m; i++){
       llint a;
       llint b;
       std::cin >> a >> b;
       std::cout << ans(v,a+1,n,k,b,a+1) << "\n";
    }
    return 0;
}