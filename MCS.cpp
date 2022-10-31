#include<iostream> 
#include<vector>

void print(std::vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    std::vector<int> s(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i];
        s[i] = sum;
    }
    print(s);
    int mid = (n-1)/2;
    int max_left = s[0];
    int max_right = v[mid+1];
    for(int i = 0; i <= mid; i++){
        for(int j = i;j <= mid;j++){
            int sum = 0;
            if(i == 0){
                sum = s[j];
            }
            else{
                sum = s[j]-s[i-1];
            }
            if(sum > max_left){
                max_left = sum;
            }
        }
    }
    for(int i = mid+1; i < n; i++){
        for(int j = i;j < n;j++){
            int sum = (s[j] - s[i-1]);
            if(sum > max_right){
                max_right = sum;
            }
        }
    }
    int max_mid = max_left + max_right;
    std::cout << max_left << " " << max_right << " " << max_mid << "\n";
    int mx = (max_left > max_right) ? max_left : max_right;
    mx = (max_mid > mx) ? max_mid : mx;
    std::cout << mx << "\n";
    return 0;
}