#include<iostream>
#include<vector>

int n;
std::vector<int> v(3);

int cut(std::vector<int> &table, int val){
    if(val == 0) return 0;
    else if(val < 0) return -2;
    else{
        if(table[val] != -1){
            return table[val];
        }
        else{
            int max = -2;
            for(int i = 0; i < 3; i++){
                int tmp = cut(table,val - v[i]);
                if(tmp > max){
                    max = tmp;
                }
            }
            if(max != -2){
                table[val] = max+1;
                return max+1;
            }
            else{
                table[val] = -2;
                return -2;
            }
        }
    }
}

int main(){
    std::cin >> n >> v[0] >> v[1] >> v[2];
    std::vector<int> table(n+1,-1);
    std::cout << cut(table, n) << "\n" ;
    return 0;
}