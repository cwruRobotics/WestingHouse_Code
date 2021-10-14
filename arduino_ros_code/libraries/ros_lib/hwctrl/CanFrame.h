#ifndef _ROS_hwctrl_CanFrame_h
#define _ROS_hwctrl_CanFrame_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hwctrl
{

  class CanFrame : public ros::Msg
  {
    public:
      typedef uint32_t _can_id_type;
      _can_id_type can_id;
      typedef uint8_t _can_dlc_type;
      _can_dlc_type can_dlc;
      uint8_t data[8];

    CanFrame():
      can_id(0),
      can_dlc(0),
      data()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->can_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->can_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->can_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->can_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->can_id);
      *(outbuffer + offset + 0) = (this->can_dlc >> (8 * 0)) & 0xFF;
      offset += sizeof(this->can_dlc);
      for( uint32_t i = 0; i < 8; i++){
      *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->can_id =  ((uint32_t) (*(inbuffer + offset)));
      this->can_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->can_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->can_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->can_id);
      this->can_dlc =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->can_dlc);
      for( uint32_t i = 0; i < 8; i++){
      this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->data[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "hwctrl/CanFrame"; };
    virtual const char * getMD5() override { return "4e60c73cd63b60b3d5f9de9cd4e3f830"; };

  };

}
#endif
