task_name = '.';
dir_name = strcat(task_name, '/data/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;

ls = [];
ms = [];

%figure()
%hold on;
for i = 1:length(names)
    %figure()

    name = names{i};  
    load(strcat(task_name, '/data/', names{i}));
    name_args = strsplit(name, '-');
    magnitude = name_args(9);
    magnitude = str2double(magnitude)
    ls(length(ls)+1) = magnitude;
    %hold on;
    
    
    %xlabel('Time [s]');
    %ylabel('Angle [rad]');

    time = data(1,start_t:stop_t);
    
    %p_c = data(1,start_t:stop_t);
    
    p_imu =  data(11,start_t:stop_t);
    p_hat = data(6,start_t:stop_t);
    p_enc =  data(16,start_t:stop_t);
    
    MSE = mean((p_hat - p_enc).^2);
    ms(length(ms)+1) = MSE;

    %plot(magnitude, MSE, 'o');
    %title(strcat(name, num2str(MSE)));
    
    %plot(time, p_imu);
    %plot(time, p_imu);
    %plot(time, p_hat);
    %plot(time, p_enc); 
    %plot(time, p_c);
    
    
    
    %legend('p_{imu}', 'p_{hat}', 'p_{enc}');
   
    %saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    %hold off;
end

display(ls)
display(ms)
f = fit(ls(:), ms(:), 'exp2');
figure();
hold on;
plot(ls,ms, 'o');
plot(f);
legend('error', 'fitted curve');

%title('Error between encoder and estimate for different pole placements');
xlabel('Poles magnitude');
ylabel('Mean square error');
%saveas(gcf, strcat('good_plot/mse.svg'));
hold off;



