#ifndef STACK_H
#define STACK_H

#include <memory>

template<class T, class A = std::allocator<T>> class cstack
{
    struct rec
    {
        T val;
        rec* next;
        rec* prev;

        rec(T _elem, rec* _prev, rec* _next = 0) { val = _elem; prev = _prev; next = _next; }
    };

    size_t mysize;
    rec* head;
    rec* last;

public:
    cstack() { head = 0; last = 0; mysize = 0; }
    cstack(T _elem) { head = new rec(_elem, 0); last = head; mysize = 1; }

    void push(T _elem);
    T pop() { T elem = last->val; last = last->prev; delete last->next; last->next = 0; --mysize; return elem; }
    size_t size() { return mysize; }
};

template<class T, class A>
void cstack<T, A>::push(T _elem)
{
    rec* ne = new rec(_elem, last);
    if (mysize == 0)
    {
        head = ne;
        last = ne;
    }
    else
    {
        last->next = ne;
        last = ne;
    }
    ++mysize;
}

#endif // STACK_H
