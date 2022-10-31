#include<iostream>
#include<vector>


int search(std::vector<int> &v, int left, int right, int x){
    if(left == right) return left;
    int mid = (left + right)/2;
    if((v[mid] <= x) && (v[mid+1] > x)) return mid;
    if(v[mid] < x){
        return search(v,mid+1,right,x);
    }
    return search(v,left,mid,x);
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    for(int i = 0; i < m; i++){
        int x;
        std::cin >> x;
        if(v[0] > x){
            std::cout << -1 << "\n";
        }
        else if(v[n-1] < x){
            std::cout << n-1 << "\n";
        }
        else{
            std:: cout << search(v,0,n-1,x) << "\n";
        }
    }
    return 0;
}