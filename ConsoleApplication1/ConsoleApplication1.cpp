#include <iostream>
#include <cmath>
#include <vector>
struct Character {
    std::string name;
    int damage;
    int health;
    int magic;
    std::vector<std::string> abilities;

    void display() const {
        for (const auto& ability : abilities) {
            std::cout << ability << ", ";
        }
        std::cout << std::endl;
    }
};
static void choseCharacter() {
    std::vector<Character> characters = {
    {"Warrior", 150, 20, 5, {"Slash", "Shield Block"}},
    {"Mage", 100, 5, 25, {"Fireball", "Teleport"}},
    {"Rogue", 120, 15, 10, {"Backstab", "Stealth"}}
    };

    int choice;

    for (size_t i = 0; characters.size(); ++i) {
        std::cout << i + 1 << ", " << characters[i].name << std::endl;
    }

    std::cout << "Choose your character!" << std::endl;

    std::cin >> choice;
    if (choice >= 1 && choice <= characters.size()) {
        std::cout << "Your choice is: ";
        characters[choice - 1].display();
    }
}
int main()
{
    std::cout << "Text based game" << std::endl;
}
