task_name = 'task_3_lqr_with_integral_action';
dir_name = strcat('../', task_name, '/data/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;

for i = 17:length(names)
    figure()

    name = names{i};  %strcat('mag', sprintf('%.2f',mag), 'ang', sprintf('%.2f',ang));
    load(strcat('../', task_name, '/data/', names{i}));
    
    %m = strsplit(name_args{1}, 'm');
    %m = str2double(m{2}) / 10
    %ang = strsplit(name_args{2}, 'ang');
    %ang = str2double(ang{2})
    
    
    hold on;
    title(name);

    xlabel('Time [s]');
    ylabel('Angle [rad]');

    time = data(1,start_t:stop_t);
    
    p_c = data(2,start_t:stop_t);
    p = data(8,start_t:stop_t);
    
    %V_d = data(4,start_t:stop_t);
    %V_s = data(5,start_t:stop_t);
    %V_f = (V_s - V_d) * 0.5;
    %V_b = (V_s + V_d) * 0.5;
    %plot(time, V_f);
    %plot(time, V_d);
    %plot(time, V_s);
    %V_f = min(5, max(-0.5, V_f));
    %V_b = min(5, max(-0.5, V_b));
    %V_f = lowpass(V_f, 0.1);
    %V_b = lowpass(V_b, 0.1);
    %plot(time, V_f);
    %plot(time, V_b);
    
    plot(time, p_c);
    plot(time, p); 
    
    legend('p_c','p');
   
    saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    hold off;
end
