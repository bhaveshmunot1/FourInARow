#include "stdafx.h"
#include "Game.h"


Game::Game()
{
    LOG(__FUNCTION__ " IN\n");
    m_pPPlayer = NULL;
    m_iTotalMovesPlayed = 0;
    m_CComp.SetTimeLimit(3);
    m_CComp.SetDepthLimit(41);
    LOG(__FUNCTION__ " OUT\n");
}


Game::~Game()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}

void Game::Toss()
{
    LOG(__FUNCTION__ " IN\n");
    int toss;
    DISPLAY("Do you want a toss, or your choice only?\t");
    INPUT("%d", &toss);
    if (toss)
    {
        m_eFirstPlayer = PLAYER1;
    }
    else
    {
        ePlayer choice;
        INPUT("%d", &choice);
        m_eFirstPlayer = choice;
    }
    LOG(__FUNCTION__ " OUT\n");
}

void Game::Play()
{
    LOG(__FUNCTION__ " IN\n");
    m_eCurrentPlayer = m_eFirstPlayer;
    if (m_eCurrentPlayer == PLAYER1)
    {
        m_pPPlayer = &m_HHuman;
    }
    else
    {
        m_pPPlayer = &m_CComp;
    }

    while (!IsOver())
    {
        m_BBoard.Draw();
        m_pPPlayer->PlayMove(m_BBoard, m_eCurrentPlayer);
        Toggle();
    }

    LOG(__FUNCTION__ " OUT\n");
}

void Game::Pause()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}

bool Game::IsOver()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
    return m_BBoard.IsFull() || m_BBoard.WinningState();
}

void Game::DeclareWinner()
{
    LOG(__FUNCTION__ " IN\n");
    DISPLAY(" The Winner is Player%d!", m_BBoard.GetWinner());
    LOG(__FUNCTION__ " OUT\n");
}

void Game::End()
{
    LOG(__FUNCTION__ " IN\n");
    if (IsOver())
    {
        DeclareWinner();
    }
    else
    {
        //TODO
    }
    LOG(__FUNCTION__ " OUT\n");
}

void Game::Toggle()
{
    LOG(__FUNCTION__" IN\n");
    if (m_pPPlayer == &m_HHuman)
    {
        m_pPPlayer = &m_CComp;
        m_eCurrentPlayer = PLAYER2;
    }
    else
    {
        m_pPPlayer = &m_HHuman;
        m_eCurrentPlayer = PLAYER1;
    }
    LOG(__FUNCTION__" OUT\n");
}