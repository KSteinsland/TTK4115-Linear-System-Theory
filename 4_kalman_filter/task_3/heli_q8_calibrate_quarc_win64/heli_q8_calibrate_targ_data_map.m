  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 9;
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
    ;% Auto data (heli_q8_calibrate_P)
    ;%
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.calibrate_time
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_P.elevation_offset
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_calibrate_P.num_measures
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_calibrate_P.HILInitialize_analog_input_maxi
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_calibrate_P.HILInitialize_analog_input_mini
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_calibrate_P.HILInitialize_analog_output_max
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_calibrate_P.HILInitialize_analog_output_min
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_calibrate_P.HILInitialize_final_analog_outp
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_calibrate_P.HILInitialize_final_pwm_outputs
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_calibrate_P.HILInitialize_initial_analog_ou
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_calibrate_P.HILInitialize_initial_pwm_outpu
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_frequency
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_leading_deadb
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_trailing_dead
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_other_outputs
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_other_outpu_m
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_other_outpu_k
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_other_outpu_j
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_calibrate_P.HILInitialize_watchdog_analog_o
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_calibrate_P.HILInitialize_watchdog_pwm_outp
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.HILInitialize_hardware_clocks
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_P.HILInitialize_initial_encoder_c
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_alignment
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_configuration
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_modes
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_polarity
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_calibrate_P.HILInitialize_watchdog_digital_
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.HILInitialize_analog_input_chan
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_P.HILInitialize_analog_output_cha
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_calibrate_P.HILInitialize_encoder_channels
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_calibrate_P.HILInitialize_pwm_channels
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_calibrate_P.HILInitialize_quadrature
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 32;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.HILInitialize_active
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_P.HILInitialize_final_digital_out
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_calibrate_P.HILInitialize_initial_digital_o
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_input_
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_inpu_m
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_output
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_outp_b
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_outp_e
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_outp_j
	  section.data(9).logicalSrcIdx = 40;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_outp_c
	  section.data(10).logicalSrcIdx = 41;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_out_ex
	  section.data(11).logicalSrcIdx = 42;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_analog_outp_p
	  section.data(12).logicalSrcIdx = 43;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_clock_frequen
	  section.data(13).logicalSrcIdx = 44;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_clock_frequ_e
	  section.data(14).logicalSrcIdx = 45;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_clock_params_
	  section.data(15).logicalSrcIdx = 46;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_clock_param_c
	  section.data(16).logicalSrcIdx = 47;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_digital_outpu
	  section.data(17).logicalSrcIdx = 48;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_digital_out_b
	  section.data(18).logicalSrcIdx = 49;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_digital_out_c
	  section.data(19).logicalSrcIdx = 50;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_digital_ou_c1
	  section.data(20).logicalSrcIdx = 51;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_digital_out_a
	  section.data(21).logicalSrcIdx = 52;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_digital_out_j
	  section.data(22).logicalSrcIdx = 53;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_digital_out_m
	  section.data(23).logicalSrcIdx = 54;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_encoder_count
	  section.data(24).logicalSrcIdx = 55;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_encoder_cou_k
	  section.data(25).logicalSrcIdx = 56;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_encoder_param
	  section.data(26).logicalSrcIdx = 57;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_encoder_par_m
	  section.data(27).logicalSrcIdx = 58;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_other_outpu_l
	  section.data(28).logicalSrcIdx = 59;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_a
	  section.data(29).logicalSrcIdx = 60;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_g
	  section.data(30).logicalSrcIdx = 61;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_p
	  section.data(31).logicalSrcIdx = 62;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_pwm_output_ap
	  section.data(32).logicalSrcIdx = 63;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_pwm_outputs_o
	  section.data(33).logicalSrcIdx = 64;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_pwm_params_at
	  section.data(34).logicalSrcIdx = 65;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_calibrate_P.HILInitialize_set_pwm_params__f
	  section.data(35).logicalSrcIdx = 66;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.Constant_Value
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 68;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_calibrate_P.Constant_Value_g
	  section.data(3).logicalSrcIdx = 69;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_calibrate_P.Memory_X0
	  section.data(4).logicalSrcIdx = 70;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_calibrate_P.Memory_X0_k
	  section.data(5).logicalSrcIdx = 71;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_calibrate_P.Memory_X0_f
	  section.data(6).logicalSrcIdx = 72;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_calibrate_P.Memory_X0_a
	  section.data(7).logicalSrcIdx = 73;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_calibrate_P.Memory_X0_l
	  section.data(8).logicalSrcIdx = 74;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_calibrate_P.Step_Y0
	  section.data(9).logicalSrcIdx = 75;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_calibrate_P.Step_YFinal
	  section.data(10).logicalSrcIdx = 76;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_calibrate_P.Step_Y0_d
	  section.data(11).logicalSrcIdx = 77;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_calibrate_P.Step_YFinal_d
	  section.data(12).logicalSrcIdx = 78;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_calibrate_P.Constant_Value_c
	  section.data(13).logicalSrcIdx = 79;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_calibrate_P.Constant1_Value_d
	  section.data(14).logicalSrcIdx = 80;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_calibrate_P.Memory_X0_b
	  section.data(15).logicalSrcIdx = 81;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_calibrate_P.Gain2_Gain
	  section.data(16).logicalSrcIdx = 82;
	  section.data(16).dtTransOffset = 24;
	
	  ;% heli_q8_calibrate_P.Switch_Threshold
	  section.data(17).logicalSrcIdx = 83;
	  section.data(17).dtTransOffset = 33;
	
	  ;% heli_q8_calibrate_P.Step_Y0_j
	  section.data(18).logicalSrcIdx = 84;
	  section.data(18).dtTransOffset = 34;
	
	  ;% heli_q8_calibrate_P.Step_YFinal_m
	  section.data(19).logicalSrcIdx = 85;
	  section.data(19).dtTransOffset = 35;
	
	  ;% heli_q8_calibrate_P.Step1_Y0
	  section.data(20).logicalSrcIdx = 86;
	  section.data(20).dtTransOffset = 36;
	
	  ;% heli_q8_calibrate_P.Step1_YFinal
	  section.data(21).logicalSrcIdx = 87;
	  section.data(21).dtTransOffset = 37;
	
	  ;% heli_q8_calibrate_P.Gain1_Gain
	  section.data(22).logicalSrcIdx = 88;
	  section.data(22).dtTransOffset = 38;
	
	  ;% heli_q8_calibrate_P.Constant_Value_j
	  section.data(23).logicalSrcIdx = 89;
	  section.data(23).dtTransOffset = 47;
	
	  ;% heli_q8_calibrate_P.Switch_Threshold_c
	  section.data(24).logicalSrcIdx = 90;
	  section.data(24).dtTransOffset = 48;
	
	  ;% heli_q8_calibrate_P.Step_Y0_a
	  section.data(25).logicalSrcIdx = 91;
	  section.data(25).dtTransOffset = 49;
	
	  ;% heli_q8_calibrate_P.Step_YFinal_k
	  section.data(26).logicalSrcIdx = 92;
	  section.data(26).dtTransOffset = 50;
	
	  ;% heli_q8_calibrate_P.Switch_Threshold_f
	  section.data(27).logicalSrcIdx = 93;
	  section.data(27).dtTransOffset = 51;
	
	  ;% heli_q8_calibrate_P.Step_Y0_b
	  section.data(28).logicalSrcIdx = 94;
	  section.data(28).dtTransOffset = 52;
	
	  ;% heli_q8_calibrate_P.Step_YFinal_dc
	  section.data(29).logicalSrcIdx = 95;
	  section.data(29).dtTransOffset = 53;
	
	  ;% heli_q8_calibrate_P.Step1_Y0_l
	  section.data(30).logicalSrcIdx = 96;
	  section.data(30).dtTransOffset = 54;
	
	  ;% heli_q8_calibrate_P.Step1_YFinal_j
	  section.data(31).logicalSrcIdx = 97;
	  section.data(31).dtTransOffset = 55;
	
	  ;% heli_q8_calibrate_P.Switch_Threshold_cu
	  section.data(32).logicalSrcIdx = 98;
	  section.data(32).dtTransOffset = 56;
	
	  ;% heli_q8_calibrate_P.Step_Y0_o
	  section.data(33).logicalSrcIdx = 99;
	  section.data(33).dtTransOffset = 57;
	
	  ;% heli_q8_calibrate_P.Step_YFinal_m4
	  section.data(34).logicalSrcIdx = 100;
	  section.data(34).dtTransOffset = 58;
	
	  ;% heli_q8_calibrate_P.Step1_Y0_j
	  section.data(35).logicalSrcIdx = 101;
	  section.data(35).dtTransOffset = 59;
	
	  ;% heli_q8_calibrate_P.Step1_YFinal_f
	  section.data(36).logicalSrcIdx = 102;
	  section.data(36).dtTransOffset = 60;
	
	  ;% heli_q8_calibrate_P.Switch_Threshold_i
	  section.data(37).logicalSrcIdx = 103;
	  section.data(37).dtTransOffset = 61;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.StreamCall1_SendBufferSize
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_P.StreamCall1_ReceiveBufferSize
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.StreamFormattedWrite_MaxUnits
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.StringConstant_Value
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_P.StreamCall1_URI
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 255;
	
	  ;% heli_q8_calibrate_P.StreamCall1_Endian
	  section.data(3).logicalSrcIdx = 109;
	  section.data(3).dtTransOffset = 256;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_P.StreamCall1_Active
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
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
    ;% Auto data (heli_q8_calibrate_B)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_B.Memory
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_B.Divide
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_calibrate_B.Memory_a
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_calibrate_B.Divide_d
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_calibrate_B.Memory_d
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_calibrate_B.Divide_g
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_calibrate_B.Memory_dh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_calibrate_B.Divide_h
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_calibrate_B.Memory_k
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_calibrate_B.Divide_k
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_calibrate_B.Product
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_calibrate_B.Switch
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 15;
	
	  ;% heli_q8_calibrate_B.Switch1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 25;
	
	  ;% heli_q8_calibrate_B.Sum
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 26;
	
	  ;% heli_q8_calibrate_B.Switch_j
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 27;
	
	  ;% heli_q8_calibrate_B.Switch1_o
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 28;
	
	  ;% heli_q8_calibrate_B.Sum_b
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 29;
	
	  ;% heli_q8_calibrate_B.Switch_d
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 30;
	
	  ;% heli_q8_calibrate_B.Sum_l
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 31;
	
	  ;% heli_q8_calibrate_B.Switch_k
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% heli_q8_calibrate_B.Sum_k
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
	  ;% heli_q8_calibrate_B.Switch_e
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 34;
	
	  ;% heli_q8_calibrate_B.Sum_a
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 35;
	
	  ;% heli_q8_calibrate_B.Switch_h
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_B.StreamCall1_o2
	  section.data(1).logicalSrcIdx = 24;
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
    nTotSects     = 7;
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
    ;% Auto data (heli_q8_calibrate_DW)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_DW.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 32;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_FilterFrequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 40;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_POSortedFreqs
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_POValues
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 56;
	
	  ;% heli_q8_calibrate_DW.Memory_PreviousInput
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 64;
	
	  ;% heli_q8_calibrate_DW.Memory_PreviousInput_p
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 65;
	
	  ;% heli_q8_calibrate_DW.Memory_PreviousInput_ps
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 66;
	
	  ;% heli_q8_calibrate_DW.Memory_PreviousInput_l
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 67;
	
	  ;% heli_q8_calibrate_DW.Memory_PreviousInput_i
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 68;
	
	  ;% heli_q8_calibrate_DW.Memory_PreviousInput_c
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 69;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_DW.StreamCall1_Stream
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_DW.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_calibrate_DW.elevationimu_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_calibrate_DW.pitchimu_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_calibrate_DW.Connected_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_calibrate_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 35;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_calibrate_DW.StreamCall1_State
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
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


  targMap.checksum0 = 787375133;
  targMap.checksum1 = 4015194536;
  targMap.checksum2 = 4042632328;
  targMap.checksum3 = 3469145922;

