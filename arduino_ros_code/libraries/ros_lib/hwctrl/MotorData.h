#ifndef _ROS_hwctrl_MotorData_h
#define _ROS_hwctrl_MotorData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace hwctrl
{

  class MotorData : public ros::Msg
  {
    public:
      typedef int8_t _id_type;
      _id_type id;
      typedef ros::Time _timestamp_type;
      _timestamp_type timestamp;
      typedef int8_t _data_type_type;
      _data_type_type data_type;
      typedef float _value_type;
      _value_type value;
      enum { RPM =  0 };
      enum { RAW_RPM =  1 };
      enum { CURRENT_IN =  2 };
      enum { VOLTAGE_IN =  3 };
      enum { DUTY_CYCLE =  4 };
      enum { TEMPERATURE_MOS =  5 };
      enum { AMP_HOURS =  6 };
      enum { AMP_HOURS_CHARGED =  7 };
      enum { WATT_HOURS = 8 };
      enum { WATT_HOURS_CHARGED =  9 };
      enum { TACHOMETER =  10 };
      enum { TACHOMETER_ABS =  11 };
      enum { FAULT_CODE =  12 };
      enum { SETPOINT =  13 };

    MotorData():
      id(0),
      timestamp(),
      data_type(0),
      value(0)
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
      union {
        int8_t real;
        uint8_t base;
      } u_data_type;
      u_data_type.real = this->data_type;
      *(outbuffer + offset + 0) = (u_data_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data_type);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
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
      union {
        int8_t real;
        uint8_t base;
      } u_data_type;
      u_data_type.base = 0;
      u_data_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data_type = u_data_type.real;
      offset += sizeof(this->data_type);
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    virtual const char * getType() override { return "hwctrl/MotorData"; };
    virtual const char * getMD5() override { return "28d0c777ddee6c9aa67c967c558f7262"; };

  };

}
#endif
