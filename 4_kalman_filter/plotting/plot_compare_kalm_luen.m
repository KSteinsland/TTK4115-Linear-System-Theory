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
    
    e_c = data(3,start_t:stop_t);
    e_hat = data(9,start_t:stop_t);
    e_imu =  data(15,start_t:stop_t);
    e_enc =  data(21,start_t:stop_t);
    e_luen = data(27,start_t:stop_t);
    
    p_c = data(2,start_t:stop_t);
    p_hat = data(6,start_t:stop_t);
    p_imu =  data(12,start_t:stop_t);
    p_enc =  data(18,start_t:stop_t);
    p_luen = data(24,start_t:stop_t);

    %plot(time, e_imu);
   
    plot(time, p_enc);
    plot(time, p_luen);
    plot(time, p_c);
    plot(time, p_hat);
    
%     figure()
%     
%     plot(time, e_enc);
%     plot(time, e_luen);
%     plot(time, e_c);
%     plot(time, e_hat);

    mse = mean((p_hat - p_enc).^2)
    
    legend('p_{enc}', 'p_{luen}', 'p_c', 'p_hat');
   
    saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    hold off;
end
