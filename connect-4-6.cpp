#include <iostream>
#include <vector>
using namespace std;
class ConnectFourGame {
	
	//variables Needed............................
 
 public:
     int rows;
     int cols;
 
   
   char empty_Slot = ' ';
     char Red_player ='R';
     char Blue_player ='B';

     char currentPlayer= 'R';
 
    vector< vector<char> >  board;
		
		
		ConnectFourGame(int _rows, int _cols):board(_rows,vector<char>(_cols,empty_Slot))         {
			
			rows=_rows;
			cols=_cols;
		}
		
	
	
		

	
};

class WinnerChecker{
	
	char empty_Slot=' ';
	
		ConnectFourGame connect4;
	public: 
	

	
	WinnerChecker(ConnectFourGame  _connect4) : connect4(_connect4)  
	{
	
	}
	
	bool CheckWinner(){
		
		
	     
	      
	      return 	CheckWinnerHorizontally()||	CheckWinnerVertically()||	CheckWinnerDiaognallyLeft()|| CheckWinnerDiaognallyRight();
		}
		
		
		
      bool CheckWinnerHorizontally(){
      	
      	
      	for(int i=connect4.rows-1;i>=0;i--){
      	for(int j=0;j<connect4.cols-4;j++){
      			if( connect4.board[i][j] != connect4.empty_Slot && connect4.board[i][j]==connect4.board[i][j+1]   &&connect4.board[i][j]==connect4.board[i][j+2] 
				  &&connect4.board[i][j]==connect4.board[i][j+3] ){
				  	return true;
				  }
			  }
		  }
		  
		  return false;
	  }//CheckWinnerHorizontally.
	  
	  
	  bool CheckWinnerVertically(){
      		for(int j=0;j<connect4.cols;j++){
      	for(int i=connect4.rows-1;i>=connect4.rows-3;i--){
      			if( connect4.board[i][j] != connect4.empty_Slot &&       connect4.board[i][j]==connect4.board[i-1][j]   &&connect4.board[i][j]==connect4.board[i-2][j] 
				  &&connect4.board[i][j]==connect4.board[i-3][j] ){
				  	return true;
				  }
			  }
		  }
		  
		  return false;
	  }//CheckWinnerVertically..
	  
	  bool CheckWinnerDiaognallyLeft(){
      	 // Check for diagonal win (top-left to bottom-right)
                  int i=0,j=0;
             if (connect4.board[i][j] != empty_Slot && connect4.board[i][j] == connect4.board[i + 1][j + 1] && connect4.board[i][j] == connect4.board[i + 2][j + 2] && connect4.board[i][j] == connect4.board[i + 3][j + 3]&&
				connect4.board[i][j] == connect4.board[i + 4][j + 4] && connect4.board[i][j] == connect4.board[i + 5][j + 5])
                {
                  return true;
              }
	  }//CheckWinnerDiaognallyLeft..
	  
	  
	  bool CheckWinnerDiaognallyRight(){
      	  //  Check for diagonal win (bottom-left to top-right)
        int i=0,j=0;
              if (connect4.board[i][j] != empty_Slot && connect4.board[i][j] == connect4.board[i - 1][j + 1] && connect4.board[i][j] == connect4.board[i - 2][j + 2] && connect4.board[i][j] == connect4.board[i - 3][j + 3])
              {
                return true;
              }
       
        return false;
	  }//CheckWinnerDiaognallyRight...
	  
	  
	  

};


class  Input{
	
		int x;
		 int y;	
		
		ConnectFourGame* boardObj;
		
		
	public:
		Input(ConnectFourGame& _boardObj){
			boardObj= &_boardObj;
		}
		bool CheckRightInput(int rows, int cols){
			
				if(x<rows&& x>=0 && y<cols&& y>=0  ){
				  return true;
				}else{
					
					cout<<"Please give Correct Values for x and y "<<endl;
					return false;
				}
				
				
		}//CheckRightInput...

  

