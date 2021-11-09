#include <iostream>

int arr[2000000];

long long min_sum(int N, int d){
    long long sum = 0;
    size_t left = 0;
    size_t right = d - 1;
    int _min = 2000000000;
    size_t min_index = 0;
    for(int i = 0; i < d; i++){
        std::cin >> arr[i];
        if(arr[i] < _min){
            _min = arr[i];
            min_index = i;
        }
    }

    sum += _min;

    for(int i = d; i < N; i++){
        std::cin >> arr[i];

        if(arr[i] <= _min){
                min_index = i;
                _min = arr[i];
                sum += _min;
        }

        else{
            if(left != min_index){
                sum += _min;
            }
            else{
                _min = 2000000000;
                for(int j = i - d + 1; j <= i; j++){
                    if(arr[j] < _min){
                    _min = arr[j];
                    min_index = j;
                    }
                }
                sum += _min;
            }
        }

        left++;


    }

    return sum;



}

int main(){
    int N; std::cin >> N;
    int d; std::cin >> d;

    printf("%lld\n", min_sum(N, d));

    return 0;
}
