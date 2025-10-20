#include<stdio.h>
#include<string.h>
# define size 10
char*hashtable[size];
int hash(const char* value){
    int sum=0;
    for(int i=0;i<strlen(value);i++){
        sum=sum+ (int)value[i];
    }
    return sum % size;
}
int search(const char* value){
    if(hashtable[hash(value)]!=NULL && strcmp(hashtable[hash(value)],value) == 0){
        return hash(value);
    }
}
int main(){
    int i=0,n=0,choice=0,index=0,found=0;
    char value[10];
    for(i=0;i<size;i++){
        hashtable[i]=NULL;
    }
   while(1){
    printf("==HASHTABLE MENU==\n");
    printf("1.Insert\n");
    printf("2.Search\n");
    printf("3.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the name:\n");
            scanf(" %s",&value);
            hashtable[hash(value)]=value;
            break;
        case 2:
            printf("Enter the name to search:\n");
            scanf("%s",&value);
            found =search(value);
            printf("%s is found at position %d\n",value,found);
            break;
        case 3:
            printf("Exiting...\n");
            break;
    }
   }
   return 0;
}