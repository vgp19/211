#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	struct Node *next;
	int data;
	};

int isEmpty(int *arr);
int getKey(int value);
int add(int *arr, int value, int key);
int search(int *arr, int value, int key);
int main(int argc, char* argv[]){
	FILE *file;
	int num=0;
	int c=0;
	int j=2;
	int len=0;
	int err=0;
	char str[255];
	int hashTable[1000];
	//hashTable=(int *)malloc(sizeof(int)*1000);
	for(int i=0;i<1000;i++){
		hashTable[i]='\0';
	}
	if(argc<2){
		printf("error1\n");
		return 0;
	}
	file=fopen(argv[1],"r");
	if(file==NULL){
		printf("error2\n");
		return 0;
	}
	while(fgets(str,255,file)!=NULL){
		num=0;
		j=2;
		c=0;
		err=0;
		len=strlen(str);
		len=str[len-1]=='\n'?len-1:strlen(str);
			if((str[0]!='s' && str[0]!='i') || str[1]!='\t'){
				printf("error3\n");
			}else{
				if(str[2]-'0'==-3)
					c=1;
				for(int i= c==1?3:2;i<len;i++){
					if(!((str[i]-'0'>=0&&str[i]-'0'<=9))){
						printf("error4\n");
						i=strlen(str)+1;
						err=1;
					}	
				}
				if(err==0){
					if(c==1)
						j=3;
					while(j<len){
						num=num*10+(str[j]-'0');
						j++;
					}
					if(c==1)
						num=num*(-1);
					if(str[0]=='s'){
						if(search(hashTable,num,getKey(num))==1)
							printf("present\n");
						else
							printf("absent\n");
					}else{
						if(isEmpty(hashTable)==0){
							printf("error, hash table is full\n");
						}else{
							if(search(hashTable,num,getKey(num))==1){
								printf("duplicate\n");
							}else{
								add(hashTable,num,getKey(num));
								printf("inserted\n");
							}

						}
					}

				}
			}
	}
	fclose(file);
	//free(hashTable);
}

int getKey(int value){
	return(abs(value%1000));
}

int search(int *arr,int value, int key){
	int tmpKey=0;
	int result=0;
/*	if(*(arr+key).data==value){
		return 1;
	}else{
		if(key!=999)
			tmpKey=key;
		for(int i=tmpKey+1;i!=key&&i<1000;i++){
			if(*(arr+i).next==NULL)
				return 0;
			else{
				if(*(arr+i).data==value)
					return 1;
			}
			if(i==999)
				i=0;

		}
	}*/
		if(arr[key]=='\0')
			return 0;
		
		if(*(arr+key)==value)
			return 1;
		if(key!=999)
			tmpKey=key+1;
		for(int i=tmpKey;(i!=key&&i<1000);i++){
			if(*(arr+i)=='\0'){
				result=0;
				i=key;
			}else{
				if(*(arr+i)==value){
					result=1;
					i=key;
				}
			}
			if(i==999)
				i=0;	
		}
		return result;
}

int add(int *arr, int value, int key){
	//arr[temp] = malloc(sizeof(struct Node*))
	int tmpKey=0;
	int result=0;
	if(*(arr+key)=='\0'){
		*(arr+key)=value;
		return 1;
	}else{
		if(key!=999)
			tmpKey=key+1;
		for(int i=tmpKey;(i!=key&&i<1000);i++){
			if(*(arr+i)=='\0'){
				arr[i]=value;
				result=1;
				i=key;
			}
			if(i==999)
				i=0;
		}
		return result;
	}
}

int isEmpty(int *arr){
	for(int i=0;i<1000; i++){
		if(*(arr+i)=='\0')
			return 1;
	}
	return 0;
}