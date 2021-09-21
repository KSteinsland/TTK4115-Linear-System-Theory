task_name = '.';
dir_name = strcat(task_name, '/data/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 4500;



xlabel('Time [s]');

time = P_hat_data(1,start_t:stop_t);

for i = 2:30
    hold on;
    plot(time, P_hat_data(i, start_t:stop_t));
end


saveas(gcf, strcat('plot/', date, '/', 'P_hat', '.svg'));

