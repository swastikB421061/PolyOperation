#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int pow;
    float coef;
    struct node*next;
}node;
node *head1=NULL;
node *head2=NULL;
node *head3;
void add();
void sub();
void multi();
void divid();
node* insert(node* head,float coef,int pow);
node* addition(node*head1,node*head2,node*head3);
node* multiply(node* poly1, node* poly2, node* poly3);
node* subtract(node*head1,node*head2,node*head3);
node* divide(node*head1,node*head2,node*ptr);
void remainde(node *p1,node *temp,node *head2);
node* create(node* head);
void init();
void reduce(node* start);
void add();
void mainfunc();
void print();
void reset();


node* insert(node* head,float coef,int pow){
    node* current,*temp;
    temp=(node*)malloc(sizeof(node));
    temp->coef=coef;
    temp->pow=pow;
    if (head == NULL || head->pow <= pow) {
        temp->next = head;
        head = temp;
    }
    else {
        current = head;
        while (current->next != NULL && current->next->pow > pow) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
    return head;
}


node* create(node* head){
    int a,p,n=0;
    float ele;
    node*temp1;
    temp1=head;
    printf("Enter no of terms ----->> ");
    scanf("%d",&a);
    while(n!=a){
        temp1=head;
      
        printf("ENTER COEFF %d : ",n+1);
        scanf("%f",&ele);
        printf("ENTER POWER %d : ",n+1);
        scanf("%d",&p);
        while(temp1){
            if(temp1->pow==p && temp1->pow < 0){
                printf("not possible re enter\n");
                head1=head2=NULL;
                init();
                }
            temp1=temp1->next;
        }    
        head=insert(head,ele,p);
        n++;
    }
    return head;
}

int main(){
    printf("\n\n\n\n\t\t\t\t============="
           "============================="
           "===========");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~");
    printf("\n\t\t\t\t==================="
           "============================="
           "=====");
    printf("\n\t\t\t\t[|:::>:::>:::>::>  "
           "POLY  OPERATION  <::<:::<:::"
           "<:::|]\t");
    printf("\n\t\t\t\t==================="
           "============================="
           "=====");
    printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~");
    printf("\n\t\t\t\t====================="
           "================================\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
           "Developer :     @SWASTIK PRADHAN\n\t\t\t\t\t\t\t\t\t\t\t    "
           "\n\n\t\t\t\t");
        init();
    return 0;
}

void init(){
    system("pause");
    system("cls");
    head1=head2=NULL;
    printf("Enter expression in the format ---->> a[x]^m + b[x]^n + ....\n\n\n\n");
    printf("Enter function 1: \n");
    head1=create(head1);
    printf("Entering function 2: \n");
    head2=create(head2);
    mainfunc();
}


void mainfunc(){
    system("pause");
    system("cls");
    printf("\n");
    printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t********************************************\n");
    printf("\t\t\t\t\t\t  MENU TABLE\n");
     printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t********************************************\n");
    printf("\t\t\t\t\tENTER 1 TO ADD.\n");
    printf("\t\t\t\t\tENTER 2 TO SUBTRACT.\n");
    printf("\t\t\t\t\tENTER 3 TO MULTIPLY.\n");
    printf("\t\t\t\t\tENTER 4 TO DIVIDE.\n");
    printf("\t\t\t\t\tENTER 5 TO RESET.\n");
    printf("\t\t\t\t\tENTER 6 TO EXIT.\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1){
        add();
    }
    else if(ch==2){
        sub();
    }
    else if(ch==3){
        multi();
    }
    else if(ch==4){
        divid();
    }
    else if(ch==6){
        system("cls");
        printf("\n \n \n \n \n \n");
        printf(" \t \t <<<<<<<<<<===================>>>>>>>>>>    THANK YOU     <<<<<<<<<<==================>>>>>>>>>>\n\n\n\n\n");
        exit(0);
    } 
    else if(ch==5){
        reset();
    } 
    else{
        printf("Enter a valid choice  ");
        mainfunc();
    }  

}
void reset(){
    head1=head2=head3=NULL;
    printf("Reset successful \n\n\n\n");
    init();
}

node* addition(node*head1,node*head2,node*head3){
    node *p1,*p2;
    p1=head1;
    p2=head2;
    head3=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->pow == p2->pow){
            float a=(p1->coef)+(p2->coef);
            head3=insert(head3,a,p1->pow);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->pow > p2->pow){
            head3=insert(head3,p1->coef,p1->pow);
            p1=p1->next;
        }
        else if(p2->pow > p1->pow){
            head3=insert(head3,p2->coef,p2->pow);
            p2=p2->next;
        }

    }
    while(p1!=NULL){
        head3=insert(head3,p1->coef,p1->pow);
        p1=p1->next;
    }
    while(p2!=NULL){
        head3=insert(head3,p2->coef,p2->pow);
        p2=p2->next;
    }
    return (head3);
}
void print(node* head){
    node*p=head;
    printf("\n");
    while(p!=NULL){
        if(p->coef!=0)
        printf("%0.2f[x]^%d + ",p->coef,p->pow);
        p=p->next;
    }
    printf("0\n");
}

