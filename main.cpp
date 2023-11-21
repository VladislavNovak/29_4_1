#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Talent {
protected:
    string ability;
    bool status;

    explicit Talent(bool inStatus) : status{inStatus} {}

public:
    void changeFlag() { status = !status; }

    void showTalent() { cout << (status ? "  can " : "  can`t ") << ability << endl; }
};

// Каждая способность, наследуемая от абстрактного класса Talent,
// должна быть представлена в виде отдельного класса.
class TalentSwim : public Talent {
public:
    explicit TalentSwim(bool inAbility) : Talent(inAbility) { ability = "swim"; }
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

    virtual void setTalent(Talent*talent) = 0;

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

    void setTalent(Talent*talent) override { talents.emplace_back(talent); }

    void changeTalent(int index) {
        if (index >= 0 && index < talents.size()) {
            talents[index]->changeFlag();
        }
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

    dog.changeTalent(1);

    dog.showTalents();

    return 0;
}
