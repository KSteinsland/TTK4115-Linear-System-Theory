/*
 * heli_q8_2015.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_2015".
 *
 * Model version              : 1.84
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Mon Nov 02 12:12:17 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_2015.h"
#include "heli_q8_2015_private.h"
#include "heli_q8_2015_dt.h"

t_stream heli_q8_2015_rtZt_stream = NULL;

/* Block signals (auto storage) */
B_heli_q8_2015_T heli_q8_2015_B;

/* Continuous states */
X_heli_q8_2015_T heli_q8_2015_X;

/* Block states (auto storage) */
DW_heli_q8_2015_T heli_q8_2015_DW;

/* Real-time model */
RT_MODEL_heli_q8_2015_T heli_q8_2015_M_;
RT_MODEL_heli_q8_2015_T *const heli_q8_2015_M = &heli_q8_2015_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_2015_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_2015_M, 2);
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
  if (heli_q8_2015_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_2015_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_2015_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_2015_M->Timing.perTaskSampleHits[5] =
      heli_q8_2015_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_2015_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_2015_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_2015_M->Timing.TaskCounters.TID[2] = 0;
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
  heli_q8_2015_derivatives();
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
void heli_q8_2015_output0(void)        /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_HILReadEncoderTimebase_o3;
  real_T rtb_TmpSignalConversionAtR_dInp[5];
  real_T rtb_TmpSignalConversionAtToFile[21];
  t_stream_ptr rtb_StreamCall1_o1;
  t_stream_ptr rtb_StreamFormattedWrite_o1;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  real_T currentTime;
  real_T rtb_Gain2[3];
  real_T rtb_Sqrt;
  real_T rtb_euler_rates[3];
  int32_T i;
  real_T tmp[7];
  real_T tmp_0[2];
  real_T tmp_1[2];
  real_T tmp_2[9];
  real_T tmp_3[5];
  real_T tmp_4[3];
  real_T tmp_5[5];
  int32_T i_0;
  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* set solver stop time */
    if (!(heli_q8_2015_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_2015_M->solverInfo,
                            ((heli_q8_2015_M->Timing.clockTickH0 + 1) *
        heli_q8_2015_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_2015_M->solverInfo,
                            ((heli_q8_2015_M->Timing.clockTick0 + 1) *
        heli_q8_2015_M->Timing.stepSize0 + heli_q8_2015_M->Timing.clockTickH0 *
        heli_q8_2015_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_2015_M)) {
    heli_q8_2015_M->Timing.t[0] = rtsiGetT(&heli_q8_2015_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S9>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_2015/Heli 3D/Subsystem/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_q8_2015_DW.HILReadEncoderTimebase_Task,
        1, &heli_q8_2015_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_2015_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_2015_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_HILReadEncoderTimebase_o3 =
          heli_q8_2015_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* RateTransition: '<S3>/Rate Transition: x' */
    if (heli_q8_2015_M->Timing.RateInteraction.TID1_2) {
      heli_q8_2015_B.RateTransitionx = heli_q8_2015_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: x' */

    /* DeadZone: '<S3>/Dead Zone: x' */
    if (heli_q8_2015_B.RateTransitionx > heli_q8_2015_P.DeadZonex_End) {
      rtb_Sqrt = heli_q8_2015_B.RateTransitionx - heli_q8_2015_P.DeadZonex_End;
    } else if (heli_q8_2015_B.RateTransitionx >= heli_q8_2015_P.DeadZonex_Start)
    {
      rtb_Sqrt = 0.0;
    } else {
      rtb_Sqrt = heli_q8_2015_B.RateTransitionx - heli_q8_2015_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: x' */

    /* Gain: '<S3>/Joystick_gain_x' incorporates:
     *  Gain: '<S3>/Gain: x'
     */
    heli_q8_2015_B.Joystick_gain_x = heli_q8_2015_P.Gainx_Gain * rtb_Sqrt *
      heli_q8_2015_P.Joystick_gain_x;

    /* RateTransition: '<S3>/Rate Transition: y' */
    if (heli_q8_2015_M->Timing.RateInteraction.TID1_2) {
      heli_q8_2015_B.RateTransitiony = heli_q8_2015_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S3>/Rate Transition: y' */

    /* DeadZone: '<S3>/Dead Zone: y' */
    if (heli_q8_2015_B.RateTransitiony > heli_q8_2015_P.DeadZoney_End) {
      rtb_Sqrt = heli_q8_2015_B.RateTransitiony - heli_q8_2015_P.DeadZoney_End;
    } else if (heli_q8_2015_B.RateTransitiony >= heli_q8_2015_P.DeadZoney_Start)
    {
      rtb_Sqrt = 0.0;
    } else {
      rtb_Sqrt = heli_q8_2015_B.RateTransitiony - heli_q8_2015_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S3>/Dead Zone: y' */

    /* Gain: '<S3>/Joystick_gain_y' incorporates:
     *  Gain: '<S3>/Gain: y'
     */
    heli_q8_2015_B.Joystick_gain_y = heli_q8_2015_P.Gainy_Gain * rtb_Sqrt *
      heli_q8_2015_P.Joystick_gain_y;

    /* DiscretePulseGenerator: '<S19>/Pulse Generator' */
    heli_q8_2015_B.PulseGenerator = (heli_q8_2015_DW.clockTickCounter <
      heli_q8_2015_P.PulseGenerator_Duty) && (heli_q8_2015_DW.clockTickCounter >=
      0) ? heli_q8_2015_P.PulseGenerator_Amp : 0.0;
    if (heli_q8_2015_DW.clockTickCounter >= heli_q8_2015_P.PulseGenerator_Period
        - 1.0) {
      heli_q8_2015_DW.clockTickCounter = 0;
    } else {
      heli_q8_2015_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator' */

    /* DiscretePulseGenerator: '<S19>/Pulse Generator1' */
    heli_q8_2015_B.PulseGenerator1 = (heli_q8_2015_DW.clockTickCounter_e <
      heli_q8_2015_P.PulseGenerator1_Duty) &&
      (heli_q8_2015_DW.clockTickCounter_e >= 0) ?
      heli_q8_2015_P.PulseGenerator1_Amp : 0.0;
    if (heli_q8_2015_DW.clockTickCounter_e >=
        heli_q8_2015_P.PulseGenerator1_Period - 1.0) {
      heli_q8_2015_DW.clockTickCounter_e = 0;
    } else {
      heli_q8_2015_DW.clockTickCounter_e++;
    }

    /* End of DiscretePulseGenerator: '<S19>/Pulse Generator1' */
  }

  /* Step: '<S19>/Step1' */
  currentTime = heli_q8_2015_M->Timing.t[0];

  /* Step: '<S19>/Step' */
  if (heli_q8_2015_M->Timing.t[0] < heli_q8_2015_P.Step_Time) {
    rtb_Sqrt = heli_q8_2015_P.Step_Y0;
  } else {
    rtb_Sqrt = heli_q8_2015_P.Step_YFinal;
  }

  /* End of Step: '<S19>/Step' */

  /* Sum: '<S16>/Sum' incorporates:
   *  Gain: '<S19>/pitch_test_toggle'
   *  Sum: '<S19>/Sum3'
   */
  heli_q8_2015_B.Sum[0] = (rtb_Sqrt + heli_q8_2015_B.PulseGenerator) *
    heli_q8_2015_P.pitch_test + heli_q8_2015_B.Joystick_gain_x;

  /* Step: '<S19>/Step1' */
  if (currentTime < heli_q8_2015_P.Step1_Time) {
    currentTime = heli_q8_2015_P.Step1_Y0;
  } else {
    currentTime = heli_q8_2015_P.Step1_YFinal;
  }

  /* Sum: '<S16>/Sum' incorporates:
   *  Gain: '<S19>/elevation_test_toggle'
   *  Sum: '<S19>/Sum1'
   */
  heli_q8_2015_B.Sum[1] = (currentTime + heli_q8_2015_B.PulseGenerator1) *
    heli_q8_2015_P.elevation_test + heli_q8_2015_B.Joystick_gain_y;

  /* Integrator: '<S5>/Integrator' */
  for (i = 0; i < 5; i++) {
    heli_q8_2015_B.Integrator[i] = heli_q8_2015_X.Integrator_CSTATE[i];
  }

  /* End of Integrator: '<S5>/Integrator' */

  /* Bias: '<S5>/offset to get zero travel' */
  heli_q8_2015_B.offsettogetzerotravel = heli_q8_2015_B.Integrator[0] +
    heli_q8_2015_P.offsettogetzerotravel_Bias;

  /* Bias: '<S5>/imu offset' */
  heli_q8_2015_B.imuoffset = heli_q8_2015_B.Integrator[3] +
    heli_q8_2015_P.imuoffset_Bias;

  /* Integrator: '<S17>/Integrator1' */
  heli_q8_2015_B.Integrator1 = heli_q8_2015_X.Integrator1_CSTATE;

  /* Integrator: '<S17>/Integrator' */
  heli_q8_2015_B.Integrator_l = heli_q8_2015_X.Integrator_CSTATE_m;

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Gain: '<S4>/Gain'
   */
  tmp[0] = heli_q8_2015_B.offsettogetzerotravel;
  tmp[3] = heli_q8_2015_B.imuoffset;
  tmp[4] = heli_q8_2015_B.Integrator[4];
  tmp[5] = heli_q8_2015_B.Integrator1;
  tmp[6] = heli_q8_2015_B.Integrator_l;
  tmp[1] = heli_q8_2015_B.Integrator[1];

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Sum'
   */
  tmp_0[0] = heli_q8_2015_P.F[0] * heli_q8_2015_B.Sum[0] + heli_q8_2015_P.F[2] *
    heli_q8_2015_B.Sum[1];

  /* SignalConversion: '<S4>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Gain: '<S4>/Gain'
   */
  tmp[2] = heli_q8_2015_B.Integrator[2];

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Sum'
   */
  tmp_0[1] = heli_q8_2015_P.F[1] * heli_q8_2015_B.Sum[0];
  tmp_0[1] += heli_q8_2015_P.F[3] * heli_q8_2015_B.Sum[1];
  for (i = 0; i < 2; i++) {
    /* Gain: '<S4>/Gain' incorporates:
     *  Sum: '<S4>/Sum'
     */
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 7; i_0++) {
      tmp_1[i] += heli_q8_2015_P.K[(i_0 << 1) + i] * tmp[i_0];
    }

    /* Sum: '<S4>/Sum' */
    heli_q8_2015_B.Sum_j[i] = tmp_0[i] - tmp_1[i];
  }

  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* Constant: '<S4>/V_s0' */
    heli_q8_2015_B.V_s0 = heli_q8_2015_P.V_s0;
  }

  /* Sum: '<S4>/Sum1' */
  heli_q8_2015_B.Sum1 = heli_q8_2015_B.Sum_j[0] + heli_q8_2015_B.V_s0;
  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* Gain: '<S9>/Elevation: Count to rad' */
    heli_q8_2015_B.ElevationCounttorad = heli_q8_2015_P.ElevationCounttorad_Gain
      * rtb_HILReadEncoderTimebase_o3;
  }

  /* TransferFcn: '<S9>/Elevation: Transfer Fcn' */
  heli_q8_2015_B.ElevationTransferFcn = 0.0;
  heli_q8_2015_B.ElevationTransferFcn += heli_q8_2015_P.ElevationTransferFcn_C *
    heli_q8_2015_X.ElevationTransferFcn_CSTATE;
  heli_q8_2015_B.ElevationTransferFcn += heli_q8_2015_P.ElevationTransferFcn_D *
    heli_q8_2015_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S9>/Constant'
     */
    heli_q8_2015_B.Sum_jp = heli_q8_2015_B.ElevationCounttorad -
      heli_q8_2015_P.Constant_Value_f;

    /* Gain: '<S9>/Pitch: Count to rad' */
    heli_q8_2015_B.PitchCounttorad = heli_q8_2015_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;
  }

  /* TransferFcn: '<S9>/Pitch: Transfer Fcn' */
  heli_q8_2015_B.PitchTransferFcn = 0.0;
  heli_q8_2015_B.PitchTransferFcn += heli_q8_2015_P.PitchTransferFcn_C *
    heli_q8_2015_X.PitchTransferFcn_CSTATE;
  heli_q8_2015_B.PitchTransferFcn += heli_q8_2015_P.PitchTransferFcn_D *
    heli_q8_2015_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* Gain: '<S9>/Travel: Count to rad' */
    heli_q8_2015_B.TravelCounttorad = heli_q8_2015_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S9>/Travel: Transfer Fcn' */
  heli_q8_2015_B.TravelTransferFcn = 0.0;
  heli_q8_2015_B.TravelTransferFcn += heli_q8_2015_P.TravelTransferFcn_C *
    heli_q8_2015_X.TravelTransferFcn_CSTATE;
  heli_q8_2015_B.TravelTransferFcn += heli_q8_2015_P.TravelTransferFcn_D *
    heli_q8_2015_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* S-Function (stream_call_block): '<S6>/Stream Call1' */

    /* S-Function Block: heli_q8_2015/Heli 3D/IMU1/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_2015_P.Constant_Value_c != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_2015_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_2015_P.StringConstant_Value, 255)
                == 255) {
              rtmSetErrorStatus(heli_q8_2015_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_2015_P.StringConstant_Value, true,
                heli_q8_2015_P.StreamCall1_SendBufferSize,
                heli_q8_2015_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_2015_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_2015_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_2015_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_2015_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_2015_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_2015_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
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

            result = stream_poll(heli_q8_2015_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_2015_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_2015_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_2015_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_2015_DW.StreamCall1_Stream;
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
          rtb_StreamCall1_o1 = &heli_q8_2015_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(heli_q8_2015_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_2015_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_2015_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_2015_B.StreamCall1_o2 = heli_q8_2015_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S6>/Stream Formatted Write' */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_2015_P.StreamFormattedWrite_MaxUnits,
          &rtb_StreamFormattedWrite_o2, "%c\n"
          , (char) heli_q8_2015_P.Constant1_Value_d
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
    /* S-Function Block: heli_q8_2015/Heli 3D/IMU1/Stream Read1 (stream_read_block) */
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

    /* Switch: '<S6>/Switch' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     *  Memory: '<S6>/Memory'
     */
    for (i = 0; i < 10; i++) {
      if (rtb_StreamRead1_o3) {
        heli_q8_2015_B.Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        heli_q8_2015_B.Switch[i] = heli_q8_2015_DW.Memory_PreviousInput[i];
      }
    }

    /* End of Switch: '<S6>/Switch' */

    /* Gain: '<S6>/Gain2' */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = heli_q8_2015_P.Gain2_Gain[i + 6] * heli_q8_2015_B.Switch[2]
        + (heli_q8_2015_P.Gain2_Gain[i + 3] * heli_q8_2015_B.Switch[1] +
           heli_q8_2015_P.Gain2_Gain[i] * heli_q8_2015_B.Switch[0]);
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
        rtb_Sqrt = rtb_Gain2[2];
      } else {
        rtb_Sqrt = heli_q8_2015_P.Constant_Value_g;
      }

      /* End of Switch: '<S14>/Switch' */
      heli_q8_2015_B.Switch1 = atan(rtb_Gain2[1] / rtb_Sqrt);
    } else {
      heli_q8_2015_B.Switch1 = heli_q8_2015_P.Constant1_Value_c;
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
        rtb_Sqrt = heli_q8_2015_P.Constant_Value;
      }

      /* End of Switch: '<S13>/Switch' */
      rtb_Sqrt = rt_atan2d_snf(rtb_Gain2[0], rtb_Sqrt);
    } else {
      rtb_Sqrt = heli_q8_2015_P.Constant1_Value;
    }

    /* End of Switch: '<S13>/Switch1' */

    /* Sum: '<S13>/Sum1' incorporates:
     *  Constant: '<S13>/Constant2'
     */
    heli_q8_2015_B.Sum1_p = rtb_Sqrt - heli_q8_2015_P.Constant2_Value;

    /* MATLAB Function: '<S7>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  SignalConversion: '<S10>/TmpSignal ConversionAt SFunction Inport2'
     */
    /* MATLAB Function 'Heli 3D/Measurement/Gyro vector to [pitch rate, elevation rate, travle rate]': '<S10>:1' */
    /* '<S10>:1:3' */
    /* '<S10>:1:4' */
    /* psi = euler_angles(3); */
    /* '<S10>:1:8' */
    /* '<S10>:1:11' */
    tmp_2[0] = 1.0;
    tmp_2[3] = sin(heli_q8_2015_B.Switch1) * tan(heli_q8_2015_B.Sum1_p);
    tmp_2[6] = cos(heli_q8_2015_B.Switch1) * tan(heli_q8_2015_B.Sum1_p);
    tmp_2[1] = 0.0;
    tmp_2[4] = cos(heli_q8_2015_B.Switch1);
    tmp_2[7] = -sin(heli_q8_2015_B.Switch1);
    tmp_2[2] = 0.0;
    tmp_2[5] = sin(heli_q8_2015_B.Switch1) / cos(heli_q8_2015_B.Sum1_p);
    tmp_2[8] = cos(heli_q8_2015_B.Switch1) / cos(heli_q8_2015_B.Sum1_p);

    /* Gain: '<S6>/Gain1' incorporates:
     *  MATLAB Function: '<S7>/Gyro vector to [pitch rate, elevation rate, travle rate]'
     */
    for (i = 0; i < 3; i++) {
      rtb_Gain2[i] = heli_q8_2015_P.Gain1_Gain[i + 6] * heli_q8_2015_B.Switch[5]
        + (heli_q8_2015_P.Gain1_Gain[i + 3] * heli_q8_2015_B.Switch[4] +
           heli_q8_2015_P.Gain1_Gain[i] * heli_q8_2015_B.Switch[3]);
    }

    /* End of Gain: '<S6>/Gain1' */

    /* MATLAB Function: '<S7>/Gyro vector to [pitch rate, elevation rate, travle rate]' */
    for (i = 0; i < 3; i++) {
      rtb_euler_rates[i] = tmp_2[i + 6] * rtb_Gain2[2] + (tmp_2[i + 3] *
        rtb_Gain2[1] + tmp_2[i] * rtb_Gain2[0]);
    }

    /* SignalConversion: '<S2>/TmpSignal ConversionAtR_dInport1' */
    rtb_TmpSignalConversionAtR_dInp[0] = heli_q8_2015_B.Switch1;
    rtb_TmpSignalConversionAtR_dInp[1] = rtb_euler_rates[0];
    rtb_TmpSignalConversionAtR_dInp[2] = heli_q8_2015_B.Sum1_p;
    rtb_TmpSignalConversionAtR_dInp[3] = rtb_euler_rates[1];
    rtb_TmpSignalConversionAtR_dInp[4] = rtb_euler_rates[2];

    /* ToFile: '<S2>/R_d' */
    if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
      {
        if (!(++heli_q8_2015_DW.R_d_IWORK.Decimation % 1) &&
            (heli_q8_2015_DW.R_d_IWORK.Count*6)+1 < 100000000 ) {
          FILE *fp = (FILE *) heli_q8_2015_DW.R_d_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[6];
            heli_q8_2015_DW.R_d_IWORK.Decimation = 0;
            u[0] = heli_q8_2015_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtR_dInp[0];
            u[2] = rtb_TmpSignalConversionAtR_dInp[1];
            u[3] = rtb_TmpSignalConversionAtR_dInp[2];
            u[4] = rtb_TmpSignalConversionAtR_dInp[3];
            u[5] = rtb_TmpSignalConversionAtR_dInp[4];
            if (fwrite(u, sizeof(real_T), 6, fp) != 6) {
              rtmSetErrorStatus(heli_q8_2015_M,
                                "Error writing to MAT-file R_d.mat");
              return;
            }

            if (((++heli_q8_2015_DW.R_d_IWORK.Count)*6)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file R_d.mat.\n");
            }
          }
        }
      }
    }

    /* S-Function (stop_with_error_block): '<S6>/Stop with Call Error' */

    /* S-Function Block: heli_q8_2015/Heli 3D/IMU1/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S6>/Stop with Read Error' */

    /* S-Function Block: heli_q8_2015/Heli 3D/IMU1/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  rtb_Sqrt = (heli_q8_2015_B.Sum1 - heli_q8_2015_B.Sum_j[1]) *
    heli_q8_2015_P.Frontgain_Gain;

  /* Saturate: '<S8>/Front motor: Saturation' */
  if (rtb_Sqrt > heli_q8_2015_P.FrontmotorSaturation_UpperSat) {
    heli_q8_2015_B.FrontmotorSaturation =
      heli_q8_2015_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Sqrt < heli_q8_2015_P.FrontmotorSaturation_LowerSat) {
    heli_q8_2015_B.FrontmotorSaturation =
      heli_q8_2015_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_2015_B.FrontmotorSaturation = rtb_Sqrt;
  }

  /* End of Saturate: '<S8>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  rtb_Sqrt = (heli_q8_2015_B.Sum1 + heli_q8_2015_B.Sum_j[1]) *
    heli_q8_2015_P.Backgain_Gain;

  /* Saturate: '<S8>/Back motor: Saturation' */
  if (rtb_Sqrt > heli_q8_2015_P.BackmotorSaturation_UpperSat) {
    heli_q8_2015_B.BackmotorSaturation =
      heli_q8_2015_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Sqrt < heli_q8_2015_P.BackmotorSaturation_LowerSat) {
    heli_q8_2015_B.BackmotorSaturation =
      heli_q8_2015_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_2015_B.BackmotorSaturation = rtb_Sqrt;
  }

  /* End of Saturate: '<S8>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* S-Function (hil_write_analog_block): '<S8>/HIL Write Analog' */

    /* S-Function Block: heli_q8_2015/Heli 3D/Motor driver/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_2015_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_2015_B.FrontmotorSaturation;
      heli_q8_2015_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_2015_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILWriteAnalog_channels, 2,
        &heli_q8_2015_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
      }
    }

    /* SignalConversion: '<S15>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFile[4] = heli_q8_2015_B.offsettogetzerotravel;
    rtb_TmpSignalConversionAtToFile[0] = heli_q8_2015_B.Sum[0];
    rtb_TmpSignalConversionAtToFile[2] = heli_q8_2015_B.Sum_j[0];
    rtb_TmpSignalConversionAtToFile[5] = heli_q8_2015_B.Integrator[1];
    rtb_TmpSignalConversionAtToFile[1] = heli_q8_2015_B.Sum[1];
    rtb_TmpSignalConversionAtToFile[3] = heli_q8_2015_B.Sum_j[1];
    rtb_TmpSignalConversionAtToFile[6] = heli_q8_2015_B.Integrator[2];
    rtb_TmpSignalConversionAtToFile[7] = heli_q8_2015_B.imuoffset;
    rtb_TmpSignalConversionAtToFile[8] = heli_q8_2015_B.Integrator[4];
    rtb_TmpSignalConversionAtToFile[9] = heli_q8_2015_B.Integrator1;
    rtb_TmpSignalConversionAtToFile[10] = heli_q8_2015_B.Integrator_l;
    rtb_TmpSignalConversionAtToFile[11] = heli_q8_2015_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[12] = heli_q8_2015_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[13] = heli_q8_2015_B.Sum_jp;
    rtb_TmpSignalConversionAtToFile[14] = heli_q8_2015_B.ElevationTransferFcn;
    rtb_TmpSignalConversionAtToFile[15] = heli_q8_2015_B.TravelTransferFcn;
    rtb_TmpSignalConversionAtToFile[16] = heli_q8_2015_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[17] = heli_q8_2015_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[18] = heli_q8_2015_B.Sum_jp;
    rtb_TmpSignalConversionAtToFile[19] = heli_q8_2015_B.ElevationTransferFcn;
    rtb_TmpSignalConversionAtToFile[20] = heli_q8_2015_B.TravelTransferFcn;

    /* ToFile: '<S15>/To File' */
    if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
      {
        if (!(++heli_q8_2015_DW.ToFile_IWORK.Decimation % 1) &&
            (heli_q8_2015_DW.ToFile_IWORK.Count*22)+1 < 100000000 ) {
          FILE *fp = (FILE *) heli_q8_2015_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[22];
            heli_q8_2015_DW.ToFile_IWORK.Decimation = 0;
            u[0] = heli_q8_2015_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtToFile[0];
            u[2] = rtb_TmpSignalConversionAtToFile[1];
            u[3] = rtb_TmpSignalConversionAtToFile[2];
            u[4] = rtb_TmpSignalConversionAtToFile[3];
            u[5] = rtb_TmpSignalConversionAtToFile[4];
            u[6] = rtb_TmpSignalConversionAtToFile[5];
            u[7] = rtb_TmpSignalConversionAtToFile[6];
            u[8] = rtb_TmpSignalConversionAtToFile[7];
            u[9] = rtb_TmpSignalConversionAtToFile[8];
            u[10] = rtb_TmpSignalConversionAtToFile[9];
            u[11] = rtb_TmpSignalConversionAtToFile[10];
            u[12] = rtb_TmpSignalConversionAtToFile[11];
            u[13] = rtb_TmpSignalConversionAtToFile[12];
            u[14] = rtb_TmpSignalConversionAtToFile[13];
            u[15] = rtb_TmpSignalConversionAtToFile[14];
            u[16] = rtb_TmpSignalConversionAtToFile[15];
            u[17] = rtb_TmpSignalConversionAtToFile[16];
            u[18] = rtb_TmpSignalConversionAtToFile[17];
            u[19] = rtb_TmpSignalConversionAtToFile[18];
            u[20] = rtb_TmpSignalConversionAtToFile[19];
            u[21] = rtb_TmpSignalConversionAtToFile[20];
            if (fwrite(u, sizeof(real_T), 22, fp) != 22) {
              rtmSetErrorStatus(heli_q8_2015_M,
                                "Error writing to MAT-file test.mat");
              return;
            }

            if (((++heli_q8_2015_DW.ToFile_IWORK.Count)*22)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file test.mat.\n");
            }
          }
        }
      }
    }
  }

  /* Sum: '<S17>/Sum' */
  heli_q8_2015_B.Sum_n = heli_q8_2015_B.imuoffset - heli_q8_2015_B.Sum[1];

  /* Sum: '<S17>/Sum1' */
  heli_q8_2015_B.Sum1_h = heli_q8_2015_B.offsettogetzerotravel -
    heli_q8_2015_B.Sum[0];

  /* SignalConversion: '<S5>/TmpSignal ConversionAtGain4Inport1' */
  tmp_3[0] = heli_q8_2015_B.PitchCounttorad;
  tmp_3[1] = heli_q8_2015_B.PitchTransferFcn;
  tmp_3[2] = heli_q8_2015_B.Sum_jp;
  tmp_3[3] = heli_q8_2015_B.ElevationTransferFcn;
  tmp_3[4] = heli_q8_2015_B.TravelTransferFcn;
  for (i = 0; i < 3; i++) {
    /* Gain: '<S5>/Gain4' incorporates:
     *  Sum: '<S5>/Sum'
     */
    rtb_Gain2[i] = 0.0;

    /* Gain: '<S5>/Gain1' incorporates:
     *  Sum: '<S5>/Sum'
     */
    rtb_euler_rates[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      /* Gain: '<S5>/Gain4' incorporates:
       *  Sum: '<S5>/Sum'
       */
      rtb_Gain2[i] += heli_q8_2015_P.C[3 * i_0 + i] * tmp_3[i_0];

      /* Gain: '<S5>/Gain1' incorporates:
       *  Sum: '<S5>/Sum'
       */
      rtb_euler_rates[i] += heli_q8_2015_P.C[3 * i_0 + i] *
        heli_q8_2015_B.Integrator[i_0];
    }

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/Gain'
     */
    tmp_4[i] = rtb_Gain2[i] - rtb_euler_rates[i];
  }

  /* SignalConversion: '<S5>/TmpSignal ConversionAtGain3Inport1' incorporates:
   *  Bias: '<S5>/Bias'
   */
  rtb_Sqrt = heli_q8_2015_B.Sum1 + -heli_q8_2015_P.V_s0;
  for (i = 0; i < 5; i++) {
    /* Gain: '<S5>/Gain2' incorporates:
     *  Sum: '<S5>/Sum1'
     */
    tmp_3[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp_3[i] += heli_q8_2015_P.A[5 * i_0 + i] * heli_q8_2015_B.Integrator[i_0];
    }

    /* End of Gain: '<S5>/Gain2' */

    /* Gain: '<S5>/Gain' incorporates:
     *  Sum: '<S5>/Sum1'
     */
    tmp_5[i] = 0.0;
    tmp_5[i] += heli_q8_2015_P.L[i] * tmp_4[0];
    tmp_5[i] += heli_q8_2015_P.L[i + 5] * tmp_4[1];
    tmp_5[i] += heli_q8_2015_P.L[i + 10] * tmp_4[2];

    /* Sum: '<S5>/Sum1' incorporates:
     *  Gain: '<S5>/Gain3'
     *  SignalConversion: '<S5>/TmpSignal ConversionAtGain3Inport1'
     */
    heli_q8_2015_B.Sum1_e[i] = (heli_q8_2015_P.B[i + 5] * heli_q8_2015_B.Sum_j[1]
      + heli_q8_2015_P.B[i] * rtb_Sqrt) + (tmp_3[i] + tmp_5[i]);
  }
}

