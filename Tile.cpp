#include<iostream>
#include<vector>
#include<cmath>

void print(std::vector<std::vector<int>> &v){
    for(std::vector<int> &x : v){
        for(int &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}

int change(int a, int b){
    int ans = a > b ? (a-b)*(a-b) : (b-a)*(b-a);
    return ans;
}


int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<int> s(n+1);
    for(int i = 1; i <= n; i++){
        std::cin >> s[i];
    }
    std::vector<int> v(m+1,-1);
    std::vector<std::vector<int>> table(n+1,v);
    for(int i = 0; i <= n; i++){
        table[i][0] = 0;
    }
    for(int i = 0; i <= m; i++){
        table[0][i] = 0;
    }
    int max = (int)(std::sqrt(m));
    for(int i = 1; i <= max; i++){
        table[1][i*i] = change(s[1],i);
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= max; j++){
            for(int k = 1; k <= m; k++){
                if(table[i-1][k]!= -1 && k+j*j <= m){
                    int tmp = table[i-1][k] + change(s[i],j);
                    if(table[i][k+j*j] == -1){
                        table[i][k+j*j] = tmp;
                    }
                    else if(table[i][k+j*j] > tmp){
                        table[i][k+j*j] = tmp;
                    }
                }
            }
        }
    }
    //print(table);
    std::cout << table[n][m];
}