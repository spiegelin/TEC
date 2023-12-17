%function Step3

%Bz=mo/(4*pi)*(3*z*(mz*z)-mz*(x^2+y^2+z^2))/(x^2+y^2+z^2)^(5/2)

clear
clc
clf
mag=500;          %magnetic moment
Rring=0.5;      %Ring radius in m
zo=0.1;           %initial position of magnet
zring=0;        %Ring position
dt=0.01;        %time step
t(1)=0;
zm(1)=zo;       %magnet position at t=0
cc=1;           %counter
vz(1)=0;        %initial magnet velocity


figure(1)




while zm(cc)>-zo %0.0162
pause(0.001)
clf
    

    [x,y,phiB1,Bz]=B_due_M(zm(cc),mag,Rring);

    zm(cc+1)=zm(cc)+vz(cc)*dt-.5*9.81*dt^2;
    vz(cc+1)=(zm(cc+1)-zm(cc))/dt;

    [x,y,phiB2,Bz]=B_due_M(zm(cc+1),mag,Rring);

    fem(cc)=(phiB2-phiB1)/dt;

    subplot(2,2,1)
    hold on
    axis([0 0.3 -.2 .1])
    grid on
    xlabel 'time, s'
    ylabel 'fem, mV'
    plot(t(1:cc),100*fem(1:cc),'-k','LineWidth',1)
    plot(t(1:cc),100*fem(1:cc),'*r','LineWidth',2)
    

    subplot(2,2,2)
    hold on
    axis([0 0.3 -10 10])
    grid on
    xlabel 'time, s'
    ylabel 'magnet heigth, cm'
    plot(t(1:cc),100*zm(1:cc),'ob','LineWidth',2)    

    subplot(2,2,3)
    hold on
    pcolor(x,y,zm(cc)/abs(zm(cc))*abs(abs(Bz)).^(1/3)); shading interp; colormap hot; colorbar
    view(-45,-45)

    subplot(2,2,4)
    
    hold on
    
Lx=length(x);   Ly=length(y);
xx=repmat(x,Lx,1);  yy=repmat(y',1,Ly);     zz=0*xx;
    %quiver3(xx,yy,zz,0*Bz,0*Bz,zm(cc)/abs(zm(cc))*abs(abs(Bz)).^(1/3))
%     
    mesh(x,y,zm(cc)/abs(zm(cc))*abs(abs(Bz)).^(1/3)); 
    view(40,0)
    axis([-Rring/2 Rring/2 -Rring/2 Rring/2 -5 15])
    
    cc=cc+1;
    t(cc)=t(cc-1)+dt;

end
%L=length(fem);
%t=0:dt:(L-1)*dt;

%plot(t,fem)














