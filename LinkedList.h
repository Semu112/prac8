#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

#include <iostream>

class LinkedList{

    public:

        //Getters and setters
        Node* get_head();
        void set_head(Node* newHead);

        Node* getNode(int position);
        Node* getBeforeEnd();
        Node* getEnd();

        bool isEmpty();

        void addFront(int newItem);
        void addEnd(int newItem);
        void addAtPosition(int position, int newItem);

        void deleteFront();
        void deleteEnd();
        void deletePosition(int position);
        
        int getItem(int position);
        int search(int item);

        void printItems();

        LinkedList(){

        }
        LinkedList(int* array, int size){

            if(size>0){

                Node* firstNode = new Node;
                firstNode->set_data(array[0]);

                this->head = firstNode;

                for(int i = 1; i<size; i++){
                    this->addEnd(array[i]);
                }
            }
            
        }
        ~LinkedList(){

            Node* itr = this->get_head();

            while(itr != nullptr){

                itr = itr->get_next();

                this->deleteFront();
            }

        }

    private:

        Node* head = nullptr;
};

#endif