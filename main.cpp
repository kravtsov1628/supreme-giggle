#include <iostream>
#include <vector>
#include <clocale>
#include <math.h>

void task1(){
    int n;

    std::cout<<"factorial of: ";
    std::cin>>n;

    std::vector<int>fackt{1};

    for (int i=2 ; i<=n;i++){
        int carry = 0;

        for (size_t j=0; j<fackt.size();j++){
           int zap = fackt[j]*i+carry;
            carry = zap/10;
            fackt[j] = zap%10;
        }

        while (carry > 0) {
            fackt.push_back(carry % 10);
            carry /= 10;
        }
    }

    for (int i = fackt.size() - 1; i >= 0; i--){
    std::cout << fackt[i];
    }
}

std::vector<int> pwr_2(int n){
    std::vector<int>power{1};

    for (int i=1 ; i<=n;i++){
        int carry = 0;

        for (size_t j=0; j<power.size();j++){
           int zap = power[j]*2+carry;
            carry = zap/10;
            power[j] = zap%10;
        }
        while (carry > 0) {
            power.push_back(carry % 10);
            carry /= 10;
        }
}
return power;
}

void task2(){
    int n;
    std::cout<<"power of 2: ";
    std::cin>>n;
    std::vector<int> power=pwr_2(n);

    
for (int i = power.size() - 1; i >= 0; i--){
    std::cout << power[i];
    }
}

void task3(){
    int n,m;
    
    std::cout<<"two numbers: ";
    std::cin>>n>>m;

    
    int min=(m>n)? n:m;
    std::vector<int> vec_n = pwr_2(n);
    std::vector<int> vec_m = pwr_2(m);
    std::vector<int>& min_vec = (vec_n.size() == static_cast<size_t>(min)) ? vec_n : vec_m;
    std::vector<int> sum;
    int diff = vec_m.size()-vec_n.size();

    for (int i=0;i<(abs(diff));i++){
        min_vec.push_back(0);
    }
    int carry = 0;
    for (int i=0;i<vec_m.size();i++){
    
        int zap = vec_n[i] + vec_m[i]+carry;
        sum.push_back( zap %10);
        carry=zap/10;
    }
    if (carry) sum.push_back(1);
    for (int i = sum.size() - 1; i >= 0; i--){
    std::cout << sum[i];
    }
}

void task4(){
    int n,m;
    
    std::cout<<"two numbers: ";
    std::cin>>n>>m;

    std::vector<int> vec_n = pwr_2(n);
    std::vector<int> vec_m = pwr_2(m);

    int min=(m>n)? n:m;
    std::vector<int>& min_vec = (vec_n.size() == static_cast<size_t>(min)) ? vec_n : vec_m;
    std::vector<int> razn;
    int diff = vec_m.size()-vec_n.size();

    for (int i=0;i<(abs(diff));i++){
        min_vec.push_back(0);
    }

    int carry=0;

    for (int i=0; i<vec_m.size();i++){
        int v_n=vec_n[i]-carry;
        int v_m=vec_m[i];
        int zap;

        if (v_n < v_m){
            zap = v_n+10 - v_m;
            carry=1;
            razn.push_back(zap);
        }
        else{
            zap = v_n - v_m;
            carry=0;
            razn.push_back(zap);
        }
    }

    for (int i = razn.size() - 1; i >= 0; i--){
        std::cout << razn[i];
    }
}

void task5(){
    int n;

    std::cout<<"the number of the Fibonacci: ";
    std::cin>>n;
    std::vector<std::vector<int>>fibon{ {1}, {1} };

    for (int i=2;i<n;i++){
        std::vector<int>& prev2 = fibon[i - 2];
        std::vector<int>& prev1 = fibon[i - 1];

        size_t max_len = std::max(prev2.size(), prev1.size());
        if (prev2.size() < max_len) prev2.resize(max_len, 0);
        if (prev1.size() < max_len) prev1.resize(max_len, 0);
        std::vector<int>zap;
        int carry = 0;
        
        for (int j=0;j<max_len;j++){
            int zappy = prev2[j] + prev1[j] + carry;
            zap.push_back(zappy % 10);
            carry = zappy / 10;
        } 
        if (carry) zap.push_back(1);
        fibon.push_back(zap);
    }

    std::vector<int>res(fibon[n-1]);
    for (int i = res.size() - 1; i >= 0; i--){
        std::cout << res[i];
    }
}

int main(){
    int task_num;

    std::cout<<"task number: ";
    std::cin>>task_num;

    switch (task_num)
    {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    case 5:
        task5();
        break;
    default:
        break;
    }{}
}