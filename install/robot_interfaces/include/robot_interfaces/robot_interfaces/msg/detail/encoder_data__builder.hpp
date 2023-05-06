// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/EncoderData.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/encoder_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_EncoderData_velocity_estimate
{
public:
  explicit Init_EncoderData_velocity_estimate(::robot_interfaces::msg::EncoderData & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::EncoderData velocity_estimate(::robot_interfaces::msg::EncoderData::_velocity_estimate_type arg)
  {
    msg_.velocity_estimate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::EncoderData msg_;
};

class Init_EncoderData_distance
{
public:
  explicit Init_EncoderData_distance(::robot_interfaces::msg::EncoderData & msg)
  : msg_(msg)
  {}
  Init_EncoderData_velocity_estimate distance(::robot_interfaces::msg::EncoderData::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_EncoderData_velocity_estimate(msg_);
  }

private:
  ::robot_interfaces::msg::EncoderData msg_;
};

class Init_EncoderData_ticks
{
public:
  Init_EncoderData_ticks()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EncoderData_distance ticks(::robot_interfaces::msg::EncoderData::_ticks_type arg)
  {
    msg_.ticks = std::move(arg);
    return Init_EncoderData_distance(msg_);
  }

private:
  ::robot_interfaces::msg::EncoderData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::EncoderData>()
{
  return robot_interfaces::msg::builder::Init_EncoderData_ticks();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__BUILDER_HPP_
