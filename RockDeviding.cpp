#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> vv;

int m = 1997;

void print(vv &table){
    for(std::vector<int> &x : table){
        for(int &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}


int modsum(int a, int b){
    return ((a%m)+(b%m))%m;
}

int modmul(int a, int b){
    return ((a%m)*(b%m))%m;
}

int main(){
    int n,k;
    std::cin >> n>> k;
    std::vector<int> v(k+1);
    vv table(n+1,v);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k && j <= i; j++){
            if(j == 1 || j == i){
                table[i][j] = 1;
            }
            else{
                table[i][j] = modsum(table[i-1][j-1] , modmul(table[i-1][j],j));
            }
        }
    }
    std::cout << table[n][k] << "\n";
    return 0;
}