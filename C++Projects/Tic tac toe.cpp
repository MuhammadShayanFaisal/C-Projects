#include<cstdlib> 
#include<iostream>
#include<windows.h>
#include<string>
#include<time.h>
using namespace std;
class TicTacToe{
	protected:
	int gameover;
	int computerturnx;
	int playerturnx;
	int countdown;
	int starttime;
	string array[3][3];
	int player[5];
	int c=0;
	public:
    virtual void drawboard()=0;	
    virtual void inputplayer()=0;
    virtual void setup()=0;
    virtual void display()=0;
    virtual void inputcomputer()=0;
    virtual bool logicplayer()=0;
    virtual bool logiccomputer()=0;
    virtual void instructions()=0;
};
class tictactoe:public TicTacToe{
	public:
		tictactoe(){
			player[5]=(0,0,0,0,0);
			int i,j;
			for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				array[i][j]="";
			}
		}
		}
		void setup(){
			gameover=0;
			srand(time(NULL));
			computerturnx=rand()%9;
			starttime=time(NULL);
            countdown=10;
		}
	void drawboard(){
		int i,j;
		cout<<"-----------------------\n\n\n\n\n"<<endl;
		for(i=0;i<3;i++){
			cout<<"\t\t\t\t\t----------------\n\t\t\t\t\t";
			for(j=0;j<4;j++){
			    cout<<"|    ";	
			}
			cout<<"\n";
		}
		cout<<"\t\t\t\t\t----------------"<<endl;	
	}
	void inputplayer(){
		int startTime = time(NULL);
        int elapsedTime = 0;
		int i,j;
		cout<<"Select 1,2,3,4,5,6,7,8,9 for the entrance for the numbers"<<endl;
		cin>>playerturnx;
		player[c]=playerturnx;
		c++;
		
		elapsedTime = time(NULL) - startTime;

    if (elapsedTime > 10) {
        cout << "Time's up! Game over." << endl;
        gameover = 1;
        return;
    }
		if(playerturnx==1)
		array[0][0]="X";
		else if(playerturnx==2)
		array[0][1]="X";
		else if(playerturnx==3)
		array[0][2]="X";
		else if(playerturnx==4)
		array[1][0]="X";
		else if(playerturnx==5)
		array[1][1]="X";
		else if(playerturnx==6)
		array[1][2]="X";
		else if(playerturnx==7)
		array[2][0]="X";
		else if(playerturnx==8)
		array[2][1]="X";
		else if(playerturnx==9)
		array[2][2]="X";
	 if (countdown <= 0) {
        gameover = 1;
    } else {
        countdown = 10 - elapsedTime;
    }
			
	}
   void inputcomputer() {
    cout << "Computer turn" << endl;
    bool validTurn = false;
    int bestScore = -1000;
    int moveX, moveY;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == "") {
                array[i][j] = "O";
                if (logiccomputer()) {
                    cout << "Computer placed O at position (" << i + 1 << "," << j + 1 << ") to win" << endl;
                    return;
                }
                array[i][j] = "";
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == "") {
                array[i][j] = "X";
                if (logicplayer()) {
                    array[i][j] = "O";
                    cout << "Computer placed O at position (" << i + 1 << "," << j + 1 << ") to block player" << endl;
                    return;
                }
                array[i][j] = "";
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == "") {
                array[i][j] = "O";
                int score = minimax(array, 0, false);
                array[i][j] = "";
                if (score > bestScore) {
                    bestScore = score;
                    moveX = i;
                    moveY = j;
                }
            }
        }
    }
    array[moveX][moveY] = "O";
    cout << "Computer placed O at position (" << moveX + 1 << "," << moveY + 1 << ")" << endl;
}
    int minimax(string board[3][3], int depth, bool isMaximizing) {
        int score = evaluate(board);
        if (score == 10 || score == -10)
            return score;
        if (depth == 9)
            return 0;
        if (isMaximizing) {
            int best = -1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == "") {
                        board[i][j] = "O";
                        best = max(best, minimax(board, depth + 1, !isMaximizing));
                        board[i][j] = "";
                    }
                }
            }
            return best;
        } else {
            int best = 1000;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == "") {
                        board[i][j] = "X";
                        best = min(best, minimax(board, depth + 1, !isMaximizing));
                        board[i][j] = "";
                    }
                }
            }
            return best;
        }
    }
    int evaluate(string board[3][3]) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == "X" && board[i][1] == "X" && board[i][2] == "X")
                return -10;
            if (board[0][i] == "X" && board[1][i] == "X" && board[2][i] == "X")
                return -10;
            if (board[i][0] == "O" && board[i][1] == "O" && board[i][2] == "O")
                return 10;
            if (board[0][i] == "O" && board[1][i] == "O" && board[2][i] == "O")
                return 10;
        }
        if ((board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X") ||
            (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "X"))
            return -10;
        if ((board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O") ||
            (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "O"))
            return 10;
        return 0;
    }
	void display(){
		int i,j;
		for(i=0;i<3;i++){
			cout<<"\t\t\t\t\t----------------\n\t\t\t\t\t";
			for(j=0;j<3;j++){
				if(j==2)
				cout<<" |  "<<array[i][j]<<" |  ";
				else
			    cout<<" |  "<<array[i][j];	
			}
			cout<<"\n";
		}
		cout<<"\t\t\t\t\t----------------"<<endl;
	}
	bool logicplayer() {
    for (int i = 0; i < 3; i++) {
        if (array[i][0] =="X"&&array[i][1]=="X"&&array[i][2]=="X") 
            return true;
        if (array[0][i]=="X"&&array[1][i]=="X"&&array[2][i]=="X") 
            return true;
    }

    if ((array[0][0]=="X"&&array[1][1]=="X"&&array[2][2]=="X")||
        (array[0][2]=="X"&&array[1][1]=="X"&&array[2][0]=="X"))  
        return true;
    return false;
}
bool logiccomputer() {
    for (int i=0;i<3;i++) {
        if (array[i][0]=="O"&&array[i][1]=="O"&&array[i][2]=="O")
            return true;
        if (array[0][i]=="O"&&array[1][i]=="O"&&array[2][i]=="O")
            return true;
    }
    if ((array[0][0]=="O"&&array[1][1]=="O"&&array[2][2]=="O") || 
        (array[0][2] =="O"&&array[1][1]=="O"&&array[2][0]=="O"))   
        return true;
    return false; 
}
void instructions(){
	system("Color C0");
	cout<<"----------Welcome to the Advanced Gaming Zone, Tic Tac Toe is in your user friendly interface----------"<<endl;
	cout<<"\n\n\n\n\n\t\tMade by:\n\t\tMuhammad Shayan Faisal\n\t\tHamza Ahmed\n\t\tMuhammad Sufyan Ali\n"<<endl;
	cin.get();
	system("cls");
	system("Color A1");
	cout<<"\n\n\n\t\tRules of the Games are: "<<endl;
	cout<<"\t\t1.The game is played on a grid that's 3 squares by 3 squares.\n\t\t2.You are X , your friend (or the computer in this case) is O . Players take turns putting their marks in empty squares."<<endl;
	cout<<"\t\t3.The first player to get 3 of her marks in a row (up, down, across, or diagonally) is the winner.\n\t\t4.When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie."<<endl;
	cout<<"\t\t5. Press 1 for 1 st box entrance , 2nd for 2nd box entrance and rest all same.\n\t\t5.Remmeber 'X' has been your symbol and 'O' for computer"<<endl;
	cin.get();
	system("cls");
	system("Color 71");
}
};
int main (){
	TicTacToe *t;
	tictactoe t1;
	t=&t1;
	t->instructions();
	t->drawboard();
	t->inputplayer();
	t->inputcomputer();
	t->display();
	t->inputplayer();
	t->display();
	t->inputcomputer();
	t->display();
	
	for(int i=0;i<7;i++){
	t->inputplayer();
	t->display();
	int temp=t->logicplayer();
	if(temp==1){
	cout<<"Game over"<<endl<<"You won"<<endl;
	break;
	}
	t->inputcomputer();
	t->display();
	int temp1=t->logiccomputer();
     if(temp1==1){
	cout<<"Game over"<<endl<<"Computer won"<<endl;
	break;
	}
	if(i==8&&temp!=1&&temp1!=1){
	cout<<"Game tie"<<endl;
	cout<<"Thanks for playing"<<endl;}	
}
}
