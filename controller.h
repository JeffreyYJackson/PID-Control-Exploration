class Controller{
    public:
        double goal;
        double state;

        double error;
        double errorIntegral;
        double lastError;
        double checkFirst;//Variable to check if the calculation of the error is done for the first time in order to initialize derivative control properly.

        double proportionalGain;
        double integralGain;
        double derivativeGain;

        Controller(double proportional, double integral, double derivative):
            proportionalGain(proportional), integralGain(integral), derivativeGain(derivative){}

        void setGoal(double newGoal);
        void calculateError();
        double calculateOutput(double stateCurrent);
};