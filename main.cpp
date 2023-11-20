#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Talent {
protected:
    string name;
    bool ability;

    Talent(string inName, bool inAbility) : name{std::move(inName)}, ability{inAbility} {}

public:
    virtual void changeFlag(bool flag) = 0;
    virtual void showTalent() = 0;
};

// Каждая способность, наследуемая от абстрактного класса Talent,
// должна быть представлена в виде отдельного класса.
class TalentSwim : public Talent {
public:
    TalentSwim(string inName, bool inAbility) : Talent(std::move(inName), inAbility) {}

    void changeFlag(bool flag) override { ability = flag; }

    void showTalent() override { cout << (ability ? "ability " : "not ability ") << name << endl; }
};

class TalentDance : public Talent {
public:
    TalentDance(string inName, bool inAbility) : Talent(std::move(inName), inAbility) {}

    void changeFlag(bool flag) override { ability = flag; }

    void showTalent() override { cout << (ability ? "ability " : "not ability ") << name << endl; }
};

class TalentCount : public Talent {
public:
    TalentCount(string inName, bool inAbility) : Talent(std::move(inName), inAbility) {}

    void changeFlag(bool flag) override { ability = flag; }

    void showTalent() override { cout << (ability ? "ability " : "not ability ") << name << endl; }
};

// ---

class Animal {
protected:
    vector<Talent*> talents;
    virtual void doVoice() = 0;
    virtual void showTalents() = 0;
};

class Dog : public Animal {
public:
    Dog() = default;

    void setTalent(Talent* talent) {
        talents.emplace_back(talent);
    }

    void doVoice() override {
        cout << "Voice" << endl;
    }

    void showTalents() override {
        if (!talents.empty()) {
            for (const auto &talent : talents) {
                talent->showTalent();
            }
        }
    }
};


int main() {
    Dog dog;
    dog.setTalent(new TalentSwim("swim", true));
    dog.setTalent(new TalentDance("dance", false));
    dog.setTalent(new TalentCount("count", true));

    dog.showTalents();

    return 0;
}
