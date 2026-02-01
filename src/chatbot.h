#ifndef CHATBOT_H
#define CHATBOT_H

#include "naive_bayes.h"
#include <string>
#include <unordered_map>

class ChatBot {
    private:
        NaiveBayes model;
        std::unordered_map<std::string, std::string> responses;
        std::string preprocess(const std::string& input);
    
    public:
        ChatBot();
        std::string getResponse(const std::string& input);
        std::string reply(const std::string& input);
};

#endif