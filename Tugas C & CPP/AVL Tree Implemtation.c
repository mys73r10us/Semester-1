#include <stdio.h>
#include <stdlib.h>


struct nodeavl{
	int angka;
	int tinggi;
	struct nodeavl *kiri;
	struct nodeavl *kanan;
};

int tinggi(struct nodeavl *N){
	if(N == NULL){
		return 0;
	}
	return N -> tinggi;
}
//Node Baru
struct nodeavl *temp(int angka){
	struct nodeavl *node = (struct nodeavl*)malloc(sizeof(struct nodeavl));
	
	node -> angka = angka;
	node -> kiri = NULL;
	node -> kanan = NULL;
	node -> tinggi = 1;
	return(node);
}

int max(int a, int b){
	return (a > b)? a : b;
//	if(a > b){
//		return a;
//	}
//	else{
//		return b;		
//	}
}

int getBalance(struct nodeavl *N){
	if(N == NULL){
		return 0;
	}
	return tinggi(N-> kiri) - tinggi(N -> kanan);
}

struct nodeavl *rotateKanan(struct nodeavl *y){
	struct nodeavl *x = y -> kiri;
	struct nodeavl *T2 = x -> kanan;
	
	//Pengubahan posisi
	x -> kanan = y;
	y -> kiri = T2;
	
	//Tinggi diperbarui
	y -> tinggi = max(tinggi(y->kiri), tinggi(y->kanan))+1;
	x -> tinggi = max(tinggi(x->kiri), tinggi(x->kanan))+1;
	
	return x;
}

struct nodeavl *rotateKiri(struct nodeavl *y){
	struct nodeavl *x = y -> kanan;
	struct nodeavl *T2 = x -> kiri;
	
	//Pengubahan posisi
	x -> kiri = y;
	y -> kanan = T2;
	
	//Tinggi diperbarui
	y -> tinggi = max(tinggi(y->kiri), tinggi(y->kanan))+1;
	x -> tinggi = max(tinggi(x->kiri), tinggi(x->kanan))+1;
	
	return x;
}

struct nodeavl *insert(struct nodeavl *node, int angka){
	if(node == NULL){
		return(temp(angka));
	}

	if(angka < node->angka){
		node -> kiri = insert(node -> kiri, angka);
	}
	else if(angka > node -> angka){
		node -> kanan = insert(node -> kanan, angka);
	}
	else{
		puts("Angka telah dimasukkan");
		return node;
	}
	
	node -> tinggi = 1 + max(tinggi(node->kiri), tinggi(node->kanan));
	
	//Pegecekan apakah seimbang
	int balance = getBalance(node);
	//L L C
	if(balance > 1 && angka < node -> kiri -> angka){
		return rotateKanan(node);
	}
	//R R C
	if(balance < -1 && angka > node -> kanan -> angka){
		return rotateKiri(node);
	}
	//L R C
	if(balance > 1 && angka > node -> kiri -> angka){
		node -> kiri = rotateKiri(node -> kiri);
		return rotateKanan(node);
	}
	//R L C
	if(balance < -1 && angka < node -> kanan -> angka){
		node -> kanan = rotateKanan(node -> kanan);
		return rotateKiri(node);
	}
	
	return node;
}

//Menuju node paling bawah dari kiri
struct nodeavl *minValNode(struct nodeavl* node){
	struct nodeavl* curr = node;
	
	while(curr -> kiri != NULL){
		curr = curr -> kiri;
	}
	return curr;
}

struct nodeavl *hapus(struct nodeavl *root, int angka){
	if(root == NULL){
		return root;
	}
	
	if(angka < root -> angka){
		root -> kiri = hapus(root -> kiri, angka);
	}
	else if(angka > root -> angka){
		root -> kanan = hapus(root -> kanan, angka);
	}
	else{
		if((root -> kiri == NULL) || (root -> kanan == NULL)){
			struct nodeavl *temp = root -> kiri ? root -> kiri: root -> kanan;
			//NCC
			if(temp == NULL){
				temp = root;
				root = NULL;
			}
			//OCC
			else{
				*root = *temp;
			}
			free(temp);
		}
		//NTC
		else{
			struct nodeavl* temp = minValNode(root-> kanan);
			
			root -> angka = temp -> angka;
			
			root -> kanan = hapus(root -> kanan, temp -> angka);
		}
	}
	//ketika tree hanya memiliki 1 node
	if (root == NULL){
		return root;
	}
	//update tinggi
	root -> tinggi = 1 + max(tinggi(root->kiri), tinggi(root->kanan));
	
	//cek keseimbangan tree
	int balance = getBalance(root);
	
	//L L C
	if(balance > 1 && getBalance (root -> kiri) >= 0){
		return rotateKanan(root);
	}
	//R R C
	if(balance < -1 && getBalance (root -> kiri) <= 0){
		return rotateKiri(root);
	}
	//L R C
	if(balance > 1 && getBalance(root -> kiri) < 0){
		root -> kiri = rotateKiri(root -> kiri);
		return rotateKanan(root);
	}
	//R L C
	if(balance < -1 && getBalance(root -> kanan) > 0){
		root -> kanan = rotateKanan(root -> kanan);
		return rotateKiri(root);
	}
	return root;
}

void preorder(struct nodeavl *root){
	if(root != NULL){
		printf("%d ", root -> angka);
		preorder(root -> kiri);
		preorder(root -> kanan);
	}
}

int main(){
	struct nodeavl *root = NULL;
	int pilih, angka;
	
	puts("Tree (1-500)\n");
	puts("---------------");
	puts("1. Insert");
	puts("2. Delete");
	puts("3. Cetak");
	puts("0. Exit");
	
	
	do{
		printf("\nMasukkan Pilihan : ");scanf("%d",&pilih);
		switch(pilih){
		case 1:
			printf("Masukkan Angka (1-500) : ");scanf("%d",&angka);
			if(angka > 1 && angka < 500){
			 	root = insert(root, angka);
			 	preorder(root);
			}
			else{
				puts("Angka Tidak dimasukkan");
			}
			break;
		case 2:
			printf("Masukkan Angka yang akan dihapus : ");scanf("%d",&angka);
			root = hapus(root, angka);
			printf("%d dihapus", angka);
			break;
		case 3:
			puts("Isi dari Tree Sekarang :");
			preorder(root);
			break;
		default:
			printf("Salah Input!\n");
		};
	}while(pilih != 0);
	
}

