#ifndef _ROS_hwctrl_UwbData_h
#define _ROS_hwctrl_UwbData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace hwctrl
{

  class UwbData : public ros::Msg
  {
    public:
      typedef ros::Time _timestamp_type;
      _timestamp_type timestamp;
      typedef int8_t _node_id_type;
      _node_id_type node_id;
      typedef int8_t _anchor_id_type;
      _anchor_id_type anchor_id;
      typedef float _anchor_x_type;
      _anchor_x_type anchor_x;
      typedef float _anchor_y_type;
      _anchor_y_type anchor_y;
      typedef float _anchor_z_type;
      _anchor_z_type anchor_z;
      typedef float _distance_type;
      _distance_type distance;
      typedef float _rx_power_type;
      _rx_power_type rx_power;
      typedef float _fp_power_type;
      _fp_power_type fp_power;
      typedef float _fp_snr_type;
      _fp_snr_type fp_snr;

    UwbData():
      timestamp(),
      node_id(0),
      anchor_id(0),
      anchor_x(0),
      anchor_y(0),
      anchor_z(0),
      distance(0),
      rx_power(0),
      fp_power(0),
      fp_snr(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      } u_node_id;
      u_node_id.real = this->node_id;
      *(outbuffer + offset + 0) = (u_node_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->node_id);
      union {
        int8_t real;
        uint8_t base;
      } u_anchor_id;
      u_anchor_id.real = this->anchor_id;
      *(outbuffer + offset + 0) = (u_anchor_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->anchor_id);
      union {
        float real;
        uint32_t base;
      } u_anchor_x;
      u_anchor_x.real = this->anchor_x;
      *(outbuffer + offset + 0) = (u_anchor_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anchor_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anchor_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anchor_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->anchor_x);
      union {
        float real;
        uint32_t base;
      } u_anchor_y;
      u_anchor_y.real = this->anchor_y;
      *(outbuffer + offset + 0) = (u_anchor_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anchor_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anchor_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anchor_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->anchor_y);
      union {
        float real;
        uint32_t base;
      } u_anchor_z;
      u_anchor_z.real = this->anchor_z;
      *(outbuffer + offset + 0) = (u_anchor_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_anchor_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_anchor_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_anchor_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->anchor_z);
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
      union {
        float real;
        uint32_t base;
      } u_rx_power;
      u_rx_power.real = this->rx_power;
      *(outbuffer + offset + 0) = (u_rx_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rx_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rx_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rx_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rx_power);
      union {
        float real;
        uint32_t base;
      } u_fp_power;
      u_fp_power.real = this->fp_power;
      *(outbuffer + offset + 0) = (u_fp_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fp_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fp_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fp_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fp_power);
      union {
        float real;
        uint32_t base;
      } u_fp_snr;
      u_fp_snr.real = this->fp_snr;
      *(outbuffer + offset + 0) = (u_fp_snr.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fp_snr.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fp_snr.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fp_snr.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fp_snr);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      } u_node_id;
      u_node_id.base = 0;
      u_node_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->node_id = u_node_id.real;
      offset += sizeof(this->node_id);
      union {
        int8_t real;
        uint8_t base;
      } u_anchor_id;
      u_anchor_id.base = 0;
      u_anchor_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->anchor_id = u_anchor_id.real;
      offset += sizeof(this->anchor_id);
      union {
        float real;
        uint32_t base;
      } u_anchor_x;
      u_anchor_x.base = 0;
      u_anchor_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anchor_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anchor_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anchor_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->anchor_x = u_anchor_x.real;
      offset += sizeof(this->anchor_x);
      union {
        float real;
        uint32_t base;
      } u_anchor_y;
      u_anchor_y.base = 0;
      u_anchor_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anchor_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anchor_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anchor_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->anchor_y = u_anchor_y.real;
      offset += sizeof(this->anchor_y);
      union {
        float real;
        uint32_t base;
      } u_anchor_z;
      u_anchor_z.base = 0;
      u_anchor_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_anchor_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_anchor_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_anchor_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->anchor_z = u_anchor_z.real;
      offset += sizeof(this->anchor_z);
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
      union {
        float real;
        uint32_t base;
      } u_rx_power;
      u_rx_power.base = 0;
      u_rx_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rx_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rx_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rx_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rx_power = u_rx_power.real;
      offset += sizeof(this->rx_power);
      union {
        float real;
        uint32_t base;
      } u_fp_power;
      u_fp_power.base = 0;
      u_fp_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fp_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fp_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fp_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fp_power = u_fp_power.real;
      offset += sizeof(this->fp_power);
      union {
        float real;
        uint32_t base;
      } u_fp_snr;
      u_fp_snr.base = 0;
      u_fp_snr.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fp_snr.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fp_snr.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fp_snr.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fp_snr = u_fp_snr.real;
      offset += sizeof(this->fp_snr);
     return offset;
    }

    virtual const char * getType() override { return "hwctrl/UwbData"; };
    virtual const char * getMD5() override { return "f760082448d6396fcc8f477bef4627d2"; };

  };

}
#endif
