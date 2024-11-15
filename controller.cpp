#include "controller.h"

void Controller::setGoal(double newGoal){
    this->goal = newGoal;
    this->errorIntegral = 0;
}

double Controller::calculateOutput(double stateCurrent){
    this->state = stateCurrent;
    this->calculateError();

    double outputProportional = this->proportionalGain * this->error;
    double outputIntegral = this->integralGain * this->errorIntegral;
    double outputDerivative = this->derivativeGain * (this->error - this->lastError);

    this->lastError = this->error;

    return outputProportional + outputIntegral + outputDerivative;
}

void Controller::calculateError(){
    this->error = this->goal - this->state;
    this->errorIntegral += this->error;
}
