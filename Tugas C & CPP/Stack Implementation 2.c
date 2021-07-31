#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};
struct node *head;

void push(){
	int val;
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("Error");
	}
	else{
		printf("Masukkan Angka : ");scanf("%d",&val);		
		if(head == NULL){
			ptr -> val = val;
			ptr -> next = NULL;
			head = ptr;
		}
		else{
			ptr -> val = val;
			ptr -> next = head;
			head = ptr;
		}
		puts("Berhasil....");
	}
}

void pop(){
	int item;
	struct node *ptr;
	if (head == NULL){
		printf("\nError (Underflow)...\n");
	}
	else{
		item = head -> val;
		ptr = head;
		head = head -> next;
		free(ptr);
		printf("Popped");
	}
}

void cetak(){
	int i;
	struct node *ptr;
	ptr = head;
	if(ptr == NULL){
		printf("Stack Kosong\n");
	}
	else{
		printf("Isi Stack : ");
		while(ptr != NULL){
			printf(" %d ", ptr -> val);
			ptr = ptr -> next;
		}
	}
}

void main(){
	int pilih = 0;
	while(pilih != 4){
//      	printf("\nMasukkan Angka(4 untuk keluar) : ");
//        scanf("%d",&pilih);  
//        push(pilih);
//        cetak();
        printf("\n1. Push\n2. Pop\n3.Cetak\n4. Exit\n");
		printf("Masukkan pilihan : ");scanf("%d",&pilih);
        switch(pilih){
        	case 1:{
        		push();
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				cetak();
				break;
			}
			case 4:{
				printf("Bye...");
				break;
			}
			default:{
				printf("Salah Input");
			}
				
		};
	}  
}

