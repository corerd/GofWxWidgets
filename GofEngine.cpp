/**
 * Game of Life engine
 * See: https://github.com/knotman90/SinervisCourses/tree/master/ST_CPP_Nov22/Lezione3/Gof
*/
#include "GofEngine.h"

GofEngine::GofEngine(std::size_t aSize) :
    mSize(aSize),
    curr(mSize, std::vector<bool>(mSize, false)),
    next(mSize, std::vector<bool>(mSize, false))
{
    initialize();
}

void GofEngine::initialize()
{
    /**/
    for(int i = 0 ; i < mSize;i++){
        for(int j = 0 ; j < mSize ; j++){
            curr[i][j] = (rand()%2)==0;
        }
    }
    /**/
    int ci = mSize/2;
    int cj = mSize/2;
    curr[ci][cj] = true;
    curr[ci-1][cj-1] = true;
    curr[ci-1][cj+1] = true;
    curr[ci][cj+1] = true;
    curr[ci+1][cj] = true;
}

int GofEngine::getSize() const
{
    return mSize;
}

bool GofEngine::getCell(const int i, const int j) const
{
    return curr[i][j];
}

void GofEngine::clear()
{
}

void GofEngine::step()
{
    for(int i = 0 ; i < mSize ; i++){
        for(int j  = 0 ; j < mSize ;j++){
            next[i][j] = calcNextVal(i,j);
        }
    }
    swap(curr, next);
}

bool GofEngine::calcNextVal(const int row, const int col)
{
    /*
    Any live cell with two or three live neighbors survives.
    Any dead cell with three live neighbors becomes a live cell.
    All other live cells die in the next generation. Similarly, all other dead cells stay dead.
    */
    // input: cella in posizione i,j
    //        vicini della cella i,j

    bool currval = curr[row][col];
    int countVive = 0, countMorte = 0;
    for(int i = -1 ; i <=1 ; i++){
        for(int j = -1 ; j <=1 ;j++ ){
            if(i==0 && j==0)
            {
                continue;
            }
            int rowVicino =  row+i;
            rowVicino = ((rowVicino+mSize)%mSize);
                
            int colVicino =  col+j;
            colVicino = ((colVicino+mSize)%mSize);

            const bool vicino = curr[rowVicino][colVicino];


            countVive += vicino;
            countMorte += !vicino;
        }
    }

    if((currval && (countVive==2 || countVive==3)) || (!currval && countVive==3))
    {
        return true;
    }
    return false;
}
