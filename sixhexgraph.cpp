#include "sixhexgraph.h"
#include "sixhex.h"
#include "QPolygon"
#include "QPoint"
#include "QPainter"


SixHexGraph::SixHexGraph(int TotalRow, int TotalColumn, int SideLength, int InitialX, int InitialY)
{
    SixHex* Head = new SixHex(0,0,SideLength,InitialX,InitialY);
    this->Head = Head;

    setTotalRow(TotalRow);
    setTotalColumn(TotalColumn);
}

void SixHexGraph::initSixHexGraph()
{
    int TotalRow = this->getTotalRow();
    int TotalColumn = this->getTotalColumn();
    int InitialX = this->getHead()->getInitialX();
    int InitialY = this->getHead()->getInitialY();
    int SideLength = this->getHead()->getSideLength();

    SixHex* Temp_1 = new SixHex(1,1,SideLength,InitialX,InitialY);
    this->getHead()->DownRight = Temp_1;
    Temp_1->UpLeft = this->getHead();

    SixHex* Temp_2 = Temp_1;
    SixHex* Temp_3;

    for(int x=1;x<TotalColumn;x++)
    {
        Temp_2->Right = new SixHex(1, x+1, SideLength, InitialX, InitialY);
        Temp_2->DownRight =

    }


}

SixHex SixHexGraph::findSixHex(int LocalX, int LocalY, int InitialX, int InitialY)
{
    int SideLength = this->getHead()->getSideLength();
    int x  = LocalX - InitialX;
    int y  = LocalY - InitialY;
    int a_ = y/(3*SideLength);
    int a  = y%(3*SideLength);
    int b  = x%(1.732*SideLength);
    int b_1 = x/(1.732*SideLength);
    int b_2 = (x-SideLength*1.732/2)/(SideLength*1.732);
    int Row, Column;
    bool isSide = false;

    if(a>=0&&a<(SideLength/2))
    {
        if(b>=0&&b<(SideLength*1.732/2))
        {
            int c = SideLength*3 - 6*y - 1.732*2*x;
            if(c>0)
            {
                Row = a_;
            }
            else if(c==0)
            {
                isSide = true;
            }
            else if(c<0)
            {
                Row = a_+1;
            }
        }
        else if (b>=(SideLength*1.732/2)&&b<(SideLength*1.732))
        {
            int c = 6*y - 3*SideLength - 1.732*2*x;
            if(c>0)
            {
                Row = a_;
            }
            else if(c==0)
            {
                isSide = true;
            }
            else if(c<0)
            {
                Row = a_+1;
            }
        }
    }
    else if (a>=(SideLength/2)&&a<(SideLength*3/2))
    {
        if (x==0)
        {
            isSide = true;
        }
        else
        {
            Row = a_+1;
        }
    }
    else if (a>=(SideLength*3/2)&&a<(SideLength*2))
    {
        if(b>=0&&b<(SideLength*1.732/2))
        {
            int c = 3*y - 1.732*x;
            if(c>0)
            {
                Row = a_+2;
            }
            else if(c==0)
            {
                isSide = true;
            }
            else if(c<0)
            {
                Row = a_+1;
            }
        }
        else if (b>=(SideLength*1.732/2)&&b<(SideLength*1.732))
        {
            int c = 3*y - 3*SideLength + 1.732*x;
            if(c>0)
            {
                Row = a_+2;
            }
            else if(c==0)
            {
                isSide = true;
            }
            else if(c<0)
            {
                Row = a_+1;
            }
        }
    }
    else if (a>=(SideLength*2)&&a<(SideLength*3))
    {
        if(x==SideLength*1.732/2)
        {
            isSide = true;
        }
        else
        {
            Row = a_+2;
        }
    }

    if(Raw==a_+1)
    {
        Column = b_1+1;
    }
    else if(Raw==a_||Raw==a_+2)
    {
        Column = b_2+1;
    }

    if(isSide==true)
    {
        return nullptr;
    }
    else
    {
        return getSixHex(Row, Column);
    }
}

SixHex SixHexGraph::getSixHex(int Row, int Column)
{
    SixHex* TempHex;
    TempHex = this->getHead()->DownRight;

    for(int x=0;x<(Row-1)/2;x++)
    {
        TempHex = TempHex->DownRight->DownLeft;
    }
    if(Row%2==0)
    {
        TempHex = TempHex->DownRight;
    }
    for(int x=0;x<(Column-1);x++)
    {
        TempHex = TempHex->Right;
    }
    return TempHex;
}

void SixHexGraph::paintSixHex(SixHex Hex)
{
    QPolygon pts;
    QPainter painter;
    QPoint Point_1;
    QPoint Point_2;
    QPoint Point_3;
    QPoint Point_4;
    QPoint Point_5;
    QPoint Point_6;

    Point_1.setX(Hex.getLocalX() - 1.732*Hex.getSideLength()/2);
    Point_1.setY(Hex.getLocalY() - Hex.getSideLength()/2);
    Point_2.setX(Hex.getLocalX());
    Point_2.setY(Hex.getLocalY() - Hex.getSideLength());
    Point_3.setX(Hex.getLocalX() + 1.732*Hex.getSideLength()/2);
    Point_3.setY(Point_1.y());
    Point_4.setX(Point_3.x());
    Point_4.setY(Hex.getLocalY() + Hex.getSideLength()/2);
    Point_5.setX(Point_2.x());
    Point_5.setY(Hex.getLocalY() + Hex.getSideLength());
    Point_6.setX(Point_1.x());
    Point_6.setY(Point_4.y());

    pts.setPoints(6, Point_1.x(), Point_1.y(),
                     Point_2.x(), Point_2.y(),
                     Point_3.x(), Point_3.y(),
                     Point_4.x(), Point_4.y(),
                     Point_5.x(), Point_5.y(),
                     Point_6.x(), Point_6.y());

    painter.drawConvexPolygon(pts);

}

int SixHexGraph::getTotalRow() const
{
    return TotalRow;
}

void SixHexGraph::setTotalRow(int value)
{
    TotalRow = value;
}

int SixHexGraph::getTotalColumn() const
{
    return TotalColumn;
}

void SixHexGraph::setTotalColumn(int value)
{
    TotalColumn = value;
}

SixHex *SixHexGraph::getHead() const
{
    return Head;
}

