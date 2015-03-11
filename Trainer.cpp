//
//  Trainer.cpp
//  CreatureTrainer
//
//  You may NOT #include any .h files we provide you (Battle, Creature, CreatureType,
//  EECSRandom, Party, PrintHelper)
//  other than the ones name "ClassX.h" and "Trainer.h"
//  You may #include other <> libraries if you wish to
//
//  Created by Jeremy Gibson on 11/4/14.
//  Copyright (c) 2014 Jeremy Richard Gibson. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Trainer.h"
#include "Class1.h"
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "CreatureType.h"

//#include "CreatureType.h"

using namespace std;

string Trainer::makeMove(stringstream& situation) {
    // pull the entire string out of stringStream& situation
    string situationString = situation.str();
    //cout << situationString;
    // situationString now includes ALL of the lines that will be sent to cout
    
    // Here's how to use the stringSplit function
    vector<string> lines = splitString(situationString, "\n");
    // This splits situationString into a vector of individual lines.
    // (it splits on the new line character "\n")
    // To access the 3rd line (as in 0, 1, 2, 3), you would use bracket access
    //   as in: lines[3]
    
    // This loop will iterate through all the lines
    int pipeLine = -1;
    // lines.size() tells us how many elements are in the vector<string> lines
    // In this case, it tells us how many lines we pulled in
    int placeholder = 0;
    for (int i=0; i<lines.size(); i++) {
        // Store each line in the string line
        string line = lines[i];
        // Store the first char of line in the char c
        char c = line[0];
        // If c is a pipe ('|'), then this is the line that tells us about our
        //    party and the health of each Creature we own.
        if (c == '|') {
            // Store which line number this is
            pipeLine = i;
            placeholder = i;
        }
    }
    
    if(!CreatureType::REACH_VERSION)
    {
        collar = 0;
    }
    // Now that we know which line has the health, do something with it
    //cout << lines[pipeLine] << "\n"; // Output for testing only
    
    // Split the party health line by pipes "|"
    vector<string> creatureHealthBits = splitString(lines[pipeLine], "|");
    // This gives us something like the vector description below
    /* { "",
     " *Jackal     10/10",
     " Yaminon    17/17",
     " Megapode   13/13",
     " Jackal     10/10",
     "" } */
    // You can see that the first and last pipe caused empty strings
    
    // Now, go through this information and pull out info for each entry
    // We do 1 to <creatureHealthBits.size()-1 because we only need the middle
    //    four elements (and are skipping the empty ones.
    string current;
    for (int i=1; i<creatureHealthBits.size()-1; i++) {
        // cout just for testing
        //cout << creatureHealthBits[i] << "\n";
        
        // We are putting the string into a stringStream so we can use >>
        stringstream ss;
        ss << creatureHealthBits[i];
        
        // For example, we have a stringstream ss containing " *Jackal   10/10 "
        // pull the name as a string
        string name;
        ss >> name; // name = "*Jackal"
        // levels[i-1] = name[name.length()-1]-'0';
        //cout << "Updating now";
        for (int i = 0; i<5; i++) {
            //cout << levels[i];
        }
        //cout << "HERE: ";
        if (name[0] == '*'){
            for ( int i = 1; i < name.length(); i++){
                name[i - 1] = name[i];
            }
            name.resize(name.length() - 1);
            current = name;
            //cout << "DOES THIS WORK" << current;
        }
        
        
        
        // pull the health
        int healthy;
        ss >> healthy; // health = 10
        health[i-1] = healthy;
        //cout << name << endl;
        party[i-1] = findNum(name);
        // Get rid of the slash char
        char slash;
        ss >> slash; // slash = '/'
        
        // get max health
        int maxHealth;
        ss >> maxHealth; // maxHealth = 10
        maxHealthp[i-1] = maxHealth;
        
        // cout this info for testing purposes
        //cout << "Name: " << name << " health: " << health << "\n";
    }
    /* string bullshit;
     string potion;
     string revive;
     string collar;
     vector<string> itembits = splitString(lines[pipeLine + 2], "!");
     stringstream is;
     is >> potion >> bullshit >> bullshit >> revive >> collar;
     
     */
    
    
    // This is something else you can do ONLY for testing.
    // In a previous post, I recommended #including CreatureType.h so that you
    //    can make a Trainer::decide() function that will make the right
    //    decision if you have perfect data about creature types.
    // While developing, you can use the static vector<CreatureType> TYPES to
    //    get that perfect information, though you will eventually need to write
    //    your own function to learn that information from the data that is sent
    //    in via stringstream& situation.
    string item;
    stringstream ssss;
    string bullshit;
    string enemyName = "place-0";
    string myType;
    string myName;
    string myDamage;
    string enemyDamage;
    string enemyType;
    string enemyLevel = "";
    string myLevel = "";
    ///////////////////
    ///////////////////
    stringstream ugh;
    string faintswap;
    ugh << lines[pipeLine - 4];
    ugh >> bullshit >> faintswap;
    //////////////////
    stringstream s;
    string tempf;
    s << lines[pipeLine - 2];
    s >> bullshit >> bullshit >> tempf;
    ////////////////////////
    
    stringstream tt;
    string temps;
    tt << lines[pipeLine - 3];
    tt >> bullshit >> temps;
    
    //////////////////////////
    
    stringstream ef;
    string tempef;
    ef << lines[pipeLine - 5];
    ef >> bullshit >> bullshit >> tempef;
    //////////////////////////
    stringstream ps;
    string tempp;
    ps << lines[pipeLine-3];
    ps >> bullshit >> bullshit >> bullshit >> tempp;
    ///////////////////////////////////////////
    stringstream ab;
    string tempab;
    ab << lines[pipeLine - 3];
    ab >> bullshit >> bullshit >> tempab;
    ///////////////////////////////////
    stringstream re;
    string tempr;
    re << lines[pipeLine - 4];
    re >> bullshit >> tempr;
    ///////////////////////////
    /*HERES WHERE I CHANGED STUFF
    stringstream rend;
    string temprnd;
    re << lines[pipeLine - 3];
    re >> bullshit >> temprnd;*/
    ////////////////////////
    
    stringstream ff;
    string tempfaint;
    ff << lines[pipeLine - 6];
    ff >> tempfaint;
    ////////////////////////
    stringstream sl;
    string tempg;
    sl << lines[pipeLine - 3];
    sl >> bullshit >> tempg;
    ////////////////////
    stringstream fp;
    string tempfp;
    fp << lines[pipeLine - 4];
    fp >> bullshit >> bullshit >> bullshit >> tempfp;
    ///////////////////////////
    //cout << tempfaint;
    //THIS IS IF THE OPPONENT FAINTS
    fainted = false;
    /* if(tempef == "faints!")
     {
     fainted = true;
     }
     else{
     fainted = false;
     } */
    
    
    //////////////////////
    
    
    if (counter == 0) {
        
        stringstream ss;
        //string enemyName;
        ss << lines[pipeLine - 3];
        ss >> bullshit >> bullshit >> bullshit >> enemyName;
        int temp = (enemyName.length() - 1);
        enemyName.resize(temp);
        if (curPokemon == 0){
            
        }
        /*
         //levels[4] = enemyName[(enemyName.length()-1) - '0'];
         cout << "Levels array: ";
         for (int i = 0; i<5; i++) {
         cout << levels[i];
         }
         */
        //cout << enemyName << endl;
        counter = 1;
    }
    
    //THIS IS IF THE OPPONENT FAINTS
    fainted = false;
    if(tempef == "faints!")
    {
        
        stringstream win;
        win << lines[pipeLine - 6];
        win >> bullshit >> myName >> bullshit >> bullshit >> enemyName;
        fainted = true;
        counter = 0;
    }
    else if (tempf == "faints!" && tempfp == "Potion") {
        stringstream ss;
        ss << lines[pipeLine - 3];
        ss >> bullshit >> enemyName >> bullshit >> bullshit >> myName
        >> bullshit >> enemyType;
    }
    else if (tempp == "Potion"){
        stringstream ss;
        ss << lines[pipeLine - 2];
        ss >> bullshit >> enemyName >> bullshit
        >> bullshit >> myName >> bullshit >> enemyType >> bullshit
        >> enemyDamage;
    }
    else if (tempab == "AtkBst,"){
        stringstream ss;
        ss << lines[pipeLine - 2];
        ss >> bullshit >> enemyName >> bullshit
        >> bullshit >> myName >> bullshit >> enemyType >> bullshit
        >> enemyDamage;
    }
    else if (tempr == "revived"){
        stringstream ss;
        ss << lines[pipeLine -3];
        ss >> bullshit >> enemyName >> bullshit >> bullshit >>
        myName >> bullshit >> enemyType >> bullshit >> enemyDamage;
    }
    
    else if (tempf == "faints!" && faintswap == "swaps"){
        stringstream ss;
        ss << lines[pipeLine - 3];
        ss >> bullshit >> enemyName >> bullshit
        >> bullshit >> myName >> bullshit >>
        enemyType;
        
    }
    
    else if (tempf == "faints!") {
        
        stringstream ss;
        ss << lines[pipeLine - 4];
        
        string bullshit;
        //string myName;
        ss >> bullshit >> myName >> bullshit >> bullshit >> enemyName
        >> bullshit >> myType >> myDamage;
        ss >> bullshit >> bullshit >> bullshit >> bullshit >>
        bullshit >> bullshit >> enemyType >> bullshit >> enemyDamage;
        
        /*
         //string enemyName;
         ss >> bullshit >> bullshit >> enemyName;
         
         //string myType;
         ss >> bullshit >> myType;
         
         //int myDamage;
         ss >> bullshit >> myDamage;
         
         char period;
         ss >> bullshit >> period;
         
         //cout << myName << enemyName << myType << myDamage << endl;
         
         stringstream sss;
         sss << lines[pipeLine - 3];
         
         
         //string enemyType;
         sss >> bullshit >> bullshit >> bullshit >> bullshit >> bullshit >>
         bullshit >> enemyType;
         
         //int enemyDamage;
         sss >> bullshit >> enemyDamage;
         
         
         sss >> bullshit >> period;
         */
        
        //cout << "YAY YOU GOT ME!";
        for(int j=0; j<4; j++)
        {
            swappedIn[j] = 0;
        }
        
        //cout << enemyType << enemyDamage;
    }
    
    else if (temps == "swaps"){
        stringstream ss;
        
        ss << lines[pipeLine - 2];
        ss >> bullshit >> enemyName >> bullshit >> bullshit >> myName >>
        bullshit >> enemyType >> bullshit >> enemyDamage >> bullshit;
        //bullshit >> enemyType;
        
        //int enemyDamage;
        //ss >> bullshit >> enemyDamage;
        
        
        //ss >> bullshit;
        
        //cout << enemyType << enemyDamage;
    }
    
    //if NOT first move
    else {
        
        stringstream ss;
        ss << lines[pipeLine - 3];
        
        string bullshit;
        //string myName;
        ss >> bullshit >> myName;
        
        //string enemyName;
        if(fainted)
        {
            
            ss >> bullshit >> enemyName;
        }
        else
        {
            ss >> bullshit >> bullshit >> enemyName;
        }
        //levels[4] = enemyName[(enemyName.length()-1) - '0'];
        
        //string myType;
        ss >> bullshit >> myType;
        
        //int myDamage;
        ss >> bullshit >> myDamage;
        
        char period;
        ss >> bullshit >> period;
        
        //cout << myName << enemyName << myType << myDamage << endl;
        
        stringstream sss;
        sss << lines[pipeLine - 2];
        
        
        //string enemyType;
        sss >> bullshit >> bullshit >> bullshit >> bullshit >> bullshit >>
        bullshit >> enemyType;
        
        //int enemyDamage;
        sss >> bullshit >> enemyDamage;
        
        
        sss >> bullshit >> period;
        
        //cout << enemyType << enemyDamage;
        
    }
    myName = current;
    
    bool grew = false;
    //item counter
    stringstream it;
    if (tempg == "grows"){
        it << lines[pipeLine -4];
        it >> bullshit >> bullshit >> item;
        grew = true;
    }
    else {
        it << lines[pipeLine - 2];
        it >> bullshit >> bullshit >> item;
    }
    if (item == "Potion."){
        potion++;
    }
    if (item == "Revive." ){
        revive++;
        
    }
    if (item == "AtkBst."){
        aboost++;
    }
    if (item == "DefBst."){
        dboost++;
    }
    if ( item == "Air"){
        sa++;
    }
    if (item == "Bombast"){
        sb++;
    }
    if (item == "Dark"){
        sd++;
    }
    if (item == "Earth"){
        se++;
    }
    if (item == "Funk"){
        sf++;
    }
    if (item == "Gamma"){
        sg++;
    }
    if (item == "Hammer"){
        sh++;
    }
    if (myName[0] == 'C'){
        vector<string> mlevel = splitString(myName, "-");
        myLevel = mlevel[2];
    }
    else {
        vector<string> mlevel = splitString(myName, "-");
        myLevel = mlevel[1];
    }
    if (enemyName[0] == 'C'){
        vector<string> elevel = splitString(enemyName, "-");
        enemyLevel = elevel[2];
        
    }
    else {
        //cout << enemyName;
        vector<string> elevel = splitString(enemyName, "-");
        if(elevel[1]==enemyName)
        {
            enemyLevel = "0";
        }
        //enemyLevel = elevel[1];
    }
    
    //levels[4] = enemyName[(enemyName.length()-1)]-'0';
    //cout << " DFKJLS  " << levels[4] << enemyName;
    
    
    /*
     // This makes ct a copy of the CreatureType for Creature 0 (the Axolotyl).
     // All CreatureType and Element names start with a different letter of the
     //    alphabet (CreatureType is A-Z, Element is A-H).
     CreatureType ct = CreatureType::TYPES[0];
     // You can then get the type of ct, which is 0 because it's the Axolotyl
     int type = ct.getType();
     // You can also directly get info from CreatureTypes::TYPES elements.
     int elementalWeakness3 = CreatureType::TYPES[3].getElementalWeakness();
     */
    
    // Output for human player
    // Instead of doing this, you will need to replace the code of Trainer
    // to parse the input situation and create a proper response,
    // (like "a" for attack or "s3" to swap to the creature in slot 3).
    //cout << situationString;
    
    //cout << "find this plz "<<  "My name : " << myName << " Enemy Name: " << enemyName << endl;
    //cout << item << endl;
    //cout << potion << " " << revive << " " << collar << endl;
    //cout << sa << " " << sb << " " << sc << " " << sd << " "
    //<< se << " " << sf << " " << sg << " "<< sh << " ";
    //cout << endl << "ENEMY LEVEL " << enemyLevel;
    //cout << endl << "MY LEVEL " << myLevel;
    
    /*
     * This line is basically what your AI chooses to do
     * When first playing, you may type in your move.
     * For both the core and reach portions, however, you need to
     * comment out "cin >> response" and instead have this function
     * generate a response string.
     */
    
    /*string enemyName;
     string myType;
     string myName;
     string myDamage;
     string enemyDamage;
     string enemyType;*/
    
    string response;
    string name, type, name2, type2;
    int healthy, damage=0, damage2=0;
    int curMember, curHealth;
    name = myName;
    type = myType;
    damage = atoi(myDamage.c_str());
    damage2 = atoi(enemyDamage.c_str());
    type2 = enemyType;
    name2 = enemyName;
    curOpp = findNum(enemyName);
    
    if(!creatures[findNum(name)].getCreated())
    {
        creatures[findNum(name)].createParty(name, healthy, type, damage);
    }
    if(!creatures[findNum(name2)].getCreated())
    {
        creatures[findNum(name2)].createOpp(name2, type2, damage2);
    }
    curHealth = health[curPokemon];
    
    //if(((prevOpp != enemyName) || (prevPokemon != curPokemon)) && !fainted)
    if(damage != 0 && damage2 != 0)
    {
        creatures[findNum(myName)].setRatio(damage, damage2, findNum(enemyName));
    }
    
    /*if(damage == 12)
    {
        swappedIn[curPokemon] = 10;
    }*/
    
    //cout << " " << prevOpp << " " << enemyName;
    if(prevOpp != enemyName)
    {
        for(int j=0; j<4; j++)
        {
            swappedIn[j] = 0;
        }
    }
    
    //cin >> response;
    //bool sameGuy = prevPokemon == curPokemon;
    //cout << curHealth << " " << damage2 << " Look at this";
    enemyLevelOpp =  atoi(enemyLevel.c_str());
    enemysDamage = CreatureType::TYPES[findNum(enemyName)].getAttackBase() + enemyLevelOpp* CreatureType::TYPES[findNum(enemyName)].getAttackPerLevel();
    enemysType = CreatureType::TYPES[findNum(enemyName)].getElementalAttackType();
    int enemysDamageCur = enemysDamage;
    if(enemysType == CreatureType::TYPES[party[curPokemon]].getElementalStrength())
    {
        enemysDamageCur /= 2;
    }
    if(enemysType == CreatureType::TYPES[party[curPokemon]].getElementalWeakness())
    {
        enemysDamageCur *= 2;
    }
    //cout << "HELLO THERE " << enemysDamageCur << endl;
    //cout << endl << curHealth << " " << enemysDamageCur << " " << curPokemon;
    //cout << "HI " << enemysDamageCur << " " << curHealth;
    aboostOn--;
    if(curHealth <= enemysDamageCur && !fainted && !grew)
    {
        //cout << "YOU MADE IT HERE";
        response = swapCreatures(curPokemon);
    }
    else if(curHealth > enemysDamageCur*2 && !fainted && aboost > 0 && aboostOn <= 0)
    {
        response = "ab";
        aboost--;
        aboostOn = 4;
        //response = "a";
    }
    else
    {
        response = "a";
    }
    prevOpp = enemyName;
    prevDamage = damage2;
    prevPokemon = curPokemon;
    if(grew)
    {
        response = "r";
    }
    
    
    //swappedIn[curPokemon] = true;
    
    /*response = "a";
     runner++;
     if(runner == 20)
     {
     response = "s2";
     }
     else if(runner == 40)
     {
     response = "s3";
     }
     else if(runner == 60)
     {
     response = "s4";
     }*/
    //cout << myName << enemyName << endl;
    for(int j=0; j<4; j++)
    {
        //cout << j << "Name" << party[j] << "health" << health[j] << endl;
    }
    if(fainted)
    {
        response = "r";
        //cout << party[curPokemon];
        int recovery = CreatureType::TYPES[party[curPokemon]].getHealthRestIncrease();
        int maxHealthTom = health[curPokemon] + recovery;
        bool switchy = false;
        //cout << recovery;
        int tom=0;
        for(int j=0; j<4; j++)
        {
            if(health[j] > maxHealthTom)
            {
                switchy = true;
                maxHealthTom = health[j];
                stringstream st3;
                st3 << "s" << (j+1);
                tom = j;
                response = st3.str();
                //cout << response;
            }
        }
        int enemyLevelz = atoi(enemyLevel.c_str());
        int oppHealth = CreatureType::TYPES[findNum(enemyName)].getHealthMaxBase();
        oppHealth += CreatureType::TYPES[findNum(enemyName)].getHealthMaxPerLevel()*enemyLevelz;
        int minMaxHealth = 100000;
        int pos = 0;
        for(int j=0; j<4; j++)
        {
            if(maxHealthp[j] < minMaxHealth)
            {
                pos = j;
                minMaxHealth = maxHealthp[j];
            }
        }
        for(int j=0; j<4; j++)
        {
            if(health[j] == 0)
            {
                pos = j;
                minMaxHealth = 0;
            }
        }
        //cout << minMaxHealth << " HI" << "YO" << oppHealth;
        if(minMaxHealth+2 < oppHealth && collar > 0)
        {
            stringstream st4;
            st4 << "co" << (pos+1);
            response = st4.str();
            switchy = false;
            collar--;
        }
        if(switchy)
        {
            curPokemon = tom;
        }
    }
    //cout << " HI " << curPokemon;
    //cout << response;
    return response;
}

