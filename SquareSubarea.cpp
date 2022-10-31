#include<iostream>
#include<vector>

std::vector<std::vector<int>> table;
int r,c;
int max = 0;

void print(std::vector<std::string> &v){
    for(auto &x : v){
        std::cout << x << "\n";
    }
}

int square(std::vector<std::string> &v, int y, int x){
    if(y == r || x == c){
        return 0;
    }
    if(table[y][x] != -1){
        return table[y][x];
    }
    else{
        if(v[y][x] == '0'){
            table[y][x] = 0;
            square(v,y+1,x);
            square(v,y,x+1);
            square(v,y+1,x+1);
            return 0;
        }
        else{
            int r = square(v,y,x+1);
            int b = square(v,y+1,x);
            int rb = square(v,y+1,x+1);
            int min;
            if(r < b){
                if(r < rb){
                    min = r;
                }
                else{
                    min = rb;
                }
            }
            else{
                if(b < rb){
                    min = b;
                }
                else{
                    min = rb;
                }
            }
            if(min+1 > max){
                max = min+1;
            }
            table[y][x] = min+1;
            return min + 1;
        }
    }
}

int main(){
    std::cin >> r >> c;
    std::vector<std::string> v(r);
    for(int i = 0; i < r; i++){
        std::cin >> v[i];
    }
    for(int i = 0; i < r; i++){
        std::vector<int> tmp(c,-1);
        table.push_back(tmp);
    }
    square(v,0,0);
    std::cout << max << "\n";
}