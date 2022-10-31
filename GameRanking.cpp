#include<iostream>
#include<vector>

int n,e;

typedef std::vector<std::vector<int>> vv;

int main(){
    std::cin >> n >> e;
    vv g(n);
    for(int i = 0; i < e; i++){
        int a,b;
        std::cin >> a >> b;
        g[a].push_back(b);
    }
}