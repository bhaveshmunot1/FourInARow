#pragma once
#include "CommonData.h"
#include "Board.h"
#include "Move.h"
#include "AlphaBetaPruning.h"
#include "Time.h"

class IterativeDeepening
{
    static int m_iLimit;
    static int m_iTimeLimit;
    static int m_iDepthLimit;
public:
    IterativeDeepening();
    ~IterativeDeepening();
    static void SetValues(int, int, int);
    static Move Search(Board &, ePlayer);
};

