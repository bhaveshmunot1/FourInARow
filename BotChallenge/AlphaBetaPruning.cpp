
#include "stdafx.h"
#include "AlphaBetaPruning.h"

int AlphaBetaPruning::m_iAlpha;
int AlphaBetaPruning::m_iBeta;

AlphaBetaPruning::AlphaBetaPruning()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}


AlphaBetaPruning::~AlphaBetaPruning()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}

void AlphaBetaPruning::SetValues(int iAlpha, int iBeta)
{
    m_iAlpha = iAlpha;
    m_iBeta = iBeta;
}

int AlphaBetaPruning::FillValidMoves(Move m[], Board &BBoard)
{
    int iNumberOfEntries = 0;
    int iColumns = BBoard.GetNumberOfColumns();
    Move MTemp;
    for (int i = 0; i < iColumns; i++)
    {
        MTemp.SetValues(i);
        if (BBoard.IsValid(MTemp))
        {
            m[iNumberOfEntries] = MTemp;
            iNumberOfEntries++;
        }
    }
    return iNumberOfEntries;
}

MoveValuePair AlphaBetaPruning::AlphaBetaSearch(Board &BBoard, int Depth, ePlayer eCurrentPlayer)
{
    vector<MoveValuePair> vMVP;
    //initialize maxi variable to -inf
    int iMaxValue = -INF - 1;
    //find valid columns
    Move m[8];
    int iNumberOfValidMoves = FillValidMoves(m, BBoard);
    //for each valid column
    for (int i = 0; i < iNumberOfValidMoves; i++)
    {
        Move &x = m[i];
        //  > reflect that move
        BBoard.ReflectMove(x, eCurrentPlayer);
        //  > call abmin
        int iTempValue = AlphaBetaMin(BBoard, Depth - 1, eCurrentPlayer);
        //  > save the move and return value
        if (iMaxValue < iTempValue)
        {
            MoveValuePair MVPTemp;
            MVPTemp.SetMove(x);
            MVPTemp.SetValue(iTempValue);
            vMVP.push_back(MVPTemp);
        }        
        //  > remove that move
        BBoard.RemoveMove(x);
    }
    //find largest value and corresponding move
    iMaxValue = -INF - 1;
    MoveValuePair MRetMoveValuePair;
    for each (MoveValuePair x in vMVP)
    {
        if (iMaxValue < x.GetValue())
        {
            MRetMoveValuePair = x;
        }
    }
    return MRetMoveValuePair;
}

int AlphaBetaPruning::AlphaBetaMin(Board &BBoard, int Depth, ePlayer eCurrentPlayer)
{
    Move m[8];
    int iNumberOfValidMoves = FillValidMoves(m, BBoard);
    int iRetValue;
    if (Depth == 0 || iNumberOfValidMoves == 0)
    {
        iRetValue = BBoard.Evaluate(eCurrentPlayer);
        goto ret;
    }

    int iMinValue = INF;
    for (int i = 0; i < iNumberOfValidMoves; i++)
    {
        Move &x = m[i];
        BBoard.ReflectMove(x, Opponent(eCurrentPlayer));
        iMinValue = min(iMinValue, AlphaBetaMax(BBoard, Depth-1, eCurrentPlayer));
        BBoard.RemoveMove(x);
        if (iMinValue <= m_iAlpha)
        {
            iRetValue = m_iAlpha;
            goto ret;
        }
        m_iBeta = min(m_iBeta, iMinValue);
    }
    iRetValue = iMinValue;
ret:
    return iRetValue;
}

int AlphaBetaPruning::AlphaBetaMax(Board &BBoard, int Depth, ePlayer eCurrentPlayer)
{
    Move m[8];
    int iNumberOfValidMoves = FillValidMoves(m, BBoard);
    int iRetValue;
    if (Depth == 0 || iNumberOfValidMoves == 0)
    {
        iRetValue = BBoard.Evaluate(eCurrentPlayer);
        goto ret;
    }

    int iMaxValue = -INF;
    for (int i = 0; i < iNumberOfValidMoves; i++)
    {
        Move &x = m[i];
        BBoard.ReflectMove(x, eCurrentPlayer);
        iMaxValue = max(iMaxValue, AlphaBetaMin(BBoard, Depth - 1, eCurrentPlayer));
        BBoard.RemoveMove(x);
        if (iMaxValue >= m_iBeta)
        {
            iRetValue = m_iAlpha;
            goto ret;
        }
        m_iAlpha = max(m_iAlpha, iMaxValue);
    }
    iRetValue = iMaxValue;
ret:
    return iRetValue;
}