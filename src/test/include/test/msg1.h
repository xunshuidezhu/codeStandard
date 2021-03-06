// Generated by gencpp from file test/msg1.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_MSG1_H
#define TEST_MESSAGE_MSG1_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test
{
template <class ContainerAllocator>
struct msg1_
{
  typedef msg1_<ContainerAllocator> Type;

  msg1_()
    : score(0)
    , name()
    , age(0)  {
    }
  msg1_(const ContainerAllocator& _alloc)
    : score(0)
    , name(_alloc)
    , age(0)  {
  (void)_alloc;
    }



   typedef int8_t _score_type;
  _score_type score;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef int16_t _age_type;
  _age_type age;





  typedef boost::shared_ptr< ::test::msg1_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test::msg1_<ContainerAllocator> const> ConstPtr;

}; // struct msg1_

typedef ::test::msg1_<std::allocator<void> > msg1;

typedef boost::shared_ptr< ::test::msg1 > msg1Ptr;
typedef boost::shared_ptr< ::test::msg1 const> msg1ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test::msg1_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test::msg1_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace test

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'test': ['/home/xunshuidezhu/UMShip/src/test/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::test::msg1_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test::msg1_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::msg1_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::msg1_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::msg1_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::msg1_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test::msg1_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3699c1be22d0c29e582e433abf0bb894";
  }

  static const char* value(const ::test::msg1_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3699c1be22d0c29eULL;
  static const uint64_t static_value2 = 0x582e433abf0bb894ULL;
};

template<class ContainerAllocator>
struct DataType< ::test::msg1_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test/msg1";
  }

  static const char* value(const ::test::msg1_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test::msg1_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int8     score\n\
string	 name\n\
int16    age\n\
";
  }

  static const char* value(const ::test::msg1_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test::msg1_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.score);
      stream.next(m.name);
      stream.next(m.age);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct msg1_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test::msg1_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test::msg1_<ContainerAllocator>& v)
  {
    s << indent << "score: ";
    Printer<int8_t>::stream(s, indent + "  ", v.score);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "age: ";
    Printer<int16_t>::stream(s, indent + "  ", v.age);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_MESSAGE_MSG1_H
