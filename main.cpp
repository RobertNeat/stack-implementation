//  Check if stack is empty
//  Add element to the stack (randomly generated)
//  Delete element from stack
//  Get element from the stack
//  Delete all elements from the stack

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <stdlib.h> /* system("cls") */
#include <iostream>

using namespace std;

struct element{ //stack structure
    int number;
    element* next;  };

void push_stack(element* &stack, int value){    //add element to the stack
    element* el=new element;
    el->number=value;
    el->next=stack;
    stack= el;  }

void pop_stack(element* &stack){    //delete element from the stack
    element* temp=stack;
    stack=stack->next;
    delete temp;    }

bool isEmpty_Stack(element* stack){ //sprawdza czy stos jest pusty
    if(stack==nullptr){
        cout<<"Empty stack"<<endl;
        return true;
    }
    else{
        cout<<"Something is on the stack"<<endl;
        return false;
    }}

int top_stack(element* stack){  //address from the stack tip
    return stack->number;   }

bool isEmpty(element* &stack){ //forward pointer as reference
        isEmpty_Stack(stack);
    }

    void addOne(element* &stack){
        push_stack(stack,rand()%10+1);
    }

    void dropOne(element* &stack){
        if(!isEmpty_Stack(stack)){  pop_stack(stack);   }
    }

    void showLast(element* &stack){
        if(!isEmpty_Stack(stack)){  cout<<"Last element:"<<top_stack(stack)<<endl; }
    }

    void dropAll(element* &stack){
        while(!(isEmpty_Stack(stack))){    pop_stack(stack);}
    }

void stackMenu(int &b){
    cout<<"-------------------------------------------------"<<endl;
    cout<<"\tActions on the stack (choose action number):"<<endl;
    cout<<"\t1 - check if stack is empty"<<endl;
    cout<<"\t2 - add element to the stack (random number generation 1-10)"<<endl;
    cout<<"\t3 - drop element from the stack"<<endl;
    cout<<"\t4 - display element from the stack"<<endl;
    cout<<"\t5 - drop all elements from the stack"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Choosing: ";
    cin>>b;
    system("cls");
}



int main()
{
    element* stack=nullptr;
    srand (time(NULL));

            int b;
            stackMenu(b);
        while(b<=5 && b>=1){
               switch(b){
                case 1: //check if stack is empty
                    {
                    isEmpty(stack);
                    stackMenu(b);
                    break;
                    }
                case 2: //add one element to the stack 1-10
                    {
                    addOne(stack);
                    stackMenu(b);
                    break;
                    }
                case 3: //drop element from the stack if not empty
                    {
                    dropOne(stack);
                    stackMenu(b);
                    break;
                    }
                case 4: //display last element from the stack
                    {
                    showLast(stack);
                    stackMenu(b);
                    break;
                    }
                case 5: //drop all elements from the stack
                    {
                    dropAll(stack);
                    stackMenu(b);
                    break;
                    }
               }}
    return 0;
}
