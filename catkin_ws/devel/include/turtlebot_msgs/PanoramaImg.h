// Generated by gencpp from file turtlebot_msgs/PanoramaImg.msg
// DO NOT EDIT!


#ifndef TURTLEBOT_MSGS_MESSAGE_PANORAMAIMG_H
#define TURTLEBOT_MSGS_MESSAGE_PANORAMAIMG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <sensor_msgs/Image.h>

namespace turtlebot_msgs
{
template <class ContainerAllocator>
struct PanoramaImg_
{
  typedef PanoramaImg_<ContainerAllocator> Type;

  PanoramaImg_()
    : header()
    , pano_id()
    , latitude(0.0)
    , longitude(0.0)
    , heading(0.0)
    , geo_tag()
    , image()  {
    }
  PanoramaImg_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , pano_id(_alloc)
    , latitude(0.0)
    , longitude(0.0)
    , heading(0.0)
    , geo_tag(_alloc)
    , image(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _pano_id_type;
  _pano_id_type pano_id;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef double _heading_type;
  _heading_type heading;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _geo_tag_type;
  _geo_tag_type geo_tag;

   typedef  ::sensor_msgs::Image_<ContainerAllocator>  _image_type;
  _image_type image;





  typedef boost::shared_ptr< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> const> ConstPtr;

}; // struct PanoramaImg_

typedef ::turtlebot_msgs::PanoramaImg_<std::allocator<void> > PanoramaImg;

typedef boost::shared_ptr< ::turtlebot_msgs::PanoramaImg > PanoramaImgPtr;
typedef boost::shared_ptr< ::turtlebot_msgs::PanoramaImg const> PanoramaImgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace turtlebot_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'turtlebot_msgs': ['/home/user/catkin_ws/src/turtlebot_msgs/msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "aedf66295b374a7249a786af27aecc87";
  }

  static const char* value(const ::turtlebot_msgs::PanoramaImg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaedf66295b374a72ULL;
  static const uint64_t static_value2 = 0x49a786af27aecc87ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "turtlebot_msgs/PanoramaImg";
  }

  static const char* value(const ::turtlebot_msgs::PanoramaImg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#Pano message\n\
Header header\n\
string pano_id\n\
float64 latitude\n\
float64 longitude\n\
float64 heading #in degrees, compass heading\n\
string geo_tag\n\
sensor_msgs/Image image\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of camera\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
";
  }

  static const char* value(const ::turtlebot_msgs::PanoramaImg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pano_id);
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.heading);
      stream.next(m.geo_tag);
      stream.next(m.image);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PanoramaImg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_msgs::PanoramaImg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::turtlebot_msgs::PanoramaImg_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "pano_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.pano_id);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "heading: ";
    Printer<double>::stream(s, indent + "  ", v.heading);
    s << indent << "geo_tag: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.geo_tag);
    s << indent << "image: ";
    s << std::endl;
    Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "  ", v.image);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_MSGS_MESSAGE_PANORAMAIMG_H
