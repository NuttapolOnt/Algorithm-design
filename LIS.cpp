#include<iostream>
#include<vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    std::vector<int> table(n);
    int ans = -1;
    for(int i = n-1; i >= 0; i--){
        int max = 0;
        for(int j = i+1; j < n; j++){
            if(v[j] > v[i] && table[j] >= max){
                max = table[j];
            }
        }
        table[i] = max+1;
        if(table[i] > ans){
            ans = table[i];
        }
    }
    std::cout << ans << '\n';
    return 0;
}