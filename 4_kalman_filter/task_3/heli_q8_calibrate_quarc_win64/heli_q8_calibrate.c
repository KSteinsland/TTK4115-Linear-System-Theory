/*
 * heli_q8_calibrate.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_calibrate".
 *
 * Model version              : 1.126
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sat Nov 07 22:41:33 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_calibrate.h"
#include "heli_q8_calibrate_private.h"
#include "heli_q8_calibrate_dt.h"

t_stream heli_q8_calibrate_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_q8_calibrate_T heli_q8_calibrate_B;

/* Block states (auto storage) */
DW_heli_q8_calibrate_T heli_q8_calibrate_DW;

/* Real-time model */
RT_MODEL_heli_q8_calibrate_T heli_q8_calibrate_M_;
RT_MODEL_heli_q8_calibrate_T *const heli_q8_calibrate_M = &heli_q8_calibrate_M_;
real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void heli_q8_calibrate_output(void)
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  real_T rtb_Step1;
  real_T rtb_Gain2[3];
  real_T rtb_Sqrt;
  real_T rtb_euler_rates[3];
  int32_T i;
  real_T tmp[9];

  /* Memory: '<S7>/Memory' */
  heli_q8_calibrate_B.Memory = heli_q8_calibrate_DW.Memory_PreviousInput;

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/Constant'
   */
  heli_q8_calibrate_B.Divide = heli_q8_calibrate_B.Memory /
    heli_q8_calibrate_P.num_measures;

  /* Memory: '<S8>/Memory' */
  heli_q8_calibrate_B.Memory_a = heli_q8_calibrate_DW.Memory_PreviousInput_p;

  /* Product: '<S8>/Divide' incorporates:
   *  Constant: '<S8>/Constant'
   */
  heli_q8_calibrate_B.Divide_d = heli_q8_calibrate_B.Memory_a /
    heli_q8_calibrate_P.num_measures;

  /* Memory: '<S9>/Memory' */
  heli_q8_calibrate_B.Memory_d = heli_q8_calibrate_DW.Memory_PreviousInput_ps;

  /* Product: '<S9>/Divide' incorporates:
   *  Constant: '<S9>/Constant'
   */
  heli_q8_calibrate_B.Divide_g = heli_q8_calibrate_B.Memory_d /
    heli_q8_calibrate_P.num_measures;

  /* Memory: '<S10>/Memory' */
  heli_q8_calibrate_B.Memory_dh = heli_q8_calibrate_DW.Memory_PreviousInput_l;

  /* Product: '<S10>/Divide' incorporates:
   *  Constant: '<S10>/Constant'
   */
  heli_q8_calibrate_B.Divide_h = heli_q8_calibrate_B.Memory_dh /
    heli_q8_calibrate_P.num_measures;

  /* Memory: '<S11>/Memory' */
  heli_q8_calibrate_B.Memory_k = heli_q8_calibrate_DW.Memory_PreviousInput_i;

  /* Product: '<S11>/Divide' incorporates:
   *  Constant: '<S11>/Constant'
   */
  heli_q8_calibrate_B.Divide_k = heli_q8_calibrate_B.Memory_k /
    heli_q8_calibrate_P.num_measures;

  /* Step: '<S3>/Step' */
  if (heli_q8_calibrate_M->Timing.t[0] < 2.0 *
      heli_q8_calibrate_P.calibrate_time) {
    rtb_Step1 = heli_q8_calibrate_P.Step_Y0;
  } else {
    rtb_Step1 = heli_q8_calibrate_P.Step_YFinal;
  }

  /* End of Step: '<S3>/Step' */

  /* Product: '<S3>/Product' */
  heli_q8_calibrate_B.Product[0] = heli_q8_calibrate_B.Divide * rtb_Step1;
  heli_q8_calibrate_B.Product[1] = heli_q8_calibrate_B.Divide_d * rtb_Step1;
  heli_q8_calibrate_B.Product[2] = heli_q8_calibrate_B.Divide_g * rtb_Step1;
  heli_q8_calibrate_B.Product[3] = heli_q8_calibrate_B.Divide_h * rtb_Step1;
  heli_q8_calibrate_B.Product[4] = heli_q8_calibrate_B.Divide_k * rtb_Step1;

  /* S-Function (stream_call_block): '<S1>/Stream Call1' */

  /* S-Function Block: heli_q8_calibrate/IMU1/Stream Call1 (stream_call_block) */
  {
    t_error result = 0;
    t_boolean close_flag = (heli_q8_calibrate_P.Constant_Value_c != 0);
    rtb_StreamCall1_o1 = NULL;
    switch (heli_q8_calibrate_DW.StreamCall1_State) {
     case STREAM_CALL_STATE_NOT_CONNECTED:
      {
        if (!close_flag) {
          /* Make sure URI is null-terminated */
          if (string_length((char *) heli_q8_calibrate_P.StringConstant_Value,
                            255) == 255) {
            rtmSetErrorStatus(heli_q8_calibrate_M,
                              "URI passed to Stream Call block is not null-terminated!");
            result = -QERR_STRING_NOT_TERMINATED;
          } else {
            result = stream_connect((char *)
              heli_q8_calibrate_P.StringConstant_Value, true,
              heli_q8_calibrate_P.StreamCall1_SendBufferSize,
              heli_q8_calibrate_P.StreamCall1_ReceiveBufferSize,
              &heli_q8_calibrate_DW.StreamCall1_Stream);
            if (result == 0) {
              heli_q8_calibrate_DW.StreamCall1_State =
                STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_calibrate_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_calibrate_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_calibrate_DW.StreamCall1_Stream;
            } else if (result == -QERR_WOULD_BLOCK) {
              heli_q8_calibrate_DW.StreamCall1_State =
                STREAM_CALL_STATE_CONNECTING;
              result = 0;
            }
          }
        }
        break;
      }

     case STREAM_CALL_STATE_CONNECTING:
      {
        if (!close_flag) {
          const t_timeout timeout = { 0, 0, false };/* zero seconds */

          result = stream_poll(heli_q8_calibrate_DW.StreamCall1_Stream, &timeout,
                               STREAM_POLL_CONNECT);
          if (result > 0) {
            heli_q8_calibrate_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
            stream_set_byte_order(heli_q8_calibrate_DW.StreamCall1_Stream,
                                  (t_stream_byte_order)
                                  heli_q8_calibrate_P.StreamCall1_Endian);
            rtb_StreamCall1_o1 = &heli_q8_calibrate_DW.StreamCall1_Stream;
            result = 0;
            break;
          } else if (result == 0) {
            break;
          }
        }

        /* Fall through deliberately */
      }

     case STREAM_CALL_STATE_CONNECTED:
      {
        rtb_StreamCall1_o1 = &heli_q8_calibrate_DW.StreamCall1_Stream;
        if (!close_flag) {
          break;
        }

        /* Fall through deliberately */
      }

     default:
      {
        t_error close_result = stream_close
          (heli_q8_calibrate_DW.StreamCall1_Stream);
        if (close_result == 0) {
          heli_q8_calibrate_DW.StreamCall1_State =
            STREAM_CALL_STATE_NOT_CONNECTED;
          heli_q8_calibrate_DW.StreamCall1_Stream = NULL;
          rtb_StreamCall1_o1 = NULL;
        } else if (result == 0) {
          result = close_result;
        }
        break;
      }
    }

    heli_q8_calibrate_B.StreamCall1_o2 = heli_q8_calibrate_DW.StreamCall1_State;
    rtb_StreamCall1_o3 = (int32_T) result;
  }

  /* S-Function (stream_formatted_write_block): '<S1>/Stream Formatted Write' */
  {
    t_error result;
    if (rtb_StreamCall1_o1 != NULL) {
      result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
        heli_q8_calibrate_P.StreamFormattedWrite_MaxUnits,
        &rtb_StreamFormattedWrite_o2, "%c\n"
        , (char) heli_q8_calibrate_P.Constant1_Value_d
        );
      if (result > 0) {
        result = stream_flush(*rtb_StreamCall1_o1);
      }

      if (result == -QERR_WOULD_BLOCK) {
        result = 0;
      }
    }

    rtb_StreamFormattedWrite_o1 = rtb_StreamCall1_o1;
  }

  /* S-Function (stream_read_block): '<S1>/Stream Read1' */
  /* S-Function Block: heli_q8_calibrate/IMU1/Stream Read1 (stream_read_block) */
  {
    t_error result;
    memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
    if (rtb_StreamFormattedWrite_o1 != NULL) {
      result = stream_receive_unit_array(*rtb_StreamFormattedWrite_o1,
        &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
      rtb_StreamRead1_o3 = (result > 0);
      if (result > 0 || result == -QERR_WOULD_BLOCK) {
        result = 0;
      }
    } else {
      rtb_StreamRead1_o3 = false;
      result = 0;
    }

    rtb_StreamRead1_o5 = (int32_T) result;
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Memory: '<S1>/Memory'
   */
  for (i = 0; i < 10; i++) {
    if (rtb_StreamRead1_o3) {
      heli_q8_calibrate_B.Switch[i] = rtb_StreamRead1_o2[i];
    } else {
      heli_q8_calibrate_B.Switch[i] =
        heli_q8_calibrate_DW.Memory_PreviousInput_c[i];
    }
  }

  /* End of Switch: '<S1>/Switch' */

  /* Gain: '<S1>/Gain2' */
  for (i = 0; i < 3; i++) {
    rtb_Gain2[i] = heli_q8_calibrate_P.Gain2_Gain[i + 6] *
      heli_q8_calibrate_B.Switch[2] + (heli_q8_calibrate_P.Gain2_Gain[i + 3] *
      heli_q8_calibrate_B.Switch[1] + heli_q8_calibrate_P.Gain2_Gain[i] *
      heli_q8_calibrate_B.Switch[0]);
  }

  /* End of Gain: '<S1>/Gain2' */

  /* Switch: '<S13>/Switch1' incorporates:
   *  Constant: '<S13>/Constant1'
   *  Product: '<S13>/Divide'
   *  Trigonometry: '<S13>/atan '
   */
  if (rtb_Gain2[2] != 0.0) {
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant'
     */
    if (rtb_Gain2[2] != 0.0) {
      rtb_Step1 = rtb_Gain2[2];
    } else {
      rtb_Step1 = heli_q8_calibrate_P.Constant_Value_g;
    }

    /* End of Switch: '<S13>/Switch' */
    heli_q8_calibrate_B.Switch1 = atan(rtb_Gain2[1] / rtb_Step1);
  } else {
    heli_q8_calibrate_B.Switch1 = heli_q8_calibrate_P.Constant1_Value;
  }

  /* End of Switch: '<S13>/Switch1' */

  /* Sum: '<S7>/Sum' */
  heli_q8_calibrate_B.Sum = heli_q8_calibrate_B.Memory +
    heli_q8_calibrate_B.Switch1;

  /* Step: '<S7>/Step' */
  if (heli_q8_calibrate_M->Timing.t[0] < heli_q8_calibrate_P.calibrate_time) {
    rtb_Sqrt = heli_q8_calibrate_P.Step_Y0_d;
  } else {
    rtb_Sqrt = heli_q8_calibrate_P.Step_YFinal_d;
  }

  /* End of Step: '<S7>/Step' */

  /* Switch: '<S7>/Switch' */
  if (rtb_Sqrt > heli_q8_calibrate_P.Switch_Threshold) {
    heli_q8_calibrate_B.Switch_j = heli_q8_calibrate_B.Sum;
  } else {
    heli_q8_calibrate_B.Switch_j = heli_q8_calibrate_B.Memory;
  }

  /* End of Switch: '<S7>/Switch' */

  /* Step: '<S8>/Step1' */
  rtb_Step1 = heli_q8_calibrate_M->Timing.t[0];

  /* Sqrt: '<S12>/Sqrt' incorporates:
   *  Math: '<S12>/Math Function'
   *  Math: '<S12>/Math Function1'
   *  Sum: '<S12>/Sum'
   */
  rtb_Sqrt = sqrt(rtb_Gain2[1] * rtb_Gain2[1] + rtb_Gain2[2] * rtb_Gain2[2]);

  /* Switch: '<S12>/Switch1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Trigonometry: '<S12>/atan '
   */
  if (rtb_Sqrt != 0.0) {
    /* Switch: '<S12>/Switch' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (!(rtb_Sqrt != 0.0)) {
      rtb_Sqrt = heli_q8_calibrate_P.Constant_Value;
    }

    /* End of Switch: '<S12>/Switch' */
    heli_q8_calibrate_B.Switch1_o = rt_atan2d_snf(rtb_Gain2[0], rtb_Sqrt);
  } else {
    heli_q8_calibrate_B.Switch1_o = heli_q8_calibrate_P.elevation_offset;
  }

  /* End of Switch: '<S12>/Switch1' */

  /* MATLAB Function: '<S2>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
   *  SignalConversion: '<S4>/TmpSignal ConversionAt SFunction Inport2'
   */
  /* MATLAB Function 'Measurement/Gyro vector to [pitch rate, elevation rate, travle rate]': '<S4>:1' */
  /* '<S4>:1:3' */
  /* '<S4>:1:4' */
  /* psi = euler_angles(3); */
  /* '<S4>:1:8' */
  /* '<S4>:1:11' */
  tmp[0] = 1.0;
  tmp[3] = sin(heli_q8_calibrate_B.Switch1) * tan(heli_q8_calibrate_B.Switch1_o);
  tmp[6] = cos(heli_q8_calibrate_B.Switch1) * tan(heli_q8_calibrate_B.Switch1_o);
  tmp[1] = 0.0;
  tmp[4] = cos(heli_q8_calibrate_B.Switch1);
  tmp[7] = -sin(heli_q8_calibrate_B.Switch1);
  tmp[2] = 0.0;
  tmp[5] = sin(heli_q8_calibrate_B.Switch1) / cos(heli_q8_calibrate_B.Switch1_o);
  tmp[8] = cos(heli_q8_calibrate_B.Switch1) / cos(heli_q8_calibrate_B.Switch1_o);

  /* Gain: '<S1>/Gain1' incorporates:
   *  MATLAB Function: '<S2>/Gyro vector to [pitch rate, elevation rate, travle rate]'
   */
  for (i = 0; i < 3; i++) {
    rtb_Gain2[i] = heli_q8_calibrate_P.Gain1_Gain[i + 6] *
      heli_q8_calibrate_B.Switch[5] + (heli_q8_calibrate_P.Gain1_Gain[i + 3] *
      heli_q8_calibrate_B.Switch[4] + heli_q8_calibrate_P.Gain1_Gain[i] *
      heli_q8_calibrate_B.Switch[3]);
  }

  /* End of Gain: '<S1>/Gain1' */

  /* MATLAB Function: '<S2>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
  for (i = 0; i < 3; i++) {
    rtb_euler_rates[i] = tmp[i + 6] * rtb_Gain2[2] + (tmp[i + 3] * rtb_Gain2[1]
      + tmp[i] * rtb_Gain2[0]);
  }

  /* Sum: '<S8>/Sum' */
  heli_q8_calibrate_B.Sum_b = heli_q8_calibrate_B.Memory_a + rtb_euler_rates[0];

  /* Step: '<S8>/Step' */
  if (heli_q8_calibrate_M->Timing.t[0] < 2.0 *
      heli_q8_calibrate_P.calibrate_time) {
    rtb_Sqrt = heli_q8_calibrate_P.Step_Y0_j;
  } else {
    rtb_Sqrt = heli_q8_calibrate_P.Step_YFinal_m;
  }

  /* End of Step: '<S8>/Step' */

  /* Step: '<S8>/Step1' */
  if (rtb_Step1 < heli_q8_calibrate_P.calibrate_time) {
    rtb_Step1 = heli_q8_calibrate_P.Step1_Y0;
  } else {
    rtb_Step1 = heli_q8_calibrate_P.Step1_YFinal;
  }

  /* Switch: '<S8>/Switch' incorporates:
   *  Sum: '<S8>/Sum1'
   */
  if (rtb_Sqrt - rtb_Step1 > heli_q8_calibrate_P.Switch_Threshold_c) {
    heli_q8_calibrate_B.Switch_d = heli_q8_calibrate_B.Sum_b;
  } else {
    heli_q8_calibrate_B.Switch_d = heli_q8_calibrate_B.Memory_a;
  }

  /* End of Switch: '<S8>/Switch' */

  /* Sum: '<S9>/Sum' incorporates:
   *  Bias: '<S9>/elevation offset'
   */
  heli_q8_calibrate_B.Sum_l = (heli_q8_calibrate_B.Switch1_o +
    -heli_q8_calibrate_P.elevation_offset) + heli_q8_calibrate_B.Memory_d;

  /* Step: '<S9>/Step' */
  if (heli_q8_calibrate_M->Timing.t[0] < heli_q8_calibrate_P.calibrate_time) {
    rtb_Sqrt = heli_q8_calibrate_P.Step_Y0_a;
  } else {
    rtb_Sqrt = heli_q8_calibrate_P.Step_YFinal_k;
  }

  /* End of Step: '<S9>/Step' */

  /* Switch: '<S9>/Switch' */
  if (rtb_Sqrt > heli_q8_calibrate_P.Switch_Threshold_f) {
    heli_q8_calibrate_B.Switch_k = heli_q8_calibrate_B.Sum_l;
  } else {
    heli_q8_calibrate_B.Switch_k = heli_q8_calibrate_B.Memory_d;
  }

  /* End of Switch: '<S9>/Switch' */

  /* Step: '<S10>/Step1' */
  rtb_Step1 = heli_q8_calibrate_M->Timing.t[0];

  /* Sum: '<S10>/Sum' */
  heli_q8_calibrate_B.Sum_k = heli_q8_calibrate_B.Memory_dh + rtb_euler_rates[1];

  /* Step: '<S10>/Step' */
  if (heli_q8_calibrate_M->Timing.t[0] < 2.0 *
      heli_q8_calibrate_P.calibrate_time) {
    rtb_Sqrt = heli_q8_calibrate_P.Step_Y0_b;
  } else {
    rtb_Sqrt = heli_q8_calibrate_P.Step_YFinal_dc;
  }

  /* End of Step: '<S10>/Step' */

  /* Step: '<S10>/Step1' */
  if (rtb_Step1 < heli_q8_calibrate_P.calibrate_time) {
    rtb_Step1 = heli_q8_calibrate_P.Step1_Y0_l;
  } else {
    rtb_Step1 = heli_q8_calibrate_P.Step1_YFinal_j;
  }

  /* Switch: '<S10>/Switch' incorporates:
   *  Sum: '<S10>/Sum1'
   */
  if (rtb_Sqrt - rtb_Step1 > heli_q8_calibrate_P.Switch_Threshold_cu) {
    heli_q8_calibrate_B.Switch_e = heli_q8_calibrate_B.Sum_k;
  } else {
    heli_q8_calibrate_B.Switch_e = heli_q8_calibrate_B.Memory_dh;
  }

  /* End of Switch: '<S10>/Switch' */

  /* Step: '<S11>/Step1' */
  rtb_Step1 = heli_q8_calibrate_M->Timing.t[0];

  /* Sum: '<S11>/Sum' */
  heli_q8_calibrate_B.Sum_a = heli_q8_calibrate_B.Memory_k + rtb_euler_rates[2];

  /* Step: '<S11>/Step' */
  if (heli_q8_calibrate_M->Timing.t[0] < 2.0 *
      heli_q8_calibrate_P.calibrate_time) {
    rtb_Sqrt = heli_q8_calibrate_P.Step_Y0_o;
  } else {
    rtb_Sqrt = heli_q8_calibrate_P.Step_YFinal_m4;
  }

  /* End of Step: '<S11>/Step' */

  /* Step: '<S11>/Step1' */
  if (rtb_Step1 < heli_q8_calibrate_P.calibrate_time) {
    rtb_Step1 = heli_q8_calibrate_P.Step1_Y0_j;
  } else {
    rtb_Step1 = heli_q8_calibrate_P.Step1_YFinal_f;
  }

  /* Switch: '<S11>/Switch' incorporates:
   *  Sum: '<S11>/Sum1'
   */
  if (rtb_Sqrt - rtb_Step1 > heli_q8_calibrate_P.Switch_Threshold_i) {
    heli_q8_calibrate_B.Switch_h = heli_q8_calibrate_B.Sum_a;
  } else {
    heli_q8_calibrate_B.Switch_h = heli_q8_calibrate_B.Memory_k;
  }

  /* End of Switch: '<S11>/Switch' */

  /* S-Function (stop_with_error_block): '<S1>/Stop with Call Error' */

  /* S-Function Block: heli_q8_calibrate/IMU1/Stop with Call Error (stop_with_error_block) */
  {
    if (rtb_StreamCall1_o3 < 0) {
      msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
      return;
    }
  }

  /* S-Function (stop_with_error_block): '<S1>/Stop with Read Error' */

  /* S-Function Block: heli_q8_calibrate/IMU1/Stop with Read Error (stop_with_error_block) */
  {
    if (rtb_StreamRead1_o5 < 0) {
      msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
      return;
    }
  }
}

/* Model update function */
void heli_q8_calibrate_update(void)
{
  /* Update for Memory: '<S7>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput = heli_q8_calibrate_B.Switch_j;

  /* Update for Memory: '<S8>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_p = heli_q8_calibrate_B.Switch_d;

  /* Update for Memory: '<S9>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_ps = heli_q8_calibrate_B.Switch_k;

  /* Update for Memory: '<S10>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_l = heli_q8_calibrate_B.Switch_e;

  /* Update for Memory: '<S11>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_i = heli_q8_calibrate_B.Switch_h;

  /* Update for Memory: '<S1>/Memory' */
  memcpy(&heli_q8_calibrate_DW.Memory_PreviousInput_c[0],
         &heli_q8_calibrate_B.Switch[0], 10U * sizeof(real_T));

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_calibrate_M->Timing.clockTick0)) {
    ++heli_q8_calibrate_M->Timing.clockTickH0;
  }

  heli_q8_calibrate_M->Timing.t[0] = heli_q8_calibrate_M->Timing.clockTick0 *
    heli_q8_calibrate_M->Timing.stepSize0 +
    heli_q8_calibrate_M->Timing.clockTickH0 *
    heli_q8_calibrate_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++heli_q8_calibrate_M->Timing.clockTick1)) {
      ++heli_q8_calibrate_M->Timing.clockTickH1;
    }

    heli_q8_calibrate_M->Timing.t[1] = heli_q8_calibrate_M->Timing.clockTick1 *
      heli_q8_calibrate_M->Timing.stepSize1 +
      heli_q8_calibrate_M->Timing.clockTickH1 *
      heli_q8_calibrate_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void heli_q8_calibrate_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_calibrate/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_calibrate_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (heli_q8_calibrate_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_calibrate_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
      return;
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_calibrate_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] =
            heli_q8_calibrate_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_calibrate_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] =
            heli_q8_calibrate_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (heli_q8_calibrate_DW.HILInitialize_Card,
         heli_q8_calibrate_P.HILInitialize_analog_input_chan, 8U,
         &heli_q8_calibrate_DW.HILInitialize_AIMinimums[0],
         &heli_q8_calibrate_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_calibrate_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] =
            heli_q8_calibrate_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_calibrate_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] =
            heli_q8_calibrate_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (heli_q8_calibrate_DW.HILInitialize_Card,
         heli_q8_calibrate_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_calibrate_DW.HILInitialize_AOMinimums[0],
         &heli_q8_calibrate_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_calibrate_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_calibrate_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_q8_calibrate_DW.HILInitialize_Card,
        heli_q8_calibrate_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_calibrate_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_calibrate_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_calibrate_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_calibrate_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_calibrate_DW.HILInitialize_Card,
         heli_q8_calibrate_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_calibrate_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_calibrate_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_calibrate_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_calibrate_DW.HILInitialize_Card,
         heli_q8_calibrate_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_calibrate_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_calibrate_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            heli_q8_calibrate_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_q8_calibrate_DW.HILInitialize_Card,
        heli_q8_calibrate_P.HILInitialize_encoder_channels, 8U,
        &heli_q8_calibrate_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_calibrate_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_calibrate_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_calibrate_DW.HILInitialize_Card,
        heli_q8_calibrate_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_q8_calibrate_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_calibrate_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &heli_q8_calibrate_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_calibrate_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            heli_q8_calibrate_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = heli_q8_calibrate_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_calibrate_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            heli_q8_calibrate_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              heli_q8_calibrate_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_calibrate_DW.HILInitialize_Card,
          &heli_q8_calibrate_DW.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &heli_q8_calibrate_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_calibrate_DW.HILInitialize_Card,
          &heli_q8_calibrate_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_calibrate_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_calibrate_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            heli_q8_calibrate_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_calibrate_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_calibrate_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_calibrate_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_calibrate_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_calibrate_DW.HILInitialize_Card,
        heli_q8_calibrate_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *)
        &heli_q8_calibrate_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_calibrate_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_calibrate_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_calibrate_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            heli_q8_calibrate_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_calibrate_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_calibrate_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_calibrate_DW.HILInitialize_Card,
        heli_q8_calibrate_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_calibrate_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_calibrate_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_calibrate_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_calibrate_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_calibrate_DW.HILInitialize_Card,
        heli_q8_calibrate_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_calibrate_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_calibrate_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_calibrate_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_calibrate_DW.HILInitialize_Card,
         heli_q8_calibrate_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_calibrate_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (stream_call_block): '<S1>/Stream Call1' */

  /* S-Function Block: heli_q8_calibrate/IMU1/Stream Call1 (stream_call_block) */
  {
    heli_q8_calibrate_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_calibrate_DW.StreamCall1_Stream = NULL;
  }

  /* InitializeConditions for Memory: '<S7>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput = heli_q8_calibrate_P.Memory_X0;

  /* InitializeConditions for Memory: '<S8>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_p = heli_q8_calibrate_P.Memory_X0_k;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_ps = heli_q8_calibrate_P.Memory_X0_f;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_l = heli_q8_calibrate_P.Memory_X0_a;

  /* InitializeConditions for Memory: '<S11>/Memory' */
  heli_q8_calibrate_DW.Memory_PreviousInput_i = heli_q8_calibrate_P.Memory_X0_l;

  /* InitializeConditions for Memory: '<S1>/Memory' */
  memcpy(&heli_q8_calibrate_DW.Memory_PreviousInput_c[0],
         &heli_q8_calibrate_P.Memory_X0_b[0], 10U * sizeof(real_T));
}

