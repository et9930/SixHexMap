#ifndef SIXHEX_H
#define SIXHEX_H


class SixHex
{
public:
    SixHex *Left;
    SixHex *Right;
    SixHex *UpLeft;
    SixHex *UpRight;
    SixHex *DownLeft;
    SixHex *DownRight;


    SixHex(int Row, int Column, int SideLength, int InitialX, int InitialY);
    int getSideLength() const;
    int getRow() const;
    int getColumn() const;
    int getLocalX() const;
    int getLocalY() const;
    int getInitialX() const;
    int getInitialY() const;

private:
    int SideLength;
    int Row;
    int Column;
    int LocalX;
    int LocalY;
    int InitialX;
    int InitialY;



};

#endif // SIXHEX_H