string Trainer::swapCreatures(int member)
{
    int returner = 0;
    returner = bestChoice();
    if(returner == curPokemon)
    {
        curPokemon = returner;
        return "a";
    }
    else if(returner == 9)
    {
        potion--;
        return "po";
    }
    else if(returner >= 12)
    {
        revive--;
        stringstream st34;
        st34 << "re" << (returner-12+1);
        return st34.str();
    }
    else
    {
        swappedIn[returner]++;
        curPokemon = returner;
        stringstream st;
        st << "s" << (returner+1);
        return st.str();
    }
}

int Trainer::bestChoice()
{
    int max=0;
    int greatest=0;
    int returner=curPokemon;
    for(int j=0; j<4; j++)
    {
        int enemysDamageCur = enemysDamage;
        if(enemysType == CreatureType::TYPES[party[curPokemon]].getElementalStrength())
        {
            enemysDamageCur /= 2;
        }
        if(enemysType == CreatureType::TYPES[party[curPokemon]].getElementalWeakness())
        {
            enemysDamageCur *= 2;
        }
        
        if(health[j] > 2* enemysDamageCur && health[j] > max)
        {
            max = health[j];
            greatest = party[j];
            returner = j;
        }
    }
    if(returner == curPokemon)
    {
        for(int j=0; j<4; j++)
        {
            int enemysDamageCur = enemysDamage;
            if(enemysType == CreatureType::TYPES[party[j]].getElementalStrength())
            {
                enemysDamageCur /= 2;
            }
            if(enemysType == CreatureType::TYPES[party[j]].getElementalWeakness())
            {
                enemysDamageCur *= 2;
            }
            
            if(health[j] > enemysDamageCur && health[j] > max && swappedIn[j] < 3)
            {
                max = health[j];
                greatest = party[j];
                returner = j;
            }
        }
    }
    if(returner == curPokemon)
    {
        if(health[curPokemon] < maxHealthp[curPokemon] && potion > 0 && health[curPokemon] > 0)
        {
            returner = 9;
        }
        else if(revive > 0 && health[curPokemon] > 0)
        {
            for(int j=0; j<4; j++)
            {
                if(health[j] == 0)
                {
                    returner = 12 + j;
                }
            }
        }
    }
    if(returner == curPokemon)
    {
        //cout << "AND HERE" << endl;
        if(health[curPokemon] == 0)
        {
            //cout << "HERE TOO" << endl;
            for(int j=0; j<4; j++)
            {
                if(health[j] > 0)
                {
                    returner = j;
                }
            }
        }
    }
    return returner;
}

