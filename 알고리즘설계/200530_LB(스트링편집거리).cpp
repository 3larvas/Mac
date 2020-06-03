//
//  200530_LB(스트링편집거리).cpp
//  2020BaekJoon
//
//  Created by YeHwan Oh on 2020/05/30.
//  Copyright © 2020 YeHwan Oh. All rights reserved.
// 헬로헬로 나는 최형인~~

#include <iostream>
using namespace std;

int minValue(int a, int b, int c){
    int min = a;
    
    if(min > b){
        if(b < c){
            min = b;
        }else{
            min = c;
        }
    }
    else{
        if(min > c){
            min = c;
        }
    }
    return min;
}


int main(void){
    
    string S;
    string T;
    
    cin >> S >> T;
    
    int n = S.length();
    int m = T.length();
    
    int DP[n+1][m+1];

    DP[0][0] = 0;
    for(int i=1;i<=n;i++){
        DP[i][0] = DP[i-1][0] + 1;
    }
    for(int j=1;j<=m;j++){
        DP[0][j] = DP[0][j-1] + 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int cost;
            if(S[i-1] == T[j-1]) cost = 0; // 여기가 중요하다. 스트링의 시작은 0부터이기때문에 -1을 해줘야한다.
            else cost = 1;

            DP[i][j] = minValue(DP[i][j-1] + 1, DP[i-1][j] + 1, DP[i-1][j-1] + cost);
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }

    
    return 0;
}
