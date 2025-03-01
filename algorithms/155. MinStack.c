// 155. Min Stack
// https://leetcode.com/problems/min-stack


typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* stack;  // Main stack
    Node* minStack; // Min stack (to keep track of minimums)
} MinStack;

// Function to create a new node, since i decided to use a linked list implementation
Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL; 
    node->value = value;
    node->next = NULL;
    return node;
}


MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    if (!obj) return NULL; 
    obj->stack = NULL;
    obj->minStack = NULL;
    return obj;
}


void minStackPush(MinStack* obj, int val) {
    // Create a new node for the main stack
    Node* node = newNode(val);
    if (!node) return; 
    node->next = obj->stack;
    obj->stack = node;

    // If the minStack is empty or the new value is smaller than or equal to the current minimum, push to minStack
    if (obj->minStack == NULL || val <= obj->minStack->value) {
         // Create a new node for the min stack
        Node* minNode = newNode(val);
         if (!minNode) return; 
        minNode->next = obj->minStack;
        obj->minStack = minNode;
    }
}


void minStackPop(MinStack* obj) {
    if (obj->stack == NULL) {
        return; //if stack is empty we cant pop anything
    }

    // Pop the main stack and store the popped val
    Node* temp = obj->stack;
    obj->stack = obj->stack->next;
    int poppedValue = temp->value; 
    free(temp);

    //if minStack isnt empty and the poppedvalue has been previously pushed to minStack, it needs to be removed as well
    if (obj->minStack != NULL && poppedValue == obj->minStack->value) {
        temp = obj->minStack;
        obj->minStack = obj->minStack->next;
        free(temp);
    }
}

int minStackTop(MinStack* obj) {
    if (obj->stack == NULL) {
        return INT_MIN; 
    }
    return obj->stack->value;
}

int minStackGetMin(MinStack* obj) {
    if (obj->minStack == NULL) {
        return INT_MIN; 
    }
    return obj->minStack->value;
}


void minStackFree(MinStack* obj) {
    while (obj->stack != NULL) { 
        Node* temp = obj->stack;
        obj->stack = obj->stack->next;
        free(temp);
    }
    while (obj->minStack != NULL) {
        Node* temp = obj->minStack;
        obj->minStack = obj->minStack->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */