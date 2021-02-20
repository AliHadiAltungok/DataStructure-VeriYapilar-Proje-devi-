#include <stdio.h>                    
#include <stdlib.h>
			//Ali Hadi Altungök 181180760
            //DATA STRUCTURES (CENG205  2.Þube  MÜHENDÝSLÝK FAKÜLTESÝ)
            //FÝNAL
 
struct node
{
	char data[50];
    //int data;
    struct node *next;
    struct node *prev;    
};
typedef struct node n;
 
n *new_node, *ne,*new_node2; 
n *head = NULL, *last = NULL, *flg=NULL, *playing=NULL, *head2=NULL,*last2 =NULL ;

void printPlayList(char yonu);
void playSong(char yonu);
void RemoveSong(char* nameIn);
void reverse();
void MoveSong(char yeri,char* nameIn,char* nameIn2);
void insert_at_end(char* nameIn);
void insert_at_first(char* nameIn);
void yaz();
void insert_at_end2(char* nameIn);

FILE* filePtr;
FILE* output;

void dnm(char* nameIn, char* nameIn2){
	char name[50];
	char name2[50];
	int i;
	for(i = 0; i < 20; i++) {
        if(*(nameIn+i) == '\n') {
            name[i] = '\0';

        } else {
            name[i] = *(nameIn+i);
        }
    }
    for(i = 0; i < 30; i++) {
        if(*(nameIn2+i) == '\n') {
            name2[i] = '\0';

        } else {
            name2[i] = *(nameIn2+i);
        }
    }
    
    printf("\n%s-------%s----\n",name,name2);
	
    
}

void main()
{
	
	filePtr =fopen("input.txt", "r");
	output =fopen("output.txt", "w");
	fclose(output);
	
	
	output=fopen("output.txt","w");
  		fseek(output,0,SEEK_END);
  		//fprintf(output,"Cannot Remove The Playing Song\n***\n");
  		//fclose(output);
  	
	char text[100];

    while(fgets(text, sizeof(text), filePtr) != NULL) {
    	 if(text[0] == 'I')
		 {
    	 	if(text[11]=='H'){
    	 		//printf("%c %c insertfirst\n",text[13],text[18]);
    	 		insert_at_first(&text[13]);
			 }else if(text[11]=='T')
			 {
			 	//printf("%c %c insertend\n",text[13],text[18]);
			 	insert_at_end(&text[13]);
			 }
		 }else if(text[0] == 'M')
		 {
		 	//printf("MoveSong \t%c\t%c   %c   %c   %c\n",text[9],text[11],text[16],text[18],text[23]);
		 	MoveSong(text[9],&text[11],&text[18]);
		 	//dnm(&text[11],&text[18]);
		 	
		 }else if(text[0] == 'R')
		 {
		 	if(text[2] == 'm')
		 	{
		 		//printf("RemoveSong\t%c\n",text[16]);
		 		RemoveSong(&text[11]);
			}
			else if(text[2] == 'v')
			{
				//printf("ReversePlaylist\n");
				reverse();
			}
		 }else if(text[0] == 'P')
		 {
		 	if(text[1] == 'l')
		 	{
		 		//printf("PlaySong\t%c\n",text[9]);
		 		playSong(text[9]);
			}
			else if(text[1] == 'r')
			{
				//printf("PrintPlaylist\t%c\n",text[14]);
				printPlayList(text[14]);
			}
		 	
		 }
	}
	fclose(filePtr);



	/*
	reverse();
	printPlayList('F');
	printPlayList('R');
	playSong('N');
	playSong('P');
	insert_at_first(1);
	insert_at_first(2);
	insert_at_first(3);
	insert_at_end(4);
	insert_at_end(5);
	insert_at_end(6);
	printPlayList('F');
	MoveSong('B',5,4);
	MoveSong('A',2,1);
	printPlayList('F');
	RemoveSong(6);
	printPlayList('F');
	playSong('P');
	playSong('P');
	playSong('P');
	playSong('N');
	printPlayList('F');
	printPlayList('R');
	reverse();
	printPlayList('F');
	printPlayList('R');
	playSong('N');
	playSong('N');
	playSong('N');
	playSong('P');
	RemoveSong(1);
	*/
}



