//
//  FloydWarshall_11404.cpp
//  2020BaekJoon
//
//  Created by YeHwan Oh on 2020/05/28.
//  Copyright © 2020 YeHwan Oh. All rights reserved.
//  [도시와 버스]

#include <iostream>
#include <algorithm>
using namespace std;


int n = 0; // (1<=n<=100) 도시의 개수
int m = 0; // (1<=m<=100,000) 버스의 개수
int INF = 10000000; // 한번에 갈 수 없는 경우
int D[101][101];

// 배열 초기화 함수
void init(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            D[i][j] = i == j ? 0 : INF; // i == j 이면 0 아니면 INF 입력
        }
    }
}

// 플로이드 함수
void floyd(){
    for(int k=1;k<=n;k++){ // 거쳐서 가는 경우
        for(int i=1;i<=n;i++){ // 시작점부터
            for(int j=1;j<=n;j++){ // 끝점까지
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]); // 두 값중 더 작은 값을 입력
            }
        }
    }
}



int main(){
    
    cin >> n; // 첫째 줄에 도시의 개수를 입력
    cin >> m; // 둘째 줄에 버스의 개수를 입력
    
    init(); // 배열 초기화
    
    // 셋째줄부터는 버스의정보입력(시작도시번호, 도착도시번호, 한번타는데필요한비용)
    int from=0,to=0,weight=0; // 시작번호, 도착번호, 비용을 저장할 변수
    for(int i=0 ; i<m ; i++){ // 버스의 개수만큼 입력
        cin >> from >> to >> weight; // 시작번호, 도착번호, 비용을 입력
        if(D[from][to] > weight) D[from][to] = weight;
        
    }
    // 플로이드
    floyd();
    // 출력부분
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(D[i][j] == INF) D[i][j] = 0; // i에서 j로 갈 수 없는 경우 그 자리를 0으로 입력
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}
