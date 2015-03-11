//  Class1.cpp
//  Helper Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#include "Class1.h"
#include <string>
#include <iostream>
using namespace std;
const string CREATURE_NAMES[] = { "Axolotyl", "Bittern", "C-lacanth",
    "Dugong", "Echidna", "Fossa", "Guanaco", "Honeybdgr", "Ibex", "Jackal",
    "Kiwi", "Loris", "Megapode", "Narwhal", "Ovenbird", "Pika", "Quagga",
    "RockHyrax", "Solenodon", "Tuatara", "Uromastyx", "Vaquita", "Wolverine",
    "Xenops", "Yaminon", "Zebu" };

const string ELEMENT_NAMES[] = { "Air", "Bombast", "Cool", "Dark",
    "Earth", "Funk", "Gamma", "Hammer" };


Class1::Class1()
{
    created = false;
    for(int j=0; j<26; j++)
    {
        set[j] = false;
    }
}

void Class1::createParty(string name, int health, string type, int damage)
{
    created = true;
    for(int j = 0; j < 26; j++)
    {
        if(name == CREATURE_NAMES[j])
        {
            type = j;
        }
    }
    maxHealth = health;
    for(int j = 0; j < 26; j++)
    {
        if(type == ELEMENT_NAMES[j])
        {
            move = j;
        }
    }
    if(damage == 8 || damage == 4 || damage == 2)
    {
        attack = 4;
    }
    else if(damage > 12 || damage == 6 || damage == 3)
    {
        attack = 6;
    }
    else
    {
        attack = 4;
    }
    
}


void Class1::createOpp(string name, string type, int damage)
{
    created = true;
    for(int j = 0; j < 26; j++)
    {
        if(name == CREATURE_NAMES[j])
        {
            type = j;
        }
    }
    for(int j = 0; j < 26; j++)
    {
        if(type == ELEMENT_NAMES[j])
        {
            move = j;
        }
    }
    if(damage == 8 || damage == 4 || damage == 2)
    {
        attack = 4;
    }
    else if(damage > 12 || damage == 6 || damage == 3)
    {
        attack = 6;
    }
    else
    {
        attack = 4;
    }
}

int Class1::getType()
{
    return type;
}

void Class1::setType(string name)
{
    for(int j = 0; j < 26; j++)
    {
        if(name == CREATURE_NAMES[j])
        {
            type = j;
        }
    }
}

int Class1::getHealth()
{
    return maxHealth;
}

void Class1::setHealth(int max)
{
    maxHealth = max;
}

void Class1::setStrong(string mover)
{
    int temp = 0;
    for(int j = 0; j < 8; j++)
    {
        if(mover == ELEMENT_NAMES[j])
        {
            temp = j;
        }
    }
    strong[temp] = true;
}

bool Class1::isStrong(string mover)
{
    int temp = 0;
    for(int j = 0; j < 8; j++)
    {
        if(mover == ELEMENT_NAMES[j])
        {
            temp = j;
        }
    }
    return strong[temp];
}

void Class1::setWeak(string mover)
{
    int temp = 0;
    for(int j = 0; j < 8; j++)
    {
        if(mover == ELEMENT_NAMES[j])
        {
            temp = j;
        }
    }
    weak[temp] = true;
}

bool Class1::isWeak(string mover)
{
    int temp = 0;
    for(int j = 0; j < 8; j++)
    {
        if(mover == ELEMENT_NAMES[j])
        {
            temp = j;
        }
    }
    return weak[temp];
}

void Class1::setHeal(int healer)
{
    heal = healer;
}

void Class1::setAttack(int attackVal)
{
    attack = attackVal;
}

int Class1::getAttack()
{
    return attack;
}

bool Class1::getCreated()
{
    return created;
}

void Class1::setRatio(int attack, int defend, int pos)
{
    ratio[pos] = (double)attack/defend;
    //cout << attack << " " << defend << " " << ratio[pos] << " HERES THE RATIO";
    set[pos] = true;
}
double Class1::getRatio(int pos)
{
    return ratio[pos];
}
bool Class1::isRatioSet(int pos)
{
    //Will this work
    return set[pos];
}
