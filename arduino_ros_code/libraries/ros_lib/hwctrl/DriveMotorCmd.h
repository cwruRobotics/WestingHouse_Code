#ifndef _ROS_hwctrl_DriveMotorCmd_h
#define _ROS_hwctrl_DriveMotorCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hwctrl/MotorCmd.h"

namespace hwctrl
{

  class DriveMotorCmd : public ros::Msg
  {
    public:
      typedef hwctrl::MotorCmd _left_type;
      _left_type left;
      typedef hwctrl::MotorCmd _right_type;
      _right_type right;

    DriveMotorCmd():
      left(),
      right()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->left.serialize(outbuffer + offset);
      offset += this->right.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->left.deserialize(inbuffer + offset);
      offset += this->right.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "hwctrl/DriveMotorCmd"; };
    virtual const char * getMD5() override { return "e144b726fc134bef9a1acadd19f1c7d4"; };

  };

}
#endif
