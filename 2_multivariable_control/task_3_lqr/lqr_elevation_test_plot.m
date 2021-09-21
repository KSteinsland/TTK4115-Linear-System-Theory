task_name = '.';
dir_name = strcat(task_name, '/data_elevation_test/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 2200;
stop_t = 5000;

tiledlayout(2,1);

title_names = {
    'diag(Q) = [1, 1, 1]  |  diag(R) = [1, 1]',
    'diag(Q) = [1, 1, 100]  |  diag(R) = [1, 1]'
}

load(strcat(task_name, '/data_elevation_test/', names{2}));
e_c = data(3,start_t:stop_t);

for i = 1:length(names)
    nexttile();
    %figure()

    name = names{i};
    %n = split(name, '-')
    %name = strcat(join(n(7:9)));
    
    load(strcat(task_name, '/data_elevation_test/', names{i}));
    

    hold on;
    title(title_names{i});

    xlabel('Time [s]');
    ylabel('Angle rate [rad/s]');

    time = data(1,start_t:stop_t);
    
    p_c = data(2,start_t:stop_t);
    p_enc =  data(6,start_t:stop_t);
    
    %e_c = data(3,start_t:stop_t);
    e_enc =  data(9,start_t:stop_t);

    %plot(time, p_imu);
    plot(time, e_c);
    plot(time, e_enc); 
    
  
    
    
    legend('ed_c', 'ed');
   
    %saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    hold off;
    
end
