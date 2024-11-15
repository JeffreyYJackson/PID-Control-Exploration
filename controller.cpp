#include "controller.h"

void Controller::setGoal(double newGoal){
    this->goal = newGoal;
    this->errorIntegral = 0;
}

double Controller::calculateOutput(double stateCurrent){
    this->state = stateCurrent;
    this->calculateError();

    double outputProportional = this->proportionalCoefficient * this->error;
    double outputIntegral = this->integralCoefficient * this->errorIntegral;
    double outputDerivative = 0;

    return outputProportional + outputIntegral + outputDerivative;
}

void Controller::calculateError(){
    this->error = this->goal - this->state;
    this->errorIntegral += this->error;
}
