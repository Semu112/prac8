#include "LinkedList.h"

#include <string>
#include <iostream>

int main(void){

    std::string input;
    std::getline(std::cin, input);

    //Splits input into array, function and parameters

    //Array

    int arr[100];
    std::string strArray;
    int arrayEnds = 0;

    while(std::isdigit(input[arrayEnds]) || input[arrayEnds] == ' '){
        arrayEnds++;
    }

    strArray = input.substr(0, arrayEnds);
    int arrLength = 0;
    int arrItr = 0;

    for(int i = 0; i<strArray.size(); i++){

        if(std::isdigit(strArray[i]) || strArray[i] == '-'){

            arrLength++;
            int numLength = 0;

            int end = strArray.size()-1;
            for(int j = i; j<strArray.size(); j++){

                if(strArray[j] == ' '){
                    end = j-1;
                    break;
                }
                else if(std::isdigit(strArray[j]) || strArray[j] == '-'){
                    numLength++;
                }
            }

            std::string n = strArray.substr(i, end-i+1);
            arr[arrItr] = stoi(n);
            arrItr++; 

            i = i + numLength;
        }

    }


    //function
    int alphaEnds = arrayEnds;

    while(std::isalpha(input[alphaEnds])){
        alphaEnds++;
    }

    alphaEnds = alphaEnds-arrayEnds;

    std::string function = input.substr(arrayEnds, alphaEnds);


    //parameters
    int param1;
    int param2;

    int param1or2 = 1;

    for(int i = alphaEnds + arrayEnds; i<input.size(); i++){

        int numLength = 0;
        if(isdigit(input[i]) || input[i] == '-'){

            for(int j = i; j<input.size(); j++){
                if(isdigit(input[j]) || input[j] == '-'){
                    numLength++;
                }
                else{
                    break;
                }
            }

            if(param1or2 == 1){
                param1 = stoi(input.substr(i, numLength));
                param1or2++;
            }
            else if(param1or2 == 2){
                param2 = stoi(input.substr(i, numLength));
                break;
            }

            i = i+numLength;
        }
    }

    LinkedList ll(arr, arrLength);

    if(function == "AF"){
        ll.addFront(param1);
    }
    else if(function == "AE"){
        ll.addEnd(param1);
    }
    else if(function == "AP"){
        ll.addAtPosition(param1, param2);
    }
    else if(function == "S"){
        ll.search(param1);
    }
    else if(function == "DF"){
        ll.deleteFront();
    }
    else if(function == "DE"){
        ll.deleteEnd();
    }
    else if(function == "DP"){
        ll.deletePosition(param1);
    }
    else if(function == "GI"){
        ll.getItem(param1);
    }

    ll.printItems();

    return 0;
}