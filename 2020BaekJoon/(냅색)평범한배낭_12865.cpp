//
//  (냅색)평범한배낭_12865.cpp
//  2020BaekJoon
//
//  Created by YeHwan Oh on 2020/05/29.
//  Copyright © 2020 YeHwan Oh. All rights reserved.
//
#include <iostream>
#include <algorithm>
using namespace std;

int N=0; // 필요한 물건의 개수
int W=0; // 물건의 무게
int V=0; // 물건의 가치

int K=0; // 배낭의 최대 무게

int D[101][100001]; // 행 :  1<=물품의 수<=100 , 열 : 1<=버틸수있는 무게<=100000

class Node{
public:
    int weight;
    int value;
};

void init(){ // 배열 초기화
    for(int i=0;i<=N;i++){
        for(int j=0;j<=K;j++){
            D[i][j] = 0;
        }
    }
}

int main(void){
    
    cin >> N >> K; // 물건의 개수와 배낭이 버틸 수 있는 무게 입력
    Node node[N+1]; // 노드 생성
    for(int i=1; i<=N; i++){ // 1~N까지
        cin >> W >> V; // 물건의 무게와 물건의 비용을 입력받는다.
        node[i].weight = W; // 노드에 저장
        node[i].value = V;
    }
    
    init(); // 배열 초기화

    
    for(int i=1;i<=N;i++){ // 배열의 행
        for(int j=1;j<=K;j++){ // 배열의 열
            D[i][j] = D[i-1][j]; // 이전 행의 배열을 현재 행에 저장
            if( j - node[i].weight >= 0 ) { // 현재 이용가능 무게 - 현재 물건의 무게가 0 보다 클거나 같을 때
                D[i][j] = max( D[i][j], D[i-1][j - node[i].weight] + node[i].value); // 현재 배열과 이전 행의 이용가능 무게의 비용 + 현재 비용 중 더 큰 값
            }
        }
    }
    
    cout << D[N][K] << endl;
    
    
    return 0;
}
