#include<iostream>
#include<vector>

std::string s1,s2;
std::vector<std::vector<int>> table;

int lcs(int x, int y){
    if(x == -1 || y == -1){
        return 0;
    }
    else{
        if(table[x][y] != -1){
            return table[x][y];
        }
        else{
            if(s1[x] == s2[y]){
                int tmp = lcs(x-1,y-1) + 1;
                table[x][y] = tmp;
                return tmp;
            }
            else{
                int lhs = lcs(x-1,y);
                int rhs = lcs(x,y-1);
                int tmp = lhs > rhs ? lhs:rhs;
                table[x][y] = tmp;
                return tmp;
            }
        }
    }
}



int main(){
    std::cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++){
        std::vector<int> v(s2.size(),-1);
        table.push_back(v);
    }
    std::cout << lcs(s1.size()-1, s2.size()-1) << "\n";
    return 0;
}
/*acbdegcedbg
begcfeubk*/