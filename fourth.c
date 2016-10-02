#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size=0;
int counter0;
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
	
	for(int i=0;i<1000;i++){
		hashTable[i]='\0';
	}
	/*for(int i=0;i<1000;i++){
		printf("number at %d is %d\n",i,hashTable[i]);
	}*/
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
								size++;
							}

						}
					}

				}
			}
	}
	/*for(int i=0;i<1000;i++){
		printf("number at %d is %d\n",i,hashTable[i]);
	}*/
	fclose(file);
	//free(hashTable);
}

int getKey(int value){
	return(abs(value%1000));
}

int search(int *arr,int value, int key){
	int tmpKey=0;
	int result=0;
	int i;
		if(arr[key]=='\0')
			return 0;
		
		if(arr[key]==value)
			return 1;
		if(key!=999)
			tmpKey=key+1;
		for(i=tmpKey;i!=key;i=i+1){
			if(arr[i]=='\0'){
				return 0;
			}else{
				if(arr[i]==value){
					return 1;
				}
			}
			if(i==999)
				i=0;
		}
		return 0;
}

int add(int *arr, int value, int key){
	int tmpKey=0;
	int result=0;
	int i;
	if(*(arr+key)=='\0'){
		*(arr+key)=value;
		return 1;
	}else{
		if(key!=999)
			tmpKey=key+1;
		for(i=tmpKey;(i!=key&&i<1000);i++){
			
			if(arr[i]=='\0'){
				arr[i]=value;
				return 1;
			}
			if(i==999)
				i=0;
			
		}
		return 0;
	}
}

int isEmpty(int *arr){
	if(size==1000)
		return 0;
	else
		return 1;
}