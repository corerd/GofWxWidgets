/**
 * Game of Life engine
 * See: https://github.com/knotman90/SinervisCourses/tree/master/ST_CPP_Nov22/Lezione3/Gof
*/
#ifndef __GOF_ENGINE__
#define __GOF_ENGINE__


#include <cstddef>
#include <vector>
#include <cstdlib>

using Matrix = std::vector<std::vector<bool>>;

class GofEngine
{
    public:
        GofEngine(std::size_t aSize);
        void initialize();
        int getSize() const;
        bool getCell(const int i, const int j) const;
        void clear();
        void step();


    private:
        bool calcNextVal(const int row, const int col);

        int mSize;
        Matrix curr;
        Matrix next;
};


#endif /* __GOF_ENGINE__ */
