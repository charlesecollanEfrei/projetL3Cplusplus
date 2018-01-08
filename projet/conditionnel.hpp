// Projet C++
// Ecollan Charles
// Ha David
//
// L'3 RPOMO 2019
// Groupe A
//
// conditionnel.hpp


#ifndef conditionnel_hpp
#define conditionnel_hpp

#include <stdio.h>
#include "binaire.hpp"
class Conditionnel : public Expression {
public:
    Conditionnel(Binaire * cond, Expression * e1, Expression * e2);
    double eval() const;
private:
    Binaire * _cond;
    Expression * _e1;
    Expression * _e2;
};
#endif /* conditionnel_hpp */
