/*
 * heli_q8_presentation.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_presentation".
 *
 * Model version              : 1.86
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Sat Nov 07 22:42:06 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_presentation.h"
#include "heli_q8_presentation_private.h"
#include "heli_q8_presentation_dt.h"

t_stream heli_q8_presentation_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_q8_presentation_T heli_q8_presentation_B;

/* Continuous states */
X_heli_q8_presentation_T heli_q8_presentation_X;

/* Block states (auto storage) */
DW_heli_q8_presentation_T heli_q8_presentation_DW;

/* Real-time model */
RT_MODEL_heli_q8_presentation_T heli_q8_presentation_M_;
RT_MODEL_heli_q8_presentation_T *const heli_q8_presentation_M =
  &heli_q8_presentation_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_presentation_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_presentation_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_presentation_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_presentation_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_presentation_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_presentation_M->Timing.perTaskSampleHits[5] =
      heli_q8_presentation_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_presentation_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_presentation_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_presentation_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_presentation_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

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

/* Model output function for TID0 */
void heli_q8_presentation_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  real_T rtb_Gain2[3];
  real_T rtb_Sqrt;
  real_T rtb_Sum[5];
  real_T rtb_Switch1;
  real_T rtb_euler_rates[3];
  int32_T i;
  real_T tmp[7];
  real_T tmp_0[9];
  real_T tmp_1[5];
  real_T tmp_2[5];
  int32_T i_0;
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* set solver stop time */
    if (!(heli_q8_presentation_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_presentation_M->solverInfo,
                            ((heli_q8_presentation_M->Timing.clockTickH0 + 1) *
        heli_q8_presentation_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_presentation_M->solverInfo,
                            ((heli_q8_presentation_M->Timing.clockTick0 + 1) *
        heli_q8_presentation_M->Timing.stepSize0 +
        heli_q8_presentation_M->Timing.clockTickH0 *
        heli_q8_presentation_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_presentation_M)) {
    heli_q8_presentation_M->Timing.t[0] = rtsiGetT
      (&heli_q8_presentation_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S9>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_presentation/Heli 3D/Subsystem/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_presentation_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_presentation_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_presentation_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_presentation_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          heli_q8_presentation_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* RateTransition: '<S3>/Rate Transition: x' */
    if (heli_q8_presentation_M->Timing.RateInteraction.TID1_2) {
      heli_q8_presentation_B.RateTransitionx =
        heli_q8_presentation_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: x' */

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (heli_q8_presentation_B.RateTransitionx >
        heli_q8_presentation_P.DeadZonex_End) {
      rtb_Switch1 = heli_q8_presentation_B.RateTransitionx -
        heli_q8_presentation_P.DeadZonex_End;
    } else if (heli_q8_presentation_B.RateTransitionx >=
               heli_q8_presentation_P.DeadZonex_Start) {
      rtb_Switch1 = 0.0;
    } else {
      rtb_Switch1 = heli_q8_presentation_B.RateTransitionx -
        heli_q8_presentation_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    heli_q8_presentation_B.Joystick_gain_x = heli_q8_presentation_P.Gainx_Gain *
      rtb_Switch1 * heli_q8_presentation_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (heli_q8_presentation_M->Timing.RateInteraction.TID1_2) {
      heli_q8_presentation_B.RateTransitiony =
        heli_q8_presentation_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (heli_q8_presentation_B.RateTransitiony >
        heli_q8_presentation_P.DeadZoney_End) {
      rtb_Switch1 = heli_q8_presentation_B.RateTransitiony -
        heli_q8_presentation_P.DeadZoney_End;
    } else if (heli_q8_presentation_B.RateTransitiony >=
               heli_q8_presentation_P.DeadZoney_Start) {
      rtb_Switch1 = 0.0;
    } else {
      rtb_Switch1 = heli_q8_presentation_B.RateTransitiony -
        heli_q8_presentation_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    heli_q8_presentation_B.Joystick_gain_y = heli_q8_presentation_P.Gainy_Gain *
      rtb_Switch1 * heli_q8_presentation_P.Joystick_gain_y;

    /* Gain: '<S4>/Gain1' incorporates:
     *  SignalConversion: '<S4>/TmpSignal ConversionAtGain1Inport1'
     */
    heli_q8_presentation_B.Gain1[0] = 0.0;
    heli_q8_presentation_B.Gain1[0] += heli_q8_presentation_P.F[0] *
      heli_q8_presentation_B.Joystick_gain_x;
    heli_q8_presentation_B.Gain1[0] += heli_q8_presentation_P.F[2] *
      heli_q8_presentation_B.Joystick_gain_y;
    heli_q8_presentation_B.Gain1[1] = 0.0;
    heli_q8_presentation_B.Gain1[1] += heli_q8_presentation_P.F[1] *
      heli_q8_presentation_B.Joystick_gain_x;
    heli_q8_presentation_B.Gain1[1] += heli_q8_presentation_P.F[3] *
      heli_q8_presentation_B.Joystick_gain_y;
  }

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Integrator: '<S15>/Integrator'
   *  Integrator: '<S15>/Integrator1'
   *  Integrator: '<S5>/Integrator'
   */
  for (i = 0; i < 5; i++) {
    tmp[i] = heli_q8_presentation_X.Integrator_CSTATE[i];
  }

  tmp[5] = heli_q8_presentation_X.Integrator1_CSTATE;
  tmp[6] = heli_q8_presentation_X.Integrator_CSTATE_m;

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/Gain'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtGainInport1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Switch1 = 0.0;
    for (i_0 = 0; i_0 < 7; i_0++) {
      rtb_Switch1 += heli_q8_presentation_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    heli_q8_presentation_B.Sum[i] = heli_q8_presentation_B.Gain1[i] -
      rtb_Switch1;
  }

  /* End of Sum: '<S4>/Sum' */
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* Constant: '<S4>/V_s0' */
    heli_q8_presentation_B.V_s0 = heli_q8_presentation_P.V_s0;
  }

  /* Sum: '<S4>/Sum1' */
  heli_q8_presentation_B.Sum1 = heli_q8_presentation_B.V_s0 +
    heli_q8_presentation_B.Sum[0];
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* S-Function (stream_call_block): '<S6>/Stream Call1' */

    /* S-Function Block: heli_q8_presentation/Heli 3D/IMU1/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_presentation_P.Constant_Value_c != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_presentation_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *)
                              heli_q8_presentation_P.StringConstant_Value, 255) ==
                255) {
              rtmSetErrorStatus(heli_q8_presentation_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_presentation_P.StringConstant_Value, true,
                heli_q8_presentation_P.StreamCall1_SendBufferSize,
                heli_q8_presentation_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_presentation_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_presentation_DW.StreamCall1_State =
                  STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_presentation_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_presentation_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_presentation_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_presentation_DW.StreamCall1_State =
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

            result = stream_poll(heli_q8_presentation_DW.StreamCall1_Stream,
                                 &timeout, STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_presentation_DW.StreamCall1_State =
                STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_presentation_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_presentation_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_presentation_DW.StreamCall1_Stream;
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
          rtb_StreamCall1_o1 = &heli_q8_presentation_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close
            (heli_q8_presentation_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_presentation_DW.StreamCall1_State =
              STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_presentation_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_presentation_B.StreamCall1_o2 =
        heli_q8_presentation_DW.StreamCall1_State;
      rtb_StreamRead1_o5 = (int32_T) result;
    }

    /* S-Function (stop_with_error_block): '<S6>/Stop with Call Error' */

    /* S-Function Block: heli_q8_presentation/Heli 3D/IMU1/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stream_formatted_write_block): '<S6>/Stream Formatted Write' */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_presentation_P.StreamFormattedWrite_MaxUnits,
          &rtb_StreamFormattedWrite_o2, "%c\n"
          , (char) heli_q8_presentation_P.Constant1_Value_d
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

    /* S-Function (stream_read_block): '<S6>/Stream Read1' */
    /* S-Function Block: heli_q8_presentation/Heli 3D/IMU1/Stream Read1 (stream_read_block) */
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

    /* S-Function (stop_with_error_block): '<S6>/Stop with Read Error' */

    /* S-Function Block: heli_q8_presentation/Heli 3D/IMU1/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    /* Switch: '<S6>/Switch' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Memory: '<S6>/Memory'
     */
    for (i = 0; i < 10; i++) {
      if (rtb_StreamRead1_o3) {
        heli_q8_presentation_B.Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        heli_q8_presentation_B.Switch[i] =
          heli_q8_presentation_DW.Memory_PreviousInput[i];
      }
    }

    /* End of Switch: '<S6>/Switch' */

    /* Gain: '<S6>/Gain2' */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = heli_q8_presentation_P.Gain2_Gain[i + 6] *
        heli_q8_presentation_B.Switch[2] + (heli_q8_presentation_P.Gain2_Gain[i
        + 3] * heli_q8_presentation_B.Switch[1] +
        heli_q8_presentation_P.Gain2_Gain[i] * heli_q8_presentation_B.Switch[0]);
    }

    /* End of Gain: '<S6>/Gain2' */

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Product: '<S14>/Divide'
     *  Trigonometry: '<S14>/atan '
     */
    if (rtb_Gain2[2] != 0.0) {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S14>/Constant'
       */
      if (rtb_Gain2[2] != 0.0) {
        rtb_Switch1 = rtb_Gain2[2];
      } else {
        rtb_Switch1 = heli_q8_presentation_P.Constant_Value_g;
      }

      /* End of Switch: '<S14>/Switch' */
      rtb_Switch1 = atan(rtb_Gain2[1] / rtb_Switch1);
    } else {
      rtb_Switch1 = heli_q8_presentation_P.Constant1_Value_c;
    }

    /* End of Switch: '<S14>/Switch1' */

    /* Sqrt: '<S13>/Sqrt' incorporates:
     *  Math: '<S13>/Math Function'
     *  Math: '<S13>/Math Function1'
     *  Sum: '<S13>/Sum'
     */
    rtb_Sqrt = sqrt(rtb_Gain2[1] * rtb_Gain2[1] + rtb_Gain2[2] * rtb_Gain2[2]);

    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant1'
     *  Trigonometry: '<S13>/atan '
     */
    if (rtb_Sqrt != 0.0) {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant'
       */
      if (!(rtb_Sqrt != 0.0)) {
        rtb_Sqrt = heli_q8_presentation_P.Constant_Value;
      }

      /* End of Switch: '<S13>/Switch' */
      rtb_Sqrt = rt_atan2d_snf(rtb_Gain2[0], rtb_Sqrt);
    } else {
      rtb_Sqrt = heli_q8_presentation_P.Constant1_Value;
    }

    /* End of Switch: '<S13>/Switch1' */

    /* Sum: '<S13>/Sum1' incorporates:
     *  Constant: '<S13>/Constant2'
     */
    rtb_Sqrt -= heli_q8_presentation_P.Constant2_Value;

    /* MATLAB Function: '<S7>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'Heli 3D/Measurement/Gyro vector to [pitch rate, elevation rate, travle rate]': '<S10>:1' */
    /* '<S10>:1:3' */
    /* '<S10>:1:4' */
    /* psi = euler_angles(3); */
    /* '<S10>:1:8' */
    /* '<S10>:1:11' */
    tmp_0[0] = 1.0;
    tmp_0[3] = sin(rtb_Switch1) * tan(rtb_Sqrt);
    tmp_0[6] = cos(rtb_Switch1) * tan(rtb_Sqrt);
    tmp_0[1] = 0.0;
    tmp_0[4] = cos(rtb_Switch1);
    tmp_0[7] = -sin(rtb_Switch1);
    tmp_0[2] = 0.0;
    tmp_0[5] = sin(rtb_Switch1) / cos(rtb_Sqrt);
    tmp_0[8] = cos(rtb_Switch1) / cos(rtb_Sqrt);

    /* Gain: '<S6>/Gain1' incorporates:
     *  MATLAB Function: '<S7>/Gyro vector to [pitch rate, elevation rate, travle rate]'
     */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = heli_q8_presentation_P.Gain1_Gain[i + 6] *
        heli_q8_presentation_B.Switch[5] + (heli_q8_presentation_P.Gain1_Gain[i
        + 3] * heli_q8_presentation_B.Switch[4] +
        heli_q8_presentation_P.Gain1_Gain[i] * heli_q8_presentation_B.Switch[3]);
    }

    /* End of Gain: '<S6>/Gain1' */

    /* MATLAB Function: '<S7>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    for (i = 0; i < 3; i++) {
      rtb_euler_rates[i] = tmp_0[i + 6] * rtb_Gain2[2] + (tmp_0[i + 3] *
        rtb_Gain2[1] + tmp_0[i] * rtb_Gain2[0]);
    }

    /* Sum: '<S7>/Sum' incorporates:
     *  Constant: '<S7>/Constant'
     */
    rtb_Sum[0] = rtb_Switch1 + heli_q8_presentation_P.imu_offset[0];
    rtb_Sum[1] = rtb_euler_rates[0] + heli_q8_presentation_P.imu_offset[1];
    rtb_Sum[2] = rtb_Sqrt + heli_q8_presentation_P.imu_offset[2];
    rtb_Sum[3] = rtb_euler_rates[1] + heli_q8_presentation_P.imu_offset[3];
    rtb_Sum[4] = rtb_euler_rates[2] + heli_q8_presentation_P.imu_offset[4];
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Switch1 = (heli_q8_presentation_B.Sum1 - heli_q8_presentation_B.Sum[1]) *
    heli_q8_presentation_P.Frontgain_Gain;

  /* Saturate: '<S8>/Front motor: Saturation' */
  if (rtb_Switch1 > heli_q8_presentation_P.FrontmotorSaturation_UpperSat) {
    heli_q8_presentation_B.FrontmotorSaturation =
      heli_q8_presentation_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Switch1 < heli_q8_presentation_P.FrontmotorSaturation_LowerSat)
  {
    heli_q8_presentation_B.FrontmotorSaturation =
      heli_q8_presentation_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_presentation_B.FrontmotorSaturation = rtb_Switch1;
  }

  /* End of Saturate: '<S8>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Switch1 = (heli_q8_presentation_B.Sum1 + heli_q8_presentation_B.Sum[1]) *
    heli_q8_presentation_P.Backgain_Gain;

  /* Saturate: '<S8>/Back motor: Saturation' */
  if (rtb_Switch1 > heli_q8_presentation_P.BackmotorSaturation_UpperSat) {
    heli_q8_presentation_B.BackmotorSaturation =
      heli_q8_presentation_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Switch1 < heli_q8_presentation_P.BackmotorSaturation_LowerSat)
  {
    heli_q8_presentation_B.BackmotorSaturation =
      heli_q8_presentation_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_presentation_B.BackmotorSaturation = rtb_Switch1;
  }

  /* End of Saturate: '<S8>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* S-Function (hil_write_analog_block): '<S8>/HIL Write Analog' */

    /* S-Function Block: heli_q8_presentation/Heli 3D/Motor driver/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_presentation_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_presentation_B.FrontmotorSaturation;
      heli_q8_presentation_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_presentation_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_presentation_DW.HILInitialize_Card,
        heli_q8_presentation_P.HILWriteAnalog_channels, 2,
        &heli_q8_presentation_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
      }
    }

    /* Gain: '<S9>/Elevation: Count to rad' */
    heli_q8_presentation_B.ElevationCounttorad =
      heli_q8_presentation_P.ElevationCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o3;
  }

  /* TransferFcn: '<S9>/Elevation: Transfer Fcn' */
  heli_q8_presentation_B.ElevationTransferFcn = 0.0;
  heli_q8_presentation_B.ElevationTransferFcn +=
    heli_q8_presentation_P.ElevationTransferFcn_C *
    heli_q8_presentation_X.ElevationTransferFcn_CSTATE;
  heli_q8_presentation_B.ElevationTransferFcn +=
    heli_q8_presentation_P.ElevationTransferFcn_D *
    heli_q8_presentation_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S9>/Constant'
     */
    heli_q8_presentation_B.Sum_j = heli_q8_presentation_B.ElevationCounttorad -
      heli_q8_presentation_P.Constant_Value_f;

    /* Gain: '<S9>/Pitch: Count to rad' */
    heli_q8_presentation_B.PitchCounttorad =
      heli_q8_presentation_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;
  }

  /* TransferFcn: '<S9>/Pitch: Transfer Fcn' */
  heli_q8_presentation_B.PitchTransferFcn = 0.0;
  heli_q8_presentation_B.PitchTransferFcn +=
    heli_q8_presentation_P.PitchTransferFcn_C *
    heli_q8_presentation_X.PitchTransferFcn_CSTATE;
  heli_q8_presentation_B.PitchTransferFcn +=
    heli_q8_presentation_P.PitchTransferFcn_D *
    heli_q8_presentation_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* Gain: '<S9>/Travel: Count to rad' */
    heli_q8_presentation_B.TravelCounttorad =
      heli_q8_presentation_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S9>/Travel: Transfer Fcn' */
  heli_q8_presentation_B.TravelTransferFcn = 0.0;
  heli_q8_presentation_B.TravelTransferFcn +=
    heli_q8_presentation_P.TravelTransferFcn_C *
    heli_q8_presentation_X.TravelTransferFcn_CSTATE;
  heli_q8_presentation_B.TravelTransferFcn +=
    heli_q8_presentation_P.TravelTransferFcn_D *
    heli_q8_presentation_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* Gain: '<S5>/Gain4' */
    for (i = 0; i < 5; i++) {
      heli_q8_presentation_B.Gain4[i] = 0.0;
      for (i_0 = 0; i_0 < 5; i_0++) {
        heli_q8_presentation_B.Gain4[i] += heli_q8_presentation_P.C[5 * i_0 + i]
          * rtb_Sum[i_0];
      }
    }

    /* End of Gain: '<S5>/Gain4' */
  }

  /* Sum: '<S15>/Sum' incorporates:
   *  Integrator: '<S5>/Integrator'
   */
  heli_q8_presentation_B.Sum_n = heli_q8_presentation_X.Integrator_CSTATE[3] -
    heli_q8_presentation_B.Joystick_gain_y;

  /* Sum: '<S15>/Sum1' incorporates:
   *  Integrator: '<S5>/Integrator'
   */
  heli_q8_presentation_B.Sum1_h = heli_q8_presentation_X.Integrator_CSTATE[0] -
    heli_q8_presentation_B.Joystick_gain_x;
  for (i = 0; i < 5; i++) {
    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain1'
     *  Integrator: '<S5>/Integrator'
     */
    rtb_Switch1 = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_Switch1 += heli_q8_presentation_P.C[5 * i_0 + i] *
        heli_q8_presentation_X.Integrator_CSTATE[i_0];
    }

    rtb_Sum[i] = heli_q8_presentation_B.Gain4[i] - rtb_Switch1;

    /* End of Sum: '<S5>/Sum' */

    /* Gain: '<S5>/Gain2' incorporates:
     *  Integrator: '<S5>/Integrator'
     *  Sum: '<S5>/Sum1'
     */
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp_1[i] += heli_q8_presentation_P.A[5 * i_0 + i] *
        heli_q8_presentation_X.Integrator_CSTATE[i_0];
    }

    /* End of Gain: '<S5>/Gain2' */
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtGain3Inport1' incorporates:
   *  Bias: '<S5>/Bias'
   */
  rtb_Switch1 = heli_q8_presentation_B.Sum1 + -heli_q8_presentation_P.V_s0;
  for (i = 0; i < 5; i++) {
    /* Gain: '<S5>/Gain' incorporates:
     *  Sum: '<S5>/Sum1'
     */
    tmp_2[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp_2[i] += heli_q8_presentation_P.L[5 * i_0 + i] * rtb_Sum[i_0];
    }

    /* Sum: '<S5>/Sum1' incorporates:
     *  Gain: '<S5>/Gain3'
     *  SignalConversion: '<S5>/TmpSignal ConversionAtGain3Inport1'
     */
    heli_q8_presentation_B.Sum1_e[i] = (heli_q8_presentation_P.B[i + 5] *
      heli_q8_presentation_B.Sum[1] + heli_q8_presentation_P.B[i] * rtb_Switch1)
      + (tmp_1[i] + tmp_2[i]);
  }
}

