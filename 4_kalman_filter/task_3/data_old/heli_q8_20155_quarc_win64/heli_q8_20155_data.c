/*
 * heli_q8_20155_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_20155".
 *
 * Model version              : 1.121
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Tue Nov 03 00:11:46 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_20155.h"
#include "heli_q8_20155_private.h"

/* Block parameters (auto storage) */
P_heli_q8_20155_T heli_q8_20155_P = {
  /*  Variable: A_d
   * Referenced by: '<S23>/Prediction function'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.2234780575259187E-6, 0.0012234780575259186, 0.002, 1.0,
    0.0, 0.0, 8.1565203835061226E-10, 1.2234780575259187E-6, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.002, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.002, 1.0 },

  /*  Variable: B_d
   * Referenced by: '<S23>/Prediction function'
   */
  { 0.0, 0.0, 1.7009102730819254E-7, 0.00017009102730819255, 0.0, 0.0,
    1.0569696969696975E-6, 0.0010569696969696975, 0.0, 0.0,
    2.1552987195204065E-13, 4.3105974390408139E-10 },

  /*  Variable: C_d
   * Referenced by:
   *   '<S2>/C_d'
   *   '<S4>/Correction function'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /*  Variable: F
   * Referenced by: '<S5>/Gain1'
   */
  { -1.1804769776286648E-16, 9.14808373713447, 11.942895749700742,
    3.2252345603829328E-16 },
  0.5,                                 /* Variable: Joystick_gain_x
                                        * Referenced by: '<S3>/Joystick_gain_x'
                                        */
  0.5,                                 /* Variable: Joystick_gain_y
                                        * Referenced by: '<S3>/Joystick_gain_y'
                                        */

  /*  Variable: K
   * Referenced by: '<S5>/Gain'
   */
  { -1.1804769776286648E-16, 9.14808373713447, 5.1901531449595309E-18,
    6.6873045142090888, 3.0615359576927071E-7, -9.3827368663547885E-8,
    11.942895749700742, 3.2252345603829328E-16, 0.10954451150103366,
    3.6197117251449466E-16, 5.58686746391965E-8, 0.77594017885164568,
    -3.4388660621174605E-8, 1.9693190003554122, 3.555402178146275,
    9.6939234385937043E-8 },

  /*  Variable: Q_d
   * Referenced by: '<S23>/Prediction function'
   */
  { 1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0E-7 },

  /*  Variable: R_d
   * Referenced by: '<S4>/Correction function'
   */
  { 0.0058, 0.005, 0.0039, -0.0058, -0.0003, 0.005, 0.0055, 0.0047, -0.0053,
    -0.0002, 0.0039, 0.0047, 0.0207, -0.0064, 0.0003, -0.0058, -0.0053, -0.0064,
    0.0078, -0.0002, -0.0003, -0.0002, 0.0003, -0.0002, 0.0009 },
  7.5,                                 /* Variable: V_s0
                                        * Referenced by:
                                        *   '<S4>/Bias'
                                        *   '<S5>/Bias'
                                        */
  0.0,                                 /* Variable: bad_elevation_rate
                                        * Referenced by: '<S10>/elevation rate offset'
                                        */
  5.0,                                 /* Variable: calibrate_time
                                        * Referenced by:
                                        *   '<S5>/wait calibrate'
                                        *   '<S5>/wait calibrate 1'
                                        *   '<S27>/wait calibrate'
                                        *   '<S27>/wait calibrate1'
                                        *   '<S29>/Step'
                                        *   '<S29>/Step1'
                                        *   '<S14>/Step'
                                        *   '<S15>/Step'
                                        *   '<S16>/Step'
                                        *   '<S17>/Step'
                                        *   '<S18>/Step'
                                        *   '<S19>/Step'
                                        */
  -0.53,                               /* Variable: elevation_offset
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S16>/elevation offset'
                                        *   '<S20>/Constant1'
                                        */
  0.0,                                 /* Variable: elevation_test
                                        * Referenced by: '<S29>/elevation_test_toggle'
                                        */
  2500.0,                              /* Variable: num_measures
                                        * Referenced by:
                                        *   '<S14>/Constant'
                                        *   '<S15>/Constant'
                                        *   '<S16>/Constant'
                                        *   '<S17>/Constant'
                                        *   '<S18>/Constant'
                                        *   '<S19>/Constant'
                                        */
  1.0,                                 /* Variable: pitch_test
                                        * Referenced by: '<S29>/pitch_test_toggle'
                                        */
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
  0.001,                               /* Expression: 0.001
                                        * Referenced by: '<S20>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S21>/Constant1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S21>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
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
  -0.2,                                /* Expression: -0.2
                                        * Referenced by: '<S3>/Dead Zone: y'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S3>/Dead Zone: y'
                                        */
  1.1111111111111112,                  /* Expression: 10/9
                                        * Referenced by: '<S3>/Gain: y'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/Step'
                                        */
  -0.25,                               /* Expression: -0.25
                                        * Referenced by: '<S29>/Step'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S29>/Pulse Generator'
                                        */
  5000.0,                              /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<S29>/Pulse Generator'
                                        */
  2500.0,                              /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<S29>/Pulse Generator'
                                        */
  10.0,                                /* Expression: 5+calibrate_time
                                        * Referenced by: '<S29>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S29>/Step1'
                                        */
  -0.125,                              /* Expression: -0.125
                                        * Referenced by: '<S29>/Step1'
                                        */
  0.25,                                /* Expression: 0.25
                                        * Referenced by: '<S29>/Pulse Generator1'
                                        */
  5000.0,                              /* Computed Parameter: PulseGenerator1_Period
                                        * Referenced by: '<S29>/Pulse Generator1'
                                        */
  2500.0,                              /* Computed Parameter: PulseGenerator1_Duty
                                        * Referenced by: '<S29>/Pulse Generator1'
                                        */
  10.0,                                /* Expression: 5+calibrate_time
                                        * Referenced by: '<S29>/Pulse Generator1'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/wait calibrate'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/wait calibrate'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/wait calibrate 1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/wait calibrate 1'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Back gain'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Front gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Memory'
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
   * Referenced by: '<S6>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/pitch offset1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Memory'
                                        */

  /*  Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S6>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Memory'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S15>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S17>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S18>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S18>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S19>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S19>/Switch'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/wait calibrate'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/wait calibrate'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S27>/wait calibrate1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S27>/wait calibrate1'
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
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 55U,
    63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
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
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },
  0U,                                  /* Expression: uri_argument
                                        * Referenced by: '<S6>/Stream Call1'
                                        */
  1U,                                  /* Computed Parameter: StreamCall1_Endian
                                        * Referenced by: '<S6>/Stream Call1'
                                        */
  1U,                                  /* Computed Parameter: GameController_ControllerNumber
                                        * Referenced by: '<S3>/Game Controller'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S4>/Manual Switch'
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
