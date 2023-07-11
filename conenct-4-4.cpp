#include <iostream>
#include <vector>
using namespace std;
class ConnectFourGame {
	
	//variables Needed............................
	public:
	int rows= 6;
	int cols=7;
	
	char Red_player='R';
	char Blue_player='B';
	char empty_Slot=' ';
	char exitkey='E';
	//  taking vector of charcters   for Board Creation.....
	char currentPlayer='R';
	vector< vector<char> > board;
	
	// initilaize the board and player  using  .Ctor
	ConnectFourGame():board(rows,vector<char>(cols,empty_Slot)){
		
		
		
	}
	
	//...  Input play game Method.......
	
	void PlayGame(){
		while(true){   
			
			MakeGameBoard();  
			cout<<endl;           // laying down the Board bfor the game .............
			int col;                      // Input value of comlum from user 
			cout<<endl;   
			cout<<"The current palyer is= "<<currentPlayer<<endl;
			
		cout<<" Please Select the colum you want to fill"<<endl;
		
		cin>>col;   // taking input ...
	 if(CheckrightInput(col)==true){
		  	TakeInput(col);
	    }//..
		  
		  
		  
		  if(CheckWinner()==true){
		  	cout<<"Winner=="<<currentPlayer<<endl;
		  	break;
		  		
		 }//.....
		  
		  if(isBoardFull()){
		cout<<"No one is winenr"<<endl;
	     break;
	}//
		  
		ChnagePlayer();
		
		
		}// while...
		
		
	}// Play game method..
	
	
	void ChnagePlayer(){
		
		if(currentPlayer==Red_player){
		currentPlayer=	Blue_player;
		}else{
		currentPlayer=	Red_player;	
		}
	}
	bool CheckWinner(){
		
		
			//checking Column Wise   winner 
	for(int i=0;i<cols-1;i++){
			for(int j=rows-1;j>rows-4;j--){

		if((board[i][j]!=empty_Slot)==true){
		
		if( board[i][j]==board[i-1][j] && board[i][j]==board[i-2][j] && board[i][j]==board[i-3][j]  ){
		
		return true;	
		}
		}//outer if..
	         }
		}///.....
		
			//checking Row Wise   winner 
		for(int i=rows-1;i>=0;i--){
			for(int j=0;j<4;j++){

		if((board[i][j]!=empty_Slot)==true){
		
		if( board[i][j]==board[i][j+1] && board[i][j]==board[i][j+2] && board[i][j]==board[i][j+3]  ){
		
	    	return true;	
		}
		}//outer if..
	         }
		}///.....
		
		
		
		
	 // Check for diagonal win (top-left to bottom-right)
                //    int i=0,j=0;
              // if (board[i][j] != empty_Slot && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]&&
			//	board[i][j] == board[i + 4][j + 4] && board[i][j] == board[i + 5][j + 5])
              //  {
              //    return true;
              // }
        

        //  Check for diagonal win (bottom-left to top-right)
       
            //   if (board[i][j] != empty_Slot && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3])
            //   {
             //    return true;
              //  }
       
        return false;
	}// check winner....
	
	//...................................................................................................
	bool CheckrightInput(int col){
		
		if(col>=0 && col<cols ){
			for (int i = 0; i < rows; i++) {
        if (board[i][col] == empty_Slot) {
            return true;
            }
       }
   }
		cout<<"Please give valid column "<<endl;
		return false;
	}
	//...................take Input............................................
  void 	TakeInput(int column){
		
		for(int i=rows-1;i>=0;i--){
	
				if(board[i][column]==empty_Slot){
				
					board[i][column]= currentPlayer;
					
					break;
				}
		
		}
		
	}//TakeInput..
	
	//................................................................
	void MakeGameBoard(){
		
		
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				
				cout<<"|";
				
				if(j!=cols){
			cout<<"__";	
				}
				
				if(board[i][j]!=empty_Slot){
					cout<<board[i][j];
				}else{
					cout<<' ';
				}
				
			}
				
			
			cout<<endl;
		}
		
	}//MakeBoard...

		
	bool isBoardFull(){
		for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
           if(board[i][j]!=empty_Slot){
           	return false;
		   }
        }
        }
        
        return true;
	}//isBoardFull...
	
	
	
	
};


int main() {
   
ConnectFourGame   obj;

obj.PlayGame();
    return 0;
}




