/* Model update function for TID0 */
void heli_q8_presentation_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    /* Update for Memory: '<S6>/Memory' */
    memcpy(&heli_q8_presentation_DW.Memory_PreviousInput[0],
           &heli_q8_presentation_B.Switch[0], 10U * sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_presentation_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_presentation_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_presentation_M->Timing.clockTick0)) {
    ++heli_q8_presentation_M->Timing.clockTickH0;
  }

  heli_q8_presentation_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_presentation_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_presentation_M->Timing.clockTick1)) {
    ++heli_q8_presentation_M->Timing.clockTickH1;
  }

  heli_q8_presentation_M->Timing.t[1] =
    heli_q8_presentation_M->Timing.clockTick1 *
    heli_q8_presentation_M->Timing.stepSize1 +
    heli_q8_presentation_M->Timing.clockTickH1 *
    heli_q8_presentation_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_presentation_derivatives(void)
{
  int32_T i;
  XDot_heli_q8_presentation_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_presentation_T *)
             heli_q8_presentation_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S5>/Integrator' */
  for (i = 0; i < 5; i++) {
    _rtXdot->Integrator_CSTATE[i] = heli_q8_presentation_B.Sum1_e[i];
  }

  /* End of Derivatives for Integrator: '<S5>/Integrator' */

  /* Derivatives for Integrator: '<S15>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_presentation_B.Sum1_h;

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = heli_q8_presentation_B.Sum_n;

  /* Derivatives for TransferFcn: '<S9>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    heli_q8_presentation_P.ElevationTransferFcn_A *
    heli_q8_presentation_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    heli_q8_presentation_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S9>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_presentation_P.PitchTransferFcn_A *
    heli_q8_presentation_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_presentation_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S9>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE +=
    heli_q8_presentation_P.TravelTransferFcn_A *
    heli_q8_presentation_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_presentation_B.TravelCounttorad;
}

/* Model output function for TID2 */
void heli_q8_presentation_output2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_presentation/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_presentation_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (heli_q8_presentation_DW.GameController_Controller, &state, &new_data);
      if (result == 0) {
        heli_q8_presentation_B.GameController_o4 = state.x;
        heli_q8_presentation_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_presentation_B.GameController_o4 = 0;
      heli_q8_presentation_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_presentation_update2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  heli_q8_presentation_DW.RateTransitionx_Buffer0 =
    heli_q8_presentation_B.GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  heli_q8_presentation_DW.RateTransitiony_Buffer0 =
    heli_q8_presentation_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_presentation_M->Timing.clockTick2)) {
    ++heli_q8_presentation_M->Timing.clockTickH2;
  }

  heli_q8_presentation_M->Timing.t[2] =
    heli_q8_presentation_M->Timing.clockTick2 *
    heli_q8_presentation_M->Timing.stepSize2 +
    heli_q8_presentation_M->Timing.clockTickH2 *
    heli_q8_presentation_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_presentation_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_presentation_output0();
    break;

   case 2 :
    heli_q8_presentation_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_presentation_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_presentation_update0();
    break;

   case 2 :
    heli_q8_presentation_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_presentation_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_presentation/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_presentation_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (heli_q8_presentation_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_presentation_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
      return;
    }

    if ((heli_q8_presentation_P.HILInitialize_set_analog_input_ && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_analog_inpu_m &&
            is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &heli_q8_presentation_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] =
            heli_q8_presentation_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &heli_q8_presentation_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] =
            heli_q8_presentation_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (heli_q8_presentation_DW.HILInitialize_Card,
         heli_q8_presentation_P.HILInitialize_analog_input_chan, 8U,
         &heli_q8_presentation_DW.HILInitialize_AIMinimums[0],
         &heli_q8_presentation_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_presentation_P.HILInitialize_set_analog_output && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_analog_outp_b &&
            is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &heli_q8_presentation_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] =
            heli_q8_presentation_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &heli_q8_presentation_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] =
            heli_q8_presentation_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (heli_q8_presentation_DW.HILInitialize_Card,
         heli_q8_presentation_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_presentation_DW.HILInitialize_AOMinimums[0],
         &heli_q8_presentation_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_presentation_P.HILInitialize_set_analog_outp_e && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_analog_outp_j &&
            is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &heli_q8_presentation_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_presentation_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_q8_presentation_DW.HILInitialize_Card,
        heli_q8_presentation_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_presentation_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_presentation_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &heli_q8_presentation_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_presentation_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_presentation_DW.HILInitialize_Card,
         heli_q8_presentation_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_presentation_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_presentation_P.HILInitialize_set_encoder_param && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_encoder_par_m &&
            is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_presentation_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            heli_q8_presentation_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_presentation_DW.HILInitialize_Card,
         heli_q8_presentation_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_presentation_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_presentation_P.HILInitialize_set_encoder_count && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_encoder_cou_k &&
            is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_presentation_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            heli_q8_presentation_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_q8_presentation_DW.HILInitialize_Card,
        heli_q8_presentation_P.HILInitialize_encoder_channels, 8U,
        &heli_q8_presentation_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_presentation_P.HILInitialize_set_pwm_params_at && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_pwm_params__f &&
            is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_presentation_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_presentation_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_presentation_DW.HILInitialize_Card,
        heli_q8_presentation_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_q8_presentation_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_presentation_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &heli_q8_presentation_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_presentation_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            heli_q8_presentation_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = heli_q8_presentation_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_presentation_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            heli_q8_presentation_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              heli_q8_presentation_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (heli_q8_presentation_DW.HILInitialize_Card,
           &heli_q8_presentation_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &heli_q8_presentation_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (heli_q8_presentation_DW.HILInitialize_Card,
           &heli_q8_presentation_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &heli_q8_presentation_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &heli_q8_presentation_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            heli_q8_presentation_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_presentation_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            heli_q8_presentation_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_presentation_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            heli_q8_presentation_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration
        (heli_q8_presentation_DW.HILInitialize_Card,
         heli_q8_presentation_P.HILInitialize_pwm_channels, 8U,
         (t_pwm_configuration *)
         &heli_q8_presentation_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &heli_q8_presentation_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &heli_q8_presentation_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_presentation_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            heli_q8_presentation_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_presentation_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_presentation_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_presentation_DW.HILInitialize_Card,
        heli_q8_presentation_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_presentation_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_presentation_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_presentation_P.HILInitialize_set_pwm_outputs_a && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_pwm_outputs_g &&
            is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_presentation_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_presentation_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_presentation_DW.HILInitialize_Card,
        heli_q8_presentation_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_presentation_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_presentation_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_presentation_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_presentation_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_presentation_DW.HILInitialize_Card,
         heli_q8_presentation_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_presentation_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S9>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_presentation/Heli 3D/Subsystem/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (heli_q8_presentation_DW.HILInitialize_Card,
       heli_q8_presentation_P.HILReadEncoderTimebase_samples_,
       heli_q8_presentation_P.HILReadEncoderTimebase_channels, 3,
       &heli_q8_presentation_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  heli_q8_presentation_B.RateTransitionx =
    heli_q8_presentation_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  heli_q8_presentation_B.RateTransitiony =
    heli_q8_presentation_P.RateTransitiony_X0;

  /* Start for S-Function (stream_call_block): '<S6>/Stream Call1' */

  /* S-Function Block: heli_q8_presentation/Heli 3D/IMU1/Stream Call1 (stream_call_block) */
  {
    heli_q8_presentation_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_presentation_DW.StreamCall1_Stream = NULL;
  }

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_presentation/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_presentation_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (heli_q8_presentation_P.GameController_ControllerNumber,
         heli_q8_presentation_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_presentation_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_presentation_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    heli_q8_presentation_DW.RateTransitionx_Buffer0 =
      heli_q8_presentation_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    heli_q8_presentation_DW.RateTransitiony_Buffer0 =
      heli_q8_presentation_P.RateTransitiony_X0;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    for (i = 0; i < 5; i++) {
      heli_q8_presentation_X.Integrator_CSTATE[i] =
        heli_q8_presentation_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S5>/Integrator' */

    /* InitializeConditions for Integrator: '<S15>/Integrator1' */
    heli_q8_presentation_X.Integrator1_CSTATE =
      heli_q8_presentation_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S15>/Integrator' */
    heli_q8_presentation_X.Integrator_CSTATE_m =
      heli_q8_presentation_P.Integrator_IC_b;

    /* InitializeConditions for Memory: '<S6>/Memory' */
    memcpy(&heli_q8_presentation_DW.Memory_PreviousInput[0],
           &heli_q8_presentation_P.Memory_X0[0], 10U * sizeof(real_T));

    /* InitializeConditions for TransferFcn: '<S9>/Elevation: Transfer Fcn' */
    heli_q8_presentation_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S9>/Pitch: Transfer Fcn' */
    heli_q8_presentation_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S9>/Travel: Transfer Fcn' */
    heli_q8_presentation_X.TravelTransferFcn_CSTATE = 0.0;
  }
}

/* Model terminate function */
void heli_q8_presentation_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_presentation/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_presentation_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_presentation_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_presentation_P.HILInitialize_set_analog_out_ex && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_analog_outp_c &&
            is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &heli_q8_presentation_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            heli_q8_presentation_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_presentation_P.HILInitialize_set_pwm_output_ap && !is_switching)
        || (heli_q8_presentation_P.HILInitialize_set_pwm_outputs_p &&
            is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_presentation_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            heli_q8_presentation_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_presentation_DW.HILInitialize_Card
                         ,
                         heli_q8_presentation_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_presentation_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_presentation_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_presentation_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (heli_q8_presentation_DW.HILInitialize_Card,
             heli_q8_presentation_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &heli_q8_presentation_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (heli_q8_presentation_DW.HILInitialize_Card,
             heli_q8_presentation_P.HILInitialize_pwm_channels,
             num_final_pwm_outputs,
             &heli_q8_presentation_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_presentation_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_presentation_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_presentation_DW.HILInitialize_Card);
    hil_close(heli_q8_presentation_DW.HILInitialize_Card);
    heli_q8_presentation_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S6>/Stream Call1' */

  /* S-Function Block: heli_q8_presentation/Heli 3D/IMU1/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_presentation_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_presentation_DW.StreamCall1_Stream);
      heli_q8_presentation_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_presentation/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_presentation_P.GameController_Enabled) {
      game_controller_close(heli_q8_presentation_DW.GameController_Controller);
      heli_q8_presentation_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_presentation_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_presentation_update(tid);
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
  heli_q8_presentation_initialize();
}

void MdlTerminate(void)
{
  heli_q8_presentation_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_presentation_T *heli_q8_presentation(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_presentation_M, 0,
                sizeof(RT_MODEL_heli_q8_presentation_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_presentation_M->solverInfo,
                          &heli_q8_presentation_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_presentation_M->solverInfo, &rtmGetTPtr
                (heli_q8_presentation_M));
    rtsiSetStepSizePtr(&heli_q8_presentation_M->solverInfo,
                       &heli_q8_presentation_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_presentation_M->solverInfo,
                 &heli_q8_presentation_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_presentation_M->solverInfo, (real_T **)
                         &heli_q8_presentation_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_presentation_M->solverInfo,
      &heli_q8_presentation_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_presentation_M->solverInfo,
      &heli_q8_presentation_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_presentation_M->solverInfo,
      &heli_q8_presentation_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_presentation_M->solverInfo,
      &heli_q8_presentation_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_presentation_M->solverInfo,
                          (&rtmGetErrorStatus(heli_q8_presentation_M)));
    rtsiSetRTModelPtr(&heli_q8_presentation_M->solverInfo,
                      heli_q8_presentation_M);
  }

  rtsiSetSimTimeStep(&heli_q8_presentation_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_presentation_M->ModelData.intgData.f[0] =
    heli_q8_presentation_M->ModelData.odeF[0];
  heli_q8_presentation_M->ModelData.contStates = ((real_T *)
    &heli_q8_presentation_X);
  rtsiSetSolverData(&heli_q8_presentation_M->solverInfo, (void *)
                    &heli_q8_presentation_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_presentation_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_presentation_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_presentation_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_presentation_M->Timing.sampleTimes =
      (&heli_q8_presentation_M->Timing.sampleTimesArray[0]);
    heli_q8_presentation_M->Timing.offsetTimes =
      (&heli_q8_presentation_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_presentation_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_presentation_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_presentation_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_presentation_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_presentation_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_presentation_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_presentation_M, &heli_q8_presentation_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_presentation_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      heli_q8_presentation_M->Timing.perTaskSampleHitsArray;
    heli_q8_presentation_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_presentation_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_presentation_M, -1);
  heli_q8_presentation_M->Timing.stepSize0 = 0.002;
  heli_q8_presentation_M->Timing.stepSize1 = 0.002;
  heli_q8_presentation_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_presentation_M->Sizes.checksums[0] = (1306831641U);
  heli_q8_presentation_M->Sizes.checksums[1] = (2532077358U);
  heli_q8_presentation_M->Sizes.checksums[2] = (3873529359U);
  heli_q8_presentation_M->Sizes.checksums[3] = (4278721867U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    heli_q8_presentation_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(heli_q8_presentation_M->extModeInfo,
      &heli_q8_presentation_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_presentation_M->extModeInfo,
                        heli_q8_presentation_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_presentation_M->extModeInfo, rtmGetTPtr
                (heli_q8_presentation_M));
  }

  heli_q8_presentation_M->solverInfoPtr = (&heli_q8_presentation_M->solverInfo);
  heli_q8_presentation_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_presentation_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_presentation_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_presentation_M->ModelData.blockIO = ((void *) &heli_q8_presentation_B);
  (void) memset(((void *) &heli_q8_presentation_B), 0,
                sizeof(B_heli_q8_presentation_T));

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_presentation_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      heli_q8_presentation_B.Gain4[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      heli_q8_presentation_B.Sum1_e[i] = 0.0;
    }

    heli_q8_presentation_B.RateTransitionx = 0.0;
    heli_q8_presentation_B.Joystick_gain_x = 0.0;
    heli_q8_presentation_B.RateTransitiony = 0.0;
    heli_q8_presentation_B.Joystick_gain_y = 0.0;
    heli_q8_presentation_B.Gain1[0] = 0.0;
    heli_q8_presentation_B.Gain1[1] = 0.0;
    heli_q8_presentation_B.Sum[0] = 0.0;
    heli_q8_presentation_B.Sum[1] = 0.0;
    heli_q8_presentation_B.V_s0 = 0.0;
    heli_q8_presentation_B.Sum1 = 0.0;
    heli_q8_presentation_B.FrontmotorSaturation = 0.0;
    heli_q8_presentation_B.BackmotorSaturation = 0.0;
    heli_q8_presentation_B.ElevationCounttorad = 0.0;
    heli_q8_presentation_B.ElevationTransferFcn = 0.0;
    heli_q8_presentation_B.Sum_j = 0.0;
    heli_q8_presentation_B.PitchCounttorad = 0.0;
    heli_q8_presentation_B.PitchTransferFcn = 0.0;
    heli_q8_presentation_B.TravelCounttorad = 0.0;
    heli_q8_presentation_B.TravelTransferFcn = 0.0;
    heli_q8_presentation_B.GameController_o4 = 0.0;
    heli_q8_presentation_B.GameController_o5 = 0.0;
    heli_q8_presentation_B.Sum_n = 0.0;
    heli_q8_presentation_B.Sum1_h = 0.0;
  }

  /* parameters */
  heli_q8_presentation_M->ModelData.defaultParam = ((real_T *)
    &heli_q8_presentation_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_presentation_X;
    heli_q8_presentation_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_presentation_X, 0,
                  sizeof(X_heli_q8_presentation_T));
  }

  /* states (dwork) */
  heli_q8_presentation_M->ModelData.dwork = ((void *) &heli_q8_presentation_DW);
  (void) memset((void *)&heli_q8_presentation_DW, 0,
                sizeof(DW_heli_q8_presentation_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_presentation_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_presentation_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_presentation_DW.RateTransitiony_Buffer0 = 0.0;

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_presentation_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_presentation_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_presentation_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_presentation_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_presentation_M->Sizes.numContStates = (10);/* Number of continuous states */
  heli_q8_presentation_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_q8_presentation_M->Sizes.numY = (0);/* Number of model outputs */
  heli_q8_presentation_M->Sizes.numU = (0);/* Number of model inputs */
  heli_q8_presentation_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_presentation_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_presentation_M->Sizes.numBlocks = (101);/* Number of blocks */
  heli_q8_presentation_M->Sizes.numBlockIO = (25);/* Number of block outputs */
  heli_q8_presentation_M->Sizes.numBlockPrms = (545);/* Sum of parameter "widths" */
  return heli_q8_presentation_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
