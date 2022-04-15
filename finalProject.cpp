#include <iostream>
using namespace std;
#define SIZE 5
//the maze problem
int maze[SIZE][SIZE] = {
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,0,0},
   {0,0,0,1,1},
   {0,0,0,0,0}
};
//matrix to store the solution
int solution[SIZE][SIZE];
//function to print the solution matrix
void printsolution() {
   int i,j;
   for(i=0;i<SIZE;i++) {
      for(j=0;j<SIZE;j++) {
         printf("%d\t",solution[i][j]);
      }
      printf("\n\n");
   }
}
//function to solve the maze
//using backtracking
int solvemaze(int r, int c) {
   //if destination is reached, maze is solved
   //destination is the last cell(maze[SIZE-1][SIZE-1])
   if((r==0) && (c==4)) {  //set destination here
      solution[r][c] = 1;
      return 1;
   }
   //checking if we can visit in this cell or not
   //the indices of the cell must be in (0,SIZE-1)
   //and solution[r][c] == 0 is making sure that the cell is not already visited
   //maze[r][c] == 0 is making sure that the cell is not blocked
   if(r>=0 && c>=0 && r<SIZE && c<SIZE && solution[r][c] == 0 && maze[r][c] == 0){
      //if safe to visit then visit the cell
      solution[r][c] = 1;
      //going down
      if(solvemaze(r+1, c)) 
         return 1;
      //going right
      if(solvemaze(r, c+1))
         return 1;
      //going up
      if(solvemaze(r-1, c)) 
         return 1;
      //going left 
      if(solvemaze(r, c-1)) 
         return 1;
      //backtracking
      solution[r][c] = 0;
      return 0;
   }
   return 0;
}
int main() {
   //making all elements of the solution matrix 0
   int i,j;
   for(i=0; i<SIZE; i++) {
      for(j=0; j<SIZE; j++) {
         solution[i][j] = 0;
      }
   }
   if (solvemaze(4,0)) // input robot starting destination 
      printsolution();
   else
      printf("No solution\n");
   return 0;
}





























// #include <stdio.h>

// struct cell{
// 	int ob;
// 	int xCord;
// 	int yCord;
// };

// int main()
// {
// 	int dimX = 5, dimY = 5; //dimensions of the board
// 	int ob; //obstiacle 
// 	//target has corrdinates xt, yt
// 	int goalX = 0, goalY = 4; //goal is set to top right
// 	int robotX = 4, robotY = 0; //robot is set to bottom left
// 	int goalReached = 0;
// 						//x =  0, 1, 2, 3, 4
// 	int maze[dimX][dimY] = { { 0, 0, 0, 0, 0 },  //y = 0
// 					         { 0, 0, 0, 0, 0 },  //y = 1
// 					         { 0, 0, 0, 0, 0 },  //y = 2
// 					         { 0, 0, 0, 0, 0 },  //y = 3
// 							 { 0, 0, 0, 0, 0 }}; //y = 4
// 	maze[goalX][goalY] = 3;

// 	int mazeSol[dimX][dimY]; // matrix to store the solution 

// 	//loop to find destination in top right
// 	//while(goal is not reached){
// 	//	try to move down  // x 
// 	//	try to move left
// 	//	try to move right
// 	//	try to move up
// 	// 	at each move check to see if the move is valid (inside the board and does not move into wall)
// 	// 	if it is valid make the move and check if the goal is reached
// 	//}

// 	while(goalReached == 0){
// 		if(maze[robotX][robotY])
// 	}






	
// 	return 0;
// }
