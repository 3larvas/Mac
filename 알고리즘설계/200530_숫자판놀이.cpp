//
//  200530_숫자판놀이.cpp
//  2020BaekJoon
//
//  Created by YeHwan Oh on 2020/05/30.
//  Copyright © 2020 YeHwan Oh. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


int DP[9][9] = {
    {3, 4, 9, -2, 2, 51, -23 ,2, 1},
    {223, 7, 8 , -11, 5, 99, 2, 3 ,-4},
    {2, 51, -23 , -23, 6, 3, 2, 4 ,5},
    {5, -99, 2 , -1, 32, 2, 5, -99 ,2},
    {6, 3, 3, -4, 2, -1, 6, 3, 3},
    {32, 2, 4, 5, 3, -4, 2, -1, 4},
    {4, 4, 23, 6, 2, -1, 3, -4, 34},
    {78, 32, 1, 7, 3, -4, -23, -23, 6},
    {0, 0, 0, 0, 0, 0, 0, 0 ,0},
};

int maxDP(int a, int b, int c){
    int max = a;
    if(max < b){
        if(b>c){
            max = b;
        }else{
            max = c;
        }
    }else{
        if(max < c){
            max = c;
        }
    }
    
    return max;
}



void printDP(){
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    
    
    for(int i=1;i<9;i++){
        for(int j=0;j<9;j++){
            
            if(j==0){
                DP[i][j] = max(DP[i-1][j], DP[i-1][j+1]) + DP[i][j];
            }
            else if(j==8){
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-1]) + DP[i][j];
            }
            else{
                DP[i][j] = maxDP(DP[i-1][j-1], DP[i-1][j], DP[i-1][j+1]) + DP[i][j];
            }
            
        }
    }
    
    printDP();

    
    return 0;
}
