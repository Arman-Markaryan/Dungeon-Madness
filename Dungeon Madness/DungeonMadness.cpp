#include <iostream>
#include <string>

int main() {
    std::string characterName;
    std::string userAnswer;
    bool lore = true;


    // Tells the player to input their name before they start the game
    std::cout << "Before you begin your dungeon journey, what is your name? ";
    std::cin >> characterName;

    // Welcome message for the player
    std::cout << "Welcome to Dungeon Madness, " << characterName << " Good luck on your journey.\n";

    // Aks the user if they want to learn about lore before their character being hurt
    std::cout << "Interested in delving into the events prior to the Incident? (y/n) ";
    std::cin >> userAnswer;

    if (userAnswer == "yes" || userAnswer == "y") {
        lore = true;
    } else {
        lore = false;
    }

    if (lore) {
        std::cout << "You were attacked by the Goblin Crew while traveling through the Dark Forest. "
                     "When you were attacked, you were badly injured, causing you to stumble and fall into a deep cave. "
                     "Your left arm is badly injured, so you cannot move it, and your body is fatigued and dirty.\n";
    } else {
        std::cout << "You've chosen to skip learning about what happened prior to the Incident.\n";
    }

    // Who Knows What Happens Here?!

    return 0;
}
