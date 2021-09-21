date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');

run_name = strcat('COMPARE_KALM_LUEN-Q-', int2str(q_p), ',', int2str(q_pd), ',', int2str(q_e), ',', int2str(q_ed), ',', int2str(q_lambda), ',', int2str(q_lamdad), ',',  int2str(q_gamma), ',', int2str(q_zeta), '-R-', int2str(r_vs), ',', int2str(r_vd), 'Q_d-', num2str(qq_p), ',', num2str(qq_pd), ',', num2str(qq_e), ',', num2str(qq_ed), ',', num2str(qq_lambda), ',', num2str(qq_lambdad));
file_name = strcat('data/', date, '-', run_name, '.mat');
copyfile('test.mat',file_name);

