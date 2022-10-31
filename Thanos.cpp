#include<iostream>
#include<vector>

std::pair<int,int> thanos(std::vector<int> &v, int left, int right, int a, int b){
    if(left == right){
        std::pair<int,int> ans;
        if(v[left] != 0){
            ans = std::make_pair(b*v[left],v[left]);
        }
        else{
            ans = std::make_pair(a,0);
        }
        return ans;
    }
    int mid = (left + right)/2;
    std::pair<int,int> lhs = thanos(v,left,mid,a,b);
    std::pair<int,int> rhs = thanos(v,mid+1,right,a,b);
    std::pair<int,int> ans;
    int power;
    if(lhs.second != 0 || rhs.second != 0){
        if((lhs.first + rhs.first) < ((lhs.second + rhs.second)*b*(right - left +1))){
            power = lhs.first + rhs.first;
        }
        else{
            power = (lhs.second + rhs.second)*b*(right - left +1);
        }
    }
    else{
        power = a;
    }
    ans = std::make_pair(power,lhs.second+rhs.second);
    return ans;
}

int main(){
    int p,k,a,b;
    std::cin >> p >> k >> a >> b;
    int len = 1;
    for(int i = 0; i < p; i++){
        len *= 2;
    }
    std::vector<int> v(len);
    for(int i = 0; i < k; i++){
        int c;
        std::cin >> c;
        v[c-1] += 1;
    }
    std::cout << thanos(v,0,len-1,a,b).first << "\n";
    return 0;
}