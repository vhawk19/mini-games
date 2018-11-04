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
void intialize(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=0;
        }
    }
    board[1][1]=1;
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
            cout<<".... ....";
        }
        cout<<endl;
    }
}
int main(){
    intialize();
    display_board();
    return 0;
}
