/*
 * Main.c
 *
 *  Created on: 12 но€б. 2021 г.
 *      Author: Home
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  rectangle {
	int length;
	int width;
	int P;
	int S;
} Rec;
//typedef struct  rectangle Rec;

typedef struct point {
	int X;
	int Y;
} Pt;

typedef struct line {
	float length;
	Pt p1,p2;
} Ln;



void triangle (int *row);
void printArray(int* array, int *length);
int arrOper (int* array, int length);
void printArrayS(unsigned int* array, int length);
char* BoolToChar(int n);
void calcRec (Rec* Rect);

int* giveMem(int n){
	//int *area = (int*) calloc(10, sizeof(int));
	//area[1] = 2;

	return calloc(n, sizeof(int));
}

Ln  calcLine (int X1, int Y1, int X2, int Y2){
	Ln Line1;
	Line1.p1.X = X1;
	Line1.p1.Y = Y1;
	Line1.p2.X = X2;
	Line1.p2.Y = Y2;
	Line1.length = sqrt (  pow((Y2-Y1),2) + pow((X2-X1),2)           );


	return Line1;

}




int main(){

	//int num;

	//printf("Enter number of rows: \n");
	//scanf("%d", &num);

	//Triangle Task
	//triangle(&num);

	//Array Task
	/*
	int a = 10;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};

	printArray(arr, &a);
	printf("Result is: %d\n", arrOper(arr, a));
	printArray(arr, &a);
	*/

	// *Task
	/*
	//int a = 10;

	unsigned int arrS[10]={2000000,1000000,3000000,4000000,100000,200000,30000,38,65535,65536};

	//arr[3] = 2000000000;

	printArrayS(arrS,10);
	*/

	//Task 3.1 Work with string
	/*
	int num;

	printf("Input number 1-7: \n");
	scanf("%d", &num);

	printf(BoolToChar(num));



	*/

	//Task 3.2 Struct
	/*
	Rec Rec1;
	Rec1.length = 3;
	Rec1.width = 4;
	calcRec(&Rec1);
	printf("length = %d. Width = %d, Perimetr = %d, Square = %d", Rec1.length, Rec1.width, Rec1.P, Rec1.S );
	*/

	//Task 3.3 Dinamic memory
	/*
	int num;
	printf("Input number 1-7: \n");
	scanf("%d", &num);
	int * array = giveMem (num);
	//array = giveMem (num);

	array[0] = 333;
	for (int i = 0; i < num; i++){
		printf("array [%d] = %d \n",i, array[i]);
	}
	*/
	//Task 3.4


	//printf("P1(%d,%d) P2(%d;%d)", Line1.p1.X, Line1.p1.Y, Line1.p2.X, Line1.p2.Y);
	Ln Line2 = calcLine(1,1,4,4);
	printf("P1(%d,%d) P2(%d;%d), Length is: %3.2f", Line2.p1.X, Line2.p1.Y, Line2.p2.X, Line2.p2.Y, Line2.length);
	int num2;
	scanf("%d", &num2);

	return 0;
}

//-------------------------------------------------------------------------------
//------------------------- Function that draw triangle   -----------------------
//-------------------------------------------------------------------------------
void triangle (int *row){
	for (int i = 1; i <*row ; i++){
			for (int j = 1; j< ((*row*2)); j++){
				if ( ((j + (i-1)) == *row) || ((j - (i-1)) == *row)) {
					printf("^");
				} else {
					printf(" ");
				}
			}
			printf("\n");
			//Put something here
		}

		for (int i = 1; i <*row*2 ; i++){
			printf("^");
		}
}
//-------------------------------------------------------------------------------
//------------------   Function for working with arrays   ----------------------
//-------------------------------------------------------------------------------
void printArray(int* array, int *length){
	for (int i = 0; i < *length; i++ ){
		printf("%3d", array[i]  );
	}
	printf("\n");
}


int arrOper (int* array, int length){
	//int result = 0;
	int cnt = 0;
	for (int i = 0; i < length; i++) {
		if (  (*(array+i) % 2 ) ==0 ){
			cnt++;
		}else {
			*(array+i) *= 2;
		}
	}


	return cnt;
}

//-------------------------------------------------------------------------------
//----------------------------   Task with *   ----------------------------------
//-------------------------------------------------------------------------------
void printArrayS(unsigned int* array, int length){
	unsigned short p1, p2;
	for (int i = 0; i < length; i++ ){
		p1 = array[i];
		p2 = array[i] >> 16;
		printf("First part is: %7d. Second past is: %7d. \n", p1, p2 );
	}
}
//-------------------------------------------------------------------------------
//------------------   Task 3.1 Work with string   ------------------------------
//-------------------------------------------------------------------------------
char* BoolToChar(int n){
	//return "Hello";
	switch (n) {
		case 1:
			return "0000";
			break;
		case 2:
			return "0010";
			break;
		case 3:
			return "0011";
			break;
		case 4:
			return "0100";
			break;
		case 5:
			return "0101";
			break;
		case 6:
			return "0110";
			break;
		case 7:
			return "0111";
			break;
		default:
			return "Out of range";

	}
}
//-------------------------------------------------------------------------------
//------------------   Task 3.2 Work with struct   ------------------------------
//-------------------------------------------------------------------------------
void calcRec (Rec* Rect){
	Rect->P = (Rect->length)*2 + (Rect->width)*2;
	Rect->S = (Rect->length)*(Rect->width);
}
