#include "naive_bayes.h"
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

static std::string normalize(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void NaiveBayes::train(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    getline(file, line); // header

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string intent, text;
        getline(ss, intent, ',');
        getline(ss, text);

        text = normalize(text);

        intentCount[intent]++;
        totalSamples++;

        std::stringstream words(text);
        std::string word;
        while (words >> word) {
            wordCount[intent][word]++;
        }
    }
}

std::string NaiveBayes::predict(const std::string& text) {
    std::string input = normalize(text);

    double bestScore = -1e18;
    std::string bestIntent = "UNKNOWN";

    for (auto& intent : intentCount) {
        double score = log((double)intent.second / totalSamples);

        std::stringstream words(input);
        std::string word;
        while (words >> word) {
            score += log(wordCount[intent.first][word] + 1);
        }

        if (score > bestScore) {
            bestScore = score;
            bestIntent = intent.first;
        }
    }

    if (bestIntent.empty()) {
        return "UNKNOWN";
    }

    return bestIntent;
}