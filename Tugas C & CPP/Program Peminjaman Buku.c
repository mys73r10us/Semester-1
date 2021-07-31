#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
	int data;
	char tajuk[3];
	char judul;
	
	struct node* l;
	struct node* r; 
};

struct antrian{
	int value;
	int tanggal;
	char nama[20];
	struct antrian *next;
}*temp = NULL;

struct antrian *head = 0;

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

bool checker(struct antrian *head, int tgl, int x, char name[20]){
	struct antrian *current = head;
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
	struct antrian *node = (struct antrian*) malloc(sizeof(struct antrian));
	
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


struct node* createnode(int data, char Tajuk[2], char judul) 
{
	struct node *newnode = malloc (sizeof(struct node));
	
	newnode->judul = judul;
	newnode->data = data;
	strcpy(newnode->tajuk, Tajuk);
	
	
	newnode->l = NULL;
	newnode->r = NULL;
	
	return newnode;
}

struct node* insert(struct node* root, int data, char tajuk[3], char judul)
{
	if (root == NULL )
		return createnode(data,tajuk,judul);
	
	if (data < root->data)
		root->l = insert(root->l,data,tajuk,judul);
	else if (data > root->data)
		root->r = insert(root->r,data,tajuk,judul);
	
	return root;
}

void inorder (struct node* root)
{
	if(root==NULL) return;
	printf("==========================================\n");
	printf("\t\t List Buku\n");
	printf("==========================================\n");
	printf("Entri\t|Tajuk\t|Judul\n");
	inorder(root->l);
	printf("%d\t|%s\t|%c\n",root->data,root->tajuk,root->judul);
	inorder(root->r);
}

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->l != NULL) 
        current = current->l; 
  
    return current; 
}

struct node* deleteNode(struct node* root, int nomor, char tajuk[3], char judul){ 
   	if (root == NULL) return root; 
    if (nomor < root->data) 
        root->l = deleteNode(root->l, nomor, tajuk, judul); 
    else if (nomor > root->data) 
        root->r = deleteNode(root->r, nomor, tajuk, judul); 
    else
    { 
        if (root->l == NULL) 
        { 
            struct node *temp = root->r; 
            free(root); 
            return temp; 
        } 
        else if (root->r == NULL) 
        { 
            struct node *temp = root->l; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->r);  
        root->data = temp->data; 
        root->r = deleteNode(root->r, temp->data, temp->tajuk, temp->judul); 
    } 
    return root; 
} 

struct node *search(struct node* root, int data, char tajuk[3], char judul){
	struct node *curr = root;
	while(curr!=NULL){
		if(root -> data == data && root->judul == judul){
			printf("Buku ada...\n");
			inorder(root);
			return root;
		}
		if(root -> data < data){
			return search(root->r, data, tajuk, judul);
		}
		return search(root->l, data, tajuk, judul);
	}
	printf("Buku tidak ada..\n");
}


int main() {
	int angka, pilih, tgl, jumlah_buku, valid;
	char nama[20];
	char tajuk[3];
	char judul;
	struct node *root =NULL;
	
	do{
		puts("1. Insert Book");
		puts("2. Cari Book");
		puts("3. Borrow Book");
		puts("4. Return Book");
		puts("5. Cek Antrian");
		printf("Pilih : ");scanf("%d", &pilih);
		if(pilih == 1){ 
			scanf("%c", &judul);
			printf("Masukkan Nomor Entri Buku : ");scanf("%d",&angka);
			printf("Tajuk buku [3] & Judul Depan Buku ex(mvpE) : ");scanf("%s", tajuk);
			//SEBELUM
		/*	printf("Masukkan Entri : ");scanf("%d", &angka);
			printf("Tajuk[3] : ")scanf("%s", tajuk);
			printf("Masukkan Judul : "):scanf("%c", &judul); */
			
		
			if(root == NULL){
				root = insert(root, angka, tajuk, judul);
				inorder(root);
			}
			else{
				insert(root, angka, tajuk, judul);
				inorder(root);
			}
		}
		else if(pilih == 2){
			if(root == NULL){
				printf("Buku tidak ada..\n");
			}
			else{
				printf("Masukkan Nomor Entri Buku : ");scanf("%d",&angka);
				printf("Tajuk buku [3] : ");scanf("%s", tajuk);
				gets(tajuk);
				printf("Huruf Depan Judul Buku : ");scanf("%c", &judul);
				search(root, angka, tajuk, judul);
			}
		}
		else if(pilih == 3){
			printf("Masukkan Nomor Entri Buku : ");scanf("%d",&angka);
			printf("Tajuk buku [3] : ");scanf("%s", tajuk);
			gets(tajuk);
			printf("Huruf Depan Judul Buku : ");scanf("%c", &judul);
			deleteNode(root, angka, tajuk, judul);
			printf("Anda ingin meminjam buku yang lain ? (1/0): ");scanf("%d", &valid);
			switch(valid){
				case 1:
					printf("Masukkan Nomor Entri Buku : ");scanf("%d",&angka);
					printf("Tajuk buku [3] : ");scanf("%s", tajuk);
					gets(tajuk);
					printf("Huruf Depan Judul Buku : ");scanf("%c", &judul);
					deleteNode(root, angka, tajuk, judul);
					return;
				default:
					printf("Nama : ");scanf("%s", nama);
					printf("Tanggal peminjaman : ");scanf("%d", &tgl);
					printf("Jumlah Buku : ");scanf("%d", &jumlah_buku);
					insert_depan(jumlah_buku, tgl, nama);
					
			};
			
		}
		else if(pilih == 4){
			scanf("%c", &judul);
			printf("Masukkan Nomor Entri Buku : ");scanf("%d",&angka);
			printf("Tajuk buku [3] & Judul Depan Buku ex(mvpE) : ");scanf("%s", tajuk);
			if(root == NULL){
				root = insert(root, angka, tajuk, judul);
				inorder(root);
			}
			else{
				root = insert(root, angka, tajuk, judul);
				inorder(root);
			}
			
		}
		else if(pilih == 5){
			cetak();
		}
	
	}while(pilih != 0);
	
	return 0;
}

//Kodingan ini saya buat dengan Melanjutkan kodingan Lab BST dan lab Linked List 

