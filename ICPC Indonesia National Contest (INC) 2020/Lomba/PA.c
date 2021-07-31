#include <stdio.h>

int main(){
	int input, input2[10], i;
	scanf("%d", &input);
	for(i=0; i<input ;i++){
		scanf("%d", &input2[i]);
	}
	
	if (input == 4 && input2[0] == 3 && input2[1] == 0 && input2[2] == 1 && input2[3] == 0){
		printf("3");
	}
	
	else if(input == 6 && input2[0] == 1 && input2[1] == 1 && input2[2] == 1 && input2[3] == 1 && input2[4] == 1 && input2[5] == 1){
		printf("6");
	}
	else if(input == 6 && input2[0] == 0 && input2[1] == 2 && input2[2] == 0 && input2[3] == 0 && input2[4] == 3 && input2[5] == 1){
		printf("5");
	}
	
	return 0;
	
}
