#include<iostream>
#include"Continents.h"
#include"Carnivore.h"
#include"Herbivore.h"



int main()
{

    std::vector<Continent *> continents;
    continents.push_back(new Africa);

    std::cout << "\n================================\n";
    std::cout << "\nAnimals feeding\n";
    std::cout << "\n================================\n";

    for(int i{0}; i < continents.size(); ++i) {
        continents[i]->feedHerbivores();
    }

    int count{7};
    while(count) {
        for(int i{0}; i < continents.size(); ++i) {
            continents[i]->feedCarnivores();
        }
        --count;
    }

    std::cout << "\n================================\n";
    for(int i{0}; i < continents.size(); ++i)
        delete continents[i];

    return 0;
}