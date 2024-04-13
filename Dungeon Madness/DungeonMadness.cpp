#include <iostream>
#include <string>
#include <chrono>
#include <thread>

// Makes typewriter format operate
void typewriterEffect(const std::string& text, int delayMs) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush(); // Flush output to ensure immediate display
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}

int main() {
    std::string characterName;
    std::string userAnswer;
    bool lore = true;

    // Tells the player to input their name before they start the game
    std::string beforejourney = "Before you begin your dungeon journey, what is your name?: ";
    typewriterEffect(beforejourney, 60);
    std::cin >> characterName;    

    // Welcome message for the player
    std::string welcome = "Welcome to Dungeon Madness, " + characterName + " Good luck on your journey.\n";
    typewriterEffect(welcome, 60);

    // Ask the user if they want to learn about lore before their character is hurt
    std::string incident = "Interested in delving into the events prior to the Incident? (yes/no): ";
    typewriterEffect(incident, 60); 
    std::cin >> userAnswer;

    if (userAnswer == "yes" || userAnswer == "y") {
        lore = true;
    } if (userAnswer == "no" || userAnswer == "n") {
        lore = false;
    }

    // Display the backstory with typewriter effect if the player chooses to learn about lore
    if (lore) {
        std::string backstory = "You were attacked by the Goblin Crew while traveling through the Dark Forest. When you were attacked, you were badly injured, causing you to stumble and fall into a deep cave. Your left arm is badly injured, so you cannot move it, and your body is fatigued and dirty.\n"; 
        typewriterEffect(backstory, 60
); 
    } else {
        std::string backstoryskip = "You've chosen to skip learning about what happened prior to the Incident.\n";
        typewriterEffect(backstoryskip, 60
); 
    }

    // Continue with the rest of the game logic...

    return 0;
}
