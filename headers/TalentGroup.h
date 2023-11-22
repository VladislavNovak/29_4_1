#ifndef INC_29_4_1_TALENTGROUP_H
#define INC_29_4_1_TALENTGROUP_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

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

#endif //INC_29_4_1_TALENTGROUP_H
