#include "stdafx.h"
#include "Move.h"

Move::Move()
{

}

Move::Move(int iColumnNumber)
{
    LOG(__FUNCTION__ " IN\n");
    m_iColumnNumber = iColumnNumber;
    LOG(__FUNCTION__ " OUT\n");
}


Move::~Move()
{
    LOG(__FUNCTION__ " IN\n");
    LOG(__FUNCTION__ " OUT\n");
}

void Move::SetValues(int iColumnNumber)
{
    LOG(__FUNCTION__ " IN\n");
    m_iColumnNumber = iColumnNumber;
    LOG(__FUNCTION__ " OUT\n");
}

int Move::GetColumnNumber()
{
    return m_iColumnNumber;
}
