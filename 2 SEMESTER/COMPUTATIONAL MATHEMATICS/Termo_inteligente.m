clear; clc;

% Medidas en cm
h = 22.5;
R = 3.25;

%% Cilindro (Superficie en 3D)
subplot(1,2,1)

% Tapa
num_points = 100;
theta = linspace(0, 2*pi, num_points);
x = R*cos(theta);
y = R*sin(theta);
z = ones(size(theta)) * h;

fill3(x, y, z, "b");
hold on

% Base 
num_points = 100;
theta = linspace(0, 2*pi, num_points);
x = R*cos(theta);
y = R*sin(theta);
z = zeros(size(theta));

fill3(x, y, z, "b");

% Cuerpo del Cilindro
[X, Y, Z] = cylinder(R);
Z = Z*h;
surf(X,Y,Z, 'FaceColor','b')
title("Sólido de revolución en 3D")

%% Superficie en 2D
subplot(1,2,2)

% Base
y1 = 0:0.01:3.25;
x1 = (1 / 30) * y1.^2;
plot(x1,y1)
hold on

% Largo
%y = 3.25;
x2 = 0.3:0.1:20.5;
y = ones(1,203);
y2 = y.*3.25;
plot(x2,y2)

% Tapa
y3 = 0:0.01:3.25;
x3 = -(1 / 30) * y3.^2 + 20.8;
plot(x3,y3)
title("Sólido de revolución en 2D")
