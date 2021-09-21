task_name = '.';
dir_name = strcat(task_name, '/data_best_tuning/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;

tiledlayout(2,1);

nexttile();

load(strcat(task_name, '/data_best_tuning/', '08-Nov-2020-00-24-45-Q-100,10,500-R-1,1.mat'));

hold on;
title('Pich step respone, diag(Q) = [100, 10, 50]  |  diag(R) = [1, 1]');

xlabel('Time [s]');
ylabel('Angle [rad]');

time = data(1,start_t:stop_t);

p_c = data(2,start_t:stop_t);
p_enc =  data(6,start_t:stop_t);

%plot(time, p_imu);
plot(time, p_c);
plot(time, p_enc); 

legend('p_c', 'p');

hold off;


nexttile();

load(strcat(task_name, '/data_best_tuning/', 'ELEVATION_TEST_08-Nov-2020-00-23-04-Q-100,10,500-R-1,1.mat'));

hold on;
title('Elevation rate step response, diag(Q) = [100, 10, 50]  |  diag(R) = [1, 1]');

xlabel('Time [s]');
ylabel('Angle [rad]');

time = data(1,start_t:stop_t);

e_c = data(3,start_t:stop_t);
e_enc =  data(9,start_t:stop_t);

plot(time, e_c);
plot(time, e_enc); 

legend('ed_c', 'ed');

hold off;