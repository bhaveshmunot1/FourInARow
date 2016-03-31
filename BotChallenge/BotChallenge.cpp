// BotChallenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CommonData.h"
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
    LOG(__FUNCTION__ " IN\n");
    Game G;
    G.Toss();
    G.Play();
    G.End();
    LOG(__FUNCTION__ " OUT\n");
    return 0;
}

