#include <iostream>
#include <vector>
#include "headers/TalentGroup.h"
#include "headers/AnimalGroup.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

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
