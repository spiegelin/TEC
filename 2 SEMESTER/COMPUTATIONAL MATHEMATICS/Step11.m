clear
clc
clf

nl=1; % Vueltas 

ds=0.1;   % step de longitud de arco                                     
x=(-5:ds:5); y=(-5:ds:5);    z=x;               
Lx=length(x); Ly=length(y); Lz=length(z);       
rw=0.1;  %                                       
I=22.5;  % Corriente                                        
mo=4*pi*1e-7; % Permeabilidad del espacio libre                                    
km=mo*I/(4*pi); % Parte izquierda de Biot-Savart                                
                                                
cp=find(x<=0); cx=cp(1); % Encuentra los índices de los elementos y el primero lo pone en cx
cp=find(y<=0); cy=cp(1);                        
cp=find(z<=0); cz=cp(1);

N=12; % Partición del círculo                      
R=0.3; % Radio                                        
sz=0.2; % Longitud de arco en z                  

cp=find(z>=-nl*sz*0.5);  cz=cp(1);      

s=1;    

    dtheta=2*pi/N;  % Partición del diferencial de vueltas               
    dl=R*dtheta; % Longitud de arco                  
    ang=(0:dtheta:2*pi-dtheta);    


%% Corriente en un Solenoide 
for I=1:nl                           

    % Posición x,y,z
    Px(s:s+N-1)=R*cos(ang);           
    Py(s:s+N-1)=R*sin(ang);           
    Pz(s:s+N-1)=-nl/2*sz+(I-1)*sz;    

    % Dirección de los vectores en cada punto
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
   
    
%% Campo magnético en un solenoide

dBx(1:Lx,1:Ly,1:Lz)=0; dBy=dBx; dBz=dBx;   

tic
for I=1:Lx
    for J=1:Ly                  
        for K=1:Lz
            for L=1:nl*N        

            rx=x(I)-Px(L);      
            ry=y(J)-Py(L);      
            rz=z(K)-Pz(L);      
            
            % Magnitud del radio
            r=sqrt(rx^2+ry^2+rz^2+rw^2);    
            r3=r^3;                         

            % Fórmula Biot-Savart
            dBx(I,J,K)=dBx(I,J,K)+km*dy(L)*rz/r3;
            dBy(I,J,K)=dBy(I,J,K)+km*dx(L)*rz/r3;
            dBz(I,J,K)=dBz(I,J,K)+km*(dx(L)*ry-dy(L)*rx)/r3;

            end
        end
    end
end
toc

%% Plots
Bmag=sqrt(dBx.^2+dBy.^2+dBz.^2); % Magnitud del campo magnético   

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
