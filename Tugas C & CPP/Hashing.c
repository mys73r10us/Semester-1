#include <limits.h>
#include <stdio.h>

void insert(int ary[], int hFn, int size){
	int element, pos, n = 0;
	
	printf("Masukkan Angka : ");scanf("%d",&element);
	
	pos = element % hFn;
	
	while(ary[pos] != INT_MIN){
		if(ary[pos] == INT_MAX){
			break;
		}
		pos = (pos + 1)%hFn;n++;
		if(n==size){
			break;
		}
	}
	if(n==size){
		printf("Hash telah Full\n\n");
	}
	else{
		ary[pos] = element;
	}	
}

void hapus(int ary[], int hFn, int size){
	int element, n=0, pos;
	
	printf("Masukkan angka yang akan dihapus : ");scanf("%d", &element);
	
	pos = element % hFn;
	
	while(n++ != size){
		if(ary[pos] == INT_MIN){
			printf("Element tidak ditemukan\n\n");
			break;
		}
		else if(ary[pos] == element){
			ary[pos] = INT_MAX;
			printf("Element telah dihapus\n\n");
			break;
		}
		else{
			pos = (pos + 1) % hFn;
		}
	}
	if(--n == size){
		printf("Element tidak ditemukan\n");
	}
}

void cari(int ary[], int hFn, int size){
	int element, pos, n=0;
	
	printf("Masukkan angka yang akan dicari : ");scanf("%d",&element);
	
	pos = element % hFn;
	
	while(n++ != size){
		if(ary[pos] == element){
			printf("Element %d ditemukan di index %d\n",element,pos);
			break;
		}
		else{
			if(ary[pos] == INT_MAX || ary[pos] != INT_MIN){
				pos = (pos + 1) % hFn;
			}
		}
	}
	if(--n == size){
		printf("Element tidak ditemukan\n");
	}
}

void cetak(int ary[], int size){
	int i;
	
	printf("Index\tValue\n");
	
	for(i=0; i < size; i++){
		printf("%d\t%d\n",i,ary[i]);
	}
}

int main(){
	int size, hFn, i, choice;
	
	printf("Masukkan size yang akan digunakan : ");scanf("%d",&size);
	
	int ary[size];
	
	printf("Masukkan fungsi hash(Pembagi) : ");scanf("%d",&hFn);
	
	for(i=0; i<size; i++){
		ary[i] = INT_MIN;
	}
	
	do{
		printf("Masukkan pilihan\n");
		printf("Insert, Hapus, Cetak, Cari(1, 2, 3, 4)\n");scanf("%d",&choice);
		
		switch(choice){
			case 1:
				insert(ary, hFn, size);
				break;
			case 2:
				hapus(ary, hFn, size);
				break;
			case 3:
				cetak(ary, size);
				break;
			case 4:
				cari(ary, hFn, size);
			default:
				printf(" : ");
				break;
		}
		
	}while(choice);
	
	return 0;
}





