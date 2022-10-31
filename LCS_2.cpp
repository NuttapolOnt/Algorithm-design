#include<iostream>
#include<vector>

int n,m;
std::string s1,s2;

void print(std::vector<std::vector<int>> &v){
    for(auto &x : v){
        for(auto &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    std::cin >> n>> m;
    std::cin >> s1 >> s2;
    std::vector<std::vector<int>> table(n+1);
    for(int i = 0; i <= n ; i++){
        std::vector<int> tmp(m+1);
        for(int j = 0; j <= m; j++){
            std::cin >> tmp[j];
        }
        table[i] = tmp;
    }
    std::string ans = "";
    for(int i = 1; i <= m; i++){
        if(table[n][i] > table[n][i-1]){
            ans += s2[i-1];
        }
    }
    std::cout << ans << "\n";
    return 0;
}
/*4 5
hero
hello 0 0 0 0 0 0 0 1 1 1 1 1 0 1 2 2 2 2  0 1 2 2 2 2  0 1 2 2 2 3*/