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

#pragma region EnemeyStats
std::string name;
int healt;
int dmg;
int magic;
#pragma endregion


struct Boss {
    std::string name;
    int health;
    int dmg;
    int magic;
    stringVector abilities;
};
struct Enemy {
    std::string name;
    int healt;
    int dmg;
    int magic;
};

struct Character {
    std::string name;
    int health;
    int damage;
    int magic;
    stringVector abilities;

    void display() const {
        for (const auto& ability : abilities) {
            std::cout << ability << ", ";
        }
        std::cout << std::endl;
    }
};
static void choseEnemy() {
    std::vector<Enemy>enemies = {
        {"Gbolin", 50, 5, 0},
        {"Raider", 80, 8, 1},
        {"Dog", 40, 10, 0},
        {"Skeleton", 100, 5, 0}
    };
    int currentEnemy = rand() % enemies.size();
    std::cout << "Enemey: " << std::endl;
    std::cout << enemies[currentEnemy].name << ", " << enemies[currentEnemy].healt << ", " << enemies[currentEnemy].dmg << ", " << enemies[currentEnemy].magic;
    std::cout << std::endl;

    name = enemies[currentEnemy].name;
    healt = enemies[currentEnemy].healt;
    dmg = enemies[currentEnemy].dmg;
    magic = enemies[currentEnemy].magic;
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
void fight() {
    using namespace std;
    int fightChoice;
    int abilityChoice;
    bool blockState = false;

    std::string wantingToUse;

    do
    {
        cout << "Your turn!" << "\n";
        cout << "Choose your action!" << "\n";
        cout << "1, Attack" << "\t" << "2, Block" << "\t" << "3, Use Ability" << "\t" << "4, Flee" << endl;
        cin >> fightChoice;
        switch (fightChoice)
        {
            case 1:
                healt -= currDmg;
                break;
            case 2:
                blockState = true;
                break;
            case 3:
                cout << "Your abilites are: ";
                for (const auto& abilty : currAbilities) {
                    cout << abilty << ", ";
                }
                cout << endl;
                cout << "Choose which spell you want to use: ";
                cin >> abilityChoice;
                wantingToUse = currAbilities[abilityChoice - 1];
                useAbility(wantingToUse);
                break;
            case 4:
                int flee = rand() % 2;
                if (flee == 1) {
                    cout << fleeFromCombat();
                    break;
                }
                cout << "You couldnt flee";
            default:
                cout << "You did nothing! IDIOT" << endl;
                break;
        }
    } while (healt > 0);
}
void useAbility(std::string s) {

}
std::string fleeFromCombat() {
    return "You flee the combat!";
}
int main()
{
    std::cout << "Text based game" << std::endl;

    choseCharacter();

    choseEnemy();

    #pragma region Unit Test for stat selection
    /*
    std::cout << currName << "\n";
    std::cout << currHealth << "\n";
    std::cout << currDmg << "\n";
    std::cout << currMagic << "\n";

    for (size_t i = 0; i < currAbilities.size(); ++i) {
        std::cout << currAbilities[i];
    }
    std::cout << std::endl;
    */
    #pragma endregion

}
