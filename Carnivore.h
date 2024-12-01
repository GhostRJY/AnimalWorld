#pragma once
#include"Herbivore.h"
#include<iostream>

class Carnivore
{
    protected:
    int m_power;

    public:

    Carnivore(int power = 100)
    {
        m_power = power;
        std::cout << "Carnivore created\n";
    }

    virtual ~Carnivore()
    {
        std::cout << "Carnivore deleted\n";
    }

    virtual bool eat(Herbivore * meal) = 0;
    virtual void showMe() const = 0;
};

class Wolf: public Carnivore
{
    public:
    Wolf():Carnivore(200)
    {
        std::cout << "Wolf created\n";
    }

    ~Wolf()
    {
        std::cout << "Wolf deleted\n";
    }

    bool eat(Herbivore *meal) override
    {
        if(meal->getWeight() < m_power) {
            m_power += 50;
            meal->kill();

            std::cout << "Wolf eat" << *meal << " and have power " << m_power << '\n';
            return true;
        } else {
            m_power -= 20;
            std::cout << "Wolf can't eat" << *meal << '\n';
            return false;
        }

    }
        
    virtual void showMe() const override
    {
        std::cout << "I'am a wolf with " << m_power << " power \n";
    }
    
};

class Lion: public Carnivore
{
    public:
    Lion():Carnivore(500)
    {
        std::cout << "Lion created\n";
    }

    ~Lion()
    {
        std::cout << "Lion dleted!!!\n";
    }

    bool eat(Herbivore *meal) override
    {
        if(meal->getWeight() < m_power) {
            m_power += 100;
            meal->kill();

            std::cout << "Lion eat " << *meal << " and have power "<<m_power<<'\n';
            return true;
        } else {
            m_power -= 40;
            std::cout << "Lion can't eat " << *meal << '\n';
            return false;
        }
    }

    virtual void showMe() const override
    {
        std::cout << "I'am a lion with " << m_power << " power \n";
    }
};