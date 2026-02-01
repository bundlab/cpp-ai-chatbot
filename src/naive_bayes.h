#ifndef NAIVE_BAYES_H
#define NAIVE_BAYES_H


#include <unordered_map>
#include <vector>
#include <string>


class NaiveBayes {
private:
std::unordered_map<std::string, std::unordered_map<std::string, int>> wordCount;
std::unordered_map<std::string, int> intentCount;
int totalSamples = 0;


public:
void train(const std::string& filename);
std::string predict(const std::string& text);
};


#endif