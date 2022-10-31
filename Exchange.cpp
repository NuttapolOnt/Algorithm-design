#include<iostream>
#include<vector>
#include<queue>

typedef std::vector<std::vector<double>> vv;
typedef std::vector<std::vector<bool>> vb;

bool check(vv &g, int n){
    std::vector<double> val(n,-1.0);
    val[0] = 1;
    for(int i = 0; i <= n; i++){
        bool state = true;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(j != k){
                    if(val[j] * g[j][k] > val[k]){
                        val[k] = val[j] * g[j][k];
                        state = false;
                    }
                }
            }
        }
        if(state){
           return false;
        }
    }
    return true;
}

int main(){
    int m;
    std::cin >> m;
    for(int i = 0; i < m; i++){
        int n;
        std::cin >> n;
        std::vector<double> gtmp(n);
        vv g(n,gtmp);
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                std::cin >> g[j][k];
            }
        }
        if(check(g,n)){
            std::cout << "YES\n";
        }
        else{
            std::cout << "NO\n";
        }
    }
}