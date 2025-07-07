#include <iostream>
#include <cmath>
#include <vector>

typedef std::vector<std::string> stringVector;

#pragma region StatCheck
std::string currName;
int currDmg;
int currHealth;
int currMagic;
stringVector currAbilities;
#pragma endregion

struct Character {
    std::string name;
    int health;
    int damage;
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

    for (size_t i = 0;i < characters.size(); ++i) {
        std::cout << i + 1 << ", " << characters[i].name << std::endl;
    }

    std::cout << "Choose your character!" << std::endl;

    std::cin >> choice;

    if (choice >= 1 && choice <= characters.size()) {
        std::cout << "Your choice is: " << characters[choice - 1].name << std::endl;
        std::cout << "Abilities: ";
        characters[choice - 1].display();
        currDmg = characters[choice - 1].damage;
        currHealth = characters[choice - 1].health;
        currName = characters[choice - 1].name;
        currMagic = characters[choice - 1].magic;
        currAbilities = characters[choice - 1].abilities;
    }
}
int main()
{
    std::cout << "Text based game" << std::endl;

    choseCharacter();

    #pragma region Unit Test for stat selection

    std::cout << currName << "\n";
    std::cout << currHealth << "\n";
    std::cout << currDmg << "\n";
    std::cout << currMagic << "\n";

    for (size_t i = 0; i < currAbilities.size(); ++i) {
        std::cout << currAbilities[i];
    }
    std::cout << std::endl;
    #pragma endregion

}
