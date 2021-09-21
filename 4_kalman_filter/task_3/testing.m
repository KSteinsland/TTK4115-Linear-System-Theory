

for i = 2:31
    figure()
    a = L_kalm_data(i,:);
    a = a(a~=0);
    time = L_kalm_data(1,:);
    time = time(a~=0); 
    plot(time , a);
end