	///*
		void TakeInput(char currentPlayer){
			
				
	         while(true){
	         	
	         		cout<<"Please choose the x(Means row)";
		 		
		 		cin>>x;
		 		cout<<"Value of x==="<<x<<endl;
		 		cout<<"Now  choose the y(Means cols)";
		 		
		 		cin>>y;
		 		
		 	
		 				bool correct= CheckRightInput(boardObj->rows,boardObj->cols);
						 
						 if(correct==true){
						 		for(int i=boardObj->rows-1; i>=0;i--){
						 		//	for(int j=0; j<boardObj.cols;j++){
						 					 cout<<" i== "<<i<<" And y=="<<y<<" And x=="<<x<<endl;
									      if(x==i  ){
									       	if(boardObj->board[x][y] == boardObj->empty_Slot){
									       		boardObj->board[i][y]= currentPlayer;
									       		cout<<"currentPlayer from LOOP :"<<currentPlayer<<endl;
		 				                 	 return;
											   }else{
											   	continue;
											   }
		 				                 	 
										 }	
									//}
									 }//for..
							   break;
				           
						 }else{
						 	
						 	continue;
						 }
	         
			 }//while...
		
			
		 		
		}//TakeInput...
		
	//*/
};


class MakeBoard{
	
	ConnectFourGame* connect4;
	public:
	
	MakeBoard(ConnectFourGame &_connect4){
		connect4=&_connect4;
	}
	
	 void CreateBoard() {
       

        for (int i = 0; i < connect4->rows; i++) {
            for (int j = 0; j < connect4->cols; j++) {
                cout << "|";

                if (j != connect4->cols) {
                    cout << "__";
                }

                if (connect4->board[i][j] != connect4->empty_Slot) {
                    cout << connect4->board[i][j];
                } else {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }
		
		
};//PrintBoard...



class GameManager{
	

		char Red_player='R';
		char Blue_player='B';
		
		char currentPlayer ='R';
		
     	Input  inputObj;
	
	     WinnerChecker* checkWinner ;  
	     MakeBoard* boardObj;
	     ConnectFourGame* connect4;
	       
	       
	       
		public:	
		
	GameManager(WinnerChecker &_checkWinner ,MakeBoard &_boardObj,ConnectFourGame& _connect4 ) :inputObj (_connect4)
	
   {
   	
	   checkWinner = &_checkWinner;
	   
	    boardObj=&_boardObj;
	    connect4= &_connect4;
   	}

		void PlayerChnage(){
			if(currentPlayer==Red_player){
				currentPlayer=Blue_player;
			}else{
				currentPlayer=Red_player;
			}
		}//PlayerChnage..
		
	
	bool isBoardFull(){

			for(int i=connect4->rows-1; i>=0;i--){
				
				for(int j=0; j<connect4->cols;j++){
					
					if(connect4->board[i][j]==' '){
						return false;
						
					}	
				}	
		 		                
         }//outer for..
		
			return true;
	}//isBoardFull
		
		
			void PlayGame(){
		 		 	
		 	while(true){
		 		
		 		cout<<"  player is "<<"->"<<currentPlayer<<endl;
		 		boardObj->CreateBoard();
		 		
		 		// Taking input...
		 		inputObj.TakeInput(currentPlayer);
		 		
		 		if(checkWinner->CheckWinner()==true){
		 			cout<<"Winner is "<<currentPlayer<<endl;
					 
					 break;
				 }
				 
				 if(isBoardFull()){
				 	cout<<"No one win"<<endl;
				 	break;
				 }
		 		//chnage Player...
		 		PlayerChnage();
		 		
		 		
		 	//	PlayerChnage();
		 	
		 		
		 		
		 		
			 }//while...
	
	}

	
		
};



int main() {
   
   int const  rows=6,cols=7;
ConnectFourGame   connectFourObj(rows,cols);
MakeBoard  makeBoard(connectFourObj);
    WinnerChecker  winnerChecker(connectFourObj);
    GameManager  gameManager(winnerChecker,makeBoard,connectFourObj);



    gameManager.PlayGame();





}




























