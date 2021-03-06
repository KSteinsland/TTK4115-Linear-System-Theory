% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert h?sten 2006 av Jostein Bakkeheim
% Oppdatert h?sten 2008 av Arnfinn Aas Eielsen
% Oppdatert h?sten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]

V_s0 = 7.5;
L_2 = g * ( m_c * l_c - 2 * m_p * l_h );
K_f = - L_2 / ( l_h * V_s0 );
K_1 = K_f / ( 2 * m_p * l_p );

mag = 2.5;%2.5 og pi / 4 er best
ang =  pi / 4;

lambda_1 = complex(-mag*cos(ang), mag*sin(ang));
lambda_2 = conj(lambda_1);

K_pd = - ( lambda_1 + lambda_2 ) / K_1;
K_pp = lambda_1 * lambda_2 / K_1;
