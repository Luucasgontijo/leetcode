// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

typedef struct node {
    char data;
    struct node* next;
}  node;

typedef struct Stack {
    node* top;
} Stack;


void push(Stack* stack, char s){  
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = s;
    newNode->next = stack->top;
    stack->top = newNode;
    
}

char pop(Stack* stack){  
    node* temp = stack->top;
    char popped = temp->data;
    stack->top = temp->next;
    free(temp);
    return popped;
}

bool matchTest(char open,char close){
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

bool isValid(char* s) {
    Stack*  stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;


    while (*s){
        if (*s == '(' || *s == '[' || *s == '{'){
            push(stack, *s);
        } else {
            if (stack->top == NULL) {  // if it falls here and the stack->top is null, it means that there is a closing parenthesis and there is none opening one to match with it
                free(stack);
                return false;
            }
            char popped = pop(stack);
            if (!matchTest(popped, *s)){
                free(stack);
                return false;
            }
        }
        s++;
    } 

    bool result = (stack->top == NULL);  
    free(stack);
    return result;
}