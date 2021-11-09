#include <iostream>
#include <unistd.h>

unsigned long long* arr = new unsigned long long[2000001];

void cubes(long long n){
    unsigned long long to_cube = 1;
    while(true){
        unsigned long long cubed = to_cube * to_cube * to_cube;

        if (cubed > n){
            break;
        }

        arr[to_cube - 1] = cubed;
        to_cube ++;
    }

    int i = to_cube - 2;

    int counter = 0;

    while(n > 0){
        if(n >= arr[i]){
            n -= arr[i];
            counter ++;
        }
        else{
            i--;
        }
    }

    std::cout << counter;

}

int main(){
    unsigned long long n = 7999999999999999999;
    std::cin >> n;
    cubes(n);
}
