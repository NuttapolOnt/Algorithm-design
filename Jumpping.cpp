#include<iostream>
#include<vector>

void jump(std::vector<int> &v, std::vector<int> &table, int pos, int n){
    if(pos == n){
        return;
    }
    else{
        int max = table[pos-3];
        for(int i = 2; i >= 1; i--){
            if(table[pos-i] > max){
                max = table[pos-i];
            }
        }
        table[pos] = max + v[pos];
        jump(v,table,pos+1,n);
    }
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    std::vector<int> table(n,-1);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    table[0] = v[0];
    table[1] = v[0] + v[1];
    table[2] = table[1] > table[0] ? table[1] + v[2] : table[0] + v[2];
    jump(v,table,3,n);
    std::cout << table[n-1] << "\n";
}