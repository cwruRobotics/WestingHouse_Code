#ifndef _ROS_hwctrl_VescData_h
#define _ROS_hwctrl_VescData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace hwctrl
{

  class VescData : public ros::Msg
  {
    public:
      typedef ros::Time _timestamp_type;
      _timestamp_type timestamp;
      typedef const char* _motor_type_type;
      _motor_type_type motor_type;
      typedef int8_t _can_id_type;
      _can_id_type can_id;
      typedef float _raw_rpm_type;
      _raw_rpm_type raw_rpm;
      typedef float _current_type;
      _current_type current;
      typedef float _duty_cycle_type;
      _duty_cycle_type duty_cycle;
      typedef float _temp_mos1_type;
      _temp_mos1_type temp_mos1;
      typedef float _temp_mos2_type;
      _temp_mos2_type temp_mos2;
      typedef float _current_motor_type;
      _current_motor_type current_motor;
      typedef float _current_in_type;
      _current_in_type current_in;
      typedef float _avg_id_type;
      _avg_id_type avg_id;
      typedef float _avg_iq_type;
      _avg_iq_type avg_iq;
      typedef float _duty_now_type;
      _duty_now_type duty_now;
      typedef float _rpm_type;
      _rpm_type rpm;
      typedef float _v_in_type;
      _v_in_type v_in;
      typedef float _amp_hours_type;
      _amp_hours_type amp_hours;
      typedef float _amp_hours_charged_type;
      _amp_hours_charged_type amp_hours_charged;
      typedef float _watt_hours_type;
      _watt_hours_type watt_hours;
      typedef float _watt_hours_charged_type;
      _watt_hours_charged_type watt_hours_charged;
      typedef int32_t _tachometer_type;
      _tachometer_type tachometer;
      typedef int32_t _tachometer_abs_type;
      _tachometer_abs_type tachometer_abs;
      typedef int8_t _fault_code_type;
      _fault_code_type fault_code;

    VescData():
      timestamp(),
      motor_type(""),
      can_id(0),
      raw_rpm(0),
      current(0),
      duty_cycle(0),
      temp_mos1(0),
      temp_mos2(0),
      current_motor(0),
      current_in(0),
      avg_id(0),
      avg_iq(0),
      duty_now(0),
      rpm(0),
      v_in(0),
      amp_hours(0),
      amp_hours_charged(0),
      watt_hours(0),
      watt_hours_charged(0),
      tachometer(0),
      tachometer_abs(0),
      fault_code(0)
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
      uint32_t length_motor_type = strlen(this->motor_type);
      varToArr(outbuffer + offset, length_motor_type);
      offset += 4;
      memcpy(outbuffer + offset, this->motor_type, length_motor_type);
      offset += length_motor_type;
      union {
        int8_t real;
        uint8_t base;
      } u_can_id;
      u_can_id.real = this->can_id;
      *(outbuffer + offset + 0) = (u_can_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->can_id);
      union {
        float real;
        uint32_t base;
      } u_raw_rpm;
      u_raw_rpm.real = this->raw_rpm;
      *(outbuffer + offset + 0) = (u_raw_rpm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_rpm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_raw_rpm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_raw_rpm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raw_rpm);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_duty_cycle;
      u_duty_cycle.real = this->duty_cycle;
      *(outbuffer + offset + 0) = (u_duty_cycle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duty_cycle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duty_cycle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duty_cycle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duty_cycle);
      union {
        float real;
        uint32_t base;
      } u_temp_mos1;
      u_temp_mos1.real = this->temp_mos1;
      *(outbuffer + offset + 0) = (u_temp_mos1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp_mos1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp_mos1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp_mos1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp_mos1);
      union {
        float real;
        uint32_t base;
      } u_temp_mos2;
      u_temp_mos2.real = this->temp_mos2;
      *(outbuffer + offset + 0) = (u_temp_mos2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp_mos2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp_mos2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp_mos2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp_mos2);
      union {
        float real;
        uint32_t base;
      } u_current_motor;
      u_current_motor.real = this->current_motor;
      *(outbuffer + offset + 0) = (u_current_motor.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_motor.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_motor.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_motor.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_motor);
      union {
        float real;
        uint32_t base;
      } u_current_in;
      u_current_in.real = this->current_in;
      *(outbuffer + offset + 0) = (u_current_in.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_in.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_in.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_in.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_in);
      union {
        float real;
        uint32_t base;
      } u_avg_id;
      u_avg_id.real = this->avg_id;
      *(outbuffer + offset + 0) = (u_avg_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avg_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avg_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avg_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->avg_id);
      union {
        float real;
        uint32_t base;
      } u_avg_iq;
      u_avg_iq.real = this->avg_iq;
      *(outbuffer + offset + 0) = (u_avg_iq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_avg_iq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_avg_iq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_avg_iq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->avg_iq);
      union {
        float real;
        uint32_t base;
      } u_duty_now;
      u_duty_now.real = this->duty_now;
      *(outbuffer + offset + 0) = (u_duty_now.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_duty_now.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_duty_now.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_duty_now.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->duty_now);
      union {
        float real;
        uint32_t base;
      } u_rpm;
      u_rpm.real = this->rpm;
      *(outbuffer + offset + 0) = (u_rpm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rpm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rpm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rpm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rpm);
      union {
        float real;
        uint32_t base;
      } u_v_in;
      u_v_in.real = this->v_in;
      *(outbuffer + offset + 0) = (u_v_in.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_v_in.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_v_in.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_v_in.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->v_in);
      union {
        float real;
        uint32_t base;
      } u_amp_hours;
      u_amp_hours.real = this->amp_hours;
      *(outbuffer + offset + 0) = (u_amp_hours.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_amp_hours.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_amp_hours.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_amp_hours.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->amp_hours);
      union {
        float real;
        uint32_t base;
      } u_amp_hours_charged;
      u_amp_hours_charged.real = this->amp_hours_charged;
      *(outbuffer + offset + 0) = (u_amp_hours_charged.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_amp_hours_charged.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_amp_hours_charged.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_amp_hours_charged.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->amp_hours_charged);
      union {
        float real;
        uint32_t base;
      } u_watt_hours;
      u_watt_hours.real = this->watt_hours;
      *(outbuffer + offset + 0) = (u_watt_hours.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_watt_hours.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_watt_hours.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_watt_hours.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->watt_hours);
      union {
        float real;
        uint32_t base;
      } u_watt_hours_charged;
      u_watt_hours_charged.real = this->watt_hours_charged;
      *(outbuffer + offset + 0) = (u_watt_hours_charged.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_watt_hours_charged.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_watt_hours_charged.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_watt_hours_charged.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->watt_hours_charged);
      union {
        int32_t real;
        uint32_t base;
      } u_tachometer;
      u_tachometer.real = this->tachometer;
      *(outbuffer + offset + 0) = (u_tachometer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tachometer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tachometer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tachometer.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tachometer);
      union {
        int32_t real;
        uint32_t base;
      } u_tachometer_abs;
      u_tachometer_abs.real = this->tachometer_abs;
      *(outbuffer + offset + 0) = (u_tachometer_abs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tachometer_abs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tachometer_abs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tachometer_abs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tachometer_abs);
      union {
        int8_t real;
        uint8_t base;
      } u_fault_code;
      u_fault_code.real = this->fault_code;
      *(outbuffer + offset + 0) = (u_fault_code.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fault_code);
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
      uint32_t length_motor_type;
      arrToVar(length_motor_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_motor_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_motor_type-1]=0;
      this->motor_type = (char *)(inbuffer + offset-1);
      offset += length_motor_type;
      union {
        int8_t real;
        uint8_t base;
      } u_can_id;
      u_can_id.base = 0;
      u_can_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->can_id = u_can_id.real;
      offset += sizeof(this->can_id);
      union {
        float real;
        uint32_t base;
      } u_raw_rpm;
      u_raw_rpm.base = 0;
      u_raw_rpm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_raw_rpm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_raw_rpm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_raw_rpm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->raw_rpm = u_raw_rpm.real;
      offset += sizeof(this->raw_rpm);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_duty_cycle;
      u_duty_cycle.base = 0;
      u_duty_cycle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duty_cycle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duty_cycle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duty_cycle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->duty_cycle = u_duty_cycle.real;
      offset += sizeof(this->duty_cycle);
      union {
        float real;
        uint32_t base;
      } u_temp_mos1;
      u_temp_mos1.base = 0;
      u_temp_mos1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp_mos1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp_mos1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp_mos1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp_mos1 = u_temp_mos1.real;
      offset += sizeof(this->temp_mos1);
      union {
        float real;
        uint32_t base;
      } u_temp_mos2;
      u_temp_mos2.base = 0;
      u_temp_mos2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp_mos2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp_mos2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp_mos2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp_mos2 = u_temp_mos2.real;
      offset += sizeof(this->temp_mos2);
      union {
        float real;
        uint32_t base;
      } u_current_motor;
      u_current_motor.base = 0;
      u_current_motor.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_motor.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_motor.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_motor.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_motor = u_current_motor.real;
      offset += sizeof(this->current_motor);
      union {
        float real;
        uint32_t base;
      } u_current_in;
      u_current_in.base = 0;
      u_current_in.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_in.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_in.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_in.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_in = u_current_in.real;
      offset += sizeof(this->current_in);
      union {
        float real;
        uint32_t base;
      } u_avg_id;
      u_avg_id.base = 0;
      u_avg_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_avg_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_avg_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_avg_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->avg_id = u_avg_id.real;
      offset += sizeof(this->avg_id);
      union {
        float real;
        uint32_t base;
      } u_avg_iq;
      u_avg_iq.base = 0;
      u_avg_iq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_avg_iq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_avg_iq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_avg_iq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->avg_iq = u_avg_iq.real;
      offset += sizeof(this->avg_iq);
      union {
        float real;
        uint32_t base;
      } u_duty_now;
      u_duty_now.base = 0;
      u_duty_now.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_duty_now.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_duty_now.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_duty_now.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->duty_now = u_duty_now.real;
      offset += sizeof(this->duty_now);
      union {
        float real;
        uint32_t base;
      } u_rpm;
      u_rpm.base = 0;
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rpm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rpm = u_rpm.real;
      offset += sizeof(this->rpm);
      union {
        float real;
        uint32_t base;
      } u_v_in;
      u_v_in.base = 0;
      u_v_in.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_v_in.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_v_in.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_v_in.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->v_in = u_v_in.real;
      offset += sizeof(this->v_in);
      union {
        float real;
        uint32_t base;
      } u_amp_hours;
      u_amp_hours.base = 0;
      u_amp_hours.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_amp_hours.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_amp_hours.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_amp_hours.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->amp_hours = u_amp_hours.real;
      offset += sizeof(this->amp_hours);
      union {
        float real;
        uint32_t base;
      } u_amp_hours_charged;
      u_amp_hours_charged.base = 0;
      u_amp_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_amp_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_amp_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_amp_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->amp_hours_charged = u_amp_hours_charged.real;
      offset += sizeof(this->amp_hours_charged);
      union {
        float real;
        uint32_t base;
      } u_watt_hours;
      u_watt_hours.base = 0;
      u_watt_hours.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_watt_hours.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_watt_hours.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_watt_hours.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->watt_hours = u_watt_hours.real;
      offset += sizeof(this->watt_hours);
      union {
        float real;
        uint32_t base;
      } u_watt_hours_charged;
      u_watt_hours_charged.base = 0;
      u_watt_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_watt_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_watt_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_watt_hours_charged.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->watt_hours_charged = u_watt_hours_charged.real;
      offset += sizeof(this->watt_hours_charged);
      union {
        int32_t real;
        uint32_t base;
      } u_tachometer;
      u_tachometer.base = 0;
      u_tachometer.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tachometer.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tachometer.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tachometer.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tachometer = u_tachometer.real;
      offset += sizeof(this->tachometer);
      union {
        int32_t real;
        uint32_t base;
      } u_tachometer_abs;
      u_tachometer_abs.base = 0;
      u_tachometer_abs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tachometer_abs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tachometer_abs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tachometer_abs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tachometer_abs = u_tachometer_abs.real;
      offset += sizeof(this->tachometer_abs);
      union {
        int8_t real;
        uint8_t base;
      } u_fault_code;
      u_fault_code.base = 0;
      u_fault_code.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fault_code = u_fault_code.real;
      offset += sizeof(this->fault_code);
     return offset;
    }

    virtual const char * getType() override { return "hwctrl/VescData"; };
    virtual const char * getMD5() override { return "ab0eeb524dfff62a4b2da8331ea223bb"; };

  };

}
#endif
