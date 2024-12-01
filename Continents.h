#pragma once
#include<vector>
#include"Herbivore.h"
#include"Carnivore.h"

class Continent
{
    std::vector<Herbivore *> m_herbis;
    std::vector<Carnivore *> m_carnis;

    public:
    
    Continent()
    {
        std::cout << "Continent created\n";
    }

    virtual ~Continent()
    {
        
        if(m_herbis.size() > 0) {
            for(auto element : m_herbis) {
                delete element;
            }
        }

        if(m_carnis.size() > 0) {
            for(auto element : m_carnis) {
                delete element;
            }
        }

        std::cout << "Continent deleted!\n";
    }

    void addHerbi(Herbivore *herbi)
    {
        m_herbis.push_back(herbi);
    }

    void deleteHerbi()
    {
        delete m_herbis[m_herbis.size() - 1];
        m_herbis.pop_back();
    }

    void addCarni(Carnivore *carni)
    {
        m_carnis.push_back(carni);
    }

    void deleteCarni()
    {
        delete m_carnis[m_carnis.size() - 1];
        m_carnis.pop_back();
    }

    void feedHerbivores()
    {
        for(int i{0}; i < m_herbis.size(); ++i) {
            m_herbis[i]->eat(100);
        }
    }

    void feedCarnivores()
    {
        
        if(m_herbis.size() >= m_carnis.size()) {
            //запоминаю порядковый номер жертвы
            int victim = m_herbis.size() - 1;
            
            for(int i{0}; i < m_carnis.size(); ++i) {
                
                //если хищник скушал зверушку
                if(m_carnis[i]->eat(m_herbis[victim - i])) {
                    deleteHerbi();
                }
            }
        } else {
            std::cout << "In continent no herbivores left!!!\n";
        }
    }

};

class Africa: public Continent
{
    public:
    Africa()
    {
        Herbivore *tempHerb;
        for(int i{0}; i < 10; ++i) {
            
            if(i < 2)
                tempHerb = new Bison;
            else
                tempHerb = new Antelope;

            addHerbi(tempHerb);
        }

        Carnivore *tempCarni;
        
            tempCarni = new Wolf;
            addCarni(tempCarni);

            tempCarni = new Lion;
            addCarni(tempCarni);
        

        tempHerb = nullptr;
        tempCarni = nullptr;

        std::cout << "Africa created!\n";
    }
    ~Africa()
    {
        std::cout << "Africa deleted!\n";
    }
};

class NorthAmerica: public Continent
{
    NorthAmerica()
    {
        Herbivore *tempHerb;
        for(int i{0}; i < 10; ++i) {

            if(i % 3)
                tempHerb = new Bison;
            else
                tempHerb = new Antelope;

            addHerbi(tempHerb);
        }

        Carnivore *tempCarni;

        tempCarni = new Wolf;
        addCarni(tempCarni);

        tempCarni = new Lion;
        addCarni(tempCarni);


        tempHerb = nullptr;
        tempCarni = nullptr;

        std::cout << "North America created!\n";
    }

    ~NorthAmerica()
    {
        std::cout << "North America deleted!\n";
    }
};