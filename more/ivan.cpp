#include <iostream>

unsigned long long fact(int n){
    unsigned long long result = 1;
    for(int i = 1; i <= n; i++)
        result *= i;

    return result;

}

void print(int i){
    std::cout << char(int('a') + i);
}

void ivan(int n, int dynamic_n, unsigned long long int k, int seen[], int usable[]){

    for(int i = 0; i < n; i++)
        usable[i] = 0;

    for(int i = 0; i < n; i++){
        if(seen[i] == 0)
            usable[i] = 1;

    }

    if(dynamic_n == 1){
        for(int i = 0; i < n; i++){
            if(usable[i] == 1)
                print(i);
        }

        return;
    }

    int first_letter_num = k / fact(dynamic_n - 1);

    for(int i = 0; i < n; i++){

        if(usable[i] == 1){
            if(first_letter_num == 0){
                print(i);
                seen[i] = 1;
                break;
            }

            first_letter_num --;
        }
    }

    ivan(n, dynamic_n - 1, k % fact(dynamic_n - 1), seen, usable);

}

int main(){
    int seen[20];
    int usable[20];

    int N; std::cin >> N;

    int n;
    unsigned long long int k;

    for(int i = 0; i < N; i++){
        for(int i = 0; i < 20; i++){
            seen[i] = 0;
        }

        std::cin >> n; std::cin >> k;

        ivan(n, n, k - 1, seen, usable);

        std::cout << std::endl;

    }

    return 0;
}
