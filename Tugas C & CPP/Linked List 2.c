#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct tnode{
	int value;
	int tanggal;
	char nama[20];
	struct tnode *next;
}*temp = NULL;

struct tnode *head = 0;

void cetak(){
	temp = head;
	printf("\tList Peminjaman\n");
	printf("++++++++++++++++++++++++++++++\n");
	printf("Jumlah \t| Tanggal \t| Nama\n");

	while (temp != NULL){
		printf(" %d \t| %d \t\t|   %s\n", temp->value, temp->tanggal, temp->nama);
		temp = temp -> next;
	}
	printf("\n\n");
}

bool checker(struct tnode *head, int tgl, int x, char name[20]){
	struct tnode *current = head;
	while(current != NULL){
		if(strcmp(current -> nama, name)== 0 && (current -> tanggal = tgl)){
			printf("============================================================================================");
			printf("\n\n\tAnda Belum Mengembalikan Buku yang Sedang dipinjam Hey... Malah Minjam lagi\n\n");
			printf("============================================================================================\n");
			return true;
			
		}
		current = current -> next;
	}
	return false;
}

void insert_depan(int x, int tanggal, char nama[20]){
	bool valid;
	struct tnode *node = (struct tnode*) malloc(sizeof(struct tnode));
	
	valid =	checker(head, tanggal, x, nama);
	if(valid == true){
		return;
	}
	
	node -> tanggal = tanggal;
	node -> value = x;
	strcpy(node -> nama, nama);
	
	node -> next = NULL;
	if (head != NULL){
		node -> next = head;
		head = node;
	}
	else{
		head = node;
	}
}

void hapus(struct tnode *head, int tgl, int x, char name[20]) { 
	char valid;
	struct tnode *ptr = head;
	struct tnode *current = head;
	if((strcmp(current -> nama, name)==0) && (current -> tanggal = tgl)){
		printf("=======================================\n");
		printf("\n\nNama : %s\n", name);
		printf("Tanggal Peminjaman : %d \n\n", tgl);
		printf("=======================================\n");
		
		head = head -> next;
		free(current);
	}
	while(ptr->next != NULL && ptr->next->tanggal != tgl && strcmp(current -> nama, name)!= 0){
		ptr =  ptr -> next;
	}
} 


int main(){
	int x, tanggal, cari, pilih;
	char nama[20];
	char ch;
	do{
		puts("1. Insert");
		puts("2. Hapus");
		puts("3. Cari");
		printf("Choose ur option : ");scanf("%d", &pilih);
		if(pilih == 1){
			printf("Nama : ");scanf("%s", nama);
			printf("Masukkan tanggal(1-31) : ");scanf("%d", &tanggal);
			if(tanggal > 31){
				printf("Bukan Tanggal...");
				return;
			}
			printf("Masukkan Jumlah buku : ");scanf("%d", &x);


			insert_depan(x, tanggal, nama);
			cetak();
		}
		else if(pilih == 2){
			printf("Nama : ");scanf("%s", nama);
			printf("Masukkan tanggal peminjaman : ");scanf("%d", &tanggal);
			printf("Masukkan Jumlah buku yang dipinjam : ");scanf("%d", &x);
			hapus(head, tanggal, x, nama);

		}
	}while (pilih!= 0);
	
	return 0;
}
