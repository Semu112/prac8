#ifndef NODE_H
#define NODE_h

class Node {

    public:

        int get_data();
        void set_data(int argData);

        Node* get_next();
        void set_next(Node* argNodePtr);

        Node(){

        }

    private:

        int data;
        Node* next = nullptr;
};

#endif