#pragma once

#include "safetyproblem.hpp"

class SafetyModel {

    SafetyProblem m_sp;
    unsigned m_k;

public:

    SafetyModel(SafetyProblem, unsigned);
    SafetyProblem getSafetyProblem();
    unsigned k();

};