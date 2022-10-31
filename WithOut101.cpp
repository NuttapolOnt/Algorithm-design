#include<iostream>
#include<vector>

typedef std::vector<std::vector<std::vector<int>>> vvv;

int n;
int m = 100000007;

int mod(int a, int b){
    return ((a%m)+(b%m))%m;
}

int ans(vvv &table, int pos, int value, int state){
    if(pos == n){
        return 1;
    }
    else{
        if(table[pos][state][value] != -1){
            return table[pos][state][value];
        }
        else{
            int tmp = 0;
            if(state == 0){
                tmp = mod(ans(table, pos + 1, 0, 0) , ans(table, pos + 1, 1, 1));
            }
            else if(state == 1){
                tmp = mod(ans(table, pos + 1, 0, 2) , ans(table, pos + 1, 1, 1));
            }
            else if(state == 2){
                tmp = ans(table, pos + 1, 0, 0)%m;
            }
            table[pos][state][value] = tmp;
            return tmp;
        }
    }
}

int main(){
    std::cin >> n;
    std::vector<int> v(2,-1);
    std::vector<std::vector<int>> vv(3,v);
    vvv table(n,vv);
    std::cout << ans(table,0,0,0);
}