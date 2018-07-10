#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct students{ //öğrenci bilgilerini tutmak için veri tipimiz
	char name[20];
	char surname[20];
	int num;
	struct students *back;
}linkedList;

linkedList *first=NULL, *end=NULL; //liste başlangıçta boş


int add(linkedList *q); //listeye yeni düğüm ekleme
int listing(); //listeleme
void printList(linkedList *yazilacak);//liste yazdırma fonksiyonu
linkedList *search(int aranan);// arama fonksiyonu(numaraya göre) 
linkedList *del(int silinecek);//silme fonksiyonu
linkedList *scanKey();//klavye okuma





int main(int argc, char *argv[]) {
	
	
	linkedList *eklenecek, *k;
	int no,sonuc;
	int secim;
	
	while(1){
		printf("------------------------------------------------\n");
		printf("[1]Ekleme\n\n[2]Listele\n\n[3]Arama\n\n[4]Silme\n\n[0]Cikis\n\n");
		printf("------------------------------------------------\n");
		printf("Seciminizi Giriniz: ");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				eklenecek=scanKey();
				if(eklenecek!=NULL)
					add(eklenecek);
				else
					printf("Bellek Dolu!!!\n\n");
				break;
			case 2:
				sonuc=listing();
				if(sonuc==-1)
					printf("Bos Liste\n\n");
				break;
			case 3:
				puts("Aranan numara:");
				scanf("%d",&no);
				k=search(no);
				if(k==NULL)
					printf("Aranan Bulunamadi!\n\n");
				else printList(k);
				break;
			case 4:
				puts("silinecek kisinin numarasini gir: ");
				scanf("%d",no);
				k=del(no);
				if(k=NULL)
					printf("--Silindi--\n");
				else 
					printf("Silmek istediginiz kisi bulunamadi");
			case 0:
				exit(0);
			
				
		}
	}
	
	return 0;
}





int add(linkedList *q){
	if(first!=NULL){
		end->back = q;
		end=q;
		end->back=NULL;
	}
	
	else{
		first=q;
		end=q;
		first->back=NULL;
	}
return 0;
}

int listing(){
	
	linkedList *g;
	g=first;
	if(g==NULL)
		return -1;
		
	while(g!=NULL){
		printList(g);
		g=g->back;
	}
return 0;	
}
void printList(linkedList *yazilacak){
	
	printf("isim: %s\t\tsoyisim %s\t\tnumara: %d\n",yazilacak->name,yazilacak->surname,yazilacak->num);
}
linkedList *search(int aranan){
	linkedList *p;
	p=first;
	while(p!=NULL){
		if(p->num==aranan)
			return p;
	}
		return NULL;
}
linkedList *del(int silinecek){
	linkedList *p, *previous;
	p=first;
	while(p!=NULL){
		if(silinecek==p->num)
			break;
		previous=p;
		p=p->back;
	}
	if(p!=NULL){
		if(previous==NULL){
			if(first==end){
				first=NULL;
				end=NULL;
			}
			else 
				first=first->back;
		}
		else{
			previous->back=p->back;
			if(previous->back==NULL)
				end=previous;
		}
		free(p);
		return p;
		
	}
	else
		return NULL;
}
linkedList *scanKey(){
	linkedList *okunan;
	okunan=malloc(sizeof(linkedList));
	if(okunan==NULL)
		return NULL;
	
	puts("isim: ");
	scanf("%s",okunan->name);
	puts("soyisim: ");
	scanf("%s",okunan->surname);
	puts("numara: ");
	scanf("%d",&(okunan->num));
	return okunan;
}
