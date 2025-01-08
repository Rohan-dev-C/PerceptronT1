#include <vector>
#include <iostream>
#include <string>
#include "perceptron.h"
#include "rapidcsv.h"
using namespace std; 

vector<float> testVector1;
vector<float> testVector2;


int main() 
{
    rapidcsv::Document doc("TESLA.csv");
    vector<float> OpenData = doc.GetColumn<float>("Open");
    vector<float> CloseData = doc.GetColumn<float>("Close");
    for (int i = 0; i < 500; i++)
    {
        testVector1.push_back(OpenData[i]); 
        testVector2.push_back(CloseData[i]); 
    }
    
    perceptron test = perceptron(testVector1, testVector2, 1);

    for (int i = 0; i < 50; i++)
    {
        test.gradientDescent(); 
    }
    string input; 
    cout<<"What number opening number you like to predict the closing number for?";
    getline(std::cin, input);
    float value = stof(input); 
    cout<<test.predictValue(value);
    return 0;   
}; 