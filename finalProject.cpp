#include <iostream>
using namespace std;
#define SIZE 5
//the maze problem



int main() {
   int maze[SIZE][SIZE] = {
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,1,1},
   {0,0,0,0,0}
   };

   int solution[SIZE][SIZE];

   for(int i=0; i<SIZE; i++) {
      for(int j=0; j<SIZE; j++) {
         solution[i][j] = 0;
      }
   }

   cout << "maze at start: \n";
   for(int i=0;i<SIZE;i++) {
      for(int j=0;j<SIZE;j++) {
         printf("%d\t",maze[i][j]);
      }
      printf("\n\n");
   }

   cout << "solution at start: \n";
   for(int i=0;i<SIZE;i++) {
      for(int j=0;j<SIZE;j++) {
         printf("%d\t",solution[i][j]);
      }
      printf("\n\n");
   }



   int r = 4, c = 0; //set starting point
   cout << "starting coordinates: r = " << r << " c = " << c << "\n";
   int flag;
   int lastMove;

   while((r != 0) || (c != 4)){ //set destination here
         solution[r][c] = 1;
         flag = 0;

         //going right
         if(c + 1 >= 0 && c + 1 < SIZE && solution[r][c+1] == 0 && maze[r][c+1] == 0 && flag == 0){
            c = c + 1;
            cout << "Moving right...\n";
            flag = 1;
            lastMove = 0;
         }
         //going up
         if(r - 1 >= 0 && r - 1<SIZE && solution[r-1][c] == 0 && maze[r-1][c] == 0 && flag == 0){
            r = r - 1;
            cout << "Moving up...\n";
            flag = 1;
            lastMove = 1;
         }

         //going down
         if(r+1 >= 0 && r + 1 < SIZE && solution[r+1][c] == 0 && maze[r+1][c] == 0 && flag == 0){ 
            r = r + 1;
            cout << "Moving down...\n";
            flag = 1;
            lastMove = 2;
         }

         //going left 
         if(c - 1 >=0 && c - 1<SIZE && solution[r][c-1] == 0 && maze[r][c-1] == 0 && flag == 0){
            c = c - 1;
            cout << "Moving left...\n";
            flag = 1;
            lastMove = 3;
         }

         if(flag == 0){ //if no moves can be made mark the cell as blocked and reverse the last move made
            maze[r][c] = 1;
            if(lastMove == 0){
               c = c - 1;
            }
            else if(lastMove == 1){
               r = r + 1;
            }
            else if(lastMove == 2){
               r = r - 1;
            }
            else{
               c = c + 1;
            }
         }
         
      
   }
   solution[r][c] = 1;

   //code to print solution
   for(int i=0;i<SIZE;i++) {
      for(int j=0;j<SIZE;j++) {
         printf("%d\t",solution[i][j]);
      }
      printf("\n\n");
   }

   return 0;

}







