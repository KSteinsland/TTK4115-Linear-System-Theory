  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_2015_day3_P)
    ;%
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.A
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.B
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 25;
	
	  ;% heli_q8_2015_day3_P.C
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 35;
	
	  ;% heli_q8_2015_day3_P.F
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 60;
	
	  ;% heli_q8_2015_day3_P.Joystick_gain_x
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 64;
	
	  ;% heli_q8_2015_day3_P.Joystick_gain_y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 65;
	
	  ;% heli_q8_2015_day3_P.K
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 66;
	
	  ;% heli_q8_2015_day3_P.L
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 80;
	
	  ;% heli_q8_2015_day3_P.V_s0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 105;
	
	  ;% heli_q8_2015_day3_P.calibrate_time
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 106;
	
	  ;% heli_q8_2015_day3_P.elevation_offset
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 107;
	
	  ;% heli_q8_2015_day3_P.elevation_test
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 108;
	
	  ;% heli_q8_2015_day3_P.imu_start
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 109;
	
	  ;% heli_q8_2015_day3_P.num_measures
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 114;
	
	  ;% heli_q8_2015_day3_P.pitch_test
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 115;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_analog_input_maxi
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 116;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_analog_input_mini
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 117;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_analog_output_max
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 118;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_analog_output_min
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 119;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_final_analog_outp
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 120;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_final_pwm_outputs
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 121;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_initial_analog_ou
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 122;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_initial_pwm_outpu
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 123;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_frequency
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 124;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_leading_deadb
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 125;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_trailing_dead
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 126;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_other_outputs
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 127;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_other_outpu_m
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 128;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_other_outpu_k
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 129;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_other_outpu_j
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 130;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_watchdog_analog_o
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 131;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_watchdog_pwm_outp
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 132;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.HILReadEncoderTimebase_clock
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_hardware_clocks
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_initial_encoder_c
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_alignment
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_configuration
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_modes
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_polarity
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_watchdog_digital_
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_2015_day3_P.HILReadEncoderTimebase_channels
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_2015_day3_P.HILWriteAnalog_channels
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_encoder_channels
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 21;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_pwm_channels
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 29;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_quadrature
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 37;
	
	  ;% heli_q8_2015_day3_P.HILReadEncoderTimebase_samples_
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 38;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_inpu_m
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_outp_b
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_outp_e
	  section.data(8).logicalSrcIdx = 55;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_outp_j
	  section.data(9).logicalSrcIdx = 56;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_outp_c
	  section.data(10).logicalSrcIdx = 57;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_out_ex
	  section.data(11).logicalSrcIdx = 58;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_analog_outp_p
	  section.data(12).logicalSrcIdx = 59;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 60;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_clock_frequ_e
	  section.data(14).logicalSrcIdx = 61;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 62;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_clock_param_c
	  section.data(16).logicalSrcIdx = 63;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 64;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_digital_out_b
	  section.data(18).logicalSrcIdx = 65;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_digital_out_c
	  section.data(19).logicalSrcIdx = 66;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_digital_ou_c1
	  section.data(20).logicalSrcIdx = 67;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_digital_out_a
	  section.data(21).logicalSrcIdx = 68;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_digital_out_j
	  section.data(22).logicalSrcIdx = 69;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_digital_out_m
	  section.data(23).logicalSrcIdx = 70;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 71;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_encoder_cou_k
	  section.data(25).logicalSrcIdx = 72;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 73;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_encoder_par_m
	  section.data(27).logicalSrcIdx = 74;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_other_outpu_l
	  section.data(28).logicalSrcIdx = 75;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 76;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_pwm_outputs_g
	  section.data(30).logicalSrcIdx = 77;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_pwm_outputs_p
	  section.data(31).logicalSrcIdx = 78;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_pwm_output_ap
	  section.data(32).logicalSrcIdx = 79;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 80;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 81;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_2015_day3_P.HILInitialize_set_pwm_params__f
	  section.data(35).logicalSrcIdx = 82;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 93;
      section.data(93)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.Constant1_Value
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.Constant_Value
	  section.data(2).logicalSrcIdx = 84;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_2015_day3_P.Constant1_Value_c
	  section.data(3).logicalSrcIdx = 85;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_2015_day3_P.Constant_Value_g
	  section.data(4).logicalSrcIdx = 86;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_2015_day3_P.RateTransitionx_X0
	  section.data(5).logicalSrcIdx = 87;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_2015_day3_P.DeadZonex_Start
	  section.data(6).logicalSrcIdx = 88;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_2015_day3_P.DeadZonex_End
	  section.data(7).logicalSrcIdx = 89;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_2015_day3_P.Gainx_Gain
	  section.data(8).logicalSrcIdx = 90;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_2015_day3_P.RateTransitiony_X0
	  section.data(9).logicalSrcIdx = 91;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_2015_day3_P.DeadZoney_Start
	  section.data(10).logicalSrcIdx = 92;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_2015_day3_P.DeadZoney_End
	  section.data(11).logicalSrcIdx = 93;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_2015_day3_P.Gainy_Gain
	  section.data(12).logicalSrcIdx = 94;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_2015_day3_P.Step_Time
	  section.data(13).logicalSrcIdx = 95;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_2015_day3_P.Step_Y0
	  section.data(14).logicalSrcIdx = 96;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_2015_day3_P.Step_YFinal
	  section.data(15).logicalSrcIdx = 97;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator_Amp
	  section.data(16).logicalSrcIdx = 98;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator_Period
	  section.data(17).logicalSrcIdx = 99;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator_Duty
	  section.data(18).logicalSrcIdx = 100;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator_PhaseDelay
	  section.data(19).logicalSrcIdx = 101;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_2015_day3_P.Step1_Time
	  section.data(20).logicalSrcIdx = 102;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_2015_day3_P.Step1_Y0
	  section.data(21).logicalSrcIdx = 103;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_2015_day3_P.Step1_YFinal
	  section.data(22).logicalSrcIdx = 104;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_2015_day3_P.Step2_Y0
	  section.data(23).logicalSrcIdx = 105;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_2015_day3_P.Step2_YFinal
	  section.data(24).logicalSrcIdx = 106;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator1_Amp
	  section.data(25).logicalSrcIdx = 107;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator1_Period
	  section.data(26).logicalSrcIdx = 108;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator1_Duty
	  section.data(27).logicalSrcIdx = 109;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_2015_day3_P.PulseGenerator1_PhaseDelay
	  section.data(28).logicalSrcIdx = 110;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_2015_day3_P.Constant_Value_b
	  section.data(29).logicalSrcIdx = 111;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_2015_day3_P.Integrator_IC
	  section.data(30).logicalSrcIdx = 112;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_2015_day3_P.Integrator1_IC
	  section.data(31).logicalSrcIdx = 113;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_2015_day3_P.Integrator_IC_b
	  section.data(32).logicalSrcIdx = 114;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_2015_day3_P.waitcalibrate_Y0
	  section.data(33).logicalSrcIdx = 115;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_2015_day3_P.waitcalibrate_YFinal
	  section.data(34).logicalSrcIdx = 116;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_2015_day3_P.waitcalibrate1_Y0
	  section.data(35).logicalSrcIdx = 117;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_2015_day3_P.waitcalibrate1_YFinal
	  section.data(36).logicalSrcIdx = 118;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_2015_day3_P.Backgain_Gain
	  section.data(37).logicalSrcIdx = 119;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_2015_day3_P.Frontgain_Gain
	  section.data(38).logicalSrcIdx = 120;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_2015_day3_P.Constant_Value_c
	  section.data(39).logicalSrcIdx = 121;
	  section.data(39).dtTransOffset = 38;
	
	  ;% heli_q8_2015_day3_P.Constant1_Value_d
	  section.data(40).logicalSrcIdx = 122;
	  section.data(40).dtTransOffset = 39;
	
	  ;% heli_q8_2015_day3_P.Memory_X0
	  section.data(41).logicalSrcIdx = 123;
	  section.data(41).dtTransOffset = 40;
	
	  ;% heli_q8_2015_day3_P.Gain1_Gain
	  section.data(42).logicalSrcIdx = 124;
	  section.data(42).dtTransOffset = 50;
	
	  ;% heli_q8_2015_day3_P.Gain2_Gain
	  section.data(43).logicalSrcIdx = 125;
	  section.data(43).dtTransOffset = 59;
	
	  ;% heli_q8_2015_day3_P.Step_Y0_o
	  section.data(44).logicalSrcIdx = 126;
	  section.data(44).dtTransOffset = 68;
	
	  ;% heli_q8_2015_day3_P.Step_YFinal_j
	  section.data(45).logicalSrcIdx = 127;
	  section.data(45).dtTransOffset = 69;
	
	  ;% heli_q8_2015_day3_P.Memory_X0_f
	  section.data(46).logicalSrcIdx = 128;
	  section.data(46).dtTransOffset = 70;
	
	  ;% heli_q8_2015_day3_P.Memory_X0_fk
	  section.data(47).logicalSrcIdx = 129;
	  section.data(47).dtTransOffset = 71;
	
	  ;% heli_q8_2015_day3_P.Constant2_Value
	  section.data(48).logicalSrcIdx = 130;
	  section.data(48).dtTransOffset = 72;
	
	  ;% heli_q8_2015_day3_P.Constant_Value_j
	  section.data(49).logicalSrcIdx = 131;
	  section.data(49).dtTransOffset = 73;
	
	  ;% heli_q8_2015_day3_P.Memory_X0_d
	  section.data(50).logicalSrcIdx = 132;
	  section.data(50).dtTransOffset = 74;
	
	  ;% heli_q8_2015_day3_P.Memory_X0_a
	  section.data(51).logicalSrcIdx = 133;
	  section.data(51).dtTransOffset = 75;
	
	  ;% heli_q8_2015_day3_P.Memory_X0_n
	  section.data(52).logicalSrcIdx = 134;
	  section.data(52).dtTransOffset = 76;
	
	  ;% heli_q8_2015_day3_P.Switch_Threshold
	  section.data(53).logicalSrcIdx = 135;
	  section.data(53).dtTransOffset = 77;
	
	  ;% heli_q8_2015_day3_P.Step_Y0_c
	  section.data(54).logicalSrcIdx = 136;
	  section.data(54).dtTransOffset = 78;
	
	  ;% heli_q8_2015_day3_P.Step_YFinal_i
	  section.data(55).logicalSrcIdx = 137;
	  section.data(55).dtTransOffset = 79;
	
	  ;% heli_q8_2015_day3_P.Switch_Threshold_i
	  section.data(56).logicalSrcIdx = 138;
	  section.data(56).dtTransOffset = 80;
	
	  ;% heli_q8_2015_day3_P.Step_Y0_f
	  section.data(57).logicalSrcIdx = 139;
	  section.data(57).dtTransOffset = 81;
	
	  ;% heli_q8_2015_day3_P.Step_YFinal_b
	  section.data(58).logicalSrcIdx = 140;
	  section.data(58).dtTransOffset = 82;
	
	  ;% heli_q8_2015_day3_P.Step1_Y0_k
	  section.data(59).logicalSrcIdx = 141;
	  section.data(59).dtTransOffset = 83;
	
	  ;% heli_q8_2015_day3_P.Step1_YFinal_j
	  section.data(60).logicalSrcIdx = 142;
	  section.data(60).dtTransOffset = 84;
	
	  ;% heli_q8_2015_day3_P.Switch_Threshold_k
	  section.data(61).logicalSrcIdx = 143;
	  section.data(61).dtTransOffset = 85;
	
	  ;% heli_q8_2015_day3_P.Step_Y0_n
	  section.data(62).logicalSrcIdx = 144;
	  section.data(62).dtTransOffset = 86;
	
	  ;% heli_q8_2015_day3_P.Step_YFinal_k
	  section.data(63).logicalSrcIdx = 145;
	  section.data(63).dtTransOffset = 87;
	
	  ;% heli_q8_2015_day3_P.Switch_Threshold_f
	  section.data(64).logicalSrcIdx = 146;
	  section.data(64).dtTransOffset = 88;
	
	  ;% heli_q8_2015_day3_P.Step_Y0_ci
	  section.data(65).logicalSrcIdx = 147;
	  section.data(65).dtTransOffset = 89;
	
	  ;% heli_q8_2015_day3_P.Step_YFinal_g
	  section.data(66).logicalSrcIdx = 148;
	  section.data(66).dtTransOffset = 90;
	
	  ;% heli_q8_2015_day3_P.Step1_Y0_l
	  section.data(67).logicalSrcIdx = 149;
	  section.data(67).dtTransOffset = 91;
	
	  ;% heli_q8_2015_day3_P.Step1_YFinal_l
	  section.data(68).logicalSrcIdx = 150;
	  section.data(68).dtTransOffset = 92;
	
	  ;% heli_q8_2015_day3_P.Switch_Threshold_c
	  section.data(69).logicalSrcIdx = 151;
	  section.data(69).dtTransOffset = 93;
	
	  ;% heli_q8_2015_day3_P.Step_Y0_k
	  section.data(70).logicalSrcIdx = 152;
	  section.data(70).dtTransOffset = 94;
	
	  ;% heli_q8_2015_day3_P.Step_YFinal_jm
	  section.data(71).logicalSrcIdx = 153;
	  section.data(71).dtTransOffset = 95;
	
	  ;% heli_q8_2015_day3_P.Step1_Y0_f
	  section.data(72).logicalSrcIdx = 154;
	  section.data(72).dtTransOffset = 96;
	
	  ;% heli_q8_2015_day3_P.Step1_YFinal_f
	  section.data(73).logicalSrcIdx = 155;
	  section.data(73).dtTransOffset = 97;
	
	  ;% heli_q8_2015_day3_P.Switch_Threshold_e
	  section.data(74).logicalSrcIdx = 156;
	  section.data(74).dtTransOffset = 98;
	
	  ;% heli_q8_2015_day3_P.ElevationCounttorad_Gain
	  section.data(75).logicalSrcIdx = 157;
	  section.data(75).dtTransOffset = 99;
	
	  ;% heli_q8_2015_day3_P.ElevationTransferFcn_A
	  section.data(76).logicalSrcIdx = 158;
	  section.data(76).dtTransOffset = 100;
	
	  ;% heli_q8_2015_day3_P.ElevationTransferFcn_C
	  section.data(77).logicalSrcIdx = 159;
	  section.data(77).dtTransOffset = 101;
	
	  ;% heli_q8_2015_day3_P.ElevationTransferFcn_D
	  section.data(78).logicalSrcIdx = 160;
	  section.data(78).dtTransOffset = 102;
	
	  ;% heli_q8_2015_day3_P.Constant_Value_f
	  section.data(79).logicalSrcIdx = 161;
	  section.data(79).dtTransOffset = 103;
	
	  ;% heli_q8_2015_day3_P.PitchCounttorad_Gain
	  section.data(80).logicalSrcIdx = 162;
	  section.data(80).dtTransOffset = 104;
	
	  ;% heli_q8_2015_day3_P.PitchTransferFcn_A
	  section.data(81).logicalSrcIdx = 163;
	  section.data(81).dtTransOffset = 105;
	
	  ;% heli_q8_2015_day3_P.PitchTransferFcn_C
	  section.data(82).logicalSrcIdx = 164;
	  section.data(82).dtTransOffset = 106;
	
	  ;% heli_q8_2015_day3_P.PitchTransferFcn_D
	  section.data(83).logicalSrcIdx = 165;
	  section.data(83).dtTransOffset = 107;
	
	  ;% heli_q8_2015_day3_P.TravelCounttorad_Gain
	  section.data(84).logicalSrcIdx = 166;
	  section.data(84).dtTransOffset = 108;
	
	  ;% heli_q8_2015_day3_P.TravelTransferFcn_A
	  section.data(85).logicalSrcIdx = 167;
	  section.data(85).dtTransOffset = 109;
	
	  ;% heli_q8_2015_day3_P.TravelTransferFcn_C
	  section.data(86).logicalSrcIdx = 168;
	  section.data(86).dtTransOffset = 110;
	
	  ;% heli_q8_2015_day3_P.TravelTransferFcn_D
	  section.data(87).logicalSrcIdx = 169;
	  section.data(87).dtTransOffset = 111;
	
	  ;% heli_q8_2015_day3_P.FrontmotorSaturation_UpperSat
	  section.data(88).logicalSrcIdx = 170;
	  section.data(88).dtTransOffset = 112;
	
	  ;% heli_q8_2015_day3_P.FrontmotorSaturation_LowerSat
	  section.data(89).logicalSrcIdx = 171;
	  section.data(89).dtTransOffset = 113;
	
	  ;% heli_q8_2015_day3_P.BackmotorSaturation_UpperSat
	  section.data(90).logicalSrcIdx = 172;
	  section.data(90).dtTransOffset = 114;
	
	  ;% heli_q8_2015_day3_P.BackmotorSaturation_LowerSat
	  section.data(91).logicalSrcIdx = 173;
	  section.data(91).dtTransOffset = 115;
	
	  ;% heli_q8_2015_day3_P.waitcalibrate1_Y0_o
	  section.data(92).logicalSrcIdx = 174;
	  section.data(92).dtTransOffset = 116;
	
	  ;% heli_q8_2015_day3_P.waitcalibrate1_YFinal_f
	  section.data(93).logicalSrcIdx = 175;
	  section.data(93).dtTransOffset = 117;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.StreamCall1_SendBufferSize
	  section.data(1).logicalSrcIdx = 176;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.StreamCall1_ReceiveBufferSize
	  section.data(2).logicalSrcIdx = 177;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.StreamFormattedWrite_MaxUnits
	  section.data(1).logicalSrcIdx = 178;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 179;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.StringConstant_Value
	  section.data(1).logicalSrcIdx = 180;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.StreamCall1_URI
	  section.data(2).logicalSrcIdx = 181;
	  section.data(2).dtTransOffset = 255;
	
	  ;% heli_q8_2015_day3_P.StreamCall1_Endian
	  section.data(3).logicalSrcIdx = 182;
	  section.data(3).dtTransOffset = 256;
	
	  ;% heli_q8_2015_day3_P.GameController_ControllerNumber
	  section.data(4).logicalSrcIdx = 183;
	  section.data(4).dtTransOffset = 257;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_P.HILReadEncoderTimebase_Active
	  section.data(1).logicalSrcIdx = 184;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_P.StreamCall1_Active
	  section.data(2).logicalSrcIdx = 185;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_2015_day3_P.HILWriteAnalog_Active
	  section.data(3).logicalSrcIdx = 186;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_2015_day3_P.GameController_AutoCenter
	  section.data(4).logicalSrcIdx = 187;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_2015_day3_P.GameController_Enabled
	  section.data(5).logicalSrcIdx = 188;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_2015_day3_B)
    ;%
      section.nData     = 50;
      section.data(50)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_B.RateTransitionx
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_B.Joystick_gain_x
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_2015_day3_B.RateTransitiony
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_2015_day3_B.Joystick_gain_y
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_2015_day3_B.PulseGenerator
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_2015_day3_B.Sum1
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_2015_day3_B.Sum
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_2015_day3_B.Integrator
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
	  ;% heli_q8_2015_day3_B.Sum_j
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 13;
	
	  ;% heli_q8_2015_day3_B.Product1
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 15;
	
	  ;% heli_q8_2015_day3_B.Product
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 16;
	
	  ;% heli_q8_2015_day3_B.Switch
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 17;
	
	  ;% heli_q8_2015_day3_B.Constant1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 27;
	
	  ;% heli_q8_2015_day3_B.Memory
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 32;
	
	  ;% heli_q8_2015_day3_B.Switch1
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 33;
	
	  ;% heli_q8_2015_day3_B.Sum_h
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 34;
	
	  ;% heli_q8_2015_day3_B.Memory_n
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 35;
	
	  ;% heli_q8_2015_day3_B.Sum1_p
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 36;
	
	  ;% heli_q8_2015_day3_B.Sum1_d
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 37;
	
	  ;% heli_q8_2015_day3_B.Memory_o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 38;
	
	  ;% heli_q8_2015_day3_B.Sum2
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 39;
	
	  ;% heli_q8_2015_day3_B.Memory_ns
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 40;
	
	  ;% heli_q8_2015_day3_B.Sum3
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 41;
	
	  ;% heli_q8_2015_day3_B.Memory_f
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 42;
	
	  ;% heli_q8_2015_day3_B.Sum5
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 43;
	
	  ;% heli_q8_2015_day3_B.Switch_m
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 44;
	
	  ;% heli_q8_2015_day3_B.Sum_k
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 49;
	
	  ;% heli_q8_2015_day3_B.Switch_l
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 50;
	
	  ;% heli_q8_2015_day3_B.Sum_a
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 51;
	
	  ;% heli_q8_2015_day3_B.Switch_n
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 52;
	
	  ;% heli_q8_2015_day3_B.Sum_ac
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 53;
	
	  ;% heli_q8_2015_day3_B.Switch_e
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 54;
	
	  ;% heli_q8_2015_day3_B.Sum_hy
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 55;
	
	  ;% heli_q8_2015_day3_B.Switch_eu
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 56;
	
	  ;% heli_q8_2015_day3_B.Sum_b
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 57;
	
	  ;% heli_q8_2015_day3_B.Switch_k
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 58;
	
	  ;% heli_q8_2015_day3_B.ElevationCounttorad
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 59;
	
	  ;% heli_q8_2015_day3_B.ElevationTransferFcn
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 60;
	
	  ;% heli_q8_2015_day3_B.Sum_jp
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 61;
	
	  ;% heli_q8_2015_day3_B.PitchCounttorad
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 62;
	
	  ;% heli_q8_2015_day3_B.PitchTransferFcn
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 63;
	
	  ;% heli_q8_2015_day3_B.TravelCounttorad
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 64;
	
	  ;% heli_q8_2015_day3_B.TravelTransferFcn
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 65;
	
	  ;% heli_q8_2015_day3_B.FrontmotorSaturation
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 66;
	
	  ;% heli_q8_2015_day3_B.BackmotorSaturation
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 67;
	
	  ;% heli_q8_2015_day3_B.GameController_o4
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 68;
	
	  ;% heli_q8_2015_day3_B.GameController_o5
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 69;
	
	  ;% heli_q8_2015_day3_B.Sum_n
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 70;
	
	  ;% heli_q8_2015_day3_B.Sum1_h
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 71;
	
	  ;% heli_q8_2015_day3_B.Sum1_e
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 72;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_B.StreamCall1_o2
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 2;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (heli_q8_2015_day3_DW)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% heli_q8_2015_day3_DW.RateTransitionx_Buffer0
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% heli_q8_2015_day3_DW.RateTransitiony_Buffer0
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% heli_q8_2015_day3_DW.Memory_PreviousInput
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 66;
	
	  ;% heli_q8_2015_day3_DW.Memory_PreviousInput_i
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 76;
	
	  ;% heli_q8_2015_day3_DW.Memory_PreviousInput_k
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 77;
	
	  ;% heli_q8_2015_day3_DW.Memory_PreviousInput_c
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 78;
	
	  ;% heli_q8_2015_day3_DW.Memory_PreviousInput_l
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 79;
	
	  ;% heli_q8_2015_day3_DW.Memory_PreviousInput_a
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 80;
	
	  ;% heli_q8_2015_day3_DW.HILWriteAnalog_Buffer
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 81;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.StreamCall1_Stream
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.u_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_DW.Connected_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 2;
	
	  ;% heli_q8_2015_day3_DW.elevationimu_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 3;
	
	  ;% heli_q8_2015_day3_DW.pitchimu_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 4;
	
	  ;% heli_q8_2015_day3_DW.ElevationScoperads_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 5;
	
	  ;% heli_q8_2015_day3_DW.ElevationScoperad_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 6;
	
	  ;% heli_q8_2015_day3_DW.PitchScoperad_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 7;
	
	  ;% heli_q8_2015_day3_DW.PtichrateScoperads_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 8;
	
	  ;% heli_q8_2015_day3_DW.TravelrateScoperads_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 9;
	
	  ;% heli_q8_2015_day3_DW.TravelScoperad_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 10;
	
	  ;% heli_q8_2015_day3_DW.HILWriteAnalog_PWORK
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 11;
	
	  ;% heli_q8_2015_day3_DW.Scope_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 12;
	
	  ;% heli_q8_2015_day3_DW.XScope_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 33;
	  section.data(13).dtTransOffset = 14;
	
	  ;% heli_q8_2015_day3_DW.YScope_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 34;
	  section.data(14).dtTransOffset = 15;
	
	  ;% heli_q8_2015_day3_DW.ToFile_PWORK.FilePtr
	  section.data(15).logicalSrcIdx = 35;
	  section.data(15).dtTransOffset = 16;
	
	  ;% heli_q8_2015_day3_DW.Scopeelevation_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 36;
	  section.data(16).dtTransOffset = 17;
	
	  ;% heli_q8_2015_day3_DW.Scopeelevationrate_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 37;
	  section.data(17).dtTransOffset = 20;
	
	  ;% heli_q8_2015_day3_DW.Scopepitch_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 38;
	  section.data(18).dtTransOffset = 24;
	
	  ;% heli_q8_2015_day3_DW.Scopepitchrate_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 39;
	  section.data(19).dtTransOffset = 28;
	
	  ;% heli_q8_2015_day3_DW.Scopetravelrate_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 40;
	  section.data(20).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 44;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 45;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_2015_day3_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 46;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_2015_day3_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 47;
	  section.data(7).dtTransOffset = 43;
	
	  ;% heli_q8_2015_day3_DW.clockTickCounter
	  section.data(8).logicalSrcIdx = 48;
	  section.data(8).dtTransOffset = 46;
	
	  ;% heli_q8_2015_day3_DW.clockTickCounter_e
	  section.data(9).logicalSrcIdx = 49;
	  section.data(9).dtTransOffset = 47;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_2015_day3_DW.StreamCall1_State
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 4270170693;
  targMap.checksum1 = 535089354;
  targMap.checksum2 = 3950321240;
  targMap.checksum3 = 1280757895;

