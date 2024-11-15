#include <iostream>
#include <fstream>
#include <string>
#include "controller.h"

int main(void) {
    
    FILE *outputFile;
    outputFile = fopen("data.txt", "w");
    if(outputFile == NULL){std::cout << "Error opening file"; return 0;}

    Controller controller = Controller(0.2, 0.2, 0.2);

    double goalState = 50;
    double currentState = 20;

    double hoverVelocity = 2;
    
    controller.setGoal(goalState);

    fprintf(outputFile, "%d,%lf\n", 1,  currentState);
    std::cout<<currentState<<"\n";  
    for (int i = 2; i < 100; i++){
        
        currentState += controller.calculateOutput(currentState) - hoverVelocity; 

        fprintf(outputFile, "%d,%lf\n", i, currentState);
        std::cout<<currentState<<"\n";
    }


    return 0;
}