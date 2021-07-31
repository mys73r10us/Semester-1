#include <stdio.h>
#define SIZE 5 
//Membuat konstanta size = 5

void insert(int);
void hapus();
void cetak();

int node[SIZE], front = -1, rear = -1;

int main() {
  int pilih, x;
  do{
	printf("\nInsert/Hapus/Print (1/2/3/0 untuk keluar) : ");scanf("%d",&pilih);
	switch (pilih){
		case 1:
			printf("Masukkan Angka : ");scanf("%d",&x);
			insert(x);
			cetak();
			break;
		case 2:
			hapus();
			break;
		case 3:
			cetak();
			break;
		case 0:
			break;
		default:
			printf("Salah Input...");
	};
  }while(pilih != 0);
  
  

  return 0;
}

void insert(int value){
	if(rear == SIZE - 1){
		printf("\nQueue Penuh...\n");
	}
	else{
		if(front == -1){
			front = 0;
		}
		rear++;
		node[rear] = value;
		printf("Angka %d diinsert\n", value);
	}
}

void hapus(){
	if(front == -1 ){
		printf("\nQueue Kosong...\n");
	}
	else{
		printf("\nDihapus : %d", node[front]);
	}
	front++;
	if(front > rear){
		front = rear = -1;
	}
}

void cetak(){
	if(rear == -1){
		printf("\nQueue Kosong...\n");
	}
	else{
		int i;
		printf("\nHasil : ");
		for (i=front; i<= rear ; i++){
			printf(" %d ", node[i]);
		}
	}
	printf("\n");
}
