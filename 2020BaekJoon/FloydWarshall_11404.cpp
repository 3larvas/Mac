//
//  FloydWarshall_11404.cpp
//  2020BaekJoon
//
//  Created by YeHwan Oh on 2020/05/28.
//  Copyright © 2020 YeHwan Oh. All rights reserved.
//  [도시와 버스]

#include <iostream>
using namespace std;


int n = 0; // (1<=n<=100) 도시의 개수
int m = 0; // (1<=m<=100,000) 버스의 개수
int INF = 10000000; // 한번에 갈 수 없는 경우


int main(){
    
    
    cin >> n; // 첫째 줄에 도시의 개수를 입력
    cin >> m; // 둘째 줄에 버스의 개수를 입력
    
    int **D; // 동적할당으로 최소비용을 저장할 2차원 배열 생성
    D = new int*[n]; // 행 결정
    for(int i=0;i<n;i++){ // 열 결정
        D[i] = new int[n];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) D[i][j] = 0;
            else D[i][j] = INF;
        }
    }
    
    
    // 셋째줄부터는 버스의정보입력(시작도시번호, 도착도시번호, 한번타는데필요한비용)
    int x=0,y=0,z=0; // 시작번호, 도착번호, 비용을 저장할 변수
    for(int i=0 ; i<m ; i++){ // 버스의 개수만큼 입력
        cin >> x >> y >> z; // 시작번호, 도착번호, 비용을 입력
        D[x-1][y-1] = z; // 배열은 0~n-1까지 이므로 x,y에 -1해준다. 해당배열에 비용 입력
    }
    
    
    
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(D[i][j] > D[i][k] + D[k][j]) D[i][j] = D[i][k] + D[k][j];
            }
        }
    }
    
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
