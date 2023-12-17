%% Etapa 3 

% Definir u, zo, Rring, dt, ds
u = 2; % Momento dipolar magnético
zo = 2;
R = 2;
dt = 0.2;
ds = 0.2;

E(1) = 0;
c = 1;
z(1) = zo;
vz(1) = 0;
g = -9.81;


%t = 0:dt:dt*(c-1);


figure(1)
%I(1) = E(1) / resistencia;

[Bz(c),phi(c),x,y] = B_due_m(u,z,R,ds); %%% z(c)
while z(c) >= -zo
    %pause(0.1);
    %I(1) = E(1) / resistencia; -> parte 3
    % Llamar código step 2, dividir voltaje entre resistencia del anillo,
    % esa corriente la meto
    % [deltaZ * step2(I(cc),R, u, z(c))]; z(c+1) = z(c) + deltaZ;
    z(c+1) = z(c) + v(c)*dt + (1/2)*g*(dt^2);

    [Bz(c+1), phi(c+1),x,y] = B_due_m(u,z(c+1),R,ds);
    E(c+1) = (phi(c+1) - phi(c)) / dt;

    v(c+1) = (z(c+1) - z(c)) / dt;
    c = c+1;
end

function [Bz, phi, x, y] = B_due_m(u,z,R,ds)
    uo = 4*pi*10e-7;
    x = -R:ds:R;
    y = -R:ds:R;
    Lx = length(x);
    Ly = length(y);
    phi = 0;

    for i=1:Lx
        for j=1:Ly
            r = sqrt(x(i)^2 + y(i)^2 +z.^2); %%%%%%%%
            if  (sqrt(x(i)^2 + y(i)^2 + z.^2) <= R)
                Bz(i,j) = (uo/4*pi)*(3*(z.^2)*u - u*(r.^2)) / r.^5;
                phi = phi + Bz(i,j) * ds^2;
            end
        end
    end
end




