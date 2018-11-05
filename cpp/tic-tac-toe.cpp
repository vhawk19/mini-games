#include<bits/stdc++.h>
using namespace std;
int board[3][3];
struct move
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
        int sumc=0, sumr=0;
        for(int j=0;j<3;j++){
            sumc+=board[i][j];
	    sumr+=board[j][i]; 
        }
        if(sumc==3 || sumr==3){
            return  10;
        }
        else if(sumc==-3|| sumr==-3){
            return -10;
        }
    }

  /*for(int i=0;i<3;i++){	**REDUNDANT**
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
  */

    int sum_md=0, sum_od=0;
    for(int i=0;i<3;i++){
        sum_md+=board[i][i];
	sum_od+=board[i][2-i];
    }
    if(sum_md==3 || sum_od==3){
        return +10;
    }
    else if(sum_md==-3|| sum_od==-3){
        return -10;
    }

  /*sum_0=0;			**REDUNDANT**
    for(int i=0;i<3;i++){
        sum_0+=board[i][2-i];
    }

    if(sum_0==3){
        return +10;
    }
    else if(sum_0==-3){
        return -10;
    }
  */
    return 0;
}
bool checkmoves()//checks if any free spaces are available
{
    for(int i=0; i<3; i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==0)
                return true;	//Free space available.
    return false;
}

int minimax( bool max_move, int level=0)//checks all possible solutions and returns the value of currentboard
{
    int value= check();
    if (value==10)		//X wins.
        return value;
    if (value==-10)		//O wins.
        return value;
    if (checkmoves()==false)
        return 0;		//Draw
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

struct move find_best()//return best move for the current player as a structure 'move'
{
    int best_value=-100;
    struct move best;
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

void us_input(){		//User Input Method
	struct move player ;
	cout<<"\nEnter Row: " ;
	cin>> player.row;
	cout<<"\nEnter Collumn: " ;
	cin>> player.column;
	board[player.row-1][player.column-1] = current_player()	;



} //End of input()

void ai_input(){
	struct move ai;
	ai = find_best() ;
	board[ai.row][ai.column] = current_player();
	cout<<ai.row<<' ' <<ai.column ;	
	
}





int main(){
    intialize();
    display_board();
    us_input();
    ai_input();
    display_board();
    return 0;
}

