task_name = '.';
dir_name = strcat(task_name, '/data/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 4500;
stop_t = 10000;

for i = 1:length(names)
    figure()

    name = names{i};  
    load(strcat(task_name, '/data/', names{i}));
    

    hold on;
    title(name);

    xlabel('Time [s]');
    ylabel('Angle [rad]');

    time = data(1,start_t:stop_t);
    
    e_c = data(3,start_t:stop_t);
    e_hat = data(9,start_t:stop_t);
    e_imu =  data(14,start_t:stop_t);
    e_enc =  data(19,start_t:stop_t);

    %plot(time, e_imu);
    plot(time, e_enc); 
    plot(time, e_c);
    plot(time, e_hat);
    
    
    legend('e_{enc}', 'e_c', 'e');
   
    saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    hold off;
end
