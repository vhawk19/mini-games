#include<bits/stdc++.h>
using namespace std;
int board[3][3];
struct best_move
{
    int row;
    int column;
}
bool checkmoves(int current_board[3][3])//checks if any free spaces are available 
{
    for(int i=0; i<3; i++)
        for(int j=0;j<3;j++)
            if(current_board[i][j]==" ")
                return true;
    return false;
}

int minimax(int cur_board, bool max_move, int level=0)//checks all possible solutions and returns the value of currentboard
{
    int value= check(cur_board);
    if (value==10)
        return value;
    if (value==-10)
        reurn value;
    if (checkmoves(cur_board)==false)
        return 0;
    if(max_move)
    {
        int best_score=-100;
        for(int i=0; i<3;i++)
        {
            for(int j=0; j<3;j++)
            {
                if(cur_board[i][j]==" ")
                { cur_board[i][j]=player();
                best_score=max(best_score, minimax(cur_board, !max_move,level+1));
                cur_board[i][j]=" ";}
        }
            return best_score;
        
    }
    }
    else
        {
        int best_score=-100;
        for(int i=0; i<3;i++)
        {
            for(int j=0; j<3;j++)
            {
                if(cur_board[i][j]==" ")
                { cur_board[i][j]=player();
                best_score=min(best_score, minimax(cur_board, !max_move,level+1));
                cur_board[i][j]=" ";}
        }
        
    }
        return best_score;
    
}
    }

best_move find_best(int cur_board[3][3]//return best move for the current player
{
    int best_value=-100;
    best_move best;
    best.row=-1;
    best.column=-1;
    
    for(int i=0;i<3; i++)
        for(int j=0; j<3; j++)
            if(cur_board[i][j]==" ")
            {
                cur_board[i][j]=player();
                int new_move= minimax(cur_board,false,0);
                cur_board[i][j]=" ";
                if(new_move>best_value)
                {best.row=i;
                 best.column=j;
                 best_value=new_move;
                }
                
            }
return best;
        
}
        
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
        for(int j=0;j<3;j++){
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
int player()//returns player move

void play()


int main(){
    intialize();
    display_board();
    return 0;
}
