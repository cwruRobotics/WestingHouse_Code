#ifndef _ROS_SERVICE_EffectiveRPM_h
#define _ROS_SERVICE_EffectiveRPM_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glenn_msgs
{

static const char EFFECTIVERPM[] = "glenn_msgs/EffectiveRPM";

  class EffectiveRPMRequest : public ros::Msg
  {
    public:
      typedef float _left_type;
      _left_type left;
      typedef float _right_type;
      _right_type right;

    EffectiveRPMRequest():
      left(0),
      right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_left;
      u_left.real = this->left;
      *(outbuffer + offset + 0) = (u_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left);
      union {
        float real;
        uint32_t base;
      } u_right;
      u_right.real = this->right;
      *(outbuffer + offset + 0) = (u_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_left;
      u_left.base = 0;
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left = u_left.real;
      offset += sizeof(this->left);
      union {
        float real;
        uint32_t base;
      } u_right;
      u_right.base = 0;
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right = u_right.real;
      offset += sizeof(this->right);
     return offset;
    }

    virtual const char * getType() override { return EFFECTIVERPM; };
    virtual const char * getMD5() override { return "3a927990ab5d5c3d628e2d52b8533e52"; };

  };

  class EffectiveRPMResponse : public ros::Msg
  {
    public:
      typedef float _effective_left_type;
      _effective_left_type effective_left;
      typedef float _effective_right_type;
      _effective_right_type effective_right;

    EffectiveRPMResponse():
      effective_left(0),
      effective_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_effective_left;
      u_effective_left.real = this->effective_left;
      *(outbuffer + offset + 0) = (u_effective_left.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effective_left.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effective_left.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effective_left.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effective_left);
      union {
        float real;
        uint32_t base;
      } u_effective_right;
      u_effective_right.real = this->effective_right;
      *(outbuffer + offset + 0) = (u_effective_right.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_effective_right.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_effective_right.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_effective_right.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effective_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_effective_left;
      u_effective_left.base = 0;
      u_effective_left.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_effective_left.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_effective_left.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_effective_left.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->effective_left = u_effective_left.real;
      offset += sizeof(this->effective_left);
      union {
        float real;
        uint32_t base;
      } u_effective_right;
      u_effective_right.base = 0;
      u_effective_right.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_effective_right.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_effective_right.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_effective_right.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->effective_right = u_effective_right.real;
      offset += sizeof(this->effective_right);
     return offset;
    }

    virtual const char * getType() override { return EFFECTIVERPM; };
    virtual const char * getMD5() override { return "7a984a0d664ab350680074e43f4dcddc"; };

  };

  class EffectiveRPM {
    public:
    typedef EffectiveRPMRequest Request;
    typedef EffectiveRPMResponse Response;
  };

}
#endif
