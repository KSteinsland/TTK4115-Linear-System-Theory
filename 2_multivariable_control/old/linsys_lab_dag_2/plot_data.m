d = dir('data/*.mat');
names = {d.name};

for i = 1:length(names)
    figure()
    name_split = strsplit(names{i}, '.');
    name = name_split{2}
    load(strcat('data/', names{i}));    
    
    hold on;
    title(strcat('PITCH_', name));
    xlabel('time [s]');
    ylabel('pitch [rad]');

    plot(data(1,:), data(2,:));

    plot(data(1,:), data(7,:));

    %io_data = iddata(data(7, 2400:4800).', data(2, 2400:4800).', 0.002);
    %sys = tfest(io_data, 2, 0);
    %display(pole(sys))
    
    saveas(gcf, strcat(name, '.png'));
    hold off;
end
