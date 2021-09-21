task_name = '.';
dir_name = strcat(task_name, '/data/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;

t = tiledlayout(3,2);

names_title = {
    "Magnitude: 0.5",
    "Magnitude: 4.0",
    "Magnitude: 8.0",
    "Magnitude: 30"
    "Magnitude: 90"
    "Magnitude: 160"
};

for i = 1:length(names)
    nexttile();
    %figure()

    name = names{i};  
    load(strcat(task_name, '/data/', names{i}));
    

    hold on;
    

    xlabel('Time [s]');
    ylabel('Angle [rad]');
    
   

    time = data(1,start_t:stop_t);
    
    p_c = data(1,start_t:stop_t);
    p_imu =  data(11,start_t:stop_t);
    p_hat = data(6,start_t:stop_t);
    p_enc =  data(16,start_t:stop_t);
    
    MSE = mean((p_hat-p_enc).^2);
    
    name_title = names_title{i};
    %title(strcat(name_title, '--MSE', num2str(MSE)));
    title(name_title);
    
    %plot(time, p_imu);
    plot(time, p_imu);
    plot(time, p_hat);
    plot(time, p_enc); 
   % plot(time, p_c);
    
    legend('p_{imu}', 'p_{hat}', 'p_{enc}');
    %legend boxoff;
   
    hold off;
end

%saveas(gcf, strcat('plot/', date, '/', name, '.svg'));