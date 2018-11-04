#include<bits/stdc++.h>
using namespace std;
int board[3][3];
void display_cell(int a){
    if(a==1){
        cout<<"X ";
    }
    else if(a==-1){
        cout<<"O ";
    }
    else{
        cout<<"  ";
    }
}
int check(){
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0j<3;j++){
            sum+=board[i][j];
        }
        if(sum==3){
            return  10;
        }
        else if(sum==-3){
            return -10;
        }
    }
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0j<3;j++){
            sum+=board[j][i];
        }
        if(sum==3){
            return  10;
        }
        else if(sum==-3){
            return -10;
        }
    }
    int sum_0=0;
    for(int i=0;i<3;i++){
        sum_0+=board[i][i];
    }
    if(sum_0==3){
        return +10;
    }
    else if(sum_0==-3){
        return -10;
    }
    sum_0=0;
    for(int i=0;i<3;i++){
        sum_0+=board[i][2-i];
    }

    if(sum_0==3){
        return +10;
    }
    else if(sum_0==-3){
        return -10;
    }

    return 0;
}
void intialize(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=0;
        }
    }
}
void display_board(){
    for(int i=0;i<3;i++){
        cout<<" | ";
        for(int j=0;j<3;j++){
            display_cell(board[i][j]);
            cout<<"| ";
        }
        cout<<endl;
        for(int j=0;j<2;j++){
            cout<<"........";
        }
        cout<<endl;
    }
}
int main(){
    intialize();
    display_board();
    return 0;
}
