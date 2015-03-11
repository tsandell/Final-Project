//
//  Trainer.h
//  CreatureTrainer
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#ifndef __CreatureTrainer__Trainer__
#define __CreatureTrainer__Trainer__

#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include "Class1.h"
using namespace std;

class Trainer {
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  returns 'a' or 's#' given the situation.
     This is where the bulk of your code will go. The implementation
     of your AI goes here.
     */
    string makeMove(stringstream& situation);
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Prints out the final situation
     */
    void finalSituation(stringstream& situation);
    
    
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Splits a string into a vector of strings
     */
    vector<string> splitString(string inString, string splitOn=" ");
    
private:
    // vvvvvv Your changes to Trainer.h go between this line…
    int runner;
    bool haveRan;
    Class1 creatures[26];
    int findNum(string name);
    int curPokemon = 0;
    int party[4];
    int health[4];
    int swappedIn[4];
    string swapCreatures(int mem);
    int counter = 0;
    int bestChoice();
    string prevOpp = "Tom";
    int prevDamage = 0;
    int prevPokemon = 1;
    int name[4];
    int maxHealthp[4];
    int curOpp;
    bool fainted = false;
    int potion = 0;
    int revive = 0;
    int aboost = 0;
    int dboost = 0;
    int collar = 20;
    int sa = 0;
    int sb = 0;
    int sc = 0;
    int sd = 0;
    int se = 0;
    int sf = 0;
    int sg = 0;
    int sh = 0;
    int enemysDamage;
    int enemysType;
    int enemyLevelOpp;
    int aboostOn = 0;
    
    // ^^^^^^ And this line. That's it!
    
};

#endif /* defined(__CreatureTrainer__Trainer__) */

