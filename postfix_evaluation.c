#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 50
int stack[MAX],top=-1;
char exp1[100];
void push(int item){
	if(top==MAX-1)
		printf("Stack overflow");
	else
		stack[++top]=item;
}
int pop(){
	int data;
	if(top==-1)
		printf("Stack underflow");
	else{
		data=stack[top];
		top--;
	}
	return data;
}
float eval(){
	int i=0;
	float op1,op2,value;
	while(exp1[i]!='\0'){
		if(isdigit(exp1[i]))
			push((float)(exp1[i]-'0'));
		else{
			op2=pop();
			op1=pop();
			switch(exp1[i]){
				case '+':value=op1+op2;
						 break;
				case '-':value=op1-op2;
						 break;
				case '/':value=op1/op2;
						 break;
				case '*':value=op1*op2;
						 break;
				case '%':value=(int)op1%(int)op2;
						 break;			
			}
			push(value);
		}
		i++;
	}
	return(pop());
}
int main(){
	float val;
	printf("Enter any postfix expression: ");
	gets(exp1);
	val=eval();
	printf("\nThe value of the postfix notation: %0.2f",val);
	return 0;
}
