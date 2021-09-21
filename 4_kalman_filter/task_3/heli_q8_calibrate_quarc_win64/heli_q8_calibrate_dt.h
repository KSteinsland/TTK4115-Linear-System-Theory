/*
 * heli_q8_calibrate_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_stream),
  sizeof(t_stream_ptr),
  sizeof(intmax_t),
  sizeof(ptrdiff_t),
  sizeof(size_t),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(t_wide_char),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_stream",
  "t_stream_ptr",
  "intmax_t",
  "ptrdiff_t",
  "size_t",
  "t_int64",
  "t_uint64",
  "t_wide_char",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&heli_q8_calibrate_B.Memory), 0, 0, 37 },

  { (char_T *)(&heli_q8_calibrate_B.StreamCall1_o2), 3, 0, 1 }
  ,

  { (char_T *)(&heli_q8_calibrate_DW.HILInitialize_AIMinimums[0]), 0, 0, 79 },

  { (char_T *)(&heli_q8_calibrate_DW.StreamCall1_Stream), 14, 0, 1 },

  { (char_T *)(&heli_q8_calibrate_DW.HILInitialize_Card), 22, 0, 1 },

  { (char_T *)(&heli_q8_calibrate_DW.Scope_PWORK.LoggedData), 11, 0, 5 },

  { (char_T *)(&heli_q8_calibrate_DW.HILInitialize_ClockModes[0]), 6, 0, 43 },

  { (char_T *)(&heli_q8_calibrate_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 },

  { (char_T *)(&heli_q8_calibrate_DW.StreamCall1_State), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&heli_q8_calibrate_P.calibrate_time), 0, 0, 20 },

  { (char_T *)(&heli_q8_calibrate_P.HILInitialize_hardware_clocks[0]), 6, 0, 9 },

  { (char_T *)(&heli_q8_calibrate_P.HILInitialize_analog_input_chan[0]), 7, 0,
    33 },

  { (char_T *)(&heli_q8_calibrate_P.HILInitialize_active), 8, 0, 35 },

  { (char_T *)(&heli_q8_calibrate_P.Constant_Value), 0, 0, 62 },

  { (char_T *)(&heli_q8_calibrate_P.StreamCall1_SendBufferSize), 6, 0, 2 },

  { (char_T *)(&heli_q8_calibrate_P.StreamFormattedWrite_MaxUnits), 7, 0, 1 },

  { (char_T *)(&heli_q8_calibrate_P.StringConstant_Value[0]), 3, 0, 257 },

  { (char_T *)(&heli_q8_calibrate_P.StreamCall1_Active), 8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] heli_q8_calibrate_dt.h */