void yaz()
{
    n *temp = head;
    while (temp->next != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}


void insert_at_first(char* nameIn)
{
	new_node = ( n*)malloc(sizeof( n));
	
	int i;
	for(i = 0; i < 20; i++) {
        if(*(nameIn+i) == '\n') {
            new_node->data[i] = '\0';
        } else {
            new_node->data[i] = *(nameIn+i);
        }
    }
    
	
    if (head == last && head == NULL)
    {    
        head = last = new_node;
        head->next = last->next = NULL;
        head->prev = last->prev = NULL;head->next=head;head->prev=head;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        head->prev = last;
        last->next = head;
    }
}

void insert_at_end(char* nameIn)
{
 	new_node = ( n*)malloc(sizeof( n));
	int i;
	for(i = 0; i < 20; i++) {
        if(*(nameIn+i) == '\n') {
            new_node->data[i] = '\0';

        } else {
            new_node->data[i] = *(nameIn+i);
        }
    }
    
 
    if (head == last && head == NULL)
    {
        head = last = new_node;
        head->next = last->next = NULL;    
        head->prev = last->prev = NULL;head->next=head;head->prev=head;
    }
    else
    {
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
        head->prev = last;
        last->next = head;
    }
}

void insert_at_end2(char* nameIn)
{
 
	new_node = ( n*)malloc(sizeof( n));
	int i;
	for(i = 0; i < 20; i++) {
        if(*(nameIn+i) == '\n') {
            new_node->data[i] = '\0';

        } else {
            new_node->data[i] = *(nameIn+i);
        }
    }
 
    if (head2 == last2 && head2 == NULL)
    {
        head2 = last2 = new_node;
        head2->next = last2->next = NULL;    
        head2->prev = last2->prev = NULL;head2->next=head2;head2->prev=head2;
    }
    else
    {
        last2->next = new_node;
        new_node->prev = last2;
        last2 = new_node;
        head2->prev = last2;
        last2->next = head2;
    }
}

int uzunluk(char name[]){
	int uz=0;
	int i;
	for(i=0;name[i]!='\0';i++){
		uz++;
	}
	return uz;
}
int uzunluk2(char name[]){
	int uz=0;
	int i;
	for(i=0;name[i]!='\0';i++){
		uz++;
	}
	return uz-1;
}

void MoveSong(char yeri,char* nameIn,char* nameIn2){
	
	new_node = ( n*)malloc(sizeof( n));
	int i;
	for(i = 0; i < 6; i++) {
        if(*(nameIn+i) == '\n') {
            new_node->data[i] = '\0';

        } else {
            new_node->data[i] = *(nameIn+i);
        }
    }
    
    new_node2 = ( n*)malloc(sizeof( n));
    
	for(i = 0; i < 6; i++) {
        if(*(nameIn2+i) == '\n') {
            new_node2->data[i] = '\0';
        } else {
            new_node2->data[i] = *(nameIn2+i);
        }
    }
    
	flg=head;
	i=1;
	while(flg->next!=head){
		i++;
		flg=flg->next;
	}
	
	
	flg=head;
	int j=0;
	for(j=0;j<i;j++){//a yý çýkardýk flg olarak yedekte
		
		if(flg->data[0] == new_node->data[0] && flg->data[1] == new_node->data[1] && flg->data[3] == new_node->data[3] && uzunluk(flg->data)==uzunluk(new_node->data) && flg->data[uzunluk2(flg->data)]==new_node->data[uzunluk2(new_node->data)]&& j!=0){
		flg->prev->next=flg->next;
		flg->next->prev=flg->prev;
		break;
		}else if(flg->data[0]==new_node->data[0] && flg->data[1]==new_node->data[1] && flg->data[2]==new_node->data[2] && uzunluk(flg->data)==uzunluk(new_node->data) &&  flg->data[uzunluk2(flg->data)]==new_node->data[uzunluk2(new_node->data)] ){
		flg->prev->next=flg->next;
		flg->next->prev=flg->prev;
		head=flg->next;
		break;
		} 
		flg=flg->next;
	}
	new_node=flg;
	flg=head;
	for(j=0;j<i;j++){
		if(flg->data[0]==new_node2->data[0] && flg->data[1]==new_node2->data[1] && flg->data[2]==new_node2->data[2] && flg->data[3]==new_node2->data[3] && uzunluk(flg->data)==uzunluk(new_node2->data) &&  flg->data[uzunluk2(flg->data)]==new_node2->data[uzunluk2(new_node2->data)] && j!=0){
				if(yeri=='B'){
					flg->prev->next=new_node;
					new_node->next=flg;
					new_node->prev=flg->prev;
					flg->prev=new_node;
				}else if(yeri=='A'){
					flg->next->prev=new_node;
					new_node->next=flg->next;
					new_node->prev=flg;
					flg->next=new_node;
				}
			break;
		}else if(flg->data[0]==new_node2->data[0] && flg->data[1]==new_node2->data[1] && flg->data[2]==new_node2->data[2] && flg->data[3]==new_node2->data[3] && flg->data[uzunluk2(flg->data)]==new_node2->data[uzunluk2(new_node2->data)] && uzunluk(flg->data)==uzunluk(new_node2->data) ){
			if(yeri=='B'){
					flg->prev->next=new_node;
					new_node->next=flg;
					new_node->prev=flg->prev;
					flg->prev=new_node;
					head=new_node;
				}else if(yeri=='A'){
					flg->next->prev=new_node;
					new_node->next=flg->next;
					new_node->prev=flg;
					flg->next=new_node;
				}
				break;
		}
		flg=flg->next;
	}
		
}


void reverse()
{
	if (head == NULL) 
	{
		return;
	} 
	
	last  = head->prev;
	n * new_head = NULL;
	n* temp = head->prev;
	while (temp->prev != last)
    {
        insert_at_end2(temp->data);
        temp = temp->prev;
    }
	insert_at_end2(temp->data);
	head=head2;
	last=last2;
	
	head2=NULL;last2=NULL;
	
	flg = head;
        	 while (flg->next != head)
		        {
		        	if(flg->data[0]==playing->data[0] && flg->data[1]==playing->data[1] && flg->data[2]==playing->data[2] && uzunluk(flg->data)==uzunluk(playing->data) &&  flg->data[uzunluk2(flg->data)]==playing->data[uzunluk2(playing->data)])
		           {
		           	playing = flg;
		            
		            break;
				   }
		            flg = flg->next;
		        }
	
	
	//printf("\n-----------------------%s---------------next %s-----------prv %s \n ",playing->data,playing->next->data,playing->prev->data);
	
} 


void RemoveSong(char* nameIn)
{
	
	char a[50];
	int i;
	for(i = 0; i < 20; i++) {
        if(*(nameIn+i) == '\n') {
            a[i] = '\0';

        } else {
            a[i] = *(nameIn+i);
        }
    }

	if(playing!=NULL&&playing->data[0]==a[0] && playing->data[1]==a[1] && playing->data[2]==a[2] && uzunluk(playing->data)==uzunluk(a) && playing->data[uzunluk2(playing->data)]== a[uzunluk2(a)]){
		printf("Cannot Remove The Playing Song\n***\n");
		fprintf(output,"Cannot Remove The Playing Song\n***\n");
		return;
		
	}

	if(head==NULL){//boþ ise
		return;
	}
	if(head==last){//head tek ise
		head=NULL;
		last=head;
		return;
	}
	
	if(head->next->next==head){//2 elemanlý ise
		if(head->data[0]==a[0] && head->data[1]==a[1] && head->data[2]==a[2] && uzunluk(head->data)==uzunluk(a) && head->data[uzunluk2(head->data)]== a[uzunluk2(a)]){
			head->next->next=head->next;head=head->next;
			head->next->prev=head->next;
			printf("d2");
			last=head->next;
		}else{
			head->next=head;
			head->prev=head;
			last=head;
		}
		return;
	}

	flg=head;
	while(flg->next != head){
	if(flg->data[0]==a[0] && flg->data[1]==a[1] && flg->data[2]==a[2] && uzunluk(flg->data)==uzunluk(a) && flg->data[uzunluk2(flg->data)]==a[uzunluk2(a)]  ){
		flg->prev->next=flg->next;
		flg->next->prev=flg->prev;
			printf("d3");
		if(flg==head){
			head=head->next;
		}
		break;
	}
	flg= flg -> next;
	}
	flg->prev->next=flg->next;
	flg->next->prev=flg->prev;
	
}



void playSong(char yonu)
{
    if(head == NULL)
    {
        printf("No Songs To Play\n***\n");
        fprintf(output,"No Songs To Play\n***\n");
        return;
    }
    if(playing == NULL)
    {
        if(yonu == 'N')
        {
            playing = head;
            printf("Playing\t%s\n***\n", playing->data);
            fprintf(output,"Playing\t%s\n***\n", playing->data);
            return;
        }
        else if(yonu== 'P')
        {
            playing = head->prev;
            printf("Playing\t%s\n***\n", playing->data);
            fprintf(output,"Playing\t%s\n***\n", playing->data);
            return;
        }
    }
   else
   {
        if(yonu == 'N')
        {
            playing = playing->next;
            printf("Playing\t%s\n***\n", playing->data);
            fprintf(output,"Playing\t%s\n***\n", playing->data);
        }
        else
        {
            playing = playing->prev;
            printf("Playing\t%s\n***\n", playing->data);
            fprintf(output,"Playing\t%s\n***\n", playing->data);
        }
    }
}

void printPlayList(char yonu)
{
    if(head == NULL)
    {
        printf("No Songs To Print\n***\n");
        fprintf(output,"No Songs To Print\n***\n");
		return;
    }
    if(yonu == 'F')
    { 
        n *temp = head;

        //printf("\nTraversal in forward direction \n");
        while (temp->next != head)
        {
            printf("%s\n", temp->data);
            fprintf(output,"%s\n", temp->data);
            temp = temp->next;
        }
        printf("%s\n***\n", temp->data);
        fprintf(output,"%s\n***\n", temp->data);
    }
    else if(yonu == 'R')
    {
        n *temp = head->prev;
        //printf("\nTraversal in reverse direction \n");
        while (temp->prev != head->prev)
        {
            printf("%s\n", temp->data);
            fprintf(output,"%s\n", temp->data);
            temp = temp->prev;
        }
        printf("%s\n***\n", temp->data);
        fprintf(output,"%s\n***\n", temp->data);
    }
}
