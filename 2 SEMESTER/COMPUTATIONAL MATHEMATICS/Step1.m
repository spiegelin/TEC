clear
clc
clf
%fjmontes@tec.mx
nl=1; 

ds=0.1;                                        
x=(-5:ds:5); y=(-5:ds:5);    z=x;               
Lx=length(x); Ly=length(y); Lz=length(z);       
rw=0.1;                                         
I=22.5;                                          
mo=4*pi*1e-7;                                     
km=mo*I/(4*pi);                                 
                                                
cp=find(x<=0); cx=cp(1);
cp=find(y<=0); cy=cp(1);                        
cp=find(z<=0); cz=cp(1);

N=12;                       
R=0.3;                                         
sz=0.2;                   

cp=find(z>=-nl*sz*0.5);  cz=cp(1);      

s=1;    

    dtheta=2*pi/N;                 
    dl=R*dtheta;                   
    ang=(0:dtheta:2*pi-dtheta);    

for I=1:nl                           

    Px(s:s+N-1)=R*cos(ang);           
    Py(s:s+N-1)=R*sin(ang);           
    
   
    Pz(s:s+N-1)=-nl/2*sz+(I-1)*sz;    

   

    dx(s:s+N-1)=-Py(s:s+N-1)*dtheta;  
    dy(s:s+N-1)=Px(s:s+N-1)*dtheta;   

    s=s+N;                            
end




dz(1:N*nl)=0;                     


figure(1)

hold on
 %VERTICAL ORIENTED   
    quiver3(Px,Py,Pz,dx,dy,dz,0.5,'-r','LineWidth',3)
    plot3(Px,Py,Pz,'*k','LineWidth',5)
    plot3(Px,Py,Pz,'-k','LineWidth',.3)
   



 xlabel 'x'
    ylabel 'y'
    zlabel 'z'
    title 'Curent elements'
    legend('Discrete current elements','Current element location','Loop/Solenoid')
axis([-3 3 -3 3 -3 3])
    grid on
    view(-34,33)
   





dBx(1:Lx,1:Ly,1:Lz)=0; dBy=dBx; dBz=dBx;   

tic
for I=1:Lx
    for J=1:Ly                  
        for K=1:Lz

            for L=1:nl*N        

            rx=x(I)-Px(L);      
            ry=y(J)-Py(L);      
            rz=z(K)-Pz(L);      
            
            r=sqrt(rx^2+ry^2+rz^2+rw^2);    
            r3=r^3;                         

  

            dBx(I,J,K)=dBx(I,J,K)+km*dy(L)*rz/r3;
            dBy(I,J,K)=dBy(I,J,K)+km*dx(L)*rz/r3;
            dBz(I,J,K)=dBz(I,J,K)+km*(dx(L)*ry-dy(L)*rx)/r3;

            end

        end
    end
end
toc

%%Plots

Bmag=sqrt(dBx.^2+dBy.^2+dBz.^2);    

centery=round(Ly/2);            
Bx_xz=squeeze(dBx(:,centery,:));   
Bz_xz=squeeze(dBz(:,centery,:));    

Bxz=squeeze(Bmag(:,centery,:));    

figure(3)


hold on

 %VERTICAL ORIENTED 
pcolor(x,z,(Bxz').^(1/3)); shading interp; colormap jet; colorbar

 %HORIZONTAL ORIENTED 
%pcolor(z,x,(Bxz).^(1/3)); shading interp; colormap jet; colorbar

h1=streamslice(x,z,Bx_xz',Bz_xz',1);
set(h1,'Color', [0.8 1 0.9]);
xlabel 'x'
ylabel 'z'
title 'Magnetic field of a circular current'


%% Dipole Falling

mag = 5; % Magnetic moment of the magnet
m = 0.1; % Magnet's mass in kg
zo = 5;
w = m*-9.81;

dt = 0.25; % Time step

zm(1) = zo; % Magnet position
tt(1) = 0; % Time initialization
vz(1) = 0;

cc = 1;
path = animatedline('LineWidth',2,'LineStyle',':','Color','r');
while zm(cc) > -3 % Lower limit
    addpoints(path,0,zm(cc));
    drawnow
    head = scatter(0,zm,100,'filled');

    %signo = zm(cc) /(abs(zm(cc)));

    Fm(cc) = (6*mo*I*(R^2)*mag*(zm(cc) + 1e-5)) / (4*((zm(cc) + 1e-5)^2 + R^2)^(5/2));
    F(cc) = Fm(cc) + w;
    a = F(cc)/m;

%     zm(cc+1) = zm(cc) + vz(cc)*dt + 0.5*a*dt^2;
%     vz(cc+1) = (zm(cc+1) - zm(cc)) / dt;
%     cc = cc+1;

    pause(0.001);
    if zm(cc) > -2.9
        zm(cc+1) = zm(cc) + vz(cc)*dt+0.5*a*dt^2;
        vz(cc+1) = (zm(cc+1) - zm(cc)) / dt;
        cc = cc+1;
        delete(head)
    end
end

figure(4)
hold on
plot(zm(1:length(Fm)), Fm, '-b', 'LineWidth',2)
grid on
xlabel 'z position (m)'
ylabel 'Magnetic Force (N)'


figure(5)
hold on
tt = 0:dt:(cc-1)*dt;
zf = zo-0.5*9.81*tt.^2;
plot(tt,zm,'-r', 'LineWidth',2)
grid on
xlabel 'Time (s)'
ylabel 'Z position (m)'


%% Etapa 3

% Definir u, zo, Rring, dt, ds
u = 2;
zo = 2;
R = 2;
dt = 0.2;
ds = 0.2;

E(1) = 0;
c = 1;
z(1) = zo;
v(1) = 0;
g = -9.81;

[Bz(:,:,c),phi(c),x,y] = B_due_m(u,z,R,ds); %%% z(c)
while z(c) >= -zo
    %pause(0.1);
    z(c+1) = z(c) + v(c)*dt + (1/2)*g*(dt^2);

    [Bz(:,:,c+1), phi(c+1),x,y] = B_due_m(u,z(c+1),R,ds);
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



