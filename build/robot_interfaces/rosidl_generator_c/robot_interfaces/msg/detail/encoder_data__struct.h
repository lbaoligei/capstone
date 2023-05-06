// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:msg/EncoderData.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__STRUCT_H_
#define ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/EncoderData in the package robot_interfaces.
/**
  * File: robot_interfaces/msg/EncoderData.msg
 */
typedef struct robot_interfaces__msg__EncoderData
{
  int32_t ticks;
  float distance;
  float velocity_estimate;
} robot_interfaces__msg__EncoderData;

// Struct for a sequence of robot_interfaces__msg__EncoderData.
typedef struct robot_interfaces__msg__EncoderData__Sequence
{
  robot_interfaces__msg__EncoderData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__msg__EncoderData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__MSG__DETAIL__ENCODER_DATA__STRUCT_H_
