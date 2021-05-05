#include<stdio.h>
int p[50], a, c[50]; // int형 배열 p,c와 정수 a 선언
int main(){ 
    int n, d;
    scanf("%d", &n); //노드개수
    for (int i = 0; i < n; i++){
        scanf("%d", p + i); //노드 각 자리에 값을 입력
        if(p[i]>=0) c[p[i]]++; //p[i]값이 양수면 c배열의 p[i]번째 
    }
    scanf("%d", &d);
    c[p[d]]--;
    for (int i = 0; i < n; i++){
        if (c[i]) continue;
        int j = i;
        while (j != -1){
            if (j == d) break;
            j = p[j];
        }
        a += j == -1;
    }
    printf("%d\n", a);
    return 0;
}
