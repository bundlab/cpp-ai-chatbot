#include <iostream>
#include "chatbot.h"

int main() {
    ChatBot bot;
    std::string userInput;

    std::cout << "🤖 ML Chatbot Ready (type exit to quit)" << std::endl;

    while (true) {
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        if (userInput == "exit") break;

        std::cout << "Bot: " << bot.reply(userInput) << std::endl;
    }
    return 0;
}
