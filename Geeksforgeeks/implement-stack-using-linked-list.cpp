void MyStack ::push(int x) {
    if(!top) top = new StackNode(x);
    else{
        StackNode *tmp = new StackNode(x);
        tmp->next = top;
        top = tmp;
    }
}

int MyStack ::pop() {
    StackNode *tmp = top;
    if(!tmp) return -1;
    else{
        tmp = tmp->next;
        int r = top->data;
        delete(top);
        top = tmp;
        return r;
    }
}