program vijos1313;
var
   n,m,i,j,v0,v1,v2,p0,p1,p2,a,b,c,z:longint;
   v,p:array[0..60,0..2] of longint;
   f:array[0..60,0..20000] of longint;
begin
   readln(n,m);
   n:=n div 10;
   for i:=1 to m do
   begin
        readln(a,b,c);
        if c=0 then c:=i;
        for j:=0 to 2 do
          if v[c,j]=0 then
          begin
             v[c,j]:=a div 10 ;
             p[c,j]:=v[c,j]*b;
             break;
          end;
   end;
   z:=0;
   for i:=1 to m do
       if v[i,0]<>0 then
       begin
             v0:=v[i,0];v1:=v[i,1];v2:=v[i,2];
             p0:=p[i,0];p1:=p[i,1];p2:=p[i,2];
             for j:=n downto 0 do
             begin
                 f[i,j]:=f[z,j];
                 if (j>=v0) and (f[i,j]<f[z,j-v0]+p0) then
                 f[i,j]:=f[z,j-v0]+p0;
                 if (j>=v0+v1) and (f[i,j]<f[z,j-v0-v1]+p0+p1)then
                 f[i,j]:=f[z,j-v0-v1]+p0+p1;
                 if (j>=v0+v2) and (f[i,j]<f[z,j-v0-v2]+p0+p2)then
                 f[i,j]:=f[z,j-v0-v2]+p0+p2;
                 if (j>=v0+v1+v2) and (f[i,j]<f[z,j-v0-v1-v2]+p0+p1+p2)then
                 f[i,j]:=f[z,j-v0-v1-v2]+p0+p1+p2
             end;
             z:=i;
       end;

   writeln(f[z,n]*10);
end.





