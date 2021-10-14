#ifndef _ROS_SERVICE_StartAutonomy_h
#define _ROS_SERVICE_StartAutonomy_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glenn_msgs
{

static const char STARTAUTONOMY[] = "glenn_msgs/StartAutonomy";

  class StartAutonomyRequest : public ros::Msg
  {
    public:
      typedef bool _start_type;
      _start_type start;

    StartAutonomyRequest():
      start(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_start;
      u_start.real = this->start;
      *(outbuffer + offset + 0) = (u_start.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_start;
      u_start.base = 0;
      u_start.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start = u_start.real;
      offset += sizeof(this->start);
     return offset;
    }

    virtual const char * getType() override { return STARTAUTONOMY; };
    virtual const char * getMD5() override { return "676aa7bfb3ec2071e814f2368dfd5fb5"; };

  };

  class StartAutonomyResponse : public ros::Msg
  {
    public:
      typedef bool _confirm_type;
      _confirm_type confirm;

    StartAutonomyResponse():
      confirm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_confirm;
      u_confirm.real = this->confirm;
      *(outbuffer + offset + 0) = (u_confirm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->confirm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_confirm;
      u_confirm.base = 0;
      u_confirm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->confirm = u_confirm.real;
      offset += sizeof(this->confirm);
     return offset;
    }

    virtual const char * getType() override { return STARTAUTONOMY; };
    virtual const char * getMD5() override { return "b37994baa157ef8535427a2de0e06206"; };

  };

  class StartAutonomy {
    public:
    typedef StartAutonomyRequest Request;
    typedef StartAutonomyResponse Response;
  };

}
#endif
