#include "stdafx.h"
#include "CommonData.h"

int max(int a, int b)
{
    return ((a < b) ? b : a);
}

int min(int a, int b)
{
    return ((a < b) ? a : b);
}

ePlayer Opponent(ePlayer eCurrentPlayer)
{
    return ePlayer(3 - eCurrentPlayer);
}