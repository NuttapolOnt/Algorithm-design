#include<iostream>
#include<vector>

void print(std::vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int ans(std::vector<int> &value, std::vector<int> &table, int pos, int n){
    if(pos == n){
        return table[n-1] > table[n-2] ? table[n-1] : table[n-2];
    }
    int last0 = table[pos-2] + value[pos];
    int last1 = table[pos-1];
    table[pos] = last0 > last1 ? last0 : last1;
    //print(table);
    return ans(value,table,pos+1,n);
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> value(n);
    for(int i = 0; i < n; i++){
        std::cin >> value[i];
    }
    std::vector<int> table(n);
    table[0] = value[0];
    table[1] = value[0] > value[1] ? value[0] : value[1];
    std::cout << ans(value,table,2,n);
    return 0;
}