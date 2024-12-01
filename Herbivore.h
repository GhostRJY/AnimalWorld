#pragma once
#include<iostream>

class Herbivore
{
    friend std::ostream &operator<<(std::ostream &out, const Herbivore &object)
    {
        out << " Herbivore ";
        return out;
    }

    protected:
    int m_weight;
    bool m_live;

    public:
    Herbivore(int weight = 50)
    {
        setWeight(weight);
        setLive(true);

        std::cout << "Herbivore created \n";
    }

    virtual ~Herbivore()
    {
        std::cout << "Herbivore deleted \n";
    }

    void setWeight(const int weight)
    {
        if(weight > 0)
            m_weight = weight;
        else
            m_weight = 50;
    }

    int getWeight() const
    {
        return m_weight;
    }

    void setLive(bool live)
    {
        m_live = live;
    }
    
    bool getLive() const
    {
        return m_live;
    }

    virtual void eat(int grassCount) = 0;
    
    void kill()
    {
        setLive(false);
    }

    virtual void showMe() const = 0;

};

class Antelope: public Herbivore
{
    friend std::ostream &operator<<(std::ostream &out, const Antelope &object)
    {
        out << " Antelope ";
        return out;
    }

    public:
    Antelope() : Herbivore(100)
    {
        std::cout << "Antelope created \n";
    }

    ~Antelope()
    {
        std::cout << "Antelope deleted! \n";
    }

    virtual void eat(int grassCount) override
    {
        m_weight += grassCount / 2;
        std::cout << "\nAntelope ate " << grassCount / 2 << " herbage and its weight " << getWeight() << '\n';
    }

    void showMe() const override
    {
        std::cout << " Antelope ";
    }
};

class Bison: public Herbivore
{
    friend std::ostream &operator<<(std::ostream &out, const Bison &object)
    {
        out << " Bison ";
        return out;
    }

    public:
    Bison(): Herbivore(600)
    {
        std::cout << "Bison created \n";
    }

    ~Bison()
    {
        std::cout << "Bison deleted \n";
    }

    virtual void eat(int grassCount) override
    {
        m_weight += grassCount/2;
        std::cout << "\nBison ate " << grassCount / 2 << " herbage and its weight " << getWeight() << '\n';
    }

    void showMe() const override
    {
        std::cout << " Bison ";
    }

};