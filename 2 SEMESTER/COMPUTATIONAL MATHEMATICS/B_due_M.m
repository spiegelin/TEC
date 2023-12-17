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

%pcolor(x,y,(Bz.^(1/3))); shading interp; colormap hot; colorbar
%phiB
%mesh(x,y,Bz)



