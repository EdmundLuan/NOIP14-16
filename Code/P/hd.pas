program fgjk;
var i,j,f,v,k,max:longint;
    a:array[1..100,1..100]of longint;
    g:array[1..100,1..100]of longint;
    p:array[0..100,0..100]of longint;
    b:array[1..100]of longint;
begin
//assign(input,'D:\running zone\input.txt');
//reset(input);
fillchar(g,sizeof(g),0);
fillchar(p,sizeof(p),0);
readln(f,v);
for i:=1 to f do
begin
    for j:=1 to v do
      read(a[i,j]);
    readln;
end;
for i:=1 to v do
    g[1,i]:=a[1,i];
for i:=2 to f do
    for j:=i to v+i-f do
    begin
      g[i,j]:=-50001;
      for k:=i-1 to j-1 do
        if g[i,j]<g[i-1,k] then
        begin
          g[i,j]:=g[i-1,k];
          p[i,j]:=k;
        end;
      inc(g[i,j],a[i,j]);
    end;
max:=0;
k:=f;
for i:=f+1 to v do
    if g[f,i]>g[f,k] then
      k:=i;
writeln(g[f,k]);
for i:=f downto 1 do
begin
    b[i]:=k;
    k:=p[i,k];
end;
for i:=1 to f-1 do
    write(b[i],' ');
writeln(b[f]);
//close(input);
end.