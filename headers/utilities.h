#ifndef INC_29_4_1_UTILITIES_H
#define INC_29_4_1_UTILITIES_H

#include <vector>
#include <algorithm>

template<typename T>
int findKeyIndexInVector(const T &key, const std::vector<T> &list) {
    const int NOT_FOUND = -1;
    auto it = std::find_if(list.cbegin(), list.cend(), [key](const T &i){ return i == key; });

    if (it != list.cend()) {
        return (int)std::distance(list.cbegin(), it);
    }

    return NOT_FOUND;
}

#endif //INC_29_4_1_UTILITIES_H