/* Model terminate function */
void heli_q8_calibrate_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_calibrate/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_calibrate_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_calibrate_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_calibrate_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_calibrate_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_calibrate_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_calibrate_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_calibrate_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_calibrate_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_calibrate_DW.HILInitialize_Card
                         , heli_q8_calibrate_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_calibrate_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_calibrate_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_calibrate_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (heli_q8_calibrate_DW.HILInitialize_Card,
             heli_q8_calibrate_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &heli_q8_calibrate_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_calibrate_DW.HILInitialize_Card,
            heli_q8_calibrate_P.HILInitialize_pwm_channels,
            num_final_pwm_outputs, &heli_q8_calibrate_DW.HILInitialize_POValues
            [0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_calibrate_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_calibrate_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_calibrate_DW.HILInitialize_Card);
    hil_close(heli_q8_calibrate_DW.HILInitialize_Card);
    heli_q8_calibrate_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S1>/Stream Call1' */

  /* S-Function Block: heli_q8_calibrate/IMU1/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_calibrate_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_calibrate_DW.StreamCall1_Stream);
      heli_q8_calibrate_DW.StreamCall1_Stream = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  heli_q8_calibrate_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  heli_q8_calibrate_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_calibrate_initialize();
}

void MdlTerminate(void)
{
  heli_q8_calibrate_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_calibrate_T *heli_q8_calibrate(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_calibrate_M, 0,
                sizeof(RT_MODEL_heli_q8_calibrate_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_calibrate_M->solverInfo,
                          &heli_q8_calibrate_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_calibrate_M->solverInfo, &rtmGetTPtr
                (heli_q8_calibrate_M));
    rtsiSetStepSizePtr(&heli_q8_calibrate_M->solverInfo,
                       &heli_q8_calibrate_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&heli_q8_calibrate_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_calibrate_M)));
    rtsiSetRTModelPtr(&heli_q8_calibrate_M->solverInfo, heli_q8_calibrate_M);
  }

  rtsiSetSimTimeStep(&heli_q8_calibrate_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&heli_q8_calibrate_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_calibrate_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    heli_q8_calibrate_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_calibrate_M->Timing.sampleTimes =
      (&heli_q8_calibrate_M->Timing.sampleTimesArray[0]);
    heli_q8_calibrate_M->Timing.offsetTimes =
      (&heli_q8_calibrate_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_calibrate_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_calibrate_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    heli_q8_calibrate_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_calibrate_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(heli_q8_calibrate_M, &heli_q8_calibrate_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_calibrate_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    heli_q8_calibrate_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_calibrate_M, -1);
  heli_q8_calibrate_M->Timing.stepSize0 = 0.002;
  heli_q8_calibrate_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  heli_q8_calibrate_M->Sizes.checksums[0] = (787375133U);
  heli_q8_calibrate_M->Sizes.checksums[1] = (4015194536U);
  heli_q8_calibrate_M->Sizes.checksums[2] = (4042632328U);
  heli_q8_calibrate_M->Sizes.checksums[3] = (3469145922U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    heli_q8_calibrate_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_calibrate_M->extModeInfo,
      &heli_q8_calibrate_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_calibrate_M->extModeInfo,
                        heli_q8_calibrate_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_calibrate_M->extModeInfo, rtmGetTPtr(heli_q8_calibrate_M));
  }

  heli_q8_calibrate_M->solverInfoPtr = (&heli_q8_calibrate_M->solverInfo);
  heli_q8_calibrate_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_calibrate_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_calibrate_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  heli_q8_calibrate_M->ModelData.blockIO = ((void *) &heli_q8_calibrate_B);
  (void) memset(((void *) &heli_q8_calibrate_B), 0,
                sizeof(B_heli_q8_calibrate_T));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      heli_q8_calibrate_B.Product[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      heli_q8_calibrate_B.Switch[i] = 0.0;
    }

    heli_q8_calibrate_B.Memory = 0.0;
    heli_q8_calibrate_B.Divide = 0.0;
    heli_q8_calibrate_B.Memory_a = 0.0;
    heli_q8_calibrate_B.Divide_d = 0.0;
    heli_q8_calibrate_B.Memory_d = 0.0;
    heli_q8_calibrate_B.Divide_g = 0.0;
    heli_q8_calibrate_B.Memory_dh = 0.0;
    heli_q8_calibrate_B.Divide_h = 0.0;
    heli_q8_calibrate_B.Memory_k = 0.0;
    heli_q8_calibrate_B.Divide_k = 0.0;
    heli_q8_calibrate_B.Switch1 = 0.0;
    heli_q8_calibrate_B.Sum = 0.0;
    heli_q8_calibrate_B.Switch_j = 0.0;
    heli_q8_calibrate_B.Switch1_o = 0.0;
    heli_q8_calibrate_B.Sum_b = 0.0;
    heli_q8_calibrate_B.Switch_d = 0.0;
    heli_q8_calibrate_B.Sum_l = 0.0;
    heli_q8_calibrate_B.Switch_k = 0.0;
    heli_q8_calibrate_B.Sum_k = 0.0;
    heli_q8_calibrate_B.Switch_e = 0.0;
    heli_q8_calibrate_B.Sum_a = 0.0;
    heli_q8_calibrate_B.Switch_h = 0.0;
  }

  /* parameters */
  heli_q8_calibrate_M->ModelData.defaultParam = ((real_T *)&heli_q8_calibrate_P);

  /* states (dwork) */
  heli_q8_calibrate_M->ModelData.dwork = ((void *) &heli_q8_calibrate_DW);
  (void) memset((void *)&heli_q8_calibrate_DW, 0,
                sizeof(DW_heli_q8_calibrate_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_calibrate_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_calibrate_DW.Memory_PreviousInput = 0.0;
  heli_q8_calibrate_DW.Memory_PreviousInput_p = 0.0;
  heli_q8_calibrate_DW.Memory_PreviousInput_ps = 0.0;
  heli_q8_calibrate_DW.Memory_PreviousInput_l = 0.0;
  heli_q8_calibrate_DW.Memory_PreviousInput_i = 0.0;

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_calibrate_DW.Memory_PreviousInput_c[i] = 0.0;
    }
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_calibrate_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_calibrate_M->Sizes.numContStates = (0);/* Number of continuous states */
  heli_q8_calibrate_M->Sizes.numY = (0);/* Number of model outputs */
  heli_q8_calibrate_M->Sizes.numU = (0);/* Number of model inputs */
  heli_q8_calibrate_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_calibrate_M->Sizes.numSampTimes = (2);/* Number of sample times */
  heli_q8_calibrate_M->Sizes.numBlocks = (84);/* Number of blocks */
  heli_q8_calibrate_M->Sizes.numBlockIO = (25);/* Number of block outputs */
  heli_q8_calibrate_M->Sizes.numBlockPrms = (420);/* Sum of parameter "widths" */
  return heli_q8_calibrate_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
