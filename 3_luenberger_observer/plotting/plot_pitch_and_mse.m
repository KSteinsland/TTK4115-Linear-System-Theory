task_name = '.';
dir_name = strcat(task_name, '/data_luenberger/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;

figure()
hold on;
for i = 1:length(names)
    %figure()

    name = names{i};  
    load(strcat(task_name, '/data_luenberger/', names{i}));
    name_args = strsplit(name, '-');
    magnitude = name_args(9);
    magnitude = str2double(magnitude)

    hold on;
    

    xlabel('Negative magnitude');
    ylabel('MSR');

    time = data(1,start_t:stop_t);
    
    %p_c = data(1,start_t:stop_t);
    
    p_imu =  data(11,start_t:stop_t);
    p_hat = data(6,start_t:stop_t);
    p_enc =  data(16,start_t:stop_t);
    
    MSE = mean((p_hat - p_enc).^2);

    plot(magnitude, MSE, 'o');
    %title(strcat(name, num2str(MSE)));
    
    %plot(time, p_imu);
    %plot(time, p_imu);
    %plot(time, p_hat);
    %plot(time, p_enc); 
    %plot(time, p_c);
    
    
    
    %legend('p_{imu}', 'p_{hat}', 'p_{enc}');
   
    saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    %hold off;
end
