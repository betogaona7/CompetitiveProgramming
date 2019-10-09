void deleteNode(Node *node){
    Node *p, *tmp;
    for(p = node; p->next->next; p=p->next){
        tmp = p->next;
        p->data = tmp->data;
    }
    tmp=p->next;
    p->data = tmp->data;
    p->next = NULL;
    delete tmp;
}