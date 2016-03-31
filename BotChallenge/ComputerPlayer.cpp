#include "stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}

ComputerPlayer::ComputerPlayer(int iTimeLimit, int iDepthLimit)
{
    LOG(__FUNCTION__ " IN\n");
    m_iTimeLimitInSeconds = iTimeLimit;
    m_iDepthLimit = iDepthLimit;
    LOG(__FUNCTION__ " OUT\n");
}

ComputerPlayer::~ComputerPlayer()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}

void ComputerPlayer::SetTimeLimit(int iTimeLimit)
{
    m_iTimeLimitInSeconds = iTimeLimit;
}

int ComputerPlayer::GetTimeLimit()
{
    return m_iTimeLimitInSeconds;
}

void ComputerPlayer::SetDepthLimit(int iDepthLimit)
{
    m_iDepthLimit = iDepthLimit;
}

int ComputerPlayer::GetDepthLimit()
{
    return m_iDepthLimit;
}

void ComputerPlayer::PlayMove(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG(__FUNCTION__ " IN\n");
    BBoard.ReflectMove(Think(BBoard, eCurrentPlayer), eCurrentPlayer);
    LOG(__FUNCTION__ " OUT\n");
}

Move ComputerPlayer::Think(Board &BBoard, ePlayer eCurrentPlayer)
{
    LOG(__FUNCTION__ " IN\n");
    // TODO : Understand the LIMIT and provide appropriate value
    IterativeDeepening::SetValues(LIMIT, (GetTimeLimit()*1000 - 200), GetDepthLimit()); // Convert to milliseconds and then provide some buffer
    Move m = IterativeDeepening::Search(BBoard, eCurrentPlayer);
    /*
    int iColumns = BBoard.GetNumberOfColumns();
    for (int j = 0; j < iColumns; j++)
    {
        if (BBoard.GetPositionValue(0, j) == NONE)
        {
            m.SetValues(j);
            break;
        }
    }
    */
    LOG(__FUNCTION__ " OUT\n");
    return m;
}