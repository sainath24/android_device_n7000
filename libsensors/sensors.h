/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_SENSORS_H
#define ANDROID_SENSORS_H

#include <stdint.h>
#include <errno.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <linux/input.h>

#include <hardware/hardware.h>
#include <hardware/sensors.h>

__BEGIN_DECLS

/*****************************************************************************/

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#define ID_A  (0)
#define ID_M  (1)
#define ID_O  (2)
#define ID_L  (3)
#define ID_P  (4)
#define ID_GY (5)
#define ID_PR (6)

/*****************************************************************************/

/*
 * The SENSORS Module
 */

/* the GP2A is a binary proximity sensor that triggers around 5 cm on
 * this hardware */
#define PROXIMITY_THRESHOLD_GP2A  5.0f

/*****************************************************************************/

#define AKM_DEVICE_NAME     "/dev/akm8975"

// for akm8975
#define EVENT_TYPE_ACCEL_X          ABS_Y  //1
#define EVENT_TYPE_ACCEL_Y          ABS_X  //0
#define EVENT_TYPE_ACCEL_Z          ABS_Z  //2
//#define EVENT_TYPE_ACCEL_STATUS     ABS_WHEEL //8

#define EVENT_TYPE_YAW              ABS_RX  //3
#define EVENT_TYPE_PITCH            ABS_RY  //4
#define EVENT_TYPE_ROLL             ABS_RZ  //5
#define EVENT_TYPE_ORIENT_STATUS    ABS_WHEEL //8

#define EVENT_TYPE_MAGV_X           ABS_THROTTLE  // 7
#define EVENT_TYPE_MAGV_Y           ABS_RUDDER  // 6
#define EVENT_TYPE_MAGV_Z           ABS_GAS  // 9

#define EVENT_TYPE_TEMPERATURE      ABS_THROTTLE
#define EVENT_TYPE_STEP_COUNT       ABS_GAS
#define EVENT_TYPE_PROXIMITY        ABS_DISTANCE
#define EVENT_TYPE_PRESSURE         ABS_PRESSURE
#define EVENT_TYPE_LIGHT            ABS_MISC

#define EVENT_TYPE_GYRO_X           REL_RY
#define EVENT_TYPE_GYRO_Y           REL_RX
#define EVENT_TYPE_GYRO_Z           REL_RZ

// 90 LSB = 1G for KR3DM
#define LSB                         (90.0f)
#define NUMOFACCDATA                (8.0f)

// conversion of acceleration data to SI units (m/s^2)
#define RANGE_A                     (2*GRAVITY_EARTH)
#define CONVERT_A                   (GRAVITY_EARTH / LSB / NUMOFACCDATA)
#define CONVERT_A_X                 (CONVERT_A)
#define CONVERT_A_Y                 (-CONVERT_A)
#define CONVERT_A_Z                 (-CONVERT_A)

// conversion of magnetic data to uT units
#define CONVERT_M                   (1.0f/16.0f)
#define CONVERT_M_X                 (-CONVERT_M)
#define CONVERT_M_Y                 (-CONVERT_M)
#define CONVERT_M_Z                 (CONVERT_M)

/* conversion of orientation data to degree units */
#define CONVERT_O                   (1.0f/64.0f)
#define CONVERT_O_A                 (CONVERT_O)
#define CONVERT_O_P                 (CONVERT_O)
#define CONVERT_O_R                 (CONVERT_O)

// conversion of gyro data to SI units (radian/sec)
#define RANGE_GYRO                  (500.0f*(float)M_PI/180.0f)
#define CONVERT_GYRO                ((70.0f / 4000.0f) * ((float)M_PI / 180.0f))
#define CONVERT_GYRO_X              (-CONVERT_GYRO)
#define CONVERT_GYRO_Y              (-CONVERT_GYRO)
#define CONVERT_GYRO_Z              (-CONVERT_GYRO)

#define SENSOR_STATE_MASK           (0x7FFF)

/*****************************************************************************/

__END_DECLS

#endif  // ANDROID_SENSORS_H
