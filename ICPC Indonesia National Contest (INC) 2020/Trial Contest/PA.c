#include <stdio.h>

int main(){
	int match, bns[101], bnsO[101], total = 0, i;
	scanf("%d", &match);
	
	for(i=0; i<match; i++){
		scanf("%d", &bns[i]);
	}
	for(i=0; i<match; i++){
		scanf("%d", &bnsO[i]);
	}
	
	for(i=0; i<match; i++){
		if (bns[i] > bnsO[i]){
			total += 3;
		}
		else if (bns[i] == bnsO[i]){
			total += 1;
		}
	}
	printf("%d", total);
}
