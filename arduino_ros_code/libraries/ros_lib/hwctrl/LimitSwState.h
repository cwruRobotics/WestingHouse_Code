#ifndef _ROS_hwctrl_LimitSwState_h
#define _ROS_hwctrl_LimitSwState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace hwctrl
{

  class LimitSwState : public ros::Msg
  {
    public:
      typedef int8_t _id_type;
      _id_type id;
      typedef bool _state_type;
      _state_type state;
      typedef int8_t _motor_id_type;
      _motor_id_type motor_id;
      typedef int8_t _allowed_dir_type;
      _allowed_dir_type allowed_dir;
      typedef ros::Time _timestamp_type;
      _timestamp_type timestamp;
      enum { FORWARD =  1 };
      enum { BACKWARD =  -1 };

    LimitSwState():
      id(0),
      state(0),
      motor_id(0),
      allowed_dir(0),
      timestamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      union {
        int8_t real;
        uint8_t base;
      } u_motor_id;
      u_motor_id.real = this->motor_id;
      *(outbuffer + offset + 0) = (u_motor_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor_id);
      union {
        int8_t real;
        uint8_t base;
      } u_allowed_dir;
      u_allowed_dir.real = this->allowed_dir;
      *(outbuffer + offset + 0) = (u_allowed_dir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allowed_dir);
      *(outbuffer + offset + 0) = (this->timestamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.sec);
      *(outbuffer + offset + 0) = (this->timestamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->timestamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->timestamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->timestamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timestamp.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        bool real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
      union {
        int8_t real;
        uint8_t base;
      } u_motor_id;
      u_motor_id.base = 0;
      u_motor_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->motor_id = u_motor_id.real;
      offset += sizeof(this->motor_id);
      union {
        int8_t real;
        uint8_t base;
      } u_allowed_dir;
      u_allowed_dir.base = 0;
      u_allowed_dir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allowed_dir = u_allowed_dir.real;
      offset += sizeof(this->allowed_dir);
      this->timestamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.sec);
      this->timestamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->timestamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->timestamp.nsec);
     return offset;
    }

    virtual const char * getType() override { return "hwctrl/LimitSwState"; };
    virtual const char * getMD5() override { return "e06f506628c3aeba93eaf06d3d3fbb2a"; };

  };

}
#endif
