class Controller{
    public:
        double goal;
        double state;

        double error;
        double errorIntegral;

        double proportionalCoefficient;
        double integralCoefficient;
        double derivativeCoefficient;

        Controller(double proportional, double integral, double derivative):
            proportionalCoefficient(proportional), integralCoefficient(integral), derivativeCoefficient(derivative){}

        void setGoal(double newGoal);
        void calculateError();
        double calculateOutput(double stateCurrent);
};