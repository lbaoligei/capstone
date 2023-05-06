// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/EncoderData.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__EncoderData __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__EncoderData __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EncoderData_
{
  using Type = EncoderData_<ContainerAllocator>;

  explicit EncoderData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ticks = 0l;
      this->distance = 0.0f;
      this->velocity_estimate = 0.0f;
    }
  }

  explicit EncoderData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ticks = 0l;
      this->distance = 0.0f;
      this->velocity_estimate = 0.0f;
    }
  }

  // field types and members
  using _ticks_type =
    int32_t;
  _ticks_type ticks;
  using _distance_type =
    float;
  _distance_type distance;
  using _velocity_estimate_type =
    float;
  _velocity_estimate_type velocity_estimate;

  // setters for named parameter idiom
  Type & set__ticks(
    const int32_t & _arg)
  {
    this->ticks = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__velocity_estimate(
    const float & _arg)
  {
    this->velocity_estimate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::EncoderData_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::EncoderData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::EncoderData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::EncoderData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__EncoderData
    std::shared_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__EncoderData
    std::shared_ptr<robot_interfaces::msg::EncoderData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EncoderData_ & other) const
  {
    if (this->ticks != other.ticks) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->velocity_estimate != other.velocity_estimate) {
      return false;
    }
    return true;
  }
  bool operator!=(const EncoderData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EncoderData_

// alias to use template instance with default allocator
using EncoderData =
  robot_interfaces::msg::EncoderData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__STRUCT_HPP_
