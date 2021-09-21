date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');

run_name = strcat('mag-', sprintf('%.2f',mag), 'ang-', sprintf('%.2f',ang));
file_name = strcat('data/', date, '-', run_name, '.mat');
copyfile('test.mat',file_name);