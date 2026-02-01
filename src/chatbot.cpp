#include "chatbot.h"
#include <fstream>

ChatBot::ChatBot() {
    model.train("data/intents.csv");

    std::ifstream file("data/responses.txt");
    std::string line;

    while (getline(file, line)) {
        auto pos = line.find('=');
        if (pos != std::string::npos) {
            responses[line.substr(0, pos)] = line.substr(pos + 1);
        }
    }
}

std::string ChatBot::reply(const std::string& input) {
    std::string intent = model.predict(input);

    if (responses.count(intent)) {
        return responses[intent];
    }
    return "I'm not sure I understand yet 🤔";
}
