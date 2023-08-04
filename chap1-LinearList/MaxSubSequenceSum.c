#include <stdio.h>
#include <stdlib.h>

int MaxSubSequenceSum(int A[], int N);

int main(){
    int N, i, temp, res;
    int* A;

    scanf("%d", &N);
    A = (int*)malloc(sizeof(int)*N);
    for(i = 0; i < N; i++){
       scanf("%d", &temp);
       A[i] = temp;
    }
    res = MaxSubSequenceSum(A, N);
    printf("%d", res);

    return 0;
}

int MaxSubSequenceSum(int A[], int N){
    int ThisSum = 0, MaxSum = 0;
    int i;

    for(i = 0; i < N; i++){
        ThisSum += A[i];
        if(ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if(ThisSum < 0)
            ThisSum = 0;
    }
    if(MaxSum < 0) return 0;
    return MaxSum;
}
