#include<iostream>
#include<vector>

void print(std::vector<std::vector<int>> &table){
    for(std::vector<int> &x : table){
        for(int &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int n,k;
    std::cin >> n >> k;
    std::vector<int> v(n+1);
    std::vector<int> w(n+1);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
    }
    for(int i = 1; i <= n; i++){
        std::cin >> w[i];
    }
    std::vector<std::vector<int>> table(n+1);
    for(int i = 0; i <= n; i++){
        std::vector<int> tmp(k+1);
        for(int j = 0; j <= k; j++){
            std::cin >> tmp[j];
        }
        table[i] = tmp;
    }
    //print(table);
    std::vector<int> ans;
    int j = k;
    for(int i = n; i > 0; i--){
        if(j == 0) break;
        if(j >= w[i]){
            if(table[i-1][j-w[i]] == table[i][j] - v[i]){
                //std::cout << "work\n";
                ans.push_back(i);
                j -= w[i];
            }
        }  
    }
    std::cout << ans.size() << "\n";
    for(int &x : ans){
        std::cout << x << " ";
    }
    std::cout << "\n";
}
/*5 5
3 10 6 3 5 
5 5 3 1 1
0 0 0 0 0 0
0 0 0 0 0 3
0 0 0 0 0 10
0 0 0 6 6 10
0 3 3 6 9 10
0 5 8 8 11 14*/
