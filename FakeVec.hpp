#ifndef VEC_HPP
# define VEC_HPP

class FakeVec {

    private:
        int   _x;
        int   _y;

    public:
        FakeVec(void);
        FakeVec(int x, int y);
        FakeVec(FakeVec const & src);
        ~FakeVec(void);

        int     getX(void) const;
        int     getY(void) const;

        void    setX(int);
        void    setY(int);

        FakeVec & operator=(FakeVec const & src);
        FakeVec   operator+(FakeVec const & rhs) const;
        FakeVec   operator-(FakeVec const & rhs) const;

        bool  operator==(FakeVec const & rhs) const;
        bool  operator!=(FakeVec const & rhs) const;
};

#endif
