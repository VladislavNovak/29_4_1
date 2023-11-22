#ifndef INC_29_4_1_ANIMALGROUP_H
#define INC_29_4_1_ANIMALGROUP_H

#include <iostream>
#include <string>
#include <vector>
#include "utilities.h"
#include "TalentGroup.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Animal {
protected:
    string name;
    vector<Talent*> talents;

    virtual void showTalents() = 0;

    virtual void setTalent(Talent* talent) = 0;

    virtual int changeTalent(const string &talentName) = 0;

public:
    explicit Animal(string inName) : name{std::move(inName)} {}

    virtual ~Animal() {
        if (!talents.empty()) {
            for (auto &talent: talents) { delete talent; }
            talents.clear();
        }
    }
};

class Dog : public Animal {
public:
    [[maybe_unused]] explicit Dog(string inName) : Animal(std::move(inName)) {};

    void setTalent(Talent* talent) override { talents.emplace_back(talent); }

    // Талант можно поменять по наименованию
    int changeTalent(const string &talentName) override {
        if (talents.empty()) return -1;

        vector<string> collection;
        collection.reserve(talents.size());
        for (auto &talent : talents) { collection.emplace_back(talent->getTalentName()); }

        int index = findKeyIndexInVector(talentName,collection);
        if (index == -1) return -1;

        talents[index]->changeFlag();
        return index;
    }

    void showTalents() override {
        if (!talents.empty()) {
            cout << name << ":" << endl;
            for (const auto &talent: talents) { talent->showTalent(); }
        }
    }
};

#endif //INC_29_4_1_ANIMALGROUP_H
