#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template<typename T>
int findKeyIndexInVector(const T &key, const std::vector<T> &list) {
    const int NOT_FOUND = -1;
    auto it = std::find_if(list.cbegin(), list.cend(), [key](const T &i){ return i == key; });

    if (it != list.cend()) {
        return (int)std::distance(list.cbegin(), it);
    }

    return NOT_FOUND;
}

class Talent {
protected:
    string ability;
    bool status;

    explicit Talent(bool inStatus) : status{inStatus} {}

public:
    void changeFlag() { status = !status; }

    string getTalentName() { return ability; }

    void showTalent() { cout << (status ? "  can " : "  can`t ") << ability << endl; }
};

// Группа похожих классов (TalentSwim, TalentDance, TalentCount) сделана лишь в демонстрационных целях:
class TalentSwim : public Talent {
public:
    explicit TalentSwim(bool inStatus) : Talent(inStatus) { ability = "swim"; }
};

class TalentDance : public Talent {
public:
    explicit TalentDance(bool inStatus) : Talent(inStatus) { ability = "dance"; }
};

class TalentCount : public Talent {
public:
    explicit TalentCount(bool inStatus) : Talent(inStatus) { ability = "count"; }
};

// ---

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

int main() {
    Dog dog("Max");
    dog.setTalent(new TalentSwim(true));
    dog.setTalent(new TalentDance(false));
    dog.setTalent(new TalentCount(true));

    dog.showTalents();

    // Можно менять таланты по их наименованию (swim/dance/count):
    dog.changeTalent("dance");

    dog.showTalents();

    return 0;
}
