#include "Node.h"

int Node::get_data(){
    return this->data;
}

void Node::set_data(int argData){

    this->data = argData;

    return;
}

Node* Node::get_next(){
    return this->next;
}

void Node::set_next(Node* argNext){

    this->next = argNext;

    return;

}