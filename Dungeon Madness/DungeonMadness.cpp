#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

void typewriterEffect(const std::string& text, int delayMs) {
    for (auto c : text) {
        std::cout << c;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

int main() {
    std::string userAnswer;
    bool lore = false;
    bool wake = false;

    std::string incidentPrompt = "(LORE) - Before you begin, are you interested in delving into the events prior to the Incident? (yes/no): ";
    typewriterEffect(incidentPrompt, 60);


    auto isValidInput = [](const std::string& input) {
        return (input == "yes" || input == "y" || input == "no" || input == "n" ||
                input == "wake" || input == "slumber");
    };


    do {
        std::cin >> userAnswer;
    } while (!isValidInput(userAnswer));

    if (userAnswer == "yes" || userAnswer == "y") {
        lore = true;
    }

    if (lore) {
        std::string loreText = "You were attacked by the Goblin Crew while traveling through the Dark Forest. When you were attacked, you were badly injured, causing you to stumble and fall into a deep cave. Your left arm is badly injured, so you cannot move it, and your body is fatigued and dirty.\n";
        typewriterEffect(loreText, 60);
    } else {
        std::string skipLoreText = "You've chosen to skip learning about what happened prior to the Incident.\n";
        typewriterEffect(skipLoreText, 60);
    }


    std::string wakePrompt = "Would you like to wake up or continue your slumber? (wake/slumber): ";
    typewriterEffect(wakePrompt, 60);

    do {
        std::cin >> userAnswer;
    } while (!isValidInput(userAnswer));

    if (userAnswer == "wake") {
        wake = true;
    }

    if (wake) {
        std::string wakeText = "You slowly start picking yourself up, realizing the condition your body is in. As you look around the deep cave, you hear sounds of screeching.\n";
        typewriterEffect(wakeText, 60);


        std::string itemDescription = "After looking around the area, you spot several items thrown across the cave floor\n";
        typewriterEffect(itemDescription, 60);

        std::vector<std::string> items = { "unlit torch", "lighter", "dagger", "x2 bandages" };

        std::cout << "Items found in the cave:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item << std::endl;
        }


        std::string dialogue1 = "The cave speaks to you: Hello there, traveler. It seems you're another victim of the Goblin Crew.\n";
        typewriterEffect(dialogue1, 60);

        std::string dialogue2 = "Who's there!? Come out of the shadows!\n";
        typewriterEffect(dialogue2, 60);

        std::string eerieDescription = "\e[3mA human skull tumbles from a concealed pile of decomposed corpses lurking in the shadows. The gruesome sight is barely noticeable amidst the darkness.\e[0m\n";
        typewriterEffect(eerieDescription, 60);
    } else {
        std::string death1 = "You failed to wake up in time, resulting in the cave dwellers finding you and killing you.";
        typewriterEffect(death1, 60);
        std::cout << "\e[3mYou Died\e[0m\n" << std::endl;
        return 0;
    }

    return 0;
}
