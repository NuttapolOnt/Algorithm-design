#include<iostream>
#include<vector>



int ch(std::vector<int> &v,std::vector<std::vector<int>> &table, int val, int coin){
    if(v[coin] == 1){
        table[val][coin] = val;
    }
    else if(val % v[coin] == 0){
        table[val][coin] = val/v[coin];
        return table[val][coin];
    }
    if(table[val][coin] != -1){
        return table[val][coin];
    }
    else{
        int k = val / v[coin];
        int min = 100000000;
        for(int i = 0; i <= k; i++){
            int tmp = ch(v,table,val - (i*v[coin]),coin+1) + i;
            if(tmp < min) min = tmp;
        }
        table[val][coin] = min;
        return min;
    }
}

int main(){
    int n,m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for(int i = 0;i < n; i++){
        std::cin >> v[i];
    }
    std::vector<std::vector<int>> table(m+1);
    for(int i = 0; i <= m; i++){
        std::vector<int> v(n,-1);
        table[i] = v;
    }
    std::cout << ch(v,table,m,0);
}