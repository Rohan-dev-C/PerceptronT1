#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <list>
#include "MVPerceptron.h"
#include "rapidcsv.h"
using namespace std; 



int main() 
{
    vector<vector<float>> fullDataSet; 
    vector<float> tempVector1;
    vector<float> tempVector2;
    vector<float> tempVector3;
    vector<float> tempVector4;
    vector<vector<float>> sampleSet; 
    rapidcsv::Document doc("TESLA.csv");
    vector<float> OpenData = doc.GetColumn<float>("Open");
    vector<float> CloseData = doc.GetColumn<float>("Close");
    vector<float> LowData = doc.GetColumn<float>("Low");
    vector<float> HighData = doc.GetColumn<float>("High");
    fullDataSet.push_back(OpenData);
    fullDataSet.push_back(LowData);
    fullDataSet.push_back(HighData);
    fullDataSet.push_back(CloseData);

    for(int j = 0; j < 500; j++)
    {
        tempVector1.push_back(fullDataSet[0][j]);
        tempVector2.push_back(fullDataSet[1][j]);
        tempVector3.push_back(fullDataSet[2][j]);
        tempVector4.push_back(fullDataSet[3][j]);
    }
    sampleSet.push_back(tempVector1);
    sampleSet.push_back(tempVector2);
    sampleSet.push_back(tempVector3);
    
    
    Perceptron test = Perceptron(sampleSet, tempVector4, sampleSet.size(), 0.5);
    test.gradientDescent(100); 
    
    string input; 
    // cout<<"What number opening number you like to predict the closing number for?";
    // getline(std::cin, input);
    // float value = stof(input); 
    // cout<<test.predictValue( );
    return 0;   
}; 