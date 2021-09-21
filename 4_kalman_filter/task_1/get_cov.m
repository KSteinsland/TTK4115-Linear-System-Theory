T = 0.002;
Fs = 1/T;

x = data(2,:);


% N = length(x);
% xdft = fft(x);
% xdft = xdft(1:N/2+1);
% psdx = ( 1 / (Fs*N)) * abs(xdft).^2;
% psdx(2:end-1) = 2*psdx(2:end-1);
% freq = 0:Fs/length(x):Fs/2;
% 
% 
% plot(freq, 10*log10(psdx));
% grid on

figure()
periodogram(x, rectwin(length(x)), length(x), Fs);