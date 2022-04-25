#include <iostream>
using namespace std;
#include <vector>
#define dimX 5
#define dimY 5
//the maze problem



int main() {
   //initializing maze potentially having obstacles
   int maze[dimX][dimY];
   for(int i=0; i<dimX; i++) {
      for(int j=0; j<dimY; j++) {
         maze[i][j] = 0;
      }
   }
   //intializing obstacles
   maze[3][3] = 1;
   maze[3][4] = 1;

   //intializing solution maze ... the robot references the maze and will mark down its path in this solution maze
   int solution[dimX][dimY];
   for(int i=0; i<dimX; i++) {
      for(int j=0; j<dimY; j++) {
         solution[i][j] = 0;
      }
   }

   int r = 4, c = 0; //set starting point
   int move_made;         //flag to check if move made
   int lastMove;           //flag to check what the last move was 
   char movesMade[50];     //char array to store moves mades
   int index = 0;          //index iterator for char array moves made
   int backtrackCount = 0;    //varaible to keep track of number of times backtracked
   int noSolution = 0;           //flag to check if no solution possible

   while((r != 0) || (c != 4)){ //set destination here
         solution[r][c] = 1;
         move_made = 0;

         //going right
         if(c + 1 >= 0 && c + 1 < dimX && solution[r][c+1] == 0 && maze[r][c+1] == 0 && move_made == 0){
            c = c + 1;
            //movesMade.push_back('R');
            movesMade[index] = 'R';
            index++;
            move_made = 1;
            lastMove = 0;
            backtrackCount = 0;
         }
         //going up
         if(r - 1 >= 0 && r - 1<dimY && solution[r-1][c] == 0 && maze[r-1][c] == 0 && move_made == 0){
            r = r - 1;
            movesMade[index] = 'U';
            index++;
            move_made = 1;
            lastMove = 1;
            backtrackCount = 0;
         }

         //going down
         if(r+1 >= 0 && r + 1 < dimY && solution[r+1][c] == 0 && maze[r+1][c] == 0 && move_made == 0){ 
            r = r + 1;
            movesMade[index] = 'D';
            index++;
            move_made = 1;
            lastMove = 2;
            backtrackCount = 0;
         }

         //going left 
         if(c - 1 >=0 && c - 1<dimX && solution[r][c-1] == 0 && maze[r][c-1] == 0 && move_made == 0){
            c = c - 1;
            movesMade[index] = 'L';
            index++;
            move_made = 1;
            lastMove = 3;
            backtrackCount = 0;
         }

         //backtracking code 
         if(move_made == 0){                //move_made == 0 indicates that during an iteration of the while loop no move could be made
            maze[r][c] = 1;            //mark that position which no move could be made as an obstacle
            if(lastMove == 0){         //series of if else statments to see what the last move was made
               c = c - 1;              //once the last move made is determined it will reverse that move, backing out of the position it was stuck in                 
               movesMade[index] = '_';  //after that it will make another move and will not go back to the place it was trapped as it now sees it as an obstacle, popping its last move
               index++;
               backtrackCount++;       //count number of times back tracked so that we can determine if there is no solution
            }                          
            else if(lastMove == 1){    
               r = r + 1;
               movesMade[index] = '_';
               index++;
               backtrackCount++;
            }
            else if(lastMove == 2){
               r = r - 1;
               movesMade[index] = '_';
               index++;
               backtrackCount++;
            }
            else if(lastMove == 3){
               c = c + 1;
               movesMade[index] = '_';
               index++;
               backtrackCount++;
            }
            else{
               cout << "No move or backtrack possible. No solution.\n";
               break;
            }
         }

         if(backtrackCount > 2){
            cout << "No solution.";
            noSolution = 1;
            break;
         }

         
      
   }
   solution[r][c] = 1;

   if(!noSolution){
      //code to print solution
      printf("Solution found!\n");
      for(int i=0;i<dimX;i++) {
         for(int j=0;j<dimY;j++) {
            printf("%d\t",solution[i][j]);
         }
      printf("\n\n");
      }

      for(int i = 0; i < index; i++){
         cout << movesMade[i];
      }
   }
   
   
   return 0;

}








