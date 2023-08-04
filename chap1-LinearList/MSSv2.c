#include <stdio.h>

int A[10010];
int dp[10010];

int max(int a, int b);

int main(){
    int i, N, MaxSum, sum;
    int left, right;

    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
/*
dp[i] = max(dp[i-1] + A[i], A[i])
dp[i]:表示以i为右端点的最大子列和的值
dp[i]可以清晰地划分为两个不相干的部分：
    1.当只有一个元素时，dp[i] = A[i];
    2.当子列中不止一个元素时，dp[i] = dp[i-1] + A[i]
故dp[i]取两者最大值
*/
        if(!i){
            dp[i] = A[i];
            MaxSum = dp[i];
        }
        else{
            dp[i] = max(A[i], dp[i-1]+A[i]);
            MaxSum = max(MaxSum, dp[i]);
        }
    }
/*
从前往后遍历dp[i], 若发现dp[i] == MaxSum, 
则说明此时的i为最大子列和的右端点.
*/
    for(i = 0; i < N; i++){
        if(dp[i] == MaxSum){
            right = i;
            break;
        }
    }

/*
从右端点往前遍历A[i], 若求和过程中发现 sum == MaxSum,
则说明此时i可以作为最大子列和的左端点 (考虑前面可能存在 0 的情况)
*/
    sum = 0;
    for(i = right; i >= 0; i--){
        sum += A[i];
        if(sum == MaxSum)
            left = i;
    }

    if(MaxSum < 0)
        printf("%d %d %d", 0, A[0], A[N-1]);
    else   
        printf("%d %d %d", MaxSum, A[left], A[right]);

    return 0;
}

int max(int a, int b){
    if(a > b) return a;
    else return b;
}