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
Joystick_gain_x = 0.5;
Joystick_gain_y = 0.5;

%%%%%%%%%%% Test references
pitch_test = 0;
elevation_test = 0;

%%%%%%%%%%% USB Serial Port
PORT = 12;

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

T = 0.002;
calibrate_time = 2;
num_measures = 2/T;
imu_start = [0 0 -0.53 0 0]';
elevation_offset = -0.53;

L_2 = g * ( m_c * l_c - 2 * m_p * l_h );

K_f = - L_2 / (l_h * V_s0);

L_1 = l_p * K_f; % minus foran egentlig :))
L_3 = l_h * K_f;
L_4 = l_h * K_f;

K_1 = L_1 / J_p;
K_2 = L_3 / J_e;
K_3 = L_4 * V_s0 / J_lam;

A = [0 1 0 0 0; 
     0 0 0 0 0; 
     0 0 0 1 0; 
     0 0 0 0 0; 
     K_3 0 0 0 0];
 
A_a = [0 1 0 0 0 0 0; 
     0 0 0 0 0 0 0; 
     0 0 0 1 0 0 0; 
     0 0 0 0 0 0 0; 
     K_3 0 0 0 0 0 0;
     1 0 0 0 0 0 0;
     0 0 0 1 0 0 0];
 
B = [0 0; 0 K_1; 0 0; K_2 0; 0 0];

B_a = [0 0; 0 K_1; 0 0; K_2 0; 0 0; 0 0; 0 0];


C = [1 0 0 0 0; 
     0 1 0 0 0; 
     0 0 1 0 0; 
     0 0 0 1 0; 
     0 0 0 0 1];
 

 
 C_a = [1 0 0 0 0 0 0; 
         0 0 0 0 0 0 0; 
         0 0 0 0 0 0 0; 
         0 0 0 1 0 0 0; 
         0 0 0 0 1 0 0];

q_p = 100; 
q_pd = 1; 
q_e = 1.11111111; 
q_ed = 100;
q_lamdad = 10.668; % 1; 
q_gamma = 25;
q_zeta = 100;

Q = [q_p 0 0 0 0 0 0; 
     0 q_pd 0 0 0 0 0; 
     0 0 q_e 0 0 0 0; 
     0 0 0 q_ed 0 0 0; 
     0 0 0 0 q_lamdad 0 0;
     0 0 0 0 0 q_gamma 0;
     0 0 0 0 0 0 q_zeta];

r_vs = 1; %1;%10;
r_vd = 1; %2;%10;
R = [r_vs 0; 0 r_vd];

%K = lqr(A_a, B_a, Q, R);
%k = K(1:2,1:5)
%k_a = K(1:2,5:7)

%F = [ k(1,1) k(1,4); k(2,1) k(2,4)];

%A_p = A_a - B_a*K
% sys = ss(A_p,B_a,C_a,0);
% p = pole(sys)
% plot(p, 'o');
% hold on;
% 
poles_L = zeros(0);
L_mag = -30;
L_ang = pi / 4;

poles_L(5) = complex(L_mag, 0);
poles_L(6) = complex(2*L_mag, 0);
poles_L(7) = complex(3*L_mag, 0);

x=3;
y=1;
for i=1:2:x
   poles_L(i) =  complex(L_mag*cos(y*L_ang/x), L_mag*sin(y*L_ang/x));
   poles_L(i+1) = conj(poles_L(i));
   y = y + 1;
end
    
plot(poles_L, 'o');

display(poles_L)
L = place(A', C', poles_L)';

hold off;



