//
//  200530_치즈.cpp
//  2020BaekJoon
//
//  Created by YeHwan Oh on 2020/05/30.
//  Copyright © 2020 YeHwan Oh. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int **DP;

void printDP(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    
    cin >> n >> m;
    
    DP = new int*[n];
    for(int i=0;i<n;i++){
        DP[i] = new int[m];
    }
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> DP[i][j];
        }
    }
    
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<m; j++){
            
            if(i==n-1&&j==0) DP[i][j] = 0;
            else if(i==n-1) DP[i][j] = DP[i][j-1] + DP[i][j];
            else if(j == 0) DP[i][j] = DP[i+1][j] + DP[i][j];
            else DP[i][j] = max(DP[i][j-1],DP[i+1][j]) + DP[i][j];
            
        }
    }
    
    
    printDP();
    
    
    for(int i=0;i<n;i++)
        delete [] DP[i];
    delete [] DP;
    
    
    return 0;
}
