real = csvread('real.csv')
euler = csvread('euler.csv')
rk4 = csvread('rk4.csv')
length(real(:,1))
length(real(:,2))
plot(real(:,1), real(:,2));
hold on
plot(euler(:,1), euler(:,2), "o-");
hold on
plot(rk4(:,1), rk4(:,2), "+-");

xlabel('X');
ylabel('Y');
title('Real VS RK4 VS Euler');
