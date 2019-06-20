#ifndef UNCOPYABLE_H
#define UNCOPYABLE_H
class uncopyable
{
protected:
    uncopyable() = default;
    ~uncopyable() = default;
private:
    uncopyable(const uncopyable&) = delete;
    uncopyable& operator()(const uncopyable&) = delete;
};

#endif