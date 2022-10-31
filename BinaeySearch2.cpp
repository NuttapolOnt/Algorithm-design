#include<iostream>
#include<vector>

int search(std::vector<int> &v, int left, int right, int k){
    if(left == right) return v[left];
    int mid = (left + right)/2;
    // if(v[mid] <= k && v[mid+1] > k) return v[left];
    // if(v[mid] < k && v[mid+1] >= k) return v[right];
    if(k < v[mid+1]){
        return search(v,left,mid,k);
    }
    return search(v,mid+1,right,k);
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
        int k;
        std::cin >> k;
        if(k < v[0]) std::cout << -1 << "\n";
        else if(k == v[0]) std::cout << v[0] << "\n";
        else if(k >= v[n-1]) std::cout << v[n-1] << "\n"; 
        else std::cout << search(v,0,n-1,k) << "\n"; 
    }
    return 0;
}