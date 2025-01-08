#include <vector>
#include <iostream>
#include <string>

using namespace std; 


float dotProduct(vector<float> vec1, vector<float> vec2)
{
    float total = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        total += vec1[i] * vec2[i];
    }
    return total;
}
float ScalarProduct(vector<float> vec1, float scalar)
{
    float total = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        total += vec1[i] * scalar;
    }
    return total;
}

class perceptron
{
    public:
    const float learningRate = 0.01; 
    float weight = 1; //initialise to a smaller random value instead of 1
    //vector<float> weights;
    vector<float> inputVector;
    vector<float> actualData; 
    float bias; 
    const float n = 500;

    perceptron(vector<float> input, vector<float> actual, int dimensions)
    {
        inputVector = input; 
        actualData = actual; 
        //weights.resize(inputVector.size(), 1); // Initialize weights with the same size as inputVector and set all the values randomly
        bias = 0; 
    }


    float predictValue(float testValue)
    {
        float newVal = weight*testValue + bias; 
        return newVal;
    }


    float calcCostFunction(float predictedY, float actualY, float inputDataIndex)
    {
        float error = predictedY - actualY; 
        float subSum = inputDataIndex*error; //the subSum is calculated wrong - it should be  error * inputVector[i] not actualY
    
        float gradient = error*subSum; 
        return gradient;
    }

    

    void gradientDescent()
    {
        for (int i = 0; i < inputVector.size(); i++)
        {
            float value = inputVector[i]*weight + bias; 
            float untreatedVal = calcCostFunction(value, actualData[i], inputVector[i]);
            float val = learningRate*untreatedVal; 
            weight -= val/n; 
            float error = value - actualData[i];
            bias -=  2*error*learningRate/n;  //bias term should also have learning rate
            
            cout<<i; 
            cout<<"\n weight: ";
            cout<<weight; 
            cout<<"\n bias: ";
            cout<<bias; 
            cout<<"\n";
        }
    }
};