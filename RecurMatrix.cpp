#include<iostream>
#include<vector>

void print(std::vector<std::vector<int>> &v){
    for(auto &x : v){
        for(auto &y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
}

void create(std::vector<std::vector<int>> &v, int a, int b,int x,int y,int len){
    if(a == 0){
        v[y][x] = b;
        return;
    }
    else{
        len = len/2;
        create(v,a-1,b,x,y,len);
        create(v,a-1,b-1,x+len,y,len);
        create(v,a-1,b+1,x,y+len,len);
        create(v,a-1,b,x+len,y+len,len);
    }
    return;
}

int main(){
    int a,b;
    std::cin >> a >> b;
    int len = 1;
    for(int i = 0; i < a; i++){
        len *= 2;
    }
    std::vector<std::vector<int>> v(len);
    for(int i = 0; i < len; i++){
        std::vector<int> a(len);
        v[i] = a;
    }
    create(v,a,b,0,0,len);
    print(v);
    return 0;
}