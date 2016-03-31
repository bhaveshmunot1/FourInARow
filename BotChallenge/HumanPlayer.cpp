#include "stdafx.h"
#include "HumanPlayer.h"


HumanPlayer::HumanPlayer()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}


HumanPlayer::~HumanPlayer()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}

void HumanPlayer::PlayMove(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG(__FUNCTION__ " IN\n");
    BBoard.ReflectMove(Think(BBoard, eCurrentPlayer), eCurrentPlayer);
    LOG(__FUNCTION__ " OUT\n");
}

Move HumanPlayer::Think(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG(__FUNCTION__ " IN\n");    
    Move m;
    int iColumnNumber;
    DISPLAY("Your move?\t");
    INPUT("%d", &iColumnNumber);
    m.SetValues(iColumnNumber);
    LOG(__FUNCTION__ " OUT\n");
    return m;
}
