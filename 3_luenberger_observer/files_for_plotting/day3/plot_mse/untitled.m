task_name = '.';
dir_name = strcat(task_name, '/data/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;

for i = 1:length(names)
    figure()

    name = names{i};  
    load(strcat(task_name, '/data/', names{i}));
    

    hold on;
    title(name);

    xlabel('Time [s]');
    ylabel('Angle [rad]');

    time = data(1,start_t:stop_t);
    
    %p_c = data(1,start_t:stop_t);
    
    p_imu =  data(11,start_t:stop_t);
    p_hat = data(6,start_t:stop_t);
    p_enc =  data(16,start_t:stop_t);

    %plot(time, p_imu);
    plot(time, p_imu);
    plot(time, p_hat);
    plot(time, p_enc); 
    %plot(time, p_c);
    
    
    
    legend('p_{imu}', 'p_{hat}', 'p_{enc}');
   
    saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    hold off;
end
