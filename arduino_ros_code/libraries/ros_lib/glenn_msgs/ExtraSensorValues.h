#ifndef _ROS_glenn_msgs_ExtraSensorValues_h
#define _ROS_glenn_msgs_ExtraSensorValues_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glenn_msgs
{

  class ExtraSensorValues : public ros::Msg
  {
    public:
      typedef float _port_drive_encoder_type;
      _port_drive_encoder_type port_drive_encoder;
      typedef float _starboard_drive_encoder_type;
      _starboard_drive_encoder_type starboard_drive_encoder;
      typedef float _bc_attitude_port_pot_type;
      _bc_attitude_port_pot_type bc_attitude_port_pot;
      typedef float _bc_attitude_starboard_pot_type;
      _bc_attitude_starboard_pot_type bc_attitude_starboard_pot;
      typedef float _dep_load_cell_type;
      _dep_load_cell_type dep_load_cell;
      typedef float _exc_load_cell_type;
      _exc_load_cell_type exc_load_cell;
      typedef float _dep_lower_limit_type;
      _dep_lower_limit_type dep_lower_limit;
      typedef float _dep_upper_limit_type;
      _dep_upper_limit_type dep_upper_limit;
      typedef float _exc_fore_limit_type;
      _exc_fore_limit_type exc_fore_limit;
      typedef float _exc_aft_limit_type;
      _exc_aft_limit_type exc_aft_limit;
      typedef float _bc_lower_limit_type;
      _bc_lower_limit_type bc_lower_limit;
      typedef float _bc_upper_limit_type;
      _bc_upper_limit_type bc_upper_limit;

    ExtraSensorValues():
      port_drive_encoder(0),
      starboard_drive_encoder(0),
      bc_attitude_port_pot(0),
      bc_attitude_starboard_pot(0),
      dep_load_cell(0),
      exc_load_cell(0),
      dep_lower_limit(0),
      dep_upper_limit(0),
      exc_fore_limit(0),
      exc_aft_limit(0),
      bc_lower_limit(0),
      bc_upper_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_port_drive_encoder;
      u_port_drive_encoder.real = this->port_drive_encoder;
      *(outbuffer + offset + 0) = (u_port_drive_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_port_drive_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_port_drive_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_port_drive_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->port_drive_encoder);
      union {
        float real;
        uint32_t base;
      } u_starboard_drive_encoder;
      u_starboard_drive_encoder.real = this->starboard_drive_encoder;
      *(outbuffer + offset + 0) = (u_starboard_drive_encoder.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_starboard_drive_encoder.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_starboard_drive_encoder.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_starboard_drive_encoder.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->starboard_drive_encoder);
      union {
        float real;
        uint32_t base;
      } u_bc_attitude_port_pot;
      u_bc_attitude_port_pot.real = this->bc_attitude_port_pot;
      *(outbuffer + offset + 0) = (u_bc_attitude_port_pot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bc_attitude_port_pot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bc_attitude_port_pot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bc_attitude_port_pot.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bc_attitude_port_pot);
      union {
        float real;
        uint32_t base;
      } u_bc_attitude_starboard_pot;
      u_bc_attitude_starboard_pot.real = this->bc_attitude_starboard_pot;
      *(outbuffer + offset + 0) = (u_bc_attitude_starboard_pot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bc_attitude_starboard_pot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bc_attitude_starboard_pot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bc_attitude_starboard_pot.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bc_attitude_starboard_pot);
      union {
        float real;
        uint32_t base;
      } u_dep_load_cell;
      u_dep_load_cell.real = this->dep_load_cell;
      *(outbuffer + offset + 0) = (u_dep_load_cell.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dep_load_cell.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dep_load_cell.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dep_load_cell.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dep_load_cell);
      union {
        float real;
        uint32_t base;
      } u_exc_load_cell;
      u_exc_load_cell.real = this->exc_load_cell;
      *(outbuffer + offset + 0) = (u_exc_load_cell.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exc_load_cell.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exc_load_cell.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exc_load_cell.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exc_load_cell);
      union {
        float real;
        uint32_t base;
      } u_dep_lower_limit;
      u_dep_lower_limit.real = this->dep_lower_limit;
      *(outbuffer + offset + 0) = (u_dep_lower_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dep_lower_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dep_lower_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dep_lower_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dep_lower_limit);
      union {
        float real;
        uint32_t base;
      } u_dep_upper_limit;
      u_dep_upper_limit.real = this->dep_upper_limit;
      *(outbuffer + offset + 0) = (u_dep_upper_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dep_upper_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dep_upper_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dep_upper_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dep_upper_limit);
      union {
        float real;
        uint32_t base;
      } u_exc_fore_limit;
      u_exc_fore_limit.real = this->exc_fore_limit;
      *(outbuffer + offset + 0) = (u_exc_fore_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exc_fore_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exc_fore_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exc_fore_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exc_fore_limit);
      union {
        float real;
        uint32_t base;
      } u_exc_aft_limit;
      u_exc_aft_limit.real = this->exc_aft_limit;
      *(outbuffer + offset + 0) = (u_exc_aft_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_exc_aft_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_exc_aft_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_exc_aft_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exc_aft_limit);
      union {
        float real;
        uint32_t base;
      } u_bc_lower_limit;
      u_bc_lower_limit.real = this->bc_lower_limit;
      *(outbuffer + offset + 0) = (u_bc_lower_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bc_lower_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bc_lower_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bc_lower_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bc_lower_limit);
      union {
        float real;
        uint32_t base;
      } u_bc_upper_limit;
      u_bc_upper_limit.real = this->bc_upper_limit;
      *(outbuffer + offset + 0) = (u_bc_upper_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bc_upper_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bc_upper_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bc_upper_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bc_upper_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_port_drive_encoder;
      u_port_drive_encoder.base = 0;
      u_port_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_port_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_port_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_port_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->port_drive_encoder = u_port_drive_encoder.real;
      offset += sizeof(this->port_drive_encoder);
      union {
        float real;
        uint32_t base;
      } u_starboard_drive_encoder;
      u_starboard_drive_encoder.base = 0;
      u_starboard_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_starboard_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_starboard_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_starboard_drive_encoder.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->starboard_drive_encoder = u_starboard_drive_encoder.real;
      offset += sizeof(this->starboard_drive_encoder);
      union {
        float real;
        uint32_t base;
      } u_bc_attitude_port_pot;
      u_bc_attitude_port_pot.base = 0;
      u_bc_attitude_port_pot.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bc_attitude_port_pot.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bc_attitude_port_pot.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bc_attitude_port_pot.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bc_attitude_port_pot = u_bc_attitude_port_pot.real;
      offset += sizeof(this->bc_attitude_port_pot);
      union {
        float real;
        uint32_t base;
      } u_bc_attitude_starboard_pot;
      u_bc_attitude_starboard_pot.base = 0;
      u_bc_attitude_starboard_pot.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bc_attitude_starboard_pot.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bc_attitude_starboard_pot.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bc_attitude_starboard_pot.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bc_attitude_starboard_pot = u_bc_attitude_starboard_pot.real;
      offset += sizeof(this->bc_attitude_starboard_pot);
      union {
        float real;
        uint32_t base;
      } u_dep_load_cell;
      u_dep_load_cell.base = 0;
      u_dep_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dep_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dep_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dep_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dep_load_cell = u_dep_load_cell.real;
      offset += sizeof(this->dep_load_cell);
      union {
        float real;
        uint32_t base;
      } u_exc_load_cell;
      u_exc_load_cell.base = 0;
      u_exc_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exc_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exc_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exc_load_cell.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exc_load_cell = u_exc_load_cell.real;
      offset += sizeof(this->exc_load_cell);
      union {
        float real;
        uint32_t base;
      } u_dep_lower_limit;
      u_dep_lower_limit.base = 0;
      u_dep_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dep_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dep_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dep_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dep_lower_limit = u_dep_lower_limit.real;
      offset += sizeof(this->dep_lower_limit);
      union {
        float real;
        uint32_t base;
      } u_dep_upper_limit;
      u_dep_upper_limit.base = 0;
      u_dep_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dep_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dep_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dep_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dep_upper_limit = u_dep_upper_limit.real;
      offset += sizeof(this->dep_upper_limit);
      union {
        float real;
        uint32_t base;
      } u_exc_fore_limit;
      u_exc_fore_limit.base = 0;
      u_exc_fore_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exc_fore_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exc_fore_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exc_fore_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exc_fore_limit = u_exc_fore_limit.real;
      offset += sizeof(this->exc_fore_limit);
      union {
        float real;
        uint32_t base;
      } u_exc_aft_limit;
      u_exc_aft_limit.base = 0;
      u_exc_aft_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_exc_aft_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_exc_aft_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_exc_aft_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->exc_aft_limit = u_exc_aft_limit.real;
      offset += sizeof(this->exc_aft_limit);
      union {
        float real;
        uint32_t base;
      } u_bc_lower_limit;
      u_bc_lower_limit.base = 0;
      u_bc_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bc_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bc_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bc_lower_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bc_lower_limit = u_bc_lower_limit.real;
      offset += sizeof(this->bc_lower_limit);
      union {
        float real;
        uint32_t base;
      } u_bc_upper_limit;
      u_bc_upper_limit.base = 0;
      u_bc_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bc_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bc_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bc_upper_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bc_upper_limit = u_bc_upper_limit.real;
      offset += sizeof(this->bc_upper_limit);
     return offset;
    }

    virtual const char * getType() override { return "glenn_msgs/ExtraSensorValues"; };
    virtual const char * getMD5() override { return "b0927e857703908f9289c1a02e9fb428"; };

  };

}
#endif
