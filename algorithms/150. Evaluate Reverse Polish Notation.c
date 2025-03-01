// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/


typedef struct node{
    int data;
    struct node* next;
} node 

typedef struct Stack{
    node* top;
} Stack

void pop(){
    
}

int evalRPN(char** tokens, int tokensSize) {
    int j = 0;
    for (int i = 0; i < tokensSize ; i++){
        if (strcmp(tokens[i], "*") == 0){
            pop(*);
            j--;
        } else if (strcmp(tokens[i], "/") == 0){
            list[j-2] /= list[j-1];
            j--;
        }  else if (strcmp(tokens[i], "+") == 0){
            list[j-2] += list[j-1];
            j--;
        } else if (strcmp(tokens[i], "-") == 0){
            list[j-2] -= list[j-1];
            j--;
        } else {
            list[j] = atoi(tokens[i]);
            j++;
        }
    }
    return list[0];
}