/*
 * heli_q8_presentation_data.c
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

/* Block parameters (auto storage) */
P_heli_q8_presentation_T heli_q8_presentation_P = {
  /*  Variable: A
   * Referenced by: '<S5>/Gain2'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.61173902876295927, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Variable: B
   * Referenced by: '<S5>/Gain3'
   */
  { 0.0, 0.0, 0.0, 0.08504551365409628, 0.0, 0.0, 0.52848484848484878, 0.0, 0.0,
    0.0 },

  /*  Variable: C
   * Referenced by:
   *   '<S5>/Gain1'
   *   '<S5>/Gain4'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Variable: F
   * Referenced by: '<S4>/Gain1'
   */
  { -6.914299121887635E-16, 13.311173649552543, 18.3431479462413,
    -1.8826751062689642E-15 },
  0.5,                                 /* Variable: Joystick_gain_x
                                        * Referenced by: '<S3>/Joystick_gain_x'
                                        */
  0.5,                                 /* Variable: Joystick_gain_y
                                        * Referenced by: '<S3>/Joystick_gain_y'
                                        */

  /*  Variable: K
   * Referenced by: '<S4>/Gain'
   */
  { -6.914299121887635E-16, 13.311173649552543, -3.029662475952982E-16,
    7.1676254371800336, 0.11049893172283932, -3.6596497785078332E-8,
    18.3431479462413, -1.8826751062689642E-15, 3.5450917167133571E-8,
    1.2120164011324794, -2.10144971358904E-8, 4.6430054161561847,
    9.9449031533818584, 3.6596497874306728E-8 },

  /*  Variable: L
   * Referenced by: '<S5>/Gain'
   */
  { 28.97777478867205, 7.7645713530756222, 0.0, 0.0, 0.61173902876295927,
    -6.7645713530756222, 28.97777478867205, 0.0, 0.0, 0.0, 0.0, 0.0,
    25.98076211353316, 14.999999999999998, 0.0, 0.0, 0.0, -13.999999999999998,
    25.98076211353316, 0.0, 0.0, 0.0, 0.0, 0.0, 30.0 },
  7.5,                                 /* Variable: V_s0
                                        * Referenced by:
                                        *   '<S4>/V_s0'
                                        *   '<S5>/Bias'
                                        */

  /*  Variable: imu_offset
   * Referenced by: '<S7>/Constant'
   */
  { -0.017840628459667864, -0.012030798829118918, -0.028820476184687777,
    0.0038684721057597317, -0.0025513372190390953 },
  10.0,                                /* Mask Parameter: HILInitialize_analog_input_maxi
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_input_mini
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Mask Parameter: HILInitialize_analog_output_max
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Mask Parameter: HILInitialize_analog_output_min
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_analog_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_analog_ou
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_initial_pwm_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  24305.934065934067,                  /* Mask Parameter: HILInitialize_pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_leading_deadb
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_pwm_trailing_dead
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_set_other_outpu_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_analog_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Mask Parameter: HILInitialize_watchdog_pwm_outp
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILReadEncoderTimebase_clock
                                        * Referenced by: '<S9>/HIL Read Encoder Timebase'
                                        */

  /*  Mask Parameter: HILInitialize_hardware_clocks
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* Mask Parameter: HILInitialize_initial_encoder_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_alignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_configuration
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_pwm_modes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_pwm_polarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_watchdog_digital_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Mask Parameter: HILInitialize_analog_input_chan
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_analog_output_cha
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILReadEncoderTimebase_channels
   * Referenced by: '<S9>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /*  Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S8>/HIL Write Analog'
   */
  { 0U, 1U },

  /*  Mask Parameter: HILInitialize_encoder_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Mask Parameter: HILInitialize_pwm_channels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* Mask Parameter: HILInitialize_quadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  500U,                                /* Mask Parameter: HILReadEncoderTimebase_samples_
                                        * Referenced by: '<S9>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_final_digital_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_initial_digital_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_input_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_inpu_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_output
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_outp_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_analog_out_ex
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_analog_outp_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequen
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_frequ_e
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_params_
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_clock_param_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_outpu
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_b
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_c
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_ou_c1
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_digital_out_j
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_digital_out_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_count
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_cou_k
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_encoder_param
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_encoder_par_m
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_other_outpu_l
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_a
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_g
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_p
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_output_ap
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_outputs_o
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Mask Parameter: HILInitialize_set_pwm_params_at
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Mask Parameter: HILInitialize_set_pwm_params__f
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Constant1'
                                        */
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: x'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<S3>/Dead Zone: x'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S3>/Dead Zone: x'
                                        */
  1.1111111111111112,                  /* Expression: 10/9
                                        * Referenced by: '<S3>/Gain: x'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Rate Transition: y'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<S3>/Dead Zone: y'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S3>/Dead Zone: y'
                                        */
  1.1111111111111112,                  /* Expression: 10/9
                                        * Referenced by: '<S3>/Gain: y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Integrator'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Back gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Front gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  65.0,                                /* Expression: 65
                                        * Referenced by: '<S6>/Constant1'
                                        */

  /*  Expression: [0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S6>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S6>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /*  Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S6>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },
  0.11,                                /* Expression: 0.11
                                        * Referenced by: '<S13>/Constant2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Constant'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S8>/Front motor: Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S8>/Front motor: Saturation'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S8>/Back motor: Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S8>/Back motor: Saturation'
                                        */
  -0.0015339807878856412,              /* Expression: -2 * pi /4096
                                        * Referenced by: '<S9>/Elevation: Count to rad'
                                        */
  -50.0,                               /* Computed Parameter: ElevationTransferFcn_A
                                        * Referenced by: '<S9>/Elevation: Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: ElevationTransferFcn_C
                                        * Referenced by: '<S9>/Elevation: Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: ElevationTransferFcn_D
                                        * Referenced by: '<S9>/Elevation: Transfer Fcn'
                                        */
  0.53,                                /* Expression: 0.53
                                        * Referenced by: '<S9>/Constant'
                                        */
  -0.0015339807878856412,              /* Expression: -2*pi /4096
                                        * Referenced by: '<S9>/Pitch: Count to rad'
                                        */
  -50.0,                               /* Computed Parameter: PitchTransferFcn_A
                                        * Referenced by: '<S9>/Pitch: Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: PitchTransferFcn_C
                                        * Referenced by: '<S9>/Pitch: Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: PitchTransferFcn_D
                                        * Referenced by: '<S9>/Pitch: Transfer Fcn'
                                        */
  0.00076699039394282058,              /* Expression: 2*pi/8192
                                        * Referenced by: '<S9>/Travel: Count to rad'
                                        */
  -50.0,                               /* Computed Parameter: TravelTransferFcn_A
                                        * Referenced by: '<S9>/Travel: Transfer Fcn'
                                        */
  -2500.0,                             /* Computed Parameter: TravelTransferFcn_C
                                        * Referenced by: '<S9>/Travel: Transfer Fcn'
                                        */
  50.0,                                /* Computed Parameter: TravelTransferFcn_D
                                        * Referenced by: '<S9>/Travel: Transfer Fcn'
                                        */
  8000,                                /* Computed Parameter: StreamCall1_SendBufferSize
                                        * Referenced by: '<S6>/Stream Call1'
                                        */
  8000,                                /* Computed Parameter: StreamCall1_ReceiveBufferSize
                                        * Referenced by: '<S6>/Stream Call1'
                                        */
  80U,                                 /* Computed Parameter: StreamFormattedWrite_MaxUnits
                                        * Referenced by: '<S6>/Stream Formatted Write'
                                        */
  12U,                                 /* Computed Parameter: GameController_BufferSize
                                        * Referenced by: '<S3>/Game Controller'
                                        */

  /*  Expression: value
   * Referenced by: '<S6>/String Constant'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 49U,
    50U, 63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
    111U, 114U, 100U, 61U, 56U, 44U, 112U, 97U, 114U, 105U, 116U, 121U, 61U,
    110U, 111U, 110U, 101U, 44U, 115U, 116U, 111U, 112U, 61U, 49U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
  0U,                                  /* Expression: uri_argument
                                        * Referenced by: '<S6>/Stream Call1'
                                        */
  1U,                                  /* Computed Parameter: StreamCall1_Endian
                                        * Referenced by: '<S6>/Stream Call1'
                                        */
  1U,                                  /* Computed Parameter: GameController_ControllerNumber
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoderTimebase_Active
                                        * Referenced by: '<S9>/HIL Read Encoder Timebase'
                                        */
  0,                                   /* Computed Parameter: StreamCall1_Active
                                        * Referenced by: '<S6>/Stream Call1'
                                        */
  0,                                   /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S8>/HIL Write Analog'
                                        */
  0,                                   /* Computed Parameter: GameController_AutoCenter
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1                                    /* Computed Parameter: GameController_Enabled
                                        * Referenced by: '<S3>/Game Controller'
                                        */
};
