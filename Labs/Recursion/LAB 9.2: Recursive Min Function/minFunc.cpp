#include "minFunc.h"

const int * min(const int arr[], int arrSize) {
//     int location = arrSize - 1;
//     int low = arr[arrSize - 1];
    
    if (arrSize <= 1) {
        return arr;
    }
    
//     int temporarySize = arrSize / 2;
//     const int *x = min(arr, temporarySize);
//     const int *y = min(arr, arrSize - temporarySize);
    
//     if (x < y) {
//         return x;
//     }
//     else if (y < x) {
//         return y;
//     }
    
    const int* small = min(arr, arrSize - 1);
    
    if (*small > arr[arrSize - 1]) {
        return arr + arrSize - 1;
    }
    
    else {
        return small;
    }
}
