#ifndef SIXHEXGRAPH_H
#define SIXHEXGRAPH_H
#include "sixhex.h"
#define MAX_SIDE_NUMBER 1000
enum terrain
{
    EmptyTerrain=0,
    Clear,
    Woods
};

enum border
{
    EmptyBorder=0,
    Stream,
    River
};

class SixHexGraph
{
public:
    terrain TerrainTable[MAX_SIDE_NUMBER][MAX_SIDE_NUMBER];
    border BorderTable[MAX_SIDE_NUMBER][MAX_SIDE_NUMBER][6];



    SixHexGraph(int TotalRow, int TotalColumn, int SideLength, int InitialX, int InitialY);
    void initSixHexGraph();
    SixHex findSixHex(int LocalX, int LocalY, int InitialX, int InitialY);
    SixHex getSixHex(int Row, int Column);

    void paintSixHex(SixHex Hex);

    int getTotalRow() const;
    void setTotalRow(int value);

    int getTotalColumn() const;
    void setTotalColumn(int value);

    SixHex *getHead() const;

private:
    int TotalRow;
    int TotalColumn;
    SixHex *Head;

};

#endif // SIXHEXGRAPH_H
