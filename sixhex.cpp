#include "sixhex.h"

SixHex::SixHex(int Row, int Column, int SideLength, int InitialX, int InitialY)
{
    this->Row = Row;
    this->Column = Column;
    this->SideLength = SideLength;
    this->InitialX = InitialX;
    this->InitialY = InitialY;
    if(Row%2!=0)
    {
        this->LocalX = (Column*2-1)*1.732*SideLength/2 + InitialX;
    }
    else
    {
        this->LocalX = Column*1.732*SideLength + InitialX;
    }
    this->LocalY = (Row*3-1)*SideLength/2 + InitialY;
}

int SixHex::getSideLength() const
{
    return SideLength;
}

int SixHex::getRow() const
{
    return Row;
}

int SixHex::getColumn() const
{
    return Column;
}

int SixHex::getLocalX() const
{
    return LocalX;
}

int SixHex::getLocalY() const
{
    return LocalY;
}

int SixHex::getInitialX() const
{
    return InitialX;
}

int SixHex::getInitialY() const
{
    return InitialY;
}
