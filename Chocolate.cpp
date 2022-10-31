#include<iostream>
#include<vector>

typedef long llint;

llint choc(std::vector<int> &s, std::vector<llint> &table, int val){
    if(val == 0){
        return 1;
    }
    else if(val < 0){
        return 0;
    }
    else{
        if(table[val] != -1){
            return table[val];
        }
        else{
            llint count = 0;
            for(int i = s.size()-1; i >= 0; i--){
                count = (count + choc(s,table,val-s[i]) % 1000003) % 1000003;
            }
            table[val] = count;
            return count;
        }
    }
}

int main(){ 
    int n,k;
    std::cin >> n >> k;
    std::vector<int> s(k);
    for(int i = 0; i < k; i++){
        std::cin >> s[i];
    }
    std::vector<llint> table(n+1,-1);
    std::cout << choc(s,table,n) % 1000003 << "\n";
    return 0;
}


