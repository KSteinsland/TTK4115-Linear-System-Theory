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
Joystick_gain_y = 1;


%%%%%%%%%%% Test references
pitch_test = 1;
elevation_test = 0;

%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]

J_p = 2 * m_p * l_p * l_p;
J_e = m_c * l_c * l_c + 2 * m_p * l_h * l_h;
J_lam = m_c * l_c * l_c + 2 * m_p * (l_h * l_h + l_p * l_p);

V_s0 = 7.5;

L_2 = g * ( m_c * l_c - 2 * m_p * l_h );

K_f = - L_2 / (l_h * V_s0);

L_1 = l_p * K_f; % minus foran egentlig :))
L_3 = l_h * K_f;
L_4 = l_h * K_f;

K_1 = L_1 / J_p;
K_2 = L_3 / J_e;
K_3 = L_4 * V_s0 / J_lam;

B = [0 0; 0 K_1; K_2 0];
A = [0 1 0; 0 0 0; 0 0 0];

mag = 2.5;%2.5 og pi / 4 er best
ang = pi / 4;


lambda_1 = complex(-mag*cos(ang), mag*sin(ang));
lambda_2 = conj(lambda_1);
lambda_3 = complex(-6/5*mag, 0);


p = [lambda_1, lambda_2, lambda_3];

K = place(A, B, p);
F = [ K(1,1) K(1,3); K(2,1) K(2,3)];

