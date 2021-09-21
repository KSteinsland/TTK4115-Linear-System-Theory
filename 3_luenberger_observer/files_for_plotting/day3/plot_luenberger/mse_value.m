task_name = '.';
dir_name = strcat(task_name, '/data/*.mat');
d = dir(dir_name);
names = {d.name};

date = datestr(now, 'dd-mmm-yyyy-HH-MM-SS');
mkdir(strcat('plot/',date));

start_t = 1500;
stop_t = 7000;


load(strcat(task_name, '/data/LUENBERGER_4__MAG(-30).mat'));

time = data(1,start_t:stop_t);

p_hat = data(6,start_t:stop_t);
p_enc =  data(16,start_t:stop_t);

pd_hat = data(7,start_t:stop_t);
pd_enc =  data(17,start_t:stop_t);

e_hat = data(8,start_t:stop_t);
e_enc =  data(18,start_t:stop_t);

ed_hat = data(9,start_t:stop_t);
ed_enc =  data(19,start_t:stop_t);

ld_hat = data(10,start_t:stop_t);
ld_enc =  data(20,start_t:stop_t);  

% hold on;
% plot(ld_hat)
% plot(ld_enc)
% hold off;

% MSE_p = mean((p_hat-p_enc).^2)
% MSE_pd = mean((pd_hat-pd_enc).^2)
% MSE_e = mean((e_hat-e_enc).^2)
% MSE_ed = mean((ed_hat-ed_enc).^2)
% MSE_ld = mean((ld_hat-ld_enc).^2)

y_enc = [p_enc, pd_enc, e_enc, ed_enc, ld_enc];
x_hat = [p_hat, pd_hat, e_hat, ed_hat, ld_hat]; 

mse = mean(norm(x_hat - y_enc))






%saveas(gcf, strcat('plot/', date, '/', name, '.svg'));