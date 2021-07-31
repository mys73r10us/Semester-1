#include <stdio.h>
#include <stdlib.h>

// A linked list node 
struct Node 
{ 
	int value;
	int data; 
  	struct Node *next; 
}*head, *temp = NULL;



void insert_depan(int x){
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	node -> data = x;
	node -> next = NULL;
	if (head != NULL){
		node -> next = head;
		head = node;
	}
	else{
		head = node;
	}
}

void insert_belakang(int x){
//	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
//	struct Node *current = (struct Node*)malloc(sizeof(struct Node));
//	
//	node -> data = x;
//	node -> next = NULL;
//	if(head != NULL){
//		current = head;
//		while (current->next != NULL){
//			current = current -> next;
//		}
//		current -> next = node;
//		node -> next = NULL;
//	}
//	else{
//		head = node;
//	}
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node -> data = x;
	node -> next = NULL;
	if(head != NULL){
		temp = head;
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = node;
		node -> next = NULL;
	}
	else{
		head = node;
	}
}

void insert_posisi(int index, int x){
	struct Node *node = (struct Node*)malloc(sizeof(struct Node));
	node -> data = x;
	node -> next = NULL;
	if (head!=NULL){
		temp = head;
		if (index == 0){
			node -> next = head;
			head = node;
		}
		else{
			while(index > 1 && temp->next != NULL){
				temp = temp -> next;
				index--;
			}
			if (index > 1 && temp -> next == NULL){
			temp -> next = node;
			}
			else{
				struct Node *ptr = temp -> next;
				temp -> next = node;
				node -> next = ptr;
			}
		}
	}
	else{
		head = node;
	}
}

void cetak(){
	temp = head;
	printf("\nList :");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp -> next;
	}
	printf("\n\n");
}


void hapus_depan(){
	struct Node *temp = head;
	head = head -> next;
	free(temp);
}

void hapus_belakang(){
	struct Node *temp = head;
	while(temp -> next -> next != NULL){
		temp = temp -> next;		
	}
	free(temp -> next);
	temp -> next = NULL;
}

void hapus_tengah(int val){
	int i;
	struct Node *toDelete, *prevNode;
	
	if (head == NULL){
		printf("wrong!");
	}
	else{
		toDelete = head;
		prevNode = head;
		for(i=2; i<=val; i++){
			prevNode = toDelete;
			toDelete = toDelete->next;
			if(toDelete == NULL){
				break;
			}
		}
		if(toDelete!=NULL){
			if(toDelete == head){
				head = head -> next;
			}
			prevNode -> next = toDelete->next;
			toDelete -> next = NULL;
			free(toDelete);
		}
		else{
			printf("Invalid Position");
		}
	}
}
//void cetak_deret()
//{
//	temp = head;
//	printf("\nISI list sekarang adalah : "); 
//	while (temp!=NULL)
//	{
//		printf("%d ", temp->value);
//		temp=temp->next;
//	}
//	printf("\n\n"); // pindah baris setelah cetak list
//}



int main(int argc, char *argv[]) {
	int x, v, y, i;
	do{
		if (head == NULL){
		
			printf("Masukkan Angka (0 untuk keluar): "); scanf("%d",&x);
			printf("Belakang/Depan/Posisi (0/1/2) : ");scanf("%d",&y);
			if (y==0){
				insert_belakang(x);
			}
			else if (y==1){
				insert_depan(x);
			}
			else if (y==2){
			printf("Masukkan index : ");scanf("%d",&i);
			insert_posisi(i, x);
			}
			cetak();
			printf("ingin hapus depan/belakang/Tengah (1/0/2) : ");scanf("%d", &v);
			if (v == 1){
				hapus_depan();
			}
			else if (v == 0){
				hapus_belakang();
			}
			else if(v == 2){
				printf("Index ke? : ");scanf("%d",&i);
				hapus_tengah(i);
			}
			cetak();
		}
		else{
			printf("ingin hapus depan/belakang/Tengah (1/0/2) : ");scanf("%d", &v);
			if (v == 1){
				hapus_depan();
			}
			else if (v == 0){
				hapus_belakang();
			}
			else if(v == 2){
				printf("Index ke? : ");scanf("%d",&i);
				hapus_tengah(i);
			}
			cetak();
			printf("Masukkan Angka (0 untuk keluar): "); scanf("%d",&x);
			printf("Belakang/Depan/Posisi (0/1/2) : ");scanf("%d",&y);
			if (y==0){
				insert_belakang(x);
			}
			else if (y==1){
				insert_depan(x);
			}
			else if (y==2){
			printf("Masukkan index : ");scanf("%d",&i);
			insert_posisi(i, x);
			}
			cetak();
			printf("ingin hapus depan/belakang/Tengah (1/0/2) : ");scanf("%d", &v);
			if (v == 1){
				hapus_depan();
			}
			else if (v == 0){
				hapus_belakang();
			}
			else if(v == 2){
				printf("Index ke? : ");scanf("%d",&i);
				hapus_tengah(i);
			}
			cetak();
			
		}
	}while (x!=0);
	
	return 0;
}
	
