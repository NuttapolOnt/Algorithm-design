#include<iostream>
#include<vector>

typedef std::vector<std::vector<int>> vv;

int r,c;
int ans = 0;

int walk(vv &map, int y, int x, vv &table){
    if(x == 0 && y == 0){
        table[y][x] = map[y][x];
        return map[y][x];
    }
    if(table[y][x] != 0){
        return table[y][x];
    }
    else{
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 0;
        if(y-1 >= 0){
            ans1 = map[y][x] + walk(map,y-1,x,table);
        }
        if(x-1 >= 0){
            ans2 = map[y][x] + walk(map,y,x-1,table);
        }
        if(x-1 >= 0 && y-1 >= 0){
            ans3 = 2*map[y][x] + walk(map,y-1,x-1,table);
        }
        int tmp = ans1 > ans2 ? ans1 : ans2;
        int ans = ans3 > tmp ? ans3 : tmp;
        table[y][x] = ans;
        return ans;
    }
}

int main(){
    std::cin >> r >> c;
    vv map;
    vv table;
    for(int i = 0; i < r; i++){
        std::vector<int> tmp(c);
        std::vector<int> a(c);
        for(int j = 0; j < c; j++){
            std::cin >> tmp[j];
        }
        map.push_back(tmp);
        table.push_back(a);
    }
    std::cout << walk(map,r-1,c-1,table) << std::endl;
    return 0;
}