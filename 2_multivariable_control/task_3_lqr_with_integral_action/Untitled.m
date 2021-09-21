date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');

run_name = strcat('Q-', int2str(q_p), ',', int2str(q_pd), ',', int2str(q_ed), '-R-', int2str(r_vs), ',', int2str(r_vd));
file_name = strcat('data/', date, '-', run_name, '.mat');
copyfile('test.mat',file_name);