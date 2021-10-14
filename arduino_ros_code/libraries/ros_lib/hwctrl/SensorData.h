#ifndef _ROS_hwctrl_SensorData_h
#define _ROS_hwctrl_SensorData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hwctrl
{

  class SensorData : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef int8_t _sensor_id_type;
      _sensor_id_type sensor_id;
      typedef float _value_type;
      _value_type value;

    SensorData():
      name(""),
      sensor_id(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        int8_t real;
        uint8_t base;
      } u_sensor_id;
      u_sensor_id.real = this->sensor_id;
      *(outbuffer + offset + 0) = (u_sensor_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sensor_id);
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
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        int8_t real;
        uint8_t base;
      } u_sensor_id;
      u_sensor_id.base = 0;
      u_sensor_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sensor_id = u_sensor_id.real;
      offset += sizeof(this->sensor_id);
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

    virtual const char * getType() override { return "hwctrl/SensorData"; };
    virtual const char * getMD5() override { return "fc30f8bd197a4e6e07b2d29a0b3dfa64"; };

  };

}
#endif