void add(){
    system("pause");
    system("cls");
    if(head3==NULL){
        printf("Your first func---->");
        print(head1);
        printf("Your second func---->");
        print(head2);
        head3=addition(head1,head2,head3);
        printf("\n\nAfter Addition:  ");
        print(head3);
    }
    else{
        head2=head3;
        printf("Your first func---->");
        print(head2);
        head1=head3=NULL;
        head1=create(head1);
        printf("Your second func---->");
        print(head1);
        head3=addition(head1,head2,head3);
        printf("\n\nAfter Addition:  ");
        print(head3);
    }  
    mainfunc();
}

void multi(){
    system("pause");
    system("cls");
    if(head3==NULL){
        printf("Your first func---->");
        print(head1);
        printf("Your second func---->");
        print(head2);
        head3=multiply(head1,head2,head3);
        printf("\n\nAfter Multiplication:  ");
        print(head3);
    }
    else{
        head2=head3;
        printf("Your first func---->");
        print(head2);
        head1=head3=NULL;
        head1=create(head1);
        printf("Your second func---->");
        print(head1);
        head3=multiply(head1,head2,head3);
        printf("\n\nAfter Multiplication:  ");
        print(head3);
    }  
    mainfunc();
}
node* multiply(node* poly1, node* poly2, node* poly3)
{
    poly3=NULL;
    node *p1, *p2;
    p1 = poly1;
    p2 = poly2;
    while (p1 != NULL) {
        while (p2 != NULL) {
            float coeff;
            int power;
            coeff = p1->coef * p2->coef;
            power = p1->pow + p2->pow;

            poly3 = insert(poly3, coeff, power);
            p2 = p2->next;
        }
        p2 = poly2;
        p1 = p1->next;
    }

    reduce(poly3);
    return poly3;
}


void reduce(node* start){
    node *p1, *p2, *temp;
    p1 = start;
  
    while (p1 != NULL && p1->next != NULL) {
        p2 = p1;
  
        while (p2->next != NULL) {
            if (p1->pow == p2->next->pow) {
  
                p1->coef = p1->coef + p2->next->coef;
                temp = p2->next;
                p2->next = p2->next->next;
  
                free (temp);
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
}
void sub(){
    system("pause");
    system("cls");
    if(head3==NULL){
        printf("Your first func---->");
        print(head1);
        printf("Your second func---->");
        print(head2);
        head3=subtract(head1,head2,head3);
        printf("\n\nAfter Subtraction:  ");
        print(head3);
    }
    else{
        head1=head3;
        printf("Your first func---->");
        print(head1);
        head2=head3=NULL;
        head2=create(head2);
        printf("Your second func---->");
        print(head2);
        head3=subtract(head1,head2,head3);
        printf("\n\nAfter Subtraction:  ");
        print(head3);
    }  
    mainfunc();
}

node* subtract(node*head1,node*head2,node*head3){
    node *p1,*p2;
    p1=head1;
    p2=head2;
    //head3=NULL;
    while(p1!=NULL && p2!=NULL){
        if(p1->pow == p2->pow){
            float a=(p1->coef)-(p2->coef);
            head3=insert(head3,a,p1->pow);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->pow > p2->pow){
            head3=insert(head3,(p1->coef),p1->pow);
            p1=p1->next;
        }
        else if(p2->pow > p1->pow){
            head3=insert(head3,-(p2->coef),p2->pow);
            p2=p2->next;
        }

    }
    while(p1!=NULL){
        head3=insert(head3,(p1->coef),p1->pow);
        p1=p1->next;
    }
    while(p2!=NULL){
        head3=insert(head3,-p2->coef,p2->pow);
        p2=p2->next;
    }
    return (head3);
}
node *divide(node*head1,node*head2,node*ptr){
    node *p1=head1;
    node *temp=ptr;
    node *head3,*head5;
    while((head1->pow)>=(head2->pow)){
    head3=NULL;
    head5=NULL;
    if((head1->pow)>=(head2->pow)){

        ptr->coef=(head1->coef)/(head2->coef);
        ptr->pow=(head1->pow)-(head2->pow);
        ptr->next=NULL;
        head5=multiply(head2,ptr,head5);
        head1=subtract(head1,head5,head3);
        while(((head1->coef)==0)&&((head1->next)!=NULL))
        head1=head1->next;
        if((head1->pow)>=(head2->pow)){
        ptr=ptr->next=malloc(sizeof(node));
        ptr->next=NULL;
        }
        }
    }
    printf("The qoutient is: ");
    print(temp);
    remainde(p1,temp,head2);
    //return temp;
}
void remainde(node *p1,node *temp,node *head2){
    node *m,*n;
    n=m=NULL;
    m=multiply(head2,temp,m);
    n=subtract(p1,m,n);
    printf("\nThe remainder is: ");
    print(n);
    //return n;
}
void divid(){
    system("pause");
    system("cls");
    node *ptr=malloc(sizeof(node));
    head1=head2=NULL;
    printf("Enter function 1: \n");
    head1=create(head1);
    printf("Entering function 2: \n");
    head2=create(head2);
    print(head1);
    print(head2);
    if(head1->pow/head2->pow==0){
    printf("\n\n Division Not possible");
       divid();
    }
    else{
    printf("\n\n----After division-----\n\n");
    ptr=divide(head1,head2,ptr);
    print(ptr);
    mainfunc();
    }
}

