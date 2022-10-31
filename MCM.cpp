#include<iostream>
#include<vector>

void print(std::vector<std::vector<int>> &v){
    for(std::vector<int> &x : v){
        for(int &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    std::cout << "--------------------" << "\n";
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n+1);
    for(int i = 0; i <= n; i++){
        std::cin >> v[i];
    }
    std::vector<int> tmp(n);
    std::vector<std::vector<int>> table(n,tmp);
    for(int i = 0; i < n-1; i++){
        table[i][i+1] = v[i] * v[i+1] * v[i+2];
    }
    for(int i = 2; i < n; i++){
        for(int j = 0; j < n-i; j++){
            int min = table[j][j] + table[j+1][j+i] + v[j]*v[j+1]*v[j+i+1];
            for(int k = 0; k < i; k++){
                int tmp = table[j][j+k] + table[j+1+k][j+i] + v[j]*v[j+k+1]*v[j+i+1];
                //std::cout << tmp << "\n";
                if(tmp < min) {
                    min = tmp;
                }
            }
            //std::cout << "\n";
            table[j][j+i] = min;
            //print(table);
        }
    }
    std::cout << table[0][n-1];
}