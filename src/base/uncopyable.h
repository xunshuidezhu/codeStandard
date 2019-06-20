/******************************************************************
 * @author XuHuanyu
 * @brief uncopyable interface,for the class which cannot copy
 * @data 2019/6/20
 * *****************************************************************/


#ifndef UNCOPYABLE_H
#define UNCOPYABLE_H
class uncopyable
{
protected:
    uncopyable() = default;
    ~uncopyable() = default;
private:
    uncopyable(const uncopyable&) = delete;
    uncopyable& operator=(const uncopyable&) = delete;
};

#endif