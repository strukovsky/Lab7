//
// Created by strukovsky on 14.12.2020.
//

#ifndef LAB7_NEW_PREPODCOMPARER_H
#define LAB7_NEW_PREPODCOMPARER_H

#include "Prepod.h"

class PrepodComparer
    {
    public:
        inline bool operator()(const Prepod& first, const Prepod& second)
        {
            return first.get_subject() < second.get_subject();
        }
    };
#endif //LAB7_NEW_PREPODCOMPARER_H
