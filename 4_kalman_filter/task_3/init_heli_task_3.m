% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 0.5;
Joystick_gain_y = 0.5;

%%%%%%%%%%% Test references
pitch_test = 1;
elevation_test = 0;

%%%%%%%%%%% USB Serial Port
PORT = 12;

T = 0.002; % Timestep used in simulink

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

% Offsets
elevation_offset = -0.53;

%bad_elevation_rate = 0.0;
enc_p = 0;

%Calibration
calibrate_time = 2;
num_measures = calibrate_time / T;

imu_start = [0 0 -0.53 0 0 0]';

A = [0 1 0 0 0 0; 
     0 0 0 0 0 0; 
     0 0 0 1 0 0; 
     0 0 0 0 0 0;
     0 0 0 0 0 1;
     K_3 0 0 0 0 0];

B = [0 0; 
     0 K_1;
     0 0;
     K_2 0;
     0 0;
     0 0];

C = [1 0 0 0 0 0; 
     0 1 0 0 0 0; 
     0 0 1 0 0 0; 
     0 0 0 1 0 0; 
     0 0 0 0 0 1];

A_a = [0 1 0 0 0 0 0 0; 
     0 0 0 0 0 0 0 0; 
     0 0 0 1 0 0 0 0; 
     0 0 0 0 0 0 0 0;
     0 0 0 0 0 0 0 1;
     K_3 0 0 0 0 0 0 0;
     1 0 0 0 0 0 0 0;
     0 0 0 1 0 0 0 0];

B_a = [0 0;
       0 K_1; 
       0 0; 
       K_2 0; 
       0 0; 
       0 0; 
       0 0; 
       0 0];

C_a = [1 0 0 0 0 0 0 0; 
        0 1 0 0 0 0 0 0;
        0 0 1 0 0 0 0 0;
        0 0 0 1 0 0 0 0;
        0 0 0 0 0 1 0 0];

% q_p = 51; % 61.2313; 
% q_pd = 10.1; % 15.1; 
% q_e = 90; % 0.9; 
% q_ed = 590.21; % 90;
% q_lambda = 0.12;%10;%0.12; % 1;
% q_lamdad = 3.1;%30; % 3; 
% q_gamma = 4.813; % 2.844;
% q_zeta = 10.24329512; % 5;

q_p = 100; 
q_pd = 1; 
q_e = 1.111; 
q_ed = 100;
q_lambda = 0.12;
q_lamdad = 10.668; % 1; 
q_gamma = 25;
q_zeta = 100;


Q = [q_p 0 0 0 0 0; 
     0 q_pd 0 0 0 0; 
     0 0 q_e 0 0 0; 
     0 0 0 q_ed 0 0;
     0 0 0 0 q_lambda 0;
     0 0 0 0 0 q_lamdad];

Q_a = [q_p 0 0 0 0 0 0 0; 
     0 q_pd 0 0 0 0 0 0; 
     0 0 q_e 0 0 0 0 0; 
     0 0 0 q_ed 0 0 0 0;
     0 0 0 0 q_lambda 0 0 0
     0 0 0 0 0 q_lamdad 0 0;
     0 0 0 0 0 0 q_gamma 0;
     0 0 0 0 0 0 0 q_zeta];

r_vs = 1; 
r_vd = 1;
R = [r_vs 0; 0 r_vd];


% Measurement noise, found experimentally in task 1
% High Lambdad value
R_d =[

    0.0058    0.0050    0.0039   -0.0058   -0.0003;
    0.0050    0.0055    0.0047   -0.0053   -0.0002;
    0.0039    0.0047    0.0207   -0.0064    0.0003;
   -0.0058   -0.0053   -0.0064    0.0078   -0.0002;
   -0.0003   -0.0002    0.0003   -0.0002    0.0009];

qq_test = 0.000001;

qq_p        = 0.000001;
qq_pd       = 0.0001;
qq_e        = 0.00001;
qq_ed       = 0.00001;
qq_lambda   = 0.0000001;
qq_lambdad  = 0.000001;

Q_d = [qq_p 0 0 0 0 0; 
       0 qq_pd 0 0 0 0; 
       0 0 qq_e 0 0 0; 
       0 0 0 qq_ed 0 0;
       0 0 0 0 qq_lambda 0;
       0 0 0 0 0 qq_lambdad]; % Uncertainty


  
% Q_d = diag(q_vals);

sys = ss(A, B, C, 0);
sys_d = c2d(sys, T);
A_d = sys_d.A;
B_d = sys_d.B;
C_d = sys_d.C;

K = lqr(A_a, B_a, Q_a, R);
k_a = K(1:2, 7:8);

A_p = A_a - B_a*K
sys = ss(A_p,B_a,C_a,0);

p = pole(sys)
plot(p, 'o');


F = [K(1,1) K(1,4); K(2,1) K(2,4)];

x_hat_0 = [ 0 0 -0.53 0 0 0 ]';
P_hat_0 = zeros(6,6);
y_0 = C*x_hat_0;


