#include<iostream>
#include<vector>

void print(std::vector<int> &v){
    for(int &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    std::vector<int> table(n);
    for(int i= 0; i < n; i++){
        std::cin >> v[i];
    }
    for(int i = 0; i <= k &&  i < n; i++){
        table[i] = v[i];
    }
    for(int i = k+1; i < n; i++){
        int start = i - (2*k + 1) > 0 ? i - (2*k + 1) : 0;
        table[i] = v[i] + table[start];
        for(int j = start + 1; j <= i; j++){
            if(table[j] + v[i] < table[i]){
                table[i] = table[j] + v[i];
            }
        }
        print(table);
    }
    int ans = table[n-1];
    for(int i = n-2; i >= n-(k+1) && i > 0; i--){
        if(table[i] < ans) ans = table[i];
    }
    std::cout << ans << "\n";
    return 0;
}