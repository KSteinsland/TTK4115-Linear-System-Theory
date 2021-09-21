task_name = '.';
dir_name = strcat(task_name, '/data_pitch_test/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;

tiledlayout(2,2);

title_names = {
    'diag(Q) = [100, 10, 50, 1, 1]  |  diag(R) = [1, 1]',
    'diag(Q) = [100, 10, 50, 100, 1]  |  diag(R) = [1, 1]',
    'diag(Q) = [100, 10, 50, 10, 1]  |  diag(R) = [1, 1]',
    'diag(Q) = [100, 10, 50, 5, 1]  |  diag(R) = [1, 1]'
}

for i = 1:length(names)
    nexttile();
    %figure()

    name = names{i};
    %n = split(name, '-')
    %name = strcat(join(n(7:9)));
    
    load(strcat(task_name, '/data_pitch_test/', names{i}));
    

    hold on;
    title(title_names{i});

    xlabel('Time [s]');
    ylabel('Angle [rad]');

    time = data(1,start_t:stop_t);
    
    p_c = data(2,start_t:stop_t);
    p_enc =  data(6,start_t:stop_t);
    
    e_c = data(3,start_t:stop_t);
    e_enc =  data(9,start_t:stop_t);

    %plot(time, p_imu);
    plot(time, p_c);
    plot(time, p_enc); 
    
  
    
    
    legend('p_c', 'p');
   
    %saveas(gcf, strcat('plot/', date, '/', name, '.svg'));
    hold off;
    
end
