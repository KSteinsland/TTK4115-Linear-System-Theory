d = dir('linsys_data/compare/*.mat');
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH:MM:SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 4500;

figure()
axis ([3,9,-5,20])
hold on;

title("Step responses");

xlabel('Time [s]');
ylabel('Angle [°]');


for i = 1:length(names)

    name_split = strsplit(names{i}, '.');
    name_args = strsplit(name_split{2}, '__');
    name = strcat(name_args{1}, name_args{2})
    load(strcat('linsys_data/compare/', names{i}));
        

    time = data(1,start_t:stop_t);
    
    p_c = rad2deg(data(2,start_t:stop_t));
    p = rad2deg(data(7,start_t:stop_t));
    

    if i == 1
        plot(time, p_c, 'DisplayName', 'p_c');
        legend('p_c', 'Location','northwest')
    end
    

    %[x,y] = pol2cart(deg2rad(str2double(extractBetween(name_args{2}, 4, 5))), str2double(extractBetween(name_args{1}, 2, 3))/10);
    disp_name = "p, \lambda = (" + sprintf('%.1f', str2double(extractBetween(name_args{1}, 2, 3))/10) + ", ±" + sprintf('%.1f', str2double(extractBetween(name_args{2}, 4, 5))) + "°)";
    plot(time, p, 'DisplayName', disp_name);
     
end

saveas(gcf, strcat('plot/', date, '/', 'step_response', '.svg'));

