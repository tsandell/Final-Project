//
//  Class1.h
//  Class1
//
//  These class heaaders are for use in your Trainer class. If you wish to 
//  write helper classes, write them in these 5 classes. 
//  Use of these classes is optional. You may use none or any or all of them. 
//  You still may NOT #include any.h files we provide you
//  (Battle, Creature, CreatureType, EECSRandom, Party, PrintHelper)
//

#ifndef __CreatureTrainer__Class1__
#define __CreatureTrainer__Class1__

// vvvvvv Your implementations go between this lineÖ
#include <string>
using namespace std;

class Class1{
private:
    int type;
    int move;
    int maxHealth;
    double ratio[26];
    bool strong[8];
    bool weak[8];
    int heal;
    int attack;
    bool created;
    bool set[26];
    
public:
    Class1();
    void createParty(string name, int health, string type, int damage);
    void createOpp(string name, string type, int damage);
    void setType(string name);
    int getType();
    int getHealth();
    void setRatio(int attack, int defend, int pos);
    double getRatio(int pos);
    bool isRatioSet(int pos);
    void setHealth(int max);
    void setStrong(string mover);
    bool isStrong(string mover);
    void setWeak(string mover);
    bool isWeak(string mover);
    void setHeal(int healer);
    void setAttack(int attackVal);
    int getAttack();
    bool getCreated();
};





// ^^^^^^ And this line. That's it!

#endif /* defined(__CreatureTrainer__Class1__) */
