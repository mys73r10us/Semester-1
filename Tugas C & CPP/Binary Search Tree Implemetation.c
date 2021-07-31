#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	char namaP[3];
	char hurufDepan;
	
	struct node *left, *right;
};

struct node *newNode(int item){
	char namaP[3];
	char hurufDepan;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> key = item;
	temp -> namaP[3]= item
	temp -> hurufDepan = item;
	
	temp -> left = temp -> right = NULL;
	return temp;
}

struct node *cari(struct node *root, int x){
	if(root == NULL || root -> key == x){
		return root;
	}
	else if(x > root -> key){
		return cari(root -> right, x);
	}
	else{
		return cari(root -> left, x);
	}
}

void inorder(struct node *root){
	if (root != NULL){
		inorder(root -> left);
		printf("%d \n", root->key);
		inorder(root -> right);
	}
}

struct node *insert(struct node *node, int key, char namaP[3], char hurufDepan){
	if(node == NULL){
		return newNode(key);  
	}
	
	if(key < node -> key ){
		node -> left = insert(node -> left, key, namaP[3], hurufDepan);
	}
	else if(key > node -> key){
		node -> right = insert(node -> right, key, namaP[3], hurufDepan);
	}
	
	return node;

}



int main(){
	int pilih, angka;
	char namaP[3], hurufDepan;
	struct node *root = NULL;
	printf("Masukkan nomor urut Buku pertama : ");scanf("%d", &angka);
	printf("Masukkan Singkatan Nama Pengarang : ");scanf("%c", &namaP);	
	printf("Masukkan Huruf Depan dari judul Buku : ");scanf("%c", &hurufDepan);
	
	root = insert(root, angka, namaP[3], hurufDepan);
	do{
		printf("Insert/Cetak/Cari (1/2/3) : ");scanf("%d",&pilih);
		if(pilih == 1){
			printf("Masukkan Angka : ");scanf("%d",&angka);
			insert(root, angka, namaP[3], hurufDepan );
		}
		else if(pilih == 2){
			inorder(root);
		}
		else if(pilih == 3){
			printf("Masukkan Angka yang akan dicari : ");scanf("%d",&angka);
			cari(root, angka);
		}
		else if(pilih == 0){
			break;
		}
	}while(pilih != 0);
	
	
	return 0;
}
