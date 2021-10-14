#ifndef _ROS_glenn_msgs_TransitControlData_h
#define _ROS_glenn_msgs_TransitControlData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace glenn_msgs
{

  class TransitControlData : public ros::Msg
  {
    public:
      typedef float _t_vel_type;
      _t_vel_type t_vel;
      typedef float _t_angular_vel_type;
      _t_angular_vel_type t_angular_vel;
      typedef float _vel_type;
      _vel_type vel;
      typedef float _angular_vel_type;
      _angular_vel_type angular_vel;
      typedef float _t_right_speed_type;
      _t_right_speed_type t_right_speed;
      typedef float _t_left_speed_type;
      _t_left_speed_type t_left_speed;
      typedef float _right_speed_type;
      _right_speed_type right_speed;
      typedef float _left_speed_type;
      _left_speed_type left_speed;
      uint32_t followed_segment_length;
      typedef float _followed_segment_type;
      _followed_segment_type st_followed_segment;
      _followed_segment_type * followed_segment;
      uint32_t closest_point_length;
      typedef float _closest_point_type;
      _closest_point_type st_closest_point;
      _closest_point_type * closest_point;
      uint32_t reference_point_length;
      typedef float _reference_point_type;
      _reference_point_type st_reference_point;
      _reference_point_type * reference_point;

    TransitControlData():
      t_vel(0),
      t_angular_vel(0),
      vel(0),
      angular_vel(0),
      t_right_speed(0),
      t_left_speed(0),
      right_speed(0),
      left_speed(0),
      followed_segment_length(0), st_followed_segment(), followed_segment(nullptr),
      closest_point_length(0), st_closest_point(), closest_point(nullptr),
      reference_point_length(0), st_reference_point(), reference_point(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_t_vel;
      u_t_vel.real = this->t_vel;
      *(outbuffer + offset + 0) = (u_t_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_t_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_t_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_t_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t_vel);
      union {
        float real;
        uint32_t base;
      } u_t_angular_vel;
      u_t_angular_vel.real = this->t_angular_vel;
      *(outbuffer + offset + 0) = (u_t_angular_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_t_angular_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_t_angular_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_t_angular_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t_angular_vel);
      union {
        float real;
        uint32_t base;
      } u_vel;
      u_vel.real = this->vel;
      *(outbuffer + offset + 0) = (u_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel);
      union {
        float real;
        uint32_t base;
      } u_angular_vel;
      u_angular_vel.real = this->angular_vel;
      *(outbuffer + offset + 0) = (u_angular_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angular_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angular_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angular_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angular_vel);
      union {
        float real;
        uint32_t base;
      } u_t_right_speed;
      u_t_right_speed.real = this->t_right_speed;
      *(outbuffer + offset + 0) = (u_t_right_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_t_right_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_t_right_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_t_right_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t_right_speed);
      union {
        float real;
        uint32_t base;
      } u_t_left_speed;
      u_t_left_speed.real = this->t_left_speed;
      *(outbuffer + offset + 0) = (u_t_left_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_t_left_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_t_left_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_t_left_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->t_left_speed);
      union {
        float real;
        uint32_t base;
      } u_right_speed;
      u_right_speed.real = this->right_speed;
      *(outbuffer + offset + 0) = (u_right_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_speed);
      union {
        float real;
        uint32_t base;
      } u_left_speed;
      u_left_speed.real = this->left_speed;
      *(outbuffer + offset + 0) = (u_left_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_speed);
      *(outbuffer + offset + 0) = (this->followed_segment_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->followed_segment_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->followed_segment_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->followed_segment_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->followed_segment_length);
      for( uint32_t i = 0; i < followed_segment_length; i++){
      union {
        float real;
        uint32_t base;
      } u_followed_segmenti;
      u_followed_segmenti.real = this->followed_segment[i];
      *(outbuffer + offset + 0) = (u_followed_segmenti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_followed_segmenti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_followed_segmenti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_followed_segmenti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->followed_segment[i]);
      }
      *(outbuffer + offset + 0) = (this->closest_point_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->closest_point_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->closest_point_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->closest_point_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->closest_point_length);
      for( uint32_t i = 0; i < closest_point_length; i++){
      union {
        float real;
        uint32_t base;
      } u_closest_pointi;
      u_closest_pointi.real = this->closest_point[i];
      *(outbuffer + offset + 0) = (u_closest_pointi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_closest_pointi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_closest_pointi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_closest_pointi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->closest_point[i]);
      }
      *(outbuffer + offset + 0) = (this->reference_point_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->reference_point_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->reference_point_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->reference_point_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_point_length);
      for( uint32_t i = 0; i < reference_point_length; i++){
      union {
        float real;
        uint32_t base;
      } u_reference_pointi;
      u_reference_pointi.real = this->reference_point[i];
      *(outbuffer + offset + 0) = (u_reference_pointi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_reference_pointi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_reference_pointi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_reference_pointi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->reference_point[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_t_vel;
      u_t_vel.base = 0;
      u_t_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_t_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_t_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_t_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->t_vel = u_t_vel.real;
      offset += sizeof(this->t_vel);
      union {
        float real;
        uint32_t base;
      } u_t_angular_vel;
      u_t_angular_vel.base = 0;
      u_t_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_t_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_t_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_t_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->t_angular_vel = u_t_angular_vel.real;
      offset += sizeof(this->t_angular_vel);
      union {
        float real;
        uint32_t base;
      } u_vel;
      u_vel.base = 0;
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vel = u_vel.real;
      offset += sizeof(this->vel);
      union {
        float real;
        uint32_t base;
      } u_angular_vel;
      u_angular_vel.base = 0;
      u_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angular_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angular_vel = u_angular_vel.real;
      offset += sizeof(this->angular_vel);
      union {
        float real;
        uint32_t base;
      } u_t_right_speed;
      u_t_right_speed.base = 0;
      u_t_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_t_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_t_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_t_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->t_right_speed = u_t_right_speed.real;
      offset += sizeof(this->t_right_speed);
      union {
        float real;
        uint32_t base;
      } u_t_left_speed;
      u_t_left_speed.base = 0;
      u_t_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_t_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_t_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_t_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->t_left_speed = u_t_left_speed.real;
      offset += sizeof(this->t_left_speed);
      union {
        float real;
        uint32_t base;
      } u_right_speed;
      u_right_speed.base = 0;
      u_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_speed = u_right_speed.real;
      offset += sizeof(this->right_speed);
      union {
        float real;
        uint32_t base;
      } u_left_speed;
      u_left_speed.base = 0;
      u_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_speed = u_left_speed.real;
      offset += sizeof(this->left_speed);
      uint32_t followed_segment_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      followed_segment_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      followed_segment_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      followed_segment_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->followed_segment_length);
      if(followed_segment_lengthT > followed_segment_length)
        this->followed_segment = (float*)realloc(this->followed_segment, followed_segment_lengthT * sizeof(float));
      followed_segment_length = followed_segment_lengthT;
      for( uint32_t i = 0; i < followed_segment_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_followed_segment;
      u_st_followed_segment.base = 0;
      u_st_followed_segment.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_followed_segment.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_followed_segment.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_followed_segment.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_followed_segment = u_st_followed_segment.real;
      offset += sizeof(this->st_followed_segment);
        memcpy( &(this->followed_segment[i]), &(this->st_followed_segment), sizeof(float));
      }
      uint32_t closest_point_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      closest_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      closest_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      closest_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->closest_point_length);
      if(closest_point_lengthT > closest_point_length)
        this->closest_point = (float*)realloc(this->closest_point, closest_point_lengthT * sizeof(float));
      closest_point_length = closest_point_lengthT;
      for( uint32_t i = 0; i < closest_point_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_closest_point;
      u_st_closest_point.base = 0;
      u_st_closest_point.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_closest_point.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_closest_point.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_closest_point.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_closest_point = u_st_closest_point.real;
      offset += sizeof(this->st_closest_point);
        memcpy( &(this->closest_point[i]), &(this->st_closest_point), sizeof(float));
      }
      uint32_t reference_point_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      reference_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      reference_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      reference_point_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->reference_point_length);
      if(reference_point_lengthT > reference_point_length)
        this->reference_point = (float*)realloc(this->reference_point, reference_point_lengthT * sizeof(float));
      reference_point_length = reference_point_lengthT;
      for( uint32_t i = 0; i < reference_point_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_reference_point;
      u_st_reference_point.base = 0;
      u_st_reference_point.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_reference_point.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_reference_point.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_reference_point.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_reference_point = u_st_reference_point.real;
      offset += sizeof(this->st_reference_point);
        memcpy( &(this->reference_point[i]), &(this->st_reference_point), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "glenn_msgs/TransitControlData"; };
    virtual const char * getMD5() override { return "db1d921e08f9575bce54048044a53044"; };

  };

}
#endif