void Trainer::finalSituation(stringstream& situation) {
   // cout << situation.str();
    
    
}



vector<string> Trainer::splitString(string inString, string splitOn) {
    vector<string> elements;
    string substring;
    
    size_t splitIndex = inString.find(splitOn),
    substrStart = 0;
    
    // keep searching until no spaces remain
    while (splitIndex != string::npos) {
        substring = inString.substr(substrStart, splitIndex - substrStart);
        elements.push_back(substring);
        substrStart = splitIndex + 1;
        // start at next character after finding substring
        splitIndex = inString.find(splitOn, substrStart);
    }
    // add last element to vector
    substring = inString.substr(substrStart, inString.length() - substrStart);
    elements.push_back(substring);
    
    return elements;
}

int Trainer::findNum(string name)
{
    const string CREATURE_NAMES[] = { "Axolotyl", "Bittern", "C-lacanth",
        "Dugong", "Echidna", "Fossa", "Guanaco", "Honeybdgr", "Ibex", "Jackal",
        "Kiwi", "Loris", "Megapode", "Narwhal", "Ovenbird", "Pika", "Quagga",
        "RockHyrax", "Solenodon", "Tuatara", "Uromastyx", "Vaquita", "Wolverine",
        "Xenops", "Yaminon", "Zebu" };
    string name2 = name;
    name = "";
    //cout << "OLD NAME" << name2 << endl;
    for(int j=0; j<name2.length(); j++)
    {
        if(name2[j] != '-' && !(name2[j]>='0' && name2[j]<='9'))
        {
            name += name2[j];
        }
    }
    //cout << "NEW NAME" << name << endl;
    int type = 0;
    for(int j = 0; j < 26; j++)
    {
        if(name == CREATURE_NAMES[j])
        {
            type = j;
        }
    }
    return type;
}
