class Controller{
    public:
        double goal;
        double state;

        double error;
        double errorIntegral;
        double lastError = 0;

        double proportionalGain;
        double integralGain;
        double derivativeGain;

        Controller(double proportional, double integral, double derivative):
            proportionalGain(proportional), integralGain(integral), derivativeGain(derivative){}

        void setGoal(double newGoal);
        void calculateError();
        double calculateOutput(double stateCurrent);
};