/* Model update function for TID0 */
void heli_q8_2015_update0(void)        /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    /* Update for Memory: '<S6>/Memory' */
    memcpy(&heli_q8_2015_DW.Memory_PreviousInput[0], &heli_q8_2015_B.Switch[0],
           10U * sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_2015_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_2015_M->solverInfo);
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
  if (!(++heli_q8_2015_M->Timing.clockTick0)) {
    ++heli_q8_2015_M->Timing.clockTickH0;
  }

  heli_q8_2015_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_2015_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_2015_M->Timing.clockTick1)) {
    ++heli_q8_2015_M->Timing.clockTickH1;
  }

  heli_q8_2015_M->Timing.t[1] = heli_q8_2015_M->Timing.clockTick1 *
    heli_q8_2015_M->Timing.stepSize1 + heli_q8_2015_M->Timing.clockTickH1 *
    heli_q8_2015_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_2015_derivatives(void)
{
  int32_T i;
  XDot_heli_q8_2015_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_2015_T *) heli_q8_2015_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S5>/Integrator' */
  for (i = 0; i < 5; i++) {
    _rtXdot->Integrator_CSTATE[i] = heli_q8_2015_B.Sum1_e[i];
  }

  /* End of Derivatives for Integrator: '<S5>/Integrator' */

  /* Derivatives for Integrator: '<S17>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_2015_B.Sum1_h;

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = heli_q8_2015_B.Sum_n;

  /* Derivatives for TransferFcn: '<S9>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_2015_P.ElevationTransferFcn_A *
    heli_q8_2015_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_2015_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S9>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_2015_P.PitchTransferFcn_A *
    heli_q8_2015_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_2015_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S9>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_2015_P.TravelTransferFcn_A *
    heli_q8_2015_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_2015_B.TravelCounttorad;
}

/* Model output function for TID2 */
void heli_q8_2015_output2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_2015/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_2015_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_2015_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        heli_q8_2015_B.GameController_o4 = state.x;
        heli_q8_2015_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_2015_B.GameController_o4 = 0;
      heli_q8_2015_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_2015_update2(void)        /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S3>/Rate Transition: x' */
  heli_q8_2015_DW.RateTransitionx_Buffer0 = heli_q8_2015_B.GameController_o4;

  /* Update for RateTransition: '<S3>/Rate Transition: y' */
  heli_q8_2015_DW.RateTransitiony_Buffer0 = heli_q8_2015_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_2015_M->Timing.clockTick2)) {
    ++heli_q8_2015_M->Timing.clockTickH2;
  }

  heli_q8_2015_M->Timing.t[2] = heli_q8_2015_M->Timing.clockTick2 *
    heli_q8_2015_M->Timing.stepSize2 + heli_q8_2015_M->Timing.clockTickH2 *
    heli_q8_2015_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_2015_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_2015_output0();
    break;

   case 2 :
    heli_q8_2015_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_2015_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_2015_update0();
    break;

   case 2 :
    heli_q8_2015_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_2015_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_2015/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_2015_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_2015_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_2015_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
      return;
    }

    if ((heli_q8_2015_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_2015_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_q8_2015_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_2015_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_2015_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_analog_input_chan, 8U,
        &heli_q8_2015_DW.HILInitialize_AIMinimums[0],
        &heli_q8_2015_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_2015_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_2015_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_q8_2015_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_2015_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_2015_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_2015_DW.HILInitialize_AOMinimums[0],
        &heli_q8_2015_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_2015_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_2015_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_2015_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_2015_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_2015_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_2015_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_2015_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_2015_DW.HILInitialize_Card,
         heli_q8_2015_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_2015_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_2015_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_2015_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_2015_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_2015_DW.HILInitialize_Card,
         heli_q8_2015_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_2015_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_2015_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_2015_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            heli_q8_2015_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_encoder_channels, 8U,
        &heli_q8_2015_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_2015_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_2015_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_2015_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_q8_2015_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_2015_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &heli_q8_2015_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_2015_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_q8_2015_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_2015_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_2015_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = p_HILInitialize_pwm_channels[i1];
            heli_q8_2015_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = heli_q8_2015_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_2015_DW.HILInitialize_Card,
          &heli_q8_2015_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_2015_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_2015_DW.HILInitialize_Card,
          &heli_q8_2015_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_2015_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_2015_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_2015_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_2015_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_2015_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_2015_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_2015_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_q8_2015_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_2015_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_2015_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_q8_2015_DW.HILInitialize_POSortedFreqs
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_2015_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_2015_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_2015_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_2015_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_2015_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_2015_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_2015_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_2015_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_2015_DW.HILInitialize_Card,
        heli_q8_2015_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_2015_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_2015_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_2015_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_2015_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_2015_DW.HILInitialize_Card,
         heli_q8_2015_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_2015_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S9>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_2015/Heli 3D/Subsystem/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_2015_DW.HILInitialize_Card,
      heli_q8_2015_P.HILReadEncoderTimebase_samples_,
      heli_q8_2015_P.HILReadEncoderTimebase_channels, 3,
      &heli_q8_2015_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S3>/Rate Transition: x' */
  heli_q8_2015_B.RateTransitionx = heli_q8_2015_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S3>/Rate Transition: y' */
  heli_q8_2015_B.RateTransitiony = heli_q8_2015_P.RateTransitiony_X0;

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator' */
  heli_q8_2015_DW.clockTickCounter = -2500;

  /* Start for DiscretePulseGenerator: '<S19>/Pulse Generator1' */
  heli_q8_2015_DW.clockTickCounter_e = -2500;

  /* Start for S-Function (stream_call_block): '<S6>/Stream Call1' */

  /* S-Function Block: heli_q8_2015/Heli 3D/IMU1/Stream Call1 (stream_call_block) */
  {
    heli_q8_2015_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_2015_DW.StreamCall1_Stream = NULL;
  }

  /* Start for ToFile: '<S2>/R_d' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "R_d.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_2015_M, "Error creating .mat file R_d.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,6,0,"data")) {
      rtmSetErrorStatus(heli_q8_2015_M,
                        "Error writing mat file header to file R_d.mat");
      return;
    }

    heli_q8_2015_DW.R_d_IWORK.Count = 0;
    heli_q8_2015_DW.R_d_IWORK.Decimation = -1;
    heli_q8_2015_DW.R_d_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_2015/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_2015_P.GameController_Enabled) {
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
        (heli_q8_2015_P.GameController_ControllerNumber,
         heli_q8_2015_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_2015_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_2015_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
      }
    }
  }

  /* Start for ToFile: '<S15>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "test.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_2015_M, "Error creating .mat file test.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,22,0,"data")) {
      rtmSetErrorStatus(heli_q8_2015_M,
                        "Error writing mat file header to file test.mat");
      return;
    }

    heli_q8_2015_DW.ToFile_IWORK.Count = 0;
    heli_q8_2015_DW.ToFile_IWORK.Decimation = -1;
    heli_q8_2015_DW.ToFile_PWORK.FilePtr = fp;
  }

  {
    int32_T i;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: x' */
    heli_q8_2015_DW.RateTransitionx_Buffer0 = heli_q8_2015_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S3>/Rate Transition: y' */
    heli_q8_2015_DW.RateTransitiony_Buffer0 = heli_q8_2015_P.RateTransitiony_X0;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    for (i = 0; i < 5; i++) {
      heli_q8_2015_X.Integrator_CSTATE[i] = heli_q8_2015_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S5>/Integrator' */

    /* InitializeConditions for Integrator: '<S17>/Integrator1' */
    heli_q8_2015_X.Integrator1_CSTATE = heli_q8_2015_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S17>/Integrator' */
    heli_q8_2015_X.Integrator_CSTATE_m = heli_q8_2015_P.Integrator_IC_b;

    /* InitializeConditions for TransferFcn: '<S9>/Elevation: Transfer Fcn' */
    heli_q8_2015_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S9>/Pitch: Transfer Fcn' */
    heli_q8_2015_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S9>/Travel: Transfer Fcn' */
    heli_q8_2015_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Memory: '<S6>/Memory' */
    memcpy(&heli_q8_2015_DW.Memory_PreviousInput[0], &heli_q8_2015_P.Memory_X0[0],
           10U * sizeof(real_T));
  }
}

/* Model terminate function */
void heli_q8_2015_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_2015/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_2015_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_2015_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_2015_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_2015_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_2015_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_2015_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_q8_2015_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_2015_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_2015_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_2015_DW.HILInitialize_Card
                         , heli_q8_2015_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_2015_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_2015_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_2015_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_2015_DW.HILInitialize_Card,
            heli_q8_2015_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs, &heli_q8_2015_DW.HILInitialize_AOVoltages
            [0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_2015_DW.HILInitialize_Card,
            heli_q8_2015_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_q8_2015_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_2015_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_2015_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_2015_DW.HILInitialize_Card);
    hil_close(heli_q8_2015_DW.HILInitialize_Card);
    heli_q8_2015_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S6>/Stream Call1' */

  /* S-Function Block: heli_q8_2015/Heli 3D/IMU1/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_2015_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_2015_DW.StreamCall1_Stream);
      heli_q8_2015_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<S2>/R_d' */
  {
    FILE *fp = (FILE *) heli_q8_2015_DW.R_d_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "R_d.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_2015_M, "Error closing MAT-file R_d.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_2015_M, "Error reopening MAT-file R_d.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6, heli_q8_2015_DW.R_d_IWORK.Count, "data"))
      {
        rtmSetErrorStatus(heli_q8_2015_M,
                          "Error writing header for data to MAT-file R_d.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_2015_M, "Error closing MAT-file R_d.mat");
        return;
      }

      heli_q8_2015_DW.R_d_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S3>/Game Controller' */

  /* S-Function Block: heli_q8_2015/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_2015_P.GameController_Enabled) {
      game_controller_close(heli_q8_2015_DW.GameController_Controller);
      heli_q8_2015_DW.GameController_Controller = NULL;
    }
  }

  /* Terminate for ToFile: '<S15>/To File' */
  {
    FILE *fp = (FILE *) heli_q8_2015_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "test.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_2015_M, "Error closing MAT-file test.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_2015_M, "Error reopening MAT-file test.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 22, heli_q8_2015_DW.ToFile_IWORK.Count,
           "data")) {
        rtmSetErrorStatus(heli_q8_2015_M,
                          "Error writing header for data to MAT-file test.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_2015_M, "Error closing MAT-file test.mat");
        return;
      }

      heli_q8_2015_DW.ToFile_PWORK.FilePtr = (NULL);
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
  heli_q8_2015_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_2015_update(tid);
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
  heli_q8_2015_initialize();
}

void MdlTerminate(void)
{
  heli_q8_2015_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_2015_T *heli_q8_2015(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_2015_M, 0,
                sizeof(RT_MODEL_heli_q8_2015_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_2015_M->solverInfo,
                          &heli_q8_2015_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_2015_M->solverInfo, &rtmGetTPtr(heli_q8_2015_M));
    rtsiSetStepSizePtr(&heli_q8_2015_M->solverInfo,
                       &heli_q8_2015_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_2015_M->solverInfo, &heli_q8_2015_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_2015_M->solverInfo, (real_T **)
                         &heli_q8_2015_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_2015_M->solverInfo,
      &heli_q8_2015_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_2015_M->solverInfo,
      &heli_q8_2015_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_2015_M->solverInfo,
      &heli_q8_2015_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_2015_M->solverInfo,
      &heli_q8_2015_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_2015_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_2015_M)));
    rtsiSetRTModelPtr(&heli_q8_2015_M->solverInfo, heli_q8_2015_M);
  }

  rtsiSetSimTimeStep(&heli_q8_2015_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_2015_M->ModelData.intgData.f[0] = heli_q8_2015_M->ModelData.odeF[0];
  heli_q8_2015_M->ModelData.contStates = ((real_T *) &heli_q8_2015_X);
  rtsiSetSolverData(&heli_q8_2015_M->solverInfo, (void *)
                    &heli_q8_2015_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_2015_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_2015_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_2015_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_2015_M->Timing.sampleTimes =
      (&heli_q8_2015_M->Timing.sampleTimesArray[0]);
    heli_q8_2015_M->Timing.offsetTimes =
      (&heli_q8_2015_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_2015_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_2015_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_2015_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_2015_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_2015_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_2015_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_2015_M, &heli_q8_2015_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_2015_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_2015_M->Timing.perTaskSampleHitsArray;
    heli_q8_2015_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_2015_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_2015_M, -1);
  heli_q8_2015_M->Timing.stepSize0 = 0.002;
  heli_q8_2015_M->Timing.stepSize1 = 0.002;
  heli_q8_2015_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_2015_M->Sizes.checksums[0] = (1233938989U);
  heli_q8_2015_M->Sizes.checksums[1] = (3210702312U);
  heli_q8_2015_M->Sizes.checksums[2] = (3397774269U);
  heli_q8_2015_M->Sizes.checksums[3] = (713118665U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    heli_q8_2015_M->extModeInfo = (&rt_ExtModeInfo);
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
    rteiSetModelMappingInfoPtr(heli_q8_2015_M->extModeInfo,
      &heli_q8_2015_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_2015_M->extModeInfo,
                        heli_q8_2015_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_2015_M->extModeInfo, rtmGetTPtr(heli_q8_2015_M));
  }

  heli_q8_2015_M->solverInfoPtr = (&heli_q8_2015_M->solverInfo);
  heli_q8_2015_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_2015_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_2015_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_2015_M->ModelData.blockIO = ((void *) &heli_q8_2015_B);
  (void) memset(((void *) &heli_q8_2015_B), 0,
                sizeof(B_heli_q8_2015_T));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      heli_q8_2015_B.Integrator[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      heli_q8_2015_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      heli_q8_2015_B.Sum1_e[i] = 0.0;
    }

    heli_q8_2015_B.RateTransitionx = 0.0;
    heli_q8_2015_B.Joystick_gain_x = 0.0;
    heli_q8_2015_B.RateTransitiony = 0.0;
    heli_q8_2015_B.Joystick_gain_y = 0.0;
    heli_q8_2015_B.PulseGenerator = 0.0;
    heli_q8_2015_B.PulseGenerator1 = 0.0;
    heli_q8_2015_B.Sum[0] = 0.0;
    heli_q8_2015_B.Sum[1] = 0.0;
    heli_q8_2015_B.offsettogetzerotravel = 0.0;
    heli_q8_2015_B.imuoffset = 0.0;
    heli_q8_2015_B.Integrator1 = 0.0;
    heli_q8_2015_B.Integrator_l = 0.0;
    heli_q8_2015_B.Sum_j[0] = 0.0;
    heli_q8_2015_B.Sum_j[1] = 0.0;
    heli_q8_2015_B.V_s0 = 0.0;
    heli_q8_2015_B.Sum1 = 0.0;
    heli_q8_2015_B.ElevationCounttorad = 0.0;
    heli_q8_2015_B.ElevationTransferFcn = 0.0;
    heli_q8_2015_B.Sum_jp = 0.0;
    heli_q8_2015_B.PitchCounttorad = 0.0;
    heli_q8_2015_B.PitchTransferFcn = 0.0;
    heli_q8_2015_B.TravelCounttorad = 0.0;
    heli_q8_2015_B.TravelTransferFcn = 0.0;
    heli_q8_2015_B.Switch1 = 0.0;
    heli_q8_2015_B.Sum1_p = 0.0;
    heli_q8_2015_B.FrontmotorSaturation = 0.0;
    heli_q8_2015_B.BackmotorSaturation = 0.0;
    heli_q8_2015_B.GameController_o4 = 0.0;
    heli_q8_2015_B.GameController_o5 = 0.0;
    heli_q8_2015_B.Sum_n = 0.0;
    heli_q8_2015_B.Sum1_h = 0.0;
  }

  /* parameters */
  heli_q8_2015_M->ModelData.defaultParam = ((real_T *)&heli_q8_2015_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_2015_X;
    heli_q8_2015_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_2015_X, 0,
                  sizeof(X_heli_q8_2015_T));
  }

  /* states (dwork) */
  heli_q8_2015_M->ModelData.dwork = ((void *) &heli_q8_2015_DW);
  (void) memset((void *)&heli_q8_2015_DW, 0,
                sizeof(DW_heli_q8_2015_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_2015_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_2015_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_2015_DW.RateTransitiony_Buffer0 = 0.0;

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_2015_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_2015_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_2015_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_2015_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_2015_M->Sizes.numContStates = (10);/* Number of continuous states */
  heli_q8_2015_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  heli_q8_2015_M->Sizes.numY = (0);    /* Number of model outputs */
  heli_q8_2015_M->Sizes.numU = (0);    /* Number of model inputs */
  heli_q8_2015_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_2015_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_2015_M->Sizes.numBlocks = (123);/* Number of blocks */
  heli_q8_2015_M->Sizes.numBlockIO = (33);/* Number of block outputs */
  heli_q8_2015_M->Sizes.numBlockPrms = (538);/* Sum of parameter "widths" */
  return heli_q8_2015_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
