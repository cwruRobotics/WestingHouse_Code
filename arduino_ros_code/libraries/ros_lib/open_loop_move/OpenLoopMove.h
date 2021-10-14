#ifndef _ROS_SERVICE_OpenLoopMove_h
#define _ROS_SERVICE_OpenLoopMove_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace open_loop_move
{

static const char OPENLOOPMOVE[] = "open_loop_move/OpenLoopMove";

  class OpenLoopMoveRequest : public ros::Msg
  {
    public:
      typedef uint8_t _move_type_type;
      _move_type_type move_type;
      typedef float _distance_type;
      _distance_type distance;
      enum { DISTANCE =  0 };
      enum { ANGLE =  1 };

    OpenLoopMoveRequest():
      move_type(0),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->move_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->move_type);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.real = this->distance;
      *(outbuffer + offset + 0) = (u_distance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_distance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_distance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_distance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->move_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->move_type);
      union {
        float real;
        uint32_t base;
      } u_distance;
      u_distance.base = 0;
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->distance = u_distance.real;
      offset += sizeof(this->distance);
     return offset;
    }

    virtual const char * getType() override { return OPENLOOPMOVE; };
    virtual const char * getMD5() override { return "882d40624bfe3e1768b29d6153aa30dd"; };

  };

  class OpenLoopMoveResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    OpenLoopMoveResponse():
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

    virtual const char * getType() override { return OPENLOOPMOVE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class OpenLoopMove {
    public:
    typedef OpenLoopMoveRequest Request;
    typedef OpenLoopMoveResponse Response;
  };

}
#endif
