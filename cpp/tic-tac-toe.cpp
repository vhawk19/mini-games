#include<bits/stdc++.h>
using namespace std;
int board[3][3];
struct best_move
{
    int row;
    int column;
};

int p = 1;	//This will be a player turn counter. (private)
int current_player(){
		p++;
		if(p%2==0) return 1 ; //X
		else return -1 ;	//O

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
        for(int j=0;j<3;j++){
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
bool checkmoves()//checks if any free spaces are available
{
    for(int i=0; i<3; i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==0)
                return true;
    return false;
}

int minimax( bool max_move, int level=0)//checks all possible solutions and returns the value of currentboard
{
    int value= check();
    if (value==10)
        return value;
    if (value==-10)
        return value;
    if (checkmoves()==false)
        return 0;
    if(max_move)
    {
        int best_score=-100;
        for(int i=0; i<3;i++)
        {
            for(int j=0; j<3;j++)
            {
                if(board[i][j]==0)
                { board[i][j]=current_player();
                best_score=max(best_score, minimax( !max_move,level+1));
                board[i][j]=0;}
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
                if(board[i][j]==0)
                { board[i][j]=current_player();
                best_score=min(best_score, minimax( !max_move,level+1));
                board[i][j]=0;}
        }

    }
        return best_score;

}
    }

best_move find_best()//return best move for the current player
{
    int best_value=-100;
    best_move best;
    best.row=-1;
    best.column=-1;

    for(int i=0;i<3; i++)
        for(int j=0; j<3; j++)
            if(board[i][j]==0)
            {
                board[i][j]=current_player();
                int new_move= minimax(false,0);
                board[i][j]=0;
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

void input(){
	int i, j, p = 0 ;
	cout<<"\nEnter Row: " ;
	cin>> i;
	cout<<"\nEnter Collumn: " ;
	cin>> j;
	board[i-1][j-1] = current_player()	;



} //End of input()

//int player()//returns player move




int main(){
    intialize();
    display_board();
    input();
    input() ;
    display_board();
    return 0;
}

