#ifndef _ROS_SERVICE_LED_h
#define _ROS_SERVICE_LED_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hwctrl
{

static const char LED[] = "hwctrl/LED";

  class LEDRequest : public ros::Msg
  {
    public:
      typedef uint8_t _r_type;
      _r_type r;
      typedef uint8_t _g_type;
      _g_type g;
      typedef uint8_t _b_type;
      _b_type b;

    LEDRequest():
      r(0),
      g(0),
      b(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->r >> (8 * 0)) & 0xFF;
      offset += sizeof(this->r);
      *(outbuffer + offset + 0) = (this->g >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g);
      *(outbuffer + offset + 0) = (this->b >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->r =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->r);
      this->g =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->g);
      this->b =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->b);
     return offset;
    }

    virtual const char * getType() override { return LED; };
    virtual const char * getMD5() override { return "353891e354491c51aabe32df673fb446"; };

  };

  class LEDResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    LEDResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return LED; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class LED {
    public:
    typedef LEDRequest Request;
    typedef LEDResponse Response;
  };

}
#endif
