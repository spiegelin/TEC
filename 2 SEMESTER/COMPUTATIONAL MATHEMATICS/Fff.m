%DEFINIR CONSTANTES
Mu0 = (4*pi)*10^-7;  %Mu sub cero
g = -9.81;      %gravedad

c = 1;            % Counter
mu = 1;       %Momento magnetico
Z0 = 0.003;      %posición inicial
R_ring = 0.01;     %Radio del ring
dt = 0.001;      % delta tiempo
ds = 0.01;      % delta longitud (ds^2 es diferencial de área)
%I(1) = 0;
RE = 0.003;
%F(1) = 0;

E(1) = 0;       %Voltage inducido
z(1) = Z0;      %Iniciamos el vector de Z en la posicion inicial Z0
V(1) = 0;       %Velocidad Inicial
t(1) = 0;
mumass = 0.005;
[x,y,MagFlux(c),Bz] = B_due_M(z(c),mu,R_ring); %Usamos la funcion con las valores anteriores
figure(1)
while z(c) >= 0
    I(c) = E(c)/RE;
    F(c) = (6*Mu0*I(c)*R_ring^2*z(c)*mu)/(4*((z(c)^2+R_ring^2)^(5/2)));
    F(c) = F(c)+(-9.81*mumass);
    a = F(c)/mumass;
    dz = V(c)*dt + (0.5*a*dt*dt);
    z(c+1) = z(c) + dz;
    [x,y,MagFlux(c+1),Bz] = B_due_M(z(c+1),mu,R_ring);    %Volvemos a llamar  la funcion pero en la posición siguiente
    s = z(c)/abs(z(c));
    E(c+1) = (MagFlux(c+1) - MagFlux(c)) / dt;                          %Voltaje Inducido
    V(c+1) = dz / dt;


    pause (0.1)                                       %Velocidad
    if c > 1
        t = 0:dt:(dt*(c-1));
    end
    % Crear una nueva figura
    figure(1)
    % Subgráfico 1
    subplot(2,2,1)
    plot(t(1:c), z(1:c))
    title('Cambio de posición respecto al tiempo')
    
    % Subgráfico 2
    subplot(2,2,2)
    plot(z(1:c), E(1:c))
    title('Cambio de Corriente Electrica inducida respecto al tiempo')
    
    % Subgráfico 3
    subplot(2,2,3)
    plot(t(1:c), V(1:c))
    title('Cambio de velocidad respecto al tiempo')

    subplot(2,2,4)
    plot(z(1:c), F(1:c))
    title('Cambio de fuerza respecto a la posicion')


    
    % Ajustar el espaciado entre los subgráficos
    spacing = 0.04;
    set(gcf, 'Position', get(0,'Screensize'));
    set(gcf, 'PaperPositionMode', 'auto');
    pos = get(gca, 'Position');
    pos(2) = pos(2) + spacing;
    set(gca, 'Position', pos);
    
    % Ajustar el espaciado entre las etiquetas de los subgráficos
    set(gca, 'XTickLabel', get(gca, 'XTickLabel'), 'fontsize', 8)

    c = c + 1;
end

z
E
V
I
F

%%Función para calcular el Campo magnetico

function [x,y,phiB,Bz]=B_due_M(z,mag,Rring)

%mag=50;
%z=0.1;
%Rring=1.5;

mo=4*pi*1e-7;

ds=0.005;

x=-Rring:ds:Rring;  y=-Rring:ds:Rring; 
Lx=length(x); Ly=length(y);

Bz(1:Lx,1:Ly)=0;
phiB=0;

for i=1:Lx
    for j=1:Ly

        r=sqrt(x(i)^2+y(j)^2);

        if r<Rring

            Bz(i,j)=mo/(4*pi)*(3*z*(mag*z)-mag*(x(i)^2+y(j)^2+z^2))/((x(i)^2+y(j)^2+z^2+(ds/10)^2)^(5/2));
            phiB=phiB+ds^2*Bz(i,j);

        end

    end
end
end

%pcolor(x,y,(Bz.^(1/3))); shading interp; colormap hot; colorbar
%phiB
%mesh(x,y,Bz)




