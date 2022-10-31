#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> vv;
typedef unsigned long long int llint;

int n,k,p;

void print(std::vector<llint> &v){
    for(llint &x : v){
        std::cout << x << " ";
    }
    std::cout << "\n";
}

std::vector<llint> ans(vv & g){
    std::vector<llint> table(k);
    for(int i = 1; i < k; i++){
        table[i] = table[i-1] + g[i-1][1];
    }
    for(int i = k-1; i >= 0; i--){
        std::cout << "wotk\n";
        llint tmp  = table[(i+1)%k] + g[(i+1)%k][0];
        if(tmp <= table[i]){
            table[i] = tmp;
        }
        else{
            break;
        }
    }
    return table;
}

int main(){
    std::cin >> n >> k >> p;
    std::vector<int> gtmp(5);
    vv g(k,gtmp);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 5; j++){
            std::cin >> g[i][j];
        }
    }
    std::vector<llint> v = ans(g);
    print(v);
}
/*4 3 1
99 99 1 99 10 99 99 99 99 3 99 2 99 5 99*/