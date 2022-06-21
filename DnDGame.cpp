// DnDGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <stdexcept>

class Character {
private:
    std::string CharacterName;
    std::string CharacterRace;
    std::string CharacterClass;
    int CharacterLevel;
    int CharacterMaxHealth;
    int CharacterMaxMana;
    int CharacterCurrentHealth;
    int CharacterCurrentMana;
    int AttackStats;
    int DefenceStats;

public:
    Character(std::string charactername, std::string characterrace, std::string characterclass, int characterlevel)
    {
        CharacterName = charactername;
        CharacterRace = characterrace;
        CharacterClass = characterclass;
        CharacterLevel = characterlevel;
        CharacterMaxHealth = 0;
        CharacterMaxMana = 0;
        CharacterCurrentHealth = 0;
        CharacterCurrentMana = 0;
        AttackStats = 0;
        DefenceStats = 0;
    }
    void SmallHealthPotion()
    {
        if (CharacterCurrentHealth + 50 >= CharacterMaxHealth)
        {
            CharacterCurrentHealth = CharacterMaxHealth;
        }
        else
            CharacterCurrentHealth = CharacterCurrentHealth + 50;
    }
    void MeduimHealthPotion()
    {
        if (CharacterCurrentHealth + 100 >= CharacterMaxHealth)
        {
            CharacterCurrentHealth = CharacterMaxHealth;
        }
        else
            CharacterCurrentHealth = CharacterCurrentHealth + 100;
    }
    void LargeHealthPotion()
    {
        if (CharacterCurrentHealth + 200 >= CharacterMaxHealth)
        {
            CharacterCurrentHealth = CharacterMaxHealth;
        }
        else
            CharacterCurrentHealth = CharacterCurrentHealth + 200;
    }
    void SmallManaPotion()
    {
        if (CharacterCurrentMana + 50 >= CharacterMaxMana)
        {
            CharacterCurrentMana = CharacterMaxMana;
        }
        else
            CharacterCurrentMana = CharacterCurrentMana + 50;
    }
    void MeduimManaPotion()
    {
        if (CharacterCurrentMana + 100 >= CharacterMaxMana)
        {
            CharacterCurrentMana = CharacterMaxMana;
        }
        else
            CharacterCurrentMana = CharacterCurrentMana + 100;
    }
    void LargeManaPotion()
    {
        if (CharacterCurrentMana + 200 >= CharacterMaxMana)
        {
            CharacterCurrentMana = CharacterMaxMana;
        }
        else
            CharacterCurrentMana = CharacterCurrentMana + 200;
    }

    void GetCharacterStatus()
    {
        std::cout << "Character Name: " << CharacterName << std::endl;
        std::cout << "Character Race: " << CharacterRace << std::endl;
        std::cout << "Character Class: " << CharacterClass << std::endl;
        std::cout << "Character Health: " << CharacterMaxHealth << "/" << CharacterCurrentHealth << std::endl;
        std::cout << "Character Mana: " << CharacterMaxMana << "/" << CharacterCurrentMana << std::endl;
        std::cout << "Character Level: " << CharacterLevel << std::endl;
        std::cout << "Character Attack Stats: " << AttackStats << std::endl;
        std::cout << "Character Defence Stats: " << DefenceStats << std::endl;
    }
};

class Monster {
    std::string MonsterName;
    int MonsterHealth;
    int MonsterAttackStat;
    int MonsterLevel;
    int ExpGiven;
};

/*class Mage : public Character {
public:
    Mage(std::string charactername, std::string characterrace, std::string characterclass, int characterlevel) : Character (charactername, characterrace, characterclass, characterlevel)
    {
        
    }
};*/

bool tryParse(std::string& input, int& output) {
    try {
        output = std::stoi(input);
    }
    catch (std::invalid_argument) {
        return false;
    }
    return true;
}


int main()
{
    std::cout << "Welcome to the world of D&D!\n";
    std::cout<<R"(                                                                           
 (  (            (  (          (                             )             
 )\))(   '   (   )\ )\ )       )\ )      )                ( /(  (  (       
((_)()\ ) (  )( ((_|()/(    ( (()/(     (     (   (    (  )\())))\ )(  (   
_(())\_)())\(()\ _  ((_))   )\ /(_))    )\  ' )\  )\ ) )\(_))//((_|()\ )\  
\ \((_)/ ((_)((_) | _| |   ((_|_) _|  _((_)) ((_)_(_/(((_) |_(_))  ((_|(_) 
 \ \/\/ / _ \ '_| / _` |  / _ \|  _| | '  \() _ \ ' \)|_-<  _/ -_)| '_(_-< 
  \_/\_/\___/_| |_\__,_|  \___/|_|   |_|_|_|\___/_||_|/__/\__\___||_| /__/ 
                                                                           )" << std::endl;
    std::string name, race, charclass, input;
    int race_num=0;
    int class_num = 0;
    std::cout << "Please enter your character name: "<<std::endl;
    getline(std::cin, name);
    
    while (race_num != 1 && race_num != 2 && race_num != 3)
    {
        std::cout << "Please choose your character race: " << std::endl;
        std::cout << "(1) Human     (2) Elf     (3) Dwarf       (Press numbers to choose between the races)" << std::endl;
        

        getline(std::cin, input);

        while (!tryParse(input, race_num))
        {
            std::cout << "Bad entry. Enter a NUMBER: ";
            getline(std::cin, input);
        }

        switch (race_num)
        {
        case 1:
            race = "Human";
            break;
        case 2:
            race = "Elf";
            break;
        case 3:
            race = "Dwarf";
            break;
        default:
            std::cout << "- Invalid race -" << std::endl;
            break;
        }
    }

    while (class_num != 1 && class_num != 2 && class_num != 3)
    {
        std::cout << "Please choose your character class: " << std::endl;
        std::cout << "(1) Warriror     (2) Hunter     (3) Mage       (Press numbers to choose between the races)" << std::endl;
        getline(std::cin, input);

        while (!tryParse(input, class_num))
        {
            std::cout << "Bad entry. Enter a NUMBER: ";
            getline(std::cin, input);
        }
       
        switch (class_num)
        {
        case 1:
            charclass = "Warrior";
            break;
        case 2:
            charclass = "Hunter";
            break;
        case 3:
            charclass = "Mage";
            break;
        default:
            std::cout << "- Invalid class -" << std::endl;
            break;
        }
        
    }

    Character Player1(name, race, charclass, 1);
    std::cout << "Your character status: "<<std::endl;
    Player1.GetCharacterStatus();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
