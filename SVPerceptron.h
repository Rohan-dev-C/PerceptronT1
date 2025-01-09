#include <vector>
#include <iostream>
#include <string>

using namespace std; 

// This is a perceptron that is 1-dimensional, this is effectively a Linear Regression Model

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
    float learningRate = 0.01; 
    float weight = 0.05;
    vector<float>inputVector; 
    vector<float> actualData; 
    float bias; 
    const float n = 100;

    perceptron(vector<float> input, vector<float> actual, int dimensions, float rate)
    {
        learningRate = rate; 
        inputVector = input; 
        actualData = actual; 
        bias = 0; 
    }


    float predictValue(float testValue)
    {
        float newVal = weight*testValue + bias; 
        return newVal;
    }    

    void gradientDescent(int numEpochs)
    {
        for(int j = 0; j < numEpochs; j++)
        {
            for (int i = 0; i < inputVector.size(); i++)
            {
                float value = inputVector[i]*weight + bias; 
                float error =  value - actualData[i];
                weight -= learningRate * inputVector[i] * error / n;
                bias -= learningRate * error / n;

                cout<<i <<"\n weight: " <<weight <<"\n bias: " <<bias <<"\n";
            }
            learningRate *= 1 - j/numEpochs; 
        }
    }
};
