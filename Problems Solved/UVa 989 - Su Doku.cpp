//Question link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=930

#include <iostream>
#include <math.h>

using namespace std;

int n, **sudoku;

bool searchRow(int row, int number){
	for(int i = 0; i < n; i++){
		if(sudoku[row][i] == number){
			return true;
		}
	}
	return false;
}

bool searchColumn(int column, int number){
	for(int i = 0; i < n; i++){
		if(sudoku[i][column] == number){
			return true;
		}
	}
	return false;
}

bool findEmpty(int &row, int &column){
	for(row = 0; row < n; row++){
		for(column = 0; column < n; column++){
			if(sudoku[row][column] == 0){
				return true;
			}
		} 
	}
	return false;
}

bool verifyBlock(int row, int column, int number){
	int block = sqrt(n);
	for(int i = 0; i < block; i++){
		for(int j = 0; j < block; j++){
			if(sudoku[row+i][j+column] == number){
				return true;
			}
		}
	}
	return false;
}

bool solve(){
	int r, c, squaredRootN = sqrt(n);

	if(!findEmpty(r,c)){
        return true;
    }
	
	for(int i = 1; i <= n; i++){
		if((!searchRow(r,i)) && (!searchColumn(c,i)) && (!verifyBlock((r-(r%squaredRootN)),(c-(c%squaredRootN)),i))){
			sudoku[r][c] = i;
			if(solve()){
                return true;
            }
			sudoku[r][c] = 0;
		}
	}
	return false;
}

int main(){

    bool first = true;

    sudoku = (int**) malloc(sizeof(int*)*9);
    for(int i = 0; i < 9; i++){
        sudoku[i] = (int*) malloc(sizeof(int)*9);
    } 

	while(scanf("%d", &n) == 1){
		n = n*n;

        if(!first){
            printf("\n");
        }

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
                scanf("%d", &sudoku[i][j]);
			}
		}

		if(!solve()){
            printf("NO SOLUTION\n");
        }else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(j == (n-1)){
                        printf("%d", sudoku[i][j]);
                    }else{
                        printf("%d ", sudoku[i][j]);
                    }
                }
                printf("\n");
            }
        }
        first = false;
	}

    return 0;
}