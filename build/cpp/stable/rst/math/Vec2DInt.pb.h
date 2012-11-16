/* This file is generated - do not edit. */

#pragma once

#include <string.h> // for memcpy()

#include <string>
#include <vector>

#include <boost/cstdint.hpp>

#include <rosetta/api.h>


namespace rst {
namespace math {

class Vec2DInt{
public:
  // Accessors
  /**
   * Field number of the "x" field.
   */
  static const int kxFieldNumber = 0;
  
  /**
   * Return true if the "x" field is present.
   */
  inline bool has_x() const;
  
  /**
   * Return value of "x" field.
   */
  inline const boost::uint32_t&x() const;
  
  inline void set_x(const boost::uint32_t&newValue);
  
  
  /**
   * Field number of the "y" field.
   */
  static const int kyFieldNumber = 0;
  
  /**
   * Return true if the "y" field is present.
   */
  inline bool has_y() const;
  
  /**
   * Return value of "y" field.
   */
  inline const boost::uint32_t&y() const;
  
  inline void set_y(const boost::uint32_t&newValue);
  
  
  // Type-independent protocol buffer API
  
  /**
   * Return the default instance of this class.
   * 
   * @return A reference to the default instance.
  
   */
  static const Vec2DInt& default_instance();
  
  /**
   * Return the fully qualified name of this class.
   */
  static const std::string GetTypeName();
  
  /**
   * Return a new instance of this class.
   */
  Vec2DInt* New();
  
  /**
   * Return the number of octets required to store the serialized
   * representation of this object.
  
   */
  int ByteSize() const;
  
  bool SerializeToString(std::string* destination) const;
  
  bool ParseFromString(const std::string& source);
  
  bool SerializeToArray(void* destination,int size) const;
  
  bool ParseFromArray(const void* source,int size);
  
  boost::uint32_t _x;
  boost::uint32_t _y;
  
};
}
}

// Inlined Stuff

// Accessors for rst::math::Vec2DInt

 bool rst::math::Vec2DInt::has_x() const{
  return true;
}

 const boost::uint32_t&rst::math::Vec2DInt::x() const{
  return this->_x;
}

 void rst::math::Vec2DInt::set_x(const boost::uint32_t&newValue){
  this->_x=newValue;
}



 bool rst::math::Vec2DInt::has_y() const{
  return true;
}

 const boost::uint32_t&rst::math::Vec2DInt::y() const{
  return this->_y;
}

 void rst::math::Vec2DInt::set_y(const boost::uint32_t&newValue){
  this->_y=newValue;
}




