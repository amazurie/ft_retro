#ifndef VEC_HPP
# define VEC_HPP

class FakeVec {

    private:
        float   _x;
        float   _y;

    public:
        FakeVec(void);
        FakeVec(float x, float y);
        FakeVec(FakeVec const & src);
        ~FakeVec(void);

        float     getX(void) const;
        float     getY(void) const;

        void    setX(float);
        void    setY(float);

        FakeVec & operator=(FakeVec const & src);
        FakeVec   operator+(FakeVec const & rhs) const;
        FakeVec   operator-(FakeVec const & rhs) const;

        bool  operator==(FakeVec const & rhs) const;
        bool  operator!=(FakeVec const & rhs) const;
};

#endif
