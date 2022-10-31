#include<iostream>
#include<vector>


typedef std::vector<std::vector<int>> vv;

vv table;
void print(vv &v){
    for(auto &x : v){
        for(int &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    std::cout << "---------------------------\n";
}

int bino(int n, int k){
    if(n == k || k == 0){
        table[n][k] = 1;
        return 1;
    }
    else if(table[n][k] == 0){
        int a = bino(n-1,k-1) + bino(n-1,k);
        table[n][k] = a;
        return a;
    }
    return table[n][k];
}

int main(){
    int n,k;
    std::cin >> n >> k;
    for(int i = 0; i <= n; i++){
        std::vector<int> a(n+1);
        table.push_back(a);
    }
    std::cout << bino(n,k);
    return 0;
}