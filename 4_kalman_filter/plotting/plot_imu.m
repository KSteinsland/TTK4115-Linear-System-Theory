% task_name = '.';
% dir_name = strcat(task_name, '/*.mat');
% d = dir(dir_name);
% names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;


figure()

%name = names{i};
name = 'R_d';
%load(strcat(task_name, names{i}));

hold on;
title(name);

xlabel('Time [s]');
ylabel('Angle [rad]');

time = data(1,start_t:stop_t);

p = data(2,start_t:stop_t);
p_dot = data(3,start_t:stop_t);
e =  data(4,start_t:stop_t);
e_dot = data(5,start_t:stop_t);
lambda_dot = data(6,start_t:stop_t);

plot(time, p); 
plot(time, p_dot);
plot(time, e);
plot(time, e_dot); 
plot(time, lambda_dot);

M = data(2:6, start_t:stop_t);

R_d = cov(M')
%R_d = cov(M(:), M(:))


legend('p', 'p_{dot}', 'e', 'e_{dot}', 'lambda_{dot}');

saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
hold off;

