#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <list>

using namespace std; 

float ScalarProduct(vector<float> vec1, float scalar)
{
    float total = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        total += vec1[i] * scalar;
    }
    return total;
}
float dotProduct(vector<float> vec1, vector<float> vec2)
{
    float total = 0;
    for (int i = 0; i < vec1.size(); i++)
    {
        total += vec1[i] * vec2[i];
    }
    return total;
}


class Perceptron
{
    public:
    float learningRate = 0.01; 
    vector<float> weights;
    vector<vector<float>>inputVector;
    vector<float> actualData; 
    int dimensions;
    float bias; 
    float n;
    Perceptron(vector<vector<float>> input, vector<float> actual, int dimension, float rate)
    {
        learningRate = rate; 
        inputVector = input; 
        actualData = actual; 
        dimensions = dimension; 
        weights.resize(dimensions, 0.05); 
        bias = 0; 
        n = inputVector[0].size(); 
    }

    // float calcCostFunction(float predictedY, float actualY, float inputDataIndex, float error)
    // {
    //     float subSum = inputDataIndex*error; //should be  error * inputVector[i] not actualY
    //     float gradient = error*subSum; 
    //     return gradient;
    // }

    float CalculatePredictedVal(vector<float>& weights, int index)
    {
        float total = 0; 
        for (int i = 0; i < weights.size(); i++)
        {
            total += weights[i]*inputVector[i][index]; 
        }
        return total + bias;    
    }

    float predictValue(vector<float> inputs)
    {
        float total = 0;
        for (int i = 0; i < inputs.size(); i++)
        {
            total += inputs[i]*weights[i];
        }
        return total + bias;    
    }

    void updateWeights(float error, vector<float>& weights, int index)
    {
        for (int i = 0; i < weights.size(); i++)
        {
            weights[i] -= learningRate*inputVector[i][index]*error/n;
        }
    }

    void printWeightsNB(int index)
    {
        for (size_t i = 0; i < weights.size(); i++)
        {
             cout<< index <<"\n weight " << i << " :" << weights[i]; 
        }
        cout<<"\n bias: " <<bias <<"\n";
        
    }

    float gradientDescent(int numEpochs)
    {
        for (int i = 0; i < numEpochs; i++)
        {
           
            for (int j = 0; j < actualData.size(); j++)
            {
                float value = CalculatePredictedVal(weights, j); 
                float error = value - actualData[i]; 
                updateWeights(error, weights, j); 
                bias = learningRate*error/n; 

                printWeightsNB(j); 
            }
            learningRate *= 1 - i/numEpochs; 
        
        }
        
    }

}; 