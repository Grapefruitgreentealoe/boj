#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *arr;     // 데이터 메모리 포인터
    int maxLength;// 가용 가능한 공간 길이
    int length;   // 현재 데이터가 담긴 길이
}queue; // 큐의 정보를 담은 스트럭처

queue* newQueue(int maxLength){
    queue* temp = (queue *)malloc(sizeof(queue));
    temp->arr = (int *)malloc(sizeof(int) * maxLength);
    temp->maxLength = maxLength;
    temp->length = 0;
    return temp;
} // 새로운 큐를 생성하는 함수; 반환값 : 만들어진 큐의 주소

int delQueue(queue *q){
    if(q->arr && q->maxLength){
        free(q->arr);
        free(q);
        return 1;
    }
    return 0;
} // 생성되어있는 큐 삭제; 반환값: 삭제 성공 1, 삭제 실패(안함) 0

int push(queue* q, int value){
    if(q->maxLength <= q->length){
        q->maxLength *= 2;
        int *arr = (int *)malloc(sizeof(int) * q->maxLength);
        for(int i = 0 ; i < q->length;++i){
            arr[i] = q->arr[i];
        }
        free(q->arr);
        q->arr = arr;
    }
    q->arr[q->length++] = value;
    return 1;
} // 큐에 값 넣기; 반환값: 1

int pop(queue* q){
    if(q->length < 1){
        return -1;
    }else{
        int ret = q->arr[0];
        for(int i = 1; i < q->length;++i){
            q->arr[i-1] = q->arr[i];
        }
        q->length--;
        return ret;
    }
} // 큐에서 선입 값 뽑기; 반환값: 선입 값

int size(queue* q){
    return q->length;
} // 큐의 현재 길이 뽑기; 반환값: 큐의 현재 길이

int empty(queue* q){
    return q->length == 0;
} // 큐의 저장 상태 확인; 반환값: 큐에 임의의 값 저장됨 1, 큐가 비어있음 0

int front(queue* q){
    if(!q->length){
        // if length of q is zero
        return -1;
    }
    return q->arr[0];
} // 큐의 선입 값 확인; 반환값: 선입 값

int back(queue* q){
    if(!q->length){
        // if length of q is zero
        return -1;
    }
    return q->arr[q->length-1];
} // 큐의 최후입 값 확인; 반환값: 최후입 값

int main(void){
    queue* q = newQueue(10);
    
    int cmdCount;
    scanf("%d", &cmdCount);
    
    while(cmdCount--){
        char str[6];
        scanf("%s", str);
        int sum = 0;
        for(int i = 0 ; str[i]; ++i){
            sum += str[i];
        }
        
        switch(sum){
            case 448: // push
                {
                    int num;
                    scanf("%d", &num);
                    push(q, num);
                }
                break;
            case 335: // pop
                printf("%d\n", pop(q));
                break;
            case 443: // size
                printf("%d\n", size(q));
                break;
            case 559: // empty
                printf("%d\n", empty(q));
                break;
            case 553: // front
                printf("%d\n", front(q));
                break;
            case 401: // back
                printf("%d\n", back(q));
                break;
        }
    }
    delQueue(q);
    return 0;
}
