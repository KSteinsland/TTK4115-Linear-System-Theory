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
    
    p_c = data(2,start_t:stop_t);
    p_enc =  data(6,start_t:stop_t);

    %plot(time, p_imu);
    plot(time, p_c);
    plot(time, p_enc); 
    
  
    
    
    legend('p_c', 'p');
   
    %saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    hold off;
end
