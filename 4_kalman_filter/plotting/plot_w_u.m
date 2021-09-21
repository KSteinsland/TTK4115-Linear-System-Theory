d = dir('linsys_data/*.mat');
%names = {d.name};
names = {'data.m35__ang45.mat'}
date = datestr(now, 'dd-mmm-yyyy-HH:MM:SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 4500;

for i = 1:length(names)
    figure()
    axis ([3,9,0.5,5.5])
    hold on;
    
    title(name);

    xlabel('Time [s]');
    ylabel('Voltage [V]');
    
    name_split = strsplit(names{i}, '.');
    name_args = strsplit(name_split{2}, '__');
    name = strcat(name_args{1}, name_args{2})
    load(strcat('linsys_data/', names{i}));
    
    %m = strsplit(name_args{1}, 'm');
    %m = str2double(m{2}) / 10
    %ang = strsplit(name_args{2}, 'ang');
    %ang = str2double(ang{2})
    %lam = - m / (2 * cos(deg2rad(ang)));
    %text(7.5, 0.05, sprintf('%.6f',lam));
    

    time = data(1,start_t:stop_t);
    
    p_c = data(2,start_t:stop_t);
    p = data(7,start_t:stop_t);
    
    V_d = data(3,start_t:stop_t);
    V_s = data(4,start_t:stop_t);
    
    
    V_f = (V_s - V_d) * 0.5;
    V_b = (V_s + V_d) * 0.5;
    
    %plot(time, V_f);
    %plot(time, V_d);
    %plot(time, V_s);
    

    V_f = min(5, max(-5, V_f));
    V_b = min(5, max(-5, V_b));
    
    V_f = lowpass(V_f, 0.1);
    V_b = lowpass(V_b, 0.1);
    
    plot(time, V_f);
    plot(time, V_b);
    
    legend('V_f','V_b');

    %plot(time, p_c);
    %plot(time, p); 
   
    
    saveas(gcf, strcat('plot/', date, '/', name, '.eps'));
    hold off;
end
