#include<iostream>
#include<vector>

typedef std::vector<std::vector<std::vector<int>>> vvv;

vvv table;
int N,M,K;

int barcode(int n, int m, int k){
    if(n == N){
        if(k == K){
            return 1;
        }
        return 0;
    }
    int ans = 0;
    if(table[n][m][k] != -1){
        return table[n][m][k];
    }
    else{
        if(k < K){
            int a = barcode(n+1,0,k+1);
            ans += a;
        }
        if(m+1 < M){
            int b = barcode(n+1,m+1,k);
            ans += b;
        }
        table[n][m][k] = ans;
    }
    return ans;
}

int main(){
    std::cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        std::vector<std::vector<int>> vv;
        for(int j = 0; j < M; j++){
            std::vector<int> v(K+1,-1);
            vv.push_back(v);
        }
        table.push_back(vv);
    }
    std::cout << barcode(1,0,0) << "\n";